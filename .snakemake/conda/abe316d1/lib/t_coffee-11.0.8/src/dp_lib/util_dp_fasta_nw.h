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

typedef struct hseq* SeqHasch;

typedef struct hseq
{
  SeqHasch hl[256];
  int  n;
  int  *l;
} hseq;

int ** ktup_dist_mat ( char **seq, int nseq, int ktup, char *type);
int ** evaluate_diagonals_for_two_sequences ( char *seq1, char *seq2,int maximise,Constraint_list *CL,int ktup);
int ** evaluate_diagonals ( Alignment *A, int *ns, int **l_s, Constraint_list *CL,int maximise,int n_groups, char **group_list,int ktup);
int ** evaluate_segments_with_ktup  ( Alignment *A, int *ns, int **l_s, Constraint_list *CL,int maximise,int n_groups, char **group_list,int ktup);
int ** evaluate_diagonals_with_ktup ( Alignment *A, int *ns, int **l_s, Constraint_list *CL,int maximise,int n_groups, char **group_list,int ktup);

int ** evaluate_diagonals_with_clist ( Alignment *A, int *ns, int **l_s, Constraint_list *CL,int maximise,int n_groups, char **group_list,int ktup);

int * flag_diagonals (int l1, int l2, int **sorted_diag,float T, int window);                
int * extract_N_diag (int l1, int l2, int **sorted_diag, int n_chosen_diag, int window);

int hasch_seq(char *seq1, int **hs, int **lu,int ktup, char *alph);
int fasta_gotoh_pair_wise (Alignment *A,int*ns, int **l_s,Constraint_list *CL);
int cfasta_gotoh_pair_wise (Alignment *A,int*ns, int **l_s,Constraint_list *CL);
int very_fast_gotoh_pair_wise (Alignment *A,int*ns, int **l_s,Constraint_list *CL);

int make_fasta_gotoh_pair_wise (Alignment *A,int*ns, int **l_s,Constraint_list *CL, int *diag);
/*********************************************************************/
/*                                                                   */
/*                         KTUP_DP                                   */
/*                                                                   */
/*                                                                   */
/*********************************************************************/

int precomputed_pair_wise (Alignment *A,int*ns, int **l_s,Constraint_list *CL);
int ktup_pair_wise (Alignment *A,int*ns, int **l_s,Constraint_list *CL);
int ktup_comparison ( char *seq1, char *seq2, int ktup);
HaschT* hasch_sequence ( char *seq1, int ktup);

SeqHasch * seq2hasch (int i,char *seq, int ktup, SeqHasch *H);
Constraint_list * hasch2constraint_list (Sequence*S, Constraint_list *CL);
SeqHasch *cleanhasch       (SeqHasch *H);
int hasch2sim        (SeqHasch *H, int nseq);
