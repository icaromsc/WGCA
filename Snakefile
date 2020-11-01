#SnakeMake clinical genomic annotation workflow

def list_files():
    import os
    l=os.listdir('data/samples/')
    li=[x.split('.')[0] for x in l]
    li_unique=set(li)
    li_f=(list(li_unique))
    return li_f

SAMPLES = list_files()

# Define default rule to run full pipeline
rule all:
    input:
        "WGCA_analysis_result/plasmid_summary.tsv",
        "WGCA_analysis_result/virulence_summary.tsv",
        "WGCA_analysis_result/RGI_heatmap"



rule virulence_identification:
    input:
        "data/samples/{sample}.fasta"
    output:
        #report("virulence_prediction/{sample}.tsv", category="Virulence factors")
        "virulence_prediction/{sample}.tsv"
    conda:
        "envs/abricate.yaml"
    shell:
        "abricate --minid=90 --mincov=60 --db=vfdb {input} > {output}"

rule summarize_virulence:
    input:
        expand("virulence_prediction/{sample}.tsv", sample=SAMPLES)
    output:
        "virulence_prediction/summary.tsv"
    conda:
        "envs/abricate.yaml"
    shell:
        "abricate --summary {input} > {output}"

rule plasmid_prediction:
    input:
        "data/samples/{sample}.fasta"
    output:
        #report("plasmid_prediction/{sample}.tsv", category="Plasmid Prediction")
        "plasmid_prediction/{sample}.tsv"
    conda:
        "envs/abricate.yaml"
    shell:
        "abricate --minid=60 --mincov=90 --db=plasmidfinder {input} > {output}"

rule summarize_plasmid_prediction:
    input:
        expand("plasmid_prediction/{sample}.tsv", sample=SAMPLES)
    output:
        "plasmid_prediction/summary.tsv"
    conda:
        "envs/abricate.yaml"
    shell:
        "abricate --summary {input} > {output}"

rule resistome_prediction:
    input:
        "data/samples/{sample}.fasta"
    output:
        log = "resistome_prediction/{sample}",
        #txt = report("resistome_prediction/{sample}.txt", category="Resistance prediction")
        txt = "resistome_prediction/{sample}.txt"
        #txt = "resistome_prediction/{sample}.txt",
        #json = "resistome_prediction/{sample}.json"
    conda:
        "envs/rgi.yaml"
    shell:
        "rgi main -i {input} -o resistome_prediction/{wildcards.sample} -a DIAMOND -t contig --clean --debug > {output.log}"

rule generate_resistome_heatmap:
    input:
        logs = expand("resistome_prediction/{sample}", sample=SAMPLES),
        dir = "resistome_prediction/"
    output:
        log = "resistome_prediction/RGI_heatmap"
    conda:
        "envs/rgi.yaml"
    shell:
        "rgi heatmap --input {input.dir} --output {output} --category drug_class --cluster samples -d text > {output}"


rule summary_results:
    input:
        p="plasmid_prediction/summary.tsv",
        v="virulence_prediction/summary.tsv",
        r="resistome_prediction/RGI_heatmap",
        #gi=expand("genomic_islands/{sample}_GI.gff3", sample=SAMPLES),
        #rt=expand("resistome_summary/{sample}.txt", sample=SAMPLES),
        #pr=expand("prophage_prediction/{sample}/prophage_coordinates.tsv", sample=SAMPLES),
        spr="prophage_prediction/prophage_summary.tsv",
        sgi="genomic_islands/GI_summary.tsv"
    output:
        r="WGCA_analysis_result/RGI_heatmap",
        v=report("WGCA_analysis_result/virulence_summary.tsv", caption="report_description/virulence.rst", category="General"),
        p=report("WGCA_analysis_result/plasmid_summary.tsv", caption="report_description/plasmid.rst", category="General"),
        t=report("WGCA_analysis_result/RGI_heatmap-"+str(len(SAMPLES))+".png", caption="report_description/heatmap.rst" , category="General"),
        #rr=report(expand("WGCA_analysis_result/{sample}.tsv", sample=SAMPLES), category="Resistance"),
        compact=report("jamira_integrative_results.zip", caption="report_description/report.rst", category="General"),
        spr=report("WGCA_analysis_result/prophage_summary.tsv",caption="report_description/report.rst", category="General"),
        rgi=report("WGCA_analysis_result/GI_summary.tsv", caption="report_description/report.rst", category="General")
    run:

        shell("cp {input.p} {output.p}")
        shell("cp {input.v} {output.v}")
        shell("cp {input.r} {output.r}")
        shell("cp resistome_prediction/RGI_* WGCA_analysis_result/")
        shell("cp {input.sgi} WGCA_analysis_result/")
        #shell("cp {input.rt} WGCA_analysis_result/")
        shell("cp {input.spr} WGCA_analysis_result/")
        shell("cd WGCA_analysis_result/ ; rename 's/.txt/.tsv/' *")
        #for i,s in zip(input.pr,SAMPLES):
        #    shell("cp {i} WGCA_analysis_result/{s}_prophage_coordinates.tsv")
        shell("zip -r jamira_integrative_results plasmid_prediction/ prophage_prediction/ virulence_prediction/ resistome_prediction/ genomic_islands/")

