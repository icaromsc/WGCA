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

#include <stdlib.h>
#include <time.h>

#include "classes.h"
#include "kmeans.h"
#include "Vector.h"

#include "Stack.h"

#ifdef _OPENMP
	#include<omp.h>
#endif


static char *km_tmp_dir = NULL;
static char *km_cwd =NULL;


typedef struct
{
	KM_node *node;
	size_t id;
}Node_pair;


/**
 * \brief Prints the generated tree to a given file

 * The tree only contains the vector numbers so the vector set is needed to get the sequence names. The sequence set is needed to get the actual sequences.
 * \param root The root note of the tree to print.
 * \param vecs The vector set.
 * \param seq_set The sequence set.
 * \param out_f The file to write the file into.
 *
 */

void
print_km_tree(KM_node *root, int *vecs, const SeqSet *seq_set, char *out_f);


/**
 * \brief This function contains the code to produce a KM-Coffee alignment.
 * \param seq_f The sequence file.
 * \param k The maximum size of the profile clusters.
 * \param k_leaf the maximum size of the leaf clusters.
 * \param method The method to use for the alignment procedure.
 * \param aln_f The output alignment file.
 * \param n_core The number of cores to use (OPEN-MP for kmeans/fork in T-Coffee)
 * \param gapopen The gapopening costs
 * \param gapext The gapextension costs
 * \param init The method to use to initialize the k-means prototypes.
 * \return EXIT_SUCCESS on success else EXIT_FAILURE
 */
int
km_coffee_align3(char *seq_f, int k, int k_leaf, char *method, char *aln_f, int n_cores, int gapopen, int gapext, char *init);





