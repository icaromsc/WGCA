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
/*********************************************************************************************/
/*                                                                                           */
/*         STRUCTURES FOR HSEARCH                                                            */
/*                                                                                           */
/*********************************************************************************************/
#define FIND           0
#define ADD            1
#define REMOVE         2
#define DECLARE        3
#define MARK           4
#define UNMARK         5
#define FREE           6
#define FREE_STACK     7
#define FREE_ALL       8
#define FREE_MARK      9
#define INFO           10
     
struct HaschT
{
  int ne;
  struct Hasch_entry **p;
};
typedef struct HaschT HaschT;

struct Hasch_entry
{
  struct Hasch_entry *n;
  struct Hasch_entry *p;
  int k;
  struct Hasch_data  *data;
  struct Hasch_data * (*free_data)(struct Hasch_data *); 
  struct Hasch_data * (*declare_data)(struct Hasch_entry*);
  int tag;
};
typedef struct Hasch_entry Hasch_entry;
struct Char_node
{
 struct Char_node **c;
 int key;
 
};
typedef struct Char_node Char_node;

HaschT * hcreate ( int n_elements,struct Hasch_data * declare_data(struct Hasch_entry *), struct Hasch_data *free_data(struct Hasch_data *) );
HaschT *hdestroy (HaschT *T,struct Hasch_data * declare_data(struct Hasch_entry *), struct Hasch_data *free_data(struct Hasch_data *) );
Hasch_entry* hsearch (HaschT *T, int k, int action, struct Hasch_data * declare_data(struct Hasch_entry *), struct Hasch_data *free_data(struct Hasch_data *) );
Hasch_entry * extract_hasch_entry_from_list (Hasch_entry *e, struct Hasch_data * declare_data(struct Hasch_entry *), struct Hasch_data *free_data(struct Hasch_data *) );
Hasch_entry * insert_hasch_entry_in_list (Hasch_entry *p, Hasch_entry *e, Hasch_entry *n, struct Hasch_data * declare_data(struct Hasch_entry *), struct Hasch_data *free_data(struct Hasch_data *) );
Hasch_entry * allocate_hasch_entry (Hasch_entry *e, int action,struct Hasch_data * declare_data(struct Hasch_entry *), struct Hasch_data *free_data(struct Hasch_data *) );




 
int string2key (char *s, Char_node *n);
Char_node * declare_char_node (int action);


 
