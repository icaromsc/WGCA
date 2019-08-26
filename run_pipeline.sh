#execute pipeline workflow
snakemake WGCA_analysis_result/res_summary.tsv WGCA_analysis_result/vir_summary.tsv --use-conda
#generate report in HTML file
snakemake --report pipeline3.html  WGCA_analysis_result/res_summary.tsv WGCA_analysis_result/vir_summary.tsv
#generate DAG workflow images
snakemake --dag WGCA_analysis_result/res_summary.tsv WGCA_analysis_result/vir_summary.tsv | dot -Tsvg > resistance_and_virulence_dag_final_3.svg
#just virulence
snakemake virulence_genes/summary.tsv --use-conda