rule genome_annotation:
    input:
        "data/samples/{sample}.fasta"
    output:
        "genome_annotation/{sample}.gbk"
    conda:
        "envs/prokka.yaml"
    shell:
        "prokka --force --outdir genome_annotation/ --cpus 1 --usegenus --Genus Enterococcus --compliant --prefix {wildcards.sample} {input}"

rule genomic_island_prediction:
    input:
        "genome_annotation/{sample}.gbk"
    output:
        #report("genomic_islands/{sample}_GI.gff3", category="Genomic Islands")
        "genomic_islands/{sample}_GI.gff3"
    conda:
        "envs/island_path.yaml"
    shell:
        "islandpath {input} {output}"

rule convert_gbk_to_seed:
    input:
        "genome_annotation/{sample}.gbk"
    output:
        directory("seeds/{sample}")
    conda:
        "envs/phispy.yaml"
    shell:
        "python scripts/phispy/genbank_to_seed.py {input} {output}"

rule prophage_prediction:
    input:
        "seeds/{sample}"
    output:
        #d = dir("prophage_prediction/{sample}"),
        r1 = "prophage_prediction/{sample}/prophage.tbl",
        #r2 = report("prophage_prediction/{sample}/prophage_coordinates.tsv", category="Prophages"),
        r2 = "prophage_prediction/{sample}/prophage_coordinates.tsv",
        r3 = "prophage_prediction/{sample}/prophage_tbl.tsv"
    conda:
        "envs/phispy.yaml"
    shell:
        "scripts/phispy/PhiSpy.py -i {input} -o prophage_prediction/{wildcards.sample} -t 25 "

rule summarize_prophage_prediction:
    input:
        pr=expand("prophage_prediction/{sample}/prophage_coordinates.tsv", sample=SAMPLES)
    output:
        spr="prophage_prediction/prophage_summary.tsv"
    run:
        import csv
        print("Saving file to tsv format...")
        head = ["Sample","Prophages"]
        # write file
        with open('prophage_prediction/prophage_summary.tsv', 'w', newline='') as f_output:
            tsv_output = csv.writer(f_output, delimiter='\t')
            tsv_output.writerow(head)
            for i in input.pr:
                filepath=i
                #get number of prophages
                n_prophages = len(open(filepath).readlines())

                #get filename alias
                sample = filepath.split("/")[-2]
                data = [sample, n_prophages]
                print("sample:",sample," | prophages:",n_prophages)
                tsv_output.writerow(data)
        print("Done!")

rule summarize_genomic_islands:
    input:
        gi=expand("genomic_islands/{sample}_GI.gff3", sample=SAMPLES)
    output:
        sgi="genomic_islands/GI_summary.tsv"
    run:
        import csv
        print("Saving file to tsv format...")
        head = ["Sample","GIs"]
        # write file
        with open(output.sgi, 'w', newline='') as f_output:
            tsv_output = csv.writer(f_output, delimiter='\t')
            tsv_output.writerow(head)
            for i in input.gi:
                filepath=i
                #get number of prophages
                n_gi = (len(open(filepath).readlines(  ))) -1

                #get filename alias
                sample = filepath.split("_")[-2]
                sample = sample.split("/")[-1]
                data = [sample, n_gi]
                print("sample:",sample," | genomic_islands:",n_gi)
                tsv_output.writerow(data)
        print("Done!")
