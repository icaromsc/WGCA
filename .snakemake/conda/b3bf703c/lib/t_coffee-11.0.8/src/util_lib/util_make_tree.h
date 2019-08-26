/******************************COPYRIGHT NOTICE*******************************/
/*  (c) Centro de Regulacio Genomica                                                        */
/*  and                                                                                     */
/*  Cedric Notredame                                                                        */
/*  12 Aug 2014 - 22:07.                                                                    */
/*All rights reserved.                                                                      */
/*This file is part of T-COFFEE.                                                            */
/*                                                                                          */
/*    T-COFFEE is free software; you can redistribute it and/or modify                      */
/*    it under the terms of the GNU General Public License as published by                  */
/*    the Free Software Foundation; either version 2 of the License, or                     */
/*    (at your option) any later version.                                                   */
/*                                                                                          */
/*    T-COFFEE is distributed in the hope that it will be useful,                           */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of                        */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         */
/*    GNU General Public License for more details.                                          */
/*                                                                                          */
/*    You should have received a copy of the GNU General Public License                     */
/*    along with Foobar; if not, write to the Free Software                                 */
/*    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA             */
/*...............................................                                           */
/*  If you need some more information                                                       */
/*  cedric.notredame@europe.com                                                             */
/*...............................................                                           */
/******************************COPYRIGHT NOTICE*******************************/
NT_node ** seq2cw_tree ( Sequence *S, char *file);
NT_node ** make_nj_tree (  Alignment *A,int **distances,int gop, int gep, char **out_seq, char **out_seq_name, int out_nseq, char *tree_file, char *tree_mode);
NT_node ** make_upgma_tree (  Alignment *A,int **distances,int gop, int gep, char **out_seq, char **out_seq_name, int out_nseq, char *tree_file, char *tree_mode);


NT_node ** int_dist2nj_tree (int **distances, char **out_seq_name, int out_nseq,  char *tree_file);
NT_node ** float_dist2nj_tree (float **distances, char **out_seq_name, int out_nseq,  char *tree_file);
NT_node ** dist2nj_tree (double **distances, char **out_seq_name, int out_nseq,  char *tree_file);

//////////////////////////////////////////////////////////////////////////////
//
//                              km
///////////////////////////////////////////////////////////////////////////////

double **aln2km_vector (Alignment *A, char *mode, int *dim);
NT_node ** seq2km_tree (Sequence *S, char *file);
NT_node ** seq2co_tree (Sequence *S, char *file);

NT_node aln2km_tree (Alignment *A, char *mode, int nboot);
NT_node rec_km_tree (char **name,int n,int dim,double **V, int nboot);
  

NT_node ** int_dist2upgma_tree (int **mat, Alignment *A, int nseq, char *fname);
NT_node **     dist2upgma_tree (double **mat, char **name, int nseq, char *fname);
NT_node upgma_merge (int **mat, NT_node *NL, int *used, int *n, int N);

void nj_tree(char **tree_description, int nseq);
void fast_nj_tree(char **tree_description);
void slow_nj_tree(char **tree_description);

void print_phylip_tree(char **tree_description, FILE *tree, int bootstrap);
void two_way_split(char **tree_description, FILE *tree, int start_row, int flag, int bootstrap);
void guide_tree(char *fname, double **saga_tmat, char **sag_seq_name, int saga_nseq);



NT_node split2upgma_tree (Split **S, Alignment *A, int nseq, char *fname);
NT_node split_upgma_merge (Alignment *A, Split **S, NT_node *NL, int *used, int *n, int N);
float get_split_dist ( Alignment *A, NT_node L, NT_node R, Split **S) ;

Alignment * upgma_tree_aln  (Alignment*A, int nseq, Constraint_list *CL);
int ** dist_mat2best_split (int **mat, int nseq);
int upgma_node_heap (NT_node X);
