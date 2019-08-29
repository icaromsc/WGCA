docker run -v $PWD:/data -i -t quay.io/biocontainers/rgi:4.2.2--py35ha92aebf_1 rgi main -i data/data/samples/V583.fasta -o data/resistome_prediction/V583 -t contig --clean
