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
struct Dp_Model
{
  int *diag;

  int TG_MODE;
  int F_TG_MODE;
  int gop;
  int gep;
  int f_gop;
  int f_gep;
  int nstate;
  int START;
  int END;
  
  char**model_comments;
  int **model;
  int **model_properties;
  int **bounded_model;
  int (***model_emission_function)(Alignment*, int **, int, int*, int, int **, int, int*, int, struct Constraint_list *);

  int LEN_I;
  int LEN_J;
  int DELTA_I;
  int DELTA_J;
  int EMISSION;
  int START_EMISSION;
  int TERM_EMISSION;
  
  int ALN_TYPE;
  Constraint_list *CL;
  /*Associated Functions*/
  
  /*To Deprecate*/
  int UM;
  
  int TYPE;
  int F0;
  int F1;
  
  
  int NON_CODING;
  int INSERTION;
  int DELETION;
  int CODING0;
  int CODING1;
  int CODING2;
  

};
typedef struct Dp_Model Dp_Model;

struct Dp_Result
{
  int *traceback;
  int len;
  int score;
  Dp_Model *Dp_model;
};
typedef struct Dp_Result Dp_Result;

Dp_Result * make_fast_generic_dp_pair_wise (Alignment *A, int*ns, int **l_s,Dp_Model *M);

Constraint_list* free_dp_model  (Dp_Model *D);
Dp_Result * free_dp_result (Dp_Result *D );
