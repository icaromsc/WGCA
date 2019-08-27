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
#ifndef __UTIL_DP_GOTOH_NW_H
#define __UTIL_DP_GOTOH_NW_H 
/*pair wise aln implementations*/

int idscore_pairseq (char *s1, char *s2, int gop, int gep, int **m, char *mode);
int idscore_pair_wise (Alignment *A,int*ns, int **l_s,Constraint_list *CL);
int gotoh_pair_wise    (Alignment *A,int*ns, int **l_s,Constraint_list *CL);
int glocal_pair_wise ( Alignment *A, int *ns, int **l_s, Constraint_list *CL);
int gotoh_pair_wise_lgp ( Alignment *A, int *ns, int **l_s, Constraint_list *CL);
int test_pair_wise (Alignment *A, int *ns, int **l_s, Constraint_list *CL);

int glocal2_pair_wise (Alignment *A,int*ns, int **ls,Constraint_list *CL);
int linked_pair_wise ( Alignment *A, int *ns, int **l_s, Constraint_list *CL);
int linked_pair_wise_collapse ( Alignment *A, int *ns, int **l_s, Constraint_list *CL);
int cl2pair_list_ecl_ext_pc ( Alignment *A, int *ns, int **ls, Constraint_list *CL, int ***list_in, int *n_in);
int procoffee_pair_wise ( Alignment *A, int *nsi, int **lsi, Constraint_list *CL);


/////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////                                                                           ///////////////
///////////////                                                                           ///////////////
///////////////                       Profile_PW                                          ///////////////
///////////////                                                                           ///////////////
///////////////                                                                           ///////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int **aln2prf (Alignment *A, char *matrix);
char *add_sequence2prf (char *seq, char *al,int **prf, int lj, int gop, int gep);

#endif 