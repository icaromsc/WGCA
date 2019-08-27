# WGCA
SnakeMake workflow for Whole Genome Clinical annotation of bacterias including: Virulence and resistance genes

# Dependencies:
- Miniconda3 or conda 4.7.11


# Configuration
- Create a conda environment to use SnakeMake:

conda env create -f envs/WGCA_main.yaml -n jamira

- activate the environment:

conda activate jamira


# How to run the pipeline:
- Just run the following command:

snakemake -n

- Generate a summary of the results in HTML format:

snakemake -n --report myresults.html
