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
/*
*	
*	Rand.c
*	
*	-	linear and additive congruential random number generators
*		(see R. Sedgewick, Algorithms, Chapter 35)
*
*	Implementation: R. Fuchs, EMBL Data Library, 1991
*	
*/



#define m1	10000
#define m	100000000

/* linear congruential method
*	
*	linrand() returns an unsigned long random number in the range 0 to r-1
*/



static unsigned long mult(unsigned long p, unsigned long q)
{
	unsigned long p1,p0,q1,q0;
	
	p1 = p/m1; p0 = p % m1;
	q1 = q/m1; q0 = q % m1;
	return (unsigned long)((((p0*q1 + p1*q0) % m1) * m1 + p0*q0) % m);
}


/* additive congruential method
*	
*	addrand() returns an unsigned long random number in the range 0 to r-1
*	The random number generator is initialized by addrandinit()
*/

static unsigned long j;
static unsigned long a[55];

unsigned long addrand(unsigned long r)
{
int x,y;
/*        fprintf(stdout,"\n j = %d",j);  */
	j = (j + 1) % 55;
/*        fprintf(stdout,"\n j = %d",j);  */
	x = (j+23)%55;
	y = (j+54)%55;
	a[j] = (a[x] + a[y]) % m;
/*	a[j] = (a[(j+23)%55] + a[(j+54)%55]) % m;  */
/*        fprintf(stdout,"\n a[j] = %d",a[j]);     */
	return( ((a[j] / m1) * r) / m1 );
}

void addrandinit(unsigned long s)
{
	a[0] = s;
	j = 0;
	do {
		++j;
		a[j] = (mult(31,a[j-1]) + 1) % m;
	} while (j<54);
}
