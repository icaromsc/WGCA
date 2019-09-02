# WGCA
Bioinformatics Workflow for Whole Genome Clinical annotation of bacterias including: Virulence and resistance genes

[![Snakemake](https://img.shields.io/badge/Snakemake-≥5.5.4-1abc9c?style=flat-square)](https://snakemake.bitbucket.io)
[![Open Source Love png1](https://badges.frapsoft.com/os/v1/open-source.png?v=103)](https://github.com/ellerbrock/open-source-badges/)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-yellow.svg)](https://GitHub.com/Naereen/StrapDown.js/graphs/commit-activity)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites
[![Generic badge](https://img.shields.io/badge/Docker-≥18.06-blue.svg)](https://www.docker.com/)
[![Generic badge](https://img.shields.io/badge/Conda-≥4.7.11-sss.svg)](https://docs.conda.io/en/latest/miniconda.html)

- Miniconda3 or conda >=4.7.11
- Docker version >=18.06.1-ce


## Configuration
- Create a conda environment to use SnakeMake:
```
conda env create -f envs/config.yaml -n jamira
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

[![forthebadge](https://forthebadge.com/images/badges/built-with-science.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/made-with-python.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/60-percent-of-the-time-works-every-time.svg)](https://forthebadge.com)
