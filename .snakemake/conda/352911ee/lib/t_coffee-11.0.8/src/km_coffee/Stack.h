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
#ifndef STACK_H_
#define STACK_H_

// #include "km_util.h"

typedef struct
{
	size_t size;
	size_t reserved;
	void **data;
	void *last;
} Stack;


/**
 * \brief Initializes the stack.
 * \return A pointer to a new stack.
 */
Stack*
Stack_init();

/**
 * \brief Adds a new element to the stack.
 * \param stack The stack to which the new element should be added.
 * \param data A pointer to the object to add.
 */
void
push(Stack *stack, void *data);

/**
 * \brief Return the first element on the stack (The last one added).
 * \param stack The stack.
 * \return A pointer ot the topmost element.
 */
void*
top(Stack *stack);

/**
 * \brief Removes the topmost element from the stack.
 *
 * \param stack The stack to delete.
 * \return Pointer to the element just removed from the stack.
 */
void *
pop(Stack *stack);

/**
 * \brief Deletes the stackit self and frees the memory it requires.
 * \param stack The stack to free.
 * \warning Elements still on the stack are not freed!
 */
void
delStack(Stack *stack);
#endif
