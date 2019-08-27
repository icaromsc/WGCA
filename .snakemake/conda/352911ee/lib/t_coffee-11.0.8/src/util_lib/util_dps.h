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
struct Dps_result
    {
      int njobs;
      struct Dps_job **dps_job;
};
typedef struct Dps_result Dps_result;

struct Dps_job
    {
      int JobId;
      struct Constraint_list *CL;
      char *input_file;
      char *output_file;
};
typedef struct Dps_job Dps_job;

struct Dps_result *seq2list_DPS (struct Constraint_list *CL,char *method, char *aln_command, char *seq_command, char *weight, Dps_result *dps_result);
struct Constraint_list * gather_results_DPS ( Dps_result *DPS, struct Constraint_list *CL);
Dps_result *declare_dps_result ( int naln, Dps_result *dps);
