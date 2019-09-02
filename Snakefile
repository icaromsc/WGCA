#SnakeMake clinical genomic annotation workflow

def list_files():
    import os
    l=os.listdir('data/samples/')
    li=[x.split('.')[0] for x in l]
    return li

SAMPLES = list_files()

# rule get_files:
#     input: myfunc
#     output: "someoutput.{somewildcard}.txt"
#     shell: "..."


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
        report("virulence_genes/{sample}.tsv", category="Virulence factors")
    conda:
        "envs/abricate.yaml"
    shell:
        "abricate --minid=90 --mincov=60 --db=vfdb {input} > {output}"

rule summarize_virulence:
    input:
        expand("virulence_genes/{sample}.tsv", sample=SAMPLES)
    output:
        "virulence_genes/summary.tsv"
    conda:
        "envs/abricate.yaml"
    shell:
        "abricate --summary {input} > {output}"

rule plasmid_prediction:
    input:
        "data/samples/{sample}.fasta"
    output:
        report("plasmid_prediction/{sample}.tsv", category="Plasmid Prediction")
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
        log = "resistome_prediction/{sample}"
        #txt = "resistome_prediction/{sample}.txt",
        #json = "resistome_prediction/{sample}.json"
    shell:
        "docker run -v $PWD:/data -t quay.io/biocontainers/rgi:4.2.2--py35ha92aebf_1 rgi main -i data/{input} -o data/resistome_prediction/{wildcards.sample} -t contig --clean --debug > {output.log}"

rule resistome_all:
    input:
        expand("data/samples/{sample}.fasta", sample=SAMPLES)
    output:
        directory("res_prediction/")
    run:
        for i,s in zip(input,SAMPLES):
             #print("input file:",i,"\n name:",s)
             shell("docker run -v $PWD:/data -t quay.io/biocontainers/rgi:4.2.2--py35ha92aebf_1 rgi main -i data/{i} -o data/res_prediction/{s} -t contig --clean --debug > res_prediction/{s}")

rule generate_resistome_heatmap:
    input:
        logs = expand("resistome_prediction/{sample}", sample=SAMPLES),
        #jsons = expand("resistome_prediction/{sample}.json", sample=SAMPLES),
        #tabs = expand("resistome_prediction/{sample}.txt", sample=SAMPLES),
        dir = "resistome_summary/"
    output:
        log = "resistome_summary/RGI_heatmap"
    run:
        shell("cp {input.logs} resistome_summary/")
        shell("cp -r resistome_prediction/.  resistome_summary")
        shell("docker run -v $PWD:/data -t quay.io/biocontainers/rgi:4.2.2--py35ha92aebf_1 rgi heatmap --input data/{input.dir} --output data/{output} --category drug_class --cluster samples -d text > {output}")


rule summary_results:
    input:
        p="plasmid_prediction/summary.tsv",
        v="virulence_genes/summary.tsv",
        r="resistome_summary/RGI_heatmap",
        gi=expand("genomic_islands/{sample}_GI.gff3", sample=SAMPLES)
    output:
        r="WGCA_analysis_result/RGI_heatmap",
        v=report("WGCA_analysis_result/virulence_summary.tsv", caption="report_description/virulence.rst", category="Virulence factors"),
        p=report("WGCA_analysis_result/plasmid_summary.tsv", caption="report_description/plasmid.rst", category="Plasmid Prediction"),
        t=report("WGCA_analysis_result/RGI_heatmap-"+str(len(SAMPLES))+".png", caption="report_description/heatmap.rst" , category="Antimicrobial Resistance")
    run:
        shell("cp {input.p} {output.p}")
        shell("cp {input.v} {output.v}")
        shell("cp {input.r} {output.r}")
        shell("cp resistome_summary/RGI_* WGCA_analysis_result/")
        shell("cp {input.gi} WGCA_analysis_result/")

rule genome_annotation:
    input:
        "data/samples/{sample}.fasta"
    output:
        "genome_annotation/{sample}.gbk"
    conda:
        "envs/prokka.yaml"
    shell:
        "prokka --force --outdir genome_annotation/ --usegenus --Genus Enterococcus --prefix {wildcards.sample} {input}"

# rule genomic_island_prediction_docker:
#     input:
#         "genome_annotation/{sample}.gbk"
#     output:
#         report("genomic_islands/{sample}", category="Genomic Islands")
#     shell:
#         "docker run -v $PWD:/data -i -t quay.io/biocontainers/islandpath:1.0.4--pl526_0 islandpath data/{input} data/{output}_GI.tsv > {output}"

rule genomic_island_prediction:
    input:
        "genome_annotation/{sample}.gbk"
    output:
        report("genomic_islands/{sample}_GI.gff3", category="Genomic Islands")
    conda:
        "envs/island_path.yaml"
    shell:
        "islandpath {input} {output}"
