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
struct CL_node
    {
     
      int copy_mode;
      struct CL_node *c;
      struct CL_node *p;
      struct CL_node *l;
      struct CL_node *r;
      int seq;
      int res;
      int free;
};

typedef struct CL_node CL_node;
Alignment * add_constraint2aln ( Alignment *A, int s1, int r1, int s2, int r2);
Alignment * graph_aln (Alignment *A, Constraint_list *CL, Sequence *S);
Alignment* graph2aln (Alignment *A, CL_node *G, Sequence *S);
CL_node ***add_constraint2graph_aln (CL_node ***G, int s1, int r1, int s2, int r2);
CL_node * shift_segment ( CL_node *S, int segL, int shiftL);

int  is_graph_gap_column(CL_node *S);
CL_node * remove_graph_gap_column (CL_node *S);
CL_node * swap_gap_in_graph ( CL_node*S, CL_node *E);

CL_node * declare_cl_nodes ( int len, int seq);
CL_node * insert_gap_columns (CL_node *S, int d);
int get_node_distance ( CL_node *S, CL_node *E);
CL_node ***aln2graph (Alignment *A);
CL_node *vfree_graph (CL_node *S);
CL_node *vfree_cl_node ( CL_node *N);
