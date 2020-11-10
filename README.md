<h1 align="center">
  <img src="https://github.com/icaromsc/WGCA/blob/master/src/jamira_logo.jpeg" width="40%" height="40%"/>
</h1>

# JAMIRA WORKFLOW
JAMIRA is a Bioinformatics Workflow for Integrative Exploration of Genomic Features of bacterias including:
- Virulence factors;
- Resistome profile;
- Plasmid prediction;
- Prophage prediction;
- Genomic Islands prediction;


[![Snakemake](https://img.shields.io/badge/Snakemake-≥5.5.4-1abc9c?style=flat-square)](https://snakemake.bitbucket.io)
[![Open Source Love png1](https://badges.frapsoft.com/os/v1/open-source.png?v=103)](https://github.com/ellerbrock/open-source-badges/)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-yellow.svg)](https://GitHub.com/Naereen/StrapDown.js/graphs/commit-activity)


### Prerequisites
[![Generic badge](https://img.shields.io/badge/Conda-≥4.9.0-sss.svg)](https://docs.conda.io/en/latest/miniconda.html)


## Getting Started
To run JAMIRA you need to install Conda.
JAMIRA Workflow is intended to be executed in a Conda environment to ensure data reproducibillity and modularization among different genomic tools used in this pipeline.

## Configuration
After complete Conda installation you need to add the bioconda channel
- Add the bioconda channel with the following commands:
```
conda config --add channels defaults
conda config --add channels bioconda
conda config --add channels conda-forge
```

- Create a conda environment for JAMIRA with the following command:
```
conda env create -f envs/config.yaml -n jamira
```
- activate your JAMIRA environment:

```
conda activate jamira
```

- Install SnakeMake:

```
mamba install -c conda-forge -c bioconda snakemake
```

Congratulations!
The JAMIRA workflow is ready to be used!

## How to run JAMIRA workflow:
Complete JAMIRA workflow can be executed with a single concise command line call.

```
snakemake --use-conda
```

- Addionally the user can run the complete workflow specyfing the number of cores (e.g 4 cores):
```
snakemake -j 4 --use-conda
```





## Additional features

### Generate a summary of jamira workflow in HTML format:

After completing the workflow execution, the pipeline provides an option to generate a summary web report in HTML format. The interactive report can be generated with the following command call:
```
snakemake -n --report myresults.html
```

### Generate a visual representation of JAMIRA workflow:

You can create a Direct Acyclic Graph (DAG) representation to visualize all steps executed with jamira workflow

- Display your DAG representation:
```
snakemake -j 4 --use-conda -n --dag | dot -Tsvg | display
```

- Save your DAG representation in SVG format:
```
snakemake -j 4 --use-conda -n --dag | dot -Tsvg > dag.svg
```

# JAMIRA WORKFLOW MODULES
JAMIRA incorporate a collection of modules for specific data analysis tasks commonly applied in comparative genomic studies, such as: (i) virulence genes identification; (ii) antimicrobial resistance genes identification; (iii) plasmid sequences prediction; (iv) genomic islands prediction and (v) prophage prediction.

## Genomic Islands Prediction
The genomic islands prediction module searches large segments of exogenous DNA inserted into bacterial genomes, well known as genomic islands (GIs), frequently associated with particular adaptations of microbes that are of medical, agricultural, or environmental importance.

- In this workflow we use IslandPath-DIMOB:

IslandPath-DIMOB is a standalone software to predict genomic islands in bacterial and archaeal genomes based on the presence of dinucleotide biases and mobility genes.

#### Please cite
[Bertelli and Brinkman, 2018](https://doi.org/10.1093/bioinformatics/bty095)  
[Hsiao et al., 2005](http://journals.plos.org/plosgenetics/article?id=10.1371/journal.pgen.0010062)

## Prophage Prediction

The prophage prediction module searches for mobile elements, responsible for carrying and disseminate virulence factors and antimicrobial resistance genes between bacteria.

- In this workflow we use PhiSpy to identify the most likely prophage regions in Bacterial genomes.

#### Please cite
[Akhter et al., 2012](https://doi.org/10.1093/nar/gks406)

## Antimicrobial Resistance Identification
The antimicrobial resistance identification module enables the prediction of complete resistome profiles from genomic data.

- In this workflow we use RGI to predict resistomes based on homology and SNP models.

#### Please cite
[Jia et al., 2017](https://doi.org/10.1093/nar/gkw1004)

## Plasmid Prediction
The plasmid prediction module searches for well-known replicon sequences to detect related plasmids that are often associated with antimicrobial resistance in clinically relevant bacterial pathogens.

- In this workflow we use ABRICATE to perform a BLAST against a curated database of plasmid sequences, PlasmidFinder database (Carattoli et al., 2014).

#### Please cite
[Seemann, 2018](https://github.com/tseemann/abricate)
[Carattoli et al., 2014](https://doi.org/10.1128/aac.02412-14)



## Virulence factors identification
The plasmid prediction module searches for well-known replicon sequences to detect related plasmids that are often associated with antimicrobial resistance in clinically relevant bacterial pathogens.

- In this workflow we use ABRICATE to perform a BLAST against a curated database of virulence factors related to bacterial pathogens,  VFDB database (Chen et al., 2016).

#### Please cite
[Seemann, 2018](https://github.com/tseemann/abricate)
[Chen et al., 2016](https://dx.doi.org/10.1093/nar/gkv1239)


## Authors
* **Ícaro Castro** - *Workflow development* - [Github](https://github.com/icaromsc)
* **Rafaella Bueno** - *Web server development* - [Github](https://github.com/rafaellabueno)
* **Robson Ruiz** - *Web server development* - [Github](https://github.com/robsonruiz)

[![forthebadge](https://forthebadge.com/images/badges/built-with-science.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/made-with-python.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/60-percent-of-the-time-works-every-time.svg)](https://forthebadge.com)
