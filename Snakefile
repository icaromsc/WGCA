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


rule virulence_identification:
    input:
        "data/samples/{sample}.fasta"
    output:
        "virulence_genes/{sample}.tsv"
    shell:
        "abricate --minid=90 --db=vfdb {input} > {output}"

rule summarize_virulence:
    input:
        expand("virulence_genes/{sample}.tsv", sample=SAMPLES)
    output:
        "virulence_genes/summary.tsv"
    shell:
        "abricate --summary {input} > {output}"

rule resistance_identification:
    input:
        "data/samples/{sample}.fasta"
    output:
        "resistance_genes/{sample}.tsv"
    conda:
        "envs/abricate.yaml"
    shell:
        "abricate --minid=90 --db=card {input} > {output}"


rule summarize_resistance:
    input:
        expand("resistance_genes/{sample}.tsv", sample=SAMPLES)
    output:
        "resistance_genes/summary.tsv"
    shell:
        "abricate --summary {input} > {output}"

rule summary_results:
    input:
        r="resistance_genes/summary.tsv",
        v="virulence_genes/summary.tsv"
    output:
        v="WGCA_analysis_result/vir_summary.tsv",
        r="WGCA_analysis_result/res_summary.tsv"
    shell:
        "cp {input.r} {output.r} ; cp {input.v} {output.v}"
