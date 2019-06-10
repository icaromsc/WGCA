#SnakeMake clinical genomic annotation workflow
SAMPLES = ["MP2-6", "MP5-8", "MP8-1"]
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
    shell:
        "abricate --minid=90 --db=card {input} > {output}"

rule summarize_resistance:
    input:
        expand("resistance_genes/{sample}.tsv", sample=SAMPLES)
    output:
        "resistance_genes/summary.tsv"
    shell:
        "abricate --summary {input} > {output}"
