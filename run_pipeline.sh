#execute pipeline workflow
snakemake WGCA_analysis_result/plasmid_summary.tsv WGCA_analysis_result/virulence_summary.tsv --use-conda
#generate report in HTML file
snakemake WGCA_analysis_result/plasmid_summary.tsv WGCA_analysis_result/virulence_summary.tsv --report pipeline_virulence_and_plasmid_all_genomes.html
#generate DAG workflow images
snakemake --dag WGCA_analysis_result/plasmid_summary.tsv WGCA_analysis_result/virulence_summary.tsv | dot -Tsvg > plasmid_and_virulence_dag_final.svg
#just virulence prediction
snakemake virulence_genes/summary.tsv --use-conda
#just plasmid prediction
snakemake plasmid_prediction/summary.tsv --use-conda
