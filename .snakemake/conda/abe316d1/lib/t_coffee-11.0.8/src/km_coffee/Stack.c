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
// #include "Stack.h"
#include "km_coffee_header.h"

Stack * Stack_init()
{
	Stack *stack = (Stack*) my_malloc(sizeof(Stack));
	stack->reserved = 0;
	stack->size=0;
	stack->data=NULL;
	stack->last=NULL;
	return stack;
}

void push(Stack *stack, void *data)
{
	if (stack->reserved +1 > stack->size)
	{
		stack->reserved += 10;
		stack->data=(void**) realloc(stack->data, stack->reserved);
	}
	stack->data[stack->size] = data;
	stack->last=stack->data[stack->size];
	++stack->size;
}

void * pop(Stack *stack)
{
	--stack->size;
	if (stack->size == 0)
		stack->last=NULL;
	else
		stack->last=stack->data[stack->size-1];
	return stack->data[stack->size];
}

void delStack(Stack *stack)
{
	free(stack->data);
	free(stack);
}