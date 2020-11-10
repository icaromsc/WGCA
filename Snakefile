#SnakeMake clinical genomic annotation workflow
import pathlib

def list_files():
    import os
    l=os.listdir('data/samples/')
    li=[x.split('.')[0] for x in l]
    li_unique=set(li)
    li_f=(list(li_unique))
    return li_f

SAMPLES = list_files()

#Creat temp dirs if not exists
pathlib.Path('results').mkdir(parents=True, exist_ok=True)
pathlib.Path('results/genome_annotation/').mkdir(parents=True, exist_ok=True)
pathlib.Path('results/genome_islands/').mkdir(parents=True, exist_ok=True)
pathlib.Path('results/plasmid_prediction/').mkdir(parents=True, exist_ok=True)
pathlib.Path('results/prophage_prediction/').mkdir(parents=True, exist_ok=True)
pathlib.Path('results/resistome_prediction/').mkdir(parents=True, exist_ok=True)
pathlib.Path('results/seeds/').mkdir(parents=True, exist_ok=True)
pathlib.Path('results/virulence_prediction/').mkdir(parents=True, exist_ok=True)

# Define default rule to run full pipeline
rule all:
    input:
        "results/WGCA_analysis_result/plasmid_summary.tsv",
        "results/WGCA_analysis_result/virulence_summary.tsv",
        "results/WGCA_analysis_result/RGI_heatmap",
        "jamira_integrative_results.zip"


rule virulence_identification:
    input:
        "data/samples/{sample}.fasta"
    output:
        #report("virulence_prediction/{sample}.tsv", category="Virulence factors")
        "results/virulence_prediction/{sample}.tsv"
    conda:
        "envs/abricate.yaml"
    shell:
        "abricate --minid=90 --mincov=60 --db=vfdb {input} > {output}"

rule summarize_virulence:
    input:
        expand("results/virulence_prediction/{sample}.tsv", sample=SAMPLES)
    output:
        "results/virulence_prediction/summary.tsv"
    conda:
        "envs/abricate.yaml"
    shell:
        "abricate --summary {input} > {output}"

rule plasmid_prediction:
    input:
        "data/samples/{sample}.fasta"
    output:
        #report("plasmid_prediction/{sample}.tsv", category="Plasmid Prediction")
        "results/plasmid_prediction/{sample}.tsv"
    conda:
        "envs/abricate.yaml"
    shell:
        "abricate --minid=60 --mincov=90 --db=plasmidfinder {input} > {output}"

rule summarize_plasmid_prediction:
    input:
        expand("results/plasmid_prediction/{sample}.tsv", sample=SAMPLES)
    output:
        "results/plasmid_prediction/summary.tsv"
    conda:
        "envs/abricate.yaml"
    shell:
        "abricate --summary {input} > {output}"

rule resistome_prediction:
    input:
        "data/samples/{sample}.fasta"
    output:
        log = "results/resistome_prediction/{sample}",
        #txt = report("resistome_prediction/{sample}.txt", category="Resistance prediction")
        txt = "results/resistome_prediction/{sample}.txt"
        #txt = "resistome_prediction/{sample}.txt",
        #json = "resistome_prediction/{sample}.json"
    conda:
        "envs/rgi.yaml"
    shell:
        "rgi main -i {input} -o results/resistome_prediction/{wildcards.sample} -a DIAMOND -t contig --clean --debug > {output.log}"

rule generate_resistome_heatmap:
    input:
        logs = expand("results/resistome_prediction/{sample}", sample=SAMPLES),
        dir = "results/resistome_prediction/"
    output:
        "results/resistome_prediction/RGI_heatmap"
    conda:
        "envs/rgi.yaml"
    shell:
        "rgi heatmap --input {input.dir} --output {output} --category drug_class --cluster samples -d text > {output}"


rule summary_results:
    input:
        p="results/plasmid_prediction/summary.tsv",
        v="results/virulence_prediction/summary.tsv",
        r="results/resistome_prediction/RGI_heatmap",
        #gi=expand("genomic_islands/{sample}_GI.gff3", sample=SAMPLES),
        #rt=expand("resistome_summary/{sample}.txt", sample=SAMPLES),
        #pr=expand("prophage_prediction/{sample}/prophage_coordinates.tsv", sample=SAMPLES),
        spr="results/prophage_prediction/prophage_summary.tsv",
        sgi="results/genomic_islands/GI_summary.tsv"
    output:
        r="results/WGCA_analysis_result/RGI_heatmap",
        v=report("results/WGCA_analysis_result/virulence_summary.tsv", caption="report_description/virulence.rst", category="General"),
        p=report("results/WGCA_analysis_result/plasmid_summary.tsv", caption="report_description/plasmid.rst", category="General"),
        t=report("results/WGCA_analysis_result/RGI_heatmap-"+str(len(SAMPLES))+".png", caption="report_description/heatmap.rst" , category="General"),
        #rr=report(expand("WGCA_analysis_result/{sample}.tsv", sample=SAMPLES), category="Resistance"),
        compact=report("jamira_integrative_results.zip", caption="report_description/report.rst", category="General"),
        spr=report("results/WGCA_analysis_result/prophage_summary.tsv",caption="report_description/report.rst", category="General"),
        rgi=report("results/WGCA_analysis_result/GI_summary.tsv", caption="report_description/report.rst", category="General")
    run:

        shell("cp {input.p} {output.p}")
        shell("cp {input.v} {output.v}")
        shell("cp {input.r} {output.r}")
        shell("cp results/resistome_prediction/RGI_* results/WGCA_analysis_result/")
        shell("cp {input.sgi} results/WGCA_analysis_result/")
        #shell("cp {input.rt} WGCA_analysis_result/")
        shell("cp {input.spr} results/WGCA_analysis_result/")
        shell("cd results/WGCA_analysis_result/ ; rename 's/.txt/.tsv/' *")
        #for i,s in zip(input.pr,SAMPLES):
        #    shell("cp {i} WGCA_analysis_result/{s}_prophage_coordinates.tsv")
        shell("zip -r jamira_integrative_results results/plasmid_prediction/ results/prophage_prediction/ results/virulence_prediction/ results/resistome_prediction/ results/genomic_islands/")

rule genome_annotation:
    input:
        "data/samples/{sample}.fasta"
    output:
        "results/genome_annotation/{sample}.gbk"
    conda:
        "envs/prokka.yaml"
    shell:
        "prokka --force --outdir results/genome_annotation/ --cpus 1 --usegenus --Genus Enterococcus --compliant --prefix {wildcards.sample} {input}"

rule genomic_island_prediction:
    input:
        "results/genome_annotation/{sample}.gbk"
    output:
        #report("genomic_islands/{sample}_GI.gff3", category="Genomic Islands")
        "results/genomic_islands/{sample}_GI.gff3"
    conda:
        "envs/island_path.yaml"
    shell:
        "islandpath {input} {output}"

rule convert_gbk_to_seed:
    input:
        "results/genome_annotation/{sample}.gbk"
    output:
        directory("results/seeds/{sample}")
    conda:
        "envs/phispy.yaml"
    shell:
        "python scripts/phispy/genbank_to_seed.py {input} {output}"

rule prophage_prediction:
    input:
        "results/seeds/{sample}"
    output:
        #d = dir("prophage_prediction/{sample}"),
        r1 = "results/prophage_prediction/{sample}/prophage.tbl",
        #r2 = report("prophage_prediction/{sample}/prophage_coordinates.tsv", category="Prophages"),
        r2 = "results/prophage_prediction/{sample}/prophage_coordinates.tsv",
        r3 = "results/prophage_prediction/{sample}/prophage_tbl.tsv"
    conda:
        "envs/phispy.yaml"
    shell:
        "scripts/phispy/PhiSpy.py -i {input} -o results/prophage_prediction/{wildcards.sample} -t 25 "

rule summarize_prophage_prediction:
    input:
        pr=expand("results/prophage_prediction/{sample}/prophage_coordinates.tsv", sample=SAMPLES)
    output:
        spr="results/prophage_prediction/prophage_summary.tsv"
    run:
        import csv
        print("Saving file to tsv format...")
        head = ["Sample","Prophages"]
        # write file
        with open('results/prophage_prediction/prophage_summary.tsv', 'w', newline='') as f_output:
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
        gi=expand("results/genomic_islands/{sample}_GI.gff3", sample=SAMPLES)
    output:
        sgi="results/genomic_islands/GI_summary.tsv"
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
