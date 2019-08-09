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





/**
 * \brief Struct to save the features for a set of sequences.
 * 
 */
typedef struct
{
	/// The number of this sequence.
	int seq_number;
	/// The feature to use in qsort.
	int *elem_2_compare;
	/// An element of features.
	double *features;
}
Cluster_info;


int				cluster_recursive(int start, int end, Cluster_info* matrix, int dim, double *mean, double *variance, int *elem_2_compare, FILE* tree_f, int *node);
int*			recode_sequence(char * seq, int seq_length, int *char2value, int alphabet_size, int word_length);
double*			get_features(int *recoded_seq, int seq_length, int k_tup, int max_coding, int max_dist, int num_features);
Cluster_info*	feature_extract(char *seq_file_name, int max_dist, int k_tup, int *char2value, int alphabet_size, int *elem_2_compare, int *num_seq_p, int num_features);
void			compute_oligomer_distance_tree(char *seq_file_name, int* char2value, char *tree_file_name, int max_dist, int word_length, int alphabet_size);

