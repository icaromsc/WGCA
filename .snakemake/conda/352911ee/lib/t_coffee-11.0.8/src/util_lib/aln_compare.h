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
typedef struct
{   Alignment *A;
    Alignment *B;
    Alignment *sim_A;
    Sequence  *S;
    Structure *ST;
/*PARAMETERS*/
    char ***grep_list;
    int n_greps;

    char *sim_aln;
    char *alignment1_file;
    char *alignment2_file;
    
    char *io_format;

    int n_structure;
    char **struct_file;
    char **struct_format;
    int *n_symbol;
    char ***symbol_list;

/*LIST VARIABLES*/
    int **code_A;
    int **code_B;
    int n_elementsA;
    int n_elementsB;
    
    int **end_index;
    int **start_index;
/*RESULTS_VARIABLES*/
    int **tot_count;
    int **pos_count;
    int ***pw_tot_count;
    int ***pw_pos_count;
    int *glob;
    int **pw_glob;
/*IO VARIABLES*/
    int n_categories;
    char ***category;
    char *category_list;
    int *n_sub_categories;
    char sep_l;
    char sep_r;
/*Sims VARIABLES*/
    float **sim;
    float **sim_param;
    char *sim_matrix;
    
    int sim_n_categories;
    char ***sim_category;
    char *sim_category_list;
    int *sim_n_sub_categories;
}Result;


#define MAX_N_CATEGORIES 100
#define MAX_N_STRUC      100
    

    

int aln_compare (int argc, char *argv[]);
int **analyse_distance ( Alignment *A, int **dis);

Structure * read_structure (char *fname, char *format, Alignment *A,Alignment *B, Structure *ST, int n_symbols, char **symbol_table);


int is_in_struct_category ( int s1, int s2, int r1, int r2, Structure *ST, char **cat, int n_sub_cat);
char * get_structure_residue (int s, int r, Structure *S);
int parse_category_list ( char *category_list, char ***category, int *sub_n_categories);
int struc_matches_pattern ( char *struc, char *pattern);
float **get_aln_compare_sim ( Alignment *A, Structure *S, char **cat, int n_cat, char *matrix);
float **analyse_sim ( Alignment *A, float **dis);

/*Output*/
FILE *output_format (char *iof, FILE *fp, Result *R);
FILE *output_pair_wise_sequence_results (FILE *fp,  Result *R);
FILE *output_sequence_results (FILE *fp,  Result *R);
FILE *output_total_results (FILE *fp,  Result *R);
FILE *output_header (FILE *fp, Result *R);
FILE *output_large_header ( FILE *fp, Result *R);

/*Parameter Checking*/
int is_a_struc_format (char *format);
void get_separating_char ( char s, char *l, char *r);
void output_informations ();

int check_configuration4program();
