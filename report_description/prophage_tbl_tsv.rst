The file contains all the genes of the genome.
The tenth colum represents the status of a gene. If this column is 1 then the gene is a phage like gene; otherwise it is a bacterial gene.


This file has 16 columns:
(i) fig_no: the id of each gene;
(ii) function: function of the gene;
(iii) contig;
(iv) start: start location of the gene;
(v) stop: end location of the gene;
(vi) position: a sequential number of the gene (starting at 1);
(vii) rank: rank of each gene provided by random forest;
(viii) my_status: status of each gene based on random forest;
(ix) pp: classification of each gene based on their function;
(x) Final_status: the status of each gene. For prophages, this column has the number of the prophage as listed in prophage.tbl above; If the column contains a 0 we believe that it is a bacterial gene.

If we can detect the att sites, the additional columns will be:
(xi) start of attL;
(xii) end of attL;
(xiii) start of attR;
(xiv) end of attR;
(xv) sequence of attL;
(xvi) sequence of attR.
