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
#ifndef CLASSES_H_
#define CLASSES_H_

#include <string.h>
#include <stdio.h>

// #include "km_util.h"

// Single Seq
/**
 * \brief A stuct to save a sequence
 */
typedef struct
{
	char *name; /// The sequence name
	char *seq; /// The sequence
	size_t size; /// The size occupied by the sequence
	size_t reserved; /// The reserved size
}Seq;


/**
 * \brief initalizes a Sequence
 * \param name The name of the sequence
 * \param reserve The amount of memory to reserve
 */
Seq*
init_Seq(char *name, int reserve);

/**
 * \brief Appends a piece of sequence to a Sequence.
 * \param seq The sequence
 * \param sequence The piece to append.
 */
void
append(Seq *seq, char *sequence);


/// Set of sequences
typedef struct
{
	Seq **seqs; /// Array of pointers to sequences
	size_t  n_seqs; /// number of sequence in the set
	size_t reserved; /// reserved memory for seqs
} SeqSet;

/**
 * \brief reads a fasta sequence
 * \param seq_f The sequence file
 * \return pointer to the sequence set
 */
SeqSet*
read_fasta(char *seq_f);

/**
 * \brief frees all memory used by this set
 * \param set The sequence set.
 */
void
delSeqSet(SeqSet *set);

#endif
