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
int evaluate_aln_gibbs   ( Alignment *A, Constraint_list *CL);
int evaluate_moca_domain ( Alignment *A, Constraint_list *CL);
int moca_residue_pair_extended_list ( Constraint_list *CL, int s1, int r1, int s2, int r2);
int moca_evaluate_matrix_score      ( Constraint_list *CL, int s1, int r1, int s2, int r2);
int moca_slow_get_dp_cost ( Alignment *A, int**pos1, int ns1, int*list1, int col1, int**pos2, int ns2, int*list2, int col2, Constraint_list *CL);

int **cache_cl_with_moca_domain (Alignment *A, Constraint_list *CL);
Alignment *make_moca_nol_aln ( Alignment *A, Constraint_list *CL);
/*********************************************************************************************/
/*                                                                                           */
/*         DOMAIN Z SCORE EVALUATION                                                         */
/*                                                                                           */
/*********************************************************************************************/

int evaluate_domain_aln_z_score (Alignment *A, int start, int end,Constraint_list *CL, char *alphabet);
int evaluate_domain_aln  ( Alignment *A, int start, int end,Constraint_list *CL);



int unpack_seq_residues ( int *s1, int *r1, int *s2, int *r2, int **packed_seq_lu);
Alignment * unpack_seq_aln ( Alignment *A,Constraint_list *C);
