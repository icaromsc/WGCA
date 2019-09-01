# WGCA
Bioinformatics Workflow for Whole Genome Clinical annotation of bacterias including: Virulence and resistance genes


## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites
- Miniconda3 or conda >=4.7.11
- Docker version >=18.06.1-ce


## Configuration
- Create a conda environment to use SnakeMake:
```
conda env create -f envs/WGCA_main.yaml -n jamira
```
- activate the environment:

```
conda activate jamira
```


## How to run the pipeline:
- Run full pipeline:
```
snakemake -j 4 --use-conda
```
- Generate a summary of the results in HTML format:
```
snakemake -n --report myresults.html
```

## Authors

* **Ícaro Castro** - *Initial work* - [PurpleBooth](https://github.com/icaromsc)
