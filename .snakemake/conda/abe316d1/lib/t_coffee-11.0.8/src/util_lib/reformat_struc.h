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
char * process_repeat (char *aln, char *seq, char *pdb);
char     * normalize_pdb_file  (char *name, char *seq,char *out_file);
Ca_trace * trim_ca_trace (Ca_trace *st, char *seq );

Ca_trace * read_ca_trace (char *file, char *seq_field );
Ca_trace * simple_read_ca_trace (char *file );
Ca_trace * hasch_ca_trace             ( Ca_trace *T);
Ca_trace * hasch_ca_trace_nb          ( Ca_trace *T);
Ca_trace * hasch_ca_trace_bubble      ( Ca_trace *T);
Ca_trace * hasch_ca_trace_transversal ( Ca_trace *TRACE);

float get_closest_vdw_contact ( Atom *A, Atom*B);
float get_atomic_distance ( Atom *A, Atom*B);
int   residues2contacts (Atom *A, Atom*B, float probe);
float ** trace2ca_distances(Ca_trace *T, float max);
float ** trace2contacts(Ca_trace *T, float probe);
float ** trace2best_contacts(Ca_trace *T, float probe );
float ** trace2closest_contacts (Ca_trace *T, float probe);
float ** trace2count_contacts(Ca_trace *T, float probe);


float** print_contacts ( char  *file1, char *file2, float T);
char *  map_contacts ( char  *file1, char *file2, float T);
int * identify_contacts (Ca_trace *ST1,Ca_trace *ST2, float T);
Sequence *seq2contacts4lignads ( Sequence *S, float T);
char *string2contacts (char *seq,char *name,char *comment, float T);
char **struc2nb (char *name,char *seq, char *comment, float Threshold, char *atom_list, char *output);
char **struclist2nb (char *name,char *seq, char *comment, float Threshold, char *atom_list, char *output);

float atom2radius (char *t);
