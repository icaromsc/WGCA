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
{
	///field saving the positions [x1,y1,l1,x2,y2,l2,...]
	int *segments;
	/// points to the current used segment
 	int *current_pos;
	/// saves the previous diagonal position.
	int prev_position;
	/// diagonal number
// 	int diagonal_num;
}
Segment;


Segment* extend_diagonals(Diagonal *diagonals, int *num_diagonals, int l1, int l2);
int seq_pair2blast_diagonal2(char *seq_file_name1, char *seq_file_name2, Diagonal **diagonals, int *dig_length, int l1, int l2, int is_dna);

int ** segments2int(Segment *diagonals, int num_diagonals, char *seq1, char *seq2, Fastal_profile *profile1, Fastal_profile *profile2, int *num_points, Fastal_param *param_set);
