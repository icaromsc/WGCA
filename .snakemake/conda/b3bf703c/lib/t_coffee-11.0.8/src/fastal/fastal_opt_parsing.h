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
// #include "string.h"

struct Fastal_arguments
{
// 	char *args[2];
	//IO


	char *sequence_file;
	char *tree_file;
	char *output_file;
	int tree_out;

	char *method;
	int is_dna;
	double gop;
	double gep;



	char *diag_method;
// 	Tree Computation
// 	int retree;
	int gap_iterate;
	int tree_only;
	char *tree_method;
	int tree_param1;
	int tree_param2;


	//Scoring
	char *mat;
	int agreement_score;
	int evaluate;
	int score;
	int num_ref_aln;
	int num_seq_in_ref;
	char *aln_ref;
	char *aln2test;
};




void tree_parse(struct Fastal_arguments *arguments, char* param);



void arg_parse (int argc, char **argv, struct Fastal_arguments *arguments);

