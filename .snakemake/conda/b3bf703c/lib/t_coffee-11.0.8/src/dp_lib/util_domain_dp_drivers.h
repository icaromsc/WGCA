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
Constraint_list *prepare_cl_for_moca ( Constraint_list *CL);
Alignment ** moca_aln ( Constraint_list *CL);
Alignment * extract_domain ( Constraint_list *CL);
Alignment * interactive_domain_extraction ( Constraint_list *CL);
int print_moca_interactive_choices ();

Alignment * approximate_domain ( int min_start, int max_start, int step_start,int min_len, int max_len, int step_len, int *best_start, int *best_len, int *best_score, Constraint_list *CL);
 
int measure_domain_length ( Constraint_list *CL,Alignment *IN, int start, int min_size, int max_size, int step);
Alignment *extract_domain_with_coordinates ( Alignment *RESULT,int start, int len, Constraint_list *CL);
int get_starting_point ( Constraint_list *CL);

Alignment * find_domain_coordinates (Constraint_list *CL, int *start, int *len);
Alignment * extend_domain ( Constraint_list *CL, int *start, int *len, int dstart, int dlen);
Alignment * modify_domain ( Constraint_list *CL, Alignment *IN, int *start, int *len, int dstart, int dlen);

int * analyse_sequence ( Constraint_list *CL);
