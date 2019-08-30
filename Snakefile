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


# Define default rule to run the complete pipeline
rule all:
    input:
        "WGCA_analysis_result/plasmid_summary.tsv",
        "WGCA_analysis_result/virulence_summary.tsv"


rule virulence_identification:
    input:
        "data/samples/{sample}.fasta"
    output:
        "virulence_genes/{sample}.tsv"
    conda:
        "envs/abricate.yaml"
    shell:
        "abricate --minid=90 --mincov=60 --db=vfdb {input} > {output}"

rule summarize_virulence:
    input:
        expand("virulence_genes/{sample}.tsv", sample=SAMPLES)
    output:
        "virulence_genes/summary.tsv"
    shell:
        "abricate --summary {input} > {output}"

rule plasmid_prediction:
    input:
        "data/samples/{sample}.fasta"
    output:
        "plasmid_prediction/{sample}.tsv"
    conda:
        "envs/abricate.yaml"
    shell:
        "abricate --minid=60 --mincov=60 --db=plasmidfinder {input} > {output}"


rule summarize_plasmid_prediction:
    input:
        expand("plasmid_prediction/{sample}.tsv", sample=SAMPLES)
    output:
        "plasmid_prediction/summary.tsv"
    conda:
        "envs/abricate.yaml"
    shell:
        "abricate --summary {input} > {output}"

# rule resistome_prediction:
#     input:
#         "data/samples/{sample}.fasta"
#     output:
#         #out = temp("resistome_prediction/{sample}"),
#         txt = "resistome_prediction/{sample}.txt",
#         json = "resistome_prediction/{sample}.json"
#     shell:
#         "docker run -v $PWD:/data -t quay.io/biocontainers/rgi:4.2.2--py35ha92aebf_1 rgi main -i data/{input} -o data/resistome_prediction/{wildcards.sample} -t contig --clean"

# rule resistome:
#     input:
#         "data/samples/{sample}.fasta"
#     output:
#         #out = temp("resistome_prediction/{sample}"),
#         txt = "resistome/{sample}.txt",
#         json = "resistome/{sample}.json"
#     singularity:
#         "docker://quay.io/biocontainers/rgi:4.2.2--py35ha92aebf_1"
#     shell:
#         "rgi main -i {input} -o resistome/{wildcards.sample} -t contig --clean"

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

# rule generate_resistome_heatmap:
#     input:
#         "resistome_prediction/"
#     output:
#         log = temp("resistome_prediction/RGI_heatmap")
#     shell:
#         "docker run -v $PWD:/data -t quay.io/biocontainers/rgi:4.2.2--py35ha92aebf_1 rgi heatmap --input data/{input} --output data/{output} --category drug_class --cluster samples -d text > {output}"


rule generate_resistome_heatmap:
    input:
        logs = expand("resistome_prediction/{sample}", sample=SAMPLES),
        #jsons = expand("resistome_prediction/{sample}.json", sample=SAMPLES),
        #tabs = expand("resistome_prediction/{sample}.txt", sample=SAMPLES),
        dir = "resistome_summary/"
    output:
        log = temp("resistome_summary/RGI_heatmap")
    run:
        shell("cp {input.logs} resistome_summary/")
        shell("cp -r resistome_prediction/.  resistome_summary")
        shell("docker run -v $PWD:/data -t quay.io/biocontainers/rgi:4.2.2--py35ha92aebf_1 rgi heatmap --input data/{input.dir} --output data/{output} --category drug_class --cluster samples -d text > {output}")


rule summary_results:
    input:
        r="plasmid_prediction/summary.tsv",
        v="virulence_genes/summary.tsv"
    output:
        v="WGCA_analysis_result/virulence_summary.tsv",
        r="WGCA_analysis_result/plasmid_summary.tsv"
    shell:
        "cp {input.r} {output.r} ; cp {input.v} {output.v}"
