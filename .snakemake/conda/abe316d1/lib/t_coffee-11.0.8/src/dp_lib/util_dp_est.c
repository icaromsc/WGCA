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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>

#include "io_lib_header.h"
#include "util_lib_header.h"
#include "define_header.h"
#include "dp_lib_header.h"



int evaluate_est_order (Sequence *S, char *concat, Constraint_list *CL, int ktuple)
    {
	int a;
        static char *alphabet;
	int  *hasched_seq, *hasched_seq1, *hasched_seq2;
	int  *lu_seq, *lu_seq1, *lu_seq2;
	int pos_ktup1, pos_ktup2;
	double score=0;
	int n_ktup;
	int n_dots=0;
	
	if ( !alphabet)alphabet=get_alphabet ( concat, alphabet);
	n_ktup=(int)pow ( (double)alphabet[0]+1, (double)ktuple);
	
	hasch_seq (concat,&hasched_seq, &lu_seq,ktuple, alphabet);
	hasched_seq1=hasched_seq2=hasched_seq;
	lu_seq1=lu_seq2=lu_seq;
	


	for ( a=1; a< n_ktup; a++)
	    {
		pos_ktup1=lu_seq1[a];
		
		while (TRUE)
		    {
		    
		     if (!pos_ktup1)break;
		     pos_ktup2=lu_seq2[a];
		     while (pos_ktup2) 
		            {
			    score+=abs ((int)(pos_ktup1-pos_ktup2));
			    pos_ktup2=hasched_seq2[pos_ktup2];
			    n_dots++;
			    }
		  pos_ktup1=hasched_seq1[pos_ktup1];
		  }
	    }
	
	score=(score/(double)(n_dots*strlen(concat)))*100000;
	vfree ( hasched_seq);
	vfree(lu_seq);


	return score;
    }
	
