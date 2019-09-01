#execute pipeline workflow
snakemake -p -j 4 --use-conda
#generate report in HTML file
snakemake --report pipeline_virulence_resistance_and_plasmid_all_genomes.html
#generate DAG workflow images
snakemake --dag | dot -Tsvg > plasmid_resistance_and_virulence_dag_workflow.svg
snakemake --dag | dot -Tsvg > plasmid_resistance_and_virulence_dag_workflow_min.svg
#just virulence prediction
snakemake virulence_genes/summary.tsv -j 4 --use-conda
#just plasmid prediction
snakemake plasmid_prediction/summary.tsv -j 4 --use-conda
#just resistome prediction
snakemake resistome_prediction/B9 resistome_summary/RGI_heatmap -j 4 
