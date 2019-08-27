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
#ifndef KM_UTIL_H_
#define KM_UTIL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>


/**
 * \brief Wrapper for fopen.
 *
 * \param name_f The name of the file to open.
 * \param mode The mode in which to open the file
 * \return The opend File. On failure an error message is printed and the program exits.
 */
FILE *
my_fopen(char *name_f, char *mode);

/**
 * \brief Wrapper for the malloc function.
 * \param size The size of the memory block to allocate
 * \return Pointer to the newly allocated block of memory. On failure an error message is printed and the program exits.
 */
void *
my_malloc(size_t size);

/**
* \brief Wrapper for the realloc function.
* \param size The size of the memory block to allocate
* \return Pointer to the newly allocated block of memory. On failure an error message is printed and the program exits.
*/
void *
my_realloc(void *p, size_t size);

/**
* \brief Wrapper for the calloc function.
* \param size The size of the memory block to allocate
* \return Pointer to the newly allocated block of memory. On failure an error message is printed and the program exits.
*/
void *
my_calloc ( size_t num, size_t size );

/**
 * \brief Makes a temporary file.
 *
 * In case of failure, the program exits.
 * \param templatee The template to used for making the temporary file.
 * \param function The function from where this was called (For error message)
 */
char *
my_make_temp_dir(char *templatee, char *function);





#endif

