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
Sequence *pavie_seq2random_seq (Sequence *S, char *subst); 
double **pavie_seq2pavie_aln(Sequence *S,char *mat, char *mode);
Alignment *pavie_seq2pavie_sort ( Sequence *S, char *mat, char *mode);
Alignment* pavie_seq2pavie_msa  ( Sequence *S, char *mat, char *mode);
NT_node pavie_seq2pavie_tree ( Sequence *S, char *mat, char *mode);
int **pavie_seq2trained_pavie_mat(Sequence *S, char *param);
int pavie_pair_wise (Alignment *A,int *ns, int **l_s,Constraint_list *CL );
Sequence *pavie_seq2noisy_seq (Sequence *S, int val,char *subst); 
