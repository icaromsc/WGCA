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
char *PerlScriptName[]={"rec_sum.pl","count.pl","p\
rocess_list.pl","make_license.pl","CCsed.script","\
msa2bootstrap.pl","t_coffee_dpa","t_coffee_dpa2","\
tc_generic_method.pl","rnapdb2protpdb.pl","generic\
_method.tc_method","clustalw_method.tc_method","ex\
tract_from_pdb","install.pl","clean_cache.pl","nat\
ure_protocol.pl","mocca","dalilite.pl","wublast.pl\
","blastpgp.pl","ncbiblast_lwp.pl","wublast_lwp.pl\
","RNAplfold2tclib.pl","fasta_seq2RNAplfold_templa\
tefile.pl","fasta_seq2hmmtop_fasta.pl","fasta_seq2\
consan_aln.pl","clustalw_aln2fasta_aln.pl","msf_al\
n2fasta_aln.pl","blast_aln2fasta_aln.pl","blast_xm\
l2fasta_aln.pl","fasta_aln2fasta_aln_unique_name.p\
l","newick2name_list.pl","excel2fasta.pl","any_fil\
e2unix_file.pl","EndList"};char *PerlScriptFile[]=\
{"use File::Copy;\nuse Env qw(HOST);\nuse Env qw(H\
OME);\nuse Env qw(USER);\n$x_field=0;\n$y_field=1;\
\n$y_field_set=1;\n$nyf=1;\n\n$interval=0;\n$file=\
\"stdin\";\n\n$print_avg=1;\n$print_sd=0;\n$print_\
sum=0;\n$print_n=0;\nforeach $value ( @ARGV)\n    \
{\n	if ($value ne $ARGV[$np]) \n	    {\n	    ;\n	 \
   }\n	elsif($value eq \"-print_all\")\n	    {\n	 \
   $print_sd=$print_avg=$print_n=$print_sum=1;\n	 \
   $np++;\n	    }\n	elsif($value eq \"-print_sum\"\
)\n	    {\n	    $print_sum=1;\n	    $print_avg=0;\\
n	    $np++;\n	    }\n	elsif($value eq \"-print_n\\
")\n	    {\n	    $print_n=1;\n	    $print_avg=0;\n\
	    $np++;\n	    }\n	elsif($value eq \"-print_avg\
\")\n	    {\n	    $print_avg=1;\n	    $print_avg=0\
;\n	    $np++;\n	    }\n	elsif($value eq \"-sd\")\\
n	    {\n	    $print_sd=1;\n	    $print_avg=0;\n	 \
   $np++;\n	    }\n	elsif($value eq \"-h\")\n	    \
{\n	    $header=1;\n	    $np++;\n	    }\n	elsif ($\
value eq \"-i\")\n	    {\n	    $interval= $ARGV[++\
$np];\n	    $np++;\n    	    }\n	elsif ($value eq \
\"-r\")\n	    {\n	    $min= $ARGV[++$np];\n	    $m\
ax= $ARGV[++$np];\n	    $np++;\n    	    }\n	\n	el\
sif ($value eq \"-x\")\n	    {\n	    $x_field= $AR\
GV[++$np]-1;\n	    $np++;\n    	    }\n	elsif ($va\
lue eq \"-y\")\n	    {\n	    $nyf=0;  \n	    while\
 ($ARGV[$np+1] && !($ARGV[$np+1]=~/\\-/))\n	      \
{\n		$y_field[$nyf++]=$ARGV[++$np]-1;\n		$y_field_\
set=1;\n	      }\n\n	    $np++;\n    	    }\n	elsi\
f ($value eq \"-file\")\n	    {\n	    $file= $ARGV\
[++$np];\n	    $file_set=1;\n	    $np++;\n    	   \
 }       \n	elsif ( $value eq \"h\" ||  $value eq \
\"-h\" || $value eq \"-H\" || $value eq \"-help\" \
|| $value eq \"help\")\n	  {\n	    print STDOUT \"\
data_analyse: Analyse and discretization of data\\\
n\";\n	    print STDOUT \"       -file:    <file c\
ontaining the data to analyze>,.<def=STDIN>\\n\";\\
n	    print STDOUT \"       -x: <field containing \
the X>,...............<Def=0>\\n\";\n	    print ST\
DOUT \"       -y: <field containing the Y>,.......\
........<Def=1>\\n\";\n	    print STDOUT \"       \
-i:<Interval size on the X>,...............<Def=0>\
\\n\";\n	    print STDOUT \"       -i:<0:only one \
interval>\\n\";\n	    print STDOUT \"       -r:<Ra\
nge of the X>\\n\";\n	    print STDOUT \"       -s\
d: print standard deviation on the Y\";\n	    prin\
t STDOUT \"       -h  : print column header \\n\";\
\n	    exit (0);\n	  }\n	elsif ($value=~/-/)\n	  {\
\n	    print \"$value is not a valid FLAG[FATAL]\\\
n\";\n	    exit (0);\n	   } \n	elsif ($list eq \"\\
") \n	    {\n	    $file=$ARGV[$np];\n	    $np++;\n\
	    }\n	\n	\n      }\n\n\n\n\n\nif ($file eq \"st\
din\")\n	{\n	$remove_file=1;\n	$file=\"tmp$$\";\n	\
open (F, \">$file\");\n	while (<STDIN>)\n		{\n		pr\
int F $_;\n		}\n	close (F);\n	 \n	;}\n\n\n\n\nif (\
$interval && $max)\n  {\n    $interval_size=($max-\
$min)/$interval;\n  }\nelsif ($interval)\n  {\n   \
 open(F,$file);  \n    my $set_max=0;\n    my $set\
_min=0;\n    while (<F>)\n      {\n	my $v=$_;\n	ch\
omp($v);\n	print \"--$v--\";\n	\n	if ($v<$min ||!$\
set_min){$set_min=1;$min=$v;}\n	if ($v>$max ||!$se\
t_max){$set_max=1;$max=$v;}\n      }\n    close (F\
);\n    print \"$min $max uuuu\";\n    $interval_s\
ize=($max-$min)/$interval;\n  }\nopen(F,$file);  \\
nwhile (<F>)\n  {\n    $line=$_;\n    if (!/\\S/){\
next;}\n    @list=($line=~/(\\S+)/g);\n    \n    i\
f ($interval==0){$bin=0;}\n    else{$bin=int (($li\
st[$x_field]-$min)/($interval_size));}\n\n    \n  \
  if ($bin && $bin==$interval){$bin--;}\n    for (\
 $a=0; $a<$nyf; $a++)\n      {\n	$sum{$a}{$bin}+=$\
list[$y_field[$a]];\n	$sum2{$a}{$bin}+=$list[$y_fi\
eld[$a]]*$list[$y_field[$a]];\n	$n{$a}{$bin}++;\n \
     }\n  }\n\nif (!$interval){$interval=1;}\nfor \
( $a=0; $a<$interval; $a++)\n  {\n    printf ( \"%\
4d %4d \", $interval_size*$a, $interval_size*($a+1\
));\n    for ( $b=0; $b<$nyf; $b++)	\n      {\n	$i\
=$interval*$a;\n	if ( $n{$b}{$a}==0)\n	  {\n	    $\
avg=0;\n	    $sd=0;\n	  }\n	else\n	  {\n	    $avg=\
$sum{$b}{$a}/$n{$b}{$a};\n	    $sd=sqrt($sum2{$b}{\
$a}*$n{$b}{$a}-$sum{$b}{$a}*$sum{$b}{$a})/($n{$b}{\
$a}*$n{$b}{$a});\n	  }\n	if ($print_n) {printf \"%\
15.4f \", $n{$b}{$a};}\n	if ($print_sum){printf \"\
%15.4f \", $sum{$b}{$a};}\n	if ($print_avg){printf\
 \"%15.4f \", $avg}\n	if ($print_sd) {printf \"%15\
.4f \", $sd;}\n      }\n    printf (\"\\n\");\n  }\
\n\n\nif ( $remove_file){unlink $file;}\n","use Fi\
le::Copy;\nuse Env qw(HOST);\nuse Env qw(HOME);\nu\
se Env qw(USER);\n\nforeach $v (@ARGV){$cl.=$v;}\n\
\n\nif ( $cl=~/-k(\\d+)/){$k=$1;}\nelse {$k=1;}\ni\
f ( $cl=~/-w(\\d+)/){$w=$1;}\nelse {$w=-1;}\nif ( \
$cl=~/-p(\\d+)/){$p=$1;}\nelse {$p=-1;}\n\nwhile (\
<STDIN>)\n  {\n    @l=($_=~/(\\S+)/g);\n    $v=$l[\
$k-1];\n    if ( !$h{$v}){@ll=($v, @ll);}\n    \n \
   if ( $w==-1)\n      {$h{$v}++;}\n    else\n    \
  {$h{$v}+=$l[$w-1];}\n\n    if ($p!=-1){$print{$v\
}=$l[$p-1];}\n\n  }\nforeach $v (@ll)\n  {\n    pr\
int \"$v $print{$v} $h{$v}\\n\";\n  }\n","\nuse En\
v qw(HOST);\nuse Env qw(HOME);\nuse Env qw(USER);\\
n$random_tag=int (rand 10000)+1;\n$unique_prefix=\\
"$$.$HOST.$random_tag\";\n$queue=\"distillery.and.\
mid\";\n$monitor=0;\n$stderr_file=\"/dev/null\";\n\
$stdio_file=\"/dev/null\";\n$log_file=\"/dev/null\\
";\n$pause_time=0;\n$max_sub_jobs=60;\n$min_sub_jo\
bs=30;\n$output_all=0;\n$var='\\$';\n\nforeach $va\
lue ( @ARGV)\n    {\n	if ($value ne $ARGV[$np]) \n\
	    {\n	    ;\n	    }\n	elsif ($value eq \"-max_s\
ub_jobs\")\n	    {\n	    $max_sub_jobs= $ARGV[++$n\
p];\n	    $np++;\n    	    }	\n	elsif ($value eq \\
"-min_sub_jobs\" )\n	    {\n	    $min_sub_jobs= $A\
RGV[++$np];\n	    $np++;\n    	    }\n	elsif ($val\
ue eq \"-para\")\n	    {\n	    $para=1;\n	    $mon\
itor=1;\n	    $np++;\n    	    }\n	elsif ($value e\
q \"-monitor\") \n	    {\n	    $monitor=1;\n	    $\
np++;\n	    }\n	elsif ($value eq \"-no_monitor\") \
\n	    {\n	    $monitor=0;\n	    $np++;\n	    }\n	\
elsif ($value eq \"-queue\")\n	    {\n	    $queue=\
$ARGV[++$np];\n	    $np++;\n	    }	\n	elsif ($valu\
e eq \"-stderr_file\")\n	    {\n	    $stderr_file=\
$ARGV[++$np];\n	    $np++;\n	    }\n	elsif ($value\
 eq \"-stdio_file\")\n	    {\n	    $stdio_file=$AR\
GV[++$np];\n	    $np++;\n	    }\n	elsif ($value eq\
 \"-output_all\")\n	    {\n	    $output_all=1;\n	 \
   $np++;\n	    }\n	elsif ($value eq \"-pause\") \\
n	    {\n	    $pause_time=$ARGV[++$np];\n	    $np+\
+;\n	    }\n	elsif ($value eq \"-log\")\n	      {\\
n	       $log=1;\n	       \n	       if ($ARGV[$np+\
1]=~/\\-\\S+/) \n	          {\n		  $log_file=\"std\
err\";\n	          }\n	       else \n	          {\\
n		  $log_file=$ARGV[++$np]; \n		  ++$np;\n		 \n	 \
         }\n	      }\n	elsif ( $value eq \"-com\")\
\n	    {\n		\n		if (!$ARGV[$np+1]=~/^\\'/) { $com=\
$ARGV[++$np];}\n		else {$com=$ARGV[++$np];}\n\n	  \
   $np++;\n	    }\n	elsif ( $value eq \"-check\")\\
n	  {\n	    \n	    if (!$ARGV[$np+1]=~/^\\'/) { $c\
heck=$ARGV[++$np];}\n	    else {$check=$ARGV[++$np\
];}\n	    $np++;\n	  }\n	elsif ($com eq \"\") \n	 \
   {\n	    $com_set=1;\n	    $com=$ARGV[$np];\n	  \
  \n	    $np++;\n	    }\n	elsif ($list eq \"\") \n\
	    {\n	    $list_set=1;\n	    $list=$ARGV[$np];\\
n	    $np++;\n	    }\n	elsif ( $var_set eq \"\")\n\
	    {\n	    $var_set=1;\n	    $var=$ARGV[$np];\n	\
    $np++;\n	    }\n	}\n\n\n\n\nif ( $com eq \"\")\
{print \"You Need to Provide a Command [FATAL]\\n\\
";\n	      die;\n	     }\n\n\n\nif ($list_set==0) \
\n    {\n    $x= int (rand 100000)+1;\n    $tmp_fi\
le_name=\"tmp_file_$x\";\n    open ( TMP, \">$tmp_\
file_name\");\n    while (<STDIN>)\n      {\n	prin\
t TMP $_;\n      }\n    close (TMP);\n    open (F,\
 $tmp_file_name);\n    }\nelse \n    {\n    open (\
F, $list);\n    }\n\nif ($para==0) \n    {\n\n    \
 @tc_list= <F>;\n     close (F); \n     \n     for\
each $val(@tc_list) \n	    {\n	      \n	      \n	 \
     \n	      $loc_com=$com;\n	      if ($check){$\
loc_check=$check;}\n	      \n	      @i_val=($val=~\
/([^\\s]+)/g);\n	      \n	      if ( $#i_val==0)\n\
		{\n		  if ($check){$loc_check=~s/$var/$i_val[0]/\
g;}\n		  $loc_com=~s/$var/$i_val[0]/g;\n		}\n	    \
  else\n		{\n		  for ($n=1; $n<=$#i_val+1;$n++ )\n\
		    {\n		      \n		      $sub=\"$var$n\";\n		   \
   \n		      $loc_com=~s/$sub/$i_val[$n-1]/g;\n		 \
     if ($check){$loc_check=~s/$var/$i_val[0]/g;}\\
n		    }\n		}\n	      if ( $check && -e $loc_check\
)\n		{\n		  print STDERR \"skipping $loc_com...\\n\
\";\n		  }\n	      else\n		{\n		  system \"$loc_co\
m\";\n		}\n	    }\n    exit;\n    }\n\nelsif ($par\
a==1) \n    {\n    print STDERR \"do parallel exec\
ution of: \\\"$com $list\\\"\\n\";\n    \n    if (\
$log==1) \n	{\n	if ($log_file eq \"stdout\" || $lo\
g_file eq \"stderr\" ) \n		{\n		$log_file=\"\";\n	\
        }\n\n        else \n		{\n		system \"echo L\
OG FILE> $log_file\";\n		\n	        }\n	}\n    els\
e	\n	{\n	open ( OUT, \">/dev/null\");\n	}\n	\n    \
\n    $id=0;\n    $n_sub=0;\n    while ($val=<F>) \
\n	    {	    	    \n	    $job_log[$id]=\"$HOME/tmp\
/$unique_prefix.$id.log_file\";\n	    \n	    $job=\
$unique_prefix.\"_$id\";\n	    open (JOB, \">$job\\
");\n	    \n	    $loc_com=$com;\n	    chop $val;\n\
\n	    $loc_com=~s/\\$/$val/g;\n	 \n	    print JOB\
 \"#!/bin/csh\\n\";\n	    print JOB \"#\\$ -cwd\\n\
\";\n	    print JOB \"#\\$ -N $unique_prefix\\n\";\
\n	    if ($queue && !($queue eq \" \")) {print JO\
B \"#\\$ -l $queue\\n\";}\n	    print JOB \"#\\n\"\
;	    \n            print JOB \"$loc_com\\n\";\n	 \
   print JOB \"echo FINISHED  >> $job_log[$id]\\n\\
";\n	    print JOB \"pwd\\n\";\n	    \n	    close \
(JOB);\n	    if ( $output_all==1)\n		{\n		system \\
"qsub $job >  $unique_prefix\";		\n	        }\n	  \
  else\n		{system \"qsub $job -e $stderr_file -o $\
stdio_file >$unique_prefix\";	        \n	        }\
 \n\n\n\n	    print STDERR \"$id: $output_all\\n\"\
;\n	    $n_sub++;\n	    if ( $max_sub_jobs && $n_s\
ub==$max_sub_jobs) \n		{\n		$n_sub=monitor_process\
($min_sub_jobs,@job_log); 		 \n		\n	        }	\n	 \
  \n            unlink $unique_prefix;\n	    sleep\
 $pause_time;\n	    $id++;\n	    }\n\n    close (O\
UT);\n    close (F);\n\n    print STDERR \"Your $i\
d Jobs Have Been Submited (NAME=$unique_prefix)\\n\
\";\n    monitor_process (0, @job_log);\n    forea\
ch $file(@job_log) {if (-e $file) {unlink($file);}\
}\n    \n    }\n\nsub monitor_process ( @job_list)\
\n    {\n    my (@job_list)=@_;\n    my $min_sub_j\
obs=shift (@job_list);\n    my $n_sub_jobs;\n    m\
y $finished;\n    my $n=0;\n\n    $n_sub_jobs=-1;\\
n    $finished=0;\n    print STDERR \"\\nMonitor B\
atch: [$min_sub_jobs]\";\n       \n    while (!$fi\
nished && (($n_sub_jobs>$min_sub_jobs)|| $n_sub_jo\
bs==-1) ) \n	{\n	$finished=1;\n	$n_sub_jobs=0;\n	$\
n=0;\n	foreach $file (@job_list)\n	        {\n	\n	\
	if (-e $file){;}\n		else \n		    {\n		    $finish\
ed=0; $n_sub_jobs++;\n	            }\n	        }\n\
	system \"sleep 1\";\n        }\n    \n    return \
$n_sub_jobs;\n    }\n    \n    \nif ($tmp_file_nam\
e){unlink($tmp_file_name);}\n","\n\nforeach ($np=0\
; $np<=$#ARGV; $np++)\n    {\n    $value=$ARGV[$np\
];\n\n    if ($value eq \"-file\")\n      {\n     \
 $file= $ARGV[++$np];\n      }\n    elsif ($value \
eq \"-type\")\n      {\n        $type= $ARGV[++$np\
];\n      }\n    elsif ($value eq \"-institute\")\\
n      {\n        $institute= $ARGV[++$np];\n     \
 }\n    elsif ($value eq \"-author\")\n      {\n  \
      $author= $ARGV[++$np];\n      }\n    elsif (\
$value eq \"-date\")\n      {\n        $date= $ARG\
V[++$np];\n      }\n     elsif ($value eq \"-progr\
am\")\n      {\n        $program= $ARGV[++$np];\n \
     }\n    elsif ($value eq \"-email\")\n      {\\
n        $email= $ARGV[++$np];\n      }\n    else\\
n      {\n	print \"$value is an unkown argument[FA\
TAL]\\n\";\n	exit (1);\n      }\n  }\n\n\n\nopen F\
, $file || die;\nprint $INSTITUTE;\nif ( $type eq \
\"c\"){print \"/******************************COPY\
RIGHT NOTICE*******************************/\\n\";\
}\nif ( $type eq \"perl\"){print \"###############\
###############COPYRIGHT NOTICE###################\
###########/\\n\";}\nif ( $type eq \"txt\"){print \
\"-------------------------------COPYRIGHT NOTICE-\
-----------------------------/\\n\";}\n\n\nwhile (\
<F>)\n  {\n  s/\\$INSTITUTE/$institute/g;\n  s/\\$\
AUTHOR/$author/g;\n  s/\\$DATE/$date/g;\n  s/\\$PR\
OGRAM/$program/g;  \n  s/\\$EMAIL/$email/g;  \n  i\
f ( $type eq \"txt\"){print $_;}\n  elsif ($type e\
q \"c\"){chop $_; print \"\\/*$_*\\/\\n\";}\n  els\
if ($type eq \"perl\"){print \"\\#$_\";}\n}\nclose\
 (F);\nif ( $type eq \"c\"){print \"/*************\
*****************COPYRIGHT NOTICE*****************\
**************/\\n\";}\nif ( $type eq \"perl\"){pr\
int \"##############################COPYRIGHT NOTI\
CE##############################/\\n\";}\nif ( $ty\
pe eq \"txt\"){print \"---------------------------\
----COPYRIGHT NOTICE------------------------------\
/\\n\";}\n\n","\nwhile (<>)	\n	{\n	s/\\=cc/1234567\
89/g;\n	s/\\bcc/\\$\\(CC\\)/g;\n	s/123456789/\\=cc\
/g;\n	print $_;\n	}\n\n","$version=\"1.00\";\n$rse\
ed= int(rand(100000))+1;\n\n\nif ( $#ARGV==-1)\n  \
{\n    print \"msa2bootstrap -i <input_file> -inpu\
t <seq|msa|matrix|tree> -n <N-Boostrap> -o <outtre\
e> -tmode <nj|upgma|parsimony|ml> -dmode <kimura> \
-alignpg <t_coffee | muscle | clustalw> -rtree <fi\
le> -stype <prot|cdna|dna> -recompute -system <cyg\
win|unix>\";\n    print \"\\n\\t-i: input file, ca\
n be sequneces, msa, matrix, trees, type is specif\
ied via -input\";\n    print \"\\n\\t-input: Type \
of input data\";\n    print \"\\n\\t\\tmsa: msa in\
 fasta format\";\n    print \"\\n\\t\\tseq: comput\
e an msa with -alignpg\";\n    print \"\\n\\t\\tma\
trix: phylipp distance matrix fed directly to meth\
od -tmode [caveat: tmode=nj or upgma]\";\n    prin\
t \"\\n\\t\\ttree: list of newick trees directly f\
ed to consence in order to generate a bootstraped \
tree\";\n    \n    print \"\\n\\t-n: number of boo\
tstrap replicates\";\n    print \"\\n\\t-o: name o\
f the output tree. Files are not overwritten. Use \
-recompute to overwrite existing file\";\n    prin\
t \"\\n\\t-tmode: tree mode: nj|upgma|parsimony|ml\
\";\n    print \"\\n\\t-dmode: distance mode\";\n \
   print \"\\n\\t-alignpg: program for aligning se\
quences (t_coffee=default)\";\n    print \"\\n\\t-\
rtree: replicate tree file (default: no file)\";\n\
    print \"\\n\\t-rmsa: replicate msa file (defau\
lt: no file)\";\n    print \"\\n\\t-rmat: replicat\
e matrix file (default: no file)\";\n    print \"\\
\n\\t-stype: sequence type: protein, dna or cdna\"\
;\n    print \"\\n\\t-recompute: force files to be\
 overwritten\";\n    print \"\\n\\t-system: cygwin\
|unix\";\n      \n\n    \n    &my_exit (EXIT_FAILU\
RE);\n  }\nforeach $arg (@ARGV){$command.=\"$arg \\
";}\n\nprint \"CLINE: $command\\n\";\n$threshold=1\
00;\n$trim_msa=0;\n$stype=\"prot\";\nprint \"msa2b\
ootstrap \";\n\n$system=\"cygwin\";\nif(($command=\
~/\\-system (\\S+)/))\n  {\n    $system=$1;\n    i\
f ( $system eq \"cygwin\")\n      {\n	$exec_extens\
ion=\".exe\";\n      }\n    elsif ( $system eq \"u\
nix\")\n      {\n	$exec_extension=\"\";\n	print \"\
system=Unix\";die;\n      }\n    else\n      {\n	p\
rint \"msa2boostrap: -system=$system is an unknown\
 mode [FATAL]\\n\"; die;\n      }\n    \n    print\
 \"-system $system \";\n  }\nif(($command=~/\\-sty\
pe (\\S+)/))\n  {\n    $stype=$1;\n  }\nprint \"-s\
type=$stype \";\n\n\n\nif(($command=~/\\-i (\\S+)/\
))\n  {\n    $msa=$1;\n    print \"-i $msa \";\n  \
}\n\nif(($command=~/\\-rtree (\\S+)/))\n  {\n    $\
rtree=$1;\n    print \"-rtree=$rtree \";\n  }\n\ni\
f(($command=~/\\-rmsa (\\S+)/))\n  {\n    $rmsa=$1\
;\n  }\nif(($command=~/\\-rmat (\\S+)/))\n  {\n   \
 $rmat=$1;\n  }\n$input=\"seq\";\nif(($command=~/\\
\-input (\\S+)/))\n  {\n    $input=$1;\n  }\nprint\
 \"-input=$input \";\n\n$dmode=\"kimura\";\nif(($c\
ommand=~/\\-dmode (\\S+)/))\n  {\n    $dmode=$1;\n\
  }\nprint \"-dmode=$dmode \";\n$alignpg=\"muscle\\
";\nif(($command=~/\\-alignpg (\\S+)/))\n  {\n    \
$alignpg=$1;\n  }\nprint \"-alignpg=$dmode \";\n\n\
$tmode=\"nj\";\nif(($command=~/\\-tmode (\\S+)/))\\
n  {\n    $tmode=$1;\n  }\nprint \"-tmode=$tmode \\
";\n$recompute=0;\nif(($command=~/\\-recompute/))\\
n  {\n    $recompute=1;\n    print \"-recompute \"\
;\n  }\n\n$out=$msa;\n$out=~s/\\..*//;\n$out.=\".b\
ph\";\nif(($command=~/\\-o (\\S+)/))\n  {\n    $ou\
t=$1;\n    \n  }\nprint \"-out=$out \";\nif (-e $o\
ut && !$recompute)\n  {\n    print \"\\nNo Computa\
tion Required $out already exists\\n\";\n    &my_e\
xit (EXIT_SUCCESS);\n    \n  }\n\n$n=100;\nif(($co\
mmand=~/\\-n (\\d+)/))\n  {\n    $n=$1;\n  }\nprin\
t \"-n=$n \";\n$seed=3;\nif(($command=~/\\-s (\\d+\
)/))\n  {\n    $seed=$1;\n  }\nprint \"-s=$seed \"\
;\n\nif(($command=~/\\-run_name (\\d+)/))\n  {\n  \
  $suffix=$1;\n  }\nelse\n  {\n    $msa=~/([^.]+)/\
;\n    $suffix=$1;\n  }\nprint \"-run_name=$suffix\
\\n\";\n\n\nif ( $input eq \"seq\")\n  {\n    $seq\
=$msa;\n    $msa=\"$suffix.prot_msa\";\n    \n    \
if ($stype eq \"cdna\")\n      {\n	$cdna_seq=$seq;\
\n	$clean_cdna_seq=&vtmpnam();\n	$seq=&vtmpnam();\\
n	`t_coffee -other_pg seq_reformat -in $cdna_seq -\
action +clean_cdna >$clean_cdna_seq`;\n	`t_coffee \
-other_pg seq_reformat -in $clean_cdna_seq -action\
 +translate >$seq`;\n	\n      }\n\n    if (!-e $ms\
a || $recompute)\n      {\n	print \"\\n#####   Com\
pute an MSA With $alignpg\\n\";\n	\n	if ( $alignpg\
 eq \"t_coffee\")\n	  {`$alignpg $seq -outfile=$ms\
a >/dev/null 2>/dev/null`;}\n	elsif ( $alignpg eq \
\"muscle\")\n	  {\n	    `$alignpg -in $seq > $msa \
2>/dev/null`;\n	  }\n	elsif ( $alignpg eq \"clusta\
lw\")\n	  {\n	    `$alignpg -infile=$seq -outfile=\
$msa -quicktree >/dev/null 2>/dev/null`;\n	  }\n	e\
lsif ( $align eq \"mafft\")\n	  {\n	    `$alignpg \
$seq > $msa >/dev/null 2>/dev/null`;\n	  }\n	else\\
n	  {\n	    `$alignpg -in=$seq -outfile=$msa`;\n	 \
 }\n      }\n    if (!-e $msa)\n      {\n	print \"\
\\nError: $alignpg Could Not produce the MSA $msa \
[FATAL]\\n\";\n      }\n\n    if ($stype eq \"cdna\
\")\n      {\n	$msa2=\"$suffix.cdna_msa\";\n	`t_co\
ffee -other_pg seq_reformat -in $clean_cdna_seq -i\
n2 $msa -action +thread_dna_on_prot_aln -output fa\
sta_aln  >$msa2`;\n	$msa=$msa2;\n      }\n    \n  \
  $input=\"msa\";\n  }\n\n\n\n$seqboot_o=&vtmpnam(\
);\n$seqboot_c=&vtmpnam();\n\n$protdist_o=&vtmpnam\
();\n$protdist_c=&vtmpnam();\nif ( $input eq \"msa\
\")\n  {\n    if ($tmode eq \"nj\" || $tmode eq \"\
upgma\"){$input=\"matrix\";}\n    \n    $lmsa= &vt\
mpnam ();\n    `t_coffee -other_pg seq_reformat -i\
n $msa -output phylip_aln > $lmsa`;\n    \n    if \
( -e \"outfile\"){unlink (\"outfile\");}\n    # ru\
n seqboot\n  \n    if ( $n>1)\n      {\n	print \"R\
un SeqBoot .....\";\n	open (F, \">$seqboot_c\");\n\
	print F \"$lmsa\\nR\\n$n\\nY\\n$seed\\n\";\n	clos\
e (F);\n	`seqboot$exec_extension  < $seqboot_c`;\n\
	if ( -e \"outfile\"){ print \"[OK]\\n\";}\n	else \
{ print \"[FAILED]\\n\";&my_exit (EXIT_FAILURE);}\\
n	`mv outfile $seqboot_o`;\n      }\n    else\n   \
   {\n	`cp $lmsa $seqboot_o`;\n      }\n\n    if (\
$rmsa){`cp $seqboot_o $rmsa`;}\n    \n    if ($tmo\
de eq \"nj\" || $tmode eq \"upgma\")\n      {\n	if\
 ( $stype eq \"prot\")\n	  {\n	    # run protdist\\
n	    print \"Run Protdist [dmode=$dmode]\";\n	   \
 if ($dmode eq \"kimura\")\n	      {\n		$dmode=\"P\
\\nP\\nP\";\n	      }\n	    else\n	      {\n		prin\
t \"\\n$dmode is an unknown mode for Protdist [FAT\
AL:msa2bootstrap.pl]\\n\";\n		&my_exit (EXIT_FAILU\
RE);\n	      }\n	    open (F, \">$protdist_c\");\n\
	    if ($n>1){print F \"$seqboot_o\\n$dmode\\nM\\\
nD\\n$n\\nY\\n\";}\n	    else {printf F \"$seqboot\
_o\\n$dmode\\nY\\n\";}\n	    close (F);\n	    `pro\
tdist$exec_extension  < $protdist_c`;\n	    if ( -\
e \"outfile\"){ print \"[OK]\\n\";}\n	    else { p\
rint \"[FAILED]\\n\";&my_exit (EXIT_FAILURE);}\n	 \
   `mv outfile $protdist_o`;\n	 \n	  }\n	elsif ( $\
stype eq \"cdna\" || $stype eq \"dna\")\n	  {\n	  \
  print \"Run dnadist [dmode=default\";\n	    open\
 (F, \">$protdist_c\");\n	    if ($n>1){print F \"\
$seqboot_o\\nM\\nD\\n$n\\nY\\n\";}\n	    else {pri\
ntf F \"$seqboot_o\\nY\\n\";}\n	    close (F);\n	 \
   `protdist$exec_extension  < $protdist_c`;\n	   \
 if ( -e \"outfile\"){ print \"[OK]\\n\";}\n	    e\
lse { print \"[FAILED]\\n\";&my_exit (EXIT_FAILURE\
);}\n	    `mv outfile $protdist_o`;\n	  }\n      }\
\n  }\nelsif ( $input eq \"matrix\")\n  {\n    $pr\
otdist_o=&vtmpnam();\n    print \"MSA: $msa\\n\";\\
n    `cp $msa $protdist_o`;\n    $n=1;\n  }\n\n\n\\
n\n\n$nb_o=&vtmpnam();\n$nb_c=&vtmpnam();\nif ($in\
put eq \"matrix\" && $tmode ne \"parsimony\" && $t\
mode ne \"ml\")\n  {\n    print \"Run neighbor [tm\
ode=$tmode]\";\n\n    if ($tmode eq \"nj\")\n     \
 {\n	$tmode=\"\\nN\\nN\";\n      }\n    elsif ( $t\
mode eq \"upgma\")\n      {\n	$tmode = \"\\nN\";\n\
      }\n    else\n      {\n	print \"\\n ERROR: $t\
mode is an unknown tree computation mode\\n\";\n	&\
my_exit (EXIT_FAILURE);\n      }\n\n    open (F, \\
">$nb_c\");\n    if ($n>1){print F \"$protdist_o$t\
mode\\nM\\n$n\\n$seed\\nY\\n\";}\n    else {print \
F \"$protdist_o$tmode\\nY\\n\";}\n    close (F);\n\
\n    `neighbor$exec_extension  < $nb_c`;\n    if \
( -e \"outtree\"){ print \"[Neighbor OK]\\n\";}\n \
   else { print \"[FAILED]\\n\";&my_exit (EXIT_FAI\
LURE);}\n    `mv outtree $nb_o`;\n    unlink (\"ou\
tfile\");\n  }\nelsif ($input eq \"msa\" && $tmode\
 eq \"parsimony\")\n  {\n    if ( -e \"outfile\"){\
unlink (\"outfile\");}\n    if ( -e \"outtree\"){u\
nlink (\"outtree\");}\n    \n    if ($stype eq \"p\
rot\")\n      {\n	print \"Run protpars [tmode=$tmo\
de]\";\n	open (F, \">$nb_c\");\n	if ($n>1){print F\
 \"$seqboot_o\\nM\\nD\\n$n\\n$seed\\n10\\nY\\n\";}\
\n	else {print F \"$seqboot_o\\nY\\n\";}\n	close (\
F);\n	`protpars$exec_extension  < $nb_c`;\n      }\
\n    elsif ( $stype eq \"dna\" || $stype eq \"cdn\
a\")\n      {\n	print \"Run dnapars [tmode=$tmode]\
\";\n	open (F, \">$nb_c\");\n	if ($n>1){print F \"\
$seqboot_o\\nM\\nD\\n$n\\n$seed\\n10\\nY\\n\";}\n	\
else {print F \"$seqboot_o\\nY\\n\";}\n	close (F);\
\n	`dnapars$exec_extension  < $nb_c`;\n      }\n  \
  if ( -e \"outtree\"){ print \"[OK]\\n\";}\n    e\
lse { print \"[FAILED]\\n\";&my_exit (EXIT_FAILURE\
);}\n    `mv outtree $nb_o`;\n   unlink (\"outfile\
\");\n  }\nelsif ($input eq \"msa\" && $tmode eq \\
"ml\")\n  {\n    if ( -e \"outfile\"){unlink (\"ou\
tfile\");}\n    if ( -e \"outtree\"){unlink (\"out\
tree\");}\n    \n    if ($stype eq \"prot\")\n    \
  {\n	print \"Error: ML impossible with Protein Se\
quences [ERROR]\";\n	&my_exit (EXIT_FAILURE);\n   \
   }\n    elsif ( $stype eq \"dna\" || $stype eq \\
"cdna\")\n      {\n	print \"Run dnaml [tmode=$tmod\
e]\";\n	open (F, \">$nb_c\");\n	if ($n>1){print F \
\"$seqboot_o\\nM\\nD\\n$n\\n$seed\\n10\\nY\\n\";}\\
n	else {print F \"$seqboot_o\\nY\\n\";}\n	close (F\
);\n	`dnaml$exec_extension  < $nb_c`;\n      }\n  \
  if ( -e \"outtree\"){ print \"[OK]\\n\";}\n    e\
lse { print \"[FAILED]\\n\";&my_exit (EXIT_FAILURE\
);}\n    `mv outtree $nb_o`;\n   unlink (\"outfile\
\");\n  }\n\n\nelse\n  {\n    `cp $msa $nb_o`;\n  \
  $n=2;\n  }\n\nif ($rmsa && -e $seqboot_o){print \
\"\\nOutput List of $n Replicate MSA: $rmsa\\n\";`\
cp $seqboot_o $rmsa`;}\nif ($rmat && -e $protdist_\
o){print \"\\nOutput List of $n Replicate MATRICES\
: $rmat\\n\";`cp $protdist_o $rmat`;}\nif ($rtree \
&& -e $nb_o){print \"\\nOutput List of $n Replicat\
e TREES: $rtree\\n\";`cp $nb_o $rtree`;}\n\n\n\n$c\
on_o=&vtmpnam();\n$con_c=&vtmpnam();\nif ($n >1)\n\
  {\n    print \"Run Consense.....\";\n    open (F\
, \">$con_c\");\n    print F \"$nb_o\\nY\\n\";\n  \
  close (F);\n    `consense$exec_extension  < $con\
_c`;\n    if ( -s \"outtree\"  > 0) { print \"[OK]\
\\n\";}\n    else { print \"[FAILED]\\n\";&my_exit\
 (EXIT_FAILURE);}\n    `mv outtree $con_o`;\n    u\
nlink (\"outfile\");\n  }\nelse\n  {\n    `cp $nb_\
o $con_o`;\n  }\n\n\n`cp $con_o $out`;\nif ( !-e $\
out)\n  {\n    print \"Tree Computation failed [FA\
ILED]\\n\";\n    &my_exit (EXIT_FAILURE);\n  }\nel\
sif ($n>1)\n  {\n    print \"\\nOutput Bootstrappe\
d Tree: $out\\n\";\n    $avg=`t_coffee -other_pg s\
eq_reformat -in $out -action +avg_bootstrap`;\n   \
 $avg=~s/\\n//g;\n    print \"$avg\\n\";\n  }\nels\
e\n  {\n    print \"\\nOutput Tree: $out\\n\";\n  \
}\n\nopen (F, \"$out\");\nwhile (<F>)\n  {\n    \n\
    $tree.=$_;\n  }\nclose (F);\n$tree=~s/\\n//g;\\
nprint \"BPH: $tree\\n\";\n\n\n&my_exit (EXIT_SUCC\
ESS);\n\nsub my_exit \n  {\n    my $m=@_[0];\n    \
&clean_vtmpnam();\n    exit ($m);\n  }\nsub vtmpna\
m \n  {\n    my $file;\n\n\n    $ntmp++;\n    $fil\
e=\"tmp4msa2bootstrap.$rseed.$$.$ntmp\";\n    \n  \
  push (@tmpfile, $file);\n    return $file;\n  }\\
nsub clean_vtmpnam \n  {\n    my $t;\n    foreach \
$t (@tmpfile)\n      {\n	if ( -e $t){unlink ($t)};\
\n      }\n  }\n","use Env;\n$seq_reformat=\"t_cof\
fee -other_pg seq_reformat \";\n$VersionTag=\"1.00\
\";\n$step=1;\n$unset=\"\";\n$scoreT1=$scoreT2=$ns\
eqT=$dp_limit=$unset;\n@tl=();\nchomp($tc_version=\
`t_coffee -version`);$tc_version=~s/PROGRAM: //;\n\
\n\nprint STDERR \"\\n****************************\
*************************************\";\nprint ST\
DERR \"\\n*           HIGH LEVEL PROGRAM: T-COFFEE\
_DPA Version $VersionTag\";\nprint STDERR \"\\n*  \
         LOW  LEVEL PROGRAM: $tc_version \";\nprin\
t STDERR \"\\n************************************\
*****************************\";\n\nif (!@ARGV)\n \
 {\n    print \"t_coffee_dpa accepts every t_coffe\
e_flag.\\nType t_coffee to obtain a list\\n\";\n  \
  print \"Requires $TC_VERSION\\n\";\n    print \"\
Requires \";\n    print \"t_coffee_dpa specific fl\
ags:\\n\";\n    print \"\\t-dpa_master_aln........\
............Master alignment: provided OR computed\
\\n\";\n    print \"\\t-dpa_master_aln............\
........By default, Computed with t_coffee -very_f\
ast\\n\";\n    print \"\\t-dpa_master_aln=<file>..\
...........Use file, (must be an aln in Fasta or C\
lustalW\\n\";\n    print \"\\t-dpa_master_aln=<pro\
gram>..........Compute aln with pg -in seq -out al\
n`\\n\";\n    print \"\\t-dpa_maxnseq.............\
..........Maximum number of sequences in subgroups\
\\n\";\n    print \"\\t-dpa_min_score1............\
........Minimum Id for two sequences to be grouped\
 in ref_aln\\n\";\n    print \"\\t-dpa_min_score2.\
...................Minimum Id within a subgroup\\n\
\";\n    print \"\\t-dpa_debug....................\
.....Keep Tmp File (for debug purpose)\\n\\n\";\n \
   \n    exit (0);\n  }\nforeach $arg (@ARGV)\n  {\
\n    $arg_list.=\" $arg\";\n  }\n$arg_list=~s/[=,\
;]/ /g;\n\n\n($seq0, $arg_list)=&extract_val_from_\
arg_list(\"^\",$arg_list, \"SPLICE\",\"unset\");\n\
($seq1, $arg_list)=&extract_val_from_arg_list(\"-s\
eq\",$arg_list, \"SPLICE\",\"unset\");\n($seq2, $a\
rg_list)=&extract_val_from_arg_list(\"-in\",$arg_l\
ist, \"KEEP\",\"unset\");\n($seq3, $arg_list)=&ext\
ract_val_from_arg_list(\"-infile\",$arg_list, \"SP\
LICE\",\"unset\");\n($prf,  $arg_list)=&extract_va\
l_from_arg_list(\"-profile\",$arg_list, \"SPLICE\"\
,\"unset\");\n\n$gl{'Seq'}=$seq=&vtmpnam();#file c\
ontaining all the sequences\n\n   #1-remove sequen\
ces from -in\nif ( $arg_list =~/\\-in\\b/)\n  {\n \
   my $save, $name;\n    while($arg_list=~/\\-in\\\
b[^-]+(\\bS[\\w.]+)/)\n      {\n	$name=$1;$name=~s\
/^.//;\n	if ( !-e $name){$save.=\" S$name \";}\n\n\
	$arg_list=~s/S$name/ /;\n      }\n    $arg_list=~\
s/\\-in\\b/\\-in $save /;\n  }\n   #2-prepare \n\n\
if (!($arg_list=~/\\-outorder/))\n  {\n    \n    $\
output_cl .=\" -outorder=$seq\";\n  }\n@output_fla\
g=(\"-output\",\"-outfile\", \"-run_name\", \"-out\
order\"); \nforeach $v1 (@output_flag)\n  {\n    (\
$v2, $arg_list)=&extract_val_from_arg_list($v1,$ar\
g_list, \"SPLICE\",\"unset\");\n    if ($v2 ne \"\\
")\n      {\n\n	if ($v1 eq \"-run_name\"){$run_nam\
e=$v2;$output_cl .=\" $v1 $v2 \";}\n	elsif ( $v1 e\
q \"-outorder\")\n	  {\n	    if ( $v2 eq \"input\"\
){$v2=$seq;}\n	    $outorder=$v2;$output_cl .=\" $\
v1 $v2 \";\n	  }\n	else\n	  {\n	    $output_cl .=\\
" $v1 $v2 \";\n	  }\n      }\n }\n\n\n($dpa_master\
_aln, $arg_list)  =&extract_val_from_arg_list(\"-d\
pa_master_aln\",$arg_list, \"SPLICE\", \"t_coffee\\
");\n$dpa_master_aln=~s/\\s//g;\n($nseqT, $arg_lis\
t)           =&extract_val_from_arg_list(\"-dpa_ma\
xnseq\",$arg_list, \"SPLICE\", 30);\n($scoreT1, $a\
rg_list)         =&extract_val_from_arg_list(\"-dp\
a_min_score1\",$arg_list, \"SPLICE\", 80);\n($scor\
eT2, $arg_list)         =&extract_val_from_arg_lis\
t(\"-dpa_min_score2\"    ,$arg_list, \"SPLICE\", 3\
0);\n($dpa_limit, $arg_list)       =&extract_val_f\
rom_arg_list(\"-dpa_limit\"        ,$arg_list, \"S\
PLICE\", 0);\n($dpa_delta_id, $arg_list)    =&extr\
act_val_from_arg_list(\"-dpa_delta_id\"        ,$a\
rg_list, \"SPLICE\", 1);\n($dpa_debug, $arg_list) \
      =&extract_val_from_arg_list(\"-dpa_debug\"  \
         ,$arg_list, \"SPLICE\", 0);\n\n\n$in_seq=\
$seq0.\" \".$seq1.\" \".$seq2.\" \".$seq3;\n$in_pr\
f=(($prf ne $unset)?\"$prf \":\"\");\n&exit_dpa ((\
$in_seq eq \"\" && $in_prf eq \"\")?1:0, \"ERROR: \
You did not Provide any sequences. Use the -seq fl\
ag [FATAL: t_coffee_dpa]\\n\", EXIT_FAILURE);\n\n\\
nprint STDERR \"\\nSTART DPA COMPUTATION\";\n\n\n\\
nif ($in_seq=~/\\S+/)\n  {\n    \n    print STDERR\
 \"\\n Step $step: Gather all the sequences into t\
he tmp file: [$seq]\";$step++;	\n    &my_system (\\
"t_coffee $in_seq -convert -quiet -output fasta_se\
q -outfile=$seq -maxnseq 0\");\n  }\n\nif ( !-e $s\
eq){$seq=\"\";}\n\nif ($in_prf=~/\\S+/)\n  {\n    \
$seq_in_type=\"profile\"; \n    $seq.= $in_prf; \n\
  }\nif ($seq eq \"\"){ &exit_dpa (1, \"\\nERROR: \
No Sequence FOund. Provide Sequences with the -seq\
 flag [FATAL: t_coffee_dpa]\", EXIT_FAILURE);}\n\n\
 \n\nif ( $run_name)\n  {\n    $suffix=$run_name;\\
n  }\nelsif ($in_seq=~/\\b(S[\\w.]+\\b)/)\n  {\n  \
  my $suffix1, $sufffix2;\n    $suffix1=$suffix2=$\
1;\n    $suffix2=~s/^S//;\n    if ( -e $suffix1){$\
suffix=$suffix1;}\n    elsif ( -e $suffix2){$suffi\
x=$suffix2;}\n    else\n      {\n	$suffix=&vtmpnam\
();	\n      }\n    $suffix=~s/\\.\\w+//;\n  }\n\ne\
lse\n  {\n    $suffix=&vtmpnam();\n  }\n\n\nif (!$\
run_name){$output_cl.=\" -run_name $suffix \";}\n\\
n\n$gl{'Tree'}=&seq2dpa_tree ($seq, \"$suffix.dpad\
nd\");\n\nprint STDERR \"\\n Step $step: Prepare g\
uide tree: $gl{'Tree'}\";$step++;\n\nprint STDERR \
\"\\n Step $step: Identify and Align Closely Relat\
ed Groups\";$step++;\n%gl=&make_one_pass (0, $scor\
eT1,\"Align\",%gl);\n\nprint STDERR \"\\n Step $st\
ep: Make Multiple Group Alignment\";$step++;\nwhil\
e (!%gl ||$gl{'Ng'}>$nseqT)\n  {\n    %gl=&make_on\
e_pass ($nseqT, $scoreT2,\"t_coffee\",%gl);\n    i\
f ( $gl{'Newgroups'}==0){$scoreT2--;}    \n  }\npr\
int STDERR \"\\n Step $step: Make The Final Alignm\
ent\";$step++;\n\n\n$arg_list .=$output_cl;\n\n\n%\
gl=&tree2group (0,0, %gl);\n$gl{$gl{'0'}{'File'}}{\
'Output'}=\"\";\n$a=0;\n&align_groups (\"t_coffee\\
",'0', $arg_list, \" \", %gl);\n\n\n\nif ( !$dpa_k\
eep_tmpfile){&clean_tmp_file (@tl);}\n\n\n\nsub se\
q2dpa_tree \n  {\n    my $seq=@_[0];\n    my $newt\
ree=@_[1];\n    my $aln=&vtmpnam ();\n\n    &my_sy\
stem (\"t_coffee -special_mode quickaln -in $seq -\
outfile $aln -quiet\");\n    &my_system (\"$seq_re\
format -in $aln -action +aln2tree +tree2dpatree -o\
utput newick >$newtree\");\n    return $newtree;\n\
  }	\nsub seq2dpa_tree_old \n  {\n    my $aln=@_[0\
];\n    my $newtree=@_[1];\n    \n    \n    &my_sy\
stem(\"$seq_reformat -in $aln -action +seq2dpatree\
 -output newick > $newtree\");\n    return $newtre\
e;\n  }\nsub aln2dpa_tree \n  {\n    my $aln=@_[0]\
;\n    my $newtree=&vtmpnam();\n    \n    &my_syst\
em(\"$seq_reformat -in $aln -action +aln2tree +tre\
e2dpatree -output newick > $newtree\");\n    retur\
n $newtree;\n  }\nsub group_file2ngroups\n  {\n   \
 my $file=@_[0];\n    my $n;\n    \n    open ( F, \
$file);\n    while (<F>)\n      {\n	$n+=/\\>/;\n  \
    }\n    close (F);\n    return $n;\n  }\n\nsub \
make_one_pass\n  {\n    my ($N, $ID,$pg, %gl)=@_;\\
n    my $a;\n\n    %gl=&tree2group ($N,$ID,%gl);\n\
    if (!$gl{'Newgroups'}){return %gl;}\n    else\\
n      {\n	for ( $a=0; $a< $ng; $a++)\n	  {\n	    \
if ($gl{$gl{$a}{'File'}}{'Ng'}>1){&display_group($\
a, %gl);}\n	    &align_groups ($pg, $a, $arg_list,\
 \" -quiet=quiet \", %gl);\n	  }\n	return %gl;\n  \
    }\n  }\n\nsub tree2group \n  {\n    my ($N, $I\
D, %gl)=@_;\n    my $prefix=&vtmpnam();\n    my $g\
roup_file=&vtmpnam();\n    my $file;\n    my $oldt\
ree=&vtmpnam();\n    my $n;\n    my $tree;\n\n\n  \
  if ( $gl{'Ng'}==1){return %gl;}\n    $tree=$gl{'\
Tree'}; \n    \n    #1 extract the groups\n    &my\
_system (\"$seq_reformat -in $tree -action +tree2g\
roup $N $ID $prefix > $group_file\");\n    $n=grou\
p_file2ngroups($group_file);\n    \n    \n    $gl{\
'Newgroups'}=1;\n    if ( $n==$gl{'Ng'})\n      {\\
n	$gl{'Newgroups'}=0;\n	return %gl;\n      }\n    \
$gl{'Iteration'}++;\n    $gl{'MaxNseq'}=$N;$gl{'Mi\
nID'}=$ID;\n    $gl{'GroupFile'}=$group_file;$gl{'\
Ng'}=$ng=0;\n    #2 Process the group list into th\
e hash\n    open (F, $group_file);\n    while (<F>\
)\n      {\n	$gl{'File'}.=$_;\n	if (/\\>/)\n	  {\n\
	    $line=$_;\n	    $line=~s/\\>//;\n	    @list=(\
$line=~/(\\S+)/g);\n	    $file=$gl{$ng}{'File'}=sh\
ift @list;\n	    $gl{$file}{'Output'}=$file;\n	   \
 \n	    $gl{$file}{'Ng'}=$#list+1;\n	    if ($gl{$\
file}{'Ng'}>1){ $gl{$file}{'Tlist'}=$gl{$file}{'Al\
ist'}=\"(\";}\n	    foreach $l (@list)\n	      {\n\
	\n		$gl{$file}{'List'}.=\" $l \";\n		\n		if (!$gl\
{$l}{'Tlist'})\n		  {\n		    $gl{$l}{'Tlist'}=\"$l\
\";\n		    $gl{$l}{'Alist'}=\"$l\";\n		    $gl{$l}\
{'Nseq'}=1;\n		    $gl{$l}{'Ng'}=1;\n		  }\n		$gl{\
$file}{'Tlist'}.=\"$gl{$l}{'Tlist'},\";\n		$gl{$fi\
le}{'Alist'}.=\"$gl{$l}{'Tlist'}|\";\n		$gl{$file}\
{'Nseq'}+=$gl{$l}{'Nseq'};\n	      }\n	    \n\n	  \
  chop($gl{$file}{'Tlist'});chop($gl{$file}{'Alist\
'});\n	    if ($gl{$file}{'Ng'}>1){$gl{$file}{'Tli\
st'}.=\")\"; $gl{$file}{'Alist'}.=\");\";}\n	    $\
ng++;\n	  }	\n      }\n    $gl{'Ng'}=$ng;\n    clo\
se (F);\n    \n    #3 Update the old tree with the\
 new groups\n    $gl{'Tree'}=&vtmpnam();\n    &my_\
system (\"$seq_reformat -in $tree -action +collaps\
e_tree $group_file -output newick > $gl{'Tree'}\")\
;\n    \n    return %gl;\n  }\n\nsub display_group\
 \n  {\n    my ($g,%gl)=@_;\n    my $f;\n    \n   \
 if ( $g==-1)\n      {\n	print STDERR \"\\nIterati\
on $gl{'Iteration'} [MaxN=$gl{'MaxNseq'}][MinID=$g\
l{'MinID'}]\";\n      }\n    else\n      {\n\n	$f=\
$gl{$g}{'File'};\n	$action=($gl{$f}{'Ng'}==1 || $g\
l{'Iteration'}==1)?\"KEEP  \":\"ALIGN \";\n       \
 print STDERR \"\\n\\t[$action][MaxN=$gl{'MaxNseq'\
}][MinID=$gl{'MinID'}][File $f][Nseq=$gl{$f}{'Nseq\
'}][Ngroups=$gl{$f}{'Ng'}][$gl{$f}{'Alist'}]\";\n \
     }\n  }\n      \n\n\nsub align_groups\n  {\n  \
  my ($pg, $g, $arg, $extra_arg,%gl)=@_;\n    my $\
f;\n    my $Output,$Outflag;\n    \n    \n    $f=$\
gl{$g}{'File'};\n    $Output=($gl{$f}{'Output'});\\
n    \n    if ( $pg eq \"Align\")\n      {\n	if ( \
!-e $f)\n	  {\n	    $command=\"$seq_reformat -in $\
gl{'Seq'}  -action +extract_aln $gl{'GroupFile'}\"\
;\n	    if ($gl{$f}{'Ng'}>1)\n	      {\n		&my_syst\
em ($command);\n		$command=\"t_coffee -special_mod\
e quick_aln  S$f -outfile=$Output -quiet\";\n	    \
  }\n	  }\n	else \n	  {$command=\"\";}\n      }\n \
   elsif ( -e $f)\n      {	\n	$Outflag=($Output)?\\
"-outfile=$Output\":\"\";\n	$command=\"$pg -infile\
 $f $Outflag -quiet stdout $arg $extra_arg -maxnse\
q 0 -convert -quiet stdout\";\n      }\n    elsif \
( $gl{$f}{'Ng'}==1)\n      {\n	$action=($dpa_debug\
)?\"cp\":\"mv\";\n	$command=\"$action $gl{$f}{'Lis\
t'} $Output\";\n      }\n    else\n      {\n	$Outf\
lag=($Output)?\"-outfile=$Output\":\"\";\n	$comman\
d=\"$pg -profile $gl{$f}{'List'} $Outflag $arg $ex\
tra_arg -maxnseq 0\";\n      }\n    \n    &my_syst\
em ($command);\n    return $outfile;\n  }\n    \ns\
ub my_system \n  {\n    my $command=@_[0];\n    my\
 $force=@_[1];\n    my $status;\n\n    if ( $dpa_d\
ebug) {print STDERR \"\\nCOMMAND: $command\";}\n  \
  $status=system ($command);\n\n    if (!$force)\n\
       {\n	 &exit_dpa (($status==1), \"Failed in C\
ommand:\\n$command\\n[FATAL: t_coffee_dpa]\\n\", E\
XIT_FAILURE);\n       }\n    \n    return $status;\
\n  }\n\nsub vtmpnam\n  {\n    my $prefix=@_[0];\n\
    my $tmp_file_name;\n\n    $tmp_prefix=($prefix\
)?$prefix:\"dpa_tmp_file_$$\";\n   \n    $tmp_coun\
t++;\n    $tmp_file_name=\"$tmp_prefix\".\"$tmp_co\
unt\";\n    $tl[$#tl+1]=$tmp_file_name;\n    retur\
n $tmp_file_name;\n  }\n\nsub clean_tmp_file\n  {\\
n\n    my $list;\n    my $file;\n    \n    if ($dp\
a_debug){return;}\n    $list=vtmpnam();\n    `ls -\
1 | grep $tmp_prefix>$list`;\n    \n    open (F,$l\
ist);\n    while ( <F>)\n      {\n	$file=$_;\n	cho\
p $file;\n	if ( -e $file){unlink $file;}\n      }\\
n    close (F);\n    unlink $list;\n  }\n\n\nsub e\
xit_dpa\n  {\n  my $condition=@_[0];\n  my $error_\
msg=@_[1];\n  my $exit_value=@_[2];\n  if ( $condi\
tion)\n    {\n      print \"$error_msg\\n\";\n    \
  exit ($exit_value);\n    }\n  else\n    {\n     \
 return;\n    }\n  \n}\nsub extract_val_from_arg_l\
ist\n  {\n    my $arg=@_[0];\n    my $arg_list=@_[\
1];\n    my $keep_flag=@_[2];\n    my $default_val\
ue=@_[3];\n    my $val=\"\";\n    \n    #protect\n\
    $arg_list=~s/\\s-/ \\@/g;\n    $arg=~s/-/\\@/g\
;\n    \n    #search\n    if ($arg eq \"^\")\n    \
  {\n	$arg_list=~/^([^@]*)/;\n	$val=$1;\n      }\n\
    else\n      {$arg_list=~/$arg ([^@]*)/;$val=$1\
;}\n    \n    #remove trailing spaces\n    $val=~s\
/\\s*$//;\n    \n    #remove the parsed sequence i\
f needed\n    if (($val ne \"\") && $keep_flag ne \
\"KEEP\")\n      {\n	if ( $arg eq \"^\"){$arg_list\
=~s/$val/ /;}\n	else {$arg_list=~s/($arg [^@]*)/ /\
;}\n      }\n	\n    #unprotect\n    $arg_list=~s/\\
\@/-/g;\n    $arg=~s/\\@/-/g;\n    \n    if (($val\
 eq \"\") && $default_value ne \"unset\"){$val=$de\
fault_value;}\n    \n    return $val, $arg_list;\n\
  }\n$program=\"T-COFFEE (Version_11.00.8cbe486)\"\
;\\n\n","\n$DEBUG=1;\n$dpa_nseq=10;\n$dpa_sim=0;\n\
if (!@ARGV)\n  {\n    `t_coffee`;\n    exit (0);\n\
  }\nforeach $arg (@ARGV)\n  {\n    $arg_list.=\" \
$arg\";\n  }\n$max_nseq=10;\n($seq0, $arg_list)=&e\
xtract_val_from_arg_list(\"^\",$arg_list);\n($seq1\
, $arg_list)=&extract_val_from_arg_list(\"-seq\",$\
arg_list);\n($seq2, $arg_list)=&extract_val_from_a\
rg_list(\"-in\",$arg_list, \"KEEP\");\n($seq3, $ar\
g_list)=&extract_val_from_arg_list(\"-infile\",$ar\
g_list);\n$in_seq=$seq0.\" \".$seq1.\" \".$seq2.\"\
 \".$seq3;\n\n$seq=vtmpnam();\n`t_coffee $in_seq -\
convert -output fasta_seq -outfile=$seq`;\n\n\n($d\
pa_nseq, $arg_list)=&extract_val_from_arg_list(\"-\
dpa_nseq\",$arg_list);\n($master_aln, $arg_list)=&\
extract_val_from_arg_list(\"-master_aln\",$arg_lis\
t);\n($sim_matrix, $arg_list)=&extract_val_from_ar\
g_list(\"-sim_matrix\",$arg_list);\n($core_seq, $a\
rg_list)=&extract_val_from_arg_list(\"-core_seq\",\
$arg_list);\n($dpa_sim, $arg_list)=&extract_val_fr\
om_arg_list(\"-dpa_sim\",$arg_list);\n($run_name, \
$arg_list)=&extract_val_from_arg_list(\"-run_name\\
",$arg_list);\n($output, $arg_list)=&extract_val_f\
rom_arg_list(\"-output\",$arg_list);\n\n\n\nif (!$\
sim_mat && !$master_aln)#Compute the fast alignmen\
t\n  {\n    $ref_aln=vtmpnam();\n    `t_coffee -se\
q=$seq -very_fast -outfile=$ref_aln -quiet`;\n    \
\n  }\n\nif (!$sim_mat)\n  {\n    $sim_mat=vtmpnam\
();\n    `seq_reformat -in $ref_aln -output sim > \
$sim_mat`;\n  }\n\nif ( !$core_seq)\n  {\n    $cor\
e_seq=vtmpnam();\n    `seq_reformat -in $ref_aln -\
action +trimTC N$max_nseq -output fasta_seq > $cor\
e_seq`;\n  }\n@core_name=`seq_reformat -in $core_s\
eq -output name `; \n\n@tot_name=`seq_reformat -in\
 $seq -output name `;\n\nforeach $s (@core_name){$\
s=~s/\\s//g;$hcore{$s}=1;}\nforeach $s (@tot_name)\
{$s=~s/\\s//g;}\nprint STDERR \"T-Coffee_dpa:\\n\"\
;\nprint STDERR \"\\tTOTAL  SEQ: @tot_name\\n\";\n\
print STDERR \"\\tCHOSEN SEQ: @core_name\\n\";\n\n\
\n\nopen (F, $sim_mat);\nwhile ( <F>)\n  {\n    @l\
=($_=~/(\\b[\\S]+\\b)/g);\n    if (($l[0] eq \"TOP\
\" || $l[0] eq \"BOT\"))\n      {\n	$s1=$l[1];$s2=\
$l[2];$v=$l[3];\n	if ($hcore{$s1} && !$hcore{$s2})\
\n	  {\n	    if (!$hseq{$s2}{\"sim\"} || $v>$hseq{\
$s2}{\"sim\"})\n	      {\n		$hseq{$s2}{\"sim\"}=$v\
;$hseq{$s2}{\"seq\"}=$s1;\n	      }\n	  }\n      }\
\n  }\nclose (F);\nforeach $s (@tot_name)\n  {\n\n\
    if ( !$hseq{$s}{\"seq\"}){;}\n    else\n      \
{\n	$s2=$hseq{$s}{\"seq\"};\n	$v=$hseq{$s}{\"sim\"\
};\n		\n	if ($v>$dpa_sim)\n	  {\n	    $hseq{$s}{'u\
sed'}=1;\n	    $seq_list{$s2}{$seq_list{$s2}{'nseq\
'}++}=$s;\n	  }\n      }\n  }\nforeach $s (@core_n\
ame){$seq_list{$s}{$seq_list{$s}{'nseq'}++}=$s;$hs\
eq{$s}{'used'}=1;}\nforeach $s (@tot_name){if (!$h\
seq{$s}{'used'}){$seq_list{'unused'}{$seq_list{'un\
used'}{'nseq'}++}=$s;}}\n\n\n$n=0;\nforeach $s (@c\
ore_name)\n  {\n    $ng++;\n    $n=$seq_list{$s}{'\
nseq'};\n    for (@g_list=(), $a=0; $a<$n; $a++){@\
g_list=(@g_list,$seq_list{$s}{$a});}\n\n    $g_seq\
=vtmpnam();\n    $g_aln=vtmpnam();\n    \n    prin\
t STDERR \"Group $ng: $#g_list Seq: @g_list: \";\n\
    \n    \n    `seq_reformat -in $seq -action +lo\
wer +keep_name +extract_seq  @g_list -output fasta\
_seq > $g_seq`;\n    \n    \n    if ( $#g_list==0)\
\n      {\n	print STDERR \"[No aln]\\n\";\n	$g_aln\
=$g_seq;\n      }\n    elsif ($#g_list<$max_nseq) \
\n      {\n	print STDERR \"[t_coffee]\\n\";\n	`t_c\
offee $g_seq -outfile=$g_aln -quiet $arg_list`;\n \
     }\n    else\n      {\n	print STDERR \"[t_coff\
ee_dpa]\\n\";\n	`t_coffee_dpa2 $g_seq -outfile=$g_\
aln $arg_list -sim_matrix $sim_matrix -dpa_nseq $d\
pa_nseq`;\n      }\n    @profile_list=(@profile_li\
st, $g_aln);\n  }\n\n\nprint \"UNUSED $seq_list{'u\
nused'}{'nseq'}\";\n\nif ($seq_list{'unused'}{'nse\
q'})\n    {\n      $prf=vtmpnam();\n      \n      \
`t_coffee -profile @profile_list $arg_list -outfil\
e=$prf -quiet`;\n      $n=$seq_list{\"unused\"}{'n\
seq'};\n      $new_seq=vtmpnam();\n      $new_prf=\
vtmpnam();\n      for ($a=0; $a<$n-1; $a++)\n	{\n	\
  $s=$seq_list{\"unused\"}{$a};\n	  print STDERR \\
"\\nADD Sequence $s\";\n	  \n	  `seq_reformat -in \
$seq -action +lower +keep_name +extract_seq $s  -o\
utput fasta_seq > $new_seq`;\n	  `t_coffee -profil\
e $prf $new_seq $arg_list -outfile=$new_prf`;\n	  \
`cp $new_prf $prf`;\n	}\n      $s=$seq_list{\"unus\
ed\"}{$a};\n      `seq_reformat -in $seq -action +\
lower +keep_name +extract_seq $s  -output fasta_se\
q > $new_seq`;\n      @profile_list=($prf, $new_se\
q);\n    }\n    \n      \nif ($run_name){$arg_list\
.=\" -run_name $run_name\";}\nelse \n  {\n    $in_\
seq=~/([\\w-]+)/;\n    $arg_list.=\" -run_name $1\\
";\n  }\nif ( $output){$arg_list.=\" -output $outp\
ut \";}\n\n`t_coffee -profile @profile_list $arg_l\
ist`;\n\n\n&clean (@tmp_file_list);\n\n\nsub vtmpn\
am\n  {\n    my $tmp_file_name;\n    $tmp_name_cou\
nter++;\n    $tmp_file_name=\"tmp_file_$tmp_name_c\
ounter\\_Pid$$\";\n    $tmp_file_list[$ntmp_file++\
]=$tmp_file_name;\n    return $tmp_file_name;\n  }\
\nsub clean\n  {\n  my @fl=@_;\n  my $file;\n  ret\
urn;\n\n  foreach $file ( @fl)\n    {\n      if ( \
-e $file){unlink($file);}\n    }\n}\nsub extract_v\
al_from_arg_list\n  {\n    my $arg=@_[0];\n    my \
$arg_list=@_[1];\n    my $keep_flag=@_[2];\n    #p\
rotect\n    $arg_list=~s/\\s-/ \\@/g;\n    $arg=~s\
/-/\\@/g;\n    \n    #search\n    if ($arg eq \"^\\
")\n      {\n	$arg_list=~/^([^@]*)/;\n	$val=$1;\n \
     }\n    else\n      {$arg_list=~/$arg ([^@]*)/\
;$val=$1;}\n    \n    #remove the parsed sequence \
if needed\n    if ($val && $keep_flag ne \"KEEP\")\
\n      {\n	if ( $arg eq \"^\"){$arg_list=~s/$val/\
 /;}\n	else {$arg_list=~s/($arg [^@]*)/ /;}\n     \
 }\n	\n    #unprotect\n    $arg_list=~s/\\@/-/g;\n\
    $arg=~s/\\@/-/g;\n    \n    return $val, $arg_\
list;\n  }\n\n","use Env;\nuse FileHandle;\nuse Cw\
d;\nuse File::Path;\nuse Sys::Hostname;\n\n\nour $\
PIDCHILD;\nour $ERROR_DONE;\nour @TMPFILE_LIST;\no\
ur $EXIT_FAILURE=1;\nour $EXIT_SUCCESS=0;\n\nour $\
REFDIR=getcwd;\nour $EXIT_SUCCESS=0;\nour $EXIT_FA\
ILURE=1;\n\nour $PROGRAM=\"tc_generic_method.pl\";\
\nour $CL=$PROGRAM;\n\nour $CLEAN_EXIT_STARTED;\no\
ur $debug_lock=$ENV{\"DEBUG_LOCK\"};\nour $debug_g\
eneric_method=$ENV{\"DEBUG_GENERIC_METHOD\"};\nour\
 $LOCKDIR=$ENV{\"LOCKDIR_4_TCOFFEE\"};\nif (!$LOCK\
DIR){$LOCKDIR=getcwd();}\nour $ERRORDIR=$ENV{\"ERR\
ORDIR_4_TCOFFEE\"};\nour $ERRORFILE=$ENV{\"ERRORFI\
LE_4_TCOFFEE\"};\n&set_lock ($$);\nif (isshellpid(\
getppid())){lock4tc(getppid(), \"LLOCK\", \"LSET\"\
, \"$$\\n\");}\nour %RECODE;\nour $RECODE_N;\n\n\n\
\n\nour $BLAST_MAX_NRUNS=2;\nour $COMMAND;\nour $P\
IDCHILD;\n\n$REF_EMAIL=\"\";\n$tmp_dir=\"\";\n$ini\
t_dir=\"\";\n\n\n$test=0;\nif ($test==1)\n  {\n   \
 $SERVER=\"NCBI\";\n    $query=$ARGV[0];\n    $hit\
f=$ARGV[1];\n    %s=read_fasta_seq($query);\n    @\
sl=keys(%s);\n    &blast_xml2profile (\"xx\", $s{$\
sl[0]}{seq},$maxid,$minid,$mincov, $hitf);\n    my\
exit ($EXIT_FAILURE);\n  }\n\nforeach $v(@ARGV){$c\
l.=\"$v \";}\n$COMMAND=$cl;\n($mode)=&my_get_opt (\
 $cl, \"-mode=\",1,0);\n\n($A)=(&my_get_opt ( $cl,\
 \"-name1=\",0,0));\n($B)=(&my_get_opt ( $cl, \"-n\
ame2=\",0,0));\n($TMPDIR)=(&my_get_opt ( $cl, \"-t\
mpdir=\",0,0));\n($CACHE)=(&my_get_opt ( $cl, \"-c\
ache=\",0,0));\n($SERVER)=((&my_get_opt ( $cl, \"-\
server=\",0,0)));\n($EMAIL)=((&my_get_opt ( $cl, \\
"-email=\",0,0)));\n\nif (!$A){$A=\"A\";}\nif (!$B\
){$B=\"B\";}\n\n\nif (!$TMPDIR)\n  {\n    $HOME=$E\
NV{HOME};\n    if ($ENV{TMP_4_TCOFFEE}){$TMPDIR=$E\
NV{TMP_4_TCOFFEE};}\n    else{$TMPDIR=\"$HOME/.t_c\
offee/tmp/\";}\n  }\nif ( ! -d $TMPDIR)\n  {\n    \
mkdir $TMPDIR;\n  }\nif ( ! -d $TMPDIR)\n  {\n    \
print \"ERROR: Could not create temporary dir: $TM\
PDIR\\n\";\n    myexit ($EXIT_FAILURE);\n  }\n\n$E\
MAIL=~s/XEMAILX/\\@/g;\nif (!$EMAIL)\n  {\n    if \
($ENV{EMAIL_4_TCOFFEE}){$EMAIL=$ENV{EMAIL_4_TCOFFE\
E};}\n    elsif ($ENV{EMAIL}){$EMAIL=$ENV{EMAIL};}\
\n    else {$EMAIL=$REF_EMAIL;}\n  }\n\n($maxid,$m\
inid,$mincov)=(&my_get_opt ( $cl, \"-maxid=\",0,0,\
 \"-minid=\",0,0,\"-mincov=\",0,0));\nif (!$cl=~/\\
\-maxid\\=/){$maxid=95;}\nif (!$cl=~/\\-minid\\=/)\
{$minid=35;}\nif (!$cl=~/\\-mincov\\=/){$mincov=80\
;}\n\n\n\n\nif ($mode eq \"seq_msa\")\n  {\n    &s\
eq2msa($mode,&my_get_opt ( $cl, \"-infile=\",1,1, \
\"-method=\",1,2, \"-param=\",0,0,\"-outfile=\",1,\
0, \"-database=\",0,0));\n  }\nelsif ( $mode eq \"\
tblastx_msa\")\n  {\n    &seq2tblastx_lib ($mode,&\
my_get_opt ( $cl, \"-infile=\",1,1, \"-outfile=\",\
1,0));\n  }\nelsif ( $mode eq \"tblastpx_msa\")\n \
 {\n    &seq2tblastpx_lib ($mode,&my_get_opt ( $cl\
, \"-infile=\",1,1, \"-outfile=\",1,0));\n  }\nels\
if ( $mode eq \"thread_pair\")\n  {\n    &seq2thre\
ad_pair($mode,&my_get_opt ( $cl, \"-infile=\",1,1,\
 \"-pdbfile1=\",1,1, \"-method=\",1,2,\"-param=\",\
0,0, \"-outfile=\",1,0, ));\n  }\nelsif ( $mode eq\
 \"pdbid_pair\")\n  {\n    &seq2pdbid_pair($mode,&\
my_get_opt ( $cl, \"-pdbfile1=\",1,0, \"-pdbfile2=\
\",1,0, \"-method=\",1,2,\"-param=\",0,0, \"-outfi\
le=\",1,0, ));\n  }\nelsif ( $mode eq \"pdb_pair\"\
)\n  {\n    &seq2pdb_pair($mode,&my_get_opt ( $cl,\
 \"-pdbfile1=\",1,1, \"-pdbfile2=\",1,1, \"-method\
=\",1,2,\"-param=\",0,0, \"-outfile=\",1,0, ));\n \
 }\nelsif ( $mode eq \"rnapdb_pair\")\n{\n    &seq\
2rnapdb_pair($mode,&my_get_opt ( $cl, \"-pdbfile1=\
\",1,1, \"-pdbfile2=\",1,1, \"-method=\",1,2,\"-pa\
ram=\",0,0, \"-outfile=\",1,0, ));\n}\nelsif ( $mo\
de eq \"profile_pair\")\n  {\n     &seq2profile_pa\
ir($mode,&my_get_opt ( $cl, \"-profile1=\",1,1, \"\
-profile2=\",1,1, \"-method=\",1,2,\"-param=\",0,0\
, \"-outfile=\",1,0 ));\n  }\nelsif ($mode eq \"pd\
b_template_test\")\n  {\n    &blast2pdb_template_t\
est ($mode,&my_get_opt ( $cl, \"-infile=\",1,1));\\
n\n  }\nelsif ($mode eq \"psi_template_test\")\n  \
{\n    &psiblast2profile_template_test ($mode,&my_\
get_opt ( $cl, \"-seq=\",1,1,\"-blast=\",1,1));\n\\
n  }\n\nelsif ( $mode eq \"pdb_template\")\n  {\n \
   &blast2pdb_template ($mode,&my_get_opt ( $cl, \\
"-infile=\",1,1, \"-database=\",1,0, \"-method=\",\
1,0, \"-outfile=\",1,0,\"-pdb_type=\",1,0));\n  }\\
n\nelsif ( $mode eq \"profile_template\")\n  {\n\n\
    &psiblast2profile_template ($mode,&my_get_opt \
( $cl, \"-infile=\",1,1, \"-database=\",1,0, \"-me\
thod=\",1,0, \"-outfile=\",1,0));\n  }\nelsif ( $m\
ode eq \"psiprofile_template\")\n  {\n    &psiblas\
t2profile_template ($mode,&my_get_opt ( $cl, \"-in\
file=\",1,1, \"-database=\",1,0, \"-method=\",1,0,\
 \"-outfile=\",1,0));\n  }\nelsif ( $mode eq \"RNA\
_template\")\n  {\n    &seq2RNA_template ($mode,&m\
y_get_opt ( $cl, \"-infile=\",1,1,\"-pdbfile=\",1,\
1,\"-outfile=\",1,0));\n  }\nelsif ( $mode eq \"tm\
_template\")\n  {\n    &seq2tm_template ($mode, \"\
\", &my_get_opt ( $cl, \"-infile=\",1,1,\"-arch=\"\
,1,1,\"-psv=\",1,1, \"-outfile=\",1,0,));\n  }\nel\
sif ( $mode eq \"psitm_template\")\n  {\n    &seq2\
tm_template ($mode,&my_get_opt ( $cl, \"-database=\
\",1,0, \"-infile=\",1,1, \"-arch=\",1,1,\"-psv=\"\
,1,1, \"-outfile=\",1,0,));\n  }\nelsif ( $mode eq\
 \"ssp_template\")\n  {\n    &seq2ssp_template ($m\
ode,&my_get_opt ( $cl, \"-infile=\",1,1,\"-seq=\",\
1,1,\"-obs=\",1,1, \"-outfile=\",1,0));\n  }\nelsi\
f ( $mode eq \"psissp_template\")\n  {\n    &seq2s\
sp_template ($mode,&my_get_opt ( $cl, \"-infile=\"\
,1,1,\"-seq=\",1,1,\"-obs=\",1,1, \"-outfile=\",1,\
0));\n  }\n\n\n\nelse\n  {\n    myexit(flush_error\
( \"$mode iss an unknown mode of tc_generic_method\
.pl\"));\n  }\nmyexit ($EXIT_SUCCESS);\n\n\nsub se\
q2ssp_template\n  {\n  my ($mode, $infile,$gor_seq\
,$gor_obs,$outfile)=@_;\n  my %s, %h;\n  my $resul\
t;\n  my (@profiles);\n  &set_temporary_dir (\"set\
\",$infile,\"seq.pep\");\n  %s=read_fasta_seq (\"s\
eq.pep\");\n\n\n  open (R, \">result.aln\");\n\n  \
#print stdout \"\\n\";\n  foreach $seq (keys(%s))\\
n    {\n\n      open (F, \">seqfile\");\n      $s{\
$seq}{seq}=uc$s{$seq}{seq};\n      print (F \">$s{\
$seq}{name}\\n$s{$seq}{seq}\\n\");\n      close (F\
);\n      $lib_name=\"$s{$seq}{name}.ssp\";\n     \
 $lib_name=&clean_file_name ($lib_name);\n\n      \
if ($mode eq \"ssp_template\"){&seq2gor_prediction\
 ($s{$seq}{name},$s{$seq}{seq}, \"seqfile\", $lib_\
name,$gor_seq, $gor_obs);}\n      elsif ($mode eq \
\"psissp_template\")\n	{\n	  &seq2msa_gor_predicti\
on ($s{$seq}{name},$s{$seq}{seq},\"seqfile\", $lib\
_name,$gor_seq, $gor_obs);\n	}\n\n      if ( !-e $\
lib_name)\n	{\n	  myexit(flush_error(\"GORIV faile\
d to compute the secondary structure of $s{$seq}{n\
ame}\"));\n	  myexit ($EXIT_FAILURE);\n	}\n      e\
lse\n	{\n	  print stdout \"!\\tProcess: >$s{$seq}{\
name} _E_ $lib_name \\n\";\n	  print R \">$s{$seq}\
{name} _E_ $lib_name\\n\";\n	}\n      unshift (@pr\
ofiles, $lib_name);\n    }\n  close (R);\n  &set_t\
emporary_dir (\"unset\",$mode, $method,\"result.al\
n\",$outfile, @profiles);\n}\n\nsub seq2tm_templat\
e\n  {\n  my ($mode, $db, $infile,$arch,$psv,$outf\
ile)=@_;\n  my %s, %h;\n  my $result;\n  my (@prof\
iles);\n  &set_temporary_dir (\"set\",$infile,\"se\
q.pep\");\n  %s=read_fasta_seq (\"seq.pep\");\n\n\\
n  open (R, \">result.aln\");\n\n  #print stdout \\
"\\n\";\n  foreach $seq (keys(%s))\n    {\n      o\
pen (F, \">seqfile\");\n      print (F \">$s{$seq}\
{name}\\n$s{$seq}{seq}\\n\");\n      close (F);\n \
     $lib_name=\"$s{$seq}{name}.tmp\";\n      $lib\
_name=&clean_file_name ($lib_name);\n\n      if ($\
mode eq \"tm_template\")\n	{\n	  &safe_system (\"t\
_coffee -other_pg fasta_seq2hmmtop_fasta.pl -in=se\
qfile -out=$lib_name -arch=$arch -psv=$psv\");\n	}\
\n      elsif ( $mode eq \"psitm_template\")\n	{\n\
	  &seq2msa_tm_prediction ($s{$seq}{name},$s{$seq}\
{seq}, $db, \"seqfile\", $lib_name,$arch, $psv);\n\
	}\n      if ( !-e $lib_name)\n	{\n	  myexit(flush\
_error(\"hmmtop failed to compute the secondary st\
ructure of $s{$seq}{name}\"));\n	  myexit ($EXIT_F\
AILURE);\n	}\n      else\n	{\n	  print stdout \"!\\
\tProcess: >$s{$seq}{name} _T_ $lib_name\\n\";\n	 \
 print R \">$s{$seq}{name} _T_ $lib_name\\n\";\n	}\
\n      unshift (@profiles, $lib_name);\n    }\n  \
close (R);\n  &set_temporary_dir (\"unset\",$mode,\
 $method,\"result.aln\",$outfile, @profiles);\n}\n\
\n\n\nsub seq2RNA_template\n  {\n    \n    my ($mo\
de, $infile, $pdbfile, $outfile)=@_;\n    my %s, %\
h ;\n    my $result;\n    my (@profiles);\n    my \
($seq_mode, $pdb_mode, $pwd);\n    \n    #use $seq\
_mode to estimate the template of sequences WITHOU\
T a PDB\n    #use $pdb_mode to estimate the templa\
te of sequences WITH    a PDB\n\n    $seq_mode=$EN\
V{\"SEQ2TEMPLATE4_F_\"};\n    $pdb_mode=$ENV{\"PDB\
2TEMPLATE4_F_\"};\n    \n    if (!$pdb_mode){$pdb_\
mode=\"find_pair-p\";}\n    if (!$seq_mode){$seq_m\
ode=\"RNAplfold\";}\n    \n    my $cwd = cwd();\n \
   &set_temporary_dir (\"set\",$infile,\"seq.pep\"\
);\n    %s=read_fasta_seq (\"seq.pep\");\n    %pdb\
_template_h = &read_template_file($pdbfile);\n    \
my $pdb_chain;\n    \n       \n    open (R, \">res\
ult.aln\");\n    #print stdout \"\\n\";\n    forea\
ch $seq (keys(%s))\n      {\n	\n	open (F, \">seqfi\
le\");\n	print (F \">$s{$seq}{name}\\n$s{$seq}{seq\
}\\n\");\n	close (F);\n	$pdb_chain = $pdb_template\
_h{$seq};\n	$lib_name=\"$s{$seq}{name}.rfold\";\n	\
$lib_name=&clean_file_name ($lib_name);\n	if ($pdb\
_template_h{$seq} eq \"\")\n	  {\n	    if    ($seq\
_mode eq \"RNAplfold\"){RNAplfold2lib (\"seqfile\"\
, \"$lib_name\");}\n	    elsif ($seq_mode eq \"no\\
"){$lib_name=0;}\n	    else\n	      {\n		myexit(ad\
d_error (EXIT_FAILURE,$$,$$,getppid(), \"seq2RNA_t\
emplate failure::method $seq_mode not available fo\
r sequences without PDB structures\"));\n	      }\\
n	  }\n	elsif ($pdb_template_h{$seq} ne \"\")\n	  \
{\n	    my $pdbf;\n	    if (-e \"$cwd/$pdb_chain\"\
){$pdbf=\"$cwd/$pdb_chain\";}\n	    else {$pdbf=\"\
$CACHE$pdb_chain\";}\n	    \n\n	    if($pdb_mode e\
q \"x3dna-ssr\")\n	      {\n		x3dnassr2lib (\"seqf\
ile\", \"$pdbf\", \"$lib_name\");\n	      }\n	    \
elsif ($pdb_mode eq \"find_pair-p\")\n	      {\n		\
x3dna_find_pair2lib (\"seqfile\", \"$pdbf\", \"$li\
b_name\", \"find_pair -p\");\n	      }\n	    elsif\
 ($pdb_mode eq \"find_pair\")\n	      {\n		x3dna_f\
ind_pair2lib (\"seqfile\", \"$pdbf\", \"$lib_name\\
", \"find_pair\");\n	      }\n	    elsif ($pdb_mod\
e eq \"RNAplfold\")\n	      {\n		RNAplfold2lib (\"\
seqfile\", \"$lib_name\");\n	      }\n	    elsif (\
$pdb_mode eq \"no\"){$lib_name=0;}\n	    else\n	  \
    {\n		myexit(add_error (EXIT_FAILURE,$$,$$,getp\
pid(), \"seq2RNA_template failure::Could not find \
method $pdb_mode\"));\n	      }\n	  }\n	if ($lib_n\
ame)\n	  {\n	    print stdout \"!\\tProcess: >$s{$\
seq}{name} _F_ $lib_name\\n\";\n	    print R \">$s\
{$seq}{name} _F_ $lib_name\\n\";\n	    unshift (@p\
rofiles, $lib_name);\n	  }\n      }\n    close (R)\
;\n    &set_temporary_dir (\"unset\",$mode, $metho\
d,\"result.aln\",$outfile, @profiles);\n  }\n\n\n\\
nsub psiblast2profile_template_test\n  {\n  my ($m\
ode, $seq,$blast)=@_;\n  my %s, %h, ;\n  my ($resu\
lt,$psiblast_output,$profile_name,@profiles);\n  m\
y $trim=0;\n  my $maxid=100;\n  my $minid=0;\n  my\
 $mincov=0;\n  my $maxcov=100;\n\n  %s=read_fasta_\
seq ($seq);\n  open (R, \">result.aln\");\n\n  #pr\
int stdout \"\\n\";\n  foreach $seq (keys(%s))\n  \
  {\n\n      open (F, \">seqfile\");\n      print \
(F \">$A\\n$s{$seq}{seq}\\n\");\n      close (F);\\
n      $psiblast_output=$blast;\n      if ( -e $ps\
iblast_output)\n	{\n	  %profile=blast_xml2profile(\
$s{$seq}{name}, $s{$seq}{seq},$maxid, $minid,$minc\
ov,$psiblast_output);\n\n\n\n	  $profile_name=\"$s\
{$seq}{name}.prf\";\n	  $profile_name=&clean_file_\
name ($profile_name);\n	  unshift (@profiles, $pro\
file_name);\n	  output_profile ($profile_name, \\%\
profile, $trim);\n	  print stdout \"!\\tProcess: >\
$s{$seq}{name} _R_ $profile_name [$profile{n} Seq.\
] [$SERVER/blast/$db][$CACHE_STATUS]\\n\";\n	  pri\
nt R \">$s{$seq}{name} _R_ $profile_name\\n\";\n	}\
\n    }\n  close (R);\n\n  die;\n}\nsub psiblast2p\
rofile_template\n  {\n  my ($mode, $infile, $db, $\
method, $outfile)=@_;\n  my %s, %h, ;\n  my ($resu\
lt,$psiblast_output,$profile_name,@profiles);\n  m\
y $trim=0;\n  &set_temporary_dir (\"set\",$infile,\
\"seq.pep\");\n  %s=read_fasta_seq (\"seq.pep\");\\
n  open (R, \">result.aln\");\n\n  #print stdout \\
"\\n\";\n  foreach $seq (keys(%s))\n    {\n      o\
pen (F, \">seqfile\");\n      print (F \">$A\\n$s{\
$seq}{seq}\\n\");\n      close (F);\n      $psibla\
st_output=&run_blast ($s{$seq}{name},$method, $db,\
 \"seqfile\",\"outfile\");\n\nif ( -e $psiblast_ou\
tput)\n	{\n	  %profile=blast_xml2profile($s{$seq}{\
name}, $s{$seq}{seq},$maxid, $minid,$mincov,$psibl\
ast_output);\n	  unlink ($psiblast_output);\n\n	  \
$profile_name=\"$s{$seq}{name}.prf\";\n	  $profile\
_name=&clean_file_name ($profile_name);\n	  unshif\
t (@profiles, $profile_name);\n	  output_profile (\
$profile_name, \\%profile, $trim);\n	  print stdou\
t \"!\\tProcess: >$s{$seq}{name} _R_ $profile_name\
 [$profile{n} Seq.] [$SERVER/blast/$db][$CACHE_STA\
TUS]\\n\";\n	  print R \">$s{$seq}{name} _R_ $prof\
ile_name\\n\";\n	}\n    }\n  close (R);\n  &set_te\
mporary_dir (\"unset\",$mode, $method,\"result.aln\
\",$outfile, @profiles);\n}\nsub blast2pdb_templat\
e_test\n    {\n      my ($mode,$infile)=@_;\n     \
 my ($maxid,$minid,$mincov);\n      $maxid=100;\n \
     $minid=0;\n      $mincov=0;\n\n      print \"\
$infile\\n\";\n\n      %p=blast_xml2profile($s{$se\
q}{name}, $s{$seq}{seq},$maxid, $minid,$mincov,$in\
file);\n      $c=1;\n      print stdout \"!\\tProc\
ess: >$s{$seq}{name} [$SERVER/blast/$db][$CACHE_ST\
ATUS]\\n\";\n      while (!$found && $c<$p{n})\n	{\
\n	  $pdbid=&id2pdbid($p{$c}{identifyer});\n	  if \
( length ($pdbid)>5){$pdbid=id2pdbid($p{$c}{defini\
tion});}\n\n	  if ( length ($pdbid)>5)\n	    {\n	 \
     myexit(add_error (EXIT_FAILURE,$$,$$,getppid(\
), \"BLAST_FAILURE::Could Not Parse PDBID ($p{$c}{\
identifyer},$p{$c}{definition})\"));\n	    }\n\n\n\
	  if (!&pdb_is_released($pdbid))\n	    {\n	      \
print stdout \"\\t\\t**$pdbid [PDB NOT RELEASED or\
 WITHDRAWN]\\n\";\n	      $c++;\n	    }\n	  elsif \
(!&pdb_has_right_type ($pdbid,$type))\n	    {\n	  \
    my $ptype=&pdb2type ($pdbid);\n	      my $etyp\
e=&type2etype($type);\n\n	      print stdout \"\\t\
\\t**$pdbid [$ptype cannot be used (expected: $ety\
pe)]\\n\";\n	      $c++;\n	    }\n	  else\n	    {\\
n	      $found=1;\n	    }\n	}\n\n      if ($found)\
\n	{\n	  print stdout \"\\t\\t >$s{$seq}{name} _P_\
 $pdbid\\n\";\n	}\n      else\n	{\n	  print stdout\
 \"\\t\\t >$s{$seq}{name} No Template Selected\\n\\
";\n	}\n      die;\n    }\nsub blast2pdb_template\\
n  {\n  my ($mode, $infile, $db, $method, $outfile\
,$type)=@_;\n  my %s, %h, ;\n  my ($result,$blast_\
output);\n  &set_temporary_dir (\"set\",$infile,\"\
seq.pep\");\n  %s=read_fasta_seq (\"seq.pep\");\n \
 open (R, \">result.aln\");\n\n\n  #print stdout \\
"\\n\";\n  foreach $seq (keys(%s))\n    {\n      m\
y $c;\n      my $found;\n\n      open (F, \">seqfi\
le\");\n      print (F \">$A\\n$s{$seq}{seq}\\n\")\
;\n      close (F);\n\n      $blast_output=&run_bl\
ast ($s{$seq}{name},$method, $db, \"seqfile\",\"ou\
tfile\");\n\n      %p=blast_xml2profile($s{$seq}{n\
ame}, $s{$seq}{seq},$maxid, $minid,$mincov,$blast_\
output);\n      unlink ($blast_output);\n\n      $\
c=1;\n      print stdout \"!\\tProcess: >$s{$seq}{\
name} [$SERVER/blast/$db][$CACHE_STATUS]\\n\";\n  \
    while (!$found && $c<$p{n})\n	{\n	  $pdbid=&id\
2pdbid($p{$c}{identifyer});\n	  if ( length ($pdbi\
d)>5){$pdbid=id2pdbid($p{$c}{definition});}\n\n	  \
if ( length ($pdbid)>5)\n	    {\n	      myexit(add\
_error (EXIT_FAILURE,$$,$$,getppid(), \"BLAST_FAIL\
URE::Could Not Parse PDBID ($p{$c}{identifyer},$p{\
$c}{definition})\"));\n	    }\n\n\n	  if (!&pdb_is\
_released($pdbid))\n	    {\n	      print stdout \"\
\\t\\t**$pdbid [PDB NOT RELEASED or WITHDRAWN]\\n\\
";\n	      $c++;\n	    }\n	  elsif (!&pdb_has_righ\
t_type ($pdbid,$type))\n	    {\n	      my $ptype=&\
pdb2type ($pdbid);\n	      my $etype=&type2etype($\
type);\n\n	      print stdout \"\\t\\t**$pdbid [$p\
type cannot be used (expected: $etype)]\\n\";\n	  \
    $c++;\n	    }\n	  else\n	    {\n	      $found=\
1;\n	    }\n	}\n\n      if ($found)\n	{\n	  print \
R \">$s{$seq}{name} _P_ $pdbid\\n\";\n	  print std\
out \"\\t\\t >$s{$seq}{name} _P_ $pdbid\\n\";\n	}\\
n      else\n	{\n	  print R \">$s{$seq}{name}\\n\"\
;\n	  print stdout \"\\t\\t >$s{$seq}{name} No Tem\
plate Selected\\n\";\n	}\n    }\n  close (R);\n  &\
set_temporary_dir (\"unset\",$mode, $method,\"resu\
lt.aln\",$outfile);\n}\nsub type2etype\n  {\n    m\
y $type=shift;\n    my $etype;\n\n    if ( $type=~\
/n/){$etype.=\"NMR \";}\n    if ( $type=~/d/){$ety\
pe.=\"diffraction \";}\n    if ( $type=~/m/){$etyp\
e.=\"model \";}\n    return $etype;\n  }\nsub pdb2\
type\n  {\n     my $pdb=shift;\n     my $f=vtmpnam\
();\n\n     my $value= &safe_system (\"t_coffee -o\
ther_pg extract_from_pdb -model_type $pdb > $f\");\
\n     my $r=&file2string ($f);\n     chomp($r);\n\
     return $r;\n   }\nsub pdb_has_right_type\n  {\
\n    my $pdb=shift;\n    my $type=shift;\n\n    m\
y $f=vtmpnam();\n\n    my $value= &safe_system (\"\
t_coffee -other_pg extract_from_pdb -model_type $p\
db > $f\");\n    my $r=&file2string ($f);\n    cho\
mp($r);\n\n\n    if ( $r eq \"NMR\" && $type=~/n/)\
{return 1;}\n    elsif ( $r eq \"diffraction\" && \
$type=~/d/){return 1;}\n    elsif ( $r eq \"model\\
" && $type=~/m/){return 1;}\n    else {return 0;}\\
n  }\nsub pdb_is_released\n  {\n    my $pdb=shift;\
\n    my $f=vtmpnam();\n\n    $value= &safe_system\
 (\"t_coffee -other_pg extract_from_pdb -is_releas\
ed_pdb_name $pdb > $f\");\n    my $r=&file2string \
($f);\n    chomp($r);\n    return $r;\n  }\nsub bl\
ast_msa\n  {\n    my ($blast,$infile,$db,$outfile)\
=@_;\n    my ($a, %s1, %s, %qs, %qs1);\n    my $se\
qfile;\n    my $SEQ=new FileHandle;\n    my $seqfi\
le=\"seqfile\";\n    my @txt;\n\n\n    %s1=&read_f\
asta_seq ($db);\n    %s=&fasta_hash2index_hash(%s1\
);\n    %qs1=&read_fasta_seq ($infile);\n    %qs=&\
fasta_hash2index_hash(%qs1);\n\n\n    #&safe_syste\
m (\"formatdb -i $db\");\n    if ($blast eq \"blas\
tp\"){&safe_system  (\"blastall -i $infile -d $db \
-m7 -p blastp -o io\");}\n    elsif ($blast eq \"b\
lastn\"){&safe_system  (\"blastn -query $infile -d\
b $db -outfmt 5 -word_size 4 -out io\");}\n\n    &\
set_blast_type (\"io\");\n\n\n    my %FB=&xml2tag_\
list (\"io\", \"Iteration\");\n    open (F, \">$ou\
tfile\");\n    print F \"! TC_LIB_FORMAT_01\\n\";\\
n    print F \"$s{n}\\n\";\n    for ( my $a=0; $a<\
$s{n}; $a++)\n      {\n	print F \"$s{$a}{name} $s{\
$a}{len} $s{$a}{seq}\\n\";\n      }\n\n\n    for (\
 my $a=0; $a<$FB{n}; $a++)\n      {\n	my %p=blast_\
xml2profile ($qs{$a}{name}, $qs{$a}{seq},100, 0, 0\
, $FB{$a}{body});\n	my $query=$p{0}{name};\n	my $i\
= $s1{$query}{order}+1;\n	for (my $b=1; $b<$p{n}; \
$b++)\n	  {\n	    my $l=length ($p{$b}{Qseq});\n	 \
   my $hit=$p{$b}{definition};\n	    my $Qstart=$p\
{$b}{Qstart};\n	    my $Hstart=$p{$b}{Hstart};\n	 \
   my $identity=$p{$b}{identity};\n	    my @lrQ=sp\
lit (//,$p{$b}{Qseq});\n	    my @lrH=split (//,$p{\
$b}{Hseq});\n\n	    my $j= $s1{$hit}{order}+1;\n	 \
   #if ( $j==$i){next;}\n	    printf F \"# %d %d\\\
n\", $i, $j;\n	    #  print  F \"\\n$p{$b}{Qseq} (\
$Qstart)\\n$p{$b}{Hseq} ($Hstart)\";\n	    for ($c\
=0; $c<$l; $c++)\n	      {\n		my $rQ=$lrQ[$c];\n		\
my $rH=$lrH[$c];\n		my $n=0;\n\n		if ($rQ ne \"-\"\
){$n++, $Qstart++;}\n		if ($rH ne \"-\"){$n++; $Hs\
tart++;}\n\n		if ( $n==2)\n		  {\n		    printf F \\
"\\t%d %d %d\\n\", $Qstart-1, $Hstart-1,$identity;\
\n		  }\n	      }\n	  }\n      }\n    print F \"! \
SEQ_1_TO_N\\n\";\n    close (F);\n    return $outp\
ut;\n  }\n\nsub blast_msa_old\n  {\n    my ($infil\
e,$outfile)=@_;\n    my ($a, %seq);\n    %s1=&read\
_fasta_seq ($infile);\n    foreach $s (keys (%s1))\
\n      {\n	$i=$s1{$s}{order};\n	$s{$i}{name}=$s;\\
n	$s{$i}{seq}=$s1{$s}{seq};\n	$s{$i}{len}=length( \
$s{$i}{seq});\n	$s{n}++;\n      }\n    &safe_syste\
m (\"formatdb -i $infile\");\n    &safe_system (\"\
blastall -i $infile -d $infile -m7 -o io\");\n    \
&set_blast_type (\"io\");\n\n    %FB=&xml2tag_list\
 (\"io\", \"Iteration\");\n\n    open (F, \">$outf\
ile\");\n    print F \"! TC_LIB_FORMAT_01\\n\";\n \
   print F \"$s{n}\\n\";\n    for ( $a=0; $a<$s{n}\
; $a++)\n      {\n	print F \"$s{$a}{name} $s{$a}{l\
en} $s{$a}{seq}\\n\";\n      }\n    for ( $a=0; $a\
<$FB{n}; $a++)\n      {\n	%p=blast_xml2profile ($s\
{$a}{name}, $s{$a}{seq},100, 0, 0, $FB{$a}{body});\
\n	for ($b=1; $b<$p{n}; $b++)\n	  {\n	    my $l=le\
ngth ($p{$b}{Qseq});\n	    my $hit=$p{$b}{definiti\
on};\n	    my $Qstart=$p{$b}{Qstart};\n	    my $Hs\
tart=$p{$b}{Hstart};\n	    my $identity=$p{$b}{ide\
ntity};\n	    my @lrQ=split (//,$p{$b}{Qseq});\n	 \
   my @lrH=split (//,$p{$b}{Hseq});\n	    my $i= $\
s1{$s{$a}{name}}{order}+1;\n	    my $j= $s1{$hit}{\
order}+1;\n	    #if ( $j==$i){next;}\n	    printf \
F \"# %d %d\\n\", $i, $j;\n	    #  print  F \"\\n$\
p{$b}{Qseq} ($Qstart)\\n$p{$b}{Hseq} ($Hstart)\";\\
n	    for ($c=0; $c<$l; $c++)\n	      {\n		my $rQ=\
$lrQ[$c];\n		my $rH=$lrH[$c];\n		my $n=0;\n\n		if \
($rQ ne \"-\"){$n++, $Qstart++;}\n		if ($rH ne \"-\
\"){$n++; $Hstart++;}\n\n		if ( $n==2)\n		  {\n		 \
   printf F \"\\t%d %d %d\\n\", $Qstart-1, $Hstart\
-1,$identity;\n		  }\n	      }\n	  }\n      }\n   \
 print F \"! SEQ_1_TO_N\\n\";\n    close (F);\n   \
 return $output;\n\n  }\n\nsub seq2msa\n  {\n    m\
y ($mode, $infile, $method, $param, $outfile,$data\
base)=@_;\n    &set_temporary_dir (\"set\",$infile\
,\"seq.pep\", $database, \"db.pep\");\n    $param.\
=\" >/dev/null 2>&1 \";\n\n\n    #make sure test.p\
ep is in FASTA\n    &safe_system (\"t_coffee -othe\
r_pg seq_reformat -in seq.pep -output fasta_seq > \
x\");\n    `mv x seq.pep`;\n\n    if ( $method eq \
\"blastp\")\n      {\n	&blast_msa (\"blastp\",\"se\
q.pep\",$database,\"result.aln\");\n      }\n    e\
lsif ( $method eq \"blastn\")\n      {\n	&blast_ms\
a (\"blastn\",\"seq.pep\",$database,\"result.aln\"\
);\n      }\n\n    elsif ( $method eq \"muscle\")\\
n      {\n	`muscle -in seq.pep -out result.aln $pa\
ram`;\n      }\n    elsif ( $method eq \"probcons\\
")\n      {\n	`probcons seq.pep >result.aln 2>/dev\
/null`;\n      }\n    elsif ( $method eq \"mafft\"\
)\n      {\n	`mafft --quiet --localpair --maxitera\
te 1000 seq.pep> result.aln  2>/dev/null`\n      }\
\n    elsif ( $method=~/prank/)\n      {\n	`$metho\
d -d=seq.pep -o=result.aln -quiet 2>/dev/null`;\n	\
`mv result.aln.1.fas result.aln`;\n      }\n    el\
sif ($method eq \"clustalo\")\n      {\n	`clustalo\
 -i seq.pep > result.aln`;\n      }\n    else\n   \
   {\n	`$method -infile=seq.pep -outfile=result.al\
n`;\n      }\n\n    &set_temporary_dir (\"unset\",\
$mode, $method,\"result.aln\",$outfile);\n    myex\
it ($EXIT_SUCCESS);\n  }\n\nsub seq2thread_pair\n \
 {\n    my ($mode, $infile, $pdbfile1, $method, $p\
aram, $outfile)=@_;\n    &set_temporary_dir (\"set\
\",$infile,\"seq.pep\",$pdbfile1,\"struc.pdb\");\n\
    if ($method eq \"fugueali\")\n      {\n	#Env V\
ariable that need to be defined for Fugue\n	if (!$\
ENV{FUGUE_LIB_LIST}){$ENV{FUGUE_LIB_LIST}=\"DUMMY\\
";}\n	if (!$ENV{HOMSTRAD_PATH})  {$ENV{HOMSTRAD_PA\
TH}=\"DUMMY\";}\n	if (!$ENV{HOMS_PATH}){$ENV{HOMS_\
PATH}=\"DUMMY\";}\n\n	`joy struc.pdb >x 2>x`;\n	&c\
heck_file(\"struc.tem\", \"Joy failed [FATAL:$PROG\
RAM/$method]\");\n	`melody -t struc.tem >x 2>x`;\n\
	&check_file(\"struc.tem\", \"Melody failed [FATAL\
:$PROGRAM/$method]\");\n	`fugueali -seq seq.pep -p\
rf struc.fug -print > tmp_result.aln`;\n\n	&check_\
file(\"tmp_result.aln\", \"Fugue failed [FATAL:$PR\
OGRAM/$method]\");\n	&safe_system (\"t_coffee -oth\
er_pg seq_reformat -in tmp_result.aln -output fast\
a_aln >result.aln\");\n      }\n    elsif ( $metho\
d eq \"t_coffee\")\n      {\n	&safe_system (\"t_co\
ffee -in Pstruc.pdb Sseq.pep Mslow_pair -outfile r\
esult.aln -quiet\");\n      }\n    else\n      {\n\
	&safe_system (\"$method -infile=seq.pep -pdbfile1\
=struc.pdb -outfile=result.aln $param>x 2>x\");\n \
     }\n    &set_temporary_dir (\"unset\",$mode,$m\
ethod,\"result.aln\",$outfile);\n    myexit ($EXIT\
_SUCCESS);\n  }\nsub seq2pdbid_pair\n  {\n    my (\
$mode, $pdbfile1, $pdbfile2, $method, $param, $out\
file)=@_;\n    my ($name);\n\n\n    &set_temporary\
_dir (\"set\");\n    $name=$pdbfile1.\" \".$pdbfil\
e2;\n\n    if (    &cache_file(\"GET\",\"\",\"$nam\
e\",\"$method\",\"dali\",$outfile,\"EBI\"))\n     \
 {return $outfile;}\n    else\n      {\n	if ($meth\
od eq \"daliweb\")\n	  {\n	    $pdbfile1=~/(....)(\
.)/;\n	    $id1=$1; $c1=$2;\n\n	    $pdbfile2=~/(.\
...)(.)/;\n	    $id2=$1; $c2=$2;\n\n	    $command=\
\"t_coffee -other_pg dalilite.pl --pdb1 $id1 --cha\
inid1 $c1 --pdb2 $id2 --chainid2 $c2 --email=$EMAI\
L  >dali_stderr 2>dali_stderr\";\n	    $dali=`$com\
mand`;\n\n	    open (F, \"dali_stderr\");\n	    wh\
ile (<F>)\n	      {\n		if ( /JobId: dalilite-(\\S+\
)/)\n		{\n		  $jobid=$1;\n		}\n	      }\n	    clos\
e (F);\n	    unlink (\"dali_stderr\");\n\n	    $ou\
tput1=\"dalilite-$jobid.txt\";\n	    if ( -e $outp\
ut1)\n	      {\n		unlink ($output1);\n		&url2file \
(\"http://www.ebi.ac.uk/Tools/es/cgi-bin/jobresult\
s.cgi/dalilite/dalilite-$jobid/aln.html\", \"outpu\
t2\");\n\n		if ( -e \"output2\")\n		  {\n		    my \
($seq1, $seq2);\n		    $seq1=$seq2=\"\";\n\n		    \
open (F, \"output2\");\n		    while (<F>)\n		     \
 {\n			$l=$_;\n			if ( $l=~/Query\\s+(\\S+)/)\n			\
  {\n			    $seq1.=$1;\n			  }\n			elsif ( $l=~/Sb\
jct\\s+(\\S+)/)\n			  {\n			    $seq2.=$1;\n			  }\
\n		      }\n		    close (F);\n		    unlink (\"out\
put2\");\n		    if ($seq1 ne \"\" && $seq2 ne \"\"\
)\n		      {\n			$output3=\">$A\\n$seq1\\n>$B\\n$s\
eq2\\n\";\n			$output3=~s/\\./-/g;\n			open (F, \"\
>result.aln\");\n			print F \"$output3\";\n			clos\
e (F);\n		      }\n		  }\n	      }\n	  }\n      }\\
n    &cache_file(\"SET\",\"\",\"$name\",\"$method\\
",\"dali\",\"result.aln\",\"EBI\");\n    &set_temp\
orary_dir (\"unset\",$mode, $method, \"result.aln\\
",$outfile);\n    myexit ($EXIT_SUCCESS);\n  }\nsu\
b seq2pdb_pair\n  {\n    my ($mode, $pdbfile1, $pd\
bfile2, $method, $param, $outfile)=@_;\n\n    &set\
_temporary_dir (\"set\",$pdbfile1,\"pdb1.pdb\",$pd\
bfile2,\"pdb2.pdb\");\n    if ($method eq \"t_coff\
ee\")\n      {\n	&safe_system (\"t_coffee -in Ppdb\
1.pdb Ppdb2.pdb -quiet -outfile=result.aln\");\n  \
    }\n    elsif ( $method eq \"DaliLite\")\n     \
 {\n	if ( &safe_system (\"DaliLite -pairwise pdb1.\
pdb pdb2.pdb >tmp1\")==$EXIT_SUCCESS)\n	  {\n	    \
 my ($seq1, $seq2);\n	     $seq1=$seq2=\"\";\n\n	 \
    open (F, \"tmp1\");\n	     while (<F>)\n	     \
  {\n		 $l=$_;\n		 if ( $l=~/Query\\s+(\\S+)/)\n		\
   {\n		     $seq1.=$1;\n		   }\n		 elsif ( $l=~/S\
bjct\\s+(\\S+)/)\n		   {\n		     $seq2.=$1;\n		   \
}\n	       }\n	     close (F);\n	     unlink (\"tm\
p1\");\n	     if ($seq1 ne \"\" && $seq2 ne \"\")\\
n	       {\n		 my $output3=\">$A\\n$seq1\\n>$B\\n$\
seq2\\n\";\n		 $output3=~s/\\./-/g;\n		 open (F, \\
">result.aln\");\n		 print F \"$output3\";\n		 clo\
se (F);\n	       }\n	   }\n	else\n	  {\n	    print\
 \"ERROR: DalLite failed to align the considered s\
tructures[tc_generic_method.pl]\\n\";\n	  }\n     \
 }\n    elsif ( $method eq \"TMalign\")\n      {\n\
	if ( &safe_system (\"TMalign pdb1.pdb pdb2.pdb >t\
mp1\")==$EXIT_SUCCESS)\n	  {\n	    `tail -4 tmp1 >\
 tmp2`;\n\n	    open (F, \"tmp2\");\n	    while (<\
F>)\n	      {\n		unshift(@l, $_);\n	      }\n	    \
close (F);\n	    open (F, \">result.aln\");\n	    \
$l[3]=~s/[^a-zA-Z0-9-]/\\-/g;\n	    $l[1]=~s/[^a-z\
A-Z0-9-]/\\-/g;\n	    print F \">$A\\n$l[3]\\n>$B\\
\n$l[1]\\n\";\n	    close (F);\n	  }\n	else\n	  {\\
n	    print \"ERROR: TMalign failed to align the c\
onsidered structures[tc_generic_method.pl]\\n\";\n\
	    `rm result.aln >/dev/null 2>/dev/null`;\n	  }\
\n      }\n    elsif ( $method eq \"mustang\")\n  \
    {\n	if ( &safe_system (\"mustang -i pdb1.pdb p\
db2.pdb -F fasta >/dev/null 2>/dev/null\")==$EXIT_\
SUCCESS)\n	  {\n	    `mv results.afasta result.aln\
`;\n	  }\n	else\n	  {\n	    print \"ERROR: mustang\
 failed to align the considered structures[tc_gene\
ric_method.pl]\\n\";\n	    `rm result.aln >/dev/nu\
ll 2>/dev/null`;\n	  }\n      }\n    else\n      {\
\n	if ( &safe_system (\"$method -pdbfile1=pdb1.pep\
 -pdbfile2=pdb2.pdb -outfile=result.aln $param>x 2\
>x\")==$EXIT_SUCCESS)\n	  {\n	    `mv results.afas\
ta result.aln`;\n	  }\n	else\n	  {\n	    print \"E\
RROR: $method failed to align the considered struc\
tures[tc_generic_method.pl]\\n\";\n	    `rm result\
.aln >/dev/null 2>/dev/null`;\n	  }\n      }\n    \
&set_temporary_dir (\"unset\",$mode, $method, \"re\
sult.aln\",$outfile);\n    myexit ($EXIT_SUCCESS);\
\n  }\n\nsub seq2rnapdb_pair\n  {\n    my ($mode, \
$pdbfile1, $pdbfile2, $method, $param, $outfile)=@\
_;\n    \n    if ($method eq \"runsara.py\")\n    \
  {\n	my $path=$ENV{PATH};\n	\n	if ($ENV{X3DNA_4_S\
ARA}){$ENV{PATH}=\"$ENV{X3DNA_4_SARA}:$path\";}\n	\
\n	open(TMP,\"<$pdbfile1\");\n	my $count = 0;\n	my\
 $line;\n	while (<TMP>)\n	  {\n	    $line = $_;\n	\
    if ($count ==1)\n	      {\n		last;\n	      }\n\
	    $count += 1;\n	  }\n	\n	\n	$chain1 = substr($\
line,length($line)-3,1);\n	\n	close TMP;\n	open(TM\
P,\"<$pdbfile2\");\n	my $count = 0;\n	while (<TMP>\
)\n	  {\n	    $line = $_;\n	    if ($count ==1)\n	\
      {\n		last;\n	      }\n	    $count += 1;\n	  \
}\n	$chain2 = substr($line,length($line)-3,1);\n	c\
lose TMP;\n	\n	$tmp_file=&vtmpnam();\n	\n	safe_sys\
tem(\"runsara.py $pdbfile1 $chain1 $pdbfile2 $chai\
n2 -s -o $tmp_file --limitation 5000 > /dev/null 2\
> /dev/null\");\n	if ($ENV{X3DNA_4_SARA}){$ENV{PAT\
H}=$path;}\n	\n	open(TMP,\"<$tmp_file\") or die \"\
cannot open the sara tmp file:$!\\n\";\n	open(OUT,\
\">$outfile\") or die \"cannot open the $outfile f\
ile:$!\\n\";\n	\n	my $switch = 0;\n	my $seqNum = 0\
;\n	foreach my $line (<TMP>)\n	  {\n	    next unle\
ss ($line=~/SARAALI/);\n	    if ($line=~/>/)\n	   \
   {\n		$switch =0;\n		print OUT \">seq$seqNum\\n\\
";\n		$seqNum++;\n	      }\n	    if ($switch < 2){\
\n	      $switch++;\n	      next;\n	    }\n	    \n\
	    if ($line =~/REMARK\\s+SARAALI\\s+([^\\*]+)\\\
*/)\n	      {\n		my $string = $1;\n		print OUT \"$\
string\\n\";\n	      }\n	  }\n	close TMP;\n	close \
OUT;\n	unlink($tmp_file);\n      }\n  }\nsub seq2p\
rofile_pair\n{\n	my ($mode, $profile1, $profile2, \
$method, $param, $outfile)=@_;\n\n\n	if ($method e\
q \"clustalw\")\n	{\n		&set_temporary_dir (\"set\"\
,$profile1,\"prf1.aln\",$profile2,\"prf2.aln\");\n\
		`clustalw -profile1=prf1.aln -profile2=prf2.aln \
-outfile=result.aln`;\n		&set_temporary_dir (\"uns\
et\",$mode, $method, \"result.aln\",$outfile);\n	}\
\n	elsif ( $method eq \"clustalo\")\n	{\n		`clusta\
lo --p1 $profile1 --p2 $profile2 -o $outfile --for\
ce`;\n	}\n	elsif ( $method eq \"hhalign\")\n	{\n		\
hhalign ( $profile1,$profile2,$outfile,$param);\n	\
}\n	else\n	{\n		`$method -profile1=prf1.aln -profi\
le2=prf2.aln -outfile=result.aln $param>x 2>x`;\n	\
}\n	myexit ($EXIT_SUCCESS);\n}\n\nsub pg_is_instal\
led\n  {\n    my @ml=@_;\n    my ($r, $p, $m);\n  \
  my $supported=0;\n\n    my $p=shift (@ml);\n    \
if ($p=~/::/)\n      {\n	if (safe_system (\"perl -\
M$p -e 1\")==$EXIT_SUCCESS){return 1;}\n	else {ret\
urn 0;}\n      }\n    else\n      {\n	$r=`which $p\
 2>/dev/null`;\n	if ($r eq \"\"){$r=0;}\n	else {$r\
=1;}\n\n	if ($r==0 && is_blast_package ($p)){retur\
n pg_is_installed (\"legacy_blast.pl\");}\n	else {\
return $r;}\n      }\n  }\n\nsub is_blast_package\\
n  {\n    my $p=shift;\n    if ( $p=~/blastp/){ret\
urn 1;}\n    elsif ($p=~/blastall/){return 1;}\n  \
  elsif ($p=~/blastn/){return 1;}\n    elsif ($p=~\
/blastx/){return 1;}\n    elsif ($p=~/formatdb/){r\
eturn 1;}\n    else {return 0;}\n  }\n\nsub check_\
internet_connection\n  {\n    my $internet;\n    m\
y $tmp;\n    &check_configuration ( \"wget\");\n\n\
    $tmp=&vtmpnam ();\n\n    if     (&pg_is_instal\
led    (\"wget\")){`wget www.google.com -O$tmp >/d\
ev/null 2>/dev/null`;}\n    elsif  (&pg_is_install\
ed    (\"curl\")){`curl www.google.com -o$tmp >/de\
v/null 2>/dev/null`;}\n\n    if ( !-e $tmp || -s $\
tmp < 10){$internet=0;}\n    else {$internet=1;}\n\
    if (-e $tmp){unlink $tmp;}\n\n    return $inte\
rnet;\n  }\nsub check_pg_is_installed\n  {\n    my\
 @ml=@_;\n    my $r=&pg_is_installed (@ml);\n    i\
f (!$r && $p=~/::/)\n      {\n	print STDERR \"\\nY\
ou Must Install the perl package $p on your system\
.\\nRUN:\\n\\tsudo perl -MCPAN -e 'install $pg'\\n\
\";\n      }\n    elsif (!$r)\n      {\n	myexit(fl\
ush_error(\"\\nProgram $p Supported but Not Instal\
led on your system\"));\n      }\n    else\n      \
{\n	return 1;\n      }\n  }\nsub set_temporary_dir\
\n  {\n    my @list=@_;\n    my $dir_mode, $a, $mo\
de, $method;\n\n    $dir_mode=shift (@list);\n\n\n\
    if ( $dir_mode eq \"set\")\n      {\n	$initial\
_dir=cwd();\n	if ( !$tmp_dir)\n	  {\n	    $rand=ra\
nd (100000);\n	    $tmp_dir=\"$TMPDIR/tmp4tcoffee_\
profile_pair_dir_$$\\_P_$rand\";\n	  }\n	if ( !-d \
$tmp_dir)\n	  {\n	    push (@TMPDIR_LIST, $tmp_dir\
);\n	    `mkdir $tmp_dir`;\n	  }\n\n	for ( $a=0; $\
a<=$#list; $a+=2)\n	      {\n		if (-e $list[$a]){ \
`cp $list[$a] $tmp_dir/$list[$a+1]`;}\n	      }\n	\
chdir $tmp_dir;\n      }\n    elsif ( $dir_mode eq\
 \"unset\")\n      {\n	$mode=shift (@list);\n	$met\
hod=shift (@list);\n\n	if (!-e $list[0])\n	  {\n	 \
  myexit(flush_error(\"Program $method failed to p\
roduce $list[1]\" ));\n	    myexit ($EXIT_FAILURE)\
;\n	  }\n	else\n	  {\n	    chdir $initial_dir;\n	 \
   # `t_coffee -other_pg seq_reformat -in $tmp_dir\
/$list[0] -output fasta_aln -out $tmp_dir/result2.\
aln`;\n	    `cp $tmp_dir/$list[0] $tmp_dir/result2\
.aln`;\n	    if ( $list[1] eq \"stdout\")\n	      \
{\n		open (F, \"$tmp_dir/result2.aln\");\n		while \
(<F>){print $_;}close(F);\n	      }\n	    else\n	 \
     {\n		`mv $tmp_dir/result2.aln $list[1]`;\n	  \
    }\n	    shift (@list); shift (@list);\n	    fo\
reach $f (@list)\n	      {\n		if (-e (\"$tmp_dir/$\
f\")){`mv $tmp_dir/$f .`;}\n	      }\n	  }\n      \
}\n  }\n\n\n\n\nsub my_get_opt\n  {\n    my @list=\
@_;\n    my ($cl, $a, $argv, @argl);\n\n    \n    \
@argl=();\n    $cl=shift @list;\n    for ( my $a=0\
; $a<=$#list; $a+=3)\n      {\n	my $option=$list[$\
a];\n	my $optional=$list[$a+1];\n	my $status=$list\
[$a+2];\n	my $argv=\"\";\n	if ($cl=~/$option(\\S+)\
/){$argv=$1;}\n	@argl=(@argl,$argv);\n\n\n	#$optio\
nal:0=>optional\n	#$optional:1=>must be set\n	#$st\
atus: 0=>no requirement\n	#$status: 1=>must be an \
existing file\n	#$status: 2=>must be an installed \
package\n	\n\n	if ($optional==0){;}\n	elsif ( $opt\
ional==1 && $argv eq \"\")\n	  {\n	    myexit(flus\
h_error( \"ERROR: Option $option must be set\"));\\
n	    myexit ($EXIT_FAILURE);\n	  }\n	if ($status=\
=0){;}\n	elsif ($status ==1 && $argv ne \"\" && !-\
e $argv)\n	  {\n	    myexit(flush_error( \"File [$\
argv] must exist\"));\n	    myexit ($EXIT_FAILURE)\
;\n	  }\n	elsif ( $status==2 && $argv ne \"\" && &\
check_pg_is_installed ($argv)==0)\n	  {\n	    myex\
it(flush_error( \" $argv is not installed\"));\n	 \
   myexit ($EXIT_FAILURE);\n	  }\n      }\n    ret\
urn @argl;\n    }\n\nsub check_file\n  {\n    my (\
$file, $msg)=@_;\n\n    if ( !-e $file)\n      {\n\
	myexit(flush_error(\"$msg\"));\n      }\n    }\ns\
ub hhalign\n  {\n    my ($aln1, $aln2, $outfile, $\
param)=@_;\n    my $h1, $h2;\n\n    $h{0}{index}=0\
;\n    $h{1}{index}=1;\n\n    $h{0}{aln}=$aln1;\n \
   $h{1}{aln}=$aln2;\n\n\n\n    %{$h{0}}=aln2psi_p\
rofile (%{$h{0}});\n    %{$h{1}}=aln2psi_profile (\
%{$h{1}});\n\n    $param=~s/#S/ /g;\n    $param=~s\
/#M/\\-/g;\n    $param=~s/#E/\\=/g;\n\n\n\n    $co\
mmand=\"hhalign -i $h{0}{a3m} -t $h{1}{a3m} -tc $o\
utfile.tmp -rank 1 -mapt 0 $param\";\n    `$comman\
d`;\n\n  #  `hhalign -i $h{0}{a3m} -t $h{1}{a3m} -\
tc $outfile.tmp -rank 1 -mapt 0 -gapf 0.8 -gapg 0.\
8`;\n\n\n    # To run global use the following\n\n\
    open (I, \"$outfile.tmp\");\n    open (O, \">$\
outfile\");\n    $h{0}{cons}=s/\\./x/g;\n    $h{1}\
{cons}=s/\\./x/g;\n\n    print O \"! TC_LIB_FORMAT\
_01\\n2\\n$h{0}{name} $h{0}{len} $h{0}{seq}\\n$h{1\
}{name} $h{1}{len} $h{1}{seq}\\n#1 2\\n\";\n\n    \
while (<I>)\n      {\n	if (/(\\d+)\\s+(\\d+)\\s+(\\
\d+)/)\n	  {\n	    print O \"\\t$h{0}{$1}\\t$h{1}{\
$2}\\t$3\\n\";\n	  }\n      }\n    print O \"! SEQ\
_1_TO_N\\n\";\n\n    close (O);\n    close (I);\n \
 }\n\nsub aln2psi_profile\n  {\n    my (%h)=@_;\n \
   my ($aln,$i,$hv, $a, @c, $n);\n\n\n    $i=$h{in\
dex};\n    $aln=$h{aln};\n\n    `cp $aln $$.hhh_al\
n`;\n    $command=\"t_coffee -other_pg seq_reforma\
t -in $aln -output hasch\";\n    $hv=`$command`;ch\
omp ($hv);\n\n    $h{a2m}=\"$tmp/$hv.tmp4hhpred.a2\
m\";\n    $h{a3m}=\"$tmp/$hv.tmp4hhpred.a3m\";\n  \
  if ( -e $h{a3m}){;}\n    else\n      {\n	$x=`whi\
ch hhconsensus`;\n	`hhconsensus  -M 50 -i $h{aln} \
-oa2m $h{a2m}`;\n	if (!-e $h{a2m})\n	  {\n	    pri\
nt STDERR \"Program tc_generic_method.pl FAILED to\
 run:\\n\\thhconsensus  -M 50 -i $h{aln} -oa2m $h{\
a2m}\";\n	    myexit ($EXIT_FAILURE);\n	  }\n\n	`h\
hconsensus  -M 50 -i $h{aln} -oa3m $h{a3m}`;\n	if \
(!-e $h{a3m})\n	  {\n	    print STDERR \"Program t\
c_generic_method.pl FAILED to run:\\n\\thhconsensu\
s  -M 50 -i $h{aln} -oa3m $h{a3m}\";\n	    myexit \
($EXIT_FAILURE);\n	  }\n       `buildali.pl $h{a3m\
} -n 1`;\n      }\n\n\n    $h{a2m_seq}=`head -n 2 \
$h{a2m} | grep -v \">\"`;chomp ($h{a2m_seq});\n   \
 $h{a3m_seq}=`head -n 2 $h{a3m} | grep -v \">\"`;c\
homp ($h{a3m_seq});\n    $h{cons}=$h{a2m_seq};\n  \
  $h{seq}=`head -n 2 $h{aln} | grep -v \">\"`;chom\
p ($h{seq});\n\n\n\n    @c=split (//, $h{cons});\n\
    $h{len}=$#c+1;\n    for ($n=0,$a=0, $b=0; $a<$\
h{len};$a++)\n      {\n	if ( $c[$a]=~/[A-Z]/)\n	  \
{\n	    $h{++$n}=++$b;\n\n	  }\n	elsif ( $c[$a]=~/\
[a-z\\.]/)\n	  {\n	    ++$b;\n	  }\n      }\n\n   \
 $name=`head -n 2 $h{aln} | grep \">\"`;\n    $nam\
e=~/\\>(\\S+)/;\n    $h{name}=$1;\n\n    `cp $h{a2\
m} $i.a2m`;\n    `cp $h{a3m} $i.a3m`;\n    `cp $h{\
aln} $i.hh_aln`;\n\n    return %h;\n  }\nsub read_\
fasta_seq_index\n  {\n    my $f=@_[0];\n    my %hs\
eq;\n    my (@seq, @com, @name);\n    my ($a, $s,$\
nseq);\n\n    open (F, $f);\n    while (<F>)\n    \
  {\n	$s.=$_;\n      }\n    close (F);\n\n\n    @n\
ame=($s=~/>(\\S*).*\\n[^>]*/g);\n\n    @seq =($s=~\
/>.*.*\\n([^>]*)/g);\n    @com =($s=~/>\\S*(.*)\\n\
([^>]*)/g);\n\n\n    $nseq=$#name+1;\n\n    for ($\
a=0; $a<$nseq; $a++)\n      {\n	my $s;\n	my $n=$na\
me[$a];\n	$hseq{$a}{name}=$n;\n	$seq[$a]=~s/[^A-Za\
-z]//g;\n	$hseq{$a}{order}=$a;\n	$hseq{$a}{seq}=$s\
eq[$a];\n	$hseq{$a}{com}=$com[$a];\n\n      }\n   \
 return %hseq;\n  }\nsub read_fasta_seq\n  {\n    \
my $f=@_[0];\n    my %hseq;\n    my (@seq, @com, @\
name);\n    my ($a, $s,$nseq);\n\n    open (F, $f)\
;\n    while (<F>)\n      {\n	$s.=$_;\n      }\n  \
  close (F);\n\n\n    @name=($s=~/>(\\S*).*\\n[^>]\
*/g);\n\n    @seq =($s=~/>.*.*\\n([^>]*)/g);\n    \
@com =($s=~/>\\S*(.*)\\n([^>]*)/g);\n\n\n    $nseq\
=$#name+1;\n\n    for ($a=0; $a<$nseq; $a++)\n    \
  {\n	my $s;\n	my $n=$name[$a];\n	$hseq{$n}{name}=\
$n;\n	$seq[$a]=~s/[^A-Za-z]//g;\n	$hseq{$n}{order}\
=$a;\n	$hseq{$n}{seq}=$seq[$a];\n	$hseq{$n}{com}=$\
com[$a];\n\n      }\n    return %hseq;\n  }\n\n\ns\
ub read_fasta_aln\n  {\n    my $f=@_[0];\n    my %\
hseq;\n    my (@seq, @com, @name);\n    my ($a, $s\
,$nseq);\n\n    open (F, $f);\n    while (<F>)\n  \
    {\n	$s.=$_;\n      }\n    close (F);\n\n\n    \
@name=($s=~/>(\\S*).*\\n[^>]*/g);\n\n    @seq =($s\
=~/>.*.*\\n([^>]*)/g);\n    @com =($s=~/>\\S*(.*)\\
\n([^>]*)/g);\n\n\n    $nseq=$#name+1;\n\n    for \
($a=0; $a<$nseq; $a++)\n      {\n	my $s;\n	my $n=$\
name[$a];\n	$hseq{$n}{name}=$n;\n	$seq[$a]=~s/[^A-\
Za-z-.()[\\]]//g;\n	$hseq{$n}{order}=$a;\n	$hseq{$\
n}{seq}=$seq[$a];\n	$hseq{$n}{com}=$com[$a];\n\n  \
    }\n    return %hseq;\n  }\n\nsub recode_name2\\
n{\n	my ($in)=shift;\n	my $mode=shift;\n\n	my %seq\
;\n	my $new_name;\n\n	if (! -e $in){return;}\n\n	#\
needed by ClustalOmega to avoid very long names\n	\
open (INFILE, \"+<$in\");\n\n	my $line;\n\n	if ($m\
ode eq \"code\")\n	{\n		chomp($line = <INFILE>);\n\
		my $line_length = length($line);\n		$new_name=++\
$RECODE_N;\n		$new_name=\">$new_name\";\n		my $new\
_length = length($new_name);\n		$RECODE {$new_name\
}=$line;\n		for ($count = $new_length; $count < $l\
ine_length; $count++)\n		{\n			$new_name .= \" \";\
\n		}\n		$new_name=\"$new_name\\n\";\n		seek INFIL\
E, 0, 0\n			or die \"could not seek: $!\";\n		prin\
t INFILE \"$new_name\";\n	}\n	else\n	{\n		my $n_fo\
und = 0;\n		my $file_pos=0;\n		$file_pos=tell INFI\
LE;\n		while (<INFILE>)\n		{\n			$line=$_;\n			$li\
ne =~ s/\\s*$//;\n\n			$old_name= $RECODE{$line};\\
n			if ($old_name ne \"\")\n			{\n				seek INFILE,\
 $file_pos, 0\n					or die \"could not seek: $!\";\
\n				print INFILE \"$old_name\\n\";\n				$file_po\
s++;\n				if ($file_pos == 2)\n				{\n					print \\
"stop\\n\";\n					break;\n				}\n			}\n			$file_po\
s=tell INFILE;\n		}\n\n	}\n\n\n	close INFILE;\n}\n\
\n\nsub recode_name\n{\n	my ($in)=shift;\n	my $mod\
e=shift;\n	my $f=new FileHandle;\n	my %seq;\n	my $\
new_name;\n\n	if (! -e $in){return;}\n\n	#needed b\
y ClustalOmega to avoid very long names\n	%seq=rea\
d_fasta_aln ($in);\n\n	open ($f, \">$in\");\n	fore\
ach my $s (keys(%seq))\n	{\n		if ($mode eq \"code\\
")\n		{\n			$new_name=++$RECODE_N;\n			$RECODE {$n\
ew_name}=$seq{$s}{name};\n		}\n		else\n		{\n			$ne\
w_name=$RECODE{$seq{$s}{name}};\n		}\n		print $f \\
">$new_name\\n$seq{$s}{seq}\\n\";\n	}\n	close $f;\\
n}\n\nsub fasta_hash2index_hash\n  {\n    my %s1=@\
_;\n    my %s;\n    foreach my $s (keys (%s1))\n  \
    {\n	my $i=$s1{$s}{order};\n	$s{$i}{name}=$s;\n\
	$s{$i}{seq}=$s1{$s}{seq};\n	$s{$i}{len}=length( $\
s{$i}{seq});\n	$s{n}++;\n      }\n    return %s;\n\
  }\nsub file_contains\n  {\n    my ($file, $tag, \
$max)=(@_);\n    my ($n);\n    $n=0;\n\n    if ( !\
-e $file && ($file =~/$tag/)) {return 1;}\n    els\
if ( !-e $file){return 0;}\n    else\n      {\n	op\
en (FC, \"$file\");\n	while ( <FC>)\n	  {\n	    if\
 ( ($_=~/$tag/))\n	      {\n		close (FC);\n		retur\
n 1;\n	      }\n	    elsif ($max && $n>$max)\n	   \
   {\n		close (FC);\n		return 0;\n	      }\n	    $\
n++;\n	  }\n      }\n    close (FC);\n    return 0\
;\n  }\n\n\nsub file2string\n  {\n    my $f=@_[0];\
\n    my $string, $l;\n    open (F,\"$f\");\n    w\
hile (<F>)\n      {\n\n	$l=$_;\n	#chomp ($l);\n	$s\
tring.=$l;\n      }\n    close (F);\n    $string=~\
s/\\r\\n//g;\n    $string=~s/\\n//g;\n    return $\
string;\n  }\n\n\nsub tag2value\n  {\n\n    my $ta\
g=(@_[0]);\n    my $word=(@_[1]);\n    my $return;\
\n\n    $tag=~/$word=\"([^\"]+)\"/;\n    $return=$\
1;\n    return $return;\n  }\n\nsub hit_tag2pdbid\\
n  {\n    my $tag=(@_[0]);\n    my $pdbid;\n\n    \
$tag=~/id=\"(\\S+)\"/;\n    $pdbid=$1;\n    $pdbid\
=~s/_//;\n    return $pdbid;\n  }\nsub id2pdbid\n \
 {\n    my $in=@_[0];\n    my $id;\n\n    $in=~/(\\
\S+)/;\n    $id=$in;\n    $id=~s/PDB/pdb/g;\n\n   \
 if ($id =~/pdb(.*)/){$id=$1;}\n    elsif ( $id=~/\
(\\S+)\\s+mol:protein/){$id=$1;}\n    $id=~s/[:|ï¿\
½ï¿½_]//g;\n    return $id;\n  }\nsub set_blast_ty\
pe\n  {\n    my $file =@_[0];\n    if (&file_conta\
ins ($file,\"EBIApplicationResult\",100)){$BLAST_T\
YPE=\"EBI\";}\n    elsif (&file_contains ($file,\"\
NCBI_BlastOutput\",100)) {$BLAST_TYPE=\"NCBI\";}\n\
    else\n      {\n	$BLAST_TYPE=\"\";\n      }\n  \
  return $BLAST_TYPE;\n  }\nsub is_valid_blast_xml\
\n    {\n      my $file=shift;\n      my $line;\n\\
n\n      if ( !-e $file) {return 0;}\n      $line=\
&file2tail ($file,100);\n\n      if ( $line=~/<\\/\
EBIApplicationResult/ || $line=~/<\\/NCBI_BlastOut\
put/ || $line=~/<\\/BlastOutput/ ){return 1;}\n   \
   return 0;\n    }\nsub file2blast_flavor\n      \
{\n	my $file=shift;\n	if (&file_contains ($file,\"\
EBIApplicationResult\",100)){return \"EBI\";}\n	el\
sif (&file_contains ($file,\"NCBI_BlastOutput\",10\
0)){return \"NCBI\";}\n	else {return \"UNKNOWN\";}\
\n      }\nsub blast_xml2profile\n  {\n    my ($na\
me,$seq,$maxid, $minid, $mincov, $file)=(@_);\n   \
 my (%p, $a, $string, $n);\n\n\n\n    if ($BLAST_T\
YPE eq \"EBI\" || &file_contains ($file,\"EBIAppli\
cationResult\",100)){%p=ebi_blast_xml2profile(@_);\
}\n    elsif ($BLAST_TYPE eq \"NCBI\" || &file_con\
tains ($file,\"NCBI_BlastOutput\",100)){%p=ncbi_bl\
ast_xml2profile(@_);}\n    else\n      {\n	myexit(\
add_error ( $$,$$,getppid(), \"BLAST_FAILURE::unko\
wn XML\",$CL));\n      }\n    for ($a=0; $a<$p{n};\
 $a++)\n      {\n	my $name=$p{$a}{name};\n	$p{$nam\
e}{seq}=$p{$a}{seq};\n	$p{$name}{index}=$a;\n     \
 }\n    return %p;\n  }\nsub ncbi_tblastx_xml2lib_\
file\n  {\n    my  ($outlib,$string)=(@_);\n    my\
 ($L,$l, $a,$b,$c,$d,$i,$nhits,@identifyerL);\n   \
 my (%ITERATION);\n\n    open (F, \">>$outlib\");\\
n\n    $seq=~s/[^a-zA-Z]//g;\n    $L=length ($seq)\
;\n\n    %ITERATION=xml2tag_list ($string, \"Itera\
tion\");\n    for ($i=0; $i<$ITERATION{n};$i++)\n \
     {\n	my ($qindex, $qlen, %hit, $string);\n	$st\
ring=$ITERATION{$i}{body};\n\n	$qindex=xmltag2valu\
e($string,\"Iteration_iter-num\");\n	$qlen  =xmlta\
g2value($string,\"Iteration_query-len\");\n	%hit=&\
xml2tag_list  ($string, \"Hit\");\n\n	for ($a=0; $\
a<$hit{n}; $a++)\n	  {\n	    my ($string);\n	    $\
string=$hit{$a}{body};\n\n	    $hindex=xmltag2valu\
e($string,\"Hit_accession\")+1;\n	    if ($hindex<\
=$qindex){next;}\n	    else  {print F  \"# $qindex\
 $hindex\\n\";}\n\n\n	    $hlen=xmltag2value  ($st\
ring,\"Hit_len\");\n	    %HSP=&xml2tag_list  ($str\
ing, \"Hsp\");\n\n	    for ($b=0; $b<$HSP{n}; $b++\
)\n	      {\n		my ($string, $qs,$qe,$qf,$hs,$he,$h\
f,$s, $d, $e);\n		$string=$HSP{$b}{body};\n\n		$qs\
=xmltag2value  ($string,\"Hsp_query-from\");\n		$q\
e=xmltag2value  ($string,\"Hsp_query-to\");\n		$qf\
=xmltag2value  ($string,\"Hsp_query-frame\");\n\n	\
	$hs=xmltag2value  ($string,\"Hsp_hit-from\");\n		\
$he=xmltag2value  ($string,\"Hsp_hit-to\");\n		$hf\
=xmltag2value  ($string,\"Hsp_hit-frame\");\n\n		$\
s=xmltag2value  ($string,\"Hsp_identity\");\n		$l=\
xmltag2value  ($string,\"Hsp_align-len\");\n		$s=i\
nt(($s*100)/$l);\n\n		if ($qf>0)\n		  {$rqs=$qs; $\
rqe=$qe;}\n		else\n		  {\n		    $rqe=($qlen-$qs)+1\
;\n		    $rqs=($qlen-$qe)+1;\n		  }\n\n		if ($hf>0\
)\n		  {$rhs=$hs; $rhe=$he;}\n		else\n		  {\n		   \
 $rhe=($hlen-$hs)+1;\n		    $rhs=($hlen-$he)+1;\n	\
	  }\n		for ($d=0,$e=$rqs; $e<$rqe; $e++,$d++)\n		\
  {\n		    my ($r1,$r2);\n		    $r1=$e;\n		    $r2\
=$rhs+$d;\n		    print F \" $r1 $r2 $s 0\\n\";\n		\
  }\n	      }\n	  }\n      }\n    print F \"! SEQ_\
1_TO_N\\n\";\n\n    close (F);\n    return %lib;\n\
  }\n\nsub ncbi_tblastpx_xml2lib_file\n  {\n    my\
  ($outlib,$string,%s)=(@_);\n    my ($L,$l, $a,$b\
,$c,$d,$i,$nhits,@identifyerL);\n    my (%ITERATIO\
N,%hdes, %qdes);\n\n    open (F, \">>$outlib\");\n\
\n    $seq=~s/[^a-zA-Z]//g;\n    $L=length ($seq);\
\n\n    %ITERATION=xml2tag_list ($string, \"Iterat\
ion\");\n    for ($i=0; $i<$ITERATION{n};$i++)\n  \
    {\n	my ($qindex, $qlen, %hit, $string);\n	$str\
ing=$ITERATION{$i}{body};\n\n	$qdef=xmltag2value($\
string,\"Iteration_query-def\");\n	%qdes=&tblastpx\
_name2description($qdef,%s);\n	$qlen  =xmltag2valu\
e($string,\"Iteration_query-len\");\n	%hit=&xml2ta\
g_list  ($string, \"Hit\");\n\n	for ($a=0; $a<$hit\
{n}; $a++)\n	  {\n	    my ($string);\n	    $string\
=$hit{$a}{body};\n	    $hdef=xmltag2value($string,\
\"Hit_def\");\n	    %hdes=&tblastpx_name2descripti\
on($hdef,%s);\n	    if ($hdes{index}<=$qdes{index}\
){next;}\n	    else  {print F  \"# $qdes{index} $h\
des{index}\\n\";}\n\n\n	    $hlen=xmltag2value  ($\
string,\"Hit_len\");\n	    %HSP=&xml2tag_list  ($s\
tring, \"Hsp\");\n\n	    for ($b=0; $b<$HSP{n}; $b\
++)\n	      {\n		my ($string, $l,$qs,$qe,$qf,$hs,$\
he,$hf,$s, $d, $e, @s1, @s2);\n		$string=$HSP{$b}{\
body};\n\n		$qs=xmltag2value  ($string,\"Hsp_query\
-from\");\n		$qe=xmltag2value  ($string,\"Hsp_quer\
y-to\");\n		$qf=$qdes{frame};\n		$qseq=xmltag2valu\
e  ($string,\"Hsp_qseq\");\n\n		$hs=xmltag2value  \
($string,\"Hsp_hit-from\");\n		$he=xmltag2value  (\
$string,\"Hsp_hit-to\");\n		$hf=$hdes{frame};\n		$\
hseq=xmltag2value  ($string,\"Hsp_hseq\");\n\n		$s\
=xmltag2value  ($string,\"Hsp_identity\");\n		$l=x\
mltag2value  ($string,\"Hsp_align-len\");\n		$s=in\
t(($s*100)/$l);\n		@s1=tblastpx_hsp2coordinates($q\
seq,$qs,$qe,%qdes);\n		@s2=tblastpx_hsp2coordinate\
s($hseq,$hs,$he,%hdes);\n\n\n		for ($f=0; $f<=$#s1\
; $f++)\n		  {\n		    if ($s1[$f]==-1 || $s2[$f]==\
-1){next;}\n		    else\n		      {\n			print F \" $\
s1[$f] $s2[$f] $s 0\\n\";\n		      }\n		  }\n	    \
  }\n	  }\n      }\n    print F \"! SEQ_1_TO_N\\n\\
";\n\n    close (F);\n    return %lib;\n  }\nsub t\
blastpx_hsp2coordinates\n  {\n    my ($seq, $s, $e\
, %des)=@_;\n    my @list;\n    my @sa;\n    my @g\
ap=(-1,-1,-1);\n\n    $s=$des{start}+3*($s-1);\n\n\
    if ($des{strand} eq \"d\"){;}\n    else {$s=($\
des{length}-$s)+1;}\n\n    foreach $c (split (//,$\
seq))\n      {\n	if ( $c eq '-'){push (@list,@gap)\
;}\n	elsif ($des{strand} eq \"d\")\n	  {\n	    pus\
h(@list,$s++,$s++,$s++);\n	  }\n	else\n	  {\n	    \
push(@list, $s--,$s--,$s--);\n	  }\n      }\n    r\
eturn @list;\n  }\n\nsub tblastpx_name2description\
\n  {\n    my ($name, %s)=@_;\n    my @at=split(\"\
__\", $name);\n    my %des;\n\n    $des{name}=$at[\
0];\n    $des{strand}=$at[1];\n\n    $des{start}=$\
at[2];\n    $des{end}=$at[3];\n    $des{length}=$a\
t[4];\n    $des{index}=$s{$at[0]}{order}+1;\n    r\
eturn %des;\n  }\nsub ncbi_blast_xml2profile\n  {\\
n    my ($name,$seq,$maxid, $minid, $mincov, $stri\
ng)=(@_);\n    my ($L,$l, $a,$b,$c,$d,$nhits,@iden\
tifyerL);\n\n\n    $seq=~s/[^a-zA-Z]//g;\n    $L=l\
ength ($seq);\n\n    #This is causing the NCBI par\
ser to fail when Iteration_query-def is missing\n \
   #%query=&xml2tag_list ($string, \"Iteration_que\
ry-def\");\n    #$name=$query{0}{body};\n\n    %hi\
t=&xml2tag_list ($string, \"Hit\");\n\n\n    for (\
$nhits=0,$a=0; $a<$hit{n}; $a++)\n      {\n	my ($l\
db,$id, $identity, $expectation, $start, $end, $co\
verage, $r);\n	my (%ID,%DE,%HSP);\n\n	$ldb=\"\";\n\
\n	%ID=&xml2tag_list ($hit{$a}{body}, \"Hit_id\");\
\n	$identifyer=$ID{0}{body};\n\n	%DE=&xml2tag_list\
 ($hit{$a}{body}, \"Hit_def\");\n	$definition=$DE{\
0}{body};\n\n	%HSP=&xml2tag_list ($hit{$a}{body}, \
\"Hsp\");\n	for ($b=0; $b<$HSP{n}; $b++)\n	  {\n	 \
   my (%START,%END,%E,%I,%Q,%M);\n\n\n	    %START=\
&xml2tag_list ($HSP{$b}{body}, \"Hsp_query-from\")\
;\n	    %HSTART=&xml2tag_list ($HSP{$b}{body}, \"H\
sp_hit-from\");\n\n	    %LEN=  &xml2tag_list ($HSP\
{$b}{body}, \"Hsp_align-len\");\n	    %END=  &xml2\
tag_list ($HSP{$b}{body}, \"Hsp_query-to\");\n	   \
 %HEND=  &xml2tag_list ($HSP{$b}{body}, \"Hsp_hit-\
to\");\n	    %E=&xml2tag_list     ($HSP{$b}{body},\
 \"Hsp_evalue\");\n	    %I=&xml2tag_list     ($HSP\
{$b}{body}, \"Hsp_identity\");\n	    %Q=&xml2tag_l\
ist     ($HSP{$b}{body}, \"Hsp_qseq\");\n	    %M=&\
xml2tag_list     ($HSP{$b}{body}, \"Hsp_hseq\");\n\
\n	    for ($e=0; $e<$Q{n}; $e++)\n\n	      {\n		$\
qs=$Q{$e}{body};\n		$ms=$M{$e}{body};\n\n		$expect\
ation=$E{$e}{body};\n		$identity=($LEN{$e}{body}==\
0)?0:$I{$e}{body}/$LEN{$e}{body}*100;\n		$start=$S\
TART{$e}{body};\n		$end=$END{$e}{body};\n		$Hstart\
=$HSTART{$e}{body};\n		$Hend=$HEND{$e}{body};\n\n	\
	$coverage=($L)?(($end-$start)*100)/$L:0;\n\n		if \
($identity>$maxid || $identity<$minid || $coverage\
<$mincov){next;}\n		@lr1=(split (//,$qs));\n		@lr2\
=(split (//,$ms));\n		$l=$#lr1+1;\n		for ($c=0;$c<\
$L;$c++){$p[$nhits][$c]=\"-\";}\n		for ($d=0,$c=0;\
 $c<$l; $c++)\n		  {\n		    $r=$lr1[$c];\n		    if\
 ( $r=~/[A-Za-z]/)\n		      {\n\n			$p[$nhits][$d \
+ $start-1]=$lr2[$c];\n			$d++;\n		      }\n		  }\\
n		$Qseq[$nhits]=$qs;\n		$Hseq[$nhits]=$ms;\n		$Qs\
tartL[$nhits]=$start;\n		$HstartL[$nhits]=$Hstart;\
\n		$identityL[$nhits]=$identity;\n		$endL[$nhits]\
=$end;\n		$definitionL[$nhits]=$definition;\n		$id\
entifyerL[$nhits]=$identifyer;\n		$comment[$nhits]\
=\"$ldb|$identifyer [Eval=$expectation][id=$identi\
ty%][start=$Hstart end=$Hend]\";\n		$nhits++;\n	  \
    }\n	  }\n      }\n\n\n    $profile{n}=0;\n    \
$profile{$profile{n}}{name}=$name;\n    $profile{$\
profile{n}}{seq}=$seq;\n    $profile {n}++;\n\n   \
 for ($a=0; $a<$nhits; $a++)\n      {\n	$n=$a+1;\n\
\n	$profile{$n}{name}=\"$name\\_$a\";\n	$profile{$\
n}{seq}=\"\";\n	$profile{$n}{Qseq}=$Qseq[$a];\n	$p\
rofile{$n}{Hseq}=$Hseq[$a];\n	$profile{$n}{Qstart}\
=$QstartL[$a];\n	$profile{$n}{Hstart}=$HstartL[$a]\
;\n	$profile{$n}{identity}=$identityL[$a];\n	$prof\
ile{$n}{definition}=$definitionL[$a];\n	$profile{$\
n}{identifyer}=$identifyerL[$a];\n	$profile{$n}{co\
mment}=$comment[$a];\n\n	for ($b=0; $b<$L; $b++)\n\
	  {\n	    if ($p[$a][$b])\n	      {\n		$profile{$\
n}{seq}.=$p[$a][$b];\n	      }\n	    else\n	      \
{\n		$profile{$n}{seq}.=\"-\";\n	      }\n	  }\n  \
    }\n\n    $profile{n}=$nhits+1;\n    return %pr\
ofile;\n  }\nsub ebi_blast_xml2profile\n  {\n    m\
y ($name,$seq,$maxid, $minid, $mincov, $string)=(@\
_);\n    my ($L,$l, $a,$b,$c,$d,$nhits,@identifyer\
L,$identifyer);\n\n\n\n    $seq=~s/[^a-zA-Z]//g;\n\
    $L=length ($seq);\n    %hit=&xml2tag_list ($st\
ring, \"hit\");\n\n    for ($nhits=0,$a=0; $a<$hit\
{n}; $a++)\n      {\n	my ($ldb,$id, $identity, $ex\
pectation, $start, $end, $coverage, $r);\n	my (%Q,\
%M,%E,%I);\n\n	$ldb=&tag2value ($hit{$a}{open}, \"\
database\");\n	$identifyer=&tag2value ($hit{$a}{op\
en}, \"id\");\n\n	$description=&tag2value ($hit{$a\
}{open}, \"description\");\n\n	%Q=&xml2tag_list ($\
hit{$a}{body}, \"querySeq\");\n	%M=&xml2tag_list (\
$hit{$a}{body}, \"matchSeq\");\n	%E=&xml2tag_list \
($hit{$a}{body}, \"expectation\");\n	%I=&xml2tag_l\
ist ($hit{$a}{body}, \"identity\");\n\n\n	for ($b=\
0; $b<$Q{n}; $b++)\n	  {\n\n	    $qs=$Q{$b}{body};\
\n	    $ms=$M{$b}{body};\n\n	    $expectation=$E{$\
b}{body};\n	    $identity=$I{$b}{body};\n\n\n	    \
$start=&tag2value ($Q{$b}{open}, \"start\");\n	   \
 $end=&tag2value ($Q{$b}{open}, \"end\");\n	    $s\
tartM=&tag2value ($M{$b}{open}, \"start\");\n	    \
$endM=&tag2value ($M{$b}{open}, \"end\");\n	    $c\
overage=(($end-$start)*100)/$L;\n\n	   # print \"$\
id: ID: $identity COV: $coverage [$start $end]\\n\\
";\n\n	    if ($identity>$maxid || $identity<$mini\
d || $coverage<$mincov){next;}\n	    # print \"KEE\
P\\n\";\n\n\n	    @lr1=(split (//,$qs));\n	    @lr\
2=(split (//,$ms));\n	    $l=$#lr1+1;\n	    for ($\
c=0;$c<$L;$c++){$p[$nhits][$c]=\"-\";}\n	    for (\
$d=0,$c=0; $c<$l; $c++)\n	      {\n		$r=$lr1[$c];\\
n		if ( $r=~/[A-Za-z]/)\n		  {\n\n		    $p[$nhits]\
[$d + $start-1]=$lr2[$c];\n		    $d++;\n		  }\n	  \
    }\n\n	    $Qseq[$nhits]=$qs;\n	    $Hseq[$nhit\
s]=$ms;\n	    $QstartL[$nhits]=$start;\n	    $Hsta\
rtL[$nhits]=$Hstart;\n	    $identityL[$nhits]=$ide\
ntity;\n	    $endL[$nhits]=$end;\n	    $definition\
L[$nhits]=$definition;\n	    $identifyerL[$nhits]=\
$identifyer;\n	    $comment[$nhits]=\"$ldb|$identi\
fyer [Eval=$expectation][id=$identity%][start=$sta\
rtM end=$endM]\";\n	    $nhits++;\n	  }\n      }\n\
\n    $profile{n}=0;\n    $profile{$profile{n}}{na\
me}=$name;\n    $profile{$profile{n}}{seq}=$seq;\n\
    $profile {n}++;\n\n    for ($a=0; $a<$nhits; $\
a++)\n      {\n	$n=$a+1;\n	$profile{$n}{name}=\"$n\
ame\\_$a\";\n	$profile{$n}{seq}=\"\";\n	$profile{$\
n}{Qseq}=$Qseq[$a];\n	$profile{$n}{Hseq}=$Hseq[$a]\
;\n	$profile{$n}{Qstart}=$QstartL[$a];\n	$profile{\
$n}{Hstart}=$HstartL[$a];\n	$profile{$n}{identity}\
=$identityL[$a];\n	$profile{$n}{definition}=$defin\
itionL[$a];\n	$profile{$n}{identifyer}=$identifyer\
L[$a];\n	$profile{$n}{comment}=$comment[$a];\n\n	f\
or ($b=0; $b<$L; $b++)\n	  {\n	    if ($p[$a][$b])\
\n	      {\n		$profile{$n}{seq}.=$p[$a][$b];\n	   \
   }\n	    else\n	      {\n		$profile{$n}{seq}.=\"\
-\";\n	      }\n	  }\n      }\n    $profile{n}=$nh\
its+1;\n\n    return %profile;\n  }\nsub output_pr\
ofile\n  {\n    my ($outfile,$profileR, $trim)=(@_\
);\n    my ($a);\n    my %profile=%$profileR;\n   \
 my $P= new FileHandle;\n    my $tmp=vtmpnam();\n\\
n    open ($P, \">$tmp\");\n    for ($a=0; $a<$pro\
file{n}; $a++)\n      {\n	print $P \">$profile{$a}\
{name} $profile{$a}{comment}\\n$profile{$a}{seq}\\\
n\";\n      }\n    close ($P);\n\n    if ( $trim)\\
n      {\n	&safe_system (\"t_coffee -other_pg seq_\
reformat -in $tmp -action +trim _aln_%%$trim\\_K1 \
-output fasta_aln -out $outfile\");\n      }\n    \
else\n      {\n	&safe_system (\"mv $tmp $outfile\"\
);\n      }\n    return;\n  }\nsub blast_xml2hit_l\
ist\n  {\n    my $string=(@_[0]);\n    return &xml\
2tag_list ($string, \"hit\");\n  }\nsub xmltag2val\
ue\n  {\n    my ($string_in, $tag)=@_;\n    my %TA\
G;\n    %TAG=xml2tag_list ($string_in, $tag);\n   \
 return $TAG{0}{body};\n  }\n\nsub xml2tag_list\n \
 {\n    my ($string_in,$tag)=@_;\n    my $tag_in, \
$tag_out;\n    my %tag;\n\n    if (-e $string_in)\\
n      {\n	$string=&file2string ($string_in);\n   \
   }\n    else\n      {\n	$string=$string_in;\n   \
   }\n    $tag_in1=\"<$tag \";\n    $tag_in2=\"<$t\
ag>\";\n    $tag_out=\"/$tag>\";\n    $string=~s/>\
/>##1/g;\n    $string=~s/</##2</g;\n    $string=~s\
/##1/<#/g;\n    $string=~s/##2/#>/g;\n    @l=($str\
ing=~/(\\<[^>]+\\>)/g);\n    $tag{n}=0;\n    $in=0\
;$n=-1;\n\n\n\n    foreach $t (@l)\n      {\n\n	$t\
=~s/<#//;\n	$t=~s/#>//;\n\n	if ( $t=~/$tag_in1/ ||\
 $t=~/$tag_in2/)\n	  {\n\n	    $in=1;\n	    $tag{$\
tag{n}}{open}=$t;\n	    $n++;\n\n	  }\n	elsif ($t=\
~/$tag_out/)\n	  {\n\n\n	    $tag{$tag{n}}{close}=\
$t;\n	    $tag{n}++;\n	    $in=0;\n	  }\n	elsif ($\
in)\n	  {\n\n	    $tag{$tag{n}}{body}.=$t;\n	  }\n\
      }\n\n    return %tag;\n  }\n\n\nsub seq2gor_\
prediction\n  {\n    my ($name, $seq,$infile, $out\
file, $gor_seq, $gor_obs)=(@_);\n    my ($l);\n\n \
   `gorIV -prd $infile -seq $gor_seq -obs $gor_obs\
 > gor_tmp`;\n    open (GR, \">$outfile\");\n    o\
pen (OG, \"gor_tmp\");\n\n    while (<OG>)\n      \
{\n\n	$l=$_;\n	if ($l=~/\\>/){print GR \"$l\";}\n	\
elsif ( $l=~/Predicted Sec. Struct./)\n	  {\n	    \
$l=~s/Predicted Sec. Struct\\.//;\n	    print GR \\
"$l\";\n	  }\n      }\n    close (GR);\n    close \
(OG);\n    return;\n  }\nsub seq2msa_tm_prediction\
\n  {\n    my ($name, $seq, $db, $infile, $outfile\
, $arch, $psv)=(@_);\n    my (%p,%gseq,%R, $blast_\
output, %s, $l);\n    my $R2=new FileHandle;\n    \
my $db=\"uniprot\";\n    my $method=\"psitm\";\n  \
  my $SERVER=\"EBI\";\n\n    $blast_output=&run_bl\
ast ($name,\"blastp\", $db, $infile, \"outfile\");\
\n\n    if (&cache_file(\"GET\",$infile,$name,$met\
hod,$db,$outfile,$SERVER))\n      {\n	print \"\\tP\
SITM: USE Cache\\n\";\n	return $outfile;\n      }\\
n    else\n      {\n	$CACHE_STATUS=\"COMPUTE CACHE\
\";\n	%p=blast_xml2profile($name,$seq,$maxid, $min\
id,$mincov,$blast_output);\n\n\n	open (F, \">tm_in\
put\");\n	for (my $a=0; $a<$p{n}; $a++)\n	  {\n	  \
  my $s;\n\n	    $s=$p{$a}{seq};\n	    $s=uc($s);\\
n	    print F \">$p{$a}{name}\\n$s\\n\";\n	    #pr\
int stdout \">$p{$a}{name}\\n$s\\n\";\n	  }\n	clos\
e (F);\n	print \"\\tPSITM: kept  $p{n} Homologues \
for Sequence $p{0}{name}\\n\";\n	&safe_system (\"t\
_coffee -other_pg fasta_seq2hmmtop_fasta.pl -in=tm\
_input -out=$outfile -output=cons -cov=70 -trim=95\
 -arch=$arch -psv=$psv\");\n	unlink (\"tm_input\")\
;\n	&cache_file(\"SET\",$infile,$name,$method,$db,\
$outfile,$SERVER);\n	return;\n      }\n  }\n\n\nsu\
b seq2msa_gor_prediction\n  {\n    my ($name, $seq\
,$infile, $outfile, $gor_seq, $gor_obs)=(@_);\n   \
 my (%p,%gseq,%R, $blast_output, %s, $l);\n    my \
$R2=new FileHandle;\n    my $db=\"uniprot\";\n    \
my $method=\"psigor\";\n    my $SERVER=\"EBI\";\n\\
n    $blast_output=&run_blast ($name,\"blastp\", \\
"uniprot\", $infile, \"outfile\");\n\n    if (&cac\
he_file(\"GET\",$infile,$name,$method,$db,$outfile\
,$SERVER))\n      {\n	print \"\\tPSIGOR: USE Cache\
\\n\";\n	return $outfile;\n      }\n    else\n    \
  {\n	$CACHE_STATUS=\"COMPUTE CACHE\";\n	%p=blast_\
xml2profile($name,$seq,$maxid, $minid,$mincov,$bla\
st_output);\n\n\n	open (F, \">gor_input\");\n	for \
(my $a=0; $a<$p{n}; $a++)\n	  {\n	    my $s;\n\n	 \
   $s=$p{$a}{seq};\n	    $s=uc($s);\n	    print F \
\">$p{$a}{name}\\n$s\\n\";\n	    #print stdout \">\
$p{$a}{name}\\n$s\\n\";\n	  }\n	close (F);\n	print\
 \"\\tGORTM: kept  $p{n} Homologues for Sequence $\
p{0}{name}\\n\";\n	&safe_system (\"t_coffee -other\
_pg fasta_seq2hmmtop_fasta.pl -in=gor_input -out=$\
outfile -output=cons -cov=70 -trim=95 -gor_seq=$go\
r_seq -gor_obs=$gor_obs -mode=gor\");\n	unlink (\"\
tm_input\");\n	&cache_file(\"SET\",$infile,$name,$\
method,$db,$outfile,$SERVER);\n	return;\n      }\n\
  }\n\n\n\nsub run_blast\n  {\n    my ($name, $met\
hod, $db, $infile, $outfile, $run)=(@_);\n    if (\
!$run){$run=1;}\n    my $error_log=vtmpnam();\n\n \
   if (&cache_file(\"GET\",$infile,$name,$method,$\
db,$outfile,$SERVER) && is_valid_blast_xml ($outfi\
le))\n      {return $outfile;}\n    else\n      {\\
n	$CACHE_STATUS=\"COMPUTE CACHE\";\n	if ( $SERVER \
eq \"EBI_SOAP\")\n	  {\n	    &check_configuration \
(\"EMAIL\",\"SOAP::Light\",\"INTERNET\");\n\n	    \
$cl_method=$method;\n	    if ($cl_method =~/wu/)\n\
	      {\n		$cl_method=~s/wu//;\n		if ( $cl_method\
 eq \"psiblast\")\n		  {\n		    add_warning($$,$$,\
\"PSI BLAST cannot be used with the wuBLAST Client\
. Use server=EBI Or server=LOCAL. blastp will be u\
sed instead\");\n		    $cl_method=\"blastp\";\n		 \
 }\n\n		$command=\"t_coffee -other_pg wublast.pl -\
-email $EMAIL $infile -D $db -p $cl_method --outfi\
le $outfile -o xml>/dev/null 2>$error_log\";\n		&s\
afe_system ( $command);\n		if (-e \"$outfile.xml\"\
) {`mv $outfile.xml $outfile`;}\n	      }\n	    el\
se\n	      {\n		if ($cl_method eq \"psiblast\"){$c\
l_method =\"blastp -j5\";}\n\n		$command=\"t_coffe\
e -other_pg blastpgp.pl --email $EMAIL $infile -d \
$db --outfile $outfile -p $cl_method --mode PSI-Bl\
ast>/dev/null 2>$error_log\";\n		&safe_system ( $c\
ommand);\n\n		if (-e \"$outfile.xml\") {`mv $outfi\
le.xml $outfile`;}\n	      }\n	  }\n	elsif ($SERVE\
R eq \"EBI_REST\" || $SERVER eq \"EBI\")\n	  {\n	 \
   $cl_method=$method;\n	    &check_configuration(\
\"EMAIL\",\"XML::Simple\", \"INTERNET\");\n	    if\
 ($db eq \"uniprot\"){$db1=\"uniprotkb\";}\n	    e\
lse {$db1=$db;}\n\n	   \n	    if ($cl_method =~/wu\
/)\n	      {\n		$cl_method=~s/wu//;\n		if ( $cl_me\
thod eq \"psiblast\"){$cl_method=\"blastp\";}\n\n	\
	$command=\"t_coffee -other_pg wublast_lwp.pl --em\
ail $EMAIL -D $db1 -p $cl_method --outfile $outfil\
e --align 5 --stype protein $infile>/dev/null 2>er\
ror_log\";\n	      }\n	    else\n	      {\n		if ( \
$cl_method =~/psiblast/){$cl_method =\"blastp -j5\\
";}\n		$command=\"t_coffee -other_pg ncbiblast_lwp\
.pl --email $EMAIL -D $db1 -p $cl_method --outfile\
 $outfile --align 5 --stype protein $infile>/dev/n\
ull 2>$error_log\";\n	      }\n	    &safe_system (\
 $command,5);\n	    if (-e \"$outfile.out.xml\") {\
`mv $outfile.out.xml $outfile`;}\n	    elsif (-e \\
"$outfile.xml.xml\"){`mv $outfile.xml.xml $outfile\
`;}\n	    elsif (-e \"$outfile.out..xml\") {`mv $o\
utfile.out..xml $outfile`;}\n	    elsif (-e \"$out\
file.xml..xml\"){`mv $outfile.xml..xml $outfile`;}\
\n	  }\n	elsif ($SERVER eq \"NCBI\")\n	  {\n	    &\
check_configuration (\"INTERNET\");\n	    if ($db \
eq \"uniprot\"){$cl_db=\"swissprot\";}\n	    else \
{$cl_db=$db;}\n\n	    if ( $method eq \"psiblast\"\
)\n	      {\n		add_warning($$,$$,\"PSI BLAST canno\
t be used with the NCBI BLAST Client. Use server=E\
BI Or server=LOCAL. blastp will be used instead\")\
;\n		$cl_method=\"blastp\";\n	      }\n	    else\n\
	      {\n		$cl_method=$method;\n	      }\n	      \
\n	    &check_configuration ($cl_method);  \n	    \
$command=\"$cl_method -db $cl_db -query $infile -o\
ut $outfile -outfmt 5 -remote\";\n	    &safe_syste\
m ($command);\n	  }\n	elsif ($SERVER =~/CLIENT_(.*\
)/)\n	  {\n	    my $client=$1;\n	    $command=\"$c\
lient -p $method -d $db -i $infile -o $outfile -m \
7\";\n	    &safe_system ($command);\n	  }\n	elsif \
( $SERVER eq \"LOCAL_blastall\")\n	  {\n	    &chec\
k_configuration (\"blastall\");\n	    if ($method \
eq \"blastp\")\n	      {\n		$command=\"blastall -d\
 $db -i $infile -o $outfile -m7 -p blastp\";\n	   \
   }\n	    &safe_system ($command);\n	  }\n	elsif \
( $SERVER eq \"LOCAL\")\n	  {\n\n	    if ($ENV{\"B\
LAST_DB_DIR\"})\n	      {\n		$x=$ENV{\"BLAST_DB_DI\
R\"};\n		$cl_db=\"$x$db\";\n	      }\n	    else\n	\
      {\n		$cl_db=$db;\n	      }\n\n        ##\n		\
## BLAST+ provide different binaries names and CLI\
 options\n		## Use the 'legacy_blast.pl' to keep c\
ompatibility with old blast commands\n		##\n		$pat\
h=`which legacy_blast.pl 2>/dev/null`;  \n		$path=\
`dirname $path`; \n		chomp($path);\n	    if ($meth\
od eq \"blastp\")\n	      {\n		&check_configuratio\
n(\"legacy_blast.pl\");\n		$command=\"legacy_blast\
.pl blastpgp --path $path -d $cl_db -i $infile -o \
$outfile -m7 -j1\";\n	      }\n	    elsif ($method\
 eq \"psiblast\")\n	      {\n		&check_configuratio\
n(\"legacy_blast.pl\");\n		$command=\"legacy_blast\
.pl blastpgp --path $path -d $cl_db -i $infile -o \
$outfile -m7 -j5\";\n	      }\n	    elsif ($method\
 eq \"blastn\")\n	      {\n		&check_configuration(\
\"legacy_blast.pl\");\n		$command=\"legacy_blast.p\
l blastall --path $path -p blastn -d $cl_db -i $in\
file -o $outfile -m7 -W6\";\n	      }\n	    &safe_\
system ($command);\n	  }\n	else\n	  {\n\n	    myex\
it(add_error (EXIT_FAILURE,$$,$$,getppid(), \"BLAS\
T_FAILURE::UnknownServer\",$CL));\n	  }\n\n\n	#Che\
ck that everything went well\n\n	if ( !-e $outfile\
 || !&is_valid_blast_xml($outfile))\n	  {\n\n	    \
if ( -e $outfile)\n	      {\n		add_warning ($$,$$,\
\"Corrupted Blast Output (Run $run)\");\n		unlink(\
$outfile);\n	      }\n	    if ( -e $error_log)\n	 \
     {\n\n		my $error_msg=file2string ($error_log)\
;\n\n		if ( $error_msg =~/enter a valid email/)\n	\
	  {\n		    myexit(add_error (EXIT_FAILURE,$$,$$,g\
etppid(), \"BLAST_FAILURE::Invalid_or_rejected_ema\
il::$EMAIL\", \"$command\"));\n		  }\n	      }\n	 \
   if ( $run==$BLAST_MAX_NRUNS)\n	      {\n\n		mye\
xit(add_error (EXIT_FAILURE,$$,$$,getppid(), \"BLA\
ST_FAILURE::UnknownReason\", \"$command\"));\n	   \
   }\n	    else\n	      {\n		my $out;\n		if ($SERV\
ER eq \"NCBI\") {$SERVER=\"EBI\"; }\n		elsif ($SER\
VER eq \"EBI\"){$SERVER=\"NCBI\";}\n		add_warning \
($$,$$,\"Blast for $name failed (Run: $run out of \
$BLAST_MAX_NRUNS. Use $SERVER)\");\n		$out=&run_bl\
ast ($name, $method, $db,$infile, $outfile, $run+1\
);\n		if ($SERVER eq \"NCBI\") {$SERVER=\"EBI\"; }\
\n		elsif ($SERVER eq \"EBI\"){$SERVER=\"NCBI\";}\\
n		return $out;\n	      }\n	  }\n\n	&cache_file(\"\
SET\",$infile,$name,$method,$db,$outfile,$SERVER);\
\n	#system (\"cp $outfile ~/Dropbox/tmp/cedric.out\
\");\n	#die;\n	return $outfile;\n      }\n  }\n\ns\
ub cache_file\n  {\n    my ($cache_mode,$infile,$n\
ame,$method,$db, $outfile,$server)=(@_);\n    my $\
cache_file;\n    #Protect names so that they can b\
e turned into legal filenames\n    $name=&clean_fi\
le_name ($name);\n\n    if ($db=~/\\//)\n      {\n\
	$db=~/([^\\/]+)$/;\n	$db=$1;\n      }\n    $cache\
_file_sh=\"$name.$method.$db.$server.tmp\";\n    $\
cache_file=\"$CACHE/$name.$method.$db.$server.tmp\\
";\n\n    if ($infile ne \"\")\n      {\n	$cache_f\
ile_infile_sh=\"$name.$method.$db.$server.infile.t\
mp\";\n	$cache_file_infile=\"$CACHE/$name.$method.\
$db.$server.infile.tmp\";\n      }\n\n    if ($cac\
he_mode eq \"GET\")\n      {\n	if ($CACHE eq \"\" \
|| $CACHE eq \"no\" || $CACHE eq \"ignore\"  || $C\
ACHE eq \"local\" || $CACHE eq \"update\"){return \
0;}\n	elsif ( !-d $CACHE)\n	  {\n	    print STDERR\
 \"ERROR: Cache Dir: $CACHE Does not Exist\";\n	  \
  return 0;\n	  }\n	else\n	  {\n	    if ( -e $cach\
e_file && &fasta_file1_eq_fasta_file2($infile,$cac\
he_file_infile)==1)\n	      {\n		`cp $cache_file $\
outfile`;\n		$CACHE_STATUS=\"READ CACHE\";\n		retu\
rn 1;\n	      }\n	  }\n      }\n    elsif ($cache_\
mode eq \"SET\")\n      {\n	if ($CACHE eq \"\" || \
$CACHE eq \"no\" || $CACHE eq \"ignore\"  || $CACH\
E eq \"local\" || $CACHE eq \"update\"){return 0;}\
\n	elsif ( !-d $CACHE)\n	  {\n	    print STDERR \"\
ERROR: Cache Dir: $CACHE Does not Exist\";\n	    r\
eturn 0;\n	  }\n	elsif (-e $outfile)\n	  {\n	    `\
cp $outfile $cache_file`;\n	    if ($cache_file_in\
file ne \"\"){ `cp $infile $cache_file_infile`;}\n\
\n	    #functions for updating the cache\n	    #`t\
_coffee -other_pg clean_cache.pl -file $cache_file\
_sh -dir $CACHE`;\n	    #`t_coffee -other_pg clean\
_cache.pl -file $cache_file_infile_sh -dir $CACHE`\
;\n	    return 1;\n	  }\n      }\n    $CACHE_STATU\
S=\"COMPUTE CACHE\";\n    return 0;\n  }\nsub file\
1_eq_file2\n  {\n    my ($f1, $f2)=@_;\n    if ( $\
f1 eq \"\"){return 1;}\n    elsif ( $f2 eq \"\"){r\
eturn 1;}\n    elsif ( !-e $f1){return 0;}\n    el\
sif ( !-e $f2){return 0;}\n    elsif ($f1 eq \"\" \
|| $f2 eq \"\" || `diff $f1 $f2` eq \"\"){return 1\
;}\n\n    return 0;\n  }\nsub clean_file_name\n  {\
\n    my $name=@_[0];\n\n    $name=~s/[^A-Za-z1-9.\
-]/_/g;\n    return $name;\n  }\nsub url2file\n  {\
\n    my ($address, $out)=(@_);\n\n    if (&pg_is_\
installed (\"wget\"))\n	{\n	  return &safe_system \
(\"wget $address -O$out >/dev/null 2>/dev/null\");\
\n	}\n    elsif (&pg_is_installed (\"curl\"))\n   \
   {\n	return &safe_system (\"curl $address -o$out\
 >/dev/null 2>/dev/null\");\n      }\n    else\n  \
    {\n	myexit(flus_error(\"neither curl nor wget \
are installed. Imnpossible to fectch remote file\"\
));\n	exit ($EXIT_FAILURE);\n      }\n  }\nsub fas\
ta_file1_eq_fasta_file2\n  {\n    my ($f1, $f2)=@_\
;\n    my (%s1, %s2);\n    my @names;\n    %s1=rea\
d_fasta_seq ($f1);\n    %s2=read_fasta_seq ($f2);\\
n\n    @names=(keys (%s1));\n\n    foreach $n (key\
s(%s1))\n      {\n	if ($s1{$n}{seq} ne $s2{$n}{seq\
}){return 0;}\n      }\n\n    foreach $n (keys(%s2\
))\n      {\n	if ($s1{$n}{seq} ne $s2{$n}{seq}){re\
turn 0;}\n      }\n    return 1;\n  }\n\n\n\nsub r\
ead_template_file\n  {\n    my $pdb_templates = @_\
[0];\n    my $tmp=new FileHandle;\n    open ($tmp,\
 \"<$pdb_templates\");\n    my %temp_h;\n    my ($\
skip,$seq, $temp);\n\n    #supports both a simple \
[seq pdb] format and the regular fasta like templa\
te format\n    while (<$tmp>)\n      {\n	\n	$line \
= $_;\n	if ($line=~/\\>(\\S+)\\s_._\\s(\\S+)/){$te\
mp_h{$1}= $2;}\n	elsif ($line =~/(\\S+)\\s(\\S+)/)\
{$temp_h{$1}= $2;}\n      }\n    close($tmp);\n   \
 return %temp_h;\n  }\n\n\n\n\n\n\nsub seq2tblastx\
_lib\n  {\n    my ($mode, $infile, $outfile)=@_;\n\
    my (%s, $method,$nseq);\n\n    $method=$mode;\\
n    &set_temporary_dir (\"set\",$infile,\"infile\\
");\n    %s=read_fasta_seq(\"infile\");\n\n\n    f\
oreach $seq (keys(%s))\n      {\n	$slist[$s{$seq}{\
order}]=$s{$seq}{seq};\n	$sname[$s{$seq}{order}]=$\
s{$seq}{name};\n	$slen[$s{$seq}{order}]=length ($s\
{$seq}{seq});\n      }\n    $nseq=$#sname+1;\n    \
open (F, \">outfile\");\n    print F \"! TC_LIB_FO\
RMAT_01\\n\";\n    print F \"$nseq\\n\";\n    for \
($a=0; $a<$nseq;$a++)\n      {\n	print F \"$sname[\
$a] $slen[$a]  $slist[$a]\\n\"\n      }\n    close\
 (F);\n    &safe_system (\"formatdb -i infile -p F\
\");\n    &safe_system (\"blastall -p tblastx -i i\
nfile -d infile -m 7 -S1>blast.output\");\n\n    n\
cbi_tblastx_xml2lib_file (\"outfile\", file2string\
 (\"blast.output\"));\n    &set_temporary_dir (\"u\
nset\",$mode, $method, \"outfile\",$outfile);\n   \
 myexit ($EXIT_SUCCESS);\n    }\nsub seq2tblastpx_\
lib\n  {\n    my ($mode, $infile, $outfile)=@_;\n \
   my (%s, $method,$nseq);\n    $method=$mode;\n  \
  &set_temporary_dir (\"set\",$infile,\"infile\");\
\n    %s=read_fasta_seq(\"infile\");\n\n    foreac\
h $seq (keys(%s))\n      {\n	$slist[$s{$seq}{order\
}]=$s{$seq}{seq};\n	$sname[$s{$seq}{order}]=$s{$se\
q}{name};\n	$slen[$s{$seq}{order}]=length ($s{$seq\
}{seq});\n      }\n    $nseq=$#sname+1;\n    open \
(F, \">outfile\");\n    print F \"! TC_LIB_FORMAT_\
01\\n\";\n    print F \"$nseq\\n\";\n    for ($a=0\
; $a<$nseq;$a++)\n      {\n	print F \"$sname[$a] $\
slen[$a]  $slist[$a]\\n\"\n      }\n    close (F);\
\n    &safe_system(\"t_coffee -other_pg seq_reform\
at -in infile -output tblastx_db1 > tblastxdb\");\\
n    &safe_system (\"formatdb -i tblastxdb -p T\")\
;\n    &safe_system (\"blastall -p blastp -i tblas\
txdb -d tblastxdb -m7 >blast.output\");\n    ncbi_\
tblastpx_xml2lib_file (\"outfile\", file2string (\\
"blast.output\"), %s);\n    &set_temporary_dir (\"\
unset\",$mode, $method, \"outfile\",$outfile);\n  \
  myexit ($EXIT_SUCCESS);\n    }\n\nsub x3dna_find\
_pair2lib\n      {\n      my ($seq, $pdb, $lib, $p\
g)=@_;\n      my $outfile1=\"dssr-2ndstrs.dbn\";\n\
      my $outfile2=\"simple.output\";\n      my $f\
= new FileHandle;\n      my ($rnaSS,$pdbSS);\n    \
  my $command;\n      my %s_pdb;\n      my %s_seq;\
\n      \n      #$pg: \"find_pair\" OR \"find_pair\
 -p\"\n      \n      if (!pg_is_installed (\"find_\
pair\"))\n	{\n	  add_warning ($$,$$, \"x3dna/find_\
pairs could not be used to extract RNA secondary s\
tructures. Secondary structures will be extracted \
by x3dna-ssr instead\");\n	  return x3dnassr2lib (\
$seq, $pdb, $lib);\n	}\n      \n      #get PDB seq\
uence\n      safe_system (\"t_coffee -other_pg ext\
ract_from_pdb $pdb -seq >$outfile1\");\n      \n  \
    #get find_pair contacts\n      $command=\"$pg \
$pdb simple.output > /dev/null 2>/dev/null\";\n   \
   safe_system ($command);\n\n      if (($command=\
~/find_pair -p/)){$outfile2=\"allpairs.ana\";}\n  \
    else {$outfile2=\"simple.output\";}\n      \n \
     if ( !-e $outfile2)\n	{\n	  myexit(flush_erro\
r(\"x3dna failed to compute the secondary structur\
e file $outfile2 for $pdb\"));\n	  myexit ($EXIT_F\
AILURE);\n	}\n      \n\n      #Handle situations w\
hen the pdb sequence differs from the RNA sequence\
\n      #my @out=file2array($outfile1);\n      %s_\
pdb=read_fasta_seq_index ($outfile1);\n      %s_se\
q=read_fasta_seq_index ($seq);\n      my $rnaS=uc(\
$s_seq{0}{seq});\n      my $pdbS=uc($s_pdb{0}{seq}\
);\n      \n      my $vienna;\n      my @lu;\n    \
\n      if ($rnaS ne $pdbS)\n	{\n	  \n	  my ($rna,\
$pdb);\n	  $rnaSS=$rnaS;\n	  $pdbSS=$pdbS;\n	  $rn\
aSS=~s/T/U/g;\n	  $pdbSS=~s/T/U/g;\n	  ($rnaSS,$pd\
bSS)=nw ($rnaS, $pdbS);\n	  \n	  my @rnaA =split (\
//,$rnaSS);\n	  my @pdbA=split (//,$pdbSS);\n	  my\
 $l=@rnaA;\n	  \n	  #print \"\\n--- $s_seq{0}{name\
} $rnaSS\\n--- $s_seq{0}{name} $pdbSS\\n\\n\";\n	 \
 \n	  for (my $b=0,my $a=0; $a<$l; $a++)\n	    {\n\
	      if   ($rnaA[$a] ne '-' && $pdbA[$a] ne '-')\
{$lu[++$pdb]=++$rna;}\n	      elsif($rnaA[$a] eq '\
-'){$lu[++$pdb]=-1;}\n	      elsif($pdbA[$a] eq '-\
'){++$rna;}\n	    }\n	}\n      else\n	{\n	  for (m\
y $a=0; $a<=length ($rnaS); $a++)\n	    {\n	      \
$lu[$a]=$a;\n	    }\n	}\n      my $l=length ($rnaS\
);\n      open ($f, \">$lib\");\n      print $f \"\
! TC_LIB_FORMAT_01\\n\";\n      print $f \"1\\n\";\
\n      print $f \"$s_seq{0}{name} $l $rnaS\\n\";\\
n      print $f \"!CMT: [SOURCE] >$s_seq{0}{name} \
3D contact library Generated by $pg (x3dna)\\n\";\\
n      print $f \"#1 1\\n\";\n      \n      my $ne\
;\n      my @array=file2array($outfile2);\n      f\
or (my $a=0; $a<5; $a++){shift (@array);}\n      w\
hile (!($array[0]=~/####/))\n	{\n	  my $line= shif\
t (@array);\n	  my @l=($line=~/(\\d+)/g);\n	  \n	 \
\n	  my $f1=$lu[$l[0]];\n	  my $s1=$lu[$l[1]];\n\n\
	  #print \"\\n$line\\n$l[0] --> $f1\\n$l[1] --> $\
s1\\n\\n\"; \n	  \n	  if (!$f1 || !$s1)\n	    {\n	\
      print \"\\n---- $rnaSS\\n---- $pdbSS\\n$line\
\\n[$l[0] --- $l[1]]<---->[$f1 --- $s1]\\n\";\n	  \
    myexit(flush_error(\"Error while parsing s3dna\
::find_pair output\"));\n	    }\n	  elsif ($f1==-1\
 || $s1==-1){;}\n	  elsif ($f1<$s1){print $f \"$f1\
 $s1 100\\n\";}\n	  else {print $f \"$s1 $f1 100\\\
n\";$ne++;}\n	}\n      print $f \"! SEQ_1_TO_N\\n\\
";\n      close ($f);\n      return;\n    }\nsub R\
NAplfold2lib\n  {\n    my ($seq, $lib)=@_;\n    my\
 $f= new FileHandle;\n    \n    &safe_system (\"t_\
coffee -other_pg RNAplfold2tclib.pl -in=$seq -out=\
$lib\");\n    \n    if ( !-e $lib)\n	{\n	 myexit(f\
lush_error(\"RNAplfold failed to compute the secon\
dary structure of $s{$seq}{name}\"));\n	 myexit ($\
EXIT_FAILURE);\n       }\n    open ($f, \">>$lib\"\
);\n    print $f \"!CMT: [SOURCE] 2D contact libra\
ry Generated by RNAPlfold (Vienna Package)\\n\";\n\
    close $f;\n    return;\n  }\nsub x3dnassr2lib\\
n    {\n      my ($seq, $pdb, $lib)=@_;\n      my \
$outfile=\"dssr-2ndstrs.dbn\";\n      my $f= new F\
ileHandle;\n      \n\n      if (!pg_is_installed (\
\"x3dna-ssr\"))\n	{\n	  add_warning ($$,$$, \"x3dn\
a-ssr could not be used to extract RNA secondary s\
tructures. Secondary structures will be predicted \
ab-initio instead with RNAPlfold\");\n	  return RN\
Aplfold2lib ($seq,$lib);\n	}\n      \n      safe_s\
ystem (\"x3dna-ssr -i=$pdb >/dev/null 2>/dev/null\\
");\n      if ( !-e $outfile)\n	{\n	  myexit(flush\
_error(\"x3dna-ssr failed to compute the secondary\
 structure file \"));\n	  myexit ($EXIT_FAILURE);\\
n	}\n\n      #Handle situations when the pdb seque\
nce differs from the RNA sequence\n      @out=file\
2array($outfile);\n      my %s=read_fasta_seq ($se\
q);\n      my @names=keys (%s);\n      my $rnaS=uc\
($s{$names[0]}{seq});\n      my $pdbS=uc($out[1]);\
\n      my $vienna;\n      \n      #x3dna returns \
non legitimate nucleotides\n       $pdbS=~s/[^AGCT\
U]//g;\n      \n      if ($rnaS ne $pdbS)\n	{\n	  \
my ($rna,$pdb);\n	  my $rnaSS=$rnaS;\n	  my $pdbSS\
=$pdbS;\n	  $rnaSS=~s/T/U/g;\n	  $pdbSS=~s/T/U/g;\\
n	  ($rnaSS,$pdbSS)=nw ($rnaSS, $pdbSS);\n	  my @r\
naA =split (//,$rnaSS);\n	  my @pdbA=split (//,$pd\
bSS);\n	  my @SS=split (//, $out[2]);\n	  \n	  my \
$l=@rnaA;\n	  for (my $b=0,my $a=0; $a<$l; $a++)\n\
	    {\n	      if   ($rnaA[$a] ne '-' && $pdbA[$a]\
 ne '-'){$vienna.=$SS[$b++];}\n	      elsif($rnaA[\
$a] eq '-'){$b++;}\n	      elsif($pdbA[$a] eq '-')\
{$vienna.='.';}\n	    }\n	}\n      else\n	{\n	  $v\
ienna=$out[2];\n	}\n    \n\n      open ($f, \">seq\
\");\n      print $f \">$names[0]\\n$rnaS\\n\";\n \
     close $f;\n      \n      open ($f, \">str\");\
\n      print $f \">$names[0]\\n$vienna\\n\";\n   \
   close $f;\n      \n      safe_system (\"t_coffe\
e -other_pg seq_reformat -in seq -in2 str -output \
vienna2tc_lib >$lib\");\n      if ( !-e $lib)\n	  \
  {\n	      myexit(flush_error(\"seq_reformat fail\
ed to convert your secondary structure\"));\n	    \
  myexit ($EXIT_FAILURE);\n	    }\n      \n      o\
pen ($f, \">>$lib\");\n      print $f \"!CMT: [SOU\
RCE] >$names[0] 2D Contact library generated by x3\
dna-ssr\\n\";\n      #print $f \"! Vienna_Format: \
>$names[0]\\n\";\n      #print $f \"! Vienna_Forma\
t: $vienna\\n\";\n      \n      close $f;\n      r\
eturn;\n    }\n\n\nsub file2head\n      {\n	my $fi\
le = shift;\n	my $size = shift;\n	my $f= new FileH\
andle;\n	my $line;\n	open ($f,$file);\n	read ($f,$\
line, $size);\n	close ($f);\n	return $line;\n     \
 }\nsub file2tail\n      {\n	my $file = shift;\n	m\
y $size = shift;\n	my $f= new FileHandle;\n	my $li\
ne;\n\n	open ($f,$file);\n	seek ($f,$size*-1, 2);\\
n	read ($f,$line, $size);\n	close ($f);\n	return $\
line;\n      }\n\n\nsub vtmpnam\n      {\n	my $r=r\
and(100000);\n	my $f=\"file.$r.$$\";\n	while (-e $\
f)\n	  {\n	    $f=vtmpnam();\n	  }\n	push (@TMPFIL\
E_LIST, $f);\n	return $f;\n      }\n\nsub myexit\n\
  {\n    my $code=@_[0];\n    if ($CLEAN_EXIT_STAR\
TED==1){return;}\n    else {$CLEAN_EXIT_STARTED=1;\
}\n    ### ONLY BARE EXIT\n    exit ($code);\n  }\\
nsub set_error_lock\n    {\n      my $name = shift\
;\n      my $pid=$$;\n\n\n      &lock4tc ($$,\"LER\
ROR\", \"LSET\", \"$$ -- ERROR: $name $PROGRAM\\n\\
");\n      return;\n    }\nsub set_lock\n  {\n    \
my $pid=shift;\n    my $msg= shift;\n    my $p=get\
ppid();\n    &lock4tc ($pid,\"LLOCK\",\"LRESET\",\\
"$p$msg\\n\");\n  }\nsub unset_lock\n   {\n\n    m\
y $pid=shift;\n    &lock4tc ($pid,\"LLOCK\",\"LREL\
EASE\",\"\");\n  }\nsub shift_lock\n  {\n    my $f\
rom=shift;\n    my $to=shift;\n    my $from_type=s\
hift;\n    my $to_type=shift;\n    my $action=shif\
t;\n    my $msg;\n\n    if (!&lock4tc($from, $from\
_type, \"LCHECK\", \"\")){return 0;}\n    $msg=&lo\
ck4tc ($from, $from_type, \"LREAD\", \"\");\n    &\
lock4tc ($from, $from_type,\"LRELEASE\", $msg);\n \
   &lock4tc ($to, $to_type, $action, $msg);\n    r\
eturn;\n  }\nsub isshellpid\n  {\n    my $p=shift;\
\n    if (!lock4tc ($p, \"LLOCK\", \"LCHECK\")){re\
turn 0;}\n    else\n      {\n	my $c=lock4tc($p, \"\
LLOCK\", \"LREAD\");\n	if ( $c=~/-SHELL-/){return \
1;}\n      }\n    return 0;\n  }\nsub isrootpid\n \
 {\n    if(lock4tc (getppid(), \"LLOCK\", \"LCHECK\
\")){return 0;}\n    else {return 1;}\n  }\nsub lo\
ck4tc\n	{\n	  my ($pid,$type,$action,$value)=@_;\n\
	  my $fname;\n	  my $host=hostname;\n\n	  if ($ty\
pe eq \"LLOCK\"){$fname=\"$LOCKDIR/.$pid.$host.loc\
k4tcoffee\";}\n	  elsif ( $type eq \"LERROR\"){ $f\
name=\"$LOCKDIR/.$pid.$host.error4tcoffee\";}\n	  \
elsif ( $type eq \"LWARNING\"){ $fname=\"$LOCKDIR/\
.$pid.$host.warning4tcoffee\";}\n\n	  if ($debug_l\
ock)\n	    {\n	      print STDERR \"\\n\\t---lock4\
tc(tcg): $action => $fname =>$value (RD: $LOCKDIR)\
\\n\";\n	    }\n\n	  if    ($action eq \"LCHECK\")\
 {return -e $fname;}\n	  elsif ($action eq \"LREAD\
\"){return file2string($fname);}\n	  elsif ($actio\
n eq \"LSET\") {return string2file ($value, $fname\
, \">>\");}\n	  elsif ($action eq \"LRESET\") {ret\
urn string2file ($value, $fname, \">\");}\n	  elsi\
f ($action eq \"LRELEASE\")\n	    {\n	      if ( $\
debug_lock)\n		{\n		  my $g=new FileHandle;\n		  o\
pen ($g, \">>$fname\");\n		  print $g \"\\nDestroy\
ed by $$\\n\";\n		  close ($g);\n		  safe_system (\
\"mv $fname $fname.old\");\n		}\n	      else\n		{\\
n		  unlink ($fname);\n		}\n	    }\n	  return \"\"\
;\n	}\n\nsub file2string\n	{\n	  my $file=@_[0];\n\
	  my $f=new FileHandle;\n	  my $r;\n	  open ($f, \
\"$file\");\n	  while (<$f>){$r.=$_;}\n	  close ($\
f);\n	  return $r;\n	}\nsub file2array\n	{\n	  my \
$file=@_[0];\n	  my $f=new FileHandle;\n	  my @r;\\
n	  open ($f, \"$file\");\n	  while (<$f>){@r=(@r,\
$_);}\n	  close ($f);\n	  return @r;\n	}\nsub stri\
ng2file\n    {\n    my ($s,$file,$mode)=@_;\n    m\
y $f=new FileHandle;\n\n    open ($f, \"$mode$file\
\");\n    print $f  \"$s\";\n    close ($f);\n  }\\
n\nBEGIN\n    {\n      srand;\n\n      $SIG{'SIGUP\
'}='signal_cleanup';\n      $SIG{'SIGINT'}='signal\
_cleanup';\n      $SIG{'SIGQUIT'}='signal_cleanup'\
;\n      $SIG{'SIGILL'}='signal_cleanup';\n      $\
SIG{'SIGTRAP'}='signal_cleanup';\n      $SIG{'SIGA\
BRT'}='signal_cleanup';\n      $SIG{'SIGEMT'}='sig\
nal_cleanup';\n      $SIG{'SIGFPE'}='signal_cleanu\
p';\n\n      $SIG{'SIGKILL'}='signal_cleanup';\n  \
    $SIG{'SIGPIPE'}='signal_cleanup';\n      $SIG{\
'SIGSTOP'}='signal_cleanup';\n      $SIG{'SIGTTIN'\
}='signal_cleanup';\n      $SIG{'SIGXFSZ'}='signal\
_cleanup';\n      $SIG{'SIGINFO'}='signal_cleanup'\
;\n\n      $SIG{'SIGBUS'}='signal_cleanup';\n     \
 $SIG{'SIGALRM'}='signal_cleanup';\n      $SIG{'SI\
GTSTP'}='signal_cleanup';\n      $SIG{'SIGTTOU'}='\
signal_cleanup';\n      $SIG{'SIGVTALRM'}='signal_\
cleanup';\n      $SIG{'SIGUSR1'}='signal_cleanup';\
\n\n\n      $SIG{'SIGSEGV'}='signal_cleanup';\n   \
   $SIG{'SIGTERM'}='signal_cleanup';\n      $SIG{'\
SIGCONT'}='signal_cleanup';\n      $SIG{'SIGIO'}='\
signal_cleanup';\n      $SIG{'SIGPROF'}='signal_cl\
eanup';\n      $SIG{'SIGUSR2'}='signal_cleanup';\n\
\n      $SIG{'SIGSYS'}='signal_cleanup';\n      $S\
IG{'SIGURG'}='signal_cleanup';\n      $SIG{'SIGCHL\
D'}='signal_cleanup';\n      $SIG{'SIGXCPU'}='sign\
al_cleanup';\n      $SIG{'SIGWINCH'}='signal_clean\
up';\n\n      $SIG{'INT'}='signal_cleanup';\n     \
 $SIG{'TERM'}='signal_cleanup';\n      $SIG{'KILL'\
}='signal_cleanup';\n      $SIG{'QUIT'}='signal_cl\
eanup';\n\n      our $debug_lock=$ENV{\"DEBUG_LOCK\
\"};\n\n\n\n\n      foreach my $a (@ARGV){$CL.=\" \
$a\";}\n      if ( $debug_lock ){print STDERR \"\\\
n\\n\\n********** START PG: $PROGRAM *************\
\\n\";}\n      if ( $debug_lock ){print STDERR \"\\
\n\\n\\n**********(tcg) LOCKDIR: $LOCKDIR $$ *****\
********\\n\";}\n      if ( $debug_lock ){print ST\
DERR \"\\n --- $$ -- $CL\\n\";}\n\n\n\n\n    }\nsu\
b flush_error\n  {\n    my $msg=shift;\n    return\
 add_error ($EXIT_FAILURE,$$, $$,getppid(), $msg, \
$CL);\n  }\nsub add_error\n  {\n    my $code=shift\
;\n    my $rpid=shift;\n    my $pid=shift;\n    my\
 $ppid=shift;\n    my $type=shift;\n    my $com=sh\
ift;\n\n    $ERROR_DONE=1;\n    lock4tc ($rpid, \"\
LERROR\",\"LSET\",\"$pid -- ERROR: $type\\n\");\n \
   lock4tc ($$, \"LERROR\",\"LSET\", \"$pid -- COM\
: $com\\n\");\n    lock4tc ($$, \"LERROR\",\"LSET\\
", \"$pid -- STACK: $ppid -> $pid\\n\");\n\n    re\
turn $code;\n  }\nsub add_warning\n  {\n    my $rp\
id=shift;\n    my $pid =shift;\n    my $command=sh\
ift;\n    my $msg=\"$$ -- WARNING: $command\\n\";\\
n    print STDERR \"$msg\";\n    lock4tc ($$, \"LW\
ARNING\", \"LSET\", $msg);\n  }\n\nsub signal_clea\
nup\n  {\n    print dtderr \"\\n**** $$ (tcg) was \
killed\\n\";\n    &cleanup;\n    exit ($EXIT_FAILU\
RE);\n  }\nsub clean_dir\n  {\n    my $dir=@_[0];\\
n    if ( !-d $dir){return ;}\n    elsif (!($dir=~\
/tmp/)){return ;}#safety check 1\n    elsif (($dir\
=~/\\*/)){return ;}#safety check 2\n    else\n    \
  {\n	`rm -rf $dir`;\n      }\n    return;\n  }\ns\
ub cleanup\n  {\n    #print stderr \"\\n----tc: $$\
 Kills $PIDCHILD\\n\";\n    #kill (SIGTERM,$PIDCHI\
LD);\n    my $p=getppid();\n    $CLEAN_EXIT_STARTE\
D=1;\n\n\n\n    if (&lock4tc($$,\"LERROR\", \"LCHE\
CK\", \"\"))\n      {\n	my $ppid=getppid();\n	if (\
!$ERROR_DONE)\n	  {\n	    &lock4tc($$,\"LERROR\", \
\"LSET\", \"$$ -- STACK: $p -> $$\\n\");\n	    &lo\
ck4tc($$,\"LERROR\", \"LSET\", \"$$ -- COM: $CL\\n\
\");\n	  }\n      }\n    my $warning=&lock4tc($$, \
\"LWARNING\", \"LREAD\", \"\");\n    my $error=&lo\
ck4tc($$,  \"LERROR\", \"LREAD\", \"\");\n    #rel\
ease error and warning lock if root\n\n    if (isr\
ootpid() && ($warning || $error) )\n      {\n\n	pr\
int STDERR \"**************** Summary ************\
*\\n$error\\n$warning\\n\";\n\n	&lock4tc($$,\"LERR\
OR\",\"RELEASE\",\"\");\n	&lock4tc($$,\"LWARNING\"\
,\"RELEASE\",\"\");\n      }\n\n\n    foreach my $\
f (@TMPFILE_LIST)\n      {\n	if (-e $f){unlink ($f\
);}\n      }\n    foreach my $d (@TMPDIR_LIST)\n  \
    {\n	clean_dir ($d);\n      }\n    #No More Loc\
k Release\n    #&lock4tc($$,\"LLOCK\",\"LRELEASE\"\
,\"\"); #release lock\n\n    if ( $debug_lock ){pr\
int STDERR \"\\n\\n\\n********** END PG: $PROGRAM \
($$) *************\\n\";}\n    if ( $debug_lock ){\
print STDERR \"\\n\\n\\n**********(tcg) LOCKDIR: $\
LOCKDIR $$ *************\\n\";}\n  }\nEND\n  {\n\n\
    &cleanup();\n  }\n\nsub blast_com2new_blast_co\
m\n    {\n      my $com=shift;\n	  if ($com=~/form\
atdb/)\n	    {\n	      $com=~s/formatdb/makeblastd\
b/;\n	      $com=~s/\\-i/\\-in/;\n	      if ($com \
=~/pF/){$com=~s/\\-pF/\\-dbtype nucl/;}\n	      if\
 ($com =~/p F/){$com=~s/\\-p F/\\-dbtype nucl/;}\n\
	      $com=\"$com -logfile /dev/null\";\n	      r\
eturn $com;\n	    }\n	  else {return $com;}\n\n   \
 }\nsub safe_system\n{\n  my $com=shift;\n  my $nt\
ry=shift;\n  my $ctry=shift;\n  my $pid;\n  my $st\
atus;\n  my $ppid=getppid();\n  if ($com eq \"\"){\
return 1;}\n\n  if ( ($com=~/^blast/) ||($com=~/^f\
ormatdb/)){$com=&blast_com2new_blast_com($com);}\n\
\n  if (($pid = fork ()) < 0){return (-1);}\n  if \
($pid == 0)\n    {\n      set_lock($$, \" -SHELL- \
$com (tcg)\");\n      if( $debug_generic_method ) \
{ printf \"~ exec: %s\\n\", $com; }\n      exec ($\
com);\n      if( $debug_generic_method ) { printf \
\"~ exitcode: %s\\n\", $?; }\n    }\n  else\n    {\
\n      lock4tc ($$, \"LLOCK\", \"LSET\", \"$pid\\\
n\");#update parent\n      $PIDCHILD=$pid;\n    }\\
n  if ($debug_lock){printf STDERR \"\\n\\t .... sa\
fe_system (fasta_seq2hmm)  p: $$ c: $pid COM: $com\
\\n\";}\n\n  waitpid ($pid,WTERMSIG);\n\n  shift_l\
ock ($pid,$$, \"LWARNING\",\"LWARNING\", \"LSET\")\
;\n\n  if ($? == $EXIT_FAILURE || lock4tc($pid, \"\
LERROR\", \"LCHECK\", \"\"))\n    {\n      if ($nt\
ry && $ctry <$ntry)\n	{\n\n	  add_warning ($$,$$,\\
"$com failed [retry: $ctry out of $ntry]\");\n	  l\
ock4tc ($pid, \"LRELEASE\", \"LERROR\", \"\");\n	 \
 #if ($com=~/EBI/){$com=~s/EBI/NCBI/;}\n	  #elsif \
($com=~/NCBI/){$com=~s/NCBI/EBI/;}\n\n	  return sa\
fe_system ($com, $ntry, ++$ctry);\n	}\n      elsif\
 ($ntry == -1)\n	{\n	  if (!shift_lock ($pid, $$, \
\"LERROR\", \"LWARNING\", \"LSET\"))\n	    {\n	   \
   add_warning ($$,$$,\"$com failed\");\n	    }\n	\
  else\n	    {\n	      lock4tc ($pid, \"LRELEASE\"\
, \"LERROR\", \"\");\n	    }\n	  return $?;}\n    \
  else\n	{\n	  if (!shift_lock ($pid,$$, \"LERROR\\
",\"LERROR\", \"LSET\"))\n	    {\n	      myexit(ad\
d_error ($EXIT_FAILURE,$$,$pid,getppid(), \"UNSPEC\
IFIED system\", $com));\n	    }\n	}\n    }\n  retu\
rn $?;\n}\n\nsub check_configuration\n    {\n     \
 my @l=@_;\n      my $v;\n      foreach my $p (@l)\
\n	{\n\n	  if   ( $p eq \"EMAIL\")\n	    {\n	     \
 if ( !($EMAIL=~/@/))\n		{\n		add_warning($$,$$,\"\
Could Not Use EMAIL\");\n		myexit(add_error ($EXIT\
_FAILURE,$$,$$,getppid(),\"EMAIL\",\"$CL\"));\n	  \
    }\n	    }\n	  elsif( $p eq \"INTERNET\")\n	   \
 {\n	      if ( !&check_internet_connection())\n		\
{\n		  myexit(add_error ($EXIT_FAILURE,$$,$$,getpp\
id(),\"INTERNET\",\"$CL\"));\n		}\n	    }\n	  elsi\
f( $p eq \"wget\")\n	    {\n	      if (!&pg_is_ins\
talled (\"wget\") && !&pg_is_installed (\"curl\"))\
\n		{\n		  myexit(add_error ($EXIT_FAILURE,$$,$$,g\
etppid(),\"PG_NOT_INSTALLED:wget\",\"$CL\"));\n		}\
\n	    }\n	  elsif( !(&pg_is_installed ($p)))\n	  \
  {\n	      myexit(add_error ($EXIT_FAILURE,$$,$$,\
getppid(),\"PG_NOT_INSTALLED:$p\",\"$CL\"));\n	   \
 }\n	}\n      return 1;\n    }\nsub nw\n      {\n	\
my($A,$B)=@_;\n	my ($i,$j, $s);\n	my $gep=-2;\n	my\
 $match=+2;\n	my $mismatch=0;\n	my ($sub, $ins, $d\
el);\n\n\n	if ($A eq $B){return ($A,$B);}\n	\n	$A=\
~s/[\\s\\d]//g;	\n	$B=~s/[\\s\\d]//g;	\n\n\n	my @r\
A=split ('',$A);\n	my @rB=split ('',$B);\n	\n	#eva\
luate substitutions\n	my $lenA=@rA;\n	my $lenB=@rB\
;\n	\n	for ($i=0; $i<=$lenA; $i++){$smat[$i][0]=$i\
*$gep;$tb[$i][0 ]= 1;}\n	for ($j=0; $j<=$lenB; $j+\
+){$smat[0][$j]=$j*$gep;$tb[0 ][$j]=-1;}\n	\n	for \
($i=1; $i<=$lenA; $i++)\n	  {\n	    for ($j=1; $j<\
=$lenB; $j++)\n	      {\n		if ($rA[$i-1] eq $rB[$j\
-1]){$s=$match;}\n		else {$s=$mismatch;}\n		\n		$s\
ub=$smat[$i-1][$j-1]+$s;\n		$del=$smat[$i  ][$j-1]\
+$gep;\n		$ins=$smat[$i-1][$j  ]+$gep;\n		\n		if  \
 ($sub>=$del && $sub>=$ins){$smat[$i][$j]=$sub;$tb\
[$i][$j]=0;}\n		elsif($del>$ins){$smat[$i][$j]=$de\
l;$tb[$i][$j]=-1;}\n		else {$smat[$i][$j]=$ins;$tb\
[$i][$j]=1;}\n		}\n	  }\n	#print \"\\n---- SCORE=$\
smat[$lenA][$lenB]\\n\";\n	\n	$i=$lenA;\n	$j=$lenB\
;\n	my $aln_len=0;\n\n	while (!($i==0 && $j==0))\n\
	  {\n	    if ($tb[$i][$j]==0)\n	    {\n	      $aA\
[$aln_len]=$rA[--$i];\n	      $aB[$aln_len]=$rB[--\
$j];\n	    }\n	  elsif ($tb[$i][$j]==-1)\n	    {\n\
	      $aA[$aln_len]='-';\n	      $aB[$aln_len]=$r\
B[--$j];\n	    }\n	  elsif ($tb[$i][$j]==1)\n	    \
{\n	      $aA[$aln_len]=$rA[--$i];\n	      $aB[$al\
n_len]='-';\n	    }\n	  $aln_len++;\n	  }\n	\n	\n	\
@aA=reverse (@aA);\n	@aB=reverse (@aB);\n	my $sA=j\
oin('',@aA);\n	my $sB=join('',@aB);\n	return ($sA,\
$sB);\n      }\n      \n$program=\"T-COFFEE (Versi\
on_11.00.8cbe486)\";\\n\n","use Env;\nuse FileHand\
le;\nuse Cwd;\nuse File::Path;\nuse Sys::Hostname;\
\nmy $f = new FileHandle;\n\nopen ($f, $ARGV[1]);\\
n$atom=$ARGV[0];\n\n$atom=~s/PRIME/\\'/;\nwhile (<\
$f>)\n  {\n    my $l=$_;\n\n    $l=~s/$atom/CA /;\\
n    \n    \n    $l=~s/  G /GLY /g;\n    $l=~s/  C\
 /CYS /g;\n    $l=~s/  T /THR /g;\n    $l=~s/  A /\
ALA /g;\n    $l=~s/  U /THR /g;\n    \n    $l=~s/ \
DG /GLY /g;\n    $l=~s/ DC /CYS /g;\n    $l=~s/ DT\
 /THR /g;\n    $l=~s/ DA /ALA /g;\n    $l=~s/ DU /\
THR /g;\n    \n    print $l;\n  }\n\n\n\n","*TC_ME\
THOD_FORMAT_01\n******************generic_method.t\
c_method*************\n*\n*       Incorporating ne\
w methods in T-Coffee\n*       Cedric Notredame 26\
/08/08\n*\n***************************************\
****************\n*This file is a method file\n*Co\
py it and adapt it to your need so that the method\
 \n*you want to use can be incorporated within T-C\
offee\n*******************************************\
************\n*                  USAGE            \
                  *\n*****************************\
**************************\n*This file is passed t\
o t_coffee via -in:\n*\n*	t_coffee -in Mgeneric_me\
thod.method\n*\n*	The method is passed to the shel\
l using the following\n*call:\n*<EXECUTABLE><PARAM\
1><IN_FLAG><seq_file><PARAM2><OUT_FLAG><outname><P\
ARAM>\n*\n*Conventions:\n*<FLAG_NAME> 	<TYPE>		<VA\
LUE>\n*<VALUE>:	no_name 	<=> Replaced with a space\
\n*<VALUE>:	&nbsp	<=> Replaced with a space\n*\n**\
**************************************************\
***\n*                  ALN_MODE                  \
         *\n**************************************\
*****************\n*pairwise   ->all Vs all (no se\
lf )[(n2-n)/2aln]\n*m_pairwise ->all Vs all (no se\
lf)[n^2-n]^2\n*s_pairwise ->all Vs all (self): [n^\
2-n]/2 + n\n*multiple   ->All the sequences in one\
 go\n*\nALN_MODE		pairwise\n*\n*******************\
************************************\n*           \
       OUT_MODE                           *\n*****\
**************************************************\
\n* mode for the output:\n*External methods: \n* a\
ln -> alignmnent File (Fasta or ClustalW Format)\n\
* lib-> Lib file (TC_LIB_FORMAT_01)\n*Internal Met\
hods:\n* fL -> Internal Function returning a List \
(Librairie)\n* fA -> Internal Function returning a\
n Alignmnent\n*\nOUT_MODE		aln\n******************\
*************************************\n*          \
        SEQ_TYPE                           *\n****\
**************************************************\
*\n*G: Genomic, S: Sequence, P: PDB, R: Profile\n*\
Examples:\n*SEQTYPE	S	sequences against sequences \
(default)\n*SEQTYPE	S_P	sequence against structure\
\n*SEQTYPE	P_P	structure against structure\n*SEQTY\
PE	PS	mix of sequences and structure	\n*\nSEQ_TYPE\
	S\n*\n\n*****************************************\
**************\n*                COMMAND LINE     \
                    *\n*EXECUTABLE PARAM1 IN_FLAG \
OUT_FLAG PARAM             *\n********************\
***********************************\n*************\
******************************************\n*     \
             EXECUTABLE                         *\\
n*************************************************\
******\n*name of the executable\n*passed to the sh\
ell: executable\n*	\nEXECUTABLE	tc_generic_method.\
pl\n*\n*******************************************\
************\n*                  IN_FLAG          \
                   *\n****************************\
***************************\n*IN_FLAG\n*flag indic\
ating the name of the in coming sequences\n*IN_FLA\
G S no_name ->no flag\n*IN_FLAG S &bnsp-in&bnsp ->\
 \" -in \"\n*\nIN_FLAG		-infile=\n*\n*************\
******************************************\n*     \
             OUT_FLAG                           *\\
n*************************************************\
******\n*OUT_FLAG\n*flag indicating the name of th\
e out-coming data\n*same conventions as IN_FLAG\n*\
OUT_FLAG	S no_name ->no flag\n*if you want to redi\
rect, pass the parameters via PARAM1\n*set OUT_FLA\
G to >\n*\nOUT_FLAG		-outfile=\n*\n***************\
****************************************\n*       \
           PARAM_1                              *\\
n*************************************************\
******\n*<EXECUTABLE><PARAM1><IN_FLAG><seq_file><P\
ARAM2><OUT_FLAG><outname><PARAM>\n*Parameters sent\
 to the EXECUTABLE and specified *before* IN_FLAG \
\n*If there is more than 1 PARAM line, the lines a\
re\n*concatenated\n*Command_line: @EP@PARAM@-gapop\
en%e10%s-gapext%e20\n*	%s white space\n*	%e equal \
sign\n*\n*PARAM1	\n*\n*\n*\n**********************\
*********************************\n*              \
    PARAM_2                              *\n******\
*************************************************\\
n*<EXECUTABLE><PARAM1><IN_FLAG><seq_file><PARAM2><\
OUT_FLAG><outname><PARAM>\n*Parameters sent to the\
 EXECUTABLE and specified \n*after* IN_FLAG and *b\
efore* OUT_FLAG\n*If there is more than 1 PARAM li\
ne, the lines are\n*concatenated\n*\n*PARAM1	\n*\n\
*\n***********************************************\
********\n*                  PARAM                \
              *\n*********************************\
**********************\n*<EXECUTABLE><PARAM1><IN_F\
LAG><seq_file><PARAM2><OUT_FLAG><outname><PARAM>\n\
*Parameters sent to the EXECUTABLE and specified *\
after* OUT_FLAG\n*If there is more than 1 PARAM li\
ne, the lines are\n*concatenated\n*\nPARAM	-mode=s\
eq_msa -method=clustalw\nPARAM   -OUTORDER=INPUT -\
NEWTREE=core -align -gapopen=-15\n*\n*************\
******************************************\n*     \
             END                                *\\
n*************************************************\
******\n","*TC_METHOD_FORMAT_01\n***************cl\
ustalw_method.tc_method*********\nEXECUTABLE	clust\
alw\nALN_MODE		pairwise\nIN_FLAG		-INFILE=\nOUT_FL\
AG		-OUTFILE=\nOUT_MODE		aln\nPARAM		-gapopen=-10\\
nSEQ_TYPE		S\n************************************\
*************\n","$VersionTag =                   \
                                                  \
                                                  \
            2.43;\nuse Env;\nuse FileHandle;\nuse \
Cwd;\nuse File::Path;\nuse Sys::Hostname;\nour $PI\
DCHILD;\nour $ERROR_DONE;\nour @TMPFILE_LIST;\nour\
 $EXIT_FAILURE=1;\nour $EXIT_SUCCESS=0;\n\nour $RE\
FDIR=getcwd;\nour $EXIT_SUCCESS=0;\nour $EXIT_FAIL\
URE=1;\n\nour $PROGRAM=\"extract_from_pdb\";\nour \
$CL=$PROGRAM;\n\nour $CLEAN_EXIT_STARTED;\nour $de\
bug_lock=$ENV{\"DEBUG_LOCK\"};\nour $LOCKDIR=$ENV{\
\"LOCKDIR_4_TCOFFEE\"};\nif (!$LOCKDIR){$LOCKDIR=g\
etcwd();}\nour $ERRORDIR=$ENV{\"ERRORDIR_4_TCOFFEE\
\"};\nour $ERRORFILE=$ENV{\"ERRORFILE_4_TCOFFEE\"}\
;\n&set_lock ($$);\nif (isshellpid(getppid())){loc\
k4tc(getppid(), \"LLOCK\", \"LSET\", \"$$\\n\");}\\
n      \nour $SILENT=\" >/dev/null 2>/dev/null\";\\
nour $INTERNET=-1;\n\n\n\n\n\n\n\nour $BLAST_MAX_N\
RUNS=2;\nour $EXIT_SUCCESS=0;\nour $EXIT_FAILURE=1\
;\nour $CONFIGURATION=-1;\nour $REF_EMAIL=\"\";\no\
ur $PROGRAM=\"extract_from_pdb\";\n\n\nmy %onelett\
_prot=&fill_onelett_prot();\nmy %threelett_prot=&f\
ill_threelett_prot();\nmy %onelett_RNA=&fill_onele\
tt_RNA();\nmy %threelett_RNA=&fill_threelett_RNA()\
;\nmy %onelett_DNA=&fill_onelett_DNA();\nmy %three\
lett_DNA=&fill_threelett_DNA();\n\n\n\n\n\nmy %one\
lett = (\n'P' => \\%onelett_prot,\n'D' => \\%onele\
tt_DNA,\n'R' => \\%onelett_RNA\n);\n\n\nmy %threel\
ett = (\n'P' => \\%threelett_prot,\n'D' => \\%thre\
elett_DNA,\n'R' => \\%threelett_RNA\n);\n\n\n\n\n\\
n\n\nif($ARGV[0]=~/help/ ||$ARGV[0]=~/man/ || $ARG\
V[0]=~/HELP/ || $ARGV[0]=~/Man/ || $ARGV[0] eq \"-\
h\"  || $ARGV[0] eq \"-H\"  )\n{die \"SYNTAX: extr\
act_from_pdb Version $VersionTag	\n	Minimum:      \
       [extract_from_pdb file] \n			   OR \n			   \
  [... | extract_from_pdb]\n 	Flags (Default setti\
ng on the first line)\n	   -version...............\
....[Returns the Version Number]\n           -forc\
e.....................[Forces the file to be treat\
ed like a PDB file]\n                             \
         [Regenerates the header and SEQRES fields\
]\n           -force_name................[Forces t\
he file to be named after name]]\n           -infi\
le.....file...........[Flag can be omited]\n			   \
           [File must be pdb or fro pgm]\n        \
                              [File can also be co\
mpressed Z or gz]\n                               \
       [In the case of a compressed file, you can \
omit the gz|Z extension]\n           -netfile.....\
..............[File will be fetch from the net usi\
ng wget]\n                                      [w\
get or curl must be installed]\n                  \
                    [ftp://ftp.gnu.org/pub/gnu/wge\
t/]\n                                      [http:/\
/curl.haxx.se/]\n                                 \
     [Must also be used to retrieve the file from \
a local pdb copy (cf netaddress)]\n           -net\
address................[Address used for the retri\
eving the netfile]\n                              \
        [http://www.rcsb.org/pdb/cgi/export.cgi/%%\
.pdb.gz?format=PDB&pdbId=%%&compression=gz]\n     \
                                 [http://www.expas\
y.ch/cgi-bin/get-pdb-entry.pl?%%]\n               \
                       [local -> will get the file\
 from pdb_dir (see pdb_dir)]\n           -netcompr\
ession............[Extension if the netfile comes \
compressed]\n                                     \
 [gz]\n           -pdb_dir...................[addr\
ess of the repertory where the pdb is installed]\n\
                                      [Supports st\
andard ftp style installation OR every stru in DIR\
]\n                                      [Give the\
 ..../pdb/structure/ dir]\n                       \
               [If value omitted, the pg gets it f\
rom the env variable PDB_DIR]\n           -netcomp\
ression_pg.........[gunzip]\n           -is_pdb_na\
me..........name.[Returns 1 if the name is a PDB I\
D, 0 otherwise]\n           -model_type...........\
name.[Returns the model type if valid PDB name]\n \
          -is_released_pdb_name name.[Returns 1 if\
 the name corresponds to a released PDB file]\n   \
        -get_pdb_chains.....name...[Returns the li\
st of chains corresponding to the entry]\n        \
   -get_pdb_id.........name...[Returns the PDB id \
within the provided pdb file]\n           -get_fug\
ue_name.....name...[Turns a name into a name valid\
 for fugue]\n                                     \
 [Uses the netaddress to do so]\n	   -chain......F\
IRST..........[Extract the first chain only]\n		  \
     A B C..........[Extract Several chains if nee\
ded]\n		       ALL............[Extract all the cha\
ins]	\n           -ligand.....ALL............[Extr\
act the ligands in the chain (HETATM)]\n          \
             <name1>,<name2>[Extract All the named\
 lignds]\n	   -ligand_only...............[Extract \
only the ligands]\n           -ligand_list........\
.......[Extract the list of ligands]\n	   -coor...\
....<start>..<end>.[Coordinates of the fragment to\
 extract]\n			              [Omit end to include t\
he Cter]\n           -num........absolute.......[a\
bsolute: relative to the seq] \n                  \
     file...........[file: relative to file]\n    \
       -num_out....new............[new: start 1->L\
]\n                       old............[old: kee\
p the file coordinates]\n           -delete.....<s\
tart>..<end>.[Delete from residue start to residue\
 end]\n	   -atom.......CA.............[Atoms to in\
clude, ALL for all of them]\n		       CA O N......\
...[Indicate several atoms if needed]\n	   -code..\
.....3..............[Use the 1 letter code or the \
3 letters code]\n	   -mode.......raw............[O\
utput original pdb file]\n                       p\
db............[Output something that looks like pd\
b]\n		       fasta..........[Output the sequences \
in fasta format]\n		       simple.........[Output \
a format easy to parse in C ]\n            -seq_fi\
eld..ATOM...........[Field used to extract the seq\
uence]\n		       SEQRES.........[Use the complete \
sequence]\n	   -seq.......................[Equival\
ent to  -mode fasta]\n	   -model......1...........\
...[Chosen Model in an NMR file]\n           -nodi\
agnostic..............[Switches Error Messages off\
]\n           -debug.....................[Sets the\
 DEBUG ON]\n           -no_remote_pdb_dir.........\
[Do not look for a remote file]\n           -cache\
_pdb.................[Cache Value, default is $HOM\
E/.t_coffee/cache, other values: NO<=> No cache]\n\
\n      Environement Variables\n           These v\
ariables can be set from the environement\n       \
    Command line values with the corresponding fla\
g superseed evironement value\n           NO_REMOT\
E_PDB_DIR..........[Prevents the program from sear\
ching remote file: faster]\n           PDB_DIR....\
................[Indicates where PDB file must be \
fetched (localy)]\n\n	 PROBLEMS: please contact ce\
dric.notredame\\@europe.com\\n\";\n	 exit ($EXIT_S\
UCCESS);\n}\n\n$np=0;\n$n_para=$#ARGV;\n$model=1;\\
n$pdb_dir=$ENV{'PDB_DIR'};if ($pdb_dir){$pdb_dir.=\
\"/\";}\n$debug=$ENV{'DEBUG_EXTRACT_FROM_PDB'};\n\\
n$no_remote_pdb_dir=$ENV{NO_REMOTE_PDB_DIR};\n$HOM\
E=$ENV{'HOME'};\nif ( $ENV{CACHE_4_TCOFFEE})\n{$ca\
che=$ENV{CACHE_4_TCOFFEE};}\nelse\n{\n    $cache=\\
"$HOME/.t_coffee/cache/\";\n}\n\n   \n$netaddress=\
\"http://www.rcsb.org/pdb/files/%%.pdb.gz\";\n$net\
compression_pg=\"gunzip\";\n$netcompression=\"gz\"\
;\n\nforeach ($np=0; $np<=$n_para; $np++)\n  {    \
    \n    $value=$ARGV[$np];\n   \n    if  ($np==0\
 && !($value=~/^-.*/))\n      { \n	$pdb_file= $ARG\
V[$np];\n      }\n    elsif ( !($value=~/^-.*/))\n\
      {\n	print \"@ARGV\";\n	die;\n      } \n    \\
n    elsif ($value eq \"-nodiagnostic\"){$nodiagno\
stic=1;}\n    elsif ($value eq \"-force\")\n      \
{\n	$force_pdb=1;\n      }\n    elsif ($value eq \\
"-force_name\")\n      {\n	$force_name=$ARGV[++$np\
];\n	$force_pdb=1;\n      }\n    \n    elsif ($val\
ue eq \"-is_pdb_name\")\n      {\n	$pdb_file= $ARG\
V[++$np];	\n	$is_pdb_name=1;	\n      } \n    elsif\
 ($value eq \"-is_released_pdb_name\")\n      {\n	\
$pdb_file= $ARGV[++$np];	\n	$is_released_pdb_name=\
1;\n      }\n    elsif ($value eq \"-model_type\")\
\n      {\n	$pdb_file= $ARGV[++$np];	\n	$model_typ\
e=1;\n      }\n    elsif ($value eq \"-debug\")\n{\
\n	$debug=1;\n}\n    elsif ($value eq \"-get_pdb_c\
hains\")\n{\n	$pdb_file= $ARGV[++$np];\n	$get_pdb_\
chains=1;\n}\n    elsif ($value eq \"-get_pdb_liga\
nds\")\n{\n	$get_pdb_ligands=1;\n}\n    \n    elsi\
f ($value eq \"-get_pdb_id\")\n{\n	$pdb_file= $ARG\
V[++$np];\n	$get_pdb_id=1;\n	\n}\n    \n    elsif \
( $value eq \"-get_fugue_name\")\n{\n	$pdb_file= $\
ARGV[++$np];\n	$get_fugue_name=1;\n}\n    elsif ( \
$value eq \"-infile\")\n{\n       $pdb_file= $ARGV\
[++$np];\n} \n    elsif ($value eq \"-netfile\")\n\
{\n	$netfile=1;\n	if ( !($ARGV[$np+1]=~/^-.*/)){$p\
db_file= $ARGV[++$np];}\n}\n    elsif (  $value eq\
 \"-num\")\n{\n       $numbering= $ARGV[++$np];\n}\
\n    elsif (  $value eq \"-num_out\")\n{\n       \
$numbering_out= $ARGV[++$np];\n}\n    elsif ( $val\
ue eq \"-netaddress\")\n{\n	$netadress=$ARGV[++$np\
];\n}\n     \n    elsif ( $value eq \"-netcompress\
ion\")\n{\n	 $netcompression=$ARGV[++$np];\n}\n   \
 elsif ( $value eq \"-pdb_dir\")\n{\n	 if ( !($ARG\
V[$np+1]=~/^-.*/)){$pdb_dir= \"$ARGV[++$np]/\";}\n\
}\n     elsif ( $value eq \"-no_remote_pdb_dir\")\\
n{\n	$no_remote_pdb_dir=1;\n	if ( !($ARGV[$np+1]=~\
/^-.*/)){$pdb_dir= \"$ARGV[++$np]/\";}\n}\n    els\
if ( $value eq \"-cache\")\n{\n	$cache=$ARGV[++$np\
];\n}\n    \n    elsif ($value eq \"-netcompressio\
n_pg\")\n{\n	  $netcompression_pg=$ARGV[++$np];\n}\
\n     elsif ($value eq \"-mode\")\n{\n       $MOD\
E=$ARGV[++$np];\n}\n\n    elsif ( $value eq \"-mod\
el\")\n{\n       $model= $ARGV[++$np];\n}\n    els\
if ($value eq \"-seq_field\" )\n{\n       $seq_fie\
ld= $ARGV[++$np];\n}   \n    elsif ($value eq \"-c\
oor\" )\n{\n       $start= $ARGV[++$np];\n  \n    \
   if (($ARGV[$np+1] eq \"\") ||($ARGV[$np+1]=~/^-\
.*/)){$end=\"*\";} \n       else {$end=   $ARGV[++\
$np];}     \n       $coor_set=1;\n}\n    elsif ($v\
alue eq \"-delete\" )\n{\n       $delete_start= $A\
RGV[++$np];\n       $delete_end= $ARGV[++$np];\n  \
     $delete_set=1;\n}\n    elsif  ($value eq \"-c\
ode\")\n{\n       $code= $ARGV[++$np];\n}\n    els\
if  ($value eq \"-no_hetatm\")\n{\n       $no_heta\
tm=1;\n}\n    elsif ($value eq \"-chain\")\n{\n   \
    while (!($ARGV[$np+1] eq \"\") &&!($ARGV[$np+1\
]=~/^-.*/))\n{\n	      ++$np;\n	      @c_chain=(@c\
hain,  $ARGV[$np]);\n	      $hc_chain{$ARGV[$np]}=\
$#c_chain+1;\n}           \n}\n    elsif ($value e\
q \"-atom\")\n{\n\n       while (!($ARGV[$np+1] eq\
 \"\") && !($ARGV[$np+1]=~/^-.*/))\n{\n	      ++$n\
p;\n	      $atom[$n_atom++]=  $ARGV[$np];\n	      \
$atom_list{$ARGV[$np]}=1;	      \n} \n       \n}\n\
    elsif ( $value eq \"-unfold\")\n{\n	$unfold=1;\
\n}\n    elsif ($value eq \"-seq\" ||$value eq \"-\
fasta\" )\n{\n       $MODE=\"fasta\";\n}\n    elsi\
f ( $value eq \"-version\")\n{\n	print STDERR  \"\\
\nextract_from_pdb: Version $VersionTag\\n\";\n	&m\
yexit ($EXIT_SUCCESS);\n}\n    elsif ( $value eq \\
"-ligand\")\n{\n	while (!($ARGV[$np+1] eq \"\") &&\
 !($ARGV[$np+1]=~/^-.*/))\n{\n	    ++$np;\n	    $l\
igand=1;\n	    $ligand_list{$ARGV[$np]}=1;	      \\
n} \n	$hc_chain{'LIGAND'}=1;\n}\n    elsif ( $valu\
e eq \"-ligand_only\")\n{\n	$ligand_only=1;\n}\n}\\
nif ( $debug)\n{\n    print STDERR \"\\n[DEBUG:ext\
ract_from_pdb] NO_REMOTE_PDB_DIR: $no_remote_pdb_d\
ir\\n\";\n    print STDERR \"\\n[DEBUG:extract_fro\
m_pdb] PDB_DIR: $pdb_dir\\n\";\n}\n\n\nif ( $is_pd\
b_name)\n  {\n    if (&remote_is_pdb_name($pdb_fil\
e))\n      {\n	print \"1\";\n      }\n    else\n  \
    {\n	print \"0\";\n      }\n    exit ($EXIT_SUC\
CESS);\n  }\n\nif ( $is_released_pdb_name)\n  {\n \
   \n    if (&is_released($pdb_file))\n      {\n	p\
rint \"1\";\n      }\n    else\n      {\n	print \"\
0\";\n      }\n    exit ($EXIT_SUCCESS);\n  }\nif \
($model_type)\n  {\n   \n    printf \"%s\", &pdb2m\
odel_type($pdb_file);\n    exit ($EXIT_SUCCESS);\n\
    \n  }\n    \n\nif (!$force_name)\n{\n    $pdb_\
file=~/([^\\/]*)$/;\n    $force_name=$1;\n}\n\n$lo\
cal_pdb_file=$pdb_file;\n\nif ( $debug){print STDE\
RR \"\\n[DEBUG: extract_from_pdb] Scan For $local_\
pdb_file\\n\";}\n\n$mem=$no_remote_pdb_dir;\n$no_r\
emote_pdb_dir=1;\n$tmp_pdb_file=get_pdb_file ($loc\
al_pdb_file);\n\nif ( !-e $tmp_pdb_file || $tmp_pd\
b_file eq \"\")\n  {\n    $local_pdb_file=$pdb_fil\
e;\n    ($local_pdb_file, $suffix_chain)=&pdb_name\
2name_and_chain($local_pdb_file);\n\n    if ($loca\
l_pdb_file)\n      {\n	if ( $debug){print STDERR \\
"\\nSplit $pdb_file into $local_pdb_file and $suff\
ix_chain \\n\";}\n	$tmp_pdb_file=get_pdb_file ($lo\
cal_pdb_file);\n	if ( $tmp_pdb_file ne \"\")\n	  {\
\n	    @c_chain=();\n	    @c_chain=($suffix_chain)\
;\n	    %hc_chain=();\n	    $hc_chain{$suffix_chai\
n}=1;\n	  }\n      }\n  }\n\n$no_remote_pdb_dir=$m\
em;\nif ($no_remote_pdb_dir==0)\n  {\n    \n    if\
 ( !-e $tmp_pdb_file || $tmp_pdb_file eq \"\")\n  \
    {\n	\n	$local_pdb_file=$pdb_file;\n	($local_pd\
b_file, $suffix_chain)=&pdb_name2name_and_chain($l\
ocal_pdb_file);\n	if ($local_pdb_file)\n	  {\n	   \
 \n	    if ( $debug){print STDERR \"\\nSplit $pdb_\
file into $local_pdb_file and $suffix_chain \\n\";\
}\n	    \n	    $tmp_pdb_file=get_pdb_file ($local_\
pdb_file);    \n	    \n	    if ( $tmp_pdb_file ne \
\"\")\n	      {\n		@c_chain=();\n		@c_chain=($suff\
ix_chain);\n		%hc_chain=();\n		$hc_chain{$suffix_c\
hain}=1;\n	      }\n	  }\n      }\n  }\n\nif ( $de\
bug){print STDERR \"\\n$pdb_file copied into ##$tm\
p_pdb_file##\\n\";}\n\nif ( !-e $tmp_pdb_file || $\
tmp_pdb_file eq \"\")\n{\n	if ($is_pdb_name)\n{\n	\
    print \"0\\n\"; exit ($EXIT_SUCCESS);\n}\n	els\
e\n{\n  \n	    print \"\\nEXTRACT_FROM_PDB: NO RES\
ULT for $pdb_file\\n\";\n	    &myexit ($EXIT_SUCCE\
SS);	\n}\n}\n\n\n\n\n%molecule_type=&pdbfile2chain\
type($tmp_pdb_file);\nif ( $debug){print STDERR \"\
\\n\\tSequence Type determined\\n\";}\n\n$pdb_id=&\
get_pdb_id ($tmp_pdb_file);\nif ( $debug){print ST\
DERR \"\\n\\tID: $pdb_id (for $tmp_pdb_file)\\n\";\
}\n\nif ( $pdb_id eq \"\"){$pdb_id=$force_name;}\n\
\n@f_chain=&get_chain_list ($tmp_pdb_file);\nif ( \
$debug){print STDERR \"\\n\\tChain_list:@f_chain\\\
n\";}\n\nif ( $get_pdb_chains)\n{\n    print \"@f_\
chain\\n\";\n    &myexit ($EXIT_SUCCESS);\n}\nif (\
 $get_pdb_ligands)\n{\n    %complete_ligand_list=&\
get_ligand_list ($tmp_pdb_file);\n    print $compl\
ete_ligand_list{\"result\"};\n    &myexit ($EXIT_S\
UCCESS);\n}\n\nelsif ( $get_pdb_id ||$get_fugue_na\
me )\n{\n    if    (@c_chain && $c_chain[0] eq \"F\
IRST\"){$pdb_id=$pdb_id.$f_chain[0];}\n    elsif (\
@c_chain && $c_chain[0] ne \" \"){$pdb_id=$pdb_id.\
$c_chain[0];}\n    \n    print \"$pdb_id\\n\";\n  \
  &myexit ($EXIT_SUCCESS);\n    \n}\nelsif ( $is_p\
db_name)\n{\n    printf \"1\\n\";\n    &myexit ($E\
XIT_SUCCESS);\n}\n\n\n\n$structure_file=vtmpnam();\
\n\nif ( $debug){print STDERR \"\\n\\tCheck_point \
#1: $tmp_pdb_file  $structure_file\\n\";}\n\n$INFI\
LE=vfopen (\"$tmp_pdb_file\", \"r\"); \nmy $TMP=vf\
open (\"$structure_file\", \"w\");\n\n$print_model\
=1;\n$in_model=0;\n\nif ( $debug){print STDERR \"\\
\n\\tCheck_point #2\\n\";}\nwhile ( <$INFILE>)\n{\\
n  my $first_model=0;\n  $line=$_;\n\n  if ( !$fir\
st_model && ($line =~/^MODEL\\s*(\\d*)/))\n    {\n\
      $first_model=$1;\n      if ($model==1){$mode\
l=$first_model;}\n    }\n  \n  if (($line =~/^MODE\
L\\s*(\\d*)/))\n    {\n      if ($1==$model)\n	{\n\
	  $in_model=1;\n	  $print_model=1;\n	  $is_nmr=1;\
\n	}\n      elsif ( $in_model==0)\n	{\n	  $print_m\
odel=0;\n	}\n      elsif ( $in_model==1)\n	{\n	  l\
ast;\n	}\n    }\n  if ($print_model){print $TMP $l\
ine;}  \n}\nclose ($TMP);\nclose ($INFILE);\n\nif \
( $debug){print STDERR \"\\n\\tCheck_point #3\\n\"\
;}	\n\n  if ($numbering eq \"\"){$numbering=\"abso\
lute\";}\n  if ($numbering_out eq \"\"){$numbering\
_out=\"new\";}\n\n  if ( $delete_set && $coor_set)\
 {die \"-delete and -coor are mutually exclusive, \
sorry\\n\";}\n  if ( $n_atom==0){$atom_list[$n_ato\
m++]=\"ALL\";$atom_list{$atom_list[0]}=1;}\n  if (\
 $seq_field eq \"\"){$seq_field=\"ATOM\";}\n  \n  \
if ( $MODE eq \"\"){$MODE=\"pdb\";}\n  elsif ( $MO\
DE eq \"simple\" && $code==0){$code=1;}\n\n  if ( \
$code==0){$code=3;}\n\n\nif ($f_chain[0] eq \" \")\
{$hc_chain{' '}=1;$c_chain[0]=\" \";}\nelsif (!@c_\
chain){$hc_chain{FIRST}=1;$c_chain[0]=\"FIRST\";}#\
make sure the first chain is taken by default\n\ni\
f    ($hc_chain{ALL}) \n{\n      @c_chain=@f_chain\
;\n      foreach $e (@c_chain){$hc_chain{$e}=1;}\n\
}\nelsif($hc_chain{FIRST})\n{\n	@c_chain=($f_chain\
[0]);\n	$hc_chain{$f_chain[0]}=1;\n}\n\n\n$MAIN_HO\
M_CODE=&get_main_hom_code ($structure_file);\n$INF\
ILE=vfopen ($structure_file, \"r\");\n\n\nif ( $MO\
DE eq \"raw_pdb\" || $MODE eq \"raw\")\n{\n    whi\
le (<$INFILE>)\n{	print \"$_\";}\n    close ( $INF\
ILE);\n    &myexit($EXIT_SUCCESS);\n}    \nif ( $M\
ODE eq \"raw4fugue\" )\n{\n    while (<$INFILE>)\n\
{	\n	$l=$_;\n	if ($l=~/^SEQRES/)\n{\n	    \n	    $\
c= substr($l,11,1);\n	    if ($hc_chain {$c}){prin\
t \"$l\";}\n}\n	elsif ( $l=~/^ATOM/)\n{\n	    $c=s\
ubstr($l,21,1);\n	    if ($hc_chain {$c}){print \"\
$l\";}\n}\n}\n    close ( $INFILE);\n    &myexit($\
EXIT_SUCCESS);\n}    \n\nif ( $MODE eq \"pdb\")\n{\
\n\n    $read_header=0;\n    while (<$INFILE>) \n{\
\n	    $line=$_;\n	    if    ($line =~ /^HEADER/){\
print \"$line\";$read_header=1;}\n}\n    close ($I\
NFILE);\n\n    if (!$read_header)\n{\n	print \"HEA\
DER    UNKNOWN                                 00-\
JAN-00   $force_name\\n\";\n}\n\n    $INFILE=vfope\
n ($structure_file, \"r\");\n    \n    print \"COM\
PND   1 CHAIN:\";\n    $last=pop(@c_chain);\n    f\
oreach $c ( @c_chain){ print \" $c,\";}\n    if ( \
$last eq \" \"){print \" NULL;\\n\";}\n    else \n\
{\n      print \" $last;\\n\";\n}\n    @c_chain=(@\
c_chain, $last);\n    \n    print \"REMARK Output \
of the program extract_from_pdb (Version $VersionT\
ag)\\n\";\n    print \"REMARK Legal PDB format not\
 Guaranteed\\n\";\n    print \"REMARK This format \
is not meant to be used in place of the PDB format\
\\n\";\n    print \"REMARK The header refers to th\
e original entry\\n\";\n    print \"REMARK The seq\
uence from the original file has been taken in the\
 field: $seq_field\\n\";\n    print \"REMARK extra\
ct_from_pdb, 2001, 2002, 2003, 2004, 2005 2006 (c)\
 CNRS and Cedric Notredame\\n\";   \n    if ( $coo\
r_set)\n{\n       print \"REMARK Partial chain: St\
art $start End $end\\n\";\n}\n    if ( $is_nmr)\n{\
\n       print \"REMARK NMR structure: MODEL $mode\
l\\n\";\n}\n   \n    if ( $n_atom!=0)\n{\n       p\
rint \"REMARK Contains Coordinates of: \";\n      \
 foreach $a (@atom){print \"$a \";}\n       print \
\"\\n\";\n}  \n}\n\n\n\n\nmy $residue_index = -999\
;\nmy $old_c = \"TemporaryChain\";\n\nwhile (<$INF\
ILE>) \n{\n	$line=$_;\n\n\n	if ($line =~ /^SEQRES/\
)\n{\n\n		@field=/(\\S*)\\s*/g;\n\n		$c= substr($_\
,11,1);\n\n		\n		$l=$#field;\n		for ($a=4; $a<$#fi\
eld ;)\n{\n			if (!$onelett{$molecule_type{$c}}->{\
$field[$a]})\n{\n				splice @field, $a, 1;\n}\n			\
else \n{\n				$a++;\n}\n}\n	\n		if ( $c ne $in_cha\
in)\n{\n			$pdb_chain_list[$n_pdb_chains]=$c;\n			\
$pdb_chain_len [$n_pdb_chains]=$len;\n			$in_chain\
=$c;\n			$n_pdb_chains++;\n}\n	\n		for ( $a=4; $a<\
$#field;$a++)\n{\n			$complete_seq{$c}[$complete_s\
eq_len{$c}++]=$field[$a];\n}\n}\n    elsif ( $line\
=~/^ATOM/ || ($line=~/^HETATM/ && &is_aa(substr($l\
ine,17,3),substr($line,21,1)) && !$no_hetatm))\n{\\
n\n	 \n    $RAW_AT_ID=$AT_ID=substr($line,12,4);\n\
	$RES_ID=&is_aa(substr($line,17,3),substr($line,21\
,1));\n	$CHAIN=substr($line,21,1);\n\n    $RES_NO=\
substr($line,22,4);\n	$HOM_CODE=substr ($line, 26,\
 1);\n	$TEMP=substr($line,60,6);\n	\n	$TEMP=~s/\\s\
//g;\n        $AT_ID=~s/\\s//g;\n	$RES_ID=~s/\\s//\
g;\n        $RES_NO=~s/\\s//g;\n		\n	if ( $HOM_COD\
E ne $MAIN_HOM_CODE){next;}\n	elsif ( $already_rea\
d2{$CHAIN}{$RES_ID}{$AT_ID}{$RES_NO}){next;}\n	els\
e{$already_read2{$CHAIN}{$RES_ID}{$AT_ID}{$RES_NO}\
=1;}\n	\n	\n	if ($coor_set && $numbering eq \"file\
\" && $residue_index ne $RES_NO)\n{\n	    \n	    i\
f ( $RES_NO<=$start){$real_start{$CHAIN}++;}\n	   \
 if ( $RES_NO<=$end){$real_end{$CHAIN}++;}\n}\n	el\
sif ($numbering eq \"absolute\")\n{\n	    $real_st\
art{$CHAIN}=$start;\n	    $real_end{$CHAIN}=$end;\\
n}\n\n        $KEY=\"ALL\";\n        if ( $CHAIN n\
e $in_atom_chain)\n{\n	    \n	  $pdb_atom_chain_li\
st[$n_pdb_atom_chains]=$c;\n	  $pdb_atom_chain_len\
 [$n_pdb_atom_chains]=$len;\n	  $in_atom_chain=$c;\
\n	  $n_pdb_atom_chains++;\n}\n	\n	if ( $residue_i\
ndex ne $RES_NO)\n{\n	     $residue_index = $RES_N\
O;\n	     $atom_seq{$CHAIN}[$atom_seq_len{$CHAIN}+\
+]=$RES_ID;;\n}\n}\n\n}\nclose ($INFILE);\n\n\n\n\\
n\n\n$INFILE=vfopen ($structure_file, \"r\");\nfor\
each $c (@c_chain)\n{\n\n	if    ( $seq_field eq \"\
SEQRES\"){@pdb_seq=@{$complete_seq{$c}};}\n	elsif \
( $seq_field eq \"ATOM\")  {@pdb_seq=@{$atom_seq{$\
c}};}\n	\n\n	$full_length=$l=$#pdb_seq+1;\n		\n	if\
 ( $real_end{$c}==\"*\"){$real_end{$c}=$full_lengt\
h;}\n	if ( $coor_set)\n{	   \n\n	   if ( $real_end\
{$c} < $l){splice @pdb_seq, $real_end{$c}, $l;}\n	\
   if ( $real_start{$c} < $l){splice @pdb_seq, 0, \
$real_start{$c}-1;}	  	   \n	   $l=$#pdb_seq;\n}\n\
\n	elsif ( $delete_set)\n{\n	   splice @pdb_seq, $\
delete_start, $delete_end-$delete_start+1;\n	   $l\
=$#pdb_seq;\n}\n	\n	$new_fasta_name=\"$pdb_id$c\";\
\n	if ( $coor_set)\n{\n	   if ( $n_pdb_chains==0){\
$new_fasta_name=\"$new_fasta_name$c\";}\n	   $new_\
fasta_name= $new_fasta_name.\"\\_$start\\_$end\";\\
n}\n	   \n	if ( $MODE eq \"pdb\")\n{\n	   $nl=1;\n\
	   $n=0;\n	   \n	   foreach $res ( @pdb_seq)\n		{\
\n		if ( !$n)\n		{\n		\n		 printf \"SEQRES %3d %1s\
 %4d  \", $nl,$c, $l;\n		 $nl++;\n	}\n	     $res=~\
s/\\s//g;\n	     \n	     if ($code==1){ printf \"%\
3s \",$onelett{$molecule_type{$c}}->{$res};}\n	   \
  elsif  ($code==3){ printf \"%3s \",$res};\n	    \
 \n	     $n++;		  \n	     if ( $n==13){$n=0;print \
\"\\n\";}\n}\n	  if ( $n!=0){print \"\\n\"; $n=0;}\
\n}\n	elsif ( $MODE eq \"simple\")\n{\n	  print \"\
# SIMPLE_PDB_FORMAT\\n\";\n	  if ( $new_fasta_name\
 eq \" \"){$new_fasta_name=\"dummy_name\";}\n	  pr\
int \">$new_fasta_name\\n\";\n\n	  foreach $res ( \
@pdb_seq)\n{\n	      print \"$onelett{$molecule_ty\
pe{$c}}->{$res}\";\n}\n	  print \"\\n\";\n}\n	elsi\
f ( $MODE eq \"fasta\")\n{\n	  $n=0;\n	  print \">\
$new_fasta_name\\n\";\n	  \n	  foreach $res ( @pdb\
_seq)\n{\n\n	      print \"$onelett{$molecule_type\
{$c}}->{$res}\";\n              $n++;\n	      if (\
 $n==60){print \"\\n\"; $n=0;}\n}\n	  print \"\\n\\
"; \n}\n}\n\nif ( $MODE eq \"fasta\")\n{\n     &my\
exit($EXIT_SUCCESS);\n  \n}\n\n  \n  $charcount=0;\
\n  $inchain=\"BEGIN\";\n  $n=0;\n  while (<$INFIL\
E>) \n{\n    $line=$_;\n     \n    if ($line =~/^A\
TOM/  ||  ($line=~/^HETATM/))\n{\n	$line_header=\"\
UNKNWN\";\n	$RES_ID=substr($line,17,3);\n	$chain =\
 substr($line,21,1);\n\n	if ($line =~/^ATOM/)\n{\n\
	    $line_header=\"ATOM\";\n	    $RES_ID=(&is_aa(\
$RES_ID,$chain))?&is_aa($RES_ID,$chain):$RES_ID;\n\
}\n	elsif ($line=~/^HETATM/ && ($ligand_list {$RES\
_ID} ||$ligand_list {'ALL'} || !&is_aa($RES_ID,$ch\
ain)))\n{\n	    $line_header=\"HETATM\";\n}\n	elsi\
f ($line=~/^HETATM/ && (&is_aa($RES_ID,$chain) && \
!$no_hetatm))\n{\n	    $line_header=\"ATOM\";\n	  \
  $RES_ID=&is_aa($RES_ID,$chain);\n}\n	else\n{\n	 \
   next;\n}\n\n	\n\n	$X=substr($line,30,8);     \n\
	$Y=substr($line,38,8);\n	$Z=substr($line,46,8);\n\
	$TEMP=substr($line,60,6);\n	\n	$RAW_AT_ID=$AT_ID=\
substr($line,12,4);\n	$CHAIN=substr($line,21,1);\n\
	$RES_NO=substr($line,22,4);\n	$HOM_CODE=substr ($\
line, 26, 1);\n	\n	$X=~s/\\s//g;\n	$Y=~s/\\s//g;\n\
	$Z=~s/\\s//g;\n	$TEMP=~s/\\s//g;\n	\n	$AT_ID=~s/\\
\s//g;\n	$RES_ID=~s/\\s//g;\n	$RES_NO=~s/\\s//g;\n\
\n	\n	if ( $HOM_CODE ne $MAIN_HOM_CODE){next;}\n	e\
lsif ( $already_read{$CHAIN}{$RES_ID}{$AT_ID}{$RES\
_NO}){next;}\n	else{$already_read{$CHAIN}{$RES_ID}\
{$AT_ID}{$RES_NO}=1;}\n	\n	$KEY=\"ALL\";\n\n      \
	if ( $RES_NO ==0){$start_at_zero=1;}\n\n	$RES_NO+\
=$start_at_zero;    \n	\n	if ( $current_chain ne $\
CHAIN)\n{\n	    $current_chain=$CHAIN;\n	    $pos=\
$current_residue=0;\n	    $offset=($coor_set)?($re\
al_start{$CHAIN}-1):0;\n	    if    ( $seq_field eq\
 \"SEQRES\"){@ref_seq=@{$complete_seq{$CHAIN}};}\n\
	    elsif ( $seq_field eq \"ATOM\")  {@ref_seq=@{\
$atom_seq{$CHAIN}};}\n}\n	\n	if ($current_residue \
!= $RES_NO)\n{\n	    $current_residue=$RES_NO;\n	 \
   if    ( $seq_field eq \"SEQRES\"){$pos=$current\
_residue;}\n	    elsif ( $seq_field eq \"ATOM\"){$\
pos++;}\n}\n	\n	\n	if ($n_atom==0 || $atom_list{$A\
T_ID}==1 || $atom_list{$KEY}==1)\n{ 	\n	    \n	   \
 $do_it=(!@c_chain || $hc_chain{$CHAIN} ||$hc_chai\
n{'LIGAND'} );\n	    \n	    $do_it= ($do_it==1) &&\
 ($coor_set==0 ||($pos>=$real_start{$CHAIN} && $po\
s<=$real_end{$CHAIN}));\n	    $do_it= ($do_it==1) \
&& ($delete_set==0 || $pos<$delete_start ||$pos>$d\
elete_end );\n	    if ($ligand==0 && $line_header \
eq \"HETATM\" ){$do_it=0;}\n	    if ($ligand_only=\
=1 && $line_header eq \"ATOM\" ){$do_it=0;}\n	    \
if ($ligand==1 && $line_header eq \"HETATM\" && $l\
igand_list{$RES_ID}==0 && $ligand_list{\"ALL\"}==0\
){$do_it=0;} \n	    \n	    \n	    if ( $do_it)\n{\\
n		$n++;\n		$out_pos=$pos;\n		\n	       if ( $dele\
te_set)\n{\n		  if ( $out_pos< $delete_start){;}\n\
		  else {$offset=$delete_end-$delete_start;}\n}  \
     \n	       \n	       if ( $numbering_out eq \"\
new\"){$out_pos-=$offset;}\n	       elsif ( $numbe\
ring_out eq \"old\"){$out_pos=$RES_NO;}\n	       \\
n       \n	       \n	       if ( $code==1){$RES_ID\
=$onelett{$molecule_type{$c}}->{$RES_ID};}\n	    \\
n	       if ($unfold)\n{\n		   $unfolded_x+=5;\n		\
   $X=$unfolded_x;\n		   $Y=0;\n		   $Z=0;\n		   $\
float=1;\n}\n	       else\n{\n		   $float=3;\n}\n\\
n	       if ( $MODE eq \"pdb\")\n{\n		   printf \"\
%-6s%5d %-4s %3s %s%4d    %8.3f%8.3f%8.3f  1.00 %5\
.2f\\n\",$line_header, $n, $RAW_AT_ID,$RES_ID,$CHA\
IN,$out_pos, $X, $Y, $Z,$TEMP;		  \n}\n	       els\
if ( $MODE eq \"simple\")\n{\n		    if ( $RES_ID e\
q \"\"){$RES_ID=\"X\";}\n		  printf \"%-6s %5s %s \
%2s %4d    %8.3f %8.3f %8.3f\\n\",$line_header, $A\
T_ID, $RES_ID,($CHAIN eq\"\" || $CHAIN eq \" \")?\\
"A\":$CHAIN,$out_pos, $X, $Y, $Z,$TEMP;\n}\n\n}\n}\
\n}\n}\nprint \"\\n\";\nclose($INFILE);\n\n\nif ( \
$error ne \"\") \n{$error=$error.\"\\nDiagnostic: \
   SEQRES and the residues in ATOM are probably In\
compatible\\n\";\n    $error=$error.  \"Recomendat\
ion: Rerun with '-fix 1' in order to ignore the SE\
QRES sequences\\n\";\n}\nif (!$nodiagnostic){print\
 STDERR $error;}\n&myexit ( $EXIT_SUCCESS);\n\nsub\
 is_released \n  {\n    my ($r);\n    my $in=@_[0]\
;\n    my $name=&remote_is_pdb_name ($in);\n    my\
 $hold=&remote_is_on_hold($in);\n    \n    $r=($na\
me && !$hold)?1:0;\n    return $r;\n  }\nsub remot\
e_is_pdb_name \n{\n    my $in=@_[0];\n    my ($ref\
_file, $pdb);\n    my ($value,$value1,$value2);\n \
   my $max=2;\n    \n    $ref_file=\"$cache/pdb_en\
try_type.txt\";\n    \n    if ( $in=~/[^\\w\\d\\:\\
\_]/){return 0;}\n    elsif ($no_remote_pdb_dir==1\
)\n      {\n	my $pdbdir=$ENV{'PDB_DIR'};\n	\n	my $\
r1=\"$pdbdir/derived_data/pdb_entry_type.txt\";\n	\
my $r2=$ref_file;\n	if    (-e $r1){$ref_file=$r1;}\
\n	elsif (-e $r2){$ref_file=$r2;}\n	else\n	  {\n	 \
   my $p=substr ($in,0, 4);\n	    add_warning (\"C\
annot find pdb_entry_type.txt;  $p is assumed to b\
e valid; add ftp://ftp.wwpdb.org/pub/pdb/derived_d\
ata/pdb_entry_type.txt in $cache to check name sta\
tus\");\n	  }\n      }\n    elsif ( !-e $ref_file \
|| (-M $ref_file)>$max || -z $ref_file)\n      {\n\
	&url2file(\"ftp://ftp.wwpdb.org/pub/pdb/derived_d\
ata/pdb_entry_type.txt\", $ref_file);\n      }\n  \
  $pdb=substr ($in,0, 4);\n    chomp(($value1=`gre\
p -c $pdb $ref_file`));\n    $pdb=lc($pdb);\n    c\
homp(($value2=`grep -c $pdb $ref_file`));\n    $va\
lue=($value1 || $value2)?1:0;\n    $value=($value>\
0)?1:0;\n    \n    return $value;\n  }\n\nsub pdb2\
model_type\n{\n    my $in=@_[0];\n    my ($ref_fil\
e, $pdb);\n    my ($value, $ret);\n\n    if ( $in=\
~/[^\\w\\d\\:\\_]/){return 0;}\n    $ref_file=\"$c\
ache/pdb_entry_type.txt\";\n    \n    if ( !-e $re\
f_file || (-M $ref_file)>2 || -z $ref_file)\n     \
 {\n	&url2file(\"ftp://ftp.wwpdb.org/pub/pdb/deriv\
ed_data/pdb_entry_type.txt\", $ref_file);\n      }\
\n    $pdb=substr ($in,0, 4);\n    $pdb=lc($pdb);\\
n    \n    chomp(($value=`grep $pdb $ref_file`));\\
n    \n    $value=~/^\\S+\\s+\\S+\\s+(\\S+)/;\n   \
 $ret=$1;\n    if ( $ret eq\"\"){return \"UNKNOWN\\
";}\n    \n    return $ret;\n  }\nsub remote_is_on\
_hold\n  {\n    my $in=@_[0];\n    my ($ref_file, \
$pdb);\n    my ($value1, $value2,$value);\n    \n \
   if ($no_rmote_pdb==1){return 0;}\n    elsif ( $\
in=~/[^\\w\\d\\:\\_]/){return 0;}\n    $ref_file=\\
"$cache/unreleased.xml\";\n    \n    if ( !-e $ref\
_file || (-M $ref_file)>2 || -z $ref_file)\n      \
{\n	&url2file(\"http://www.rcsb.org/pdb/rest/getUn\
released\",$ref_file);\n      }\n    \n    $pdb=su\
bstr ($in,0, 4);\n    chomp(($value1=`grep -c $pdb\
 $ref_file`));\n    $pdb=lc($pdb);\n    chomp(($va\
lue2=`grep -c $pdb $ref_file`));\n    $value=($val\
ue1 || $value2)?1:0;\n    $value=($value>0)?1:0;\n\
    return $value;\n  }\nsub is_pdb_file\n{\n    m\
y @arg=@_;\n\n    if ( !-e $arg[0]){return 0;}\n  \
  \n    $F=vfopen ($arg[0], \"r\");\n    while ( <\
$F>)\n{\n	if (/^HEADER/)\n{\n	    close $F;\n	    \
return 1;\n}\n	elsif ( /^SEQRES/)\n{\n	    close $\
F;\n	    return 1;\n}\n	elsif ( /^ATOM/)\n{\n	    \
close $F;\n	    return 1;\n}\n}\n    return 0;\n}\\
nsub get_pdb_id\n{\n    my $header_file=@_[0];\n  \
  my $id;\n    my $F= new FileHandle;\n    \n    \\
n    $F=vfopen (\"$header_file\", \"r\");\n\n    w\
hile ( <$F>)\n      {\n	if ( /HEADER/)\n	  {\n	   \
 if ($debug){print \"$_\";}\n	    $id=substr($_,62\
,4 );\n	    return $id;\n	  }\n      }\n    close \
($F);\n    \n    return \"\";\n}\n\nsub get_ligand\
_list\n{\n    my $pdb_file=@_[0];\n    my $chain;\\
n    my $ligand;\n    my %complete_ligand_list;\n \
   \n\n    $F=vfopen ($pdb_file, \"r\");\n    whil\
e ( <$F>)\n{\n	if ( /^HETATM/)\n{\n	    $line=$_;\\
n	    $chain=substr($line,21,1);\n	    $ligand=sub\
str($line,17,3);\n	    \n	    if (!$complete_ligan\
d_list{$chain}{$ligand})\n{\n		\n		$complete_ligan\
d_list{\"result\"}.=\"CHAIN $chain LIGAND $ligand\\
\n\";\n		$complete_ligand_list{$chain}{$ligand}=1;\
\n}\n}\n}\n    close ($F);\n    return %complete_l\
igand_list;\n}\n\nsub get_chain_list \n{\n    my $\
header_file;\n    my @chain_list;\n    my @list;\n\
    my $n_chains;\n    my %chain_hasch;\n    my $p\
db_file=@_[0];\n    my $c;\n    my %hasch;\n    my\
 $chain;\n  \n    \n    $F=vfopen ($pdb_file, \"r\\
");\n    while ( <$F>)\n{\n\n\n	if (/SEQRES\\s+\\d\
+\\s+(\\S+)/)\n	  {\n	    $chain = substr($_,11,1)\
;$chain=~s/\\s//g;if ( $chain eq \"\"){$chain=\" \\
";}\n	    if (!$hasch{$chain}){$hasch{$chain}=1;pu\
sh @chain_list, $chain;}\n	  }\n	if (/^ATOM/ || /^\
HETATM/)\n	  {\n	    $chain = substr($_,21,1); $ch\
ain=~s/\\s//g;if ( $chain eq \"\"){$chain=\" \";}\\
n	    if (!$hasch{$chain}){$hasch{$chain}=1;push @\
chain_list, $chain;}\n	  }\n      }\n\n\nclose ($F\
);\nif (!@chain_list)\n  {\n    @chain_list=(\"A\"\
);\n  }\n\n\nreturn @chain_list;\n}\n\nsub token_i\
s_in_list\n{\n\n    my @list=@_;\n    my $a;\n    \
\n    for ($a=1; $a<=$#list; $a++)\n{\n	if ( $list\
[$a] eq $list[0]){return $a;}\n}\n}\n\nsub pdb_nam\
e2name_and_chain \n{\n    my $pdb_file=@_[0];\n   \
 my $pdb_file_in;\n    my @array;\n    my $chain;\\
n    my $c;\n\n    $pdb_file_in=$pdb_file;\n\n    \
$pdb_file=~/^(.{4})/;$pdb_id=$1;\n    @array=($pdb\
_file=~/([\\w])/g);\n  \n  \n    $chain=uc ($array\
[4]);\n    $chain=($chain eq \"\")?\"FIRST\":$chai\
n;\n    \n    return ( $pdb_id, $chain);\n\n    if\
 ( $#array==3){return ($pdb_id, \"FIRST\");}\n    \
elsif ( $#array<4){ return ($pdb_id, \"\");}\n    \
else {return ( $pdb_id, $chain);}\n      \n    \n \
   \n}\nsub get_main_hom_code \n{\n    my $pdb_fil\
e=@_[0];\n    my %hom, $n, $best, $best_h;\n    op\
en (F, $pdb_file);\n    while (<F>)\n{\n	if ( $_=~\
/^ATOM/)\n{\n	    $h=substr ($_,26, 1);\n	    $n=+\
+$hom{$h};\n	    if ($n>$best)\n{\n		$best=$n;\n		\
$best_h=$h;\n}\n}\n}\n    close (F);\n    return $\
best_h;\n}\n\n\nsub get_pdb_file \n{\n    my ($pdb\
_file_in)=(@_);\n    my $result;\n    my @letter;\\
n    my @chain;\n    my $v;\n    my $pdb_file=$pdb\
_file_in;\n\n    $pdb_file=($pdb_file_in=~/\\S+_S_\
(\\S+)/)?$1:$pdb_file_in;\n    \n    if ($no_remot\
e_pdb_dir==0)\n      {\n	$no_remote_pdb_dir=1;\n	$\
result=get_pdb_file3 ($pdb_file);\n	$no_remote_pdb\
_dir=0;\n	if ( $result){return $result;}\n	else\n	\
  {\n	    \n	    lc ($pdb_file);\n	    $result=get\
_pdb_file3($pdb_file);\n	    return  $result;\n	  \
}\n      }\n    else\n      {\n	return get_pdb_fil\
e3 ($pdb_file);\n      }\n    \n  }\n\nsub get_pdb\
_file3 \n{\n    my $pdb_file_in=@_[0];\n    my $re\
sult;\n    my @letter;\n    my @chain;\n    my $lc\
file;\n    my $ucfile;\n    my $pdb_file=$pdb_file\
_in;\n    \n    $lcfile=lc $pdb_file;\n    $ucfile\
=uc $pdb_file;\n\n    if ( ($result=get_pdb_file2 \
($pdb_file))){return $result;}\n    \n\n    if ($l\
cfile ne $pdb_file && ($result=get_pdb_file2 ($lcf\
ile))){return $result;}\n    if ($ucfile ne $pdb_f\
ile && ($result=get_pdb_file2 ($ucfile))){return $\
result;}\n    \n   \n    \n    return \"\";\n}\nsu\
b get_pdb_file2\n{\n    my $pdb_file=@_[0];\n    m\
y $return_value;\n    \n    $return_value=\"\";\n \
   \n    if ( ($result=get_pdb_file1 ($pdb_file)))\
{$return_value=$result;}\n    elsif ( !($pdb_file=\
~/\\.pdb/) && !($pdb_file=~/\\.PDB/))\n{\n	if ( ($\
result=get_pdb_file1 (\"$pdb_file.pdb\"))){$return\
_value=$result;}\n	elsif ( ($result=get_pdb_file1 \
(\"$pdb_file.PDB\"))){$return_value=$result;}\n\n	\
elsif ( ($result=get_pdb_file1 (\"pdb$pdb_file.pdb\
\"))){$return_value=$result;}	\n	elsif ( ($result=\
get_pdb_file1 (\"pdb$pdb_file.PDB\"))){$return_val\
ue=$result;}\n	elsif ( ($result=get_pdb_file1 (\"P\
DB$pdb_file.PDB\"))){$return_value=$result;}\n	els\
if ( ($result=get_pdb_file1 (\"PDB$pdb_file.pdb\")\
)){$return_value=$result;}\n	\n	\n	elsif ( ($resul\
t=get_pdb_file1 (\"$pdb_file.ent\"))){$return_valu\
e=$result;}\n	elsif ( ($result=get_pdb_file1 (\"pd\
b$pdb_file.ent\"))){$return_value=$result;}\n	elsi\
f ( ($result=get_pdb_file1 (\"PDB$pdb_file.ent\"))\
){$return_value=$result;}\n\n	elsif ( ($result=get\
_pdb_file1 (\"$pdb_file.ENT\"))){$return_value=$re\
sult;}\n	elsif ( ($result=get_pdb_file1 (\"pdb$pdb\
_file.ENT\"))){$return_value=$result;}\n	elsif ( (\
$result=get_pdb_file1 (\"PDB$pdb_file.ENT\"))){$re\
turn_value=$result;}\n	\n	\n	\n}\n    return $retu\
rn_value;\n}\n    \nsub get_pdb_file1\n{\n    my (\
$pdb_file)=(@_);\n    my $return_value;\n    \n\n \
   $return_value=\"\";\n    if ( ($result=get_pdb_\
file0 ($pdb_file))){$return_value=$result;}\n    e\
lsif ( ($result=get_pdb_file0 (\"$pdb_file.Z\"))){\
$return_value=$result;}\n    elsif ( ($result=get_\
pdb_file0 (\"$pdb_file.gz\"))){$return_value=$resu\
lt;}\n    elsif ( ($result=get_pdb_file0 (\"$pdb_f\
ile.GZ\"))){$return_value=$result;}\n    return $r\
eturn_value;\n}\nsub get_pdb_file0 \n{ \n    my ($\
pdb_file, $attempt)=(@_);\n    my $pdb_file=@_[0];\
\n    my $tmp_pdb_file;    \n    my $return_value;\
\n\n    if ( !$attempt){$attempt=1;}\n    \n    $l\
ocal_pdb_file=\"$pdb_file\";\n    if ( $local_pdb_\
file eq \"\")\n{\n	$tmp_pdb_file=vtmpnam();\n	open\
 F, \">$tmp_pdb_file\";\n	\n	while (<STDIN>){print\
 F \"$_\";}\n	close (F);\n	\n	if (-e $tmp_pdb_file\
 && &is_pdb_file ( $local_pdb_file))\n{return $tmp\
_pdb_file;}\n}\n\n    $local_pdb_file=\"$pdb_file\\
";\n    &debug_print (\"\\nTry access local file: \
$local_pdb_file\");\n    \n    $local_pdb_file=&ch\
eck_pdb_file4compression ($local_pdb_file);\n    i\
f ( -e $local_pdb_file && (&is_pdb_file ($local_pd\
b_file) || $force_pdb))\n{\n	&debug_print ( \"\\n\\
\tIs in Current Dir\");\n	$tmp_pdb_file=vtmpnam();\
\n	`cp $local_pdb_file $tmp_pdb_file`;\n	return $t\
mp_pdb_file;\n}\n    else\n{\n	&debug_print (\"\\n\
\\tFile Not in Current Dir\");\n}\n\n    if ($pdb_\
file=~/^pdb/||$pdb_file=~/^PDB/){$pdb_div=substr (\
$pdb_file, 4, 2);}\n    else\n{\n	  $pdb_div=subst\
r ($pdb_file, 1, 2);\n}\n    $local_pdb_file=\"$pd\
b_dir/$pdb_div/$pdb_file\";\n    $local_pdb_file=&\
check_pdb_file4compression ( $local_pdb_file);\n  \
  &debug_print (\"\\nTry access file From PDB_DIR:\
 $local_pdb_file\");\n    if ($pdb_dir && -e $loca\
l_pdb_file && &is_pdb_file ($local_pdb_file))\n{\n\
	&debug_print ( \"\\n\\tIs in Local PDB DIR\");\n	\
$tmp_pdb_file=vtmpnam();\n	`cp $local_pdb_file $tm\
p_pdb_file`;\n	return $tmp_pdb_file;\n}\n\n    $lo\
cal_pdb_file=\"$pdb_dir/$pdb_file\";\n    $local_p\
db_file=&check_pdb_file4compression ( $local_pdb_f\
ile);\n    &debug_print (\"\\nTry access file From\
 PDB_DIR: local_pdb_file\");\n    if ($pdb_dir && \
-e $local_pdb_file && &is_pdb_file ($local_pdb_fil\
e))\n{\n	&debug_print ( \"\\n\\tIs in Local PDB DI\
R\");\n	$tmp_pdb_file=vtmpnam();\n	`cp $local_pdb_\
file $tmp_pdb_file`;\n	return $tmp_pdb_file;\n}\n\\
n    $local_pdb_file=\"$pdb_dir$pdb_file\";\n    $\
local_pdb_file=&check_pdb_file4compression ( $loca\
l_pdb_file);\n    &debug_print (\"\\nTry access fi\
le From PDB_DIR: $local_pdb_file\");\n    if ($pdb\
_dir && -e $local_pdb_file && &is_pdb_file ($local\
_pdb_file))\n{\n	&debug_print ( \"\\n\\tIs in Loca\
l PDB DIR\");\n	$tmp_pdb_file=vtmpnam();\n	`cp $lo\
cal_pdb_file $tmp_pdb_file`;\n	return $tmp_pdb_fil\
e;\n}\n    else\n{&debug_print ( \"\\n\\tNot In Lo\
cal Pdb Dir\");}\n\n    if ($cache ne \"NO\" && $c\
ache ne \"no\")\n{\n\n	$local_pdb_file=\"$cache/$p\
db_file\";\n	$local_pdb_file=&check_pdb_file4compr\
ession ( $local_pdb_file);\n	&debug_print(\"\\nTry\
 access file From Cache: $local_pdb_file\");\n	if \
(-e $local_pdb_file && &is_pdb_file ($local_pdb_fi\
le))\n{\n	    &debug_print ( \"\\n\\tIs in T-Coffe\
e Cache\");\n	    $tmp_pdb_file=vtmpnam();\n	    `\
cp $local_pdb_file $tmp_pdb_file`;\n	    return $t\
mp_pdb_file;\n}\n	else{&debug_print ( \"\\n\\tNot \
in Cache Dir\");}\n}\n\nif (!$no_remote_pdb_dir) \\
n  {\n    my $value=&is_released ($pdb_file);\n   \
 my $return_value=\"\";\n    if ($value==1)\n     \
 {\n	\n	&debug_print (\"\\n***********************\
******************************\\nTry Remote Access\
 for $pdb_file\");\n	$tmp_pdb_file=vtmpnam();\n	$n\
etcommand=$netaddress;\n	$netcommand=~s/%%/$pdb_fi\
le/g;\n	&url2file(\"$netcommand\", \"$tmp_pdb_file\
.$netcompression\");\n	&debug_print(\"\\nREMOTE: $\
netcommand\\n\");\n	\n	$compressed_tmp_file_name=\\
"$tmp_pdb_file.$netcompression\";\n	\n	if ($netcom\
pression && -B $compressed_tmp_file_name)\n	  {\n	\
    my $r;\n	    &debug_print (\"\\n\\tFile Found \
Remotely\");\n	    if (($r=safe_system ( \"$netcom\
pression_pg $compressed_tmp_file_name\")!=$EXIT_SU\
CCESS) && $attempts<5)\n	      {\n		&debug_print (\
\"\\n\\tProper Download Failed Try again\");\n		un\
link $compressed_tmp_file_name;\n		print \"\\nFail\
ed to Download $compressed_tmp_file_name. New Atte\
mpt $attempt/5\\n\";\n		return &get_pdb_file0($pdb\
_file, $attempt+1);\n	      }\n	    elsif ($r== $E\
XIT_SUCCESS)\n	      {\n		&debug_print (\"\\n\\tPr\
oper Download Succeeded \");\n		$return_value=$tmp\
_pdb_file;\n	      }\n	    else\n	      {\n		&debu\
g_print (\"\\n\\tProper Download Failed \");\n		&d\
ebug_print (\"\\nFile Not Found Remotely\");\n		un\
link $compressed_tmp_file_name;\n	      }\n	  }\n	\
else\n	  {\n\n	    &debug_print (\"\\nFile Not Fou\
nd Remotely\");\n	    unlink $compressed_tmp_file_\
name;\n	  }\n	#Update cache if required\n	if ($cac\
he ne \"no\" && $cache ne \"update\" && -e $return\
_value)\n	  {\n	    `cp $return_value $cache/$pdb_\
file.pdb`;\n	    #`t_coffee -other_pg clean_cache.\
pl -file $pdb_file.pdb -dir $cache`;\n	  }\n      \
}\n    &debug_print (\"\\nRemote Download Finished\
\");\n    return $return_value;\n  }\nreturn \"\";\
\n}\n\nsub check_pdb_file4compression \n{\n    my \
$file=@_[0];\n    my $tmp;\n    my $r;\n    \n    \
$tmp=&vtmpnam();\n    if (-e $tmp){unlink $tmp;}\n\
    \n    $file=~s/\\/\\//\\//g;\n    if    (-B $f\
ile && ($file=~/\\.Z/)) {`cp $file $tmp.Z`;`rm $tm\
p`;`gunzip $tmp.Z $SILENT`;$r=$tmp;}\n    elsif (-\
B $file && ($file=~/\\.gz/)){`cp $file $tmp.gz`;`g\
unzip $tmp.gz $SILENT`;return $r=$tmp;}\n    elsif\
 (-B $file ){`cp $file $tmp.gz`;`gunzip $tmp.gz $S\
ILENT`;$r=$tmp;}\n    elsif ( -e $file ) {$r= $fil\
e;}\n    elsif ( -e \"$file.gz\" ){ `cp $file.gz $\
tmp.gz`;`gunzip     $tmp.gz $SILENT`;$r=$tmp;}    \
\n    elsif ( -e \"$file.Z\") {`cp $file.Z  $tmp.Z\
`; `gunzip $tmp.Z $SILENT`;$r=$tmp;}\n    else  {$\
r= $file;}\n\n    if ( -e \"$tmp.Z\"){unlink \"$tm\
p.Z\";}\n    if ( -e \"$tmp.gz\"){unlink \"$tmp.gz\
\";}\n    \n    return $r;\n    \n}\n\n\n\n\n\n   \
 \n\n\n\n\n\n\n\nsub vfopen \n{\n    my $file=@_[0\
];\n    my $mode=@_[1];\n    my $tmp;\n    my $F =\
 new FileHandle;\n    \n    \n    $tmp=$file;\n	\n\
    \n    if ( $mode eq \"r\" && !-e $file){ myexi\
t(flush_error (\"Cannot open file $file\"));}\n   \
 elsif ($mode eq \"w\"){$tmp=\">$file\";}\n    els\
if ($mode eq \"a\"){$tmp=\">>$file\";}\n    \n    \
\n    open ($F,$tmp);\n    return $F;\n}\nsub debu\
g_print\n{\n    my $message =@_[0];\n    if ($debu\
g){print STDERR \"NO_REMOTE_PDB_DIR: $no_remote_pd\
b_dir - $message [DEBUG:extract_from_pdb]\";}\n   \
 return;\n}\nsub is_aa \n{\n    my ($aa, $chain) =\
@_;\n\n    my $one;\n    my $trhee;\n    \n    if \
( $onelett{$molecule_type{$chain}}->{$aa} eq 'X' |\
| !$onelett{$molecule_type{$chain}}->{$aa} ){retur\
n '';}\n    else\n      {\n	$one=$onelett{$molecul\
e_type{$chain}}->{$aa};\n\n	$three=$threelett{$mol\
ecule_type{$chain}}->{$one};\n	\n\n	return $three;\
\n      }\n  }\n\n\n\n\n\nsub url2file\n{\n    my \
($address, $out, $wget_arg, $curl_arg)=(@_);\n    \
my ($pg, $flag, $r, $arg, $count);\n    \n    if (\
!$CONFIGURATION){&check_configuration (\"wget\", \\
"INTERNET\", \"gzip\");$CONFIGURATION=1;}\n    \n \
   if (&pg_is_installed (\"wget\"))   {$pg=\"wget\\
"; $flag=\"-O\";$arg=$wget_arg;}\n    elsif (&pg_i\
s_installed (\"curl\")){$pg=\"curl\"; $flag=\"-o\"\
;$arg=$curl_arg;}\n    return safe_system (\"$pg $\
flag$out $address >/dev/null 2>/dev/null\");\n\n}\\
n\n\n\n\nsub pdbfile2chaintype\n  {\n    my $file=\
@_[0];\n    my %ct;\n    my $F;\n    \n    $F=vfop\
en ($file, \"r\");\n    while (<$F>)\n      {\n	my\
 $line=$_;\n	if ($line =~/^ATOM/)\n	  {\n	    my $\
C=substr($line,21,1);\n	    if (!$ct{$C})\n	      \
{	\n		my $r=substr($line,17,3);\n		$r=~s/\\s+//;\n\
		if (length ($r)==1){$ct{$C}=\"R\";}\n		elsif (le\
ngth ($r)==2){$ct{$C}=\"D\";}\n		elsif (length ($r\
)==3){$ct{$C}=\"P\";}\n		else \n		  {\n		    myexi\
t(flush_error(\"ERROR: Could not read RES_ID field\
 in file $file\"));\n		  }\n	      }\n	  }\n      \
}\n    close ($F);\n    return %ct;\n  }\n   \n   \
 \n\n\n\nsub fill_threelett_RNA\n{\n\n	my %threele\
tt=(\n	'A', '  A',\n	'T', '  T',\n	'U', '  U',\n	'\
C', '  C',\n	'G', '  G',\n	'I', '  I', #Inosine\n	\
);\n	\n	return %threelett;\n\n}\n\n\nsub fill_onel\
ett_RNA\n{\n	my   %onelett=(\n	'  A' => 'A',\n	'  \
T' => 'T',\n	'  U' => 'U',\n	'  C' => 'C',\n	'  G'\
 => 'G',\n	'CSL' => 'X',\n	'UMS' => 'X',\n	'  I' =\
> 'I',\n	'A' => 'A',\n	'T' => 'T',\n	'U' => 'U',\n\
	'C' => 'C',\n	'G' => 'G',\n	'I' => 'I',\n	);\n\n	\
return %onelett;\n\n}\n\n\nsub fill_onelett_DNA\n{\
\n	my   %onelett=(\n	' DA', 'A',\n	' DT', 'T',\n	'\
 DC', 'C',\n	' DG', 'G',\n	'DA', 'A',\n	'DT', 'T',\
\n	'DC', 'C',\n	'DG', 'G',\n	);\n\n	return %onelet\
t;\n\n}\n\nsub fill_threelett_DNA\n{\n\n	my %three\
lett=(\n	'A', ' DA',\n	'T', ' DT',\n	'C', ' DC',\n\
	'G', ' DG',\n	);\n\n	return %threelett;\n\n}\n\n\\
n\n\nsub fill_threelett_prot\n{  \n  my %threelett\
;\n\n  %threelett=(\n'A', 'ALA',\n'C', 'CYS',\n'D'\
, 'ASP',\n'E', 'GLU',\n'F', 'PHE',\n'G', 'GLY',\n'\
H', 'HIS',\n'I', 'ILE',\n'K', 'LYS',\n'L', 'LEU',\\
n'N', 'ASN',\n'M', 'MET',\n'P', 'PRO',\n'Q', 'GLN'\
,\n'R', 'ARG',\n'S', 'SER',\n'T', 'THR',\n'V', 'VA\
L',\n'W', 'TRP',\n'Y', 'TYR',\n);\n\nreturn %three\
lett;\n\n\n}\n\nsub fill_onelett_prot\n{\n    my %\
onelett;\n    \n    %onelett=(\n\n'10A', 'X',\n'11\
O', 'X',\n'12A', 'X',\n'13P', 'X',\n'13R', 'X',\n'\
13S', 'X',\n'14W', 'X',\n'15P', 'X',\n'16A', 'X',\\
n'16G', 'X',\n'1AN', 'X',\n'1AP', 'X',\n'1AR', 'X'\
,\n'1BH', 'X',\n'1BO', 'X',\n'1C5', 'X',\n'1CU', '\
X',\n'1DA', 'X',\n'1GL', 'X',\n'1GN', 'X',\n'1IN',\
 'X',\n'1LU', 'L',\n'1MA', 'X',\n'1MC', 'X',\n'1MG\
', 'X',\n'1MZ', 'X',\n'1NA', 'X',\n'1NB', 'X',\n'1\
NI', 'X',\n'1PA', 'A',\n'1PC', 'X',\n'1PE', 'X',\n\
'1PG', 'X',\n'1PI', 'A',\n'1PM', 'X',\n'1PN', 'X',\
\n'1PU', 'X',\n'1PY', 'X',\n'1UN', 'X',\n'24T', 'X\
',\n'25T', 'X',\n'26P', 'X',\n'2AB', 'X',\n'2AM', \
'X',\n'2AN', 'X',\n'2AP', 'X',\n'2AR', 'X',\n'2AS'\
, 'D',\n'2BL', 'X',\n'2BM', 'X',\n'2CP', 'X',\n'2D\
A', 'X',\n'2DG', 'X',\n'2DP', 'X',\n'2DT', 'X',\n'\
2EP', 'X',\n'2EZ', 'X',\n'2FG', 'X',\n'2FL', 'X',\\
n'2FP', 'X',\n'2FU', 'X',\n'2GL', 'X',\n'2GP', 'X'\
,\n'2HP', 'X',\n'2IB', 'X',\n'2IP', 'X',\n'2LU', '\
L',\n'2MA', 'X',\n'2MD', 'X',\n'2ME', 'X',\n'2MG',\
 'X',\n'2ML', 'L',\n'2MO', 'X',\n'2MR', 'R',\n'2MU\
', 'X',\n'2MZ', 'X',\n'2NO', 'X',\n'2NP', 'X',\n'2\
OG', 'X',\n'2PA', 'X',\n'2PC', 'X',\n'2PE', 'X',\n\
'2PG', 'X',\n'2PH', 'X',\n'2PI', 'X',\n'2PL', 'X',\
\n'2PP', 'X',\n'2PU', 'X',\n'2SI', 'X',\n'2TB', 'X\
',\n'34C', 'X',\n'35G', 'X',\n'3AA', 'X',\n'3AD', \
'X',\n'3AH', 'H',\n'3AN', 'X',\n'3AP', 'X',\n'3AT'\
, 'X',\n'3BT', 'X',\n'3CH', 'X',\n'3CN', 'X',\n'3C\
O', 'X',\n'3CP', 'X',\n'3DR', 'X',\n'3EP', 'X',\n'\
3FM', 'X',\n'3GA', 'X',\n'3GP', 'X',\n'3HB', 'X',\\
n'3HC', 'X',\n'3HP', 'X',\n'3IB', 'X',\n'3ID', 'X'\
,\n'3IN', 'X',\n'3MA', 'X',\n'3MB', 'X',\n'3MC', '\
X',\n'3MD', 'D',\n'3MF', 'X',\n'3MP', 'X',\n'3MT',\
 'X',\n'3OL', 'X',\n'3PA', 'X',\n'3PG', 'X',\n'3PO\
', 'X',\n'3PP', 'X',\n'3PY', 'X',\n'49A', 'X',\n'4\
AB', 'X',\n'4AM', 'X',\n'4AN', 'X',\n'4AP', 'X',\n\
'4BA', 'X',\n'4BT', 'X',\n'4CA', 'X',\n'4CO', 'X',\
\n'4HP', 'X',\n'4IP', 'X',\n'4MO', 'X',\n'4MV', 'X\
',\n'4MZ', 'X',\n'4NC', 'X',\n'4NP', 'X',\n'4OX', \
'X',\n'4PB', 'X',\n'4PN', 'X',\n'4PP', 'X',\n'4SC'\
, 'X',\n'4SU', 'X',\n'4TB', 'X',\n'55C', 'X',\n'5A\
D', 'X',\n'5AN', 'X',\n'5AT', 'X',\n'5CM', 'X',\n'\
5GP', 'X',\n'5HP', 'E',\n'5HT', 'X',\n'5IT', 'X',\\
n'5IU', 'X',\n'5MB', 'X',\n'5MC', 'X',\n'5MD', 'X'\
,\n'5MP', 'X',\n'5MU', 'X',\n'5NC', 'X',\n'5OB', '\
X',\n'5PA', 'X',\n'5PV', 'X',\n'6AB', 'X',\n'6CT',\
 'X',\n'6HA', 'X',\n'6HC', 'X',\n'6HG', 'X',\n'6HT\
', 'X',\n'6IN', 'X',\n'6MO', 'X',\n'6MP', 'X',\n'6\
PG', 'X',\n'6WO', 'X',\n'70U', 'X',\n'7DG', 'X',\n\
'7HP', 'X',\n'7I2', 'X',\n'7MG', 'X',\n'7MQ', 'X',\
\n'7NI', 'X',\n'87Y', 'X',\n'8AD', 'X',\n'8BR', 'X\
',\n'8IG', 'X',\n'8IN', 'X',\n'8OG', 'X',\n'95A', \
'X',\n'9AD', 'X',\n'9AM', 'X',\n'9AP', 'X',\n'9DG'\
, 'X',\n'9DI', 'X',\n'9HX', 'X',\n'9OH', 'X',\n'9T\
A', 'X',\n'A12', 'X',\n'A15', 'X',\n'A23', 'X',\n'\
A24', 'X',\n'A26', 'X',\n'A2G', 'X',\n'A2P', 'X',\\
n'A32', 'X',\n'A3P', 'X',\n'A4P', 'X',\n'A5P', 'X'\
,\n'A70', 'X',\n'A76', 'X',\n'A77', 'X',\n'A78', '\
X',\n'A79', 'X',\n'A80', 'X',\n'A85', 'X',\n'A88',\
 'X',\n'A9A', 'X',\n'AA3', 'X',\n'AA4', 'X',\n'AA6\
', 'X',\n'AAA', 'X',\n'AAB', 'X',\n'AAC', 'X',\n'A\
AE', 'X',\n'AAG', 'R',\n'AAH', 'X',\n'AAM', 'X',\n\
'AAN', 'X',\n'AAP', 'X',\n'AAR', 'R',\n'AAS', 'X',\
\n'AAT', 'X',\n'ABA', 'X',\n'ABC', 'X',\n'ABD', 'X\
',\n'ABE', 'X',\n'ABH', 'X',\n'ABI', 'X',\n'ABK', \
'X',\n'ABM', 'X',\n'ABN', 'X',\n'ABP', 'X',\n'ABR'\
, 'X',\n'ABS', 'X',\n'ABU', 'X',\n'AC1', 'X',\n'AC\
2', 'X',\n'ACA', 'X',\n'ACB', 'D',\n'ACC', 'C',\n'\
ACD', 'X',\n'ACE', 'X',\n'ACH', 'X',\n'ACI', 'X',\\
n'ACL', 'R',\n'ACM', 'X',\n'ACN', 'X',\n'ACO', 'X'\
,\n'ACP', 'X',\n'ACQ', 'X',\n'ACR', 'X',\n'ACS', '\
X',\n'ACT', 'X',\n'ACV', 'V',\n'ACX', 'X',\n'ACY',\
 'X',\n'AD2', 'X',\n'AD3', 'X',\n'ADC', 'X',\n'ADD\
', 'X',\n'ADE', 'X',\n'ADH', 'X',\n'ADI', 'X',\n'A\
DM', 'X',\n'ADN', 'X',\n'ADP', 'X',\n'ADQ', 'X',\n\
'ADR', 'X',\n'ADS', 'X',\n'ADT', 'X',\n'ADU', 'X',\
\n'ADW', 'X',\n'ADX', 'X',\n'AE2', 'X',\n'AEA', 'X\
',\n'AEB', 'X',\n'AEI', 'D',\n'AEN', 'X',\n'AET', \
'T',\n'AF1', 'X',\n'AF3', 'X',\n'AFA', 'D',\n'AFP'\
, 'X',\n'AG7', 'X',\n'AGB', 'X',\n'AGF', 'X',\n'AG\
L', 'X',\n'AGM', 'R',\n'AGN', 'X',\n'AGP', 'X',\n'\
AGS', 'X',\n'AGU', 'X',\n'AH0', 'X',\n'AH1', 'X',\\
n'AHA', 'X',\n'AHB', 'D',\n'AHC', 'X',\n'AHF', 'X'\
,\n'AHG', 'X',\n'AHH', 'X',\n'AHM', 'X',\n'AHO', '\
X',\n'AHP', 'X',\n'AHS', 'X',\n'AHT', 'Y',\n'AHU',\
 'X',\n'AHX', 'X',\n'AI1', 'X',\n'AI2', 'X',\n'AIB\
', 'X',\n'AIC', 'X',\n'AIM', 'X',\n'AIP', 'X',\n'A\
IQ', 'X',\n'AIR', 'X',\n'AJ3', 'X',\n'AKB', 'X',\n\
'AKG', 'X',\n'AKR', 'X',\n'AL1', 'X',\n'AL2', 'X',\
\n'AL3', 'X',\n'AL4', 'X',\n'AL5', 'X',\n'AL6', 'X\
',\n'AL7', 'X',\n'AL8', 'X',\n'AL9', 'X',\n'ALA', \
'A',\n'ALB', 'X',\n'ALC', 'X',\n'ALD', 'L',\n'ALE'\
, 'X',\n'ALF', 'X',\n'ALG', 'X',\n'ALL', 'X',\n'AL\
M', 'A',\n'ALN', 'A',\n'ALO', 'T',\n'ALP', 'X',\n'\
ALQ', 'X',\n'ALR', 'X',\n'ALS', 'X',\n'ALT', 'A',\\
n'ALY', 'K',\n'ALZ', 'X',\n'AMA', 'X',\n'AMB', 'X'\
,\n'AMC', 'X',\n'AMD', 'X',\n'AMG', 'X',\n'AMH', '\
X',\n'AMI', 'X',\n'AML', 'X',\n'AMN', 'X',\n'AMO',\
 'X',\n'AMP', 'X',\n'AMQ', 'X',\n'AMR', 'X',\n'AMS\
', 'X',\n'AMT', 'X',\n'AMU', 'X',\n'AMW', 'X',\n'A\
MX', 'X',\n'AMY', 'X',\n'ANA', 'X',\n'ANB', 'X',\n\
'ANC', 'X',\n'AND', 'X',\n'ANE', 'X',\n'ANI', 'X',\
\n'ANL', 'X',\n'ANO', 'X',\n'ANP', 'X',\n'ANS', 'X\
',\n'ANT', 'X',\n'AOE', 'X',\n'AOP', 'X',\n'AP1', \
'X',\n'AP2', 'X',\n'AP3', 'X',\n'AP4', 'X',\n'AP5'\
, 'X',\n'AP6', 'X',\n'APA', 'X',\n'APB', 'X',\n'AP\
C', 'X',\n'APE', 'F',\n'APF', 'X',\n'APG', 'X',\n'\
APH', 'A',\n'API', 'X',\n'APL', 'X',\n'APM', 'X',\\
n'APN', 'G',\n'APP', 'X',\n'APQ', 'X',\n'APR', 'X'\
,\n'APS', 'X',\n'APT', 'X',\n'APU', 'X',\n'APX', '\
X',\n'APY', 'X',\n'APZ', 'X',\n'AQS', 'X',\n'AR1',\
 'X',\n'AR2', 'X',\n'ARA', 'X',\n'ARB', 'X',\n'ARC\
', 'X',\n'ARD', 'X',\n'ARG', 'R',\n'ARH', 'X',\n'A\
RI', 'X',\n'ARM', 'R',\n'ARN', 'X',\n'ARO', 'R',\n\
'ARP', 'X',\n'ARQ', 'X',\n'ARS', 'X',\n'AS1', 'R',\
\n'AS2', 'X',\n'ASA', 'D',\n'ASB', 'D',\n'ASC', 'X\
',\n'ASD', 'X',\n'ASE', 'X',\n'ASF', 'X',\n'ASI', \
'X',\n'ASK', 'D',\n'ASL', 'X',\n'ASM', 'N',\n'ASO'\
, 'X',\n'ASP', 'D',\n'ASQ', 'X',\n'ASU', 'X',\n'AT\
A', 'X',\n'ATC', 'X',\n'ATD', 'X',\n'ATF', 'X',\n'\
ATG', 'X',\n'ATH', 'X',\n'ATM', 'X',\n'ATO', 'X',\\
n'ATP', 'X',\n'ATQ', 'X',\n'ATR', 'X',\n'ATT', 'X'\
,\n'ATY', 'X',\n'ATZ', 'X',\n'AUC', 'X',\n'AUR', '\
X',\n'AVG', 'X',\n'AXP', 'X',\n'AYA', 'A',\n'AZ2',\
 'X',\n'AZA', 'X',\n'AZC', 'X',\n'AZD', 'X',\n'AZE\
', 'X',\n'AZI', 'X',\n'AZL', 'X',\n'AZM', 'X',\n'A\
ZR', 'X',\n'AZT', 'X',\n'B12', 'X',\n'B1F', 'F',\n\
'B2A', 'A',\n'B2F', 'F',\n'B2I', 'I',\n'B2V', 'V',\
\n'B3I', 'X',\n'B3P', 'X',\n'B7G', 'X',\n'B96', 'X\
',\n'B9A', 'X',\n'BA1', 'X',\n'BAA', 'X',\n'BAB', \
'X',\n'BAC', 'X',\n'BAF', 'X',\n'BAH', 'X',\n'BAI'\
, 'X',\n'BAK', 'X',\n'BAL', 'A',\n'BAM', 'X',\n'BA\
O', 'X',\n'BAP', 'X',\n'BAR', 'X',\n'BAS', 'X',\n'\
BAT', 'F',\n'BAY', 'X',\n'BAZ', 'X',\n'BB1', 'X',\\
n'BB2', 'X',\n'BBA', 'X',\n'BBH', 'X',\n'BBS', 'X'\
,\n'BBT', 'X',\n'BBZ', 'X',\n'BCA', 'X',\n'BCB', '\
X',\n'BCC', 'X',\n'BCD', 'X',\n'BCL', 'X',\n'BCN',\
 'X',\n'BCR', 'X',\n'BCS', 'C',\n'BCT', 'X',\n'BCY\
', 'X',\n'BCZ', 'X',\n'BDA', 'X',\n'BDG', 'X',\n'B\
DK', 'X',\n'BDM', 'X',\n'BDN', 'X',\n'BDS', 'X',\n\
'BE1', 'X',\n'BE2', 'X',\n'BEA', 'X',\n'BEF', 'X',\
\n'BEN', 'X',\n'BEO', 'X',\n'BEP', 'X',\n'BER', 'X\
',\n'BES', 'X',\n'BET', 'X',\n'BEZ', 'X',\n'BF2', \
'X',\n'BFA', 'X',\n'BFD', 'X',\n'BFP', 'X',\n'BFS'\
, 'X',\n'BFU', 'X',\n'BG6', 'X',\n'BGF', 'X',\n'BG\
G', 'X',\n'BGL', 'X',\n'BGN', 'X',\n'BGP', 'X',\n'\
BGX', 'X',\n'BH4', 'X',\n'BHA', 'X',\n'BHC', 'X',\\
n'BHD', 'D',\n'BHO', 'X',\n'BHS', 'X',\n'BIC', 'X'\
,\n'BIN', 'X',\n'BIO', 'X',\n'BIP', 'X',\n'BIS', '\
X',\n'BIZ', 'X',\n'BJH', 'X',\n'BJI', 'X',\n'BJP',\
 'X',\n'BLA', 'X',\n'BLB', 'X',\n'BLE', 'L',\n'BLG\
', 'P',\n'BLI', 'X',\n'BLM', 'X',\n'BLV', 'X',\n'B\
LY', 'K',\n'BM1', 'X',\n'BM2', 'X',\n'BM5', 'X',\n\
'BM9', 'X',\n'BMA', 'X',\n'BMD', 'X',\n'BME', 'X',\
\n'BMP', 'X',\n'BMQ', 'X',\n'BMS', 'X',\n'BMT', 'T\
',\n'BMU', 'X',\n'BMY', 'X',\n'BMZ', 'X',\n'BNA', \
'X',\n'BNG', 'X',\n'BNI', 'X',\n'BNN', 'F',\n'BNO'\
, 'L',\n'BNS', 'X',\n'BNZ', 'X',\n'BO3', 'X',\n'BO\
4', 'X',\n'BOC', 'X',\n'BOG', 'X',\n'BOM', 'X',\n'\
BOT', 'X',\n'BOX', 'X',\n'BOZ', 'X',\n'BPA', 'X',\\
n'BPB', 'X',\n'BPD', 'X',\n'BPG', 'X',\n'BPH', 'X'\
,\n'BPI', 'X',\n'BPJ', 'X',\n'BPM', 'X',\n'BPN', '\
X',\n'BPO', 'X',\n'BPP', 'X',\n'BPT', 'X',\n'BPY',\
 'X',\n'BRB', 'X',\n'BRC', 'X',\n'BRE', 'X',\n'BRI\
', 'X',\n'BRL', 'X',\n'BRM', 'X',\n'BRN', 'X',\n'B\
RO', 'X',\n'BRS', 'X',\n'BRU', 'X',\n'BRZ', 'X',\n\
'BSB', 'X',\n'BSI', 'X',\n'BSP', 'X',\n'BT1', 'X',\
\n'BT2', 'X',\n'BT3', 'X',\n'BTA', 'L',\n'BTB', 'X\
',\n'BTC', 'C',\n'BTD', 'X',\n'BTN', 'X',\n'BTP', \
'X',\n'BTR', 'W',\n'BU1', 'X',\n'BUA', 'X',\n'BUB'\
, 'X',\n'BUC', 'X',\n'BUG', 'X',\n'BUL', 'X',\n'BU\
M', 'X',\n'BUQ', 'X',\n'BUT', 'X',\n'BVD', 'X',\n'\
BX3', 'X',\n'BYS', 'X',\n'BZ1', 'X',\n'BZA', 'X',\\
n'BZB', 'X',\n'BZC', 'X',\n'BZD', 'X',\n'BZF', 'X'\
,\n'BZI', 'X',\n'BZM', 'X',\n'BZO', 'X',\n'BZP', '\
X',\n'BZQ', 'X',\n'BZS', 'X',\n'BZT', 'X',\n'C02',\
 'X',\n'C11', 'X',\n'C1O', 'X',\n'C20', 'X',\n'C24\
', 'X',\n'C2F', 'X',\n'C2O', 'X',\n'C2P', 'X',\n'C\
3M', 'X',\n'C3P', 'X',\n'C3X', 'X',\n'C48', 'X',\n\
'C4M', 'X',\n'C4X', 'X',\n'C5C', 'X',\n'C5M', 'X',\
\n'C5P', 'X',\n'C5X', 'X',\n'C60', 'X',\n'C6C', 'X\
',\n'C6M', 'X',\n'C78', 'X',\n'C8E', 'X',\n'CA3', \
'X',\n'CA5', 'X',\n'CAA', 'X',\n'CAB', 'X',\n'CAC'\
, 'X',\n'CAD', 'X',\n'CAF', 'C',\n'CAG', 'X',\n'CA\
H', 'X',\n'CAL', 'X',\n'CAM', 'X',\n'CAN', 'X',\n'\
CAO', 'X',\n'CAP', 'X',\n'CAQ', 'X',\n'CAR', 'X',\\
n'CAS', 'C',\n'CAT', 'X',\n'CAV', 'X',\n'CAY', 'C'\
,\n'CAZ', 'X',\n'CB3', 'X',\n'CB4', 'X',\n'CBA', '\
X',\n'CBD', 'X',\n'CBG', 'X',\n'CBI', 'X',\n'CBL',\
 'X',\n'CBM', 'X',\n'CBN', 'X',\n'CBO', 'X',\n'CBP\
', 'X',\n'CBS', 'X',\n'CBX', 'X',\n'CBZ', 'X',\n'C\
C0', 'X',\n'CC1', 'X',\n'CCC', 'X',\n'CCH', 'X',\n\
'CCI', 'X',\n'CCM', 'X',\n'CCN', 'X',\n'CCO', 'X',\
\n'CCP', 'X',\n'CCR', 'X',\n'CCS', 'C',\n'CCV', 'X\
',\n'CCY', 'X',\n'CD1', 'X',\n'CDC', 'X',\n'CDE', \
'X',\n'CDF', 'X',\n'CDI', 'X',\n'CDL', 'X',\n'CDM'\
, 'X',\n'CDP', 'X',\n'CDR', 'X',\n'CDU', 'X',\n'CE\
1', 'X',\n'CEA', 'C',\n'CEB', 'X',\n'CEC', 'X',\n'\
CED', 'X',\n'CEF', 'X',\n'CEH', 'X',\n'CEM', 'X',\\
n'CEO', 'X',\n'CEP', 'X',\n'CEQ', 'X',\n'CER', 'X'\
,\n'CES', 'G',\n'CET', 'X',\n'CFC', 'X',\n'CFF', '\
X',\n'CFM', 'X',\n'CFO', 'X',\n'CFP', 'X',\n'CFS',\
 'X',\n'CFX', 'X',\n'CGN', 'X',\n'CGP', 'X',\n'CGS\
', 'X',\n'CGU', 'E',\n'CH2', 'X',\n'CH3', 'X',\n'C\
HA', 'X',\n'CHB', 'X',\n'CHD', 'X',\n'CHF', 'X',\n\
'CHG', 'G',\n'CHI', 'X',\n'CHN', 'X',\n'CHO', 'X',\
\n'CHP', 'G',\n'CHR', 'X',\n'CHS', 'F',\n'CHT', 'X\
',\n'CHX', 'X',\n'CIC', 'X',\n'CIN', 'X',\n'CIP', \
'X',\n'CIR', 'X',\n'CIT', 'X',\n'CIU', 'X',\n'CKI'\
, 'X',\n'CL1', 'X',\n'CL2', 'X',\n'CLA', 'X',\n'CL\
B', 'A',\n'CLC', 'S',\n'CLD', 'A',\n'CLE', 'L',\n'\
CLF', 'X',\n'CLK', 'S',\n'CLL', 'X',\n'CLM', 'X',\\
n'CLN', 'X',\n'CLO', 'X',\n'CLP', 'X',\n'CLQ', 'X'\
,\n'CLR', 'X',\n'CLS', 'X',\n'CLT', 'X',\n'CLX', '\
X',\n'CLY', 'X',\n'CMA', 'R',\n'CMC', 'X',\n'CMD',\
 'X',\n'CME', 'C',\n'CMG', 'X',\n'CMK', 'X',\n'CMN\
', 'X',\n'CMO', 'X',\n'CMP', 'X',\n'CMR', 'X',\n'C\
MS', 'X',\n'CMT', 'C',\n'CMX', 'X',\n'CNA', 'X',\n\
'CNC', 'X',\n'CND', 'X',\n'CNH', 'X',\n'CNM', 'X',\
\n'CNN', 'X',\n'CNO', 'X',\n'CNP', 'X',\n'CO2', 'X\
',\n'CO3', 'X',\n'CO5', 'X',\n'CO8', 'X',\n'COA', \
'X',\n'COB', 'X',\n'COC', 'X',\n'COD', 'X',\n'COE'\
, 'X',\n'COF', 'X',\n'COH', 'X',\n'COI', 'X',\n'CO\
J', 'X',\n'COL', 'X',\n'COM', 'X',\n'CON', 'X',\n'\
COP', 'X',\n'COR', 'X',\n'COS', 'X',\n'COT', 'X',\\
n'COY', 'X',\n'CP1', 'G',\n'CP2', 'X',\n'CP4', 'X'\
,\n'CPA', 'X',\n'CPB', 'X',\n'CPC', 'X',\n'CPD', '\
X',\n'CPG', 'X',\n'CPH', 'X',\n'CPI', 'X',\n'CPM',\
 'X',\n'CPN', 'G',\n'CPO', 'X',\n'CPP', 'X',\n'CPQ\
', 'X',\n'CPR', 'X',\n'CPS', 'X',\n'CPT', 'X',\n'C\
PU', 'X',\n'CPV', 'X',\n'CPY', 'X',\n'CR1', 'X',\n\
'CR6', 'X',\n'CRA', 'X',\n'CRB', 'X',\n'CRC', 'X',\
\n'CRG', 'X',\n'CRH', 'X',\n'CRO', 'T',\n'CRP', 'X\
',\n'CRQ', 'X',\n'CRS', 'X',\n'CRT', 'X',\n'CRY', \
'X',\n'CSA', 'C',\n'CSB', 'X',\n'CSD', 'C',\n'CSE'\
, 'C',\n'CSH', 'X',\n'CSI', 'X',\n'CSN', 'X',\n'CS\
O', 'C',\n'CSP', 'C',\n'CSR', 'C',\n'CSS', 'C',\n'\
CST', 'X',\n'CSW', 'C',\n'CSX', 'C',\n'CSY', 'X',\\
n'CSZ', 'C',\n'CT3', 'X',\n'CTA', 'X',\n'CTB', 'X'\
,\n'CTC', 'X',\n'CTD', 'X',\n'CTH', 'T',\n'CTO', '\
X',\n'CTP', 'X',\n'CTR', 'X',\n'CTS', 'X',\n'CTT',\
 'X',\n'CTY', 'X',\n'CTZ', 'X',\n'CU1', 'X',\n'CUA\
', 'X',\n'CUC', 'X',\n'CUL', 'X',\n'CUO', 'X',\n'C\
UZ', 'X',\n'CVI', 'X',\n'CXF', 'X',\n'CXL', 'X',\n\
'CXM', 'M',\n'CXN', 'X',\n'CXP', 'X',\n'CXS', 'X',\
\n'CY1', 'C',\n'CY3', 'X',\n'CYB', 'X',\n'CYC', 'X\
',\n'CYF', 'C',\n'CYG', 'C',\n'CYH', 'X',\n'CYL', \
'X',\n'CYM', 'C',\n'CYN', 'X',\n'CYO', 'X',\n'CYP'\
, 'X',\n'CYQ', 'C',\n'CYS', 'C',\n'CYU', 'X',\n'CY\
Y', 'X',\n'CYZ', 'X',\n'CZH', 'X',\n'CZZ', 'C',\n'\
D12', 'X',\n'D13', 'X',\n'D16', 'X',\n'D18', 'X',\\
n'D19', 'X',\n'D1P', 'X',\n'D24', 'X',\n'D34', 'X'\
,\n'D35', 'X',\n'D4D', 'X',\n'D4T', 'X',\n'D6G', '\
X',\n'DA2', 'R',\n'DA3', 'X',\n'DA6', 'X',\n'DA7',\
 'X',\n'DAA', 'X',\n'DAB', 'X',\n'DAC', 'X',\n'DAD\
', 'X',\n'DAE', 'X',\n'DAF', 'X',\n'DAG', 'X',\n'D\
AH', 'A',\n'DAJ', 'X',\n'DAK', 'X',\n'DAL', 'A',\n\
'DAM', 'A',\n'DAN', 'X',\n'DAO', 'X',\n'DAP', 'X',\
\n'DAQ', 'X',\n'DAR', 'R',\n'DAS', 'D',\n'DAT', 'X\
',\n'DAU', 'X',\n'DAV', 'X',\n'DBA', 'X',\n'DBD', \
'X',\n'DBF', 'X',\n'DBG', 'X',\n'DBI', 'X',\n'DBV'\
, 'X',\n'DBY', 'Y',\n'DCA', 'X',\n'DCB', 'X',\n'DC\
E', 'X',\n'DCF', 'X',\n'DCG', 'X',\n'DCH', 'X',\n'\
DCI', 'I',\n'DCL', 'X',\n'DCM', 'X',\n'DCP', 'X',\\
n'DCS', 'X',\n'DCT', 'X',\n'DCY', 'C',\n'DCZ', 'X'\
,\n'DDA', 'X',\n'DDB', 'X',\n'DDC', 'X',\n'DDF', '\
X',\n'DDG', 'X',\n'DDH', 'X',\n'DDL', 'X',\n'DDM',\
 'X',\n'DDO', 'L',\n'DDP', 'X',\n'DDQ', 'X',\n'DDT\
', 'Y',\n'DDU', 'X',\n'DEA', 'X',\n'DEB', 'X',\n'D\
EC', 'X',\n'DEF', 'X',\n'DEL', 'X',\n'DEM', 'X',\n\
'DEN', 'X',\n'DEP', 'X',\n'DEQ', 'X',\n'DES', 'X',\
\n'DET', 'X',\n'DFC', 'X',\n'DFG', 'X',\n'DFI', 'X\
',\n'DFL', 'X',\n'DFO', 'X',\n'DFP', 'X',\n'DFR', \
'X',\n'DFT', 'X',\n'DFV', 'X',\n'DFX', 'X',\n'DG2'\
, 'X',\n'DG3', 'X',\n'DG6', 'X',\n'DGA', 'X',\n'DG\
D', 'X',\n'DGG', 'X',\n'DGL', 'E',\n'DGN', 'Q',\n'\
DGP', 'X',\n'DGT', 'X',\n'DGX', 'X',\n'DH2', 'X',\\
n'DHA', 'A',\n'DHB', 'X',\n'DHC', 'X',\n'DHD', 'X'\
,\n'DHE', 'X',\n'DHF', 'X',\n'DHG', 'X',\n'DHI', '\
H',\n'DHL', 'X',\n'DHM', 'X',\n'DHN', 'V',\n'DHP',\
 'X',\n'DHQ', 'X',\n'DHR', 'X',\n'DHS', 'X',\n'DHT\
', 'X',\n'DHU', 'X',\n'DHY', 'X',\n'DHZ', 'X',\n'D\
I2', 'X',\n'DI3', 'G',\n'DI4', 'X',\n'DI5', 'X',\n\
'DIA', 'X',\n'DIC', 'X',\n'DIF', 'X',\n'DIG', 'X',\
\n'DII', 'X',\n'DIL', 'I',\n'DIM', 'X',\n'DIO', 'X\
',\n'DIP', 'X',\n'DIQ', 'X',\n'DIS', 'X',\n'DIT', \
'X',\n'DIV', 'V',\n'DIX', 'X',\n'DIY', 'X',\n'DKA'\
, 'X',\n'DLA', 'X',\n'DLE', 'L',\n'DLF', 'X',\n'DL\
S', 'K',\n'DLY', 'K',\n'DM1', 'X',\n'DM2', 'X',\n'\
DM3', 'X',\n'DM4', 'X',\n'DM5', 'X',\n'DM6', 'X',\\
n'DM7', 'X',\n'DM8', 'X',\n'DM9', 'X',\n'DMA', 'X'\
,\n'DMB', 'X',\n'DMC', 'X',\n'DMD', 'X',\n'DME', '\
X',\n'DMF', 'X',\n'DMG', 'G',\n'DMH', 'N',\n'DMI',\
 'X',\n'DMJ', 'X',\n'DML', 'X',\n'DMM', 'X',\n'DMN\
', 'X',\n'DMO', 'X',\n'DMP', 'X',\n'DMQ', 'X',\n'D\
MR', 'X',\n'DMS', 'X',\n'DMT', 'X',\n'DMV', 'X',\n\
'DMY', 'X',\n'DNC', 'X',\n'DND', 'X',\n'DNH', 'X',\
\n'DNJ', 'X',\n'DNN', 'X',\n'DNP', 'X',\n'DNQ', 'X\
',\n'DNR', 'X',\n'DO2', 'X',\n'DO3', 'X',\n'DOA', \
'X',\n'DOB', 'X',\n'DOC', 'X',\n'DOH', 'D',\n'DOM'\
, 'X',\n'DOS', 'X',\n'DOX', 'X',\n'DP5', 'X',\n'DP\
7', 'X',\n'DPA', 'X',\n'DPC', 'X',\n'DPD', 'X',\n'\
DPE', 'X',\n'DPG', 'X',\n'DPH', 'F',\n'DPM', 'X',\\
n'DPN', 'F',\n'DPO', 'X',\n'DPP', 'X',\n'DPR', 'P'\
,\n'DPS', 'X',\n'DPT', 'X',\n'DPX', 'X',\n'DPY', '\
X',\n'DPZ', 'X',\n'DQH', 'X',\n'DQN', 'X',\n'DR1',\
 'X',\n'DRB', 'X',\n'DRC', 'X',\n'DRI', 'X',\n'DRP\
', 'X',\n'DRT', 'X',\n'DRU', 'X',\n'DSA', 'X',\n'D\
SB', 'X',\n'DSC', 'X',\n'DSD', 'X',\n'DSE', 'S',\n\
'DSI', 'X',\n'DSN', 'S',\n'DSP', 'D',\n'DSR', 'X',\
\n'DSS', 'X',\n'DSX', 'X',\n'DSY', 'X',\n'DTB', 'X\
',\n'DTD', 'X',\n'DTH', 'T',\n'DTN', 'X',\n'DTO', \
'X',\n'DTP', 'X',\n'DTQ', 'X',\n'DTR', 'W',\n'DTT'\
, 'X',\n'DTY', 'Y',\n'DUD', 'X',\n'DUO', 'X',\n'DU\
R', 'X',\n'DUT', 'X',\n'DVA', 'V',\n'DVR', 'X',\n'\
DX9', 'X',\n'DXA', 'X',\n'DXB', 'X',\n'DXC', 'X',\\
n'DXG', 'X',\n'DXX', 'X',\n'DZF', 'X',\n'E09', 'X'\
,\n'E20', 'X',\n'E2P', 'X',\n'E3G', 'X',\n'E4N', '\
X',\n'E4P', 'X',\n'E64', 'X',\n'E6C', 'X',\n'E96',\
 'X',\n'E97', 'X',\n'EA2', 'X',\n'EAA', 'X',\n'EAP\
', 'X',\n'EBP', 'X',\n'EBW', 'X',\n'ECO', 'X',\n'E\
DA', 'X',\n'EDC', 'X',\n'EDE', 'X',\n'EDO', 'X',\n\
'EDR', 'X',\n'EEB', 'X',\n'EEE', 'X',\n'EFC', 'X',\
\n'EFZ', 'X',\n'EG1', 'X',\n'EG2', 'X',\n'EG3', 'X\
',\n'EGC', 'X',\n'EGL', 'X',\n'EHP', 'A',\n'EIC', \
'X',\n'EJT', 'X',\n'ELA', 'X',\n'EMB', 'X',\n'EMC'\
, 'X',\n'EMD', 'X',\n'EMM', 'X',\n'EMO', 'X',\n'EM\
P', 'X',\n'EMR', 'X',\n'ENA', 'X',\n'ENC', 'X',\n'\
ENH', 'X',\n'ENO', 'X',\n'ENP', 'X',\n'EOA', 'X',\\
n'EOH', 'X',\n'EOT', 'X',\n'EOX', 'X',\n'EPA', 'X'\
,\n'EPE', 'X',\n'EPH', 'X',\n'EPI', 'X',\n'EPN', '\
X',\n'EPO', 'X',\n'EPT', 'X',\n'EPU', 'X',\n'EPX',\
 'X',\n'EPY', 'X',\n'EQI', 'X',\n'EQP', 'X',\n'EQU\
', 'X',\n'ERG', 'X',\n'ERI', 'X',\n'ERY', 'X',\n'E\
SC', 'X',\n'ESD', 'X',\n'ESI', 'X',\n'ESO', 'X',\n\
'ESP', 'X',\n'EST', 'X',\n'ESX', 'X',\n'ETA', 'X',\
\n'ETC', 'X',\n'ETD', 'X',\n'ETF', 'X',\n'ETH', 'X\
',\n'ETI', 'X',\n'ETN', 'X',\n'ETO', 'X',\n'ETP', \
'X',\n'ETR', 'X',\n'ETS', 'X',\n'ETY', 'X',\n'EU3'\
, 'X',\n'EUG', 'X',\n'EYS', 'C',\n'F09', 'X',\n'F2\
B', 'X',\n'F3S', 'X',\n'F42', 'X',\n'F43', 'X',\n'\
F4S', 'X',\n'F6B', 'X',\n'F6P', 'X',\n'F89', 'X',\\
n'FA1', 'X',\n'FA5', 'F',\n'FAA', 'X',\n'FAB', 'X'\
,\n'FAC', 'X',\n'FAD', 'X',\n'FAF', 'X',\n'FAG', '\
X',\n'FAM', 'X',\n'FAR', 'X',\n'FAS', 'X',\n'FAT',\
 'X',\n'FBA', 'X',\n'FBE', 'X',\n'FBI', 'X',\n'FBP\
', 'X',\n'FBQ', 'X',\n'FBS', 'X',\n'FBT', 'X',\n'F\
BU', 'X',\n'FCA', 'X',\n'FCB', 'X',\n'FCI', 'X',\n\
'FCN', 'X',\n'FCO', 'X',\n'FCR', 'X',\n'FCT', 'X',\
\n'FCX', 'X',\n'FCY', 'C',\n'FD1', 'F',\n'FD2', 'F\
',\n'FD3', 'F',\n'FD4', 'F',\n'FDA', 'X',\n'FDC', \
'X',\n'FDI', 'X',\n'FDP', 'X',\n'FDS', 'X',\n'FE2'\
, 'X',\n'FEA', 'X',\n'FEL', 'X',\n'FEM', 'X',\n'FE\
N', 'X',\n'FEO', 'X',\n'FEP', 'X',\n'FER', 'X',\n'\
FES', 'X',\n'FFB', 'X',\n'FFC', 'X',\n'FFF', 'X',\\
n'FFO', 'X',\n'FGL', 'G',\n'FHB', 'X',\n'FHC', 'X'\
,\n'FHP', 'X',\n'FHU', 'X',\n'FID', 'X',\n'FII', '\
X',\n'FIP', 'X',\n'FK5', 'X',\n'FKA', 'X',\n'FKI',\
 'X',\n'FKP', 'X',\n'FL2', 'X',\n'FL9', 'X',\n'FLA\
', 'A',\n'FLC', 'X',\n'FLD', 'X',\n'FLE', 'L',\n'F\
LF', 'X',\n'FLO', 'X',\n'FLP', 'X',\n'FLT', 'Y',\n\
'FLU', 'X',\n'FLX', 'X',\n'FM1', 'X',\n'FM2', 'X',\
\n'FMA', 'X',\n'FMB', 'X',\n'FMC', 'X',\n'FME', 'M\
',\n'FMN', 'X',\n'FMP', 'X',\n'FMR', 'X',\n'FMS', \
'X',\n'FMT', 'X',\n'FNE', 'X',\n'FNP', 'X',\n'FNS'\
, 'X',\n'FOC', 'X',\n'FOE', 'X',\n'FOG', 'F',\n'FO\
H', 'X',\n'FOK', 'X',\n'FOL', 'X',\n'FON', 'X',\n'\
FOP', 'X',\n'FOR', 'X',\n'FOS', 'X',\n'FPA', 'X',\\
n'FPC', 'X',\n'FPI', 'X',\n'FPO', 'X',\n'FPP', 'X'\
,\n'FPT', 'X',\n'FQP', 'X',\n'FRA', 'X',\n'FRD', '\
F',\n'FRU', 'X',\n'FS3', 'X',\n'FS4', 'X',\n'FSB',\
 'X',\n'FSO', 'X',\n'FSX', 'X',\n'FTC', 'X',\n'FTP\
', 'X',\n'FTR', 'W',\n'FTT', 'X',\n'FTY', 'Y',\n'F\
UA', 'X',\n'FUC', 'X',\n'FUM', 'X',\n'FUP', 'X',\n\
'FVF', 'X',\n'FXP', 'X',\n'FXV', 'X',\n'FYA', 'F',\
\n'G16', 'X',\n'G1P', 'X',\n'G20', 'X',\n'G21', 'X\
',\n'G23', 'X',\n'G26', 'X',\n'G28', 'X',\n'G2F', \
'X',\n'G37', 'X',\n'G39', 'X',\n'G3H', 'X',\n'G3P'\
, 'X',\n'G4D', 'X',\n'G6D', 'X',\n'G6P', 'X',\n'G6\
Q', 'X',\n'G7M', 'X',\n'GA2', 'X',\n'GAA', 'X',\n'\
GAB', 'X',\n'GAC', 'X',\n'GAI', 'X',\n'GAL', 'X',\\
n'GAM', 'X',\n'GAN', 'X',\n'GAO', 'X',\n'GAP', 'X'\
,\n'GAR', 'G',\n'GAS', 'X',\n'GAT', 'X',\n'GBC', '\
X',\n'GBI', 'X',\n'GBP', 'X',\n'GBS', 'X',\n'GBX',\
 'X',\n'GC4', 'X',\n'GCA', 'X',\n'GCD', 'X',\n'GCG\
', 'G',\n'GCH', 'G',\n'GCK', 'X',\n'GCL', 'X',\n'G\
CM', 'X',\n'GCN', 'X',\n'GCO', 'X',\n'GCP', 'X',\n\
'GCR', 'X',\n'GCS', 'X',\n'GCU', 'X',\n'GD3', 'X',\
\n'GDB', 'X',\n'GDM', 'X',\n'GDN', 'X',\n'GDP', 'X\
',\n'GDS', 'X',\n'GDU', 'X',\n'GE1', 'X',\n'GE2', \
'X',\n'GE3', 'X',\n'GEA', 'X',\n'GEL', 'X',\n'GEM'\
, 'X',\n'GEN', 'X',\n'GEP', 'X',\n'GER', 'X',\n'GF\
P', 'X',\n'GGB', 'X',\n'GGL', 'E',\n'GGP', 'X',\n'\
GHP', 'G',\n'GIP', 'X',\n'GIS', 'X',\n'GKR', 'X',\\
n'GL2', 'X',\n'GL3', 'G',\n'GL4', 'X',\n'GL5', 'X'\
,\n'GL7', 'X',\n'GL9', 'X',\n'GLA', 'X',\n'GLB', '\
X',\n'GLC', 'X',\n'GLD', 'X',\n'GLE', 'X',\n'GLF',\
 'X',\n'GLG', 'X',\n'GLH', 'Q',\n'GLI', 'X',\n'GLL\
', 'X',\n'GLM', 'G',\n'GLN', 'Q',\n'GLO', 'X',\n'G\
LP', 'X',\n'GLR', 'X',\n'GLS', 'X',\n'GLT', 'X',\n\
'GLU', 'E',\n'GLV', 'X',\n'GLW', 'X',\n'GLY', 'G',\
\n'GLZ', 'X',\n'GM1', 'X',\n'GMA', 'X',\n'GMC', 'X\
',\n'GMH', 'X',\n'GMP', 'X',\n'GMY', 'X',\n'GN7', \
'X',\n'GNA', 'X',\n'GNB', 'X',\n'GNH', 'X',\n'GNP'\
, 'X',\n'GNT', 'X',\n'GOA', 'X',\n'GOL', 'X',\n'GO\
X', 'X',\n'GP1', 'X',\n'GP3', 'X',\n'GP4', 'X',\n'\
GP6', 'X',\n'GP8', 'X',\n'GPB', 'E',\n'GPC', 'X',\\
n'GPE', 'X',\n'GPG', 'X',\n'GPI', 'X',\n'GPJ', 'X'\
,\n'GPL', 'K',\n'GPM', 'X',\n'GPN', 'G',\n'GPP', '\
X',\n'GPR', 'X',\n'GPS', 'X',\n'GPX', 'X',\n'GR1',\
 'X',\n'GR3', 'X',\n'GR4', 'X',\n'GSA', 'X',\n'GSB\
', 'X',\n'GSC', 'G',\n'GSE', 'S',\n'GSH', 'X',\n'G\
SP', 'X',\n'GSR', 'X',\n'GSS', 'X',\n'GT9', 'C',\n\
'GTA', 'X',\n'GTB', 'X',\n'GTD', 'X',\n'GTE', 'X',\
\n'GTH', 'T',\n'GTN', 'X',\n'GTO', 'X',\n'GTP', 'X\
',\n'GTR', 'X',\n'GTS', 'X',\n'GTT', 'X',\n'GTX', \
'X',\n'GTZ', 'X',\n'GU7', 'X',\n'GUA', 'X',\n'GUD'\
, 'X',\n'GUM', 'X',\n'GUN', 'X',\n'GUP', 'X',\n'GU\
R', 'X',\n'GW3', 'X',\n'GZZ', 'X',\n'H2B', 'X',\n'\
H2P', 'H',\n'H2S', 'X',\n'H2U', 'X',\n'H4B', 'X',\\
n'H5M', 'P',\n'H5P', 'X',\n'HAA', 'X',\n'HAB', 'X'\
,\n'HAC', 'A',\n'HAD', 'X',\n'HAE', 'X',\n'HAG', '\
X',\n'HAI', 'X',\n'HAM', 'X',\n'HAP', 'X',\n'HAQ',\
 'X',\n'HAR', 'R',\n'HAS', 'X',\n'HAV', 'V',\n'HAX\
', 'X',\n'HAZ', 'X',\n'HBA', 'X',\n'HBC', 'X',\n'H\
BD', 'X',\n'HBI', 'X',\n'HBO', 'X',\n'HBU', 'X',\n\
'HBY', 'X',\n'HC0', 'X',\n'HC1', 'X',\n'HC4', 'X',\
\n'HCA', 'X',\n'HCC', 'X',\n'HCI', 'X',\n'HCS', 'X\
',\n'HDA', 'X',\n'HDD', 'X',\n'HDF', 'X',\n'HDN', \
'X',\n'HDS', 'X',\n'HDZ', 'X',\n'HE1', 'X',\n'HE6'\
, 'X',\n'HEA', 'X',\n'HEB', 'X',\n'HEC', 'X',\n'HE\
D', 'X',\n'HEE', 'X',\n'HEF', 'X',\n'HEG', 'X',\n'\
HEM', 'X',\n'HEN', 'X',\n'HEO', 'X',\n'HEP', 'X',\\
n'HEU', 'X',\n'HEV', 'X',\n'HEX', 'X',\n'HEZ', 'X'\
,\n'HF1', 'X',\n'HFA', 'X',\n'HFP', 'X',\n'HGA', '\
Q',\n'HGB', 'X',\n'HGC', 'X',\n'HGI', 'X',\n'HGU',\
 'X',\n'HHO', 'X',\n'HHP', 'X',\n'HIB', 'X',\n'HIC\
', 'H',\n'HII', 'X',\n'HIN', 'X',\n'HIO', 'X',\n'H\
IP', 'H',\n'HIS', 'H',\n'HLE', 'X',\n'HLT', 'X',\n\
'HMA', 'A',\n'HMB', 'X',\n'HMC', 'X',\n'HMD', 'X',\
\n'HMF', 'A',\n'HMG', 'X',\n'HMH', 'X',\n'HMI', 'L\
',\n'HMM', 'X',\n'HMN', 'X',\n'HMO', 'X',\n'HMP', \
'X',\n'HMR', 'R',\n'HNI', 'X',\n'HNP', 'X',\n'HOA'\
, 'X',\n'HOE', 'X',\n'HOH', 'X',\n'HOM', 'X',\n'HO\
P', 'X',\n'HOQ', 'X',\n'HP1', 'A',\n'HP2', 'A',\n'\
HP3', 'X',\n'HPA', 'X',\n'HPB', 'X',\n'HPC', 'X',\\
n'HPD', 'X',\n'HPE', 'A',\n'HPG', 'X',\n'HPH', 'F'\
,\n'HPP', 'X',\n'HPQ', 'F',\n'HPR', 'X',\n'HPT', '\
X',\n'HPY', 'X',\n'HQO', 'X',\n'HQQ', 'X',\n'HQU',\
 'X',\n'HRG', 'R',\n'HRI', 'X',\n'HSA', 'X',\n'HSE\
', 'S',\n'HSF', 'X',\n'HSM', 'X',\n'HSO', 'H',\n'H\
SP', 'X',\n'HT1', 'X',\n'HT2', 'X',\n'HTA', 'X',\n\
'HTL', 'X',\n'HTO', 'X',\n'HTP', 'X',\n'HTR', 'W',\
\n'HUP', 'X',\n'HUX', 'X',\n'HV5', 'A',\n'HV7', 'X\
',\n'HV8', 'X',\n'HXA', 'X',\n'HXC', 'X',\n'HXP', \
'X',\n'HY1', 'X',\n'HYA', 'X',\n'HYB', 'X',\n'HYD'\
, 'X',\n'HYG', 'X',\n'HYP', 'P',\n'I06', 'X',\n'I1\
0', 'X',\n'I11', 'X',\n'I17', 'X',\n'I2P', 'X',\n'\
I3N', 'X',\n'I3P', 'X',\n'I40', 'X',\n'I48', 'X',\\
n'I4B', 'X',\n'I52', 'X',\n'I5P', 'X',\n'I84', 'G'\
,\n'IAG', 'G',\n'IAS', 'X',\n'IB2', 'X',\n'IBB', '\
X',\n'IBP', 'X',\n'IBR', 'X',\n'IBS', 'X',\n'IBZ',\
 'X',\n'IC1', 'X',\n'ICA', 'X',\n'ICI', 'X',\n'ICL\
', 'X',\n'ICP', 'X',\n'ICT', 'X',\n'ICU', 'X',\n'I\
D2', 'X',\n'IDC', 'X',\n'IDG', 'X',\n'IDH', 'X',\n\
'IDM', 'X',\n'IDO', 'X',\n'IDP', 'X',\n'IDR', 'X',\
\n'IDS', 'X',\n'IDT', 'X',\n'IDU', 'X',\n'IFG', 'X\
',\n'IFP', 'X',\n'IGL', 'X',\n'IGN', 'X',\n'IGP', \
'X',\n'IGU', 'X',\n'IH1', 'X',\n'IH2', 'X',\n'IH3'\
, 'X',\n'IHB', 'X',\n'IHN', 'X',\n'IHP', 'X',\n'II\
C', 'X',\n'IIL', 'I',\n'IIP', 'X',\n'IK2', 'X',\n'\
IKT', 'X',\n'ILA', 'I',\n'ILE', 'I',\n'ILG', 'X',\\
n'ILO', 'X',\n'ILX', 'I',\n'IM1', 'X',\n'IM2', 'X'\
,\n'IMC', 'X',\n'IMD', 'X',\n'IME', 'X',\n'IMF', '\
X',\n'IMG', 'X',\n'IMH', 'X',\n'IMI', 'X',\n'IML',\
 'I',\n'IMM', 'X',\n'IMN', 'X',\n'IMO', 'X',\n'IMP\
', 'X',\n'IMR', 'X',\n'IMU', 'X',\n'IN0', 'D',\n'I\
N1', 'R',\n'IN2', 'K',\n'IN3', 'L',\n'IN4', 'X',\n\
'IN5', 'A',\n'IN6', 'L',\n'IN7', 'X',\n'IN8', 'X',\
\n'IN9', 'X',\n'INA', 'L',\n'INB', 'X',\n'INC', 'X\
',\n'IND', 'X',\n'INE', 'X',\n'INF', 'F',\n'ING', \
'F',\n'INH', 'R',\n'INI', 'X',\n'INJ', 'X',\n'INK'\
, 'X',\n'INL', 'X',\n'INM', 'X',\n'INN', 'A',\n'IN\
O', 'X',\n'INP', 'X',\n'INQ', 'X',\n'INR', 'X',\n'\
INS', 'X',\n'INT', 'V',\n'INU', 'X',\n'INV', 'X',\\
n'INW', 'X',\n'INX', 'X',\n'INY', 'X',\n'INZ', 'X'\
,\n'IOA', 'X',\n'IOB', 'X',\n'IOC', 'X',\n'IOD', '\
X',\n'IOE', 'X',\n'IOF', 'X',\n'IOH', 'X',\n'IOL',\
 'X',\n'IOP', 'X',\n'IP1', 'X',\n'IP2', 'X',\n'IP3\
', 'X',\n'IP4', 'X',\n'IPA', 'X',\n'IPB', 'X',\n'I\
PD', 'X',\n'IPG', 'G',\n'IPH', 'X',\n'IPL', 'X',\n\
'IPM', 'X',\n'IPN', 'X',\n'IPO', 'F',\n'IPP', 'X',\
\n'IPS', 'X',\n'IPT', 'X',\n'IPU', 'X',\n'IPY', 'A\
',\n'IQB', 'X',\n'IQP', 'X',\n'IQS', 'X',\n'IR3', \
'X',\n'IRI', 'X',\n'IRP', 'X',\n'ISA', 'X',\n'ISF'\
, 'X',\n'ISO', 'X',\n'ISP', 'X',\n'ISQ', 'X',\n'IS\
U', 'X',\n'ITM', 'X',\n'ITP', 'X',\n'ITR', 'W',\n'\
ITS', 'X',\n'ITU', 'X',\n'IU5', 'X',\n'IUM', 'X',\\
n'IUR', 'X',\n'IVA', 'X',\n'IYG', 'G',\n'IYR', 'Y'\
,\n'J77', 'X',\n'J78', 'X',\n'J80', 'X',\n'JE2', '\
X',\n'JEN', 'X',\n'JST', 'X',\n'K21', 'X',\n'KAH',\
 'X',\n'KAI', 'X',\n'KAM', 'X',\n'KAN', 'X',\n'KAP\
', 'X',\n'KCP', 'X',\n'KCX', 'K',\n'KDO', 'X',\n'K\
EF', 'X',\n'KET', 'X',\n'KGR', 'X',\n'KH1', 'X',\n\
'KIF', 'X',\n'KIV', 'V',\n'KNI', 'X',\n'KPH', 'K',\
\n'KTH', 'X',\n'KTN', 'X',\n'KTP', 'X',\n'KWT', 'X\
',\n'L04', 'X',\n'L1P', 'X',\n'L24', 'E',\n'L2P', \
'X',\n'L34', 'E',\n'L37', 'E',\n'L3P', 'X',\n'L4P'\
, 'X',\n'L75', 'X',\n'LAC', 'X',\n'LAD', 'X',\n'LA\
K', 'X',\n'LAM', 'X',\n'LAR', 'X',\n'LAT', 'X',\n'\
LAX', 'X',\n'LCO', 'X',\n'LCP', 'X',\n'LCS', 'X',\\
n'LDA', 'X',\n'LDO', 'L',\n'LDP', 'X',\n'LEA', 'X'\
,\n'LEO', 'X',\n'LEU', 'L',\n'LG2', 'X',\n'LG6', '\
X',\n'LGC', 'X',\n'LGP', 'X',\n'LHG', 'X',\n'LHY',\
 'F',\n'LI1', 'X',\n'LIG', 'X',\n'LIL', 'X',\n'LIM\
', 'X',\n'LIN', 'X',\n'LIO', 'X',\n'LIP', 'X',\n'L\
LA', 'X',\n'LLP', 'K',\n'LLY', 'K',\n'LMG', 'X',\n\
'LML', 'X',\n'LMT', 'X',\n'LMU', 'X',\n'LMZ', 'X',\
\n'LNK', 'X',\n'LNL', 'X',\n'LNO', 'X',\n'LOF', 'X\
',\n'LOL', 'L',\n'LOM', 'X',\n'LOR', 'X',\n'LOS', \
'X',\n'LOV', 'L',\n'LOX', 'X',\n'LP1', 'X',\n'LP2'\
, 'R',\n'LPA', 'X',\n'LPC', 'X',\n'LPF', 'X',\n'LP\
L', 'X',\n'LPM', 'X',\n'LPP', 'X',\n'LRB', 'X',\n'\
LRU', 'X',\n'LS1', 'X',\n'LS2', 'X',\n'LS3', 'X',\\
n'LS4', 'X',\n'LS5', 'X',\n'LTA', 'X',\n'LTL', 'X'\
,\n'LTR', 'W',\n'LUM', 'X',\n'LVS', 'L',\n'LXC', '\
X',\n'LY2', 'X',\n'LY3', 'X',\n'LYA', 'X',\n'LYB',\
 'X',\n'LYC', 'X',\n'LYD', 'X',\n'LYM', 'K',\n'LYN\
', 'X',\n'LYS', 'K',\n'LYT', 'X',\n'LYW', 'X',\n'L\
YZ', 'K',\n'M1A', 'X',\n'M1G', 'X',\n'M2G', 'X',\n\
'M3L', 'K',\n'M6P', 'X',\n'M6T', 'X',\n'M7G', 'X',\
\n'MA1', 'X',\n'MA2', 'X',\n'MA3', 'X',\n'MA4', 'X\
',\n'MA6', 'X',\n'MAA', 'A',\n'MAB', 'X',\n'MAC', \
'X',\n'MAE', 'X',\n'MAG', 'X',\n'MAH', 'X',\n'MAI'\
, 'R',\n'MAK', 'X',\n'MAL', 'X',\n'MAM', 'X',\n'MA\
N', 'X',\n'MAO', 'X',\n'MAP', 'X',\n'MAR', 'X',\n'\
MAS', 'X',\n'MAT', 'X',\n'MAU', 'X',\n'MAZ', 'X',\\
n'MBA', 'X',\n'MBD', 'X',\n'MBG', 'X',\n'MBH', 'X'\
,\n'MBN', 'X',\n'MBO', 'X',\n'MBR', 'X',\n'MBS', '\
X',\n'MBV', 'X',\n'MBZ', 'X',\n'MCA', 'X',\n'MCD',\
 'X',\n'MCE', 'X',\n'MCG', 'G',\n'MCI', 'X',\n'MCN\
', 'X',\n'MCP', 'X',\n'MCT', 'X',\n'MCY', 'X',\n'M\
D2', 'X',\n'MDA', 'X',\n'MDC', 'X',\n'MDG', 'X',\n\
'MDH', 'X',\n'MDL', 'X',\n'MDM', 'X',\n'MDN', 'X',\
\n'MDP', 'X',\n'ME6', 'X',\n'MEB', 'X',\n'MEC', 'X\
',\n'MEL', 'X',\n'MEN', 'N',\n'MEP', 'X',\n'MER', \
'X',\n'MES', 'X',\n'MET', 'M',\n'MEV', 'X',\n'MF2'\
, 'X',\n'MF3', 'M',\n'MFB', 'X',\n'MFD', 'X',\n'MF\
U', 'X',\n'MG7', 'X',\n'MGA', 'X',\n'MGB', 'X',\n'\
MGD', 'X',\n'MGG', 'R',\n'MGL', 'X',\n'MGN', 'Q',\\
n'MGO', 'X',\n'MGP', 'X',\n'MGR', 'X',\n'MGS', 'X'\
,\n'MGT', 'X',\n'MGU', 'X',\n'MGY', 'G',\n'MHB', '\
X',\n'MHF', 'X',\n'MHL', 'L',\n'MHM', 'X',\n'MHO',\
 'M',\n'MHS', 'H',\n'MHZ', 'X',\n'MIA', 'X',\n'MIC\
', 'X',\n'MID', 'X',\n'MIL', 'X',\n'MIM', 'X',\n'M\
IN', 'G',\n'MIP', 'X',\n'MIS', 'S',\n'MIT', 'X',\n\
'MJI', 'X',\n'MK1', 'X',\n'MKC', 'X',\n'MLA', 'X',\
\n'MLC', 'X',\n'MLE', 'L',\n'MLN', 'X',\n'MLT', 'X\
',\n'MLY', 'K',\n'MLZ', 'K',\n'MM3', 'X',\n'MM4', \
'X',\n'MMA', 'X',\n'MMC', 'X',\n'MME', 'M',\n'MMO'\
, 'R',\n'MMP', 'X',\n'MMQ', 'X',\n'MMT', 'X',\n'MN\
1', 'X',\n'MN2', 'X',\n'MN3', 'X',\n'MN5', 'X',\n'\
MN7', 'X',\n'MN8', 'X',\n'MNA', 'X',\n'MNB', 'X',\\
n'MNC', 'X',\n'MNG', 'X',\n'MNL', 'L',\n'MNO', 'X'\
,\n'MNP', 'X',\n'MNQ', 'X',\n'MNS', 'X',\n'MNT', '\
X',\n'MNV', 'V',\n'MO1', 'X',\n'MO2', 'X',\n'MO3',\
 'X',\n'MO4', 'X',\n'MO5', 'X',\n'MO6', 'X',\n'MOA\
', 'X',\n'MOB', 'X',\n'MOC', 'X',\n'MOE', 'X',\n'M\
OG', 'X',\n'MOH', 'X',\n'MOL', 'X',\n'MOO', 'X',\n\
'MOP', 'X',\n'MOR', 'X',\n'MOS', 'X',\n'MOT', 'X',\
\n'MOX', 'X',\n'MP1', 'X',\n'MP3', 'X',\n'MPA', 'X\
',\n'MPB', 'X',\n'MPC', 'X',\n'MPD', 'X',\n'MPG', \
'X',\n'MPH', 'M',\n'MPI', 'X',\n'MPJ', 'M',\n'MPL'\
, 'X',\n'MPN', 'X',\n'MPO', 'X',\n'MPP', 'X',\n'MP\
Q', 'G',\n'MPR', 'X',\n'MPS', 'X',\n'MQ0', 'X',\n'\
MQ7', 'X',\n'MQ8', 'X',\n'MQ9', 'X',\n'MQI', 'X',\\
n'MR2', 'X',\n'MRC', 'X',\n'MRM', 'X',\n'MRP', 'X'\
,\n'MS2', 'X',\n'MSA', 'X',\n'MSB', 'X',\n'MSD', '\
X',\n'MSE', 'M',\n'MSF', 'X',\n'MSI', 'X',\n'MSO',\
 'M',\n'MSQ', 'X',\n'MST', 'X',\n'MSU', 'X',\n'MTA\
', 'X',\n'MTB', 'X',\n'MTC', 'X',\n'MTD', 'X',\n'M\
TE', 'X',\n'MTF', 'X',\n'MTG', 'X',\n'MTO', 'X',\n\
'MTS', 'X',\n'MTT', 'X',\n'MTX', 'X',\n'MTY', 'Y',\
\n'MUG', 'X',\n'MUP', 'X',\n'MUR', 'X',\n'MVA', 'V\
',\n'MW1', 'X',\n'MW2', 'X',\n'MXA', 'X',\n'MXY', \
'X',\n'MYA', 'X',\n'MYC', 'X',\n'MYG', 'X',\n'MYR'\
, 'X',\n'MYS', 'X',\n'MYT', 'X',\n'MZM', 'X',\n'N1\
T', 'X',\n'N25', 'X',\n'N2B', 'X',\n'N3T', 'X',\n'\
N4B', 'X',\n'NA2', 'X',\n'NA5', 'X',\n'NA6', 'X',\\
n'NAA', 'X',\n'NAB', 'X',\n'NAC', 'X',\n'NAD', 'X'\
,\n'NAE', 'X',\n'NAF', 'X',\n'NAG', 'X',\n'NAH', '\
X',\n'NAI', 'X',\n'NAL', 'A',\n'NAM', 'A',\n'NAN',\
 'X',\n'NAO', 'X',\n'NAP', 'X',\n'NAQ', 'X',\n'NAR\
', 'X',\n'NAS', 'X',\n'NAU', 'X',\n'NAV', 'X',\n'N\
AW', 'X',\n'NAX', 'X',\n'NAY', 'X',\n'NBA', 'X',\n\
'NBD', 'X',\n'NBE', 'X',\n'NBG', 'X',\n'NBN', 'X',\
\n'NBP', 'X',\n'NBS', 'X',\n'NBU', 'X',\n'NCA', 'X\
',\n'NCB', 'A',\n'NCD', 'X',\n'NCH', 'X',\n'NCM', \
'X',\n'NCN', 'X',\n'NCO', 'X',\n'NCR', 'X',\n'NCS'\
, 'X',\n'ND4', 'X',\n'NDA', 'X',\n'NDC', 'X',\n'ND\
D', 'X',\n'NDO', 'X',\n'NDP', 'X',\n'NDT', 'X',\n'\
NEA', 'X',\n'NEB', 'X',\n'NED', 'X',\n'NEM', 'H',\\
n'NEN', 'X',\n'NEO', 'X',\n'NEP', 'H',\n'NEQ', 'X'\
,\n'NES', 'X',\n'NET', 'X',\n'NEV', 'X',\n'NFA', '\
F',\n'NFE', 'X',\n'NFG', 'X',\n'NFP', 'X',\n'NFS',\
 'X',\n'NG6', 'X',\n'NGA', 'X',\n'NGL', 'X',\n'NGM\
', 'X',\n'NGO', 'X',\n'NGP', 'X',\n'NGT', 'X',\n'N\
GU', 'X',\n'NH2', 'X',\n'NH3', 'X',\n'NH4', 'X',\n\
'NHD', 'X',\n'NHE', 'X',\n'NHM', 'X',\n'NHP', 'X',\
\n'NHR', 'X',\n'NHS', 'X',\n'NI1', 'X',\n'NI2', 'X\
',\n'NIC', 'X',\n'NID', 'X',\n'NIK', 'X',\n'NIO', \
'X',\n'NIP', 'X',\n'NIT', 'X',\n'NIU', 'X',\n'NIY'\
, 'Y',\n'NLA', 'X',\n'NLE', 'L',\n'NLG', 'X',\n'NL\
N', 'L',\n'NLP', 'L',\n'NM1', 'X',\n'NMA', 'A',\n'\
NMB', 'X',\n'NMC', 'G',\n'NMD', 'X',\n'NME', 'X',\\
n'NMN', 'X',\n'NMO', 'X',\n'NMQ', 'X',\n'NMX', 'X'\
,\n'NMY', 'X',\n'NNH', 'R',\n'NNO', 'X',\n'NO2', '\
X',\n'NO3', 'X',\n'NOA', 'X',\n'NOD', 'X',\n'NOJ',\
 'X',\n'NON', 'X',\n'NOP', 'X',\n'NOR', 'X',\n'NOS\
', 'X',\n'NOV', 'X',\n'NOX', 'X',\n'NP3', 'X',\n'N\
PA', 'X',\n'NPC', 'X',\n'NPD', 'X',\n'NPE', 'X',\n\
'NPF', 'X',\n'NPH', 'C',\n'NPI', 'X',\n'NPL', 'X',\
\n'NPN', 'X',\n'NPO', 'X',\n'NPP', 'X',\n'NPT', 'X\
',\n'NPY', 'X',\n'NRG', 'R',\n'NRI', 'X',\n'NS1', \
'X',\n'NS5', 'X',\n'NSP', 'X',\n'NTA', 'X',\n'NTB'\
, 'X',\n'NTC', 'X',\n'NTH', 'X',\n'NTM', 'X',\n'NT\
P', 'X',\n'NTS', 'X',\n'NTU', 'X',\n'NTZ', 'X',\n'\
NU1', 'X',\n'NVA', 'V',\n'NVI', 'X',\n'NVP', 'X',\\
n'NW1', 'X',\n'NYP', 'X',\n'O4M', 'X',\n'OAA', 'X'\
,\n'OAI', 'X',\n'OAP', 'X',\n'OAR', 'X',\n'OAS', '\
S',\n'OBA', 'X',\n'OBN', 'X',\n'OC1', 'X',\n'OC2',\
 'X',\n'OC3', 'X',\n'OC4', 'X',\n'OC5', 'X',\n'OC6\
', 'X',\n'OC7', 'X',\n'OCL', 'X',\n'OCM', 'X',\n'O\
CN', 'X',\n'OCO', 'X',\n'OCP', 'X',\n'OCS', 'C',\n\
'OCT', 'X',\n'OCV', 'K',\n'OCY', 'C',\n'ODA', 'X',\
\n'ODS', 'X',\n'OES', 'X',\n'OET', 'X',\n'OF1', 'X\
',\n'OF2', 'X',\n'OF3', 'X',\n'OFL', 'X',\n'OFO', \
'X',\n'OHE', 'X',\n'OHO', 'X',\n'OHT', 'X',\n'OIC'\
, 'X',\n'OIP', 'X',\n'OKA', 'X',\n'OLA', 'X',\n'OL\
E', 'X',\n'OLI', 'X',\n'OLO', 'X',\n'OMB', 'X',\n'\
OMC', 'X',\n'OMD', 'X',\n'OME', 'X',\n'OMG', 'X',\\
n'OMP', 'X',\n'OMT', 'M',\n'OMU', 'X',\n'ONE', 'X'\
,\n'ONL', 'L',\n'ONP', 'X',\n'OPA', 'X',\n'OPD', '\
X',\n'OPE', 'X',\n'OPG', 'X',\n'OPH', 'X',\n'OPN',\
 'X',\n'OPP', 'X',\n'OPR', 'R',\n'ORN', 'X',\n'ORO\
', 'X',\n'ORP', 'X',\n'OSB', 'X',\n'OSS', 'X',\n'O\
TA', 'X',\n'OTB', 'X',\n'OTE', 'X',\n'OTG', 'X',\n\
'OUT', 'X',\n'OVA', 'X',\n'OWQ', 'X',\n'OXA', 'X',\
\n'OXE', 'X',\n'OXI', 'X',\n'OXL', 'X',\n'OXM', 'X\
',\n'OXN', 'X',\n'OXO', 'X',\n'OXP', 'X',\n'OXS', \
'X',\n'OXY', 'X',\n'P11', 'A',\n'P24', 'X',\n'P28'\
, 'X',\n'P2P', 'X',\n'P2U', 'X',\n'P3M', 'X',\n'P4\
C', 'X',\n'P4P', 'X',\n'P5P', 'X',\n'P6G', 'X',\n'\
PA1', 'X',\n'PA2', 'X',\n'PA3', 'X',\n'PA4', 'X',\\
n'PA5', 'X',\n'PAA', 'X',\n'PAB', 'X',\n'PAC', 'X'\
,\n'PAD', 'X',\n'PAE', 'X',\n'PAG', 'X',\n'PAH', '\
X',\n'PAI', 'X',\n'PAL', 'D',\n'PAM', 'X',\n'PAN',\
 'X',\n'PAO', 'X',\n'PAP', 'A',\n'PAQ', 'F',\n'PAR\
', 'X',\n'PAS', 'X',\n'PAT', 'W',\n'PBA', 'X',\n'P\
BB', 'X',\n'PBC', 'X',\n'PBF', 'F',\n'PBG', 'X',\n\
'PBI', 'X',\n'PBM', 'X',\n'PBN', 'X',\n'PBP', 'X',\
\n'PBR', 'X',\n'PBZ', 'X',\n'PC2', 'X',\n'PCA', 'E\
',\n'PCB', 'X',\n'PCD', 'X',\n'PCE', 'X',\n'PCG', \
'X',\n'PCH', 'X',\n'PCL', 'X',\n'PCM', 'X',\n'PCP'\
, 'X',\n'PCR', 'X',\n'PCS', 'X',\n'PCU', 'X',\n'PC\
V', 'X',\n'PCY', 'X',\n'PD1', 'X',\n'PDA', 'X',\n'\
PDC', 'X',\n'PDD', 'A',\n'PDE', 'A',\n'PDI', 'X',\\
n'PDL', 'A',\n'PDN', 'X',\n'PDO', 'X',\n'PDP', 'X'\
,\n'PDT', 'X',\n'PDU', 'X',\n'PE2', 'X',\n'PE6', '\
X',\n'PEA', 'X',\n'PEB', 'X',\n'PEC', 'X',\n'PED',\
 'X',\n'PEE', 'X',\n'PEF', 'X',\n'PEG', 'X',\n'PEL\
', 'X',\n'PEO', 'X',\n'PEP', 'X',\n'PEQ', 'X',\n'P\
ER', 'X',\n'PET', 'X',\n'PFB', 'X',\n'PFC', 'X',\n\
'PFG', 'X',\n'PFL', 'X',\n'PFM', 'X',\n'PFZ', 'X',\
\n'PG4', 'X',\n'PG5', 'X',\n'PG6', 'X',\n'PGA', 'X\
',\n'PGC', 'X',\n'PGD', 'X',\n'PGE', 'X',\n'PGG', \
'G',\n'PGH', 'X',\n'PGL', 'X',\n'PGO', 'X',\n'PGP'\
, 'X',\n'PGQ', 'X',\n'PGR', 'X',\n'PGS', 'X',\n'PG\
U', 'X',\n'PGX', 'X',\n'PGY', 'G',\n'PH1', 'X',\n'\
PH2', 'X',\n'PH3', 'X',\n'PHA', 'F',\n'PHB', 'X',\\
n'PHC', 'X',\n'PHD', 'X',\n'PHE', 'F',\n'PHG', 'X'\
,\n'PHH', 'X',\n'PHI', 'F',\n'PHL', 'F',\n'PHM', '\
X',\n'PHN', 'X',\n'PHO', 'X',\n'PHP', 'X',\n'PHQ',\
 'X',\n'PHS', 'H',\n'PHT', 'X',\n'PHW', 'P',\n'PHY\
', 'X',\n'PI1', 'X',\n'PI2', 'X',\n'PI3', 'X',\n'P\
I4', 'X',\n'PI5', 'X',\n'PI6', 'X',\n'PI7', 'X',\n\
'PI8', 'X',\n'PI9', 'X',\n'PIA', 'X',\n'PIB', 'X',\
\n'PIC', 'X',\n'PID', 'X',\n'PIG', 'X',\n'PIH', 'X\
',\n'PIM', 'X',\n'PIN', 'X',\n'PIO', 'X',\n'PIP', \
'X',\n'PIQ', 'X',\n'PIR', 'X',\n'PIV', 'X',\n'PKF'\
, 'X',\n'PL1', 'X',\n'PL9', 'X',\n'PLA', 'D',\n'PL\
C', 'X',\n'PLE', 'L',\n'PLG', 'G',\n'PLH', 'X',\n'\
PLM', 'X',\n'PLP', 'X',\n'PLS', 'S',\n'PLT', 'W',\\
n'PLU', 'L',\n'PLY', 'X',\n'PMA', 'X',\n'PMB', 'X'\
,\n'PMC', 'X',\n'PME', 'F',\n'PML', 'X',\n'PMM', '\
X',\n'PMO', 'X',\n'PMP', 'X',\n'PMS', 'X',\n'PMY',\
 'X',\n'PN2', 'X',\n'PNA', 'X',\n'PNB', 'X',\n'PNC\
', 'G',\n'PND', 'X',\n'PNE', 'A',\n'PNF', 'X',\n'P\
NG', 'X',\n'PNI', 'X',\n'PNL', 'X',\n'PNM', 'X',\n\
'PNN', 'X',\n'PNO', 'X',\n'PNP', 'X',\n'PNQ', 'X',\
\n'PNS', 'X',\n'PNT', 'X',\n'PNU', 'X',\n'PO2', 'X\
',\n'PO4', 'X',\n'POB', 'X',\n'POC', 'X',\n'POL', \
'X',\n'POM', 'P',\n'PON', 'X',\n'POP', 'X',\n'POR'\
, 'X',\n'POS', 'X',\n'PP1', 'X',\n'PP2', 'X',\n'PP\
3', 'A',\n'PP4', 'X',\n'PP5', 'X',\n'PP6', 'X',\n'\
PP7', 'X',\n'PP8', 'N',\n'PP9', 'X',\n'PPB', 'X',\\
n'PPC', 'X',\n'PPD', 'X',\n'PPE', 'E',\n'PPG', 'X'\
,\n'PPH', 'F',\n'PPI', 'X',\n'PPJ', 'V',\n'PPL', '\
X',\n'PPM', 'X',\n'PPN', 'A',\n'PPO', 'X',\n'PPP',\
 'X',\n'PPQ', 'X',\n'PPR', 'X',\n'PPS', 'X',\n'PPT\
', 'X',\n'PPU', 'X',\n'PPX', 'F',\n'PPY', 'X',\n'P\
PZ', 'X',\n'PQ0', 'X',\n'PQN', 'X',\n'PQQ', 'X',\n\
'PR1', 'X',\n'PR2', 'X',\n'PR3', 'X',\n'PRA', 'X',\
\n'PRB', 'X',\n'PRC', 'X',\n'PRD', 'X',\n'PRE', 'X\
',\n'PRF', 'X',\n'PRH', 'X',\n'PRI', 'P',\n'PRL', \
'X',\n'PRN', 'X',\n'PRO', 'P',\n'PRP', 'X',\n'PRR'\
, 'A',\n'PRS', 'P',\n'PRZ', 'X',\n'PS0', 'X',\n'PS\
A', 'X',\n'PSD', 'X',\n'PSE', 'X',\n'PSF', 'S',\n'\
PSG', 'X',\n'PSI', 'X',\n'PSO', 'X',\n'PSQ', 'X',\\
n'PSS', 'X',\n'PST', 'X',\n'PSU', 'X',\n'PT1', 'X'\
,\n'PT3', 'X',\n'PTA', 'X',\n'PTC', 'X',\n'PTD', '\
X',\n'PTE', 'X',\n'PTH', 'Y',\n'PTL', 'X',\n'PTM',\
 'Y',\n'PTN', 'X',\n'PTO', 'X',\n'PTP', 'X',\n'PTR\
', 'Y',\n'PTS', 'X',\n'PTT', 'X',\n'PTU', 'X',\n'P\
TY', 'X',\n'PUA', 'X',\n'PUB', 'X',\n'PUR', 'X',\n\
'PUT', 'X',\n'PVA', 'X',\n'PVB', 'X',\n'PVH', 'H',\
\n'PVL', 'X',\n'PXA', 'X',\n'PXF', 'X',\n'PXG', 'X\
',\n'PXP', 'X',\n'PXY', 'X',\n'PXZ', 'X',\n'PY2', \
'X',\n'PY4', 'X',\n'PY5', 'X',\n'PY6', 'X',\n'PYA'\
, 'A',\n'PYC', 'X',\n'PYD', 'X',\n'PYE', 'X',\n'PY\
L', 'X',\n'PYM', 'X',\n'PYO', 'X',\n'PYP', 'X',\n'\
PYQ', 'X',\n'PYR', 'X',\n'PYS', 'X',\n'PYT', 'X',\\
n'PYX', 'X',\n'PYY', 'X',\n'PYZ', 'X',\n'PZQ', 'X'\
,\n'Q82', 'X',\n'QNC', 'X',\n'QND', 'X',\n'QSI', '\
Q',\n'QTR', 'X',\n'QUA', 'X',\n'QUE', 'X',\n'QUI',\
 'X',\n'QUO', 'X',\n'R11', 'X',\n'R12', 'X',\n'R13\
', 'X',\n'R18', 'X',\n'R1P', 'X',\n'R56', 'X',\n'R\
5P', 'X',\n'RA2', 'X',\n'RAD', 'X',\n'RAI', 'X',\n\
'RAL', 'X',\n'RAM', 'X',\n'RAN', 'X',\n'RAP', 'X',\
\n'RBF', 'X',\n'RBU', 'X',\n'RCA', 'X',\n'RCL', 'X\
',\n'RCO', 'X',\n'RDC', 'X',\n'RDF', 'W',\n'RE9', \
'X',\n'REA', 'X',\n'RED', 'K',\n'REO', 'X',\n'REP'\
, 'X',\n'RET', 'X',\n'RFA', 'X',\n'RFB', 'X',\n'RF\
L', 'X',\n'RFP', 'X',\n'RG1', 'X',\n'RGS', 'X',\n'\
RH1', 'X',\n'RHA', 'X',\n'RHC', 'X',\n'RHD', 'X',\\
n'RHM', 'X',\n'RHO', 'X',\n'RHQ', 'X',\n'RHS', 'X'\
,\n'RIA', 'X',\n'RIB', 'X',\n'RIC', 'X',\n'RIF', '\
X',\n'RIN', 'X',\n'RIP', 'X',\n'RIT', 'X',\n'RMB',\
 'X',\n'RMN', 'X',\n'RMP', 'X',\n'RNG', 'X',\n'RNS\
', 'X',\n'RNT', 'X',\n'RO2', 'X',\n'RO4', 'X',\n'R\
OC', 'N',\n'ROI', 'X',\n'ROM', 'X',\n'RON', 'V',\n\
'ROP', 'X',\n'ROS', 'X',\n'ROX', 'X',\n'RPA', 'X',\
\n'RPD', 'X',\n'RPH', 'X',\n'RPL', 'X',\n'RPP', 'X\
',\n'RPR', 'X',\n'RPX', 'X',\n'RQ3', 'X',\n'RR1', \
'X',\n'RR6', 'X',\n'RRS', 'X',\n'RS1', 'X',\n'RS2'\
, 'X',\n'RS7', 'X',\n'RSS', 'X',\n'RTA', 'X',\n'RT\
B', 'X',\n'RTC', 'X',\n'RTL', 'X',\n'RUB', 'X',\n'\
RUN', 'X',\n'RWJ', 'X',\n'RXP', 'X',\n'S02', 'X',\\
n'S11', 'X',\n'S1H', 'S',\n'S27', 'X',\n'S2C', 'C'\
,\n'S3P', 'X',\n'S4U', 'X',\n'S57', 'X',\n'S58', '\
X',\n'S5H', 'X',\n'S6G', 'X',\n'S80', 'X',\n'SAA',\
 'X',\n'SAB', 'X',\n'SAC', 'S',\n'SAD', 'X',\n'SAE\
', 'X',\n'SAF', 'X',\n'SAH', 'C',\n'SAI', 'C',\n'S\
AL', 'X',\n'SAM', 'M',\n'SAN', 'X',\n'SAP', 'X',\n\
'SAR', 'X',\n'SAS', 'X',\n'SB1', 'X',\n'SB2', 'X',\
\n'SB3', 'X',\n'SB4', 'X',\n'SB5', 'X',\n'SB6', 'X\
',\n'SBA', 'L',\n'SBB', 'X',\n'SBD', 'A',\n'SBI', \
'X',\n'SBL', 'A',\n'SBN', 'X',\n'SBO', 'X',\n'SBR'\
, 'X',\n'SBS', 'X',\n'SBT', 'X',\n'SBU', 'X',\n'SB\
X', 'X',\n'SC4', 'X',\n'SCA', 'X',\n'SCC', 'X',\n'\
SCD', 'X',\n'SCH', 'C',\n'SCI', 'X',\n'SCL', 'X',\\
n'SCM', 'X',\n'SCN', 'X',\n'SCO', 'X',\n'SCP', 'S'\
,\n'SCR', 'X',\n'SCS', 'X',\n'SCV', 'C',\n'SCY', '\
C',\n'SD8', 'X',\n'SDK', 'X',\n'SDZ', 'X',\n'SE4',\
 'X',\n'SEA', 'X',\n'SEB', 'S',\n'SEC', 'X',\n'SEG\
', 'A',\n'SEI', 'X',\n'SEL', 'S',\n'SEM', 'X',\n'S\
EO', 'X',\n'SEP', 'S',\n'SER', 'S',\n'SES', 'X',\n\
'SET', 'S',\n'SEU', 'X',\n'SF4', 'X',\n'SFG', 'X',\
\n'SFN', 'X',\n'SFO', 'X',\n'SGA', 'X',\n'SGC', 'X\
',\n'SGL', 'X',\n'SGM', 'X',\n'SGN', 'X',\n'SGP', \
'X',\n'SHA', 'X',\n'SHC', 'X',\n'SHF', 'X',\n'SHH'\
, 'X',\n'SHP', 'G',\n'SHR', 'E',\n'SHT', 'T',\n'SH\
U', 'X',\n'SI2', 'X',\n'SIA', 'X',\n'SIF', 'X',\n'\
SIG', 'X',\n'SIH', 'X',\n'SIM', 'X',\n'SIN', 'X',\\
n'SKD', 'X',\n'SKF', 'X',\n'SLB', 'X',\n'SLE', 'X'\
,\n'SLZ', 'K',\n'SMA', 'X',\n'SMC', 'C',\n'SME', '\
M',\n'SML', 'X',\n'SMM', 'M',\n'SMN', 'X',\n'SMP',\
 'X',\n'SMS', 'X',\n'SN1', 'X',\n'SN6', 'X',\n'SN7\
', 'X',\n'SNC', 'C',\n'SNN', 'X',\n'SNP', 'X',\n'S\
O1', 'X',\n'SO2', 'X',\n'SO3', 'X',\n'SO4', 'X',\n\
'SOA', 'X',\n'SOC', 'C',\n'SOM', 'X',\n'SOR', 'X',\
\n'SOT', 'X',\n'SOX', 'X',\n'SPA', 'X',\n'SPB', 'X\
',\n'SPC', 'X',\n'SPD', 'X',\n'SPE', 'X',\n'SPG', \
'X',\n'SPH', 'X',\n'SPI', 'X',\n'SPK', 'X',\n'SPM'\
, 'X',\n'SPN', 'X',\n'SPO', 'X',\n'SPP', 'X',\n'SP\
S', 'X',\n'SPY', 'X',\n'SQU', 'X',\n'SRA', 'X',\n'\
SRB', 'X',\n'SRD', 'X',\n'SRL', 'X',\n'SRM', 'X',\\
n'SRS', 'X',\n'SRY', 'X',\n'SSA', 'X',\n'SSB', 'X'\
,\n'SSG', 'X',\n'SSP', 'X',\n'ST1', 'X',\n'ST2', '\
X',\n'ST3', 'X',\n'ST4', 'X',\n'ST5', 'X',\n'ST6',\
 'X',\n'STA', 'X',\n'STB', 'X',\n'STE', 'X',\n'STG\
', 'X',\n'STI', 'X',\n'STL', 'X',\n'STN', 'X',\n'S\
TO', 'X',\n'STP', 'X',\n'STR', 'X',\n'STU', 'X',\n\
'STY', 'Y',\n'SU1', 'X',\n'SU2', 'X',\n'SUC', 'X',\
\n'SUI', 'X',\n'SUL', 'X',\n'SUR', 'X',\n'SVA', 'S\
',\n'SWA', 'X',\n'T16', 'X',\n'T19', 'X',\n'T23', \
'X',\n'T29', 'X',\n'T33', 'X',\n'T3P', 'X',\n'T42'\
, 'A',\n'T44', 'X',\n'T5A', 'X',\n'T6A', 'T',\n'T6\
P', 'X',\n'T80', 'X',\n'T87', 'X',\n'TA1', 'X',\n'\
TAA', 'X',\n'TAB', 'X',\n'TAC', 'X',\n'TAD', 'X',\\
n'TAF', 'X',\n'TAM', 'X',\n'TAP', 'X',\n'TAR', 'X'\
,\n'TAS', 'X',\n'TAU', 'X',\n'TAX', 'X',\n'TAZ', '\
X',\n'TB9', 'X',\n'TBA', 'X',\n'TBD', 'X',\n'TBG',\
 'G',\n'TBH', 'X',\n'TBM', 'T',\n'TBO', 'X',\n'TBP\
', 'X',\n'TBR', 'X',\n'TBS', 'X',\n'TBT', 'X',\n'T\
BU', 'X',\n'TBZ', 'X',\n'TC4', 'X',\n'TCA', 'X',\n\
'TCB', 'X',\n'TCH', 'X',\n'TCK', 'X',\n'TCL', 'X',\
\n'TCM', 'X',\n'TCN', 'X',\n'TCP', 'X',\n'TCR', 'W\
',\n'TCS', 'X',\n'TCZ', 'X',\n'TDA', 'X',\n'TDB', \
'X',\n'TDG', 'X',\n'TDP', 'X',\n'TDR', 'X',\n'TDX'\
, 'X',\n'TEA', 'X',\n'TEM', 'X',\n'TEN', 'X',\n'TE\
O', 'X',\n'TEP', 'X',\n'TER', 'X',\n'TES', 'X',\n'\
TET', 'X',\n'TFA', 'X',\n'TFB', 'X',\n'TFH', 'X',\\
n'TFI', 'X',\n'TFK', 'X',\n'TFP', 'X',\n'THA', 'X'\
,\n'THB', 'X',\n'THC', 'T',\n'THD', 'X',\n'THE', '\
X',\n'THF', 'X',\n'THJ', 'X',\n'THK', 'X',\n'THM',\
 'X',\n'THN', 'X',\n'THO', 'T',\n'THP', 'X',\n'THQ\
', 'X',\n'THR', 'T',\n'THS', 'X',\n'THT', 'X',\n'T\
HU', 'X',\n'THX', 'X',\n'THZ', 'X',\n'TI1', 'X',\n\
'TI2', 'X',\n'TI3', 'P',\n'TIA', 'X',\n'TIH', 'A',\
\n'TK4', 'X',\n'TLA', 'X',\n'TLC', 'X',\n'TLM', 'X\
',\n'TLN', 'X',\n'TLX', 'X',\n'TM5', 'X',\n'TM6', \
'X',\n'TMA', 'X',\n'TMB', 'T',\n'TMC', 'X',\n'TMD'\
, 'T',\n'TME', 'X',\n'TMF', 'X',\n'TML', 'K',\n'TM\
M', 'X',\n'TMN', 'X',\n'TMP', 'X',\n'TMQ', 'X',\n'\
TMR', 'X',\n'TMT', 'X',\n'TMZ', 'X',\n'TNB', 'C',\\
n'TND', 'X',\n'TNK', 'X',\n'TNP', 'X',\n'TNT', 'X'\
,\n'TOA', 'X',\n'TOB', 'X',\n'TOC', 'X',\n'TOL', '\
X',\n'TOP', 'X',\n'TOS', 'X',\n'TOT', 'X',\n'TP1',\
 'G',\n'TP2', 'P',\n'TP3', 'E',\n'TP4', 'E',\n'TP7\
', 'T',\n'TPA', 'X',\n'TPE', 'X',\n'TPF', 'X',\n'T\
PI', 'X',\n'TPL', 'W',\n'TPM', 'X',\n'TPN', 'G',\n\
'TPO', 'T',\n'TPP', 'X',\n'TPQ', 'A',\n'TPR', 'P',\
\n'TPS', 'X',\n'TPT', 'X',\n'TPV', 'X',\n'TPX', 'X\
',\n'TPY', 'X',\n'TQ3', 'X',\n'TQ4', 'X',\n'TQ5', \
'X',\n'TQ6', 'X',\n'TR1', 'X',\n'TRA', 'X',\n'TRB'\
, 'X',\n'TRC', 'X',\n'TRD', 'X',\n'TRE', 'X',\n'TR\
F', 'W',\n'TRG', 'K',\n'TRH', 'X',\n'TRI', 'X',\n'\
TRJ', 'X',\n'TRM', 'X',\n'TRN', 'W',\n'TRO', 'W',\\
n'TRP', 'W',\n'TRQ', 'X',\n'TRS', 'X',\n'TRX', 'W'\
,\n'TRZ', 'X',\n'TS2', 'X',\n'TS3', 'X',\n'TS4', '\
X',\n'TS5', 'X',\n'TSA', 'X',\n'TSB', 'X',\n'TSI',\
 'X',\n'TSM', 'X',\n'TSN', 'X',\n'TSP', 'X',\n'TSU\
', 'X',\n'TTA', 'X',\n'TTE', 'X',\n'TTN', 'X',\n'T\
TO', 'X',\n'TTP', 'X',\n'TTX', 'X',\n'TXL', 'X',\n\
'TYA', 'Y',\n'TYB', 'Y',\n'TYD', 'X',\n'TYI', 'Y',\
\n'TYL', 'X',\n'TYM', 'W',\n'TYN', 'Y',\n'TYQ', 'Y\
',\n'TYR', 'Y',\n'TYS', 'Y',\n'TYV', 'X',\n'TYY', \
'A',\n'TZB', 'X',\n'TZC', 'X',\n'TZE', 'X',\n'TZL'\
, 'X',\n'TZO', 'X',\n'TZP', 'X',\n'U01', 'X',\n'U0\
2', 'X',\n'U03', 'X',\n'U04', 'X',\n'U05', 'X',\n'\
U0E', 'X',\n'U10', 'X',\n'U18', 'X',\n'U2G', 'X',\\
n'U3P', 'X',\n'U49', 'X',\n'U55', 'X',\n'U5P', 'X'\
,\n'U66', 'X',\n'U89', 'X',\n'U8U', 'X',\n'UAA', '\
X',\n'UAG', 'A',\n'UAP', 'X',\n'UAR', 'X',\n'UC1',\
 'X',\n'UC2', 'X',\n'UC3', 'X',\n'UC4', 'X',\n'UD1\
', 'X',\n'UD2', 'X',\n'UDP', 'X',\n'UDX', 'X',\n'U\
FG', 'X',\n'UFM', 'X',\n'UFP', 'X',\n'UGA', 'X',\n\
'UIN', 'X',\n'UKP', 'A',\n'UM3', 'X',\n'UMA', 'A',\
\n'UMG', 'X',\n'UMP', 'X',\n'UNA', 'X',\n'UND', 'X\
',\n'UNI', 'X',\n'UNK', 'X',\n'UNN', 'X',\n'UNX', \
'X',\n'UP5', 'X',\n'UP6', 'X',\n'UPA', 'X',\n'UPF'\
, 'X',\n'UPG', 'X',\n'UPP', 'X',\n'UQ1', 'X',\n'UQ\
2', 'X',\n'UQ6', 'X',\n'UR2', 'X',\n'URA', 'X',\n'\
URE', 'X',\n'URF', 'X',\n'URI', 'X',\n'URS', 'X',\\
n'UTP', 'X',\n'UVC', 'X',\n'UVW', 'X',\n'V35', 'X'\
,\n'V36', 'X',\n'V4O', 'X',\n'V7O', 'X',\n'VAA', '\
V',\n'VAC', 'X',\n'VAD', 'V',\n'VAF', 'V',\n'VAG',\
 'X',\n'VAL', 'V',\n'VAN', 'X',\n'VAS', 'X',\n'VAX\
', 'X',\n'VDX', 'X',\n'VDY', 'X',\n'VG1', 'X',\n'V\
IB', 'X',\n'VIR', 'X',\n'VIT', 'X',\n'VK3', 'X',\n\
'VO3', 'X',\n'VO4', 'X',\n'VS1', 'F',\n'VS2', 'F',\
\n'VS3', 'F',\n'VS4', 'F',\n'VXA', 'X',\n'W01', 'X\
',\n'W02', 'X',\n'W03', 'X',\n'W11', 'X',\n'W33', \
'X',\n'W35', 'X',\n'W42', 'X',\n'W43', 'X',\n'W54'\
, 'X',\n'W56', 'X',\n'W59', 'X',\n'W71', 'X',\n'W8\
4', 'X',\n'W8R', 'X',\n'W91', 'X',\n'WAY', 'X',\n'\
WCC', 'X',\n'WO2', 'X',\n'WO4', 'X',\n'WRB', 'X',\\
n'WRR', 'X',\n'WRS', 'X',\n'WW7', 'X',\n'X2F', 'X'\
,\n'X7O', 'X',\n'XAA', 'X',\n'XAN', 'X',\n'XAO', '\
X',\n'XBB', 'X',\n'XBP', 'X',\n'XDN', 'X',\n'XDP',\
 'X',\n'XIF', 'X',\n'XIM', 'X',\n'XK2', 'X',\n'XL1\
', 'X',\n'XLS', 'X',\n'XMP', 'X',\n'XN1', 'X',\n'X\
N2', 'X',\n'XN3', 'X',\n'XUL', 'X',\n'XV6', 'X',\n\
'XYD', 'X',\n'XYH', 'X',\n'XYL', 'X',\n'XYP', 'X',\
\n'XYS', 'X',\n'YOF', 'Y',\n'YRR', 'X',\n'YT3', 'X\
',\n'YZ9', 'X',\n'Z34', 'G',\n'Z5A', 'X',\n'ZAF', \
'X',\n'ZAP', 'X',\n'ZEB', 'X',\n'ZEN', 'X',\n'ZES'\
, 'X',\n'ZID', 'X',\n'ZMR', 'X',\n'ZN3', 'X',\n'ZN\
H', 'X',\n'ZNO', 'X',\n'ZO3', 'X',\n'ZPR', 'P',\n'\
ZRA', 'A',\n'ZST', 'X',\n'ZYA', 'A',\n\n\n'ASN','N\
');\n} \n\n\nsub file2head\n      {\n	my $file = s\
hift;\n	my $size = shift;\n	my $f= new FileHandle;\
\n	my $line;\n	open ($f,$file);\n	read ($f,$line, \
$size);\n	close ($f);\n	return $line;\n      }\nsu\
b file2tail\n      {\n	my $file = shift;\n	my $siz\
e = shift;\n	my $f= new FileHandle;\n	my $line;\n	\
\n	open ($f,$file);\n	seek ($f,$size*-1, 2);\n	rea\
d ($f,$line, $size);\n	close ($f);\n	return $line;\
\n      }\n\n\nsub vtmpnam\n      {\n	my $r=rand(1\
00000);\n	my $f=\"file.$r.$$\";\n	while (-e $f)\n	\
  {\n	    $f=vtmpnam();\n	  }\n	push (@TMPFILE_LIS\
T, $f);\n	return $f;\n      }\n\nsub myexit\n  {\n\
    my $code=@_[0];\n    if ($CLEAN_EXIT_STARTED==\
1){return;}\n    else {$CLEAN_EXIT_STARTED=1;}\n  \
  ### ONLY BARE EXIT\n    exit ($code);\n  }\nsub \
set_error_lock\n    {\n      my $name = shift;\n  \
    my $pid=$$;\n\n      \n      &lock4tc ($$,\"LE\
RROR\", \"LSET\", \"$$ -- ERROR: $name $PROGRAM\\n\
\");\n      return;\n    }\nsub set_lock\n  {\n   \
 my $pid=shift;\n    my $msg= shift;\n    my $p=ge\
tppid();\n    &lock4tc ($pid,\"LLOCK\",\"LRESET\",\
\"$p$msg\\n\");\n  }\nsub unset_lock\n   {\n     \\
n    my $pid=shift;\n    &lock4tc ($pid,\"LLOCK\",\
\"LRELEASE\",\"\");\n  }\nsub shift_lock\n  {\n   \
 my $from=shift;\n    my $to=shift;\n    my $from_\
type=shift;\n    my $to_type=shift;\n    my $actio\
n=shift;\n    my $msg;\n    \n    if (!&lock4tc($f\
rom, $from_type, \"LCHECK\", \"\")){return 0;}\n  \
  $msg=&lock4tc ($from, $from_type, \"LREAD\", \"\\
");\n    &lock4tc ($from, $from_type,\"LRELEASE\",\
 $msg);\n    &lock4tc ($to, $to_type, $action, $ms\
g);\n    return;\n  }\nsub isshellpid\n  {\n    my\
 $p=shift;\n    if (!lock4tc ($p, \"LLOCK\", \"LCH\
ECK\")){return 0;}\n    else\n      {\n	my $c=lock\
4tc($p, \"LLOCK\", \"LREAD\");\n	if ( $c=~/-SHELL-\
/){return 1;}\n      }\n    return 0;\n  }\nsub is\
rootpid\n  {\n    if(lock4tc (getppid(), \"LLOCK\"\
, \"LCHECK\")){return 0;}\n    else {return 1;}\n \
 }\nsub lock4tc\n	{\n	  my ($pid,$type,$action,$va\
lue)=@_;\n	  my $fname;\n	  my $host=hostname;\n	 \
 \n	  if ($type eq \"LLOCK\"){$fname=\"$LOCKDIR/.$\
pid.$host.lock4tcoffee\";}\n	  elsif ( $type eq \"\
LERROR\"){ $fname=\"$LOCKDIR/.$pid.$host.error4tco\
ffee\";}\n	  elsif ( $type eq \"LWARNING\"){ $fnam\
e=\"$LOCKDIR/.$pid.$host.warning4tcoffee\";}\n	  \\
n	  if ($debug_lock)\n	    {\n	      print STDERR \
\"\\n\\t---lock4tc(tcg): $action => $fname =>$valu\
e (RD: $LOCKDIR)\\n\";\n	    }\n\n	  if    ($actio\
n eq \"LCHECK\") {return -e $fname;}\n	  elsif ($a\
ction eq \"LREAD\"){return file2string($fname);}\n\
	  elsif ($action eq \"LSET\") {return string2file\
 ($value, $fname, \">>\");}\n	  elsif ($action eq \
\"LRESET\") {return string2file ($value, $fname, \\
">\");}\n	  elsif ($action eq \"LRELEASE\") \n	   \
 {\n	      if ( $debug_lock)\n		{\n		  my $g=new F\
ileHandle;\n		  open ($g, \">>$fname\");\n		  prin\
t $g \"\\nDestroyed by $$\\n\";\n		  close ($g);\n\
		  safe_system (\"mv $fname $fname.old\");\n		}\n\
	      else\n		{\n		  unlink ($fname);\n		}\n	    \
}\n	  return \"\";\n	}\n	\nsub file2string\n	{\n	 \
 my $file=@_[0];\n	  my $f=new FileHandle;\n	  my \
$r;\n	  open ($f, \"$file\");\n	  while (<$f>){$r.\
=$_;}\n	  close ($f);\n	  return $r;\n	}\nsub stri\
ng2file \n    {\n    my ($s,$file,$mode)=@_;\n    \
my $f=new FileHandle;\n    \n    open ($f, \"$mode\
$file\");\n    print $f  \"$s\";\n    close ($f);\\
n  }\n\nBEGIN\n    {\n      srand;\n    \n      $S\
IG{'SIGUP'}='signal_cleanup';\n      $SIG{'SIGINT'\
}='signal_cleanup';\n      $SIG{'SIGQUIT'}='signal\
_cleanup';\n      $SIG{'SIGILL'}='signal_cleanup';\
\n      $SIG{'SIGTRAP'}='signal_cleanup';\n      $\
SIG{'SIGABRT'}='signal_cleanup';\n      $SIG{'SIGE\
MT'}='signal_cleanup';\n      $SIG{'SIGFPE'}='sign\
al_cleanup';\n      \n      $SIG{'SIGKILL'}='signa\
l_cleanup';\n      $SIG{'SIGPIPE'}='signal_cleanup\
';\n      $SIG{'SIGSTOP'}='signal_cleanup';\n     \
 $SIG{'SIGTTIN'}='signal_cleanup';\n      $SIG{'SI\
GXFSZ'}='signal_cleanup';\n      $SIG{'SIGINFO'}='\
signal_cleanup';\n      \n      $SIG{'SIGBUS'}='si\
gnal_cleanup';\n      $SIG{'SIGALRM'}='signal_clea\
nup';\n      $SIG{'SIGTSTP'}='signal_cleanup';\n  \
    $SIG{'SIGTTOU'}='signal_cleanup';\n      $SIG{\
'SIGVTALRM'}='signal_cleanup';\n      $SIG{'SIGUSR\
1'}='signal_cleanup';\n\n\n      $SIG{'SIGSEGV'}='\
signal_cleanup';\n      $SIG{'SIGTERM'}='signal_cl\
eanup';\n      $SIG{'SIGCONT'}='signal_cleanup';\n\
      $SIG{'SIGIO'}='signal_cleanup';\n      $SIG{\
'SIGPROF'}='signal_cleanup';\n      $SIG{'SIGUSR2'\
}='signal_cleanup';\n\n      $SIG{'SIGSYS'}='signa\
l_cleanup';\n      $SIG{'SIGURG'}='signal_cleanup'\
;\n      $SIG{'SIGCHLD'}='signal_cleanup';\n      \
$SIG{'SIGXCPU'}='signal_cleanup';\n      $SIG{'SIG\
WINCH'}='signal_cleanup';\n      \n      $SIG{'INT\
'}='signal_cleanup';\n      $SIG{'TERM'}='signal_c\
leanup';\n      $SIG{'KILL'}='signal_cleanup';\n  \
    $SIG{'QUIT'}='signal_cleanup';\n      \n      \
our $debug_lock=$ENV{\"DEBUG_LOCK\"};\n      \n   \
   \n      \n      \n      foreach my $a (@ARGV){$\
CL.=\" $a\";}\n      if ( $debug_lock ){print STDE\
RR \"\\n\\n\\n********** START PG: $PROGRAM ******\
*******\\n\";}\n      if ( $debug_lock ){print STD\
ERR \"\\n\\n\\n**********(tcg) LOCKDIR: $LOCKDIR $\
$ *************\\n\";}\n      if ( $debug_lock ){p\
rint STDERR \"\\n --- $$ -- $CL\\n\";}\n      \n	 \
    \n      \n      \n    }\nsub flush_error\n  {\\
n    my $msg=shift;\n    return add_error ($EXIT_F\
AILURE,$$, $$,getppid(), $msg, $CL);\n  }\nsub add\
_error \n  {\n    my $code=shift;\n    my $rpid=sh\
ift;\n    my $pid=shift;\n    my $ppid=shift;\n   \
 my $type=shift;\n    my $com=shift;\n    \n    $E\
RROR_DONE=1;\n    lock4tc ($rpid, \"LERROR\",\"LSE\
T\",\"$pid -- ERROR: $type\\n\");\n    lock4tc ($$\
, \"LERROR\",\"LSET\", \"$pid -- COM: $com\\n\");\\
n    lock4tc ($$, \"LERROR\",\"LSET\", \"$pid -- S\
TACK: $ppid -> $pid\\n\");\n   \n    return $code;\
\n  }\nsub add_warning \n  {\n    my $rpid=shift;\\
n    my $pid =shift;\n    my $command=shift;\n    \
my $msg=\"$$ -- WARNING: $command\\n\";\n    print\
 STDERR \"$msg\";\n    lock4tc ($$, \"LWARNING\", \
\"LSET\", $msg);\n  }\n\nsub signal_cleanup\n  {\n\
    print dtderr \"\\n**** $$ (tcg) was killed\\n\\
";\n    &cleanup;\n    exit ($EXIT_FAILURE);\n  }\\
nsub clean_dir\n  {\n    my $dir=@_[0];\n    if ( \
!-d $dir){return ;}\n    elsif (!($dir=~/tmp/)){re\
turn ;}#safety check 1\n    elsif (($dir=~/\\*/)){\
return ;}#safety check 2\n    else\n      {\n	`rm \
-rf $dir`;\n      }\n    return;\n  }\nsub cleanup\
\n  {\n    #print stderr \"\\n----tc: $$ Kills $PI\
DCHILD\\n\";\n    #kill (SIGTERM,$PIDCHILD);\n    \
my $p=getppid();\n    $CLEAN_EXIT_STARTED=1;\n    \
\n    \n    \n    if (&lock4tc($$,\"LERROR\", \"LC\
HECK\", \"\"))\n      {\n	my $ppid=getppid();\n	if\
 (!$ERROR_DONE) \n	  {\n	    &lock4tc($$,\"LERROR\\
", \"LSET\", \"$$ -- STACK: $p -> $$\\n\");\n	    \
&lock4tc($$,\"LERROR\", \"LSET\", \"$$ -- COM: $CL\
\\n\");\n	  }\n      }\n    my $warning=&lock4tc($\
$, \"LWARNING\", \"LREAD\", \"\");\n    my $error=\
&lock4tc($$,  \"LERROR\", \"LREAD\", \"\");\n    #\
release error and warning lock if root\n    \n    \
if (isrootpid() && ($warning || $error) )\n      {\
\n	\n	print STDERR \"**************** Summary ****\
*********\\n$error\\n$warning\\n\";\n\n	&lock4tc($\
$,\"LERROR\",\"RELEASE\",\"\");\n	&lock4tc($$,\"LW\
ARNING\",\"RELEASE\",\"\");\n      } \n    \n    \\
n    foreach my $f (@TMPFILE_LIST)\n      {\n	if (\
-e $f){unlink ($f);} \n      }\n    foreach my $d \
(@TMPDIR_LIST)\n      {\n	clean_dir ($d);\n      }\
\n    #No More Lock Release\n    #&lock4tc($$,\"LL\
OCK\",\"LRELEASE\",\"\"); #release lock \n\n    if\
 ( $debug_lock ){print STDERR \"\\n\\n\\n*********\
* END PG: $PROGRAM ($$) *************\\n\";}\n    \
if ( $debug_lock ){print STDERR \"\\n\\n\\n*******\
***(tcg) LOCKDIR: $LOCKDIR $$ *************\\n\";}\
\n  }\nEND \n  {\n    \n    &cleanup();\n  }\n   \\
n\nsub safe_system \n{\n  my $com=shift;\n  my $nt\
ry=shift;\n  my $ctry=shift;\n  my $pid;\n  my $st\
atus;\n  my $ppid=getppid();\n  if ($com eq \"\"){\
return 1;}\n  \n  \n\n  if (($pid = fork ()) < 0){\
return (-1);}\n  if ($pid == 0)\n    {\n      set_\
lock($$, \" -SHELL- $com (tcg)\");\n      exec ($c\
om);\n    }\n  else\n    {\n      lock4tc ($$, \"L\
LOCK\", \"LSET\", \"$pid\\n\");#update parent\n   \
   $PIDCHILD=$pid;\n    }\n  if ($debug_lock){prin\
tf STDERR \"\\n\\t .... safe_system (fasta_seq2hmm\
)  p: $$ c: $pid COM: $com\\n\";}\n\n  waitpid ($p\
id,WTERMSIG);\n\n  shift_lock ($pid,$$, \"LWARNING\
\",\"LWARNING\", \"LSET\");\n\n  if ($? == $EXIT_F\
AILURE || lock4tc($pid, \"LERROR\", \"LCHECK\", \"\
\"))\n    {\n      if ($ntry && $ctry <$ntry)\n	{\\
n	  add_warning ($$,$$,\"$com failed [retry: $ctry\
]\");\n	  lock4tc ($pid, \"LRELEASE\", \"LERROR\",\
 \"\");\n	  return safe_system ($com, $ntry, ++$ct\
ry);\n	}\n      elsif ($ntry == -1)\n	{\n	  if (!s\
hift_lock ($pid, $$, \"LERROR\", \"LWARNING\", \"L\
SET\"))\n	    {\n	      add_warning ($$,$$,\"$com \
failed\");\n	    }\n	  else\n	    {\n	      lock4t\
c ($pid, \"LRELEASE\", \"LERROR\", \"\");\n	    }\\
n	  return $?;}\n      else\n	{\n	  if (!shift_loc\
k ($pid,$$, \"LERROR\",\"LERROR\", \"LSET\"))\n	  \
  {\n	      myexit(add_error ($EXIT_FAILURE,$$,$pi\
d,getppid(), \"UNSPECIFIED system\", $com));\n	   \
 }\n	}\n    }\n  return $?;\n}\n\nsub check_config\
uration \n    {\n      my @l=@_;\n      my $v;\n  \
    foreach my $p (@l)\n	{\n	  \n	  if   ( $p eq \\
"EMAIL\")\n	    { \n	      if ( !($EMAIL=~/@/))\n	\
	{\n		add_warning($$,$$,\"Could Not Use EMAIL\");\\
n		myexit(add_error ($EXIT_FAILURE,$$,$$,getppid()\
,\"EMAIL\",\"$CL\"));\n	      }\n	    }\n	  elsif(\
 $p eq \"INTERNET\")\n	    {\n	      if ( !&check_\
internet_connection())\n		{\n		  myexit(add_error \
($EXIT_FAILURE,$$,$$,getppid(),\"INTERNET\",\"$CL\\
"));\n		}\n	    }\n	  elsif( $p eq \"wget\")\n	   \
 {\n	      if (!&pg_is_installed (\"wget\") && !&p\
g_is_installed (\"curl\"))\n		{\n		  myexit(add_er\
ror ($EXIT_FAILURE,$$,$$,getppid(),\"PG_NOT_INSTAL\
LED:wget\",\"$CL\"));\n		}\n	    }\n	  elsif( !(&p\
g_is_installed ($p)))\n	    {\n	      myexit(add_e\
rror ($EXIT_FAILURE,$$,$$,getppid(),\"PG_NOT_INSTA\
LLED:$p\",\"$CL\"));\n	    }\n	}\n      return 1;\\
n    }\nsub pg_is_installed\n  {\n    my @ml=@_;\n\
    my $r, $p, $m;\n    my $supported=0;\n    \n  \
  my $p=shift (@ml);\n    if ($p=~/::/)\n      {\n\
	if (safe_system (\"perl -M$p -e 1\")==$EXIT_SUCCE\
SS){return 1;}\n	else {return 0;}\n      }\n    el\
se\n      {\n	$r=`which $p 2>/dev/null`;\n	if ($r \
eq \"\"){return 0;}\n	else {return 1;}\n      }\n \
 }\n\n\n\nsub check_internet_connection\n  {\n    \
my $internet;\n    my $tmp;\n    &check_configurat\
ion ( \"wget\"); \n    \n    $tmp=&vtmpnam ();\n  \
  \n    if     (&pg_is_installed    (\"wget\")){`w\
get www.google.com -O$tmp >/dev/null 2>/dev/null`;\
}\n    elsif  (&pg_is_installed    (\"curl\")){`cu\
rl www.google.com -o$tmp >/dev/null 2>/dev/null`;}\
\n    \n    if ( !-e $tmp || -s $tmp < 10){$intern\
et=0;}\n    else {$internet=1;}\n    if (-e $tmp){\
unlink $tmp;}\n\n    return $internet;\n  }\nsub c\
heck_pg_is_installed\n  {\n    my @ml=@_;\n    my \
$r=&pg_is_installed (@ml);\n    if (!$r && $p=~/::\
/)\n      {\n	print STDERR \"\\nYou Must Install t\
he perl package $p on your system.\\nRUN:\\n\\tsud\
o perl -MCPAN -e 'install $pg'\\n\";\n      }\n   \
 elsif (!$r)\n      {\n	myexit(flush_error(\"\\nPr\
ogram $p Supported but Not Installed on your syste\
m\"));\n      }\n    else\n      {\n	return 1;\n  \
    }\n  }\n\n\n","use Cwd;\nuse Env;\nuse File::P\
ath;\nuse FileHandle;\nuse strict;\n\n\nour (%MODE\
, %PG, %ENV_SET, %SUPPORTED_OS);\n\n\nour $EXIT_SU\
CCESS=0;\nour $EXIT_FAILURE=1;\nour $INTERNET=0;\n\
\nour $CP=\"cp \"; #was causing a crash on MacOSX\\
nour $SILENT=\">/dev/null 2>/dev/null\";\nour $WEB\
_BASE=\"http://www.tcoffee.org\";\nour $TCLINKDB_A\
DDRESS=\"$WEB_BASE/Resources/tclinkdb.txt\";\nour \
$OS=get_os();\nour $ROOT=&get_root();\nour $CD=cwd\
();\nour $CDIR=$CD;\nour $HOME=$ENV{'HOME'};\n\nou\
r $OSNAME=$ENV{'OSNAME'};\nour $OSARCH=$ENV{'OSARC\
H'};\nour $REPO_ROOT=\"\";\n\nour $TCDIR;\nour $TC\
CACHE;\nour $TCTMP;\nour $TCM;\nour $TCMETHODS;\no\
ur $TCPLUGINS;\nour $PLUGINS_DIR=\"\";\nour $INSTA\
LL_DIR=\"\";\n\nour $CXX=\"g++\";\nour $CXXFLAGS=\\
"\";\n\nour $CPP=\"g++\";\nour $CPPFLAGS=\"\";\n\n\
our $CC=\"gcc\";\nour $CFLAGS=$ENV{'CFLAGS'};\n\no\
ur $FC=\"f77\";\nour $FFLAGS=\"\";\n\nmy $install=\
\"all\";\nmy $default_update_action=\"no_update\";\
\nmy @required_applications=(\"wget_OR_curl\");\nm\
y @smode=(\"all\", \"clean\", \"install\");\n\n&in\
itialize_PG();\n\nmy $cl=join( \" \", @ARGV);\nif \
($#ARGV==-1 || ($cl=~/-h/) ||($cl=~/-H/) )\n  {\n \
    print \"\\n!!!!!!! ./install  t_coffee        \
     --> installs t_coffee only\";\n     print \"\\
\n!!!!!!! ./install  all                  --> inst\
alls all the modes [mcoffee, expresso, psicoffee,r\
coffee..]\";\n     print \"\\n!!!!!!! ./install  [\
mcoffee|rcoffee|..] --> installs the specified mod\
e\";\n     print \"\\n!!!!!!! ./install  -h       \
            --> print usage\\n\\n\";\n     if ( $#\
ARGV==-1){exit ($EXIT_FAILURE);}\n   }\n     \nif \
(($cl=~/-h/) ||($cl=~/-H/) )\n  {\n    my $m;\n   \
 print \"\\n\\n!!!!!!! advanced mode\\n\";\n    fo\
reach $m ((keys (%MODE)),@smode)\n      {\n	print \
\"!!!!!!!       ./install $m\\n\";\n      }\n    \\
n    print \"!!!!!!! ./install [target:package|mod\
e|] [-update|-force|-exec=dir|-dis=dir|-root|-tcli\
nkdb=file|-] [CC=|FCC=|CXX=|CFLAGS=|CXXFLAGS=]\\n\\
";\n    print \"!!!!!!! ./install clean    [remove\
s all executables]\\n\";\n    print \"!!!!!!! ./in\
stall [optional:target] -update               [upd\
ates package already installed]\\n\";\n    print \\
"!!!!!!! ./install [optional:target] -force       \
         [Forces recompilation over everything]\\n\
\";\n    \n    print \"!!!!!!! ./install [optional\
:target] -root                 [You are running as\
 root]\\n\";\n    print \"!!!!!!! ./install [optio\
nal:target] -exec=/foo/bar/       [address for the\
 T-Coffee executable]\\n\";\n    print \"!!!!!!! .\
/install [optional:target] -dis=/foo/bar/        [\
Address where distributions should be stored]\\n\"\
;\n    print \"!!!!!!! ./install [optional:target]\
 -tclinkdb=foo|update  [file containing all the pa\
ckages to be installed]\\n\";\n    print \"!!!!!!!\
 ./install [optional:target] -clean               \
 [clean everything]\\n\";\n    print \"!!!!!!! ./i\
nstall [optional:target] -plugins              [pl\
ugins directory]\\n\";\n    print \"!!!!!!! ./inst\
all [optional:target] -tcdir=/foor/bar      [base \
path where T-Coffee will be installed]\\n\";\n    \
print \"!!!!!!! ./install [optional:target] -repo=\
/path/to/repo   [binaries repository root director\
y]\\n\";\n    print \"!!!!!!! mode:\";\n    foreac\
h $m (keys(%MODE)){print \"$m \";}\n    print \"\\\
n\";\n    print \"!!!!!!! Packages:\";\n    foreac\
h $m (keys (%PG)){print \"$m \";}\n    print \"\\n\
\";\n    \n    print \"\\n\\n\";\n    exit ($EXIT_\
FAILURE);\n  }\n\n\n\nmy (@argl)=($cl=~/(\\S+=[^=]\
+)\\s\\w+=/g);\npush (@argl, ($cl=~/(\\S+=[^=]+\\S\
)\\s*$/g));\n\nforeach $a (@argl)\n  {\n    if ( (\
$cl=~/CXX=(.*)/)){$CXX=$1;}\n    if ( ($cl=~/-CC=(\
.*)/    )){$CC=$1;}\n    if ( ($cl=~/-FC=(.*)/    \
)){$FC=$1;}\n    if ( ($cl=~/-CFLAGS=(.*)/)){$CFLA\
GS=$1;}\n    if ( ($cl=~/-CXXFLAGS=(.*)/)){$CXXFLA\
GS=$1;}\n  }\nour ($ROOT_INSTALL, $NO_QUESTION, $d\
efault_update_action,$BINARIES_ONLY,$force, $defau\
lt_update_action, $INSTALL_DIR, $PLUGINS_DIR, $DIS\
TRIBUTIONS,$tclinkdb, $proxy, $clean);\nif ( ($cl=\
~/-root/)){$ROOT_INSTALL=1;}\nif ( ($cl=~/-no_ques\
tion/)){$NO_QUESTION=1;}\nif ( ($cl=~/-update/)){$\
default_update_action=\"update\";}\nif ( ($cl=~/-b\
inaries/)){$BINARIES_ONLY=1;}\nif ( ($cl=~/-force/\
)){$force=1;$default_update_action=\"update\"}\nif\
 ( ($cl=~/-exec=\\s*(\\S+)/)){$INSTALL_DIR=$1;}\ni\
f ( ($cl=~/-plugins=\\s*(\\S+)/)){$PLUGINS_DIR=$1;\
}\nif ( ($cl=~/-dis=\\s*(\\S+)/)){$DISTRIBUTIONS=$\
1;}\n\nif ( ($cl=~/-tclinkdb=\\s*(\\S+)/)){$tclink\
db=$1;}\nif ( ($cl=~/-proxy=\\s*(\\S+)/)){$proxy=$\
1;}\nif ( ($cl=~/-clean/)){$clean=1;}\nif ( ($cl=~\
/-repo=\\s*(\\S+)/)){ $REPO_ROOT=$1; }\nif ( ($cl=\
~/-tcdir=\\s*(\\S+)/)){ $TCDIR=$1; }\nif ($tclinkd\
b){&update_tclinkdb ($tclinkdb);}\n\n\nif( $REPO_R\
OOT ne \"\" ) {\n	if( $OSNAME eq \"\" ) { print \"\
You have specified the repository folder but the r\
equired \\\"OSNAME\\\" enviroment variable is miss\
ing. \\n\"; exit 1; } \n	if( $OSARCH eq \"\" ) { p\
rint \"You have specified the repository folder bu\
t the required \\\"OSARCH\\\" enviroment variable \
is missing. \\n\"; exit 1; } \n}\n\n\nif(!$TCDIR) \
{ $TCDIR=\"$HOME/.t_coffee\"; }\n&add_dir ($TCDIR)\
;\n&add_dir ($TCCACHE=\"$TCDIR/cache\");\n&add_dir\
 ($TCTMP=\"$CDIR/tmp\");\n&add_dir ($TCM=\"$TCDIR/\
mcoffee\");\n&add_dir ($TCMETHODS=\"$TCDIR/methods\
\");\n&add_dir ($TCPLUGINS=\"$TCDIR/plugins/$OS\")\
;\n\n\nour $BASE=\"$CD/bin\";\nour $BIN=\"$BASE/bi\
naries/$OS\";\nour $DOWNLOAD_DIR=\"$BASE/download\\
";\nour $DOWNLOAD_FILE=\"$DOWNLOAD_DIR/files\";\no\
ur $TMP=\"$BASE/tmp\";\n\n&add_dir($BASE);\n&add_d\
ir($BIN);\n&add_dir($DOWNLOAD_DIR);\n&add_dir($DOW\
NLOAD_FILE);\nif (!$DISTRIBUTIONS){$DISTRIBUTIONS=\
\"$DOWNLOAD_DIR/distributions\";}\n&add_dir ($DIST\
RIBUTIONS);\n&add_dir ($TMP);\n\n\nif    (!$PLUGIN\
S_DIR && !$ROOT_INSTALL){$PLUGINS_DIR=$TCPLUGINS;}\
\nelsif (!$PLUGINS_DIR &&  $ROOT_INSTALL){$PLUGINS\
_DIR=\"/usr/local/bin/\";}\n\nif    (!$INSTALL_DIR\
 && !$ROOT_INSTALL){$INSTALL_DIR=\"$HOME/bin/\";mk\
path ($INSTALL_DIR);}\nelsif (!$INSTALL_DIR &&  $R\
OOT_INSTALL){$INSTALL_DIR=\"/usr/local/bin/\";}\n\\
nif (-d \"mcoffee\"){`cp mcoffee/* $TCM`;}\n\n\nou\
r $ENV_FILE=\"$TCDIR/t_coffee_env\";\n&env_file2pu\
tenv ($ENV_FILE);\n&set_proxy($proxy);\nmy ($targe\
t, $p, $r);\n$target=$p;\n\nforeach $p (  ((keys (\
%PG)),(keys(%MODE)),(@smode)) )\n  {\n    if ($ARG\
V[0] eq $p && $target eq \"\"){$target=$p;}\n  }\n\
if ($target eq \"\"){exit ($EXIT_FAILURE);}\n\n\nf\
oreach $r (@required_applications)\n  {\n    my @a\
pp_list;\n    my $i;\n    $i=0;\n    \n    @app_li\
st=split (/_OR_/, $r);\n    foreach my $pg (@app_l\
ist)\n      {\n	$i+=&pg_is_installed ($pg);\n     \
 }\n    if ($i==0)\n      {\n      print \"One of \
the following packages must be installed to procee\
d: \";\n      foreach my $pg (@app_list)\n	{\n	  p\
rint (\"$pg \");\n	}\n      die;\n    }\n  }\n\n\n\
\n\n\n\n&sign_license_ni();\n\n\n$PG{C}{compiler}=\
get_C_compiler($CC);\n$PG{Fortran}{compiler}=get_F\
_compiler($FC);\n$PG{CXX}{compiler}=$PG{CPP}{compi\
ler}=$PG{GPP}{compiler}=get_CXX_compiler($CXX);\ni\
f ($CXXFLAGS){$PG{CPP}{options}=$PG{GPP}{options}=\
$PG{CXX}{options}=$CXXFLAGS;}\nif ($CFLAGS ne \"\"\
 ){$PG{C}{options}=$CFLAGS;}\nforeach my $c (keys(\
%PG))\n  {\n    my $arguments;\n    if ($PG{$c}{co\
mpiler})\n      {\n	$arguments=\"$PG{$c}{compiler_\
flag}=$PG{$c}{compiler} \";\n	if ($PG{$c}{options}\
)\n	  {\n	    $arguments.=\"$PG{$c}{options_flag}=\
'\" . $PG{$c}{options} . \"' \";\n	  }\n	$PG{$c}{a\
rguments}=$arguments;\n      }\n  }\n\nif ($PG{$ta\
rget}){$PG{$target}{install}=1;}\nelse\n  {\n    f\
oreach my $pg (keys(%PG))\n      {\n	if ( $target \
eq \"all\" || ($PG{$pg}{mode}=~/$target/))\n	  {\n\
	    $PG{$pg} {install}=1;\n	  }\n      }\n  }\n\n\
foreach my $pg (keys(%PG))\n  {\n    if (!$PG{$pg}\
{update_action}){$PG{$pg}{update_action}=$default_\
update_action;}\n    elsif ($PG{$pg}{update_action\
} eq \"never\"){$PG{$pg}{install}=0;}\n    if ( $f\
orce && $PG{$pg}{install})\n      {\n	`rm $BIN/$pg\
 $BIN/$pg.exe $SILENT`;\n      }\n    if ($PG{$pg}\
{update_action} eq \"update\" && $PG{$pg}{install}\
){$PG{$pg}{update}=1;}\n  }\n\nif (($target=~/clea\
n/))\n  {\n    print \"------- cleaning executable\
s -----\\n\";\n    `rm bin/* $SILENT`;\n    exit (\
$EXIT_SUCCESS);\n  }\n\nif ( !$PG{$target}){print \
\"------- Installing T-Coffee Modes\\n\";}\n\nfore\
ach my $m (keys(%MODE))\n  {\n    if ( $target eq \
\"all\" || $target eq $m)\n      {\n	print \"\\n--\
----- The installer will now install the $m compon\
ents $MODE{$m}{description}\\n\";\n	foreach my $pg\
 (keys(%PG))\n	  {\n	    if ( $PG{$pg}{mode} =~/$m\
/ && $PG{$pg}{install})\n	      {\n		if ($PG{$pg}{\
touched}){print \"------- $PG{$pg}{dname}: already\
 processed\\n\";}\n		else {$PG{$pg}{success}=&inst\
all_pg($pg);$PG{$pg}{touched}=1;}\n	      }\n	  }\\
n      }\n  }\n\nif ( $PG{$target}){print \"------\
- Installing Individual Package\\n\";}\nforeach my\
 $pg (keys (%PG))\n  {\n    \n    if ( $PG{$pg}{in\
stall} && !$PG{$pg}{touched})\n      {\n	print \"\\
\n------- Install $pg\\n\";\n	$PG{$pg}{success}=&i\
nstall_pg($pg);$PG{$pg}{touched}=1;\n      }\n  }\\
nprint \"------- Finishing The installation\\n\";\\
nmy $final_report=&install ($INSTALL_DIR);\n\nprin\
t \"\\n\";\nprint \"******************************\
***************************************\\n\";\npri\
nt \"********              INSTALLATION SUMMARY   \
       *****************\\n\";\nprint \"**********\
**************************************************\
*********\\n\";\nprint \"------- SUMMARY package I\
nstallation:\\n\";\nprint \"-------   Executable I\
nstalled in: $PLUGINS_DIR\\n\";\n\nforeach my $pg \
(keys(%PG))\n  {\n    if ( $PG{$pg}{install})\n   \
   {\n	my $bin_status=($PG{$pg}{from_binary} && $P\
G{$pg}{success})?\"[from binary]\":\"\";\n	if     \
( $PG{$pg}{new} && !$PG{$pg}{old})                \
     {print \"*------        $PG{$pg}{dname}: inst\
alled $bin_status\\n\"; $PG{$pg}{status}=1;}\n	els\
if  ( $PG{$pg}{new} &&  $PG{$pg}{old})            \
         {print \"*------        $PG{$pg}{dname}: \
updated $bin_status\\n\"  ; $PG{$pg}{status}=1;} \\
n	elsif  (!$PG{$pg}{new} &&  $PG{$pg}{old} && !$PG\
{$pg}{update}){print \"*------        $PG{$pg}{dna\
me}: previous\\n\" ; $PG{$pg}{status}=1;}\n	elsif \
 (!$PG{$pg}{new} &&  $PG{$pg}{old} &&  $PG{$pg}{up\
date}){print \"*------        $PG{$pg}{dname}: fai\
led update (previous installation available)\\n\";\
$PG{$pg}{status}=0;}\n	else                       \
                                   {print \"*-----\
-        $PG{$pg}{dname}: failed installation\\n\"\
;$PG{$pg}{status}=0;}\n      }\n  }\nmy $failure;\\
n\nif ( !$PG{$target}){print \"*------ SUMMARY mod\
e Installation:\\n\";}\nforeach my $m (keys(%MODE)\
)\n  {\n  \n    if ( $target eq \"all\" || $target\
 eq $m)\n      {\n	my $succesful=1;\n	foreach my $\
pg (keys(%PG))\n	  {\n	    if (($PG{$pg}{mode}=~/$\
m/) && $PG{$pg}{install} && $PG{$pg}{status}==0)\n\
	      {\n		$succesful=0;\n		print \"*!!!!!!      \
 $PG{$pg}{dname}: Missing\\n\";\n	      }\n	  }\n	\
if ( $succesful)\n	  {\n	    $MODE{$m}{status}=1;\\
n	    print \"*------       MODE $MODE{$m}{dname} \
SUCCESSFULLY installed\\n\";\n	  }\n	else\n	  {\n	\
    $failure++;\n	    $MODE{$m}{status}=0;\n	    p\
rint \"*!!!!!!       MODE $MODE{$m}{dname} UNSUCCE\
SSFULLY installed\\n\";\n	  }\n      }\n  }\n\n   \
 \n      \nif ($clean==1 && ($BASE=~/install4tcoff\
ee/) ){print \"*------ Clean Installation Director\
y: $BASE\\n\";`rm -rf $BASE`;}\nforeach my $pg (ke\
ys(%PG)){if ($PG{$pg}{install} && $PG{$pg}{status}\
==0){exit ($EXIT_FAILURE);}}\n\nif ($failure)\n  {\
\n    print \"************************************\
*********************************\\n\";\n    print\
 \"********     SOME PACKAGES FAILED TO INSTALL   \
     *****************\\n\";\n    print \"********\
**************************************************\
***********\\n\";\n    print \"\\nSome of the repo\
rted failures may be due to connectivity problems\\
";\n    print \"\\nRerun the installation and the \
installer will specifically try to install the mis\
sing packages\";\n    print \"\\nIf this Fails, go\
 to the original website and install the package m\
anually\";\n  }\n\nprint \"***********************\
**********************************************\\n\\
";\nprint \"********              FINALIZE YOUR IN\
STALLATION    *****************\\n\";\nprint \"***\
**************************************************\
****************\\n\";\nprint \"------- Your execu\
tables are in:\\n\"; \nprint \"-------       $PLUG\
INS_DIR:\\n\";\nprint \"------- Add this directory\
 to your path with the following command:\\n\";\np\
rint \"-------       export PATH=$PLUGINS_DIR:\\$P\
ATH\\n\";\nprint \"------- Make this permanent by \
adding this line to the file:\\n\";\nprint \"-----\
--       $HOME/.bashrc\\n\";\nexit ($EXIT_SUCCESS)\
;  \n  \nsub get_CXX_compiler\n  {\n    my $c=@_[0\
];\n    my (@clist)=(\"g++\");\n    \n    return g\
et_compil ($c, @clist);\n }\nsub get_C_compiler\n \
 {\n    my $c=@_[0];\n    my (@clist)=(\"gcc\", \"\
cc\", \"icc\");\n    \n    return get_compil ($c, \
@clist);\n }\n\nsub get_F_compiler\n  {\n    my ($\
c)=@_[0];\n    my @clist=(\"f77\", \"g77\",\"g95\"\
, \"gfortran\", \"ifort\");\n    return get_compil\
 ($c, @clist);\n  } \n       \nsub get_compil\n  {\
\n    my ($fav,@clist)=(@_);\n    \n    #return th\
e first compiler found installed in the system. Ch\
eck first the favorite\n    foreach my $c ($fav,@c\
list)\n      {\n	if  (&pg_is_installed ($c)){retur\
n $c;}\n      }\n    return \"\";\n  }\nsub exit_i\
f_pg_not_installed\n  {\n    my (@arg)=(@_);\n    \
\n    foreach my $p (@arg)\n      {\n	if ( !&pg_is\
_installed ($p))\n	  {\n	    print \"!!!!!!!! The \
$p utility must be installed for this installation\
 to proceed [FATAL]\\n\";\n	    die;\n	  }\n      \
}\n    return 1;\n  }\nsub set_proxy\n  {\n    my \
($proxy)=(@_);\n    my (@list,$p);\n    \n    @lis\
t= (\"HTTP_proxy\", \"http_proxy\", \"HTTP_PROXY\"\
, \"ALL_proxy\", \"all_proxy\",\"HTTP_proxy_4_TCOF\
FEE\",\"http_proxy_4_TCOFFEE\");\n    \n    if (!$\
proxy)\n      {\n	foreach my $p (@list)\n	  {\n	  \
  if ( ($ENV_SET{$p}) || $ENV{$p}){$proxy=$ENV{$p}\
;}\n	  }\n      }\n    foreach my $p(@list){$ENV{$\
p}=$proxy;}\n  }\n	\nsub check_internet_connection\
\n  {\n    my $internet;\n    \n    if ( -e \"x\")\
{unlink (\"x\");}\n    if     (&pg_is_installed   \
 (\"wget\")){`wget www.google.com -Ox >/dev/null 2\
>/dev/null`;}\n    elsif  (&pg_is_installed    (\"\
curl\")){`curl www.google.com -ox >/dev/null 2>/de\
v/null`;}\n    else\n      {\n	printf stderr \"\\n\
ERROR: No pg for remote file fetching [wget or cur\
l][FATAL]\\n\";\n	exit ($EXIT_FAILURE);\n      }\n\
    \n    if ( !-e \"x\" || -s \"x\" < 10){$intern\
et=0;}\n    else {$internet=1;}\n    if (-e \"x\")\
{unlink \"x\";}\n    return $internet;\n  }\nsub u\
rl2file\n  {\n    my ($cmd, $file,$wget_arg, $curl\
_arg)=(@_);\n    my ($exit,$flag, $pg, $arg);\n   \
 \n    if ($INTERNET || check_internet_connection \
()){$INTERNET=1;}\n    else\n      {\n	print STDER\
R \"ERROR: No Internet Connection [FATAL:install.p\
l]\\n\";\n	exit ($EXIT_FAILURE);\n      }\n    \n \
   if     (&pg_is_installed    (\"wget\")){$pg=\"w\
get\"; $flag=\"-O\";$arg=\"--tries=2 --connect-tim\
eout=10 $wget_arg\";}\n    elsif  (&pg_is_installe\
d    (\"curl\")){$pg=\"curl\"; $flag=\"-o\";$arg=$\
curl_arg;}\n    else\n      {\n	printf stderr \"\\\
nERROR: No pg for remote file fetching [wget or cu\
rl][FATAL]\\n\";\n	exit ($EXIT_FAILURE);\n      }\\
n    \n    \n    if (-e $file){unlink($file);}\n  \
  $exit=system \"$pg $cmd $flag$file $arg\";\n    \
return $exit;\n  }\n\nsub pg_is_installed\n  {\n  \
  my ($p, $dir)=(@_);\n    my ($r,$m, $ret);\n    \
my ($supported, $language, $compil);\n    \n  \n  \
  if ( $PG{$p})\n      {\n	$language=$PG{$p}{langu\
age2};\n	$compil=$PG{$language}{compiler};\n      \
}\n    \n    if ( $compil eq \"CPAN\")\n      {\n	\
if ( system (\"perl -M$p -e 1\")==$EXIT_SUCCESS){$\
ret=1;}\n	else {$ret=0;}\n      }\n    elsif ($dir\
)\n      {\n	if (-e \"$dir/$p\" || -e \"$dir/$p\\.\
exe\"){$ret=1;}\n	else {$ret=0;}\n      }\n    els\
if (-e \"$PLUGINS_DIR/$p\" || -e \"$PLUGINS_DIR/$p\
.exe\"){$ret=1;}\n    else\n      {\n	$r=`which $p\
 2>/dev/null`;\n	if ($r eq \"\"){$ret=0;}\n	else {\
$ret=1;}\n      }\n   \n    return $ret;\n  }\nsub\
 install\n  {\n    my ($new_bin)=(@_);\n    my ($c\
opied, $report);\n\n    \n    if (!$ROOT_INSTALL)\\
n      {\n	\n	if (-e \"$BIN/t_coffee\"){`$CP $BIN/\
t_coffee $INSTALL_DIR`};\n	`cp $BIN/* $PLUGINS_DIR\
`;\n	$copied=1;\n      }\n    else\n      {\n	$cop\
ied=&root_run (\"You must be root to finalize the \
installation\", \"$CP $BIN/* $INSTALL_DIR $SILENT\\
");\n      }\n    \n     \n  if ( !$copied)\n    {\
\n      $report=\"*!!!!!! Installation unsuccesful\
. The executables have been left in $BASE/bin\\n\"\
;\n    }\n  elsif ( $copied && $ROOT)\n    {\n    \
  $report=\"*------ Installation succesful. Your e\
xecutables have been copied in $new_bin and are on\
 your PATH\\n\";\n    }\n  elsif ( $copied && !$RO\
OT)\n    {\n      $report= \"*!!!!!! T-Coffee and \
associated packages have been copied in: $new_bin\\
\n\";\n      $report.=\"*!!!!!! This address is NO\
T in your PATH sytem variable\\n\";\n      $report\
.=\"*!!!!!! You can do so by adding the following \
line in your ~/.bashrc file:\\n\";\n      $report.\
=\"*!!!!!! export PATH=$new_bin:\\$PATH\\n\";\n   \
 }\n  return $report;\n}\n\nsub sign_license_ni\n \
 {\n    my $F=new FileHandle;\n    open ($F, \"lic\
ense.txt\");\n    while (<$F>)\n      {\n	print \"\
$_\";\n      }\n    close ($F);\n    \n    return;\
\n  }\n\nsub install_pg\n  {\n    my ($pg)=(@_);\n\
    my ($report, $previous, $language, $compiler, \
$return);\n    \n    if (!$PG{$pg}{install}){retur\
n 1;}\n    \n    $previous=&pg_is_installed ($pg);\
\n    \n    if ($PG{$pg}{update_action} eq \"no_up\
date\" && $previous)\n      {\n	$PG{$pg}{old}=1;\n\
	$PG{$pg}{new}=0;\n	$return=1;\n      }\n    else\\
n      {\n	$PG{$pg}{old}=$previous;\n	\n	if ($PG{$\
pg} {language2} eq \"Perl\"){&install_perl_package\
 ($pg);}\n	elsif ($BINARIES_ONLY && &install_binar\
y_package ($pg)){$PG{$pg}{from_binary}=1;}\n	elsif\
 (&install_source_package ($pg)){;}\n	else \n	  {\\
n	    \n	    if (!&supported_os($OS))\n	      {\n	\
	print \"!!!!!!!! $pg compilation failed, binary u\
nsupported for $OS\\n\"; \n	      }\n	    elsif (!\
($PG{$pg}{from_binary}=&install_binary_package ($p\
g)))\n	      {\n		print \"!!!!!!!! $pg compilation\
 and  binary installation failed\\n\";\n	      }\n\
	  }\n	$PG{$pg}{new}=$return=&pg_is_installed ($pg\
,$BIN);\n      }\n\n    \n    return $return;\n  }\
\nsub install_perl_package\n  {\n    my ($pg)=(@_)\
;\n    my ($report, $language, $compiler);\n    \n\
    $language=$PG{$pg} {language2};\n    $compiler\
=$PG{$language}{compiler};\n    \n    if (!&pg_is_\
installed ($pg))\n      {\n	if ( $OS eq \"windows\\
"){`perl -M$compiler -e 'install $pg'`;}\n	elsif (\
 $ROOT eq \"sudo\"){system (\"sudo perl -M$compile\
r -e 'install $pg'\");}\n	else {system (\"su root \
-c perl -M$compiler -e 'install $pg'\");}\n      }\
\n    return &pg_is_installed ($pg);\n  }\n\n\n\ns\
ub install_source_package\n  {\n    my ($pg)=(@_);\
\n    my ($report, $download, $arguments, $languag\
e, $address, $name, $ext, $main_dir, $distrib);\n \
   my $wget_tmp=\"$TMP/wget.tmp\";\n    my (@fl);\\
n    if ( -e \"$BIN/$pg\" || -e \"$BIN/$pg.exe\"){\
return 1;}\n    \n    #\n    # check if the module\
 exists in the repository cache \n    #\n	if( repo\
_load($pg) ) {\n		return 1;\n	}\n    \n    if ($pg\
 eq \"t_coffee\")  {return   &install_t_coffee ($p\
g);}\n    elsif ($pg eq \"TMalign\"){return   &ins\
tall_TMalign ($pg);}\n    \n    chdir $DISTRIBUTIO\
NS;\n    \n    $download=$PG{$pg}{source};\n    \n\
    if (($download =~/tgz/))\n      {\n	($address,\
$name,$ext)=($download=~/(.+\\/)([^\\/]+)(\\.tgz).\
*/);\n      }\n    elsif (($download=~/tar\\.gz/))\
\n      {\n	($address,$name,$ext)=($download=~/(.+\
\\/)([^\\/]+)(\\.tar\\.gz).*/);\n      }\n    elsi\
f (($download=~/tar/))\n      {\n	($address,$name,\
$ext)=($download=~/(.+\\/)([^\\/]+)(\\.tar).*/);\n\
      }\n    else\n      {\n	($address,$name)=($do\
wnload=~/(.+\\/)([^\\/]+)/);\n	$ext=\"\";\n      }\
\n    $distrib=\"$name$ext\";\n    \n    if ( !-d \
$pg){mkdir $pg;}\n    chdir $pg;\n   \n    #get th\
e distribution if available\n    if ( -e \"$DOWNLO\
AD_DIR/$distrib\")\n      {\n	`$CP $DOWNLOAD_DIR/$\
distrib .`;\n      }\n    #UNTAR and Prepare every\
thing\n    if (!-e \"$name.tar\" && !-e \"$name\")\
\n      {\n	&check_rm ($wget_tmp);\n	print \"\\n--\
----- Downloading/Installing $pg\\n\";\n	\n	if (!-\
e $distrib && &url2file (\"$download\", \"$wget_tm\
p\")==$EXIT_SUCCESS)\n	  {\n	    \n	    `mv $wget_\
tmp $distrib`;\n	    `$CP $distrib $DOWNLOAD_DIR/`\
;\n	  }\n\n	if (!-e $distrib)\n	  {\n	    print \"\
!!!!!!! Download of $pg distribution failed\\n\";\\
n	    print \"!!!!!!! Check Address: $PG{$pg}{sour\
ce}\\n\";\n	    return 0;\n	  }\n	print \"\\n-----\
-- unzipping/untaring $name\\n\";\n	if (($ext =~/z\
/))\n	  { \n	    &flush_command (\"gunzip $name$ex\
t\");\n	    \n	  }\n	if (($ext =~/tar/) || ($ext =\
~/tgz/))\n	  {\n	    &flush_command(\"tar -xvf $na\
me.tar\");\n	  }\n      }\n    #Guess and enter th\
e distribution directory\n    @fl=ls($p);\n    for\
each my $f (@fl)\n      {\n	if (-d $f)\n	  {\n	   \
 $main_dir=$f;\n	  }\n      }\n    if (-d $main_di\
r)\n	  \n      {\n	chdir $main_dir;}\n    else\n  \
    {\n	print \"Error: $main_dir does not exist\";\
\n      }\n    print \"\\n------- Compiling/Instal\
ling $pg\\n\";\n    `make clean $SILENT`;\n    \n \
   \n    #\n    # SAP module\n    #\n    if ($pg e\
q \"sap\")\n      {\n	if (-e \"./configure\")\n	  \
{\n	    #new sap distribution\n	    \n	    &flush_\
command (\"./configure\");\n	    &flush_command (\\
"make clean\");\n	    &flush_command (\"make\");\n\
	    &check_cp (\"./src/$pg\", \"$BIN\");\n	    re\
po_store(\"./src/$pg\");\n	  }\n	else\n	  {\n	    \
#old style distribution\n	    `rm *.o sap  sap.exe\
 ./util/aa/*.o  ./util/wt/.o $SILENT`;\n	    &flus\
h_command (\"make $arguments sap\");\n	    &check_\
cp ($pg, \"$BIN\");\n	    repo_store($pg);\n	  }\n\
      }\n    \n    #\n    # CLUSTALW2 module\n    \
#\n    elsif ($pg eq \"clustalw2\")\n      {\n	&fl\
ush_command(\"./configure\");\n	&flush_command(\"m\
ake $arguments\");\n	&check_cp (\"./src/$pg\", \"$\
BIN\");\n	repo_store(\"./src/$pg\");\n      }\n\n \
   #\n    # CLUSTAL-OMEGA module\n    #\n    elsif\
 ($pg eq \"clustalo\")\n      {\n	&flush_command(\\
"./configure\");\n	&flush_command(\"make $argument\
s\");\n	&check_cp (\"./src/$pg\", \"$BIN\");\n	rep\
o_store(\"./src/$pg\");\n      }\n\n    #\n    # S\
TRIKE module\n    #\n    elsif ($pg eq \"strike\")\
\n      {\n	&flush_command(\"make $arguments\");\n\
	&check_cp (\"./bin/$pg\", \"$BIN\");\n	repo_store\
(\"./bin/$pg\");\n      }\n    \n    #\n    # FSA \
module\n    # \n    elsif ($pg eq \"fsa\")\n      \
{\n	&flush_command(\"./configure --prefix=$BIN\");\
\n	&flush_command(\"make $arguments\");\n	&flush_c\
ommand (\"make install\");\n\n	repo_store(\"fsa\",\
 \"$BIN/bin\");\n	`mv $BIN/bin/* $BIN`;\n	`rmdir $\
BIN/bin`;\n      }\n    \n    #\n    # CLUSTALW mo\
dule\n    #\n    elsif ($pg eq \"clustalw\")\n    \
  {\n	&flush_command(\"make $arguments clustalw\")\
;\n	`$CP $pg $BIN $SILENT`;\n	repo_store($pg);\n  \
    }\n    \n    #\n    # MAFFT module\n    #\n   \
 elsif ($pg eq \"mafft\")\n      {\n	my $base=cwd(\
);\n	my $c;\n	\n	#compile core\n	mkpath (\"./mafft\
/bin\");\n	mkpath (\"./mafft/lib\");\n	chdir \"$ba\
se/core\";\n	`make clean $SILENT`;\n	&flush_comman\
d (\"make $arguments\");\n	&flush_command (\"make \
install LIBDIR=../mafft/lib BINDIR=../mafft/bin\")\
;\n	\n	#compile extension\n	chdir \"$base/extensio\
ns\";\n	`make clean $SILENT`;\n	&flush_command (\"\
make $arguments\");\n	&flush_command (\"make insta\
ll LIBDIR=../mafft/lib BINDIR=../mafft/bin\");\n	\\
n	#put everything in mafft and copy the compiled s\
tuff in bin\n	chdir \"$base\";\n	if ($ROOT_INSTALL\
)\n	  {\n	    &root_run (\"You Must be Root to Ins\
tall MAFFT\\n\", \"mkdir /usr/local/mafft/;$CP maf\
ft/lib/* /usr/local/mafft;$CP mafft/lib/mafft* /us\
r/local/bin ;$CP mafft/bin/mafft /usr/local/bin/; \
\");\n	  }\n	else\n	  {\n	    `$CP mafft/lib/*  $B\
IN`;\n	    `$CP mafft/bin/mafft  $BIN`;\n	  }\n	`t\
ar -cvf mafft.tar mafft`;\n	`gzip mafft.tar`;\n	`m\
v mafft.tar.gz $BIN`;\n	\n	repo_store(\"mafft/bin/\
mafft\", \"mafft/lib/\", \"$BIN/mafft.tar.gz\");\n\
      }\n      \n    #\n    # DIALIGN-TX module\n \
   #\n    elsif ( $pg eq \"dialign-tx\" )\n      {\
\n	my $f;\n	my $base=cwd();\n\n	chdir \"./source\"\
;\n	if ($OS eq \"macosx\"){&flush_command (\"cp ma\
kefile.MAC_OS makefile\");}\n\n	&flush_command (\"\
 make CPPFLAGS='-O3 -funroll-loops' all\");\n	\n	c\
hdir \"..\";\n	&check_cp (\"./source/$pg\", \"$BIN\
\");\n	repo_store(\"./source/$pg\");\n      }\n   \
   \n    #\n    # DIALIGN-T module \n    # (is the\
 same as dialign-tx, but it is mantained for backw\
ard name compatibility with tcoffee)\n    #\n    e\
lsif ( $pg eq \"dialign-t\" )\n      {\n	my $f;\n	\
my $base=cwd();\n\n	chdir \"./source\";\n	if ($OS \
eq \"macosx\"){&flush_command (\"cp makefile.MAC_O\
S makefile\");}\n\n	&flush_command (\" make CPPFLA\
GS='-O3 -funroll-loops' all\");\n	\n	chdir \"..\";\
\n	&check_cp (\"./source/dialign-tx\", \"$BIN/dial\
ign-t\");\n	repo_store(\"$BIN/dialign-t\");	\n    \
  }      \n      \n    #\n    # POA module\n    #\\
n    elsif ($pg eq \"poa\")\n      {\n	&flush_comm\
and (\"make $arguments poa\");\n	&check_cp (\"$pg\\
", \"$BIN\");\n	repo_store(\"$pg\");\n      }\n   \
  \n     \n    #\n    # PROBCONS module\n    #\n  \
  elsif ( $pg eq \"probcons\")\n      {\n	&add_C_l\
ibraries(\"./ProbabilisticModel.h\", \"list\", \"c\
string\");\n	\n	`rm *.exe $SILENT`;\n	&flush_comma\
nd (\"make $arguments probcons\");\n	&check_cp(\"$\
pg\", \"$BIN/$pg\");\n	repo_store(\"$pg\");\n     \
 }\n      \n    #\n    # PROBCONS RNA module\n    \
#\n    elsif ( $pg eq \"probconsRNA\")\n      {\n	\
&add_C_libraries(\"./ProbabilisticModel.h\", \"lis\
t\", \"cstring\");\n	&add_C_libraries(\"./Main.cc\\
", \"iomanip\", \"cstring\",\"climits\");\n	`rm *.\
exe $SILENT`;\n	&flush_command (\"make $arguments \
probcons\");\n	&check_cp(\"probcons\", \"$BIN/$pg\\
");\n	repo_store(\"$BIN/$pg\");\n      }\n\n	#\n	#\
 MUSCLE module\n	#\n    elsif (  $pg eq \"muscle\"\
)\n      {	\n	`rm *.o muscle muscle.exe $SILENT`;\\
n	if ($OS eq \"macosx\" || $OS eq \"linux\")\n	  {\
\n	    &replace_line_in_file (\"./Makefile\", \"LD\
LIBS = -lm -static\",  \"LDLIBS = -lm\");\n	  }\n	\
elsif ($OS eq \"windows\")\n	  {\n	    &replace_li\
ne_in_file (\"./intmath.cpp\",  \"double log2e\", \
     \"double cedric_log\");\n	    &replace_line_i\
n_file (\"./intmath.cpp\",  \"double log2\",      \
 \"double log_notuse\");\n	    &replace_line_in_fi\
le (\"./intmath.cpp\",  \"double cedric_log\", \"d\
ouble log2e\");\n	  }\n	&flush_command (\"make $ar\
guments all\");\n	&check_cp(\"$pg\", \"$BIN\");\n	\
repo_store(\"$pg\");	\n      }\n      \n     #\n  \
   # MUS4 module\n     #\n     elsif (  $pg eq \"m\
us4\")\n      {\n	`rm *.o muscle muscle.exe $SILEN\
T`;\n	&flush_command (\"./mk\");\n	&check_cp(\"$pg\
\", \"$BIN\");\n	repo_store(\"$pg\");	\n      }\n \
     \n    #\n    # PCMA module\n    #\n    elsif \
( $pg eq \"pcma\")\n      {\n	if ($OS eq \"macosx\\
")\n	  {\n	    &replace_line_in_file (\"./alcomp2.\
c\", \"malloc.h\",  \"\");\n	  }\n	&flush_command \
(\"make $arguments pcma\");\n	&check_cp(\"$pg\", \\
"$BIN\");\n	repo_store(\"$pg\");	\n      }\n      \
\n    #\n    # KALIGN module\n    #\n    elsif ($p\
g eq \"kalign\")\n      {\n	&flush_command (\"./co\
nfigure\");\n	&flush_command(\"make $arguments\");\
\n	&check_cp (\"$pg\",$BIN);\n	repo_store(\"$pg\")\
;	\n      }\n      \n    #\n    # AMAP module\n   \
 #\n    elsif ( $pg eq \"amap\")\n      {\n	&add_C\
_libraries(\"./Amap.cc\", \"iomanip\", \"cstring\"\
,\"climits\");	\n	`make clean $SILENT`;\n	&flush_c\
ommand (\"make $arguments all\");\n	&check_cp (\"$\
pg\", $BIN);\n	repo_store(\"$pg\");	\n      }\n   \
   \n    #\n    # PRODA module\n    #\n    elsif (\
 $pg eq \"proda\")\n      {\n	&add_C_libraries(\"A\
lignedFragment.h\", \"vector\", \"iostream\", \"cs\
tring\",\"cstdlib\");\n	&add_C_libraries(\"Main.cc\
\", \"vector\", \"climits\");	\n	&add_C_libraries(\
\"Sequence.cc\", \"stdlib.h\", \"cstdio\");	\n	&fl\
ush_command (\"make $arguments all\");\n	&check_cp\
 (\"$pg\", $BIN);\n	repo_store(\"$pg\");	\n      }\
\n      \n    #\n    # PRANK module\n    #\n    el\
sif ( $pg eq \"prank\")\n      {\n	&flush_command \
(\"make $arguments all\");\n	&check_cp (\"$pg\", $\
BIN);\n	repo_store(\"$pg\");	\n      }\n      \n  \
  #\n    # !!!! MUSTANG module\n    #\n     elsif \
( $pg eq \"mustang\")\n      {\n	&flush_command (\\
"rm ./bin/*\");\n	&flush_command (\"make $argument\
s all\");\n\n	if ( $OS=~/windows/){&flush_command(\
\"cp ./bin/* $BIN/mustang.exe\");}\n	else {&flush_\
command(\"cp ./bin/* $BIN/mustang\");}\n	\n	repo_s\
tore(\"$BIN/mustang\");\n      }\n\n	#\n	# RNAplfo\
ld module\n	#\n    elsif ( $pg eq \"RNAplfold\")\n\
      {\n	&flush_command(\"./configure\");\n	&flus\
h_command (\"make $arguments all\");\n	&check_cp(\\
"./Progs/RNAplfold\", \"$BIN\");\n	&check_cp(\"./P\
rogs/RNAalifold\", \"$BIN\");\n	&check_cp(\"./Prog\
s/RNAfold\", \"$BIN\");\n	\n	repo_store(\"./Progs/\
RNAplfold\", \"./Progs/RNAalifold\", \"./Progs/RNA\
fold\");\n      }\n      \n    #\n    # !!! RETREE\
 module\n    #\n    elsif ( $pg eq \"retree\")\n  \
    {\n	chdir \"src\";\n	&flush_command (\"make $a\
rguments all\");\n	&flush_command (\"make put\");\\
n	system \"cp ../exe/* $BIN\";\n	\n	repo_store(\"r\
etree\", \"../exe\");\n      }\n	\n    chdir $CDIR\
;\n    return &pg_is_installed ($pg, $BIN);\n  }\n\
\nsub install_t_coffee\n  {\n    my ($pg)=(@_);\n \
   my ($report,$cflags, $arguments, $language, $co\
mpiler) ;\n    #1-Install T-Coffee\n    chdir \"t_\
coffee_source\";\n    &flush_command (\"make clean\
\");\n    print \"\\n------- Compiling T-Coffee\\n\
\";\n    $language=$PG{$pg} {language2};\n    $arg\
uments=$PG{$language}{arguments};\n\n    if ( $CC \
ne \"\"){\n      print \"make -i $arguments t_coff\
ee \\n\";\n      &flush_command (\"make -i $argume\
nts t_coffee\");\n    }\n    &check_cp ($pg, $BIN)\
;\n    \n    chdir $CDIR;\n    return &pg_is_insta\
lled ($pg, $BIN);\n  }\nsub install_TMalign\n  {\n\
    my ($pg)=(@_);\n    my $report;\n    chdir \"t\
_coffee_source\";\n    print \"\\n------- Compilin\
g TMalign\\n\";\n    `rm TMalign TMalign.exe $SILE\
NT`;\n    if ( $FC ne \"\"){&flush_command (\"make\
 -i $PG{Fortran}{arguments} TMalign\");}\n    &che\
ck_cp ($pg, $BIN);\n    repo_store($pg);\n\n    if\
 ( !-e \"$BIN/$pg\" && pg_has_binary_distrib ($pg)\
)\n      {\n	print \"!!!!!!! Compilation of $pg im\
possible. Will try to install from binary\\n\";\n	\
return &install_binary_package ($pg);\n      }\n  \
  chdir $CDIR;\n    return &pg_is_installed ($pg, \
$BIN);\n  }\n\nsub pg_has_binary_distrib\n  {\n   \
 my ($pg)=(@_);\n    if ($PG{$pg}{windows}){return\
 1;}\n    elsif ($PG{$pg}{osx}){return 1;}\n    el\
sif ($PG{$pg}{linux}){return 1;}\n    return 0;\n \
 }\nsub install_binary_package\n  {\n    my ($pg)=\
(@_);\n    my ($base,$report,$name, $download, $ar\
guments, $language, $dir);\n    my $isdir;\n    &i\
nput_os();\n    \n    #\n    # - paolodt - Check i\
f the module exists in the repository cache \n    \
#\n	if( repo_load($pg) ) {\n	    $PG{$pg}{from_bin\
ary}=1;\n		return 1;\n	}\n    # - paolodt - end \n\
    \n    if (!&supported_os($OS)){return 0;}\n   \
 if ( $PG{$pg}{binary}){$name=$PG{$pg}{binary};}\n\
    else \n      {\n	$name=$pg;\n	if ( $OS eq \"wi\
ndows\"){$name.=\".exe\";}\n      }\n    \n    $do\
wnload=\"$WEB_BASE/Packages/Binaries/$OS/$name\";\\
n    \n    $base=cwd();\n    chdir $TMP;\n    \n  \
  if (!-e $name)\n      {\n	`rm x $SILENT`;\n	if (\
 url2file(\"$download\",\"x\")==$EXIT_SUCCESS)\n	 \
 {\n	    `mv x $name`;\n	  }\n      }\n    \n    i\
f (!-e $name)\n      {\n	print \"!!!!!!! $PG{$pg}{\
dname}: Download of $pg binary failed\\n\";\n	prin\
t \"!!!!!!! $PG{$pg}{dname}: Check Address: $downl\
oad\\n\";\n	return 0;\n      }\n    print \"\\n---\
---- Installing $pg\\n\";\n    \n    if ($name =~/\
tar\\.gz/)\n      {\n	`gunzip  $name`;\n	`tar -xvf\
 $pg.tar`;\n	chdir $pg;\n	if ( $pg eq \"mafft\")\n\
	  {\n	    if ($ROOT_INSTALL)\n	      {\n		&root_r\
un (\"You Must be Roor to Install MAFFT\\n\", \"$C\
P mafft/bin/* /usr/local/mafft;mkdir /usr/local/ma\
fft/; $CP mafft/lib/* /usr/local/bin/\");\n	      \
}\n	    else\n	      {\n		`$CP $TMP/$pg/bin/* $BIN\
 $SILENT`;\n		`$CP $TMP/$pg/lib/* $BIN $SILENT`;\n\
	      }\n	  }\n	else\n	  {\n	    if (-e \"$TMP/$p\
g/data\"){`$CP $TMP/$pg/data/* $TCM $SILENT`;}\n	 \
   if (!($pg=~/\\*/)){`rm -rf $pg`;}\n	  }\n      \
}\n    else\n      {\n	&check_cp (\"$pg\", \"$BIN\\
");\n	`chmod u+x $BIN/$pg`; \n	unlink ($pg);\n    \
  }\n    chdir $base;\n    $PG{$pg}{from_binary}=1\
;\n    return &pg_is_installed ($pg, $BIN);\n  }\n\
\nsub add_dir \n  {\n    my $dir=@_[0];\n    \n   \
 if (!-e $dir && !-d $dir)\n      {\n	my @l;\n	uma\
sk (0000);\n	@l=mkpath ($dir,{mode => 0777});\n	\n\
      }\n    else\n      {\n	return 0;\n      }\n \
 }\nsub check_rm \n  {\n    my ($file)=(@_);\n    \
\n    if ( -e $file)\n      {\n	return unlink($fil\
e);\n      }\n    return 0;\n  }\nsub check_cp\n  \
{\n    my ($from, $to)=(@_);\n    if ( !-e $from &\
& -e \"$from\\.exe\"){$from=\"$from\\.exe\";}\n   \
 if ( !-e $from){return 0;}\n        \n    `$CP $f\
rom $to`;\n    return 1;\n  }\n\nsub repo_store \n\
{\n   # check that all required data are available\
\n   if( $REPO_ROOT eq \"\" ) { return; }\n\n\n   \
 # extract the package name from the specified pat\
h\n    my $pg =`basename $_[0]`;\n    chomp($pg);\\
n	\n    my $VER = $PG{$pg}{version};\n    my $CACH\
E = \"$REPO_ROOT/$pg/$VER/$OSNAME-$OSARCH\"; \n   \
 \n    print \"-------- Storing package: \\\"$pg\\\
\" to path: $CACHE\\n\";\n    \n    # clean the ca\
che path if exists and create it again\n    `rm -r\
f $CACHE`;\n    `mkdir -p $CACHE`;\n    \n 	for my\
 $path (@_) {\n\n	    # check if it is a single fi\
le \n	 	if( -f $path ) {\n	    	`cp $path $CACHE`;\
\n		}\n		# .. or a directory, in this case copy al\
l the content \n		elsif( -d $path ) {\n			opendir(\
IMD, $path);\n			my @thefiles= readdir(IMD);\n			c\
losedir(IMD);\n			\n			for my $_file (@thefiles) {\
\n				if( $_file ne \".\" && $_file ne \"..\") {\n\
	    			`cp $path/$_file $CACHE`;\n				}\n			}\n		\
} \n	}	   \n    \n	\n}   \n\nsub repo_load \n{\n  \
  my ($pg)=(@_);\n\n    # check that all required \
data are available\n    if( $REPO_ROOT eq \"\" ) {\
 return 0; }\n\n    my $VER = $PG{$pg}{version};\n\
    my $CACHE = \"$REPO_ROOT/$pg/$VER/$OSNAME-$OSA\
RCH\"; \n    if( !-e \"$CACHE/$pg\" ) {\n   	 	pri\
nt \"-------- Module \\\"$pg\\\" NOT found on repo\
sitory cache.\\n\";\n    	return 0;\n    }\n    \n\
    print \"-------- Module \\\"$pg\\\" found on r\
epository cache. Using copy on path: $CACHE\\n\";\\
n    `cp $CACHE/* $BIN`;\n    return 1;\n}\n\nsub \
check_file_list_exists \n  {\n    my ($base, @flis\
t)=(@_);\n    my $f;\n\n    foreach $f (@flist)\n \
     {\n	if ( !-e \"$base/$f\"){return 0;}\n      \
}\n    return 1;\n  }\nsub ls\n  {\n    my $f=@_[0\
];\n    my @fl;\n    chomp(@fl=`ls -1 $f`);\n    r\
eturn @fl;\n  }\nsub flush_command\n  {\n    my $c\
ommand=@_[0];\n    my $F=new FileHandle;\n    open\
 ($F, \"$command|\");\n    while (<$F>){print \"  \
  --- $_\";}\n    close ($F);\n  }    \n\nsub inpu\
t_installation_directory\n  {\n    my $dir=@_[0];\\
n    my $new;\n    \n    print \"------- The curre\
nt installation directory is: [$dir]\\n\";\n    pr\
int \"??????? Return to keep the default or new va\
lue:\";\n   \n    if ($NO_QUESTION==0)\n      {\n	\
chomp ($new=<stdin>);\n	while ( $new ne \"\" && !i\
nput_yes (\"You have entered $new. Is this correct\
? ([y]/n):\"))\n	  {\n	    print \"???????New inst\
allation directory:\";\n	    chomp ($new=<stdin>);\
\n	  }\n	$dir=($new eq \"\")?$dir:$new;\n	$dir=~s/\
\\/$//;\n      }\n    \n    if ( -d $dir){return $\
dir;}\n    elsif (&root_run (\"You must be root to\
 create $dir\",\"mkdir $dir\")==$EXIT_SUCCESS){ret\
urn $dir;}\n    else\n      {\n	print \"!!!!!!! $d\
ir could not be created\\n\";\n	if ( $NO_QUESTION)\
\n	  {\n	    return \"\";\n	  }\n	elsif ( &input_y\
es (\"??????? Do you want to provide a new directo\
ry([y]/n)?:\"))\n	  {\n	    return input_installat\
ion_directory ($dir);\n	  }\n	else\n	  {\n	    ret\
urn \"\";\n	  }\n      }\n    \n  }\nsub input_yes\
\n  {\n    my $question =@_[0];\n    my $answer;\n\
\n    if ($NO_QUESTION==1){return 1;}\n    \n    i\
f ($question eq \"\"){$question=\"??????? Do you w\
ish to proceed ([y]/n)?:\";}\n    print $question;\
\n    chomp($answer=lc(<STDIN>));\n    if (($answe\
r=~/^y/) || $answer eq \"\"){return 1;}\n    elsif\
 ( ($answer=~/^n/)){return 0;}\n    else\n      {\\
n	return input_yes($question);\n      }\n  }\nsub \
root_run\n  {\n    my ($txt, $cmd)=(@_);\n    \n  \
  if ( system ($cmd)==$EXIT_SUCCESS){return $EXIT_\
SUCCESS;}\n    else \n      {\n	print \"------- $t\
xt\\n\";\n	if ( $ROOT eq \"sudo\"){return system (\
\"sudo $cmd\");}\n	else {return system (\"su root \
-c \\\"$cmd\\\"\");}\n      }\n  }\nsub get_root\n\
  {\n    if (&pg_is_installed (\"sudo\")){return \\
"sudo\";}\n    else {return \"su\";}\n  }\n\nsub g\
et_os\n  {\n    my $raw_os=`uname`;\n    my $os;\n\
\n    $raw_os=lc ($raw_os);\n    \n    if ($raw_os\
 =~/cygwin/){$os=\"windows\";}\n    elsif ($raw_os\
 =~/linux/){$os=\"linux\";}\n    elsif ($raw_os =~\
/osx/){$os=\"macosx\";}\n    elsif ($raw_os =~/dar\
win/){$os=\"macosx\";}\n    else\n      {\n	$os=$r\
aw_os;\n      }\n    return $os;\n  }\nsub input_o\
s\n  {\n    my $answer;\n    if ($OS) {return $OS;\
}\n    \n    print \"??????? which os do you use: \
[w]indows, [l]inux, [m]acosx:?\";\n    $answer=lc(\
<STDIN>);\n\n    if (($answer=~/^m/)){$OS=\"macosx\
\";}\n    elsif ( ($answer=~/^w/)){$OS=\"windows\"\
;}\n    elsif ( ($answer=~/^linux/)){$OS=\"linux\"\
;}\n    \n    else\n      {\n	return &input_os();\\
n      }\n    return $OS;\n  }\n\nsub supported_os\
\n  {\n    my ($os)=(@_[0]);\n    return $SUPPORTE\
D_OS{$os};\n  }\n    \n    \n\n\nsub update_tclink\
db \n  {\n    my $file =@_[0];\n    my $name;\n   \
 my $F=new FileHandle;\n    my ($download, $addres\
s, $name, $l, $db);\n    \n    if ( $file eq \"upd\
ate\"){$file=$TCLINKDB_ADDRESS;}\n    \n    if ( $\
file =~/http:\\/\\// || $file =~/ftp:\\/\\//)\n   \
   {\n	($address, $name)=($download=~/(.*)\\/([^\\\
/]+)$/);\n	`rm x $SILENT`;\n	if (&url2file ($file,\
\"x\")==$EXIT_SUCCESS)\n	  {\n	    print \"-------\
 Susscessful upload of $name\";\n	    `mv x $name`\
;\n	    $file=$name;\n	  }\n      }\n    open ($F,\
 \"$file\");\n    while (<$F>)\n      {\n	my $l=$_\
;\n	if (($l =~/^\\/\\//) || ($db=~/^#/)){;}\n	elsi\
f ( !($l =~/\\w/)){;}\n	else\n	  {\n	    my @v=spl\
it (/\\s+/, $l);\n	    if ( $l=~/^MODE/)\n	      {\
\n		$MODE{$v[1]}{$v[2]}=$v[3];\n	      }\n	    els\
if ($l=~/^PG/)\n	      {\n		$PG{$v[1]}{$v[2]}=$v[3\
];\n	      }\n	  }\n      }\n    close ($F);\n    \
&post_process_PG();\n    return;\n  }\n\n\n\nsub i\
nitialize_PG\n  {\n\n$PG{\"t_coffee\"}{\"4_TCOFFEE\
\"}=\"TCOFFEE\";\n$PG{\"t_coffee\"}{\"type\"}=\"se\
quence_multiple_aligner\";\n$PG{\"t_coffee\"}{\"AD\
DRESS\"}=\"http://www.tcoffee.org\";\n$PG{\"t_coff\
ee\"}{\"language\"}=\"C++\";\n$PG{\"t_coffee\"}{\"\
language2\"}=\"CXX\";\n$PG{\"t_coffee\"}{\"source\\
"}=\"http://www.tcoffee.org/Packages/T-COFFEE_dist\
ribution.tar.gz\";\n$PG{\"t_coffee\"}{\"update_act\
ion\"}=\"always\";\n$PG{\"t_coffee\"}{\"mode\"}=\"\
tcoffee,mcoffee,rcoffee,expresso,3dcoffee\";\n$PG{\
\"clustalo\"}{\"4_TCOFFEE\"}=\"CLUSTALO\";\n$PG{\"\
clustalo\"}{\"type\"}=\"sequence_multiple_aligner\\
";\n$PG{\"clustalo\"}{\"ADDRESS\"}=\"http://www.cl\
ustal.org/omega/\";\n$PG{\"clustalo\"}{\"language\\
"}=\"C++\";\n$PG{\"clustalo\"}{\"language2\"}=\"C+\
+\";\n$PG{\"clustalo\"}{\"source\"}=\"http://www.c\
lustal.org/omega/clustal-omega-1.1.0.tar.gz\";\n$P\
G{\"clustalo\"}{\"mode\"}=\"mcoffee\";\n$PG{\"clus\
talo\"}{\"version\"}=\"1.1.0\";\n$PG{\"strike\"}{\\
"4_TCOFFEE\"}=\"STRIKE\";\n$PG{\"strike\"}{\"type\\
"}=\"sequence_alignment_scoring\";\n$PG{\"strike\"\
}{\"ADDRESS\"}=\"http://www.tcoffee.org/Projects/s\
trike/index.html\";\n$PG{\"strike\"}{\"language\"}\
=\"C++\";\n$PG{\"strike\"}{\"language2\"}=\"CXX\";\
\n$PG{\"strike\"}{\"source\"}=\"http://www.tcoffee\
.org/Projects/strike/strike_v1.2.tar.bz2\";\n$PG{\\
"strike\"}{\"mode\"}=\"tcoffee,expresso\";\n$PG{\"\
strike\"}{\"version\"}=\"1.2\";\n$PG{\"clustalw2\"\
}{\"4_TCOFFEE\"}=\"CLUSTALW2\";\n$PG{\"clustalw2\"\
}{\"type\"}=\"sequence_multiple_aligner\";\n$PG{\"\
clustalw2\"}{\"ADDRESS\"}=\"http://www.clustal.org\
\";\n$PG{\"clustalw2\"}{\"language\"}=\"C++\";\n$P\
G{\"clustalw2\"}{\"language2\"}=\"CXX\";\n$PG{\"cl\
ustalw2\"}{\"source\"}=\"http://www.clustal.org/do\
wnload/2.0.10/clustalw-2.0.10-src.tar.gz\";\n$PG{\\
"clustalw2\"}{\"mode\"}=\"mcoffee,rcoffee\";\n$PG{\
\"clustalw2\"}{\"version\"}=\"2.0.10\";\n$PG{\"clu\
stalw\"}{\"4_TCOFFEE\"}=\"CLUSTALW\";\n$PG{\"clust\
alw\"}{\"type\"}=\"sequence_multiple_aligner\";\n$\
PG{\"clustalw\"}{\"ADDRESS\"}=\"http://www.clustal\
.org\";\n$PG{\"clustalw\"}{\"language\"}=\"C\";\n$\
PG{\"clustalw\"}{\"language2\"}=\"C\";\n$PG{\"clus\
talw\"}{\"source\"}=\"http://www.clustal.org/downl\
oad/1.X/ftp-igbmc.u-strasbg.fr/pub/ClustalW/clusta\
lw1.82.UNIX.tar.gz\";\n$PG{\"clustalw\"}{\"mode\"}\
=\"mcoffee,rcoffee\";\n$PG{\"clustalw\"}{\"version\
\"}=\"1.82\";\n$PG{\"dialign-t\"}{\"4_TCOFFEE\"}=\\
"DIALIGNT\";\n$PG{\"dialign-t\"}{\"type\"}=\"seque\
nce_multiple_aligner\";\n$PG{\"dialign-t\"}{\"ADDR\
ESS\"}=\"http://dialign-tx.gobics.de/\";\n$PG{\"di\
align-t\"}{\"DIR\"}=\"/usr/share/dialign-tx/\";\n$\
PG{\"dialign-t\"}{\"language\"}=\"C\";\n$PG{\"dial\
ign-t\"}{\"language2\"}=\"C\";\n$PG{\"dialign-t\"}\
{\"source\"}=\"http://dialign-tx.gobics.de/DIALIGN\
-TX_1.0.2.tar.gz\";\n$PG{\"dialign-t\"}{\"mode\"}=\
\"mcoffee\";\n$PG{\"dialign-t\"}{\"binary\"}=\"dia\
lign-t\";\n$PG{\"dialign-t\"}{\"version\"}=\"1.0.2\
\";\n$PG{\"dialign-tx\"}{\"4_TCOFFEE\"}=\"DIALIGNT\
X\";\n$PG{\"dialign-tx\"}{\"type\"}=\"sequence_mul\
tiple_aligner\";\n$PG{\"dialign-tx\"}{\"ADDRESS\"}\
=\"http://dialign-tx.gobics.de/\";\n$PG{\"dialign-\
tx\"}{\"DIR\"}=\"/usr/share/dialign-tx/\";\n$PG{\"\
dialign-tx\"}{\"language\"}=\"C\";\n$PG{\"dialign-\
tx\"}{\"language2\"}=\"C\";\n$PG{\"dialign-tx\"}{\\
"source\"}=\"http://dialign-tx.gobics.de/DIALIGN-T\
X_1.0.2.tar.gz\";\n$PG{\"dialign-tx\"}{\"mode\"}=\\
"mcoffee\";\n$PG{\"dialign-tx\"}{\"binary\"}=\"dia\
lign-tx\";\n$PG{\"dialign-tx\"}{\"version\"}=\"1.0\
.2\";\n$PG{\"poa\"}{\"4_TCOFFEE\"}=\"POA\";\n$PG{\\
"poa\"}{\"type\"}=\"sequence_multiple_aligner\";\n\
$PG{\"poa\"}{\"ADDRESS\"}=\"http://www.bioinformat\
ics.ucla.edu/poa/\";\n$PG{\"poa\"}{\"language\"}=\\
"C\";\n$PG{\"poa\"}{\"language2\"}=\"C\";\n$PG{\"p\
oa\"}{\"source\"}=\"http://downloads.sourceforge.n\
et/poamsa/poaV2.tar.gz\";\n$PG{\"poa\"}{\"DIR\"}=\\
"/usr/share/\";\n$PG{\"poa\"}{\"FILE1\"}=\"blosum8\
0.mat\";\n$PG{\"poa\"}{\"mode\"}=\"mcoffee\";\n$PG\
{\"poa\"}{\"binary\"}=\"poa\";\n$PG{\"poa\"}{\"ver\
sion\"}=\"2.0\";\n$PG{\"probcons\"}{\"4_TCOFFEE\"}\
=\"PROBCONS\";\n$PG{\"probcons\"}{\"type\"}=\"sequ\
ence_multiple_aligner\";\n$PG{\"probcons\"}{\"ADDR\
ESS\"}=\"http://probcons.stanford.edu/\";\n$PG{\"p\
robcons\"}{\"language2\"}=\"CXX\";\n$PG{\"probcons\
\"}{\"language\"}=\"C++\";\n$PG{\"probcons\"}{\"so\
urce\"}=\"http://probcons.stanford.edu/probcons_v1\
_12.tar.gz\";\n$PG{\"probcons\"}{\"mode\"}=\"mcoff\
ee\";\n$PG{\"probcons\"}{\"binary\"}=\"probcons\";\
\n$PG{\"probcons\"}{\"version\"}=\"1.12\";\n$PG{\"\
mafft\"}{\"4_TCOFFEE\"}=\"MAFFT\";\n$PG{\"mafft\"}\
{\"type\"}=\"sequence_multiple_aligner\";\n$PG{\"m\
afft\"}{\"ADDRESS\"}=\"http://align.bmr.kyushu-u.a\
c.jp/mafft/online/server/\";\n$PG{\"mafft\"}{\"lan\
guage\"}=\"C\";\n$PG{\"mafft\"}{\"language\"}=\"C\\
";\n$PG{\"mafft\"}{\"source\"}=\"http://align.bmr.\
kyushu-u.ac.jp/mafft/software/mafft-6.603-with-ext\
ensions-src.tgz\";\n$PG{\"mafft\"}{\"windows\"}=\"\
http://align.bmr.kyushu-u.ac.jp/mafft/software/maf\
ft-6.603-mingw.tar\";\n$PG{\"mafft\"}{\"mode\"}=\"\
mcoffee,rcoffee\";\n$PG{\"mafft\"}{\"binary\"}=\"m\
afft.tar.gz\";\n$PG{\"mafft\"}{\"version\"}=\"6.60\
3\";\n$PG{\"muscle\"}{\"4_TCOFFEE\"}=\"MUSCLE\";\n\
$PG{\"muscle\"}{\"type\"}=\"sequence_multiple_alig\
ner\";\n$PG{\"muscle\"}{\"ADDRESS\"}=\"http://www.\
drive5.com/muscle/\";\n$PG{\"muscle\"}{\"language\\
"}=\"C++\";\n$PG{\"muscle\"}{\"language2\"}=\"GPP\\
";\n$PG{\"muscle\"}{\"source\"}=\"http://www.drive\
5.com/muscle/downloads3.7/muscle3.7_src.tar.gz\";\\
n$PG{\"muscle\"}{\"windows\"}=\"http://www.drive5.\
com/muscle/downloads3.7/muscle3.7_win32.zip\";\n$P\
G{\"muscle\"}{\"linux\"}=\"http://www.drive5.com/m\
uscle/downloads3.7/muscle3.7_linux_ia32.tar.gz\";\\
n$PG{\"muscle\"}{\"mode\"}=\"mcoffee,rcoffee\";\n$\
PG{\"muscle\"}{\"version\"}=\"3.7\";\n$PG{\"mus4\"\
}{\"4_TCOFFEE\"}=\"MUS4\";\n$PG{\"mus4\"}{\"type\"\
}=\"sequence_multiple_aligner\";\n$PG{\"mus4\"}{\"\
ADDRESS\"}=\"http://www.drive5.com/muscle/\";\n$PG\
{\"mus4\"}{\"language\"}=\"C++\";\n$PG{\"mus4\"}{\\
"language2\"}=\"GPP\";\n$PG{\"mus4\"}{\"source\"}=\
\"http://www.drive5.com/muscle/muscle4.0_src.tar.g\
z\";\n$PG{\"mus4\"}{\"mode\"}=\"mcoffee,rcoffee\";\
\n$PG{\"mus4\"}{\"version\"}=\"4.0\";\n$PG{\"pcma\\
"}{\"4_TCOFFEE\"}=\"PCMA\";\n$PG{\"pcma\"}{\"type\\
"}=\"sequence_multiple_aligner\";\n$PG{\"pcma\"}{\\
"ADDRESS\"}=\"ftp://iole.swmed.edu/pub/PCMA/\";\n$\
PG{\"pcma\"}{\"language\"}=\"C\";\n$PG{\"pcma\"}{\\
"language2\"}=\"C\";\n$PG{\"pcma\"}{\"source\"}=\"\
ftp://iole.swmed.edu/pub/PCMA/pcma.tar.gz\";\n$PG{\
\"pcma\"}{\"mode\"}=\"mcoffee\";\n$PG{\"pcma\"}{\"\
version\"}=\"1.0\";\n$PG{\"kalign\"}{\"4_TCOFFEE\"\
}=\"KALIGN\";\n$PG{\"kalign\"}{\"type\"}=\"sequenc\
e_multiple_aligner\";\n$PG{\"kalign\"}{\"ADDRESS\"\
}=\"http://msa.cgb.ki.se\";\n$PG{\"kalign\"}{\"lan\
guage\"}=\"C\";\n$PG{\"kalign\"}{\"language2\"}=\"\
C\";\n$PG{\"kalign\"}{\"source\"}=\"http://msa.cgb\
.ki.se/downloads/kalign/current.tar.gz\";\n$PG{\"k\
align\"}{\"mode\"}=\"mcoffee\";\n$PG{\"kalign\"}{\\
"version\"}=\"1.0\";\n$PG{\"amap\"}{\"4_TCOFFEE\"}\
=\"AMAP\";\n$PG{\"amap\"}{\"type\"}=\"sequence_mul\
tiple_aligner\";\n$PG{\"amap\"}{\"ADDRESS\"}=\"htt\
p://bio.math.berkeley.edu/amap/\";\n$PG{\"amap\"}{\
\"language\"}=\"C++\";\n$PG{\"amap\"}{\"language2\\
"}=\"CXX\";\n$PG{\"amap\"}{\"source\"}=\"http://am\
ap-align.googlecode.com/files/amap.2.0.tar.gz\";\n\
$PG{\"amap\"}{\"mode\"}=\"mcoffee\";\n$PG{\"amap\"\
}{\"version\"}=\"2.0\";\n$PG{\"proda\"}{\"4_TCOFFE\
E\"}=\"PRODA\";\n$PG{\"proda\"}{\"type\"}=\"sequen\
ce_multiple_aligner\";\n$PG{\"proda\"}{\"ADDRESS\"\
}=\"http://proda.stanford.edu\";\n$PG{\"proda\"}{\\
"language\"}=\"C++\";\n$PG{\"proda\"}{\"language2\\
"}=\"CXX\";\n$PG{\"proda\"}{\"source\"}=\"http://p\
roda.stanford.edu/proda_1_0.tar.gz\";\n$PG{\"proda\
\"}{\"mode\"}=\"mcoffee\";\n$PG{\"proda\"}{\"versi\
on\"}=\"1.0\";\n$PG{\"fsa\"}{\"4_TCOFFEE\"}=\"FSA\\
";\n$PG{\"fsa\"}{\"type\"}=\"sequence_multiple_ali\
gner\";\n$PG{\"fsa\"}{\"ADDRESS\"}=\"http://fsa.so\
urceforge.net/\";\n$PG{\"fsa\"}{\"language\"}=\"C+\
+\";\n$PG{\"fsa\"}{\"language2\"}=\"CXX\";\n$PG{\"\
fsa\"}{\"source\"}=\"http://sourceforge.net/projec\
ts/fsa/files/fsa-1.15.3.tar.gz/download/\";\n$PG{\\
"fsa\"}{\"mode\"}=\"mcoffee\";\n$PG{\"fsa\"}{\"ver\
sion\"}=\"1.15.3\";\n$PG{\"prank\"}{\"4_TCOFFEE\"}\
=\"PRANK\";\n$PG{\"prank\"}{\"type\"}=\"sequence_m\
ultiple_aligner\";\n$PG{\"prank\"}{\"ADDRESS\"}=\"\
http://www.ebi.ac.uk/goldman-srv/prank/\";\n$PG{\"\
prank\"}{\"language\"}=\"C++\";\n$PG{\"prank\"}{\"\
language2\"}=\"CXX\";\n$PG{\"prank\"}{\"source\"}=\
\"http://www.ebi.ac.uk/goldman-srv/prank/src/prank\
/prank.src.100802.tgz\";\n$PG{\"prank\"}{\"mode\"}\
=\"mcoffee\";\n$PG{\"prank\"}{\"version\"}=\"10030\
3\";\n$PG{\"sap\"}{\"4_TCOFFEE\"}=\"SAP\";\n$PG{\"\
sap\"}{\"type\"}=\"structure_pairwise_aligner\";\n\
$PG{\"sap\"}{\"ADDRESS\"}=\"http://mathbio.nimr.mr\
c.ac.uk/wiki/Software\";\n$PG{\"sap\"}{\"language\\
"}=\"C\";\n$PG{\"sap\"}{\"language2\"}=\"C\";\n$PG\
{\"sap\"}{\"source\"}=\"http://mathbio.nimr.mrc.ac\
.uk/download/SAP/sap-1.1.3.tar.gz\";\n$PG{\"sap\"}\
{\"mode\"}=\"expresso,3dcoffee\";\n$PG{\"sap\"}{\"\
version\"}=\"1.1.3\";\n$PG{\"TMalign\"}{\"4_TCOFFE\
E\"}=\"TMALIGN\";\n$PG{\"TMalign\"}{\"type\"}=\"st\
ructure_pairwise_aligner\";\n$PG{\"TMalign\"}{\"AD\
DRESS\"}=\"http://zhanglab.ccmb.med.umich.edu/TM-a\
lign/TMalign.f\";\n$PG{\"TMalign\"}{\"language\"}=\
\"Fortran\";\n$PG{\"TMalign\"}{\"language2\"}=\"Fo\
rtran\";\n$PG{\"TMalign\"}{\"source\"}=\"http://zh\
anglab.ccmb.med.umich.edu/TM-align/TMalign.f\";\n$\
PG{\"TMalign\"}{\"linux\"}=\"http://zhanglab.ccmb.\
med.umich.edu/TM-align/TMalign_32.gz\";\n$PG{\"TMa\
lign\"}{\"mode\"}=\"expresso,3dcoffee\";\n$PG{\"TM\
align\"}{\"version\"}=\"2013.05.11\";\n$PG{\"musta\
ng\"}{\"4_TCOFFEE\"}=\"MUSTANG\";\n$PG{\"mustang\"\
}{\"type\"}=\"structure_pairwise_aligner\";\n$PG{\\
"mustang\"}{\"ADDRESS\"}=\"http://www.cs.mu.oz.au/\
~arun/mustang\";\n$PG{\"mustang\"}{\"language\"}=\\
"C++\";\n$PG{\"mustang\"}{\"language2\"}=\"CXX\";\\
n$PG{\"mustang\"}{\"source\"}=\"http://ww2.cs.mu.o\
z.au/~arun/mustang/mustang_v3.2.1.tgz\";\n$PG{\"mu\
stang\"}{\"mode\"}=\"expresso,3dcoffee\";\n$PG{\"m\
ustang\"}{\"version\"}=\"3.2.1\";\n$PG{\"lsqman\"}\
{\"4_TCOFFEE\"}=\"LSQMAN\";\n$PG{\"lsqman\"}{\"typ\
e\"}=\"structure_pairwise_aligner\";\n$PG{\"lsqman\
\"}{\"ADDRESS\"}=\"empty\";\n$PG{\"lsqman\"}{\"lan\
guage\"}=\"empty\";\n$PG{\"lsqman\"}{\"language2\"\
}=\"empty\";\n$PG{\"lsqman\"}{\"source\"}=\"empty\\
";\n$PG{\"lsqman\"}{\"update_action\"}=\"never\";\\
n$PG{\"lsqman\"}{\"mode\"}=\"expresso,3dcoffee\";\\
n$PG{\"align_pdb\"}{\"4_TCOFFEE\"}=\"ALIGN_PDB\";\\
n$PG{\"align_pdb\"}{\"type\"}=\"structure_pairwise\
_aligner\";\n$PG{\"align_pdb\"}{\"ADDRESS\"}=\"emp\
ty\";\n$PG{\"align_pdb\"}{\"language\"}=\"empty\";\
\n$PG{\"align_pdb\"}{\"language2\"}=\"empty\";\n$P\
G{\"align_pdb\"}{\"source\"}=\"empty\";\n$PG{\"ali\
gn_pdb\"}{\"update_action\"}=\"never\";\n$PG{\"ali\
gn_pdb\"}{\"mode\"}=\"expresso,3dcoffee\";\n$PG{\"\
fugueali\"}{\"4_TCOFFEE\"}=\"FUGUE\";\n$PG{\"fugue\
ali\"}{\"type\"}=\"structure_pairwise_aligner\";\n\
$PG{\"fugueali\"}{\"ADDRESS\"}=\"http://www-cryst.\
bioc.cam.ac.uk/fugue/download.html\";\n$PG{\"fugue\
ali\"}{\"language\"}=\"empty\";\n$PG{\"fugueali\"}\
{\"language2\"}=\"empty\";\n$PG{\"fugueali\"}{\"so\
urce\"}=\"empty\";\n$PG{\"fugueali\"}{\"update_act\
ion\"}=\"never\";\n$PG{\"fugueali\"}{\"mode\"}=\"e\
xpresso,3dcoffee\";\n$PG{\"dalilite.pl\"}{\"4_TCOF\
FEE\"}=\"DALILITEc\";\n$PG{\"dalilite.pl\"}{\"type\
\"}=\"structure_pairwise_aligner\";\n$PG{\"dalilit\
e.pl\"}{\"ADDRESS\"}=\"built_in\";\n$PG{\"dalilite\
.pl\"}{\"ADDRESS2\"}=\"http://www.ebi.ac.uk/Tools/\
webservices/services/dalilite\";\n$PG{\"dalilite.p\
l\"}{\"language\"}=\"Perl\";\n$PG{\"dalilite.pl\"}\
{\"language2\"}=\"Perl\";\n$PG{\"dalilite.pl\"}{\"\
source\"}=\"empty\";\n$PG{\"dalilite.pl\"}{\"updat\
e_action\"}=\"never\";\n$PG{\"dalilite.pl\"}{\"mod\
e\"}=\"expresso,3dcoffee\";\n$PG{\"probconsRNA\"}{\
\"4_TCOFFEE\"}=\"PROBCONSRNA\";\n$PG{\"probconsRNA\
\"}{\"type\"}=\"RNA_multiple_aligner\";\n$PG{\"pro\
bconsRNA\"}{\"ADDRESS\"}=\"http://probcons.stanfor\
d.edu/\";\n$PG{\"probconsRNA\"}{\"language\"}=\"C+\
+\";\n$PG{\"probconsRNA\"}{\"language2\"}=\"CXX\";\
\n$PG{\"probconsRNA\"}{\"source\"}=\"http://probco\
ns.stanford.edu/probconsRNA.tar.gz\";\n$PG{\"probc\
onsRNA\"}{\"mode\"}=\"mcoffee,rcoffee\";\n$PG{\"pr\
obconsRNA\"}{\"version\"}=\"1.0\";\n$PG{\"sfold\"}\
{\"4_TCOFFEE\"}=\"CONSAN\";\n$PG{\"sfold\"}{\"type\
\"}=\"RNA_pairwise_aligner\";\n$PG{\"sfold\"}{\"AD\
DRESS\"}=\"http://selab.janelia.org/software/consa\
n/\";\n$PG{\"sfold\"}{\"language\"}=\"empty\";\n$P\
G{\"sfold\"}{\"language2\"}=\"empty\";\n$PG{\"sfol\
d\"}{\"source\"}=\"empty\";\n$PG{\"sfold\"}{\"upda\
te_action\"}=\"never\";\n$PG{\"sfold\"}{\"mode\"}=\
\"rcoffee\";\n$PG{\"RNAplfold\"}{\"4_TCOFFEE\"}=\"\
RNAPLFOLD\";\n$PG{\"RNAplfold\"}{\"type\"}=\"RNA_s\
econdarystructure_predictor\";\n$PG{\"RNAplfold\"}\
{\"ADDRESS\"}=\"http://www.tbi.univie.ac.at/~ivo/R\
NA/\";\n$PG{\"RNAplfold\"}{\"language\"}=\"C\";\n$\
PG{\"RNAplfold\"}{\"language2\"}=\"C\";\n$PG{\"RNA\
plfold\"}{\"source\"}=\"http://www.tbi.univie.ac.a\
t/~ivo/RNA/ViennaRNA-1.7.2.tar.gz\";\n$PG{\"RNAplf\
old\"}{\"mode\"}=\"rcoffee,\";\n$PG{\"RNAplfold\"}\
{\"version\"}=\"1.7.2\";\n$PG{\"retree\"}{\"4_TCOF\
FEE\"}=\"PHYLIP\";\n$PG{\"retree\"}{\"type\"}=\"RN\
A_secondarystructure_predictor\";\n$PG{\"retree\"}\
{\"ADDRESS\"}=\"http://evolution.gs.washington.edu\
/phylip/\";\n$PG{\"retree\"}{\"language\"}=\"C\";\\
n$PG{\"retree\"}{\"language2\"}=\"C\";\n$PG{\"retr\
ee\"}{\"source\"}=\"http://evolution.gs.washington\
.edu/phylip/download/phylip-3.69.tar.gz\";\n$PG{\"\
retree\"}{\"mode\"}=\"trmsd,\";\n$PG{\"retree\"}{\\
"version\"}=\"3.69\";\n$PG{\"hmmtop\"}{\"4_TCOFFEE\
\"}=\"HMMTOP\";\n$PG{\"hmmtop\"}{\"type\"}=\"prote\
in_secondarystructure_predictor\";\n$PG{\"hmmtop\"\
}{\"ADDRESS\"}=\"www.enzim.hu/hmmtop/\";\n$PG{\"hm\
mtop\"}{\"language\"}=\"C\";\n$PG{\"hmmtop\"}{\"la\
nguage2\"}=\"C\";\n$PG{\"hmmtop\"}{\"source\"}=\"e\
mpty\";\n$PG{\"hmmtop\"}{\"binary\"}=\"hmmtop\";\n\
$PG{\"hmmtop\"}{\"update_action\"}=\"never\";\n$PG\
{\"hmmtop\"}{\"mode\"}=\"tcoffee\";\n$PG{\"hmmtop\\
"}{\"version\"}=\"2.1\";\n$PG{\"gorIV\"}{\"4_TCOFF\
EE\"}=\"GOR4\";\n$PG{\"gorIV\"}{\"type\"}=\"protei\
n_secondarystructure_predictor\";\n$PG{\"gorIV\"}{\
\"ADDRESS\"}=\"http://mig.jouy.inra.fr/logiciels/g\
orIV/\";\n$PG{\"gorIV\"}{\"language\"}=\"C\";\n$PG\
{\"gorIV\"}{\"language2\"}=\"C\";\n$PG{\"gorIV\"}{\
\"source\"}=\"http://mig.jouy.inra.fr/logiciels/go\
rIV/GOR_IV.tar.gz\";\n$PG{\"gorIV\"}{\"update_acti\
on\"}=\"never\";\n$PG{\"gorIV\"}{\"mode\"}=\"tcoff\
ee\";\n$PG{\"wublast.pl\"}{\"4_TCOFFEE\"}=\"EBIWUB\
LASTc\";\n$PG{\"wublast.pl\"}{\"type\"}=\"protein_\
homology_predictor\";\n$PG{\"wublast.pl\"}{\"ADDRE\
SS\"}=\"built_in\";\n$PG{\"wublast.pl\"}{\"ADDRESS\
2\"}=\"http://www.ebi.ac.uk/Tools/webservices/serv\
ices/wublast\";\n$PG{\"wublast.pl\"}{\"language\"}\
=\"Perl\";\n$PG{\"wublast.pl\"}{\"language2\"}=\"P\
erl\";\n$PG{\"wublast.pl\"}{\"source\"}=\"empty\";\
\n$PG{\"wublast.pl\"}{\"update_action\"}=\"never\"\
;\n$PG{\"wublast.pl\"}{\"mode\"}=\"psicoffee,expre\
sso,accurate\";\n$PG{\"blastpgp.pl\"}{\"4_TCOFFEE\\
"}=\"EBIBLASTPGPc\";\n$PG{\"blastpgp.pl\"}{\"type\\
"}=\"protein_homology_predictor\";\n$PG{\"blastpgp\
.pl\"}{\"ADDRESS\"}=\"built_in\";\n$PG{\"blastpgp.\
pl\"}{\"ADDRESS2\"}=\"http://www.ebi.ac.uk/Tools/w\
ebservices/services/blastpgp\";\n$PG{\"blastpgp.pl\
\"}{\"language\"}=\"Perl\";\n$PG{\"blastpgp.pl\"}{\
\"language2\"}=\"Perl\";\n$PG{\"blastpgp.pl\"}{\"s\
ource\"}=\"empty\";\n$PG{\"blastpgp.pl\"}{\"update\
_action\"}=\"never\";\n$PG{\"blastpgp.pl\"}{\"mode\
\"}=\"psicoffee,expresso,accurate\";\n$PG{\"blasta\
ll\"}{\"4_TCOFFEE\"}=\"blastall\";\n$PG{\"blastall\
\"}{\"type\"}=\"protein_homology_predictor\";\n$PG\
{\"blastall\"}{\"ADDRESS\"}=\"ftp://ftp.ncbi.nih.g\
ov/blast/executables/LATEST\";\n$PG{\"blastall\"}{\
\"language\"}=\"C\";\n$PG{\"blastall\"}{\"language\
2\"}=\"C\";\n$PG{\"blastall\"}{\"source\"}=\"empty\
\";\n$PG{\"blastall\"}{\"update_action\"}=\"never\\
";\n$PG{\"blastall\"}{\"mode\"}=\"psicoffee,expres\
so,3dcoffee\";\n$PG{\"legacy_blast.pl\"}{\"4_TCOFF\
EE\"}=\"NCBIBLAST\";\n$PG{\"legacy_blast.pl\"}{\"t\
ype\"}=\"protein_homology_predictor\";\n$PG{\"lega\
cy_blast.pl\"}{\"ADDRESS\"}=\"ftp://ftp.ncbi.nih.g\
ov/blast/executables/LATEST\";\n$PG{\"legacy_blast\
.pl\"}{\"language\"}=\"C\";\n$PG{\"legacy_blast.pl\
\"}{\"language2\"}=\"C\";\n$PG{\"legacy_blast.pl\"\
}{\"source\"}=\"empty\";\n$PG{\"legacy_blast.pl\"}\
{\"update_action\"}=\"never\";\n$PG{\"legacy_blast\
.pl\"}{\"mode\"}=\"psicoffee,expresso,3dcoffee\";\\
n$PG{\"SOAP::Lite\"}{\"4_TCOFFEE\"}=\"SOAPLITE\";\\
n$PG{\"SOAP::Lite\"}{\"type\"}=\"library\";\n$PG{\\
"SOAP::Lite\"}{\"ADDRESS\"}=\"http://cpansearch.pe\
rl.org/src/MKUTTER/SOAP-Lite-0.710.08/Makefile.PL\\
";\n$PG{\"SOAP::Lite\"}{\"language\"}=\"Perl\";\n$\
PG{\"SOAP::Lite\"}{\"language2\"}=\"Perl\";\n$PG{\\
"SOAP::Lite\"}{\"source\"}=\"empty\";\n$PG{\"blast\
pgp\"}{\"update_action\"}=\"never\";\n$PG{\"SOAP::\
Lite\"}{\"mode\"}=\"none\";\n$PG{\"XML::Simple\"}{\
\"4_TCOFFEE\"}=\"XMLSIMPLE\";\n$PG{\"XML::Simple\"\
}{\"type\"}=\"library\";\n$PG{\"XML::Simple\"}{\"A\
DDRESS\"}=\"http://search.cpan.org/~grantm/XML-Sim\
ple-2.18/lib/XML/Simple.pm\";\n$PG{\"XML::Simple\"\
}{\"language\"}=\"Perl\";\n$PG{\"XML::Simple\"}{\"\
language2\"}=\"Perl\";\n$PG{\"XML::Simple\"}{\"sou\
rce\"}=\"empty\";\n$PG{\"XML::Simple\"}{\"mode\"}=\
\"psicoffee,expresso,accurate\";\n$MODE{\"tcoffee\\
"}{\"name\"}=\"tcoffee\";\n$MODE{\"rcoffee\"}{\"na\
me\"}=\"rcoffee\";\n$MODE{\"3dcoffee\"}{\"name\"}=\
\"3dcoffee\";\n$MODE{\"mcoffee\"}{\"name\"}=\"mcof\
fee\";\n$MODE{\"expresso\"}{\"name\"}=\"expresso\"\
;\n$MODE{\"trmsd\"}{\"name\"}=\"trmsd\";\n$MODE{\"\
accurate\"}{\"name\"}=\"accurate\";\n$MODE{\"seq_r\
eformat\"}{\"name\"}=\"seq_reformat\";\n\n\n$PG{C}\
{compiler}=\"gcc\";\n$PG{C}{compiler_flag}=\"CC\";\
\n$PG{C}{options}=\"\";\n$PG{C}{options_flag}=\"CF\
LAGS\";\n$PG{C}{type}=\"compiler\";\n\n$PG{\"CXX\"\
}{compiler}=\"g++\";\n$PG{\"CXX\"}{compiler_flag}=\
\"CXX\";\n$PG{\"CXX\"}{options}=\"\";\n$PG{\"CXX\"\
}{options_flag}=\"CXXFLAGS\";\n$PG{CXX}{type}=\"co\
mpiler\";\n\n$PG{\"CPP\"}{compiler}=\"g++\";\n$PG{\
\"CPP\"}{compiler_flag}=\"CPP\";\n$PG{\"CPP\"}{opt\
ions}=\"\";\n$PG{\"CPP\"}{options_flag}=\"CPPFLAGS\
\";\n$PG{CPP}{type}=\"compiler\";\n\n$PG{\"GPP\"}{\
compiler}=\"g++\";\n$PG{\"GPP\"}{compiler_flag}=\"\
GPP\";\n$PG{\"GPP\"}{options}=\"\";\n$PG{\"GPP\"}{\
options_flag}=\"CFLAGS\";\n$PG{GPP}{type}=\"compil\
er\";\n\n$PG{Fortran}{compiler}=\"g77\";\n$PG{Fort\
ran}{compiler_flag}=\"FCC\";\n$PG{Fortran}{type}=\\
"compiler\";\n\n$PG{Perl}{compiler}=\"CPAN\";\n$PG\
{Perl}{type}=\"compiler\";\n\n$SUPPORTED_OS{macox}\
=\"Macintosh\";\n$SUPPORTED_OS{linux}=\"Linux\";\n\
$SUPPORTED_OS{windows}=\"Cygwin\";\n\n\n\n$MODE{t_\
coffee}{description}=\" for regular multiple seque\
nce alignments\";\n$MODE{rcoffee} {description}=\"\
 for RNA multiple sequence alignments\";\n\n$MODE{\
psicoffee} {description}=\" for Homology Extended \
multiple sequence alignments\";\n$MODE{expresso}{d\
escription}=\" for very accurate structure based m\
ultiple sequence alignments\";\n$MODE{\"3dcoffee\"\
}{description}=\" for multiple structure alignment\
s\";\n$MODE{mcoffee} {description}=\" for combinin\
g alternative multiple sequence alignment packages\
\\n------- into a unique meta-package. The install\
er will upload several MSA packages and compile th\
em\\n\n\";\n\n\n&post_process_PG();\nreturn;\n}\n\\
nsub post_process_PG\n  {\n    my $p;\n    \n    %\
PG=&name2dname (%PG);\n    %MODE=&name2dname(%MODE\
);\n    foreach $p (keys(%PG)){if ( $PG{$p}{type} \
eq \"compiler\"){$PG{$p}{update_action}=\"never\";\
}}\n    \n  }\n\nsub name2dname\n  {\n    my (%L)=\
(@_);\n    my ($l, $ml);\n    \n    foreach my $pg\
 (keys(%L))\n      {\n	$l=length ($pg);\n	if ( $l>\
$ml){$ml=$l;}\n      }\n    $ml+=1;\n    foreach m\
y $pg (keys(%L))\n      {\n	my $name;\n	$l=$ml-len\
gth ($pg);\n	$name=$pg;\n	for ( $b=0; $b<$l; $b++)\
\n	  {\n	    $name .=\" \";\n	  }\n	$L{$pg}{dname}\
=$name;\n      }\n    return %L;\n  }\n\nsub env_f\
ile2putenv\n  {\n    my $f=@_[0];\n    my $F=new F\
ileHandle;\n    my $n;\n    \n    open ($F, \"$f\"\
);\n    while (<$F>)\n      {\n	my $line=$_;\n	my(\
$var, $value)=($_=~/(\\S+)\\=(\\S*)/);\n	$ENV{$var\
}=$value;\n	$ENV_SET{$var}=1;\n	$n++;\n      }\n  \
  close ($F);\n    return $n;\n  }\n\nsub replace_\
line_in_file\n  {\n    my ($file, $wordin, $wordou\
t)=@_;\n    my $O=new FileHandle;\n    my $I=new F\
ileHandle;\n    my $l;\n    if (!-e $file){return;\
}\n    \n    system (\"mv $file $file.old\");\n   \
 open ($O, \">$file\");\n    open ($I, \"$file.old\
\");\n    while (<$I>)\n      {\n	$l=$_;\n	if (!($\
l=~/$wordin/)){print $O \"$l\";}\n	elsif ( $wordou\
t ne \"\"){$l=~s/$wordin/$wordout/g;print $O \"$l\\
";}\n      }\n    close ($O);\n    close ($I);\n  \
  return;\n  }\n\nsub add_C_libraries\n  {\n   my \
($file,$first,@list)=@_;\n   \n    my $O=new FileH\
andle;\n    my $I=new FileHandle;\n    my ($l,$anc\
hor);\n    if (!-e $file){return;}\n   \n    $anch\
or=\"#include <$first>\";\n	 \n    system (\"mv $f\
ile $file.old\");\n    open ($O, \">$file\");\n   \
 open ($I, \"$file.old\");\n    while (<$I>)\n    \
  {\n	$l=$_;\n	print $O \"$l\";\n	if (!($l=~/$anch\
or/))\n	   {\n	    \n	    foreach my $lib (@list)\\
n	       {\n                  print $O \"#include \
<$lib>\\n\";\n	       }\n           }\n      }\n  \
  close ($O);\n    close ($I);\n    return;\n    }\
\n","use Env;\nuse Cwd;\n@suffix=(\"tmp\", \"temp\\
", \"cache\", \"t_coffee\", \"core\", \"tcoffee\")\
;\n\nif ($#ARGV==-1)\n  {\n    print \"clean_cache\
.pl -file <file to add in -dir> -dir=<dir> -size=<\
value in Mb>\\n0: unlimited -1 always.\\nWill only\
 clean directories matching:[\";\n    foreach $k(@\
suffix){print \"*$k* \";}\n    print \"]\\n\";\n  \
  exit (EXIT_FAILURE);\n  }\n\n$cl=join (\" \",@AR\
GV);\nif (($cl=~/\\-no_action/))\n  {\n    exit (E\
XIT_SUCCESS);\n  }\n\nif (($cl=~/\\-debug/))\n  {\\
n    $DEBUG=1;\n  }\nelse\n  {\n    $DEBUG=0;\n  }\
\n\nif (($cl=~/\\-dir=(\\S+)/))\n  {\n    $dir=$1;\
\n  }\nelse\n  {\n    $dir=\"./\";\n  }\n\nif ($cl\
=~/\\-file=(\\S+)/)\n  {\n    $file=$1;\n  }\nelse\
\n  {\n    $file=0;\n  }\n\nif ($cl=~/\\-size=(\\S\
+)/)\n  {\n    $max_size=$1;\n  }\nelse\n  {\n    \
$max_size=0;#unlimited\n  }\nif ($cl=~/\\-force/)\\
n  {\n    $force=1;\n  }\nelse\n  {\n    $force=0;\
\n  }\n\nif ($cl=~/\\-age=(\\S+)/)\n  {\n    $max_\
age=$1;\n  }\nelse\n  {\n    $max_age=0;#unlimited\
\n  }\n\n$max_size*=1000000;\nif ( ! -d $dir)\n  {\
\n    print STDERR \"\\nCannot process $dir: does \
not exist \\n\";\n    exit (EXIT_FAILURE);\n  }\n\\
nif ( !($dir=~/^\\//))\n  {\n    $base=cwd();\n   \
 $dir=\"$base/$dir\";\n  }\n\n$proceed=0;\nforeach\
 $s (@suffix)\n  {\n    \n    if (($dir=~/$s/)){$p\
roceed=1;}\n    $s=uc ($s);\n    if (($dir=~/$s/))\
{$proceed=1;}\n  }\nif ( $proceed==0)\n  {\n    pr\
int STDERR \"Clean_cache.pl can only clean directo\
ries whose absolute path name contains the followi\
ng strings:\";\n    foreach $w (@suffix) {print ST\
DERR \"$w \";$w=lc($w); print STDERR \"$w \";}\n  \
  print STDERR \"\\nCannot process $dir\\n\";\n   \
 exit (EXIT_FAILURE);\n  }\n\n$name_file=\"$dir/na\
me_file.txt\";\n$size_file=\"$dir/size_file.txt\";\
\nif ( $force){&create_ref_file ($dir,$name_file,$\
size_file);}\nif ($file){&add_file ($dir, $name_fi\
le, $size_file, $file);}\n&clean_dir ($dir, $name_\
file, $size_file, $max_size,$max_age);\nexit (EXIT\
_SUCCESS);\n\nsub clean_dir \n  {\n    my ($dir, $\
name_file, $size_file, $max_size, $max_age)=@_;\n \
   my ($tot_size, $size, $f, $s);\n\n  \n    $tot_\
size=&get_tot_size ($dir, $name_file, $size_file);\
\n\n    if ( $tot_size<=$max_size){return ;}\n    \
else {$max_size/=2;}\n    \n    #recreate the name\
 file in case some temprary files have not been pr\
operly registered\n    &create_ref_file ($dir, $na\
me_file, $size_file, $max_age);\n  \n    $new_name\
_file=&vtmpnam();\n    open (R, \"$name_file\");\n\
    open (W, \">$new_name_file\");\n    while (<R>\
)\n      {\n	my $line=$_;\n	\n	($f, $s)=($line=~/(\
\\S+) (\\S+)/);\n	if ( !($f=~/\\S/)){next;}\n	\n	e\
lsif ($max_size && $tot_size>=$max_size && !($f=~/\
name_file/))\n	  {\n	    remove ( \"$dir/$f\");\n	\
    $tot_size-=$s;\n	  }\n	elsif ( $max_age && -M(\
\"$dir/$f\")>=$max_age)\n	  {\n	    remove ( \"$di\
r/$f\");\n	    $tot_size-=$s;\n	  }\n	else\n	  {\n\
	    print W \"$f $s\\n\";\n	  }\n      }\n    clo\
se (R);\n    close (W);\n    open (F, \">$size_fil\
e\");\n    print F \"$tot_size\";\n    if ( -e $ne\
w_name_file){`mv $new_name_file $name_file`;}\n   \
 close (F);\n  }\nsub get_tot_size\n  {\n    my ($\
dir, $name_file, $size_file)=@_;\n    my $size;\n \
   \n    if ( !-d $dir){return 0;}\n    if ( !-e $\
name_file)\n      {\n	\n	&create_ref_file ($dir, $\
name_file, $size_file);\n      }\n    open (F, \"$\
size_file\");\n    $size=<F>;\n    close (F);\n   \
 chomp ($size);\n    return $size;\n  }\nsub size \
\n  {\n    my $f=@_[0];\n\n    if ( !-d $f){return\
 -s($f);}\n    else {return &dir2size($f);}\n  }\n\
sub dir2size\n  {\n    my $d=@_[0];\n    my ($s, $\
f);\n    \n    if ( !-d $d) {return 0;}\n    \n   \
 foreach $f (&dir2list ($d))\n      {\n	if ( -d $f\
){$s+=&dir2size (\"$d/$f\");}\n	else {$s+= -s \"$d\
ir/$f\";}\n      }\n    return $s;\n  }\n\nsub rem\
ove \n  {\n    my $file=@_[0];\n    my ($f);\n    \
\n    debug_print( \"--- $file ---\\n\");\n    if \
(($file eq \".\") || ($file eq \"..\") || ($file=~\
/\\*/)){return EXIT_FAILURE;}\n    elsif ( !-d $fi\
le)\n      {\n	debug_print (\"unlink $file\\n\");\\
n	if (-e $file){unlink ($file);}\n      }\n    els\
if ( -d $file)\n      {\n	debug_print (\"++++++++ \
$file +++++++\\n\");\n	foreach $f (&dir2list($file\
))\n	  {\n	    &remove (\"$file/$f\");\n	  }\n	deb\
ug_print (\"rmdir $file\\n\");\n	rmdir $file;\n   \
   }\n    else\n      {\n	debug_print (\"?????????\
 $file ????????\\n\");\n      }\n    return EXIT_S\
UCCESS;\n  }\n\nsub dir2list\n  {\n    my $dir=@_[\
0];\n    my (@list1, @list2,@list3, $l);\n\n    op\
endir (DIR,$dir);\n    @list1=readdir (DIR);\n    \
closedir (DIR);\n    \n    foreach $l (@list1)\n  \
    {\n	if ( $l ne \".\" && $l ne \"..\"){@list2=(\
@list2, $l);}\n      }\n    @list3 = sort { (-M \"\
$dir/$list2[$b]\") <=> (-M \"$dir/$list2[$a]\")} @\
list2;\n    return @list3;\n    \n  }\n\nsub debug\
_print\n  {\n    \n    if ($DEBUG==1){print @_;}\n\
    \n  }\nsub create_ref_file\n  {\n    my ($dir,\
$name_file,$size_file)=@_;\n    my ($f, $s, $tot_s\
ize, @l);\n    \n    if ( !-d $dir){return;}\n    \
\n    @l=&dir2list ($dir);\n    open (F, \">$name_\
file\");\n    foreach $f (@l)\n      {\n	$s=&size(\
\"$dir/$f\");\n	$tot_size+=$s;\n	print F \"$f $s\\\
n\";\n      }\n    &myecho ($tot_size, \">$size_fi\
le\");\n    close (F);\n  }\nsub add_file \n  {\n \
   my ($dir,$name_file,$size_file,$file)=@_;\n    \
my ($s, $tot_size);\n    \n    if ( !-d $dir)   {r\
eturn;}\n    if ( !-e \"$dir/$file\" ) {return;}\n\
    if ( !-e $name_file){&create_ref_file ($dir,$n\
ame_file,$size_file);}\n					    \n    $s=&size(\"\
$dir/$file\");\n    open (F, \">>$name_file\");\n \
   print F \"$file\\n\";\n    close (F);\n\n    $t\
ot_size=&get_tot_size ($dir,$name_file,$size_file)\
;\n    $tot_size+=$s;\n    &myecho ($tot_size, \">\
$size_file\");\n    \n  }\n	\nsub myecho\n  {\n   \
 my ($string, $file)=@_;\n    open (ECHO, $file) |\
| die;\n    print ECHO \"$string\";\n    close (EC\
HO);\n  }\n    \n		\n	\nsub vtmpnam\n  {\n    my $\
tmp_file_name;\n    $tmp_name_counter++;\n    $tmp\
_file_name=\"tmp_file_for_clean_cache_pdb$$.$tmp_n\
ame_counter\";\n    $tmp_file_list[$ntmp_file++]=$\
tmp_file_name;\n    if ( -e $tmp_file_name) {retur\
n &vtmpnam ();}\n    else {return $tmp_file_name;}\
\n  }\n","\nmy $address=\"http://www.tcoffee.org/D\
ata/Datasets/NatureProtocolsDataset.tar.gz\";\nmy \
$out=\"NatureProtocolsDataset.tar.gz\";\n&url2file\
 ($address,$out);\n\nif ( -e $out)\n  {\n    \n   \
 system (\"gunzip NatureProtocolsDataset.tar.gz\")\
;\n    system (\"tar -xvf NatureProtocolsDataset.t\
ar\");\n  	system (\"rm -rf NatureProtocolsDataset\
.tar\");  \n    print \"Your Data Set is in the Fo\
lder 'NatureProtocolsDataset'\\n\";\n  }\nelse \n \
 {\n    print \"Could not Download Dataset --- Web\
 site may be down -- Try again later\\n\";\n  }\n\\
n\n\n\nsub url2file\n{\n    my ($address, $out, $w\
get_arg, $curl_arg)=(@_);\n    my ($pg, $flag, $r,\
 $arg, $count);\n    \n    if (!$CONFIGURATION){&c\
heck_configuration (\"wget\", \"INTERNET\", \"gzip\
\");$CONFIGURATION=1;}\n    \n    if (&pg_is_insta\
lled (\"wget\"))   {$pg=\"wget\"; $flag=\"-O\";$ar\
g=$wget_arg;}\n    elsif (&pg_is_installed (\"curl\
\")){$pg=\"curl\"; $flag=\"-o\";$arg=$curl_arg;}\n\
    return system (\"$pg $address $flag $out>/dev/\
null 2>/dev/null\");\n\n}\n\nsub pg_is_installed\n\
  {\n    my @ml=@_;\n    my $r, $p, $m;\n    my $s\
upported=0;\n    \n    my $p=shift (@ml);\n    if \
($p=~/::/)\n      {\n	if (system (\"perl -M$p -e 1\
\")==$EXIT_SUCCESS){return 1;}\n	else {return 0;}\\
n      }\n    else\n      {\n	$r=`which $p 2>/dev/\
null`;\n	if ($r eq \"\"){return 0;}\n	else {return\
 1;}\n      }\n  }\nsub check_configuration \n    \
{\n      my @l=@_;\n      my $v;\n      foreach my\
 $p (@l)\n	{\n	  \n	  if   ( $p eq \"EMAIL\")\n	  \
  { \n	      if ( !($EMAIL=~/@/))\n		{\n		  exit (\
EXIT_FAILURE);\n		}\n	    }\n	  elsif( $p eq \"INT\
ERNET\")\n	    {\n	      if ( !&check_internet_con\
nection())\n		{\n		  exit (EXIT_FAILURE);\n		}\n	 \
   }\n	  elsif( $p eq \"wget\")\n	    {\n	      if\
 (!&pg_is_installed (\"wget\") && !&pg_is_installe\
d (\"curl\"))\n		{\n		  exit (EXIT_FAILURE);\n		}\\
n	    }\n	  elsif( !(&pg_is_installed ($p)))\n	   \
 {\n	      exit (EXIT_FAILURE);\n	    }\n	}\n     \
 return 1;\n    }\nsub check_internet_connection\n\
  {\n    my $internet;\n    my $tmp;\n    &check_c\
onfiguration ( \"wget\"); \n    \n    $tmp=&vtmpna\
m ();\n    \n    if     (&pg_is_installed    (\"wg\
et\")){`wget www.google.com -O$tmp >/dev/null 2>/d\
ev/null`;}\n    elsif  (&pg_is_installed    (\"cur\
l\")){`curl www.google.com -o$tmp >/dev/null 2>/de\
v/null`;}\n    \n    if ( !-e $tmp || -s $tmp < 10\
){$internet=0;}\n    else {$internet=1;}\n    if (\
-e $tmp){unlink $tmp;}\n\n    return $internet;\n \
 }\n\nsub vtmpnam\n      {\n	my $r=rand(100000);\n\
	my $f=\"file.$r.$$\";\n	while (-e $f)\n	  {\n	   \
 $f=vtmpnam();\n	  }\n	push (@TMPFILE_LIST, $f);\n\
	return $f;\n      }\n\n","\n$t_coffee=\"t_coffee\\
";\n\nforeach $value ( @ARGV)\n  {\n    $seq_file=\
$seq_file.\" \".$value;\n  }\n\n$name=$ARGV[0];\n$\
name=~s/\\.[^\\.]*$//;\n$lib_name=\"$name.mocca_li\
b\";\n$type=`t_coffee $seq_file -get_type -quiet`;\
\nchop ($type);\n\nif ( $type eq \"PROTEIN\"){$lib\
_mode=\"lalign_rs_s_pair -lalign_n_top 20\";}\nels\
if ( $type eq\"DNA\"){$lib_mode=\"lalign_rs_s_dna_\
pair -lalign_n_top 40\";}\n\nif ( !(-e $lib_name))\
\n  {\n	  \n  $command=\"$t_coffee -mocca -seq_wei\
ght=no -cosmetic_penalty=0 -mocca_interactive -in \
$lib_mode -out_lib $lib_name -infile $seq_file\";\\
n  \n  }\nelsif ( (-e $lib_name))\n  {\n  $command\
=\"$t_coffee -mocca -seq_weight=no -cosmetic_penal\
ty=0 -mocca_interactive -in $lib_name -infile $seq\
_file\";\n  \n  }\n\nsystem ($command);\n\nexit;\n\
\n","my $WSDL = 'http://www.ebi.ac.uk/Tools/webser\
vices/wsdl/WSDaliLite.wsdl';\n\nuse SOAP::Lite;\nu\
se Data::Dumper;\nuse Getopt::Long qw(:config no_i\
gnore_case bundling);\nuse File::Basename;\n\nmy $\
checkInterval = 5;\n\nmy %params=(\n	    'async' =\
> '1', # Use async mode and simulate sync mode in \
client\n	    );\nGetOptions(\n    'pdb1=s'     => \
\\$params{'sequence1'},\n    'chainid1=s' => \\$pa\
rams{'chainid1'},\n    'pdb2=s'     => \\$params{'\
sequence2'},\n    'chainid2=s' => \\$params{'chain\
id2'},\n    \"help|h\"	 => \\$help, # Usage info\n\
    \"async|a\"	 => \\$async, # Asynchronous submi\
ssion\n    \"polljob\"	 => \\$polljob, # Get resul\
ts\n    \"status\"	 => \\$status, # Get status\n  \
  \"jobid|j=s\"  => \\$jobid, # JobId\n    \"email\
|S=s\"  => \\$params{email}, # E-mail address\n   \
 \"trace\"      => \\$trace, # SOAP messages\n    \
\"sequence=s\" => \\$sequence, # Input PDB\n    );\
\n\nmy $scriptName = basename($0, ());\nif($help) \
{\n    &usage();\n    exit(0);\n}\n\nif($trace) {\\
n    print \"Tracing active\\n\";\n    SOAP::Lite-\
>import(+trace => 'debug');\n}\n\nmy $soap = SOAP:\
:Lite\n    ->service($WSDL)\n    ->on_fault(sub {\\
n        my $soap = shift;\n        my $res = shif\
t;\n        # Throw an exception for all faults\n \
       if(ref($res) eq '') {\n            die($res\
);\n        } else {\n            die($res->faults\
tring);\n        }\n        return new SOAP::SOM;\\
n    }\n               );\n\nif( !($polljob || $st\
atus) &&\n    !( defined($params{'sequence1'}) && \
defined($params{'sequence2'}) )\n    ) {\n    prin\
t STDERR 'Error: bad option combination', \"\\n\";\
\n    &usage();\n    exit(1);\n}\nelsif($polljob &\
& defined($jobid)) {\n    print \"Getting results \
for job $jobid\\n\";\n    getResults($jobid);\n}\n\
elsif($status && defined($jobid)) {\n    print STD\
ERR \"Getting status for job $jobid\\n\";\n    my \
$result = $soap->checkStatus($jobid);\n    print S\
TDOUT \"$result\", \"\\n\";\n    if($result eq 'DO\
NE') {\n	print STDERR \"To get results: $scriptNam\
e --polljob --jobid $jobid\\n\";\n    }\n}\nelse {\
\n    if(-f $params{'sequence1'}) {\n	$params{'seq\
uence1'} = read_file($params{'sequence1'});\n    }\
\n    if(-f $params{'sequence2'}) {\n	$params{'seq\
uence2'} = read_file($params{'sequence2'});\n    }\
\n\n    my $jobid;\n    my $paramsData = SOAP::Dat\
a->name('params')->type(map=>\\%params);\n    # Fo\
r SOAP::Lite 0.60 and earlier parameters are passe\
d directly\n    if($SOAP::Lite::VERSION eq '0.60' \
|| $SOAP::Lite::VERSION =~ /0\\.[1-5]/) {\n       \
 $jobid = $soap->runDaliLite($paramsData);\n    }\\
n    # For SOAP::Lite 0.69 and later parameter han\
dling is different, so pass\n    # undef's for tem\
plated params, and then pass the formatted args.\n\
    else {\n        $jobid = $soap->runDaliLite(un\
def,\n				     $paramsData);\n    }\n\n    if (def\
ined($async)) {\n	print STDOUT $jobid, \"\\n\";\n \
       print STDERR \"To check status: $scriptName\
 --status --jobid $jobid\\n\";\n    } else { # Syn\
chronous mode\n        print STDERR \"JobId: $jobi\
d\\n\";\n        sleep 1;\n        getResults($job\
id);\n    }\n}\n\nsub clientPoll($) {\n    my $job\
id = shift;\n    my $result = 'PENDING';\n    # Ch\
eck status and wait if not finished\n    #print ST\
DERR \"Checking status: $jobid\\n\";\n    while($r\
esult eq 'RUNNING' || $result eq 'PENDING') {\n   \
     $result = $soap->checkStatus($jobid);\n      \
  print STDERR \"$result\\n\";\n        if($result\
 eq 'RUNNING' || $result eq 'PENDING') {\n        \
    # Wait before polling again.\n            slee\
p $checkInterval;\n        }\n    }\n}\n\nsub getR\
esults($) {\n    $jobid = shift;\n    # Check stat\
us, and wait if not finished\n    clientPoll($jobi\
d);\n    # Use JobId if output file name is not de\
fined\n    unless(defined($outfile)) {\n        $o\
utfile=$jobid;\n    }\n    # Get list of data type\
s\n    my $resultTypes = $soap->getResults($jobid)\
;\n    # Get the data and write it to a file\n    \
if(defined($outformat)) { # Specified data type\n \
       my $selResultType;\n        foreach my $res\
ultType (@$resultTypes) {\n            if($resultT\
ype->{type} eq $outformat) {\n                $sel\
ResultType = $resultType;\n            }\n        \
}\n        $res=$soap->poll($jobid, $selResultType\
->{type});\n        write_file($outfile.'.'.$selRe\
sultType->{ext}, $res);\n    } else { # Data types\
 available\n        # Write a file for each output\
 type\n        for my $resultType (@$resultTypes){\
\n            #print \"Getting $resultType->{type}\
\\n\";\n            $res=$soap->poll($jobid, $resu\
ltType->{type});\n            write_file($outfile.\
'.'.$resultType->{ext}, $res);\n        }\n    }\n\
}\n\nsub read_file($) {\n    my $filename = shift;\
\n    open(FILE, $filename);\n    my $content;\n  \
  my $buffer;\n    while(sysread(FILE, $buffer, 10\
24)) {\n	$content.= $buffer;\n    }\n    close(FIL\
E);\n    return $content;\n}\n\nsub write_file($$)\
 {\n    my ($tmp,$entity) = @_;\n    print STDERR \
\"Creating result file: \".$tmp.\"\\n\";\n    unle\
ss(open (FILE, \">$tmp\")) {\n	return 0;\n    }\n \
   syswrite(FILE, $entity);\n    close (FILE);\n  \
  return 1;\n}\n\nsub usage {\n    print STDERR <<\
EOF\nDaliLite\n========\n\nPairwise comparison of \
protein structures\n\n[Required]\n\n  --pdb1      \
          : str  : PDB ID for structure 1\n  --pdb\
2                : str  : PDB ID for structure 2\n\
\n[Optional]\n\n  --chain1              : str  : C\
hain identifer in structure 1\n  --chain2         \
     : str  : Chain identifer in structure 2\n\n[G\
eneral]\n\n  -h, --help            :      : prints\
 this help text\n  -S, --email           : str  : \
user email address\n  -a, --async           :     \
 : asynchronous submission\n      --status        \
  :      : poll for the status of a job\n      --p\
olljob         :      : poll for the results of a \
job\n  -j, --jobid           : str  : jobid for an\
 asynchronous job\n  -O, --outfile         : str  \
: file name for results (default is jobid)\n      \
--trace	        :      : show SOAP messages being \
interchanged \n\nSynchronous job:\n\n  The results\
/errors are returned as soon as the job is finishe\
d.\n  Usage: $scriptName --email <your\\@email> [o\
ptions] pdbFile [--outfile string]\n  Returns: sav\
es the results to disk\n\nAsynchronous job:\n\n  U\
se this if you want to retrieve the results at a l\
ater time. The results \n  are stored for up to 24\
 hours. \n  The asynchronous submission mode is re\
commended when users are submitting \n  batch jobs\
 or large database searches	\n  Usage: $scriptName\
 --email <your\\@email> --async [options] pdbFile\\
n  Returns: jobid\n\n  Use the jobid to query for \
the status of the job. \n  Usage: $scriptName --st\
atus --jobid <jobId>\n  Returns: string indicating\
 the status of the job:\n    DONE - job has finish\
ed\n    RUNNING - job is running\n    NOT_FOUND - \
job cannot be found\n    ERROR - the jobs has enco\
untered an error\n\n  When done, use the jobid to \
retrieve the status of the job. \n  Usage: $script\
Name --polljob --jobid <jobId> [--outfile string]\\
n\n[Help]\n\n  For more detailed help information \
refer to\n  http://www.ebi.ac.uk/DaliLite/\nEOF\n;\
\n}\n","my $WSDL = 'http://www.ebi.ac.uk/Tools/web\
services/wsdl/WSWUBlast.wsdl';\n\nuse strict;\nuse\
 SOAP::Lite;\nuse Getopt::Long qw(:config no_ignor\
e_case bundling);\nuse File::Basename;\n\nmy $chec\
kInterval = 15;\n\nmy $numOpts = scalar(@ARGV);\nm\
y ($outfile, $outformat, $help, $async, $polljob, \
$status, $ids, $jobid, $trace, $sequence);\nmy %pa\
rams= ( # Defaults\n	      'async' => 1, # Force i\
nto async mode\n	      'exp' => 10.0, # E-value th\
reshold\n	      'numal' => 50, # Maximum number of\
 alignments\n	      'scores' => 100, # Maximum num\
ber of scores\n            );\nGetOptions( # Map t\
he options into variables\n    \"program|p=s\"    \
 => \\$params{program}, # BLAST program\n    \"dat\
abase|D=s\"    => \\$params{database}, # Search da\
tabase\n    \"matrix|m=s\"      => \\$params{matri\
x}, # Scoring matrix\n    \"exp|E=f\"         => \\
\$params{exp}, # E-value threshold\n    \"echofilt\
er|e\"    => \\$params{echofilter}, # Display filt\
ered sequence\n    \"filter|f=s\"      => \\$param\
s{filter}, # Low complexity filter name\n    \"ali\
gnments|b=i\"  => \\$params{numal}, # Number of al\
ignments\n    \"scores|s=i\"      => \\$params{sco\
res}, # Number of scores\n    \"sensitivity|S=s\" \
=> \\$params{sensitivity}, # Search sensitivity\n \
   \"sort|t=s\"	      => \\$params{sort}, # Sort h\
its by...\n    \"stats|T=s\"       => \\$params{st\
ats}, # Scoring statistic to use\n    \"strand|d=s\
\"      => \\$params{strand}, # Strand to use in D\
NA vs. DNA search\n    \"topcombon|c=i\"   => \\$p\
arams{topcombon}, # Consistent sets of HSPs\n    \\
"outfile=s\"       => \\$outfile, # Output file\n \
   \"outformat|o=s\"   => \\$outformat, # Output f\
ormat\n    \"help|h\"	      => \\$help, # Usage in\
fo\n    \"async|a\"	      => \\$async, # Asynchron\
ous mode\n    \"polljob\"	      => \\$polljob, # G\
et results\n    \"status\"	      => \\$status, # G\
et job status\n    \"ids\"             => \\$ids, \
# Get ids from result\n    \"jobid|j=s\"       => \
\\$jobid, # JobId\n    \"email=s\"         => \\$p\
arams{email}, # E-mail address\n    \"trace\"     \
      => \\$trace, # SOAP trace\n    \"sequence=s\\
"      => \\$sequence, # Query sequence\n    );\n\\
nmy $scriptName = basename($0, ());\nif($help || $\
numOpts == 0) {\n    &usage();\n    exit(0);\n}\n\\
nif($trace){\n    print STDERR \"Tracing active\\n\
\";\n    SOAP::Lite->import(+trace => 'debug');\n}\
\n\nmy $soap = SOAP::Lite\n    ->service($WSDL)\n \
   ->proxy('http://localhost/',\n    #proxy => ['h\
ttp' => 'http://your.proxy.server/'], # HTTP proxy\
\n    timeout => 600, # HTTP connection timeout\n \
   )\n    ->on_fault(sub { # SOAP fault handler\n \
       my $soap = shift;\n        my $res = shift;\
\n        # Throw an exception for all faults\n   \
     if(ref($res) eq '') {\n            die($res);\
\n        } else {\n            die($res->faultstr\
ing);\n        }\n        return new SOAP::SOM;\n \
   }\n               );\n\nif( !($polljob || $stat\
us || $ids) &&\n    !( defined($ARGV[0]) || define\
d($sequence) )\n    ) {\n    print STDERR 'Error: \
bad option combination', \"\\n\";\n    &usage();\n\
    exit(1);\n}\nelsif($polljob && defined($jobid)\
) {\n    print \"Getting results for job $jobid\\n\
\";\n    getResults($jobid);\n}\nelsif($status && \
defined($jobid)) {\n    print STDERR \"Getting sta\
tus for job $jobid\\n\";\n    my $result = $soap->\
checkStatus($jobid);\n    print STDOUT \"$result\\\
n\";\n    if($result eq 'DONE') {\n	print STDERR \\
"To get results: $scriptName --polljob --jobid $jo\
bid\\n\";\n    }\n}  \nelsif($ids && defined($jobi\
d)) {\n    print STDERR \"Getting ids from job $jo\
bid\\n\";\n    getIds($jobid);\n}\nelse {\n    # P\
repare input data\n    my $content;\n    my (@cont\
ents) = ();\n    if(-f $ARGV[0] || $ARGV[0] eq '-'\
) {	\n	$content={type=>'sequence',content=>read_fi\
le($ARGV[0])};	\n    }\n    if($sequence) {	\n	if(\
-f $sequence || $sequence eq '-') {	\n	    $conten\
t={type=>'sequence',content=>read_file($ARGV[0])};\
	\n	} else {\n	    $content={type=>'sequence',cont\
ent=>$sequence};\n	}\n    }\n    push @contents, $\
content;\n\n    # Submit the job\n    my $paramsDa\
ta = SOAP::Data->name('params')->type(map=>\\%para\
ms);\n    my $contentData = SOAP::Data->name('cont\
ent')->value(\\@contents);\n    # For SOAP::Lite 0\
.60 and earlier parameters are passed directly\n  \
  if($SOAP::Lite::VERSION eq '0.60' || $SOAP::Lite\
::VERSION =~ /0\\.[1-5]/) {\n        $jobid = $soa\
p->runWUBlast($paramsData, $contentData);\n    }\n\
    # For SOAP::Lite 0.69 and later parameter hand\
ling is different, so pass\n    # undef's for temp\
lated params, and then pass the formatted args.\n \
   else {\n        $jobid = $soap->runWUBlast(unde\
f, undef,\n				   $paramsData, $contentData);\n   \
 }\n\n    # Asynchronous mode: output jobid and ex\
it.\n    if (defined($async)) {\n	print STDOUT $jo\
bid, \"\\n\";\n        print STDERR \"To check sta\
tus: $scriptName --status --jobid $jobid\\n\";\n  \
  }\n    # Synchronous mode: try to get results\n \
   else {\n        print STDERR \"JobId: $jobid\\n\
\";\n        sleep 1;\n        getResults($jobid);\
\n    }\n}\n\nsub getIds($) {\n    my $jobid = shi\
ft;\n    my $results = $soap->getIds($jobid);\n   \
 for my $result (@$results){\n	print \"$result\\n\\
";\n    }\n}\n\nsub clientPoll($) {\n    my $jobid\
 = shift;\n    my $result = 'PENDING';\n    # Chec\
k status and wait if not finished\n    while($resu\
lt eq 'RUNNING' || $result eq 'PENDING') {\n      \
  $result = $soap->checkStatus($jobid);\n        p\
rint STDERR \"$result\\n\";\n        if($result eq\
 'RUNNING' || $result eq 'PENDING') {\n           \
 # Wait before polling again.\n            sleep $\
checkInterval;\n        }\n    }\n}\n\nsub getResu\
lts($) {\n    my $jobid = shift;\n    my $res;\n  \
  # Check status, and wait if not finished\n    cl\
ientPoll($jobid);\n    # Use JobId if output file \
name is not defined\n    unless(defined($outfile))\
 {\n        $outfile=$jobid;\n    }\n    # Get lis\
t of data types\n    my $resultTypes = $soap->getR\
esults($jobid);\n    # Get the data and write it t\
o a file\n    if(defined($outformat)) { # Specifie\
d data type\n	if($outformat eq 'xml') {$outformat \
= 'toolxml';}\n	if($outformat eq 'txt') {$outforma\
t = 'tooloutput';}\n        my $selResultType;\n  \
      foreach my $resultType (@$resultTypes) {\n  \
          if($resultType->{type} eq $outformat) {\\
n                $selResultType = $resultType;\n  \
          }\n        }\n        $res=$soap->poll($\
jobid, $selResultType->{type});\n	if($outfile eq '\
-') {\n	     write_file($outfile, $res);\n	} else \
{\n	    write_file($outfile.'.'.$selResultType->{e\
xt}, $res);\n	}\n    } else { # Data types availab\
le\n        # Write a file for each output type\n \
       for my $resultType (@$resultTypes){\n      \
      #print STDERR \"Getting $resultType->{type}\\
\n\";\n            $res=$soap->poll($jobid, $resul\
tType->{type});\n	    if($outfile eq '-') {\n		wri\
te_file($outfile, $res);\n	    } else {\n		write_f\
ile($outfile.'.'.$resultType->{ext}, $res);\n	    \
}\n        }\n    }\n}\n\nsub read_file($) {\n    \
my $filename = shift;\n    my ($content, $buffer);\
\n    if($filename eq '-') {\n	while(sysread(STDIN\
, $buffer, 1024)) {\n	    $content .= $buffer;\n	}\
\n    }\n    else { # File\n	open(FILE, $filename)\
 or die \"Error: unable to open input file\";\n	wh\
ile(sysread(FILE, $buffer, 1024)) {\n	    $content\
 .= $buffer;\n	}\n	close(FILE);\n    }\n    return\
 $content;\n}\n\nsub write_file($$) {\n    my ($fi\
lename, $data) = @_;\n    print STDERR 'Creating r\
esult file: ' . $filename . \"\\n\";\n    if($file\
name eq '-') {\n	print STDOUT $data;\n    }\n    e\
lse {\n	open(FILE, \">$filename\") or die \"Error:\
 unable to open output file\";\n	syswrite(FILE, $d\
ata);\n	close(FILE);\n    }\n}\n\nsub usage {\n   \
 print STDERR <<EOF\nWU-BLAST\n========\n\nRapid s\
equence database search programs utilizing the BLA\
ST algorithm.\n   \n[Required]\n\n      --email   \
    : str  : user email address \n  -p, --program	\
    : str  : BLAST program to use: blastn, blastp,\
 blastx, \n                             tblastn or\
 tblastx\n  -D, --database    : str  : database to\
 search\n  seqFile           : file : query sequen\
ce data file (\"-\" for STDIN)\n\n[Optional]\n\n  \
-m, --matrix	    : str  : scoring matrix\n  -E, --\
exp	    : real : 0<E<= 1000. Statistical significa\
nce threshold\n                             for re\
porting database sequence matches.\n  -e, --echofi\
lter  :      : display the filtered query sequence\
 in the output\n  -f, --filter	    : str  : activa\
tes filtering of the query sequence\n  -b, --align\
ments  : int  : number of alignments to be reporte\
d\n  -s, --scores	    : int  : number of scores to\
 be reported\n  -S, --sensitivity : str  :\n  -t, \
--sort	    : str  :\n  -T, --stats       : str  :\\
n  -d, --strand      : str  : DNA strand to search\
 with in DNA vs. DNA searches \n  -c, --topcombon \
  :      :\n\n[General]	\n\n  -h, --help       :  \
    : prints this help text\n  -a, --async      : \
     : forces to make an asynchronous query\n     \
 --status     :      : poll for the status of a jo\
b\n      --polljob    :      : poll for the result\
s of a job\n  -j, --jobid      : str  : jobid that\
 was returned when an asynchronous job \n         \
                   was submitted.\n  -O, --outfile\
    : str  : name of the file results should be wr\
itten to \n                            (default is\
 based on the jobid; \"-\" for STDOUT)\n  -o, --ou\
tformat  : str  : txt or xml output (no file is wr\
itten)\n      --trace	   :      : show SOAP messag\
es being interchanged \n\nSynchronous job:\n\n  Th\
e results/errors are returned as soon as the job i\
s finished.\n  Usage: $scriptName --email <your\\@\
email> [options...] seqFile\n  Returns: saves the \
results to disk\n\nAsynchronous job:\n\n  Use this\
 if you want to retrieve the results at a later ti\
me. The results \n  are stored for up to 24 hours.\
 \n  The asynchronous submission mode is recommend\
ed when users are submitting \n  batch jobs or lar\
ge database searches	\n  Usage: $scriptName --asyn\
c --email <your\\@email> [options...] seqFile\n  R\
eturns : jobid\n\n  Use the jobid to query for the\
 status of the job. \n  Usage: $scriptName --statu\
s --jobid <jobId>\n  Returns : string indicating t\
he status of the job:\n    DONE - job has finished\
\n    RUNNING - job is running\n    NOT_FOUND - jo\
b cannot be found\n    ERROR - the jobs has encoun\
tered an error\n\n  When done, use the jobid to re\
trieve the status of the job. \n  Usage: $scriptNa\
me --polljob --jobid <jobId> [--outfile string]\n \
 Returns: saves the results to disk\n\n[Help]\n\nF\
or more detailed help information refer to \nhttp:\
//www.ebi.ac.uk/blast2/WU-Blast2_Help_frame.html\n\
 \nEOF\n;\n}\n","\nmy $WSDL = 'http://www.ebi.ac.u\
k/Tools/webservices/wsdl/WSBlastpgp.wsdl';\n\nuse \
SOAP::Lite;\nuse Getopt::Long qw(:config no_ignore\
_case bundling);\nuse File::Basename;\n\nmy $check\
Interval = 15;\n\nmy %params=(\n	    'async' => '1\
', # Use async mode and simulate sync mode in clie\
nt\n	    );\nGetOptions(\n    \"mode=s\"          \
 => \\$params{mode}, # Search mode: PSI-Blast or P\
HI-Blast\n    \"database|d=s\"     => \\$params{da\
tabase}, # Database to search\n    \"matrix|M=s\" \
      => \\$params{matrix},# Scoring maxtrix\n    \
\"exp|e=f\"          => \\$params{exp}, # E-value\\
n    \"expmulti|h=f\"     => \\$params{expmulti}, \
# E-value\n    \"filter|F=s\"       => \\$params{f\
ilter}, # Low complexity filter\n    \"dropoff|X=i\
\"      => \\$params{dropoff}, # Dropoff score\n  \
  \"finaldropoff|Z=i\" => \\$params{finaldropoff},\
 # Final dropoff score\n    \"scores|v=i\"       =\
> \\$params{scores}, # Max number of scores\n    \\
"align=i\"          => \\$params{align}, # Alignme\
nt view\n    \"startregion|S=i\"  => \\$params{sta\
rtregion}, # Start of region in query\n    \"endre\
gion|H=i\"    => \\$params{endregion}, # End of re\
gion in query\n    \"maxpasses|j=i\"    => \\$para\
ms{maxpasses}, # Number of PSI iterations\n    \"o\
pengap|G=i\"      => \\$params{opengap}, # Gap ope\
n penalty\n    \"extendgap|E=i\"    => \\$params{e\
xtendgap}, # Gap extension penalty\n    \"pattern=\
s\"        => \\$params{pattern}, # PHI-BLAST patt\
ern\n    \"usagemode|p=s\"    => \\$params{usagemo\
de}, # PHI-BLAST program\n    \"appxml=s\"        \
 => \\$params{appxml}, # Application XML\n    \"se\
quence=s\"       => \\$sequence, # Query sequence\\
n    \"help\"	       => \\$help, # Usage info\n   \
 \"polljob\"	       => \\$polljob, # Get results\n\
    \"status\"	       => \\$status, # Get status\n\
    \"ids\"      	       => \\$ids, # Get ids from\
 result\n    \"jobid=s\"          => \\$jobid, # J\
obId\n    \"outfile=s\"        => \\$outfile, # Ou\
tput filename\n    \"outformat|o=s\"    => \\$outf\
ormat, # Output file format\n    \"async|a\"	     \
  => \\$async, # Async submission\n    \"email=s\"\
          => \\$params{email}, # User e-mail addre\
ss\n    \"trace\"            => \\$trace, # Show S\
OAP messages\n    );\n\nmy $scriptName = basename(\
$0, ());\nif($help) {\n    &usage();\n    exit(0);\
\n}\n\nif ($trace){\n    print \"Tracing active\\n\
\";\n    SOAP::Lite->import(+trace => 'debug');\n}\
\n\nmy $soap = SOAP::Lite\n    ->service($WSDL)\n \
   ->on_fault(sub {\n        my $soap = shift;\n  \
      my $res = shift;\n        # Throw an excepti\
on for all faults\n        if(ref($res) eq '') {\n\
            die($res);\n        } else {\n        \
    die($res->faultstring);\n        }\n        re\
turn new SOAP::SOM;\n    }\n               );\n\ni\
f( !($polljob || $status || $ids) &&\n    !( (defi\
ned($ARGV[0]) && -f $ARGV[0]) || defined($sequence\
) )\n    ) {\n    print STDERR 'Error: bad option \
combination', \"\\n\";\n    &usage();\n    exit(1)\
;\n}\nelsif($polljob && defined($jobid)) {\n    pr\
int \"Getting results for job $jobid\\n\";\n    ge\
tResults($jobid);\n}\nelsif($status && defined($jo\
bid)) {\n    print STDERR \"Getting status for job\
 $jobid\\n\";\n    my $result = $soap->checkStatus\
($jobid);\n    print STDOUT $result, \"\\n\";\n   \
 if($result eq 'DONE') {\n	print STDERR \"To get r\
esults: $scriptName --polljob --jobid $jobid\\n\";\
\n    }\n}  \nelsif($ids && defined($jobid)) {\n  \
  print STDERR \"Getting ids from job $jobid\\n\";\
\n    getIds($jobid);\n}\nelse {\n    if(-f $ARGV[\
0]) {	\n	$content={type=>'sequence', content=>read\
_file($ARGV[0])};	\n    }\n    if($sequence) {	\n	\
if(-f $sequence) {\n	    $content={type=>'sequence\
', content=>read_file($sequence)};	\n	} else {\n	 \
   $content={type=>'sequence', content=>$sequence}\
;\n	}\n    }\n    push @content, $content;\n\n    \
my $jobid;\n    my $paramsData = SOAP::Data->name(\
'params')->type(map=>\\%params);\n    my $contentD\
ata = SOAP::Data->name('content')->value(\\@conten\
t);\n    # For SOAP::Lite 0.60 and earlier paramet\
ers are passed directly\n    if($SOAP::Lite::VERSI\
ON eq '0.60' || $SOAP::Lite::VERSION =~ /0\\.[1-5]\
/) {\n        $jobid = $soap->runBlastpgp($paramsD\
ata, $contentData);\n    }\n    # For SOAP::Lite 0\
.69 and later parameter handling is different, so \
pass\n    # undef's for templated params, and then\
 pass the formatted args.\n    else {\n        $jo\
bid = $soap->runBlastpgp(undef, undef,\n				    $p\
aramsData, $contentData);\n    }\n\n    if (define\
d($async)) {\n	print STDOUT $jobid, \"\\n\";\n    \
    print STDERR \"To check status: $scriptName --\
status --jobid $jobid\\n\";\n    } else { # Synchr\
onous mode\n        print STDERR \"JobId: $jobid\\\
n\";\n        sleep 1;\n        getResults($jobid)\
;\n    }\n}\n\nsub getIds($) {\n    $jobid = shift\
;\n    my $results = $soap->getIds($jobid);\n    f\
or $result (@$results){\n	print \"$result\\n\";\n \
   }\n}\n\nsub clientPoll($) {\n    my $jobid = sh\
ift;\n    my $result = 'PENDING';\n    # Check sta\
tus and wait if not finished\n    #print STDERR \"\
Checking status: $jobid\\n\";\n    while($result e\
q 'RUNNING' || $result eq 'PENDING') {\n        $r\
esult = $soap->checkStatus($jobid);\n        print\
 STDERR \"$result\\n\";\n        if($result eq 'RU\
NNING' || $result eq 'PENDING') {\n            # W\
ait before polling again.\n            sleep $chec\
kInterval;\n        }\n    }\n}\n\nsub getResults(\
$) {\n    $jobid = shift;\n    # Check status, and\
 wait if not finished\n    clientPoll($jobid);\n  \
  # Use JobId if output file name is not defined\n\
    unless(defined($outfile)) {\n        $outfile=\
$jobid;\n    }\n    # Get list of data types\n    \
my $resultTypes = $soap->getResults($jobid);\n    \
# Get the data and write it to a file\n    if(defi\
ned($outformat)) { # Specified data type\n        \
my $selResultType;\n        foreach my $resultType\
 (@$resultTypes) {\n            if($resultType->{t\
ype} eq $outformat) {\n                $selResultT\
ype = $resultType;\n            }\n        }\n    \
    $res=$soap->poll($jobid, $selResultType->{type\
});\n        write_file($outfile.'.'.$selResultTyp\
e->{ext}, $res);\n    } else { # Data types availa\
ble\n        # Write a file for each output type\n\
        for my $resultType (@$resultTypes){\n     \
       #print \"Getting $resultType->{type}\\n\";\\
n            $res=$soap->poll($jobid, $resultType-\
>{type});\n            write_file($outfile.'.'.$re\
sultType->{ext}, $res);\n        }\n    }\n}\n\nsu\
b read_file($) {\n    my $filename = shift;\n    o\
pen(FILE, $filename);\n    my $content;\n    my $b\
uffer;\n    while(sysread(FILE, $buffer, 1024)) {\\
n	$content.= $buffer;\n    }\n    close(FILE);  \n\
    return $content;\n}\n\nsub write_file($$) {\n \
   my ($tmp,$entity) = @_;\n    print STDERR \"Cre\
ating result file: \".$tmp.\"\\n\";\n    unless(op\
en (FILE, \">$tmp\")) {\n	return 0;\n    }\n    sy\
swrite(FILE, $entity);\n    close (FILE);\n    ret\
urn 1;\n}\n\nsub usage {\n    print STDERR <<EOF\n\
Blastpgp\n========\n   \nThe blastpgp program impl\
ements the PSI-BLAST and PHI-BLAST variations\nof \
NCBI BLAST.\n\nFor more detailed help information \
refer to\nhttp://www.ebi.ac.uk/blastpgp/blastpsi_h\
elp_frame.html\n \nBlastpgp specific options:\n\n[\
Required]\n\n      --mode            : str  : sear\
ch mode to use: PSI-Blast or PHI-Blast\n  -d, --da\
tabase        : str  : protein database to search\\
n  seqFile               : file : query sequence\n\
\n[Optional]\n\n  -M, --matrix          : str  : s\
coring matrix\n  -e, --exp             : real : Ex\
pectation value\n  -h, --expmulti        : real : \
threshold (multipass model)\n  -F, --filter       \
   : str  : filter query sequence with SEG [T,F]\n\
  -m, --align           : int  : alignment view op\
tion:\n                                 0 - pairwi\
se, 1 - M/S identities,\n                         \
        2 - M/S non-identities, 3 - Flat identitie\
s,\n                                 4 - Flat non-\
identities\n  -G, --opengap         : int  : cost \
to open a gap\n  -E, --extendgap       : int  : co\
st to extend a gap\n  -g, --gapalign        : str \
 : Gapped [T,F]\n  -v, --scores          : int  : \
number of scores to be reported\n  -j, --maxpasses\
       : int  : number of iterations\n  -X, --drop\
off         : int  : Dropoff score\n  -Z, --finald\
ropoff    : int  : Dropoff for final alignment\n  \
-S, --startregion     : int  : Start of required r\
egion in query\n  -H, --endregion       : int  : E\
nd of required region in query\n  -k, --pattern   \
      : str  : Hit File (PHI-BLAST only)\n  -p, --\
usagemode       : str  : Program option (PHI-BLAST\
 only):\n                                 blastpgp\
, patseedp, seedp\n\n[General]\n\n      --help    \
        :      : prints this help text\n  -a, --as\
ync           :      : forces to make an asynchron\
ous query\n      --status          :      : poll f\
or the status of a job\n      --polljob         : \
     : poll for the results of a job\n      --jobi\
d           : str  : jobid of an asynchronous job\\
n      --ids             :      : get hit identifi\
ers for result \n  -O, --outfile         : str  : \
name of the file results should be written to\n   \
                              (default is based on\
 the jobid)\n  -o, --outformat       : str  : txt \
or xml output (no file is written)\n      --trace \
          :      : show SOAP messages being interc\
hanged\n\nSynchronous job:\n\n  The results/errors\
 are returned as soon as the job is finished.\n  U\
sage: blastpgp.pl --email <your@email> [options...\
] seqfile\n  Returns: saves the results to disk\n\\
nAsynchronous job:\n\n  Use this if you want to re\
trieve the results at a later time. The results\n \
 are stored for up to 24 hours.\n  The asynchronou\
s submission mode is recommended when users are su\
bmitting\n  batch jobs or large database searches\\
n  Usage: blastpgp.pl --email <your@email> --async\
 [options...] seqFile\n  Returns: jobid\n\n  Use t\
he jobid to query for the status of the job.\n  Us\
age: blastpgp.pl --status --jobid <jobId>\n  Retur\
ns: string indicating the status of the job\n    D\
ONE - job has finished\n    RUNNING - job is runni\
ng\n    NOT_FOUND - job cannot be found\n    ERROR\
 - the jobs has encountered an error\n\n  When don\
e, use the jobid to retrieve the results of the jo\
b.\n  Usage: blastpgp.pl --polljob --jobid <jobId>\
 [--outfile <fileName>]\n  Returns: saves the resu\
lts to disk\nEOF\n;\n}\n","\n=head1 NAME\n\nncbibl\
ast_lwp.pl\n\n=head1 DESCRIPTION\n\nNCBI BLAST (RE\
ST) web service Perl client using L<LWP>.\n\nTeste\
d with:\n\n=over\n\n=item *\nL<LWP> 5.79, L<XML::S\
imple> 2.12 and Perl 5.8.3\n\n=item *\nL<LWP> 5.80\
8, L<XML::Simple> 2.18 and Perl 5.8.8 (Ubuntu 8.04\
 LTS)\n\n=item *\nL<LWP> 5.834, L<XML::Simple> 2.1\
8 and Perl 5.10.1 (Ubuntu 10.04 LTS)\n\n=item *\nL\
<LWP> 6.03, L<XML::Simple> 2.18 and Perl 5.14.2 (U\
buntu 12.04 LTS)\n\n=back\n\nFor further informati\
on see:\n\n=over\n\n=item *\nL<http://www.ebi.ac.u\
k/Tools/webservices/services/sss/ncbi_blast_rest>\\
n\n=item *\nL<http://www.ebi.ac.uk/Tools/webservic\
es/tutorials/perl>\n\n=back\n\n=head1 LICENSE\n\nC\
opyright 2012-2013 EMBL - European Bioinformatics \
Institute\n\nLicensed under the Apache License, Ve\
rsion 2.0 (the \"License\");\nyou may not use this\
 file except in compliance with the License.\nYou \
may obtain a copy of the License at\n\n    http://\
www.apache.org/licenses/LICENSE-2.0\n\nUnless requ\
ired by applicable law or agreed to in writing, so\
ftware\ndistributed under the License is distribut\
ed on an \"AS IS\" BASIS,\nWITHOUT WARRANTIES OR C\
ONDITIONS OF ANY KIND, either express or implied.\\
nSee the License for the specific language governi\
ng permissions and\nlimitations under the License.\
\n\n=head1 VERSION\n\n$Id: ncbiblast_lwp.pl 2560 2\
013-03-20 12:56:31Z hpm $\n\n=cut\n\nuse strict;\n\
use warnings;\n\nuse English;\nuse LWP;\nuse XML::\
Simple;\nuse Getopt::Long qw(:config no_ignore_cas\
e bundling);\nuse File::Basename;\nuse Data::Dumpe\
r;\n\nmy $baseUrl = 'http://www.ebi.ac.uk/Tools/se\
rvices/rest/ncbiblast';\n\nmy $checkInterval = 3;\\
n\nmy $outputLevel = 1;\n\nmy $numOpts = scalar(@A\
RGV);\nmy %params = ( 'debugLevel' => 0 );\n\nmy %\
tool_params = ();\nGetOptions(\n\n	# Tool specific\
 options\n	'program|p=s'  => \\$tool_params{'progr\
am'},   # blastp, blastn, blastx, etc.\n	'database\
|D=s' => \\$params{'database'},       # Database(s\
) to search\n	'matrix|m=s'   => \\$tool_params{'ma\
trix'},    # Scoring martix to use\n	'exp|E=f'    \
  => \\$tool_params{'exp'},       # E-value thresh\
old\n	'filter|f=s'   => \\$tool_params{'filter'}, \
   # Low complexity filter\n	'align|A=i'    => \\$\
tool_params{'align'},     # Pairwise alignment for\
mat\n	'scores|s=i'   => \\$tool_params{'scores'}, \
   # Number of scores\n	'alignments|n=i' => \\$too\
l_params{'alignments'},   # Number of alignments\n\
	'dropoff|d=i'    => \\$tool_params{'dropoff'},   \
   # Dropoff score\n	'match_scores=s' => \\$tool_p\
arams{'match_scores'}, # Match/missmatch scores\n	\
'match|u=i'      => \\$params{'match'},           \
  # Match score\n	'mismatch|v=i'   => \\$params{'m\
ismatch'},          # Mismatch score\n	'gapopen|o=\
i'    => \\$tool_params{'gapopen'},      # Open ga\
p penalty\n	'gapext|x=i'     => \\$tool_params{'ga\
pext'},       # Gap extension penality\n	'gapalign\
|g'     => \\$tool_params{'gapalign'},     # Optim\
ise gap alignments\n	'stype=s' => \\$tool_params{'\
stype'},    # Sequence type\n	'seqrange=s' => \\$t\
ool_params{'seqrange'},    # Query subsequence\n	'\
sequence=s' => \\$params{'sequence'},         # Qu\
ery sequence\n	'multifasta' => \\$params{'multifas\
ta'},       # Multiple fasta input\n\n	# Compatabi\
lity options, old command-line\n	'numal|n=i'     =\
> \\$params{'numal'},        # Number of alignment\
s\n	'opengap|o=i'   => \\$params{'opengap'},      \
# Open gap penalty\n	'extendgap|x=i' => \\$params{\
'extendgap'},    # Gap extension penality\n	\n	# G\
eneric options\n	'email=s'       => \\$params{'ema\
il'},          # User e-mail address\n	'title=s'  \
     => \\$params{'title'},          # Job title\n\
	'outfile=s'     => \\$params{'outfile'},        #\
 Output file name\n	'outformat=s'   => \\$params{'\
outformat'},      # Output file type\n	'jobid=s'  \
     => \\$params{'jobid'},          # JobId\n	'he\
lp|h'        => \\$params{'help'},           # Usa\
ge help\n	'async'         => \\$params{'async'},  \
        # Asynchronous submission\n	'polljob'     \
  => \\$params{'polljob'},        # Get results\n	\
'resultTypes'   => \\$params{'resultTypes'},    # \
Get result types\n	'status'        => \\$params{'s\
tatus'},         # Get status\n	'params'        =>\
 \\$params{'params'},         # List input paramet\
ers\n	'paramDetail=s' => \\$params{'paramDetail'},\
    # Get details for parameter\n	'quiet'         \
=> \\$params{'quiet'},          # Decrease output \
level\n	'verbose'       => \\$params{'verbose'},  \
      # Increase output level\n	'debugLevel=i'  =>\
 \\$params{'debugLevel'},     # Debug output level\
\n	'baseUrl=s'     => \\$baseUrl,                 \
 # Base URL for service.\n);\nif ( $params{'verbos\
e'} ) { $outputLevel++ }\nif ( $params{'quiet'} ) \
 { $outputLevel-- }\n\n&print_debug_message( 'MAIN\
', 'LWP::VERSION: ' . $LWP::VERSION,\n	1 );\n\n&pr\
int_debug_message( 'MAIN', \"params:\\n\" . Dumper\
( \\%params ),           11 );\n&print_debug_messa\
ge( 'MAIN', \"tool_params:\\n\" . Dumper( \\%tool_\
params ), 11 );\n\nmy $ua;\n\nmy $scriptName = bas\
ename( $0, () );\n\nif ( $params{'help'} || $numOp\
ts == 0 ) {\n	&usage();\n	exit(0);\n}\n\n&print_de\
bug_message( 'MAIN', 'baseUrl: ' . $baseUrl, 1 );\\
n\nif (\n	!(\n		   $params{'polljob'}\n		|| $param\
s{'resultTypes'}\n		|| $params{'status'}\n		|| $pa\
rams{'params'}\n		|| $params{'paramDetail'}\n	)\n	\
&& !( defined( $ARGV[0] ) || defined( $params{'seq\
uence'} ) )\n  )\n{\n\n	# Bad argument combination\
, so print error message and usage\n	print STDERR \
'Error: bad option combination', \"\\n\";\n	&usage\
();\n	exit(1);\n}\n\nelsif ( $params{'params'} ) {\
\n	&print_tool_params();\n}\n\nelsif ( $params{'pa\
ramDetail'} ) {\n	&print_param_details( $params{'p\
aramDetail'} );\n}\n\nelsif ( $params{'status'} &&\
 defined( $params{'jobid'} ) ) {\n	&print_job_stat\
us( $params{'jobid'} );\n}\n\nelsif ( $params{'res\
ultTypes'} && defined( $params{'jobid'} ) ) {\n	&p\
rint_result_types( $params{'jobid'} );\n}\n\nelsif\
 ( $params{'polljob'} && defined( $params{'jobid'}\
 ) ) {\n	&get_results( $params{'jobid'} );\n}\n\ne\
lse {\n\n	# Multiple input sequence mode, assume f\
asta format.\n	if ( $params{'multifasta'} ) {\n		&\
multi_submit_job();\n	}\n\n	# Entry identifier lis\
t file.\n	elsif (( defined( $params{'sequence'} ) \
&& $params{'sequence'} =~ m/^\\@/ )\n		|| ( define\
d( $ARGV[0] ) && $ARGV[0] =~ m/^\\@/ ) )\n	{\n		my\
 $list_filename = $params{'sequence'} || $ARGV[0];\
\n		$list_filename =~ s/^\\@//;\n		&list_file_subm\
it_job($list_filename);\n	}\n\n	# Default: single \
sequence/identifier.\n	else {\n\n		# Load the sequ\
ence data and submit.\n		&submit_job( &load_data()\
 );\n	}\n}\n\n=head1 FUNCTIONS\n\n=cut\n\n\n=head2\
 rest_user_agent()\n\nGet a LWP UserAgent to use t\
o perform REST requests.\n\n  my $ua = &rest_user_\
agent();\n\n=cut\n\nsub rest_user_agent() {\n	prin\
t_debug_message( 'rest_user_agent', 'Begin', 21 );\
\n	# Create an LWP UserAgent for making HTTP calls\
.\n	my $ua = LWP::UserAgent->new();\n	# Set 'User-\
Agent' HTTP header to identifiy the client.\n	'$Re\
vision: 2560 $' =~ m/(\\d+)/;\n	$ua->agent(\"EBI-S\
ample-Client/$1 ($scriptName; $OSNAME) \" . $ua->a\
gent());\n	# Configure HTTP proxy support from env\
ironment.\n	$ua->env_proxy;\n	print_debug_message(\
 'rest_user_agent', 'End', 21 );\n	return $ua;\n}\\
n\n=head2 rest_error()\n\nCheck a REST response fo\
r an error condition. An error is mapped to a die.\
\n\n  &rest_error($response, $content_data);\n\n=c\
ut\n\nsub rest_error() {\n	print_debug_message( 'r\
est_error', 'Begin', 21 );\n	my $response = shift;\
\n	my $contentdata;\n	if(scalar(@_) > 0) {\n		$con\
tentdata = shift;\n	}\n	if(!defined($contentdata) \
|| $contentdata eq '') {\n		$contentdata = $respon\
se->content();\n	}\n	# Check for HTTP error codes\\
n	if ( $response->is_error ) {\n		my $error_messag\
e = '';\n		# HTML response.\n		if(	$contentdata =~\
 m/<h1>([^<]+)<\\/h1>/ ) {\n			$error_message = $1\
;\n		}\n		#  XML response.\n		elsif($contentdata =\
~ m/<description>([^<]+)<\\/description>/) {\n			$\
error_message = $1;\n		}\n		die 'http status: ' . \
$response->code . ' ' . $response->message . '  ' \
. $error_message;\n	}\n	print_debug_message( 'rest\
_error', 'End', 21 );\n}\n\n=head2 rest_request()\\
n\nPerform a REST request (HTTP GET).\n\n  my $res\
ponse_str = &rest_request($url);\n\n=cut\n\nsub re\
st_request {\n	print_debug_message( 'rest_request'\
, 'Begin', 11 );\n	my $requestUrl = shift;\n	print\
_debug_message( 'rest_request', 'URL: ' . $request\
Url, 11 );\n\n	# Get an LWP UserAgent.\n	$ua = &re\
st_user_agent() unless defined($ua);\n	# Available\
 HTTP compression methods.\n	my $can_accept;\n	eva\
l {\n	    $can_accept = HTTP::Message::decodable()\
;\n	};\n	$can_accept = '' unless defined($can_acce\
pt);\n	# Perform the request\n	my $response = $ua-\
>get($requestUrl,\n		'Accept-Encoding' => $can_acc\
ept, # HTTP compression.\n	);\n	print_debug_messag\
e( 'rest_request', 'HTTP status: ' . $response->co\
de,\n		11 );\n	print_debug_message( 'rest_request'\
,\n		'response length: ' . length($response->conte\
nt()), 11 );\n	print_debug_message( 'rest_request'\
,\n		'request:' .\"\\n\" . $response->request()->a\
s_string(), 32 );\n	print_debug_message( 'rest_req\
uest',\n		'response: ' . \"\\n\" . $response->as_s\
tring(), 32 );\n	# Unpack possibly compressed resp\
onse.\n	my $retVal;\n	if ( defined($can_accept) &&\
 $can_accept ne '') {\n	    $retVal = $response->d\
ecoded_content();\n	}\n	# If unable to decode use \
orginal content.\n	$retVal = $response->content() \
unless defined($retVal);\n	# Check for an error.\n\
	&rest_error($response, $retVal);\n	print_debug_me\
ssage( 'rest_request', 'retVal: ' . $retVal, 12 );\
\n	print_debug_message( 'rest_request', 'End', 11 \
);\n\n	# Return the response data\n	return $retVal\
;\n}\n\n=head2 rest_get_parameters()\n\nGet list o\
f tool parameter names.\n\n  my (@param_list) = &r\
est_get_parameters();\n\n=cut\n\nsub rest_get_para\
meters {\n	print_debug_message( 'rest_get_paramete\
rs', 'Begin', 1 );\n	my $url                = $bas\
eUrl . '/parameters/';\n	my $param_list_xml_str = \
rest_request($url);\n	my $param_list_xml     = XML\
in($param_list_xml_str);\n	my (@param_list)       \
= @{ $param_list_xml->{'id'} };\n	print_debug_mess\
age( 'rest_get_parameters', 'End', 1 );\n	return (\
@param_list);\n}\n\n=head2 rest_get_parameter_deta\
ils()\n\nGet details of a tool parameter.\n\n  my \
$paramDetail = &rest_get_parameter_details($param_\
name);\n\n=cut\n\nsub rest_get_parameter_details {\
\n	print_debug_message( 'rest_get_parameter_detail\
s', 'Begin', 1 );\n	my $parameterId = shift;\n	pri\
nt_debug_message( 'rest_get_parameter_details',\n	\
	'parameterId: ' . $parameterId, 1 );\n	my $url   \
               = $baseUrl . '/parameterdetails/' .\
 $parameterId;\n	my $param_detail_xml_str = rest_r\
equest($url);\n	my $param_detail_xml     = XMLin($\
param_detail_xml_str);\n	print_debug_message( 'res\
t_get_parameter_details', 'End', 1 );\n	return ($p\
aram_detail_xml);\n}\n\n=head2 rest_run()\n\nSubmi\
t a job.\n\n  my $job_id = &rest_run($email, $titl\
e, \\%params );\n\n=cut\n\nsub rest_run {\n	print_\
debug_message( 'rest_run', 'Begin', 1 );\n	my $ema\
il  = shift;\n	my $title  = shift;\n	my $params = \
shift;\n	print_debug_message( 'rest_run', 'email: \
' . $email, 1 );\n	if ( defined($title) ) {\n		pri\
nt_debug_message( 'rest_run', 'title: ' . $title, \
1 );\n	}\n	print_debug_message( 'rest_run', 'param\
s: ' . Dumper($params), 1 );\n\n	# Get an LWP User\
Agent.\n	$ua = &rest_user_agent() unless defined($\
ua);\n\n	# Clean up parameters\n	my (%tmp_params) \
= %{$params};\n	$tmp_params{'email'} = $email;\n	$\
tmp_params{'title'} = $title;\n	foreach my $param_\
name ( keys(%tmp_params) ) {\n		if ( !defined( $tm\
p_params{$param_name} ) ) {\n			delete $tmp_params\
{$param_name};\n		}\n	}\n\n	# Submit the job as a \
POST\n	my $url = $baseUrl . '/run';\n	my $response\
 = $ua->post( $url, \\%tmp_params );\n	print_debug\
_message( 'rest_run', 'HTTP status: ' . $response-\
>code, 11 );\n	print_debug_message( 'rest_run',\n	\
	'request:' .\"\\n\" . $response->request()->as_st\
ring(), 11 );\n	print_debug_message( 'rest_run',\n\
		'response: ' . length($response->as_string()) . \
\"\\n\" . $response->as_string(), 11 );\n\n	# Chec\
k for an error.\n	&rest_error($response);\n\n	# Th\
e job id is returned\n	my $job_id = $response->con\
tent();\n	print_debug_message( 'rest_run', 'End', \
1 );\n	return $job_id;\n}\n\n=head2 rest_get_statu\
s()\n\nCheck the status of a job.\n\n  my $status \
= &rest_get_status($job_id);\n\n=cut\n\nsub rest_g\
et_status {\n	print_debug_message( 'rest_get_statu\
s', 'Begin', 1 );\n	my $job_id = shift;\n	print_de\
bug_message( 'rest_get_status', 'jobid: ' . $job_i\
d, 2 );\n	my $status_str = 'UNKNOWN';\n	my $url   \
     = $baseUrl . '/status/' . $job_id;\n	$status_\
str = &rest_request($url);\n	print_debug_message( \
'rest_get_status', 'status_str: ' . $status_str, 2\
 );\n	print_debug_message( 'rest_get_status', 'End\
', 1 );\n	return $status_str;\n}\n\n=head2 rest_ge\
t_result_types()\n\nGet list of result types for f\
inished job.\n\n  my (@result_types) = &rest_get_r\
esult_types($job_id);\n\n=cut\n\nsub rest_get_resu\
lt_types {\n	print_debug_message( 'rest_get_result\
_types', 'Begin', 1 );\n	my $job_id = shift;\n	pri\
nt_debug_message( 'rest_get_result_types', 'jobid:\
 ' . $job_id, 2 );\n	my (@resultTypes);\n	my $url \
                     = $baseUrl . '/resulttypes/' \
. $job_id;\n	my $result_type_list_xml_str = &rest_\
request($url);\n	my $result_type_list_xml     = XM\
Lin($result_type_list_xml_str);\n	(@resultTypes) =\
 @{ $result_type_list_xml->{'type'} };\n	print_deb\
ug_message( 'rest_get_result_types',\n		scalar(@re\
sultTypes) . ' result types', 2 );\n	print_debug_m\
essage( 'rest_get_result_types', 'End', 1 );\n	ret\
urn (@resultTypes);\n}\n\n=head2 rest_get_result()\
\n\nGet result data of a specified type for a fini\
shed job.\n\n  my $result = rest_get_result($job_i\
d, $result_type);\n\n=cut\n\nsub rest_get_result {\
\n	print_debug_message( 'rest_get_result', 'Begin'\
, 1 );\n	my $job_id = shift;\n	my $type   = shift;\
\n	print_debug_message( 'rest_get_result', 'jobid:\
 ' . $job_id, 1 );\n	print_debug_message( 'rest_ge\
t_result', 'type: ' . $type,    1 );\n	my $url    \
= $baseUrl . '/result/' . $job_id . '/' . $type;\n\
	my $result = &rest_request($url);\n	print_debug_m\
essage( 'rest_get_result', length($result) . ' cha\
racters',\n		1 );\n	print_debug_message( 'rest_get\
_result', 'End', 1 );\n	return $result;\n}\n\n\n=h\
ead2 print_debug_message()\n\nPrint debug message \
at specified debug level.\n\n  &print_debug_messag\
e($method_name, $message, $level);\n\n=cut\n\nsub \
print_debug_message {\n	my $function_name = shift;\
\n	my $message       = shift;\n	my $level         \
= shift;\n	if ( $level <= $params{'debugLevel'} ) \
{\n		print STDERR '[', $function_name, '()] ', $me\
ssage, \"\\n\";\n	}\n}\n\n=head2 print_tool_params\
()\n\nPrint list of tool parameters.\n\n  &print_t\
ool_params();\n\n=cut\n\nsub print_tool_params {\n\
	print_debug_message( 'print_tool_params', 'Begin'\
, 1 );\n	my (@param_list) = &rest_get_parameters()\
;\n	foreach my $param ( sort(@param_list) ) {\n		p\
rint $param, \"\\n\";\n	}\n	print_debug_message( '\
print_tool_params', 'End', 1 );\n}\n\n=head2 print\
_param_details()\n\nPrint details of a tool parame\
ter.\n\n  &print_param_details($param_name);\n\n=c\
ut\n\nsub print_param_details {\n	print_debug_mess\
age( 'print_param_details', 'Begin', 1 );\n	my $pa\
ramName = shift;\n	print_debug_message( 'print_par\
am_details', 'paramName: ' . $paramName, 2 );\n	my\
 $paramDetail = &rest_get_parameter_details($param\
Name);\n	print $paramDetail->{'name'}, \"\\t\", $p\
aramDetail->{'type'}, \"\\n\";\n	print $paramDetai\
l->{'description'}, \"\\n\";\n	if(defined($paramDe\
tail->{'values'}->{'value'})) {\n		if(ref($paramDe\
tail->{'values'}->{'value'}) eq 'ARRAY') {\n			for\
each my $value ( @{ $paramDetail->{'values'}->{'va\
lue'} } ) {\n				&print_param_value($value);\n			}\
\n		}\n		else {\n				&print_param_value($paramDeta\
il->{'values'}->{'value'});\n		}\n	}\n	print_debug\
_message( 'print_param_details', 'End', 1 );\n}\n\\
n=head2 print_param_value()\n\nPrint details of a \
tool parameter value.\n\n  &print_param_details($p\
aram_value);\n\nUsed by print_param_details() to h\
andle both singluar and array values.\n\n=cut\n\ns\
ub print_param_value {\n	my $value = shift;\n	prin\
t $value->{'value'};\n	if ( $value->{'defaultValue\
'} eq 'true' ) {\n		print \"\\t\", 'default';\n	}\\
n	print \"\\n\";\n	print \"\\t\", $value->{'label'\
}, \"\\n\";\n	if ( defined( $value->{'properties'}\
 ) ) {\n		foreach\n		  my $key ( sort( keys( %{ $v\
alue->{'properties'}{'property'} } ) ) )\n		{\n			\
if ( ref( $value->{'properties'}{'property'}{$key}\
 ) eq 'HASH'\n				&& defined( $value->{'properties\
'}{'property'}{$key}{'value'} )\n			  )\n			{\n			\
	print \"\\t\", $key, \"\\t\",\n				  $value->{'pr\
operties'}{'property'}{$key}{'value'}, \"\\n\";\n	\
		}\n			else {\n				print \"\\t\", $value->{'prope\
rties'}{'property'}{'key'},\n				  \"\\t\", $value\
->{'properties'}{'property'}{'value'}, \"\\n\";\n	\
			last;\n			}\n		}\n	}\n}\n\n=head2 print_job_sta\
tus()\n\nPrint status of a job.\n\n  &print_job_st\
atus($job_id);\n\n=cut\n\nsub print_job_status {\n\
	print_debug_message( 'print_job_status', 'Begin',\
 1 );\n	my $jobid = shift;\n	print_debug_message( \
'print_job_status', 'jobid: ' . $jobid, 1 );\n	if \
( $outputLevel > 0 ) {\n		print STDERR 'Getting st\
atus for job ', $jobid, \"\\n\";\n	}\n	my $result \
= &rest_get_status($jobid);\n	print \"$result\\n\"\
;\n	if ( $result eq 'FINISHED' && $outputLevel > 0\
 ) {\n		print STDERR \"To get results: $scriptName\
 --polljob --jobid \" . $jobid\n		  . \"\\n\";\n	}\
\n	print_debug_message( 'print_job_status', 'End',\
 1 );\n}\n\n=head2 print_result_types()\n\nPrint a\
vailable result types for a job.\n\n  &print_resul\
t_types($job_id);\n\n=cut\n\nsub print_result_type\
s {\n	print_debug_message( 'result_types', 'Begin'\
, 1 );\n	my $jobid = shift;\n	print_debug_message(\
 'result_types', 'jobid: ' . $jobid, 1 );\n	if ( $\
outputLevel > 0 ) {\n		print STDERR 'Getting resul\
t types for job ', $jobid, \"\\n\";\n	}\n	my $stat\
us = &rest_get_status($jobid);\n	if ( $status eq '\
PENDING' || $status eq 'RUNNING' ) {\n		print STDE\
RR 'Error: Job status is ', $status,\n		  '. To ge\
t result types the job must be finished.', \"\\n\"\
;\n	}\n	else {\n		my (@resultTypes) = &rest_get_re\
sult_types($jobid);\n		if ( $outputLevel > 0 ) {\n\
			print STDOUT 'Available result types:', \"\\n\"\
;\n		}\n		foreach my $resultType (@resultTypes) {\\
n			print STDOUT $resultType->{'identifier'}, \"\\\
n\";\n			if ( defined( $resultType->{'label'} ) ) \
{\n				print STDOUT \"\\t\", $resultType->{'label'\
}, \"\\n\";\n			}\n			if ( defined( $resultType->{\
'description'} ) ) {\n				print STDOUT \"\\t\", $r\
esultType->{'description'}, \"\\n\";\n			}\n			if \
( defined( $resultType->{'mediaType'} ) ) {\n				p\
rint STDOUT \"\\t\", $resultType->{'mediaType'}, \\
"\\n\";\n			}\n			if ( defined( $resultType->{'fil\
eSuffix'} ) ) {\n				print STDOUT \"\\t\", $result\
Type->{'fileSuffix'}, \"\\n\";\n			}\n		}\n		if ( \
$status eq 'FINISHED' && $outputLevel > 0 ) {\n			\
print STDERR \"\\n\", 'To get results:', \"\\n\",\\
n			  \"  $scriptName --polljob --jobid \" . $para\
ms{'jobid'} . \"\\n\",\n			  \"  $scriptName --pol\
ljob --outformat <type> --jobid \"\n			  . $params\
{'jobid'} . \"\\n\";\n		}\n	}\n	print_debug_messag\
e( 'result_types', 'End', 1 );\n}\n\n=head2 submit\
_job()\n\nSubmit a job to the service.\n\n  &submi\
t_job($seq);\n\n=cut\n\nsub submit_job {\n	print_d\
ebug_message( 'submit_job', 'Begin', 1 );\n\n	# Se\
t input sequence\n	$tool_params{'sequence'} = shif\
t;\n\n	# Load parameters\n	&load_params();\n\n	# S\
ubmit the job\n	my $jobid = &rest_run( $params{'em\
ail'}, $params{'title'}, \\%tool_params );\n\n	# S\
imulate sync/async mode\n	if ( defined( $params{'a\
sync'} ) ) {\n		print STDOUT $jobid, \"\\n\";\n		i\
f ( $outputLevel > 0 ) {\n			print STDERR\n			  \"\
To check status: $scriptName --status --jobid $job\
id\\n\";\n		}\n	}\n	else {\n		if ( $outputLevel > \
0 ) {\n			print STDERR \"JobId: $jobid\\n\";\n		}\\
n		sleep 1;\n		&get_results($jobid);\n	}\n	print_d\
ebug_message( 'submit_job', 'End', 1 );\n}\n\n=hea\
d2 multi_submit_job()\n\nSubmit multiple jobs assu\
ming input is a collection of fasta formatted sequ\
ences.\n\n  &multi_submit_job();\n\n=cut\n\nsub mu\
lti_submit_job {\n	print_debug_message( 'multi_sub\
mit_job', 'Begin', 1 );\n	my $jobIdForFilename = 1\
;\n	$jobIdForFilename = 0 if ( defined( $params{'o\
utfile'} ) );\n	my (@filename_list) = ();\n\n	# Qu\
ery sequence\n	if ( defined( $ARGV[0] ) ) {    # B\
are option\n		if ( -f $ARGV[0] || $ARGV[0] eq '-' \
) {    # File\n			push( @filename_list, $ARGV[0] )\
;\n		}\n		else {\n			warn 'Warning: Input file \"'\
 . $ARGV[0] . '\" does not exist'\n		}\n	}\n	if ( \
$params{'sequence'} ) {                   # Via --\
sequence\n		if ( -f $params{'sequence'} || $params\
{'sequence'} eq '-' ) {    # File\n			push( @filen\
ame_list, $params{'sequence'} );\n		}\n		else {\n	\
		warn 'Warning: Input file \"' . $params{'sequenc\
e'} . '\" does not exist'\n		}\n	}\n\n	$/ = '>';\n\
	foreach my $filename (@filename_list) {\n		my $IN\
FILE;\n		if($filename eq '-') { # STDIN.\n			open(\
 $INFILE, '<-' )\n			  or die 'Error: unable to ST\
DIN (' . $! . ')';\n		} else { # File.\n			open( $\
INFILE, '<', $filename )\n			  or die 'Error: unab\
le to open file ' . $filename . ' (' . $! . ')';\n\
		}\n		while (<$INFILE>) {\n			my $seq = $_;\n			$\
seq =~ s/>$//;\n			if ( $seq =~ m/(\\S+)/ ) {\n			\
	print STDERR \"Submitting job for: $1\\n\"\n				 \
 if ( $outputLevel > 0 );\n				$seq = '>' . $seq;\\
n				&print_debug_message( 'multi_submit_job', $se\
q, 11 );\n				&submit_job($seq);\n				$params{'out\
file'} = undef if ( $jobIdForFilename == 1 );\n			\
}\n		}\n		close $INFILE;\n	}\n	print_debug_message\
( 'multi_submit_job', 'End', 1 );\n}\n\n=head2 lis\
t_file_submit_job()\n\nSubmit multiple jobs using \
a file containing a list of entry identifiers as \\
ninput.\n\n  &list_file_submit_job($list_filename)\
\n\n=cut\n\nsub list_file_submit_job {\n	my $filen\
ame         = shift;\n	my $jobIdForFilename = 1;\n\
	$jobIdForFilename = 0 if ( defined( $params{'outf\
ile'} ) );\n\n	# Iterate over identifiers, submitt\
ing each job\n	my $LISTFILE;\n	if($filename eq '-'\
) { # STDIN.\n		open( $LISTFILE, '<-' )\n		  or di\
e 'Error: unable to STDIN (' . $! . ')';\n	} else \
{ # File.\n		open( $LISTFILE, '<', $filename )\n		\
  or die 'Error: unable to open file ' . $filename\
 . ' (' . $! . ')';\n	}\n	while (<$LISTFILE>) {\n	\
	my $line = $_;\n		chomp($line);\n		if ( $line ne \
'' ) {\n			&print_debug_message( 'list_file_submit\
_job', 'line: ' . $line, 2 );\n			if ( $line =~ m/\
\\w:\\w/ ) {    # Check this is an identifier\n			\
	print STDERR \"Submitting job for: $line\\n\"\n		\
		  if ( $outputLevel > 0 );\n				&submit_job($lin\
e);\n			}\n			else {\n				print STDERR\n\"Warning:\
 line \\\"$line\\\" is not recognised as an identi\
fier\\n\";\n			}\n		}\n		$params{'outfile'} = unde\
f if ( $jobIdForFilename == 1 );\n	}\n	close $LIST\
FILE;\n}\n\n=head2 load_data()\n\nLoad sequence da\
ta from file or option specified on the command-li\
ne.\n\n  &load_data();\n\n=cut\n\nsub load_data {\\
n	print_debug_message( 'load_data', 'Begin', 1 );\\
n	my $retSeq;\n\n	# Query sequence\n	if ( defined(\
 $ARGV[0] ) ) {    # Bare option\n		if ( -f $ARGV[\
0] || $ARGV[0] eq '-' ) {    # File\n			$retSeq = \
&read_file( $ARGV[0] );\n		}\n		else {            \
                         # DB:ID or sequence\n			$\
retSeq = $ARGV[0];\n		}\n	}\n	if ( $params{'sequen\
ce'} ) {                   # Via --sequence\n		if \
( -f $params{'sequence'} || $params{'sequence'} eq\
 '-' ) {    # File\n			$retSeq = &read_file( $para\
ms{'sequence'} );\n		}\n		else {    # DB:ID or seq\
uence\n			$retSeq = $params{'sequence'};\n		}\n	}\\
n	print_debug_message( 'load_data', 'End', 1 );\n	\
return $retSeq;\n}\n\n=head2 load_params()\n\nLoad\
 job parameters from command-line options.\n\n  &l\
oad_params();\n\n=cut\n\nsub load_params {\n	print\
_debug_message( 'load_params', 'Begin', 1 );\n\n	#\
 Database(s) to search\n	my (@dbList) = split /[ ,\
]/, $params{'database'};\n	$tool_params{'database'\
} = \\@dbList;\n\n	# Match/missmatch\n	if ( $param\
s{'match'} && $params{'missmatch'} ) {\n		$tool_pa\
rams{'match_scores'} =\n		  $params{'match'} . ','\
 . $params{'missmatch'};\n	}\n	\n	# Compatability \
options, old command-line\n	if(!$tool_params{'alig\
nments'} && $params{'numal'}) {\n		$tool_params{'a\
lignments'} = $params{'numal'};\n	}\n	if(!$tool_pa\
rams{'gapopen'} && $params{'opengap'}) {\n		$tool_\
params{'gapopen'} = $params{'opengap'};\n	}\n	if(!\
$tool_params{'gapext'} && $params{'extendgap'}) {\\
n		$tool_params{'gapext'} = $params{'extendgap'};\\
n	}\n\n	print_debug_message( 'load_params', 'End',\
 1 );\n}\n\n=head2 client_poll()\n\nClient-side jo\
b polling.\n\n  &client_poll($job_id);\n\n=cut\n\n\
sub client_poll {\n	print_debug_message( 'client_p\
oll', 'Begin', 1 );\n	my $jobid  = shift;\n	my $st\
atus = 'PENDING';\n\n	my $errorCount = 0;\n	while \
($status eq 'RUNNING'\n		|| $status eq 'PENDING'\n\
		|| ( $status eq 'ERROR' && $errorCount < 2 ) )\n\
	{\n		$status = rest_get_status($jobid);\n		print \
STDERR \"$status\\n\" if ( $outputLevel > 0 );\n		\
if ( $status eq 'ERROR' ) {\n			$errorCount++;\n		\
}\n		elsif ( $errorCount > 0 ) {\n			$errorCount--\
;\n		}\n		if (   $status eq 'RUNNING'\n			|| $stat\
us eq 'PENDING'\n			|| $status eq 'ERROR' )\n		{\n\
\n			# Wait before polling again.\n			sleep $check\
Interval;\n		}\n	}\n	print_debug_message( 'client_\
poll', 'End', 1 );\n	return $status;\n}\n\n=head2 \
get_results()\n\nGet the results for a job identif\
ier.\n\n  &get_results($job_id);\n\n=cut\n\nsub ge\
t_results {\n	print_debug_message( 'get_results', \
'Begin', 1 );\n	my $jobid = shift;\n	print_debug_m\
essage( 'get_results', 'jobid: ' . $jobid, 1 );\n\\
n	# Verbose\n	if ( $outputLevel > 1 ) {\n		print '\
Getting results for job ', $jobid, \"\\n\";\n	}\n\\
n	# Check status, and wait if not finished\n	clien\
t_poll($jobid);\n\n	# Use JobId if output file nam\
e is not defined\n	unless ( defined( $params{'outf\
ile'} ) ) {\n		$params{'outfile'} = $jobid;\n	}\n\\
n	# Get list of data types\n	my (@resultTypes) = r\
est_get_result_types($jobid);\n\n	# Get the data a\
nd write it to a file\n	if ( defined( $params{'out\
format'} ) ) {    # Specified data type\n		my $sel\
ResultType;\n		foreach my $resultType (@resultType\
s) {\n			if ( $resultType->{'identifier'} eq $para\
ms{'outformat'} ) {\n				$selResultType = $resultT\
ype;\n			}\n		}\n		if ( defined($selResultType) ) \
{\n			my $result =\n			  rest_get_result( $jobid, \
$selResultType->{'identifier'} );\n			if ( $params\
{'outfile'} eq '-' ) {\n				write_file( $params{'o\
utfile'}, $result );\n			}\n			else {\n				write_f\
ile(\n					$params{'outfile'} . '.'\n					  . $sel\
ResultType->{'identifier'} . '.'\n					  . $selRes\
ultType->{'fileSuffix'},\n					$result\n				);\n		\
	}\n		}\n		else {\n			die 'Error: unknown result f\
ormat \"' . $params{'outformat'} . '\"';\n		}\n	}\\
n	else {    # Data types available\n		      # Writ\
e a file for each output type\n		for my $resultTyp\
e (@resultTypes) {\n			if ( $outputLevel > 1 ) {\n\
				print STDERR 'Getting ', $resultType->{'identi\
fier'}, \"\\n\";\n			}\n			my $result = rest_get_r\
esult( $jobid, $resultType->{'identifier'} );\n			\
if ( $params{'outfile'} eq '-' ) {\n				write_file\
( $params{'outfile'}, $result );\n			}\n			else {\\
n				write_file(\n					$params{'outfile'} . '.'\n	\
				  . $resultType->{'identifier'} . '.'\n					  \
. $resultType->{'fileSuffix'},\n					$result\n				\
);\n			}\n		}\n	}\n	print_debug_message( 'get_resu\
lts', 'End', 1 );\n}\n\n=head2 read_file()\n\nRead\
 a file into a scalar. The special filename '-' ca\
n be used to read from \nstandard input (STDIN).\n\
\n  my $data = &read_file($filename);\n\n=cut\n\ns\
ub read_file {\n	print_debug_message( 'read_file',\
 'Begin', 1 );\n	my $filename = shift;\n	print_deb\
ug_message( 'read_file', 'filename: ' . $filename,\
 2 );\n	my ( $content, $buffer );\n	if ( $filename\
 eq '-' ) {\n		while ( sysread( STDIN, $buffer, 10\
24 ) ) {\n			$content .= $buffer;\n		}\n	}\n	else \
{    # File\n		open( my $FILE, '<', $filename )\n	\
	  or die \"Error: unable to open input file $file\
name ($!)\";\n		while ( sysread( $FILE, $buffer, 1\
024 ) ) {\n			$content .= $buffer;\n		}\n		close($\
FILE);\n	}\n	print_debug_message( 'read_file', 'En\
d', 1 );\n	return $content;\n}\n\n=head2 write_fil\
e()\n\nWrite data to a file. The special filename \
'-' can be used to write to \nstandard output (STD\
OUT).\n\n  &write_file($filename, $data);\n\n=cut\\
n\nsub write_file {\n	print_debug_message( 'write_\
file', 'Begin', 1 );\n	my ( $filename, $data ) = @\
_;\n	print_debug_message( 'write_file', 'filename:\
 ' . $filename, 2 );\n	if ( $outputLevel > 0 ) {\n\
		print STDERR 'Creating result file: ' . $filenam\
e . \"\\n\";\n	}\n	if ( $filename eq '-' ) {\n		pr\
int STDOUT $data;\n	}\n	else {\n		open( my $FILE, \
'>', $filename )\n		  or die \"Error: unable to op\
en output file $filename ($!)\";\n		syswrite( $FIL\
E, $data );\n		close($FILE);\n	}\n	print_debug_mes\
sage( 'write_file', 'End', 1 );\n}\n\n=head2 usage\
()\n\nPrint program usage message.\n\n  &usage();\\
n\n=cut\n\nsub usage {\n	print STDERR <<EOF\nNCBI \
BLAST\n==========\n   \nRapid sequence database se\
arch programs utilizing the BLAST algorithm\n    \\
n[Required]\n\n  -p, --program      : str  : BLAST\
 program to use, see --paramDetail program\n  -D, \
--database     : str  : database(s) to search, spa\
ce separated. See\n                              -\
-paramDetail database\n      --stype        : str \
 : query sequence type, see --paramDetail stype\n \
 seqFile            : file : query sequence (\"-\"\
 for STDIN, \\@filename for\n                     \
         identifier list file)\n\n[Optional]\n\n  \
-m, --matrix       : str  : scoring matrix, see --\
paramDetail matrix\n  -e, --exp          : real : \
0<E<= 1000. Statistical significance threshold \n \
                             for reporting databas\
e sequence matches.\n  -f, --filter       :      :\
 filter the query sequence for low complexity \n  \
                            regions, see --paramDe\
tail filter\n  -A, --align        : int  : pairwis\
e alignment format, see --paramDetail align\n  -s,\
 --scores       : int  : number of scores to be re\
ported\n  -n, --alignments   : int  : number of al\
ignments to report\n  -u, --match        : int  : \
Match score (BLASTN only)\n  -v, --mismatch     : \
int  : Mismatch score (BLASTN only)\n  -o, --gapop\
en      : int  : Gap open penalty\n  -x, --gapext \
      : int  : Gap extension penalty\n  -d, --drop\
off      : int  : Drop-off\n  -g, --gapalign     :\
      : Optimise gapped alignments\n      --seqran\
ge     : str  : region within input to use as quer\
y\n      --multifasta   :      : treat input as a \
set of fasta formatted sequences\n\n[General]\n\n \
 -h, --help         :      : prints this help text\
\n      --async        :      : forces to make an \
asynchronous query\n      --email        : str  : \
e-mail address\n      --title        : str  : titl\
e for job\n      --status       :      : get job s\
tatus\n      --resultTypes  :      : get available\
 result types for job\n      --polljob      :     \
 : poll for the status of a job\n      --jobid    \
    : str  : jobid that was returned when an async\
hronous job \n                              was su\
bmitted.\n      --outfile      : str  : file name \
for results (default is jobid;\n                  \
            \"-\" for STDOUT)\n      --outformat  \
  : str  : result format to retrieve\n      --para\
ms       :      : list input parameters\n      --p\
aramDetail  : str  : display details for input par\
ameter\n      --quiet        :      : decrease out\
put\n      --verbose      :      : increase output\
\n   \nSynchronous job:\n\n  The results/errors ar\
e returned as soon as the job is finished.\n  Usag\
e: $scriptName --email <your\\@email> [options...]\
 seqFile\n  Returns: results as an attachment\n\nA\
synchronous job:\n\n  Use this if you want to retr\
ieve the results at a later time. The results \n  \
are stored for up to 24 hours. 	\n  Usage: $script\
Name --async --email <your\\@email> [options...] s\
eqFile\n  Returns: jobid\n\n  Use the jobid to que\
ry for the status of the job. If the job is finish\
ed, \n  it also returns the results/errors.\n  Usa\
ge: $scriptName --polljob --jobid <jobId> [--outfi\
le string]\n  Returns: string indicating the statu\
s of the job and if applicable, results \n  as an \
attachment.\n\nFurther information:\n\n  http://ww\
w.ebi.ac.uk/Tools/webservices/services/sss/ncbi_bl\
ast_rest\n  http://www.ebi.ac.uk/Tools/webservices\
/tutorials/perl\n\nSupport/Feedback:\n\n  http://w\
ww.ebi.ac.uk/support/\nEOF\n}\n\n=head1 FEEDBACK/S\
UPPORT\n\nPlease contact us at L<http://www.ebi.ac\
.uk/support/> if you have any \nfeedback, suggesti\
ons or issues with the service or this client.\n\n\
=cut\n","\n=head1 NAME\n\nwublast_lwp.pl\n\n=head1\
 DESCRIPTION\n\nWU-BLAST (REST) web service Perl c\
lient using L<LWP>.\n\nTested with:\n\n=over\n\n=i\
tem *\nL<LWP> 5.79, L<XML::Simple> 2.12 and Perl 5\
.8.3\n\n=item *\nL<LWP> 5.808, L<XML::Simple> 2.18\
 and Perl 5.8.8 (Ubuntu 8.04 LTS)\n\n=item *\nL<LW\
P> 5.834, L<XML::Simple> 2.18 and Perl 5.10.1 (Ubu\
ntu 10.04 LTS)\n\n=item *\nL<LWP> 6.03, L<XML::Sim\
ple> 2.18 and Perl 5.14.2 (Ubuntu 12.04 LTS)\n\n=b\
ack\n\nFor further information see:\n\n=over\n\n=i\
tem *\nL<http://www.ebi.ac.uk/Tools/webservices/se\
rvices/sss/wu_blast_rest>\n\n=item *\nL<http://www\
.ebi.ac.uk/Tools/webservices/tutorials/perl>\n\n=b\
ack\n\n=head1 LICENSE\n\nCopyright 2012-2013 EMBL \
- European Bioinformatics Institute\n\nLicensed un\
der the Apache License, Version 2.0 (the \"License\
\");\nyou may not use this file except in complian\
ce with the License.\nYou may obtain a copy of the\
 License at\n\n    http://www.apache.org/licenses/\
LICENSE-2.0\n\nUnless required by applicable law o\
r agreed to in writing, software\ndistributed unde\
r the License is distributed on an \"AS IS\" BASIS\
,\nWITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, e\
ither express or implied.\nSee the License for the\
 specific language governing permissions and\nlimi\
tations under the License.\n\n=head1 VERSION\n\n$I\
d: wublast_lwp.pl 2560 2013-03-20 12:56:31Z hpm $\\
n\n=cut\n\nuse strict;\nuse warnings;\n\nuse Engli\
sh;\nuse LWP;\nuse XML::Simple;\nuse Getopt::Long \
qw(:config no_ignore_case bundling);\nuse File::Ba\
sename;\nuse Data::Dumper;\n\nmy $baseUrl = 'http:\
//www.ebi.ac.uk/Tools/services/rest/wublast';\n\nm\
y $checkInterval = 3;\n\nmy $outputLevel = 1;\n\nm\
y $numOpts = scalar(@ARGV);\nmy %params = ( 'debug\
Level' => 0 );\n\nmy %tool_params = ();\nGetOption\
s(\n\n	# Tool specific options\n	'program|p=s'    \
 => \\$tool_params{'program'},      # BLAST progra\
m\n	'database|D=s'    => \\$params{'database'},   \
  # Search database\n	'matrix|m=s'      => \\$tool\
_params{'matrix'},       # Scoring matrix\n	'exp|E\
=f'         => \\$tool_params{'exp'},          # E\
-value threshold\n	'viewfilter|e'    => \\$tool_pa\
rams{'viewfilter'},   # Display filtered sequence\\
n	'filter|f=s'      => \\$tool_params{'filter'},  \
     # Low complexity filter name\n	'alignments|n=\
i'  => \\$tool_params{'alignments'},   # Number of\
 alignments\n	'scores|s=i'      => \\$tool_params{\
'scores'},       # Number of scores\n	'sensitivity\
|S=s' => \\$tool_params{'sensitivity'},  # Search \
sensitivity\n	'sort|t=s'        => \\$tool_params{\
'sort'},         # Sort hits by...\n	'stats|T=s'  \
     => \\$tool_params{'stats'},        # Scoring \
statistic to use\n	'strand|d=s'      => \\$tool_pa\
rams{'strand'},       # Strand to use\n	'topcombon\
|c=i'   => \\$tool_params{'topcombon'},    # Consi\
stent sets of HSPs\n	'align|A=i'       => \\$tool_\
params{'align'},   # Pairwise alignment format\n	'\
stype=s' => \\$tool_params{'stype'},    # Sequence\
 type 'protein' or 'dna'\n	'sequence=s' => \\$para\
ms{'sequence'},         # Query sequence file or D\
B:ID\n	'multifasta' => \\$params{'multifasta'},   \
    # Multiple fasta input\n\n	# Compatability opt\
ions, old command-line.\n	'echofilter|e'    => \\$\
params{'echofilter'},   # Display filtered sequenc\
e\n	'b=i'  => \\$params{'numal'},        # Number \
of alignments\n	'appxml=s'        => \\$params{'ap\
pxml'},       # Application XML\n\n	# Generic opti\
ons\n	'email=s'       => \\$params{'email'},      \
    # User e-mail address\n	'title=s'       => \\$\
params{'title'},          # Job title\n	'outfile=s\
'     => \\$params{'outfile'},        # Output fil\
e name\n	'outformat=s'   => \\$params{'outformat'}\
,      # Output file type\n	'jobid=s'       => \\$\
params{'jobid'},          # JobId\n	'help|h'      \
  => \\$params{'help'},           # Usage help\n	'\
async'         => \\$params{'async'},          # A\
synchronous submission\n	'polljob'       => \\$par\
ams{'polljob'},        # Get results\n	'resultType\
s'   => \\$params{'resultTypes'},    # Get result \
types\n	'status'        => \\$params{'status'},   \
      # Get status\n	'params'        => \\$params{\
'params'},         # List input parameters\n	'para\
mDetail=s' => \\$params{'paramDetail'},    # Get d\
etails for parameter\n	'quiet'         => \\$param\
s{'quiet'},          # Decrease output level\n	've\
rbose'       => \\$params{'verbose'},        # Inc\
rease output level\n	'debugLevel=i'  => \\$params{\
'debugLevel'},     # Debug output level\n	'baseUrl\
=s'     => \\$baseUrl,                  # Base URL\
 for service.\n);\nif ( $params{'verbose'} ) { $ou\
tputLevel++ }\nif ( $params{'quiet'} )  { $outputL\
evel-- }\n\n&print_debug_message( 'MAIN', 'LWP::VE\
RSION: ' . $LWP::VERSION,\n	1 );\n\n&print_debug_m\
essage( 'MAIN', \"params:\\n\" . Dumper( \\%params\
 ),           11 );\n&print_debug_message( 'MAIN',\
 \"tool_params:\\n\" . Dumper( \\%tool_params ), 1\
1 );\n\nmy $ua;\n\nmy $scriptName = basename( $0, \
() );\n\nif ( $params{'help'} || $numOpts == 0 ) {\
\n	&usage();\n	exit(0);\n}\n\n&print_debug_message\
( 'MAIN', 'baseUrl: ' . $baseUrl, 1 );\n\nif (\n	!\
(\n		   $params{'polljob'}\n		|| $params{'resultTy\
pes'}\n		|| $params{'status'}\n		|| $params{'param\
s'}\n		|| $params{'paramDetail'}\n	)\n	&& !( defin\
ed( $ARGV[0] ) || defined( $params{'sequence'} ) )\
\n  )\n{\n\n	# Bad argument combination, so print \
error message and usage\n	print STDERR 'Error: bad\
 option combination', \"\\n\";\n	&usage();\n	exit(\
1);\n}\n\nelsif ( $params{'params'} ) {\n	&print_t\
ool_params();\n}\n\nelsif ( $params{'paramDetail'}\
 ) {\n	&print_param_details( $params{'paramDetail'\
} );\n}\n\nelsif ( $params{'status'} && defined( $\
params{'jobid'} ) ) {\n	&print_job_status( $params\
{'jobid'} );\n}\n\nelsif ( $params{'resultTypes'} \
&& defined( $params{'jobid'} ) ) {\n	&print_result\
_types( $params{'jobid'} );\n}\n\nelsif ( $params{\
'polljob'} && defined( $params{'jobid'} ) ) {\n	&g\
et_results( $params{'jobid'} );\n}\n\nelse {\n\n	#\
 Multiple input sequence mode, assume fasta format\
.\n	if ( $params{'multifasta'} ) {\n		&multi_submi\
t_job();\n	}\n\n	# Entry identifier list file.\n	e\
lsif (( defined( $params{'sequence'} ) && $params{\
'sequence'} =~ m/^\\@/ )\n		|| ( defined( $ARGV[0]\
 ) && $ARGV[0] =~ m/^\\@/ ) )\n	{\n		my $list_file\
name = $params{'sequence'} || $ARGV[0];\n		$list_f\
ilename =~ s/^\\@//;\n		&list_file_submit_job($lis\
t_filename);\n	}\n\n	# Default: single sequence/id\
entifier.\n	else {\n\n		# Load the sequence data a\
nd submit.\n		&submit_job( &load_data() );\n	}\n}\\
n\n=head1 FUNCTIONS\n\n=cut\n\n\n=head2 rest_user_\
agent()\n\nGet a LWP UserAgent to use to perform R\
EST requests.\n\n  my $ua = &rest_user_agent();\n\\
n=cut\n\nsub rest_user_agent() {\n	print_debug_mes\
sage( 'rest_user_agent', 'Begin', 21 );\n	# Create\
 an LWP UserAgent for making HTTP calls.\n	my $ua \
= LWP::UserAgent->new();\n	# Set 'User-Agent' HTTP\
 header to identifiy the client.\n	'$Revision: 256\
0 $' =~ m/(\\d+)/;\n	$ua->agent(\"EBI-Sample-Clien\
t/$1 ($scriptName; $OSNAME) \" . $ua->agent());\n	\
# Configure HTTP proxy support from environment.\n\
	$ua->env_proxy;\n	print_debug_message( 'rest_user\
_agent', 'End', 21 );\n	return $ua;\n}\n\n=head2 r\
est_error()\n\nCheck a REST response for an error \
condition. An error is mapped to a die.\n\n  &rest\
_error($response, $content_data);\n\n=cut\n\nsub r\
est_error() {\n	print_debug_message( 'rest_error',\
 'Begin', 21 );\n	my $response = shift;\n	my $cont\
entdata;\n	if(scalar(@_) > 0) {\n		$contentdata = \
shift;\n	}\n	if(!defined($contentdata) || $content\
data eq '') {\n		$contentdata = $response->content\
();\n	}\n	# Check for HTTP error codes\n	if ( $res\
ponse->is_error ) {\n		my $error_message = '';\n		\
# HTML response.\n		if(	$contentdata =~ m/<h1>([^<\
]+)<\\/h1>/ ) {\n			$error_message = $1;\n		}\n		#\
  XML response.\n		elsif($contentdata =~ m/<descri\
ption>([^<]+)<\\/description>/) {\n			$error_messa\
ge = $1;\n		}\n		die 'http status: ' . $response->\
code . ' ' . $response->message . '  ' . $error_me\
ssage;\n	}\n	print_debug_message( 'rest_error', 'E\
nd', 21 );\n}\n\n=head2 rest_request()\n\nPerform \
a REST request (HTTP GET).\n\n  my $response_str =\
 &rest_request($url);\n\n=cut\n\nsub rest_request \
{\n	print_debug_message( 'rest_request', 'Begin', \
11 );\n	my $requestUrl = shift;\n	print_debug_mess\
age( 'rest_request', 'URL: ' . $requestUrl, 11 );\\
n\n	# Get an LWP UserAgent.\n	$ua = &rest_user_age\
nt() unless defined($ua);\n	# Available HTTP compr\
ession methods.\n	my $can_accept;\n	eval {\n	    $\
can_accept = HTTP::Message::decodable();\n	};\n	$c\
an_accept = '' unless defined($can_accept);\n	# Pe\
rform the request\n	my $response = $ua->get($reque\
stUrl,\n		'Accept-Encoding' => $can_accept, # HTTP\
 compression.\n	);\n	print_debug_message( 'rest_re\
quest', 'HTTP status: ' . $response->code,\n		11 )\
;\n	print_debug_message( 'rest_request',\n		'respo\
nse length: ' . length($response->content()), 11 )\
;\n	print_debug_message( 'rest_request',\n		'reque\
st:' .\"\\n\" . $response->request()->as_string(),\
 32 );\n	print_debug_message( 'rest_request',\n		'\
response: ' . \"\\n\" . $response->as_string(), 32\
 );\n	# Unpack possibly compressed response.\n	my \
$retVal;\n	if ( defined($can_accept) && $can_accep\
t ne '') {\n	    $retVal = $response->decoded_cont\
ent();\n	}\n	# If unable to decode use orginal con\
tent.\n	$retVal = $response->content() unless defi\
ned($retVal);\n	# Check for an error.\n	&rest_erro\
r($response, $retVal);\n	print_debug_message( 'res\
t_request', 'retVal: ' . $retVal, 12 );\n	print_de\
bug_message( 'rest_request', 'End', 11 );\n\n	# Re\
turn the response data\n	return $retVal;\n}\n\n=he\
ad2 rest_get_parameters()\n\nGet list of tool para\
meter names.\n\n  my (@param_list) = &rest_get_par\
ameters();\n\n=cut\n\nsub rest_get_parameters {\n	\
print_debug_message( 'rest_get_parameters', 'Begin\
', 1 );\n	my $url                = $baseUrl . '/pa\
rameters/';\n	my $param_list_xml_str = rest_reques\
t($url);\n	my $param_list_xml     = XMLin($param_l\
ist_xml_str);\n	my (@param_list)       = @{ $param\
_list_xml->{'id'} };\n	print_debug_message( 'rest_\
get_parameters', 'End', 1 );\n	return (@param_list\
);\n}\n\n=head2 rest_get_parameter_details()\n\nGe\
t details of a tool parameter.\n\n  my $paramDetai\
l = &rest_get_parameter_details($param_name);\n\n=\
cut\n\nsub rest_get_parameter_details {\n	print_de\
bug_message( 'rest_get_parameter_details', 'Begin'\
, 1 );\n	my $parameterId = shift;\n	print_debug_me\
ssage( 'rest_get_parameter_details',\n		'parameter\
Id: ' . $parameterId, 1 );\n	my $url              \
    = $baseUrl . '/parameterdetails/' . $parameter\
Id;\n	my $param_detail_xml_str = rest_request($url\
);\n	my $param_detail_xml     = XMLin($param_detai\
l_xml_str);\n	print_debug_message( 'rest_get_param\
eter_details', 'End', 1 );\n	return ($param_detail\
_xml);\n}\n\n=head2 rest_run()\n\nSubmit a job.\n\\
n  my $job_id = &rest_run($email, $title, \\%param\
s );\n\n=cut\n\nsub rest_run {\n	print_debug_messa\
ge( 'rest_run', 'Begin', 1 );\n	my $email  = shift\
;\n	my $title  = shift;\n	my $params = shift;\n	pr\
int_debug_message( 'rest_run', 'email: ' . $email,\
 1 );\n	if ( defined($title) ) {\n		print_debug_me\
ssage( 'rest_run', 'title: ' . $title, 1 );\n	}\n	\
print_debug_message( 'rest_run', 'params: ' . Dump\
er($params), 1 );\n\n	# Get an LWP UserAgent.\n	$u\
a = &rest_user_agent() unless defined($ua);\n\n	# \
Clean up parameters\n	my (%tmp_params) = %{$params\
};\n	$tmp_params{'email'} = $email;\n	$tmp_params{\
'title'} = $title;\n	foreach my $param_name ( keys\
(%tmp_params) ) {\n		if ( !defined( $tmp_params{$p\
aram_name} ) ) {\n			delete $tmp_params{$param_nam\
e};\n		}\n	}\n\n	# Submit the job as a POST\n	my $\
url = $baseUrl . '/run';\n	my $response = $ua->pos\
t( $url, \\%tmp_params );\n	print_debug_message( '\
rest_run', 'HTTP status: ' . $response->code, 11 )\
;\n	print_debug_message( 'rest_run',\n		'request:'\
 .\"\\n\" . $response->request()->as_string(), 11 \
);\n	print_debug_message( 'rest_run',\n		'response\
: ' . length($response->as_string()) . \"\\n\" . $\
response->as_string(), 11 );\n\n	# Check for an er\
ror.\n	&rest_error($response);\n\n	# The job id is\
 returned\n	my $job_id = $response->content();\n	p\
rint_debug_message( 'rest_run', 'End', 1 );\n	retu\
rn $job_id;\n}\n\n=head2 rest_get_status()\n\nChec\
k the status of a job.\n\n  my $status = &rest_get\
_status($job_id);\n\n=cut\n\nsub rest_get_status {\
\n	print_debug_message( 'rest_get_status', 'Begin'\
, 1 );\n	my $job_id = shift;\n	print_debug_message\
( 'rest_get_status', 'jobid: ' . $job_id, 2 );\n	m\
y $status_str = 'UNKNOWN';\n	my $url        = $bas\
eUrl . '/status/' . $job_id;\n	$status_str = &rest\
_request($url);\n	print_debug_message( 'rest_get_s\
tatus', 'status_str: ' . $status_str, 2 );\n	print\
_debug_message( 'rest_get_status', 'End', 1 );\n	r\
eturn $status_str;\n}\n\n=head2 rest_get_result_ty\
pes()\n\nGet list of result types for finished job\
.\n\n  my (@result_types) = &rest_get_result_types\
($job_id);\n\n=cut\n\nsub rest_get_result_types {\\
n	print_debug_message( 'rest_get_result_types', 'B\
egin', 1 );\n	my $job_id = shift;\n	print_debug_me\
ssage( 'rest_get_result_types', 'jobid: ' . $job_i\
d, 2 );\n	my (@resultTypes);\n	my $url            \
          = $baseUrl . '/resulttypes/' . $job_id;\\
n	my $result_type_list_xml_str = &rest_request($ur\
l);\n	my $result_type_list_xml     = XMLin($result\
_type_list_xml_str);\n	(@resultTypes) = @{ $result\
_type_list_xml->{'type'} };\n	print_debug_message(\
 'rest_get_result_types',\n		scalar(@resultTypes) \
. ' result types', 2 );\n	print_debug_message( 're\
st_get_result_types', 'End', 1 );\n	return (@resul\
tTypes);\n}\n\n=head2 rest_get_result()\n\nGet res\
ult data of a specified type for a finished job.\n\
\n  my $result = rest_get_result($job_id, $result_\
type);\n\n=cut\n\nsub rest_get_result {\n	print_de\
bug_message( 'rest_get_result', 'Begin', 1 );\n	my\
 $job_id = shift;\n	my $type   = shift;\n	print_de\
bug_message( 'rest_get_result', 'jobid: ' . $job_i\
d, 1 );\n	print_debug_message( 'rest_get_result', \
'type: ' . $type,    1 );\n	my $url    = $baseUrl \
. '/result/' . $job_id . '/' . $type;\n	my $result\
 = &rest_request($url);\n	print_debug_message( 're\
st_get_result', length($result) . ' characters',\n\
		1 );\n	print_debug_message( 'rest_get_result', '\
End', 1 );\n	return $result;\n}\n\n\n=head2 print_\
debug_message()\n\nPrint debug message at specifie\
d debug level.\n\n  &print_debug_message($method_n\
ame, $message, $level);\n\n=cut\n\nsub print_debug\
_message {\n	my $function_name = shift;\n	my $mess\
age       = shift;\n	my $level         = shift;\n	\
if ( $level <= $params{'debugLevel'} ) {\n		print \
STDERR '[', $function_name, '()] ', $message, \"\\\
n\";\n	}\n}\n\n=head2 print_tool_params()\n\nPrint\
 list of tool parameters.\n\n  &print_tool_params(\
);\n\n=cut\n\nsub print_tool_params {\n	print_debu\
g_message( 'print_tool_params', 'Begin', 1 );\n	my\
 (@param_list) = &rest_get_parameters();\n	foreach\
 my $param ( sort(@param_list) ) {\n		print $param\
, \"\\n\";\n	}\n	print_debug_message( 'print_tool_\
params', 'End', 1 );\n}\n\n=head2 print_param_deta\
ils()\n\nPrint details of a tool parameter.\n\n  &\
print_param_details($param_name);\n\n=cut\n\nsub p\
rint_param_details {\n	print_debug_message( 'print\
_param_details', 'Begin', 1 );\n	my $paramName = s\
hift;\n	print_debug_message( 'print_param_details'\
, 'paramName: ' . $paramName, 2 );\n	my $paramDeta\
il = &rest_get_parameter_details($paramName);\n	pr\
int $paramDetail->{'name'}, \"\\t\", $paramDetail-\
>{'type'}, \"\\n\";\n	print $paramDetail->{'descri\
ption'}, \"\\n\";\n	if(defined($paramDetail->{'val\
ues'}->{'value'})) {\n		if(ref($paramDetail->{'val\
ues'}->{'value'}) eq 'ARRAY') {\n			foreach my $va\
lue ( @{ $paramDetail->{'values'}->{'value'} } ) {\
\n				&print_param_value($value);\n			}\n		}\n		el\
se {\n				&print_param_value($paramDetail->{'value\
s'}->{'value'});\n		}\n	}\n	print_debug_message( '\
print_param_details', 'End', 1 );\n}\n\n=head2 pri\
nt_param_value()\n\nPrint details of a tool parame\
ter value.\n\n  &print_param_details($param_value)\
;\n\nUsed by print_param_details() to handle both \
singluar and array values.\n\n=cut\n\nsub print_pa\
ram_value {\n	my $value = shift;\n	print $value->{\
'value'};\n	if ( $value->{'defaultValue'} eq 'true\
' ) {\n		print \"\\t\", 'default';\n	}\n	print \"\\
\n\";\n	print \"\\t\", $value->{'label'}, \"\\n\";\
\n	if ( defined( $value->{'properties'} ) ) {\n		f\
oreach\n		  my $key ( sort( keys( %{ $value->{'pro\
perties'}{'property'} } ) ) )\n		{\n			if ( ref( $\
value->{'properties'}{'property'}{$key} ) eq 'HASH\
'\n				&& defined( $value->{'properties'}{'propert\
y'}{$key}{'value'} )\n			  )\n			{\n				print \"\\\
t\", $key, \"\\t\",\n				  $value->{'properties'}{\
'property'}{$key}{'value'}, \"\\n\";\n			}\n			els\
e {\n				print \"\\t\", $value->{'properties'}{'pr\
operty'}{'key'},\n				  \"\\t\", $value->{'propert\
ies'}{'property'}{'value'}, \"\\n\";\n				last;\n	\
		}\n		}\n	}\n}\n\n=head2 print_job_status()\n\nPr\
int status of a job.\n\n  &print_job_status($job_i\
d);\n\n=cut\n\nsub print_job_status {\n	print_debu\
g_message( 'print_job_status', 'Begin', 1 );\n	my \
$jobid = shift;\n	print_debug_message( 'print_job_\
status', 'jobid: ' . $jobid, 1 );\n	if ( $outputLe\
vel > 0 ) {\n		print STDERR 'Getting status for jo\
b ', $jobid, \"\\n\";\n	}\n	my $result = &rest_get\
_status($jobid);\n	print \"$result\\n\";\n	if ( $r\
esult eq 'FINISHED' && $outputLevel > 0 ) {\n		pri\
nt STDERR \"To get results: $scriptName --polljob \
--jobid \" . $jobid\n		  . \"\\n\";\n	}\n	print_de\
bug_message( 'print_job_status', 'End', 1 );\n}\n\\
n=head2 print_result_types()\n\nPrint available re\
sult types for a job.\n\n  &print_result_types($jo\
b_id);\n\n=cut\n\nsub print_result_types {\n	print\
_debug_message( 'result_types', 'Begin', 1 );\n	my\
 $jobid = shift;\n	print_debug_message( 'result_ty\
pes', 'jobid: ' . $jobid, 1 );\n	if ( $outputLevel\
 > 0 ) {\n		print STDERR 'Getting result types for\
 job ', $jobid, \"\\n\";\n	}\n	my $status = &rest_\
get_status($jobid);\n	if ( $status eq 'PENDING' ||\
 $status eq 'RUNNING' ) {\n		print STDERR 'Error: \
Job status is ', $status,\n		  '. To get result ty\
pes the job must be finished.', \"\\n\";\n	}\n	els\
e {\n		my (@resultTypes) = &rest_get_result_types(\
$jobid);\n		if ( $outputLevel > 0 ) {\n			print ST\
DOUT 'Available result types:', \"\\n\";\n		}\n		f\
oreach my $resultType (@resultTypes) {\n			print S\
TDOUT $resultType->{'identifier'}, \"\\n\";\n			if\
 ( defined( $resultType->{'label'} ) ) {\n				prin\
t STDOUT \"\\t\", $resultType->{'label'}, \"\\n\";\
\n			}\n			if ( defined( $resultType->{'descriptio\
n'} ) ) {\n				print STDOUT \"\\t\", $resultType->\
{'description'}, \"\\n\";\n			}\n			if ( defined( \
$resultType->{'mediaType'} ) ) {\n				print STDOUT\
 \"\\t\", $resultType->{'mediaType'}, \"\\n\";\n		\
	}\n			if ( defined( $resultType->{'fileSuffix'} )\
 ) {\n				print STDOUT \"\\t\", $resultType->{'fil\
eSuffix'}, \"\\n\";\n			}\n		}\n		if ( $status eq \
'FINISHED' && $outputLevel > 0 ) {\n			print STDER\
R \"\\n\", 'To get results:', \"\\n\",\n			  \"  $\
scriptName --polljob --jobid \" . $params{'jobid'}\
 . \"\\n\",\n			  \"  $scriptName --polljob --outf\
ormat <type> --jobid \"\n			  . $params{'jobid'} .\
 \"\\n\";\n		}\n	}\n	print_debug_message( 'result_\
types', 'End', 1 );\n}\n\n=head2 submit_job()\n\nS\
ubmit a job to the service.\n\n  &submit_job($seq)\
;\n\n=cut\n\nsub submit_job {\n	print_debug_messag\
e( 'submit_job', 'Begin', 1 );\n\n	# Set input seq\
uence\n	$tool_params{'sequence'} = shift;\n\n	# Lo\
ad parameters\n	&load_params();\n\n	# Submit the j\
ob\n	my $jobid = &rest_run( $params{'email'}, $par\
ams{'title'}, \\%tool_params );\n\n	# Simulate syn\
c/async mode\n	if ( defined( $params{'async'} ) ) \
{\n		print STDOUT $jobid, \"\\n\";\n		if ( $output\
Level > 0 ) {\n			print STDERR\n			  \"To check st\
atus: $scriptName --status --jobid $jobid\\n\";\n	\
	}\n	}\n	else {\n		if ( $outputLevel > 0 ) {\n			p\
rint STDERR \"JobId: $jobid\\n\";\n		}\n		sleep 1;\
\n		&get_results($jobid);\n	}\n	print_debug_messag\
e( 'submit_job', 'End', 1 );\n}\n\n=head2 multi_su\
bmit_job()\n\nSubmit multiple jobs assuming input \
is a collection of fasta formatted sequences.\n\n \
 &multi_submit_job();\n\n=cut\n\nsub multi_submit_\
job {\n	print_debug_message( 'multi_submit_job', '\
Begin', 1 );\n	my $jobIdForFilename = 1;\n	$jobIdF\
orFilename = 0 if ( defined( $params{'outfile'} ) \
);\n	my (@filename_list) = ();\n\n	# Query sequenc\
e\n	if ( defined( $ARGV[0] ) ) {    # Bare option\\
n		if ( -f $ARGV[0] || $ARGV[0] eq '-' ) {    # Fi\
le\n			push( @filename_list, $ARGV[0] );\n		}\n		e\
lse {\n			warn 'Warning: Input file \"' . $ARGV[0]\
 . '\" does not exist'\n		}\n	}\n	if ( $params{'se\
quence'} ) {                   # Via --sequence\n	\
	if ( -f $params{'sequence'} || $params{'sequence'\
} eq '-' ) {    # File\n			push( @filename_list, $\
params{'sequence'} );\n		}\n		else {\n			warn 'War\
ning: Input file \"' . $params{'sequence'} . '\" d\
oes not exist'\n		}\n	}\n\n	$/ = '>';\n	foreach my\
 $filename (@filename_list) {\n		my $INFILE;\n		if\
($filename eq '-') { # STDIN.\n			open( $INFILE, '\
<-' )\n			  or die 'Error: unable to STDIN (' . $!\
 . ')';\n		} else { # File.\n			open( $INFILE, '<'\
, $filename )\n			  or die 'Error: unable to open \
file ' . $filename . ' (' . $! . ')';\n		}\n		whil\
e (<$INFILE>) {\n			my $seq = $_;\n			$seq =~ s/>$\
//;\n			if ( $seq =~ m/(\\S+)/ ) {\n				print STDE\
RR \"Submitting job for: $1\\n\"\n				  if ( $outp\
utLevel > 0 );\n				$seq = '>' . $seq;\n				&print\
_debug_message( 'multi_submit_job', $seq, 11 );\n	\
			&submit_job($seq);\n				$params{'outfile'} = un\
def if ( $jobIdForFilename == 1 );\n			}\n		}\n		c\
lose $INFILE;\n	}\n	print_debug_message( 'multi_su\
bmit_job', 'End', 1 );\n}\n\n=head2 list_file_subm\
it_job()\n\nSubmit multiple jobs using a file cont\
aining a list of entry identifiers as \ninput.\n\n\
  &list_file_submit_job($list_filename)\n\n=cut\n\\
nsub list_file_submit_job {\n	print_debug_message(\
 'list_file_submit_job', 'Begin', 11 );\n	my $file\
name         = shift;\n	my $jobIdForFilename = 1;\\
n	$jobIdForFilename = 0 if ( defined( $params{'out\
file'} ) );\n\n	# Iterate over identifiers, submit\
ting each job\n	my $LISTFILE;\n	if($filename eq '-\
') { # STDIN.\n		open( $LISTFILE, '<-' )\n		  or d\
ie 'Error: unable to STDIN (' . $! . ')';\n	} else\
 { # File.\n		open( $LISTFILE, '<', $filename )\n	\
	  or die 'Error: unable to open file ' . $filenam\
e . ' (' . $! . ')';\n	}\n	while (<$LISTFILE>) {\n\
		my $line = $_;\n		chomp($line);\n		if ( $line ne\
 '' ) {\n			&print_debug_message( 'list_file_submi\
t_job', 'line: ' . $line, 2 );\n			if ( $line =~ m\
/\\w:\\w/ ) {    # Check this is an identifier\n		\
		print STDERR \"Submitting job for: $line\\n\"\n	\
			  if ( $outputLevel > 0 );\n				&submit_job($li\
ne);\n			}\n			else {\n				print STDERR\n\"Warning\
: line \\\"$line\\\" is not recognised as an ident\
ifier\\n\";\n			}\n		}\n		$params{'outfile'} = und\
ef if ( $jobIdForFilename == 1 );\n	}\n	close $LIS\
TFILE;\n	print_debug_message( 'list_file_submit_jo\
b', 'End', 11 );\n}\n\n=head2 load_data()\n\nLoad \
sequence data from file or option specified on the\
 command-line.\n\n  &load_data();\n\n=cut\n\nsub l\
oad_data {\n	print_debug_message( 'load_data', 'Be\
gin', 1 );\n	my $retSeq;\n\n	# Query sequence\n	if\
 ( defined( $ARGV[0] ) ) {    # Bare option\n		if \
( -f $ARGV[0] || $ARGV[0] eq '-' ) {    # File\n		\
	$retSeq = &read_file( $ARGV[0] );\n		}\n		else { \
                                    # DB:ID or seq\
uence\n			$retSeq = $ARGV[0];\n		}\n	}\n	if ( $par\
ams{'sequence'} ) {                   # Via --sequ\
ence\n		if ( -f $params{'sequence'} || $params{'se\
quence'} eq '-' ) {    # File\n			$retSeq = &read_\
file( $params{'sequence'} );\n		}\n		else {    # D\
B:ID or sequence\n			$retSeq = $params{'sequence'}\
;\n		}\n	}\n	print_debug_message( 'load_data', 'En\
d', 1 );\n	return $retSeq;\n}\n\n=head2 load_param\
s()\n\nLoad job parameters from command-line optio\
ns.\n\n  &load_params();\n\n=cut\n\nsub load_param\
s {\n	print_debug_message( 'load_params', 'Begin',\
 1 );\n\n	# Database(s) to search\n	my (@dbList) =\
 split /[ ,]/, $params{'database'};\n	$tool_params\
{'database'} = \\@dbList;\n\n	# Compatability opti\
ons, old command-line.\n	if(!$tool_params{'viewfil\
ter'} && $params{'echofilter'}) {\n		$tool_params{\
'viewfilter'} = 'true';\n	}\n	if(!$tool_params{'al\
ignments'} && $params{'numal'}) {\n		$tool_params{\
'alignments'} = $params{'numal'};\n	}\n	# TODO: se\
t alignment format option to get NCBI BLAST XML.\n\
	if($params{'appxml'}) {\n		$tool_params{'align'} \
= '';\n	}\n\n	print_debug_message( 'load_params', \
'End', 1 );\n}\n\n=head2 client_poll()\n\nClient-s\
ide job polling.\n\n  &client_poll($job_id);\n\n=c\
ut\n\nsub client_poll {\n	print_debug_message( 'cl\
ient_poll', 'Begin', 1 );\n	my $jobid  = shift;\n	\
my $status = 'PENDING';\n\n	my $errorCount = 0;\n	\
while ($status eq 'RUNNING'\n		|| $status eq 'PEND\
ING'\n		|| ( $status eq 'ERROR' && $errorCount < 2\
 ) )\n	{\n		$status = rest_get_status($jobid);\n		\
print STDERR \"$status\\n\" if ( $outputLevel > 0 \
);\n		if ( $status eq 'ERROR' ) {\n			$errorCount+\
+;\n		}\n		elsif ( $errorCount > 0 ) {\n			$errorC\
ount--;\n		}\n		if (   $status eq 'RUNNING'\n			||\
 $status eq 'PENDING'\n			|| $status eq 'ERROR' )\\
n		{\n\n			# Wait before polling again.\n			sleep \
$checkInterval;\n		}\n	}\n	print_debug_message( 'c\
lient_poll', 'End', 1 );\n	return $status;\n}\n\n=\
head2 get_results()\n\nGet the results for a job i\
dentifier.\n\n  &get_results($job_id);\n\n=cut\n\n\
sub get_results {\n	print_debug_message( 'get_resu\
lts', 'Begin', 1 );\n	my $jobid = shift;\n	print_d\
ebug_message( 'get_results', 'jobid: ' . $jobid, 1\
 );\n\n	# Verbose\n	if ( $outputLevel > 1 ) {\n		p\
rint 'Getting results for job ', $jobid, \"\\n\";\\
n	}\n\n	# Check status, and wait if not finished\n\
	client_poll($jobid);\n\n	# Use JobId if output fi\
le name is not defined\n	unless ( defined( $params\
{'outfile'} ) ) {\n		$params{'outfile'} = $jobid;\\
n	}\n\n	# Get list of data types\n	my (@resultType\
s) = rest_get_result_types($jobid);\n\n	# Get the \
data and write it to a file\n	if ( defined( $param\
s{'outformat'} ) ) {    # Specified data type\n		m\
y $selResultType;\n		foreach my $resultType (@resu\
ltTypes) {\n			if ( $resultType->{'identifier'} eq\
 $params{'outformat'} ) {\n				$selResultType = $r\
esultType;\n			}\n		}\n		if ( defined($selResultTy\
pe) ) {\n			my $result =\n			  rest_get_result( $j\
obid, $selResultType->{'identifier'} );\n			if ( $\
params{'outfile'} eq '-' ) {\n				write_file( $par\
ams{'outfile'}, $result );\n			}\n			else {\n				w\
rite_file(\n					$params{'outfile'} . '.'\n					  \
. $selResultType->{'identifier'} . '.'\n					  . $\
selResultType->{'fileSuffix'},\n					$result\n				\
);\n			}\n		}\n		else {\n			die 'Error: unknown re\
sult format \"' . $params{'outformat'} . '\"';\n		\
}\n	}\n	else {    # Data types available\n		      \
# Write a file for each output type\n		for my $res\
ultType (@resultTypes) {\n			if ( $outputLevel > 1\
 ) {\n				print STDERR 'Getting ', $resultType->{'\
identifier'}, \"\\n\";\n			}\n			my $result = rest\
_get_result( $jobid, $resultType->{'identifier'} )\
;\n			if ( $params{'outfile'} eq '-' ) {\n				writ\
e_file( $params{'outfile'}, $result );\n			}\n			e\
lse {\n				write_file(\n					$params{'outfile'} . \
'.'\n					  . $resultType->{'identifier'} . '.'\n	\
				  . $resultType->{'fileSuffix'},\n					$result\
\n				);\n			}\n		}\n	}\n	print_debug_message( 'ge\
t_results', 'End', 1 );\n}\n\n=head2 read_file()\n\
\nRead a file into a scalar. The special filename \
'-' can be used to read from \nstandard input (STD\
IN).\n\n  my $data = &read_file($filename);\n\n=cu\
t\n\nsub read_file {\n	print_debug_message( 'read_\
file', 'Begin', 1 );\n	my $filename = shift;\n	pri\
nt_debug_message( 'read_file', 'filename: ' . $fil\
ename, 2 );\n	my ( $content, $buffer );\n	if ( $fi\
lename eq '-' ) {\n		while ( sysread( STDIN, $buff\
er, 1024 ) ) {\n			$content .= $buffer;\n		}\n	}\n\
	else {    # File\n		open( my $FILE, '<', $filenam\
e )\n		  or die \"Error: unable to open input file\
 $filename ($!)\";\n		while ( sysread( $FILE, $buf\
fer, 1024 ) ) {\n			$content .= $buffer;\n		}\n		c\
lose($FILE);\n	}\n	print_debug_message( 'read_file\
', 'End', 1 );\n	return $content;\n}\n\n=head2 wri\
te_file()\n\nWrite data to a file. The special fil\
ename '-' can be used to write to \nstandard outpu\
t (STDOUT).\n\n  &write_file($filename, $data);\n\\
n=cut\n\nsub write_file {\n	print_debug_message( '\
write_file', 'Begin', 1 );\n	my ( $filename, $data\
 ) = @_;\n	print_debug_message( 'write_file', 'fil\
ename: ' . $filename, 2 );\n	if ( $outputLevel > 0\
 ) {\n		print STDERR 'Creating result file: ' . $f\
ilename . \"\\n\";\n	}\n	if ( $filename eq '-' ) {\
\n		print STDOUT $data;\n	}\n	else {\n		open( my $\
FILE, '>', $filename )\n		  or die \"Error: unable\
 to open output file $filename ($!)\";\n		syswrite\
( $FILE, $data );\n		close($FILE);\n	}\n	print_deb\
ug_message( 'write_file', 'End', 1 );\n}\n\n=head2\
 usage()\n\nPrint program usage message.\n\n  &usa\
ge();\n\n=cut\n\nsub usage {\n	print STDERR <<EOF\\
nWU-BLAST\n========\n   \nRapid sequence database \
search programs utilizing the BLAST algorithm\n   \
 \n[Required]\n\n  -p, --program      : str  : BLA\
ST program to use, see --paramDetail program\n  -D\
, --database     : str  : database(s) to search, s\
pace separated. See\n                             \
 --paramDetail database\n      --stype        : st\
r  : query sequence type, see --paramDetail stype\\
n  seqFile            : file : query sequence (\"-\
\" for STDIN, \\@filename for\n                   \
           identifier list file)\n\n[Optional]\n\n\
  -m, --matrix       : str  : scoring matrix, see \
--paramDetail matrix\n  -e, --exp          : real \
: 0<E<= 1000. Statistical significance threshold \\
n                              for reporting datab\
ase sequence matches.\n  -e, --viewfilter   :     \
 : display the filtered query sequence\n  -f, --fi\
lter       : str  : filter the query sequence for \
low complexity \n                              reg\
ions, see --paramDetail filter\n  -A, --align     \
   : int  : pairwise alignment format, see --param\
Detail align\n  -s, --scores       : int  : number\
 of scores to be reported\n  -b, --alignments   : \
int  : number of alignments to report\n  -S, --sen\
sitivity  : str  : sensitivity of the search, \n  \
                            see --paramDetail sens\
itivity\n  -t, --sort	     : str  : sort order for\
 hits, see --paramDetail sort\n  -T, --stats      \
  : str  : statistical model, see --paramDetail st\
ats\n  -d, --strand       : str  : DNA strand to s\
earch with,\n                              see --p\
aramDetail strand\n  -c, --topcombon    : str  : c\
onsistent sets of HSPs\n      --multifasta   :    \
  : treat input as a set of fasta formatted sequen\
ces\n\n[General]\n\n  -h, --help         :      : \
prints this help text\n      --async        :     \
 : forces to make an asynchronous query\n      --e\
mail        : str  : e-mail address\n      --title\
        : str  : title for job\n      --status    \
   :      : get job status\n      --resultTypes  :\
      : get available result types for job\n      \
--polljob      :      : poll for the status of a j\
ob\n      --jobid        : str  : jobid that was r\
eturned when an asynchronous job \n               \
               was submitted.\n      --outfile    \
  : str  : file name for results (default is jobid\
;\n                              \"-\" for STDOUT)\
\n      --outformat    : str  : result format to r\
etrieve\n      --params       :      : list input \
parameters\n      --paramDetail  : str  : display \
details for input parameter\n      --quiet        \
:      : decrease output\n      --verbose      :  \
    : increase output\n   \nSynchronous job:\n\n  \
The results/errors are returned as soon as the job\
 is finished.\n  Usage: $scriptName --email <your\\
\@email> [options...] seqFile\n  Returns: results \
as an attachment\n\nAsynchronous job:\n\n  Use thi\
s if you want to retrieve the results at a later t\
ime. The results \n  are stored for up to 24 hours\
. 	\n  Usage: $scriptName --async --email <your\\@\
email> [options...] seqFile\n  Returns: jobid\n\n \
 Use the jobid to query for the status of the job.\
 If the job is finished, \n  it also returns the r\
esults/errors.\n  Usage: $scriptName --polljob --j\
obid <jobId> [--outfile string]\n  Returns: string\
 indicating the status of the job and if applicabl\
e, results \n  as an attachment.\n\nFurther inform\
ation:\n\n  http://www.ebi.ac.uk/Tools/webservices\
/services/sss/wu_blast_rest\n  http://www.ebi.ac.u\
k/Tools/webservices/tutorials/perl\n\nSupport/Feed\
back:\n\n  http://www.ebi.ac.uk/support/\nEOF\n}\n\
\n=head1 FEEDBACK/SUPPORT\n\nPlease contact us at \
L<http://www.ebi.ac.uk/support/> if you have any \\
nfeedback, suggestions or issues with the service \
or this client.\n\n=cut\n","\n\n\nmy $PROBTRESH = \
0.3;# base pairs below this prob threshold will be\
 ignored\nmy $WEIGHT = 100.0; # float!!\nmy $NUCAL\
PH = \"ACGTUNRYMKSWHBVD\";\nuse vars qw($NUCALPH $\
WEIGHT);\n\nmy $myname = basename($0);\n\nuse stri\
ct;\nuse warnings;\n\nuse File::Basename;\nuse Get\
opt::Long;\nuse File::Glob ':glob';\nuse File::Spe\
c;\nuse File::Temp qw/ tempfile tempdir /;\n\n\n\n\
\nsub tcoffeelib_header($;$)\n{\n    my ($nseq, $f\
d) = @_;\n    if (! defined($fd)) {\n        $fd =\
 *STDOUT;\n    }\n    printf $fd \"! TC_LIB_FORMAT\
_01\\n\";\n    printf $fd \"%d\\n\", $nseq;\n}\n\n\
\nsub tcoffeelib_header_addseq($$;$)\n{\n    my ($\
id, $seq, $fd) = @_;\n    if (! defined($fd)) {\n \
       $fd = *STDOUT;\n    }\n    printf $fd \"%s \
%d %s\\n\", $id, length($seq), $seq;\n}\n\n\nsub t\
coffeelib_comment($;$)\n{\n    my ($comment, $fd) \
= @_;\n    if (! defined($fd)) {\n        $fd = *S\
TDOUT;\n    }\n    printf $fd \"!\" . $comment . \\
"\\n\";\n}\n\n\nsub tcoffeelib_struct($$$;$)\n{\n \
   my ($nseq, $len, $bpm, $fd) = @_;\n\n    if (! \
defined($fd)) {\n        $fd = *STDOUT;\n    }\n\n\
    # output basepair indices with fixed weight\n \
   printf $fd \"#%d %d\\n\", $nseq, $nseq;\n    # \
output basepairs (only once) and with unit-offset\\
n    for (my $i=0; $i<$len; $i++) {\n        for (\
my $j=$i+1; $j<$len; $j++) {\n            if (! de\
fined($bpm->[$i][$j])) {\n                print ST\
DERR \"ERROR: \\$bpm->[$i][$j] undefined\\n\";\n  \
          }\n            if ($bpm->[$i][$j]>0) {\n\
                print $fd $i+1;\n                p\
rint $fd \" \";\n                print $fd $j+1;\n\
                print $fd \" \" . $bpm->[$i][$j] .\
 \"\\n\";\n            }\n        }\n    }\n}\n\n\\
nsub tcoffeelib_footer(;$)\n{\n    my ($fd) = @_;\\
n    if (! defined($fd)) {\n        $fd = *STDOUT;\
\n    }\n    print $fd \"! SEQ_1_TO_N\\n\";\n}\n\n\
\n    \nsub plfold($$$)\n{    \n    my ($id, $seq,\
 $probtresh) = @_;\n    my (@struct);# return\n   \
 my ($templ, $fhtmp, $fnametmp, $cmd, $ctr, $windo\
w_size);\n    our $ntemp++;\n    \n    $templ = $m\
yname . \".pid-\" . $$ .$ntemp .\".XXXXXX\";\n    \
($fhtmp, $fnametmp) = tempfile($templ, UNLINK => 1\
); \n    print $fhtmp \">$id\\n$seq\\n\";\n\n    #\
 --- init basepair array\n    #\n    for (my $i=0;\
 $i<length($seq); $i++) {\n        for (my $j=$i+1\
; $j<length($seq); $j++) {\n            $struct[$i\
][$j]=0;\n        }\n    }\n\n\n    # --- call rna\
plfold and drop a readme\n    #\n    $window_size=\
(length($seq)<70)?length($seq):70;\n    $cmd = \"R\
NAplfold -W $window_size < $fnametmp >/dev/null\";\
\n    system($cmd);\n    \n    if ($? != 0) {\n   \
     printf STDERR \"ERROR: RNAplfold ($cmd) exite\
d with error status %d\\n\", $? >> 8;\n        ret\
urn;\n    }\n    #unlink($fnametmp);\n    my $fps \
= sprintf(\"%s_dp.ps\", $id); # check long name\n \
   \n    if (! -s $fps) {\n      {\n\n	$fps = spri\
ntf(\"%s_dp.ps\", substr($id,0,12)); # check short\
 name\n 	if (! -s $fps)\n	  {\n	    die(\"couldn't\
 find expected file $fps\\n\");\n	    return;\n	  \
}\n      }\n    }\n\n    \n    # --- read base pai\
rs from created postscript\n    #\n    open(FH, $f\
ps);\n    while (my $line = <FH>) {\n        my ($\
nti, $ntj, $prob);\n        chomp($line);        \\
n        # line: bp bp sqrt-prob ubox\n        my \
@match = ($line =~ m/^([0-9]+) +([0-9]+) +([0-9\\.\
]+) +ubox$/);\n        if (scalar(@match)) {\n    \
        $nti=$1;\n            $ntj=$2;\n          \
  $prob=$3*$3;# prob stored as square root\n\n    \
        if ($prob>$probtresh) {\n                #\
printf STDERR \"\\$struct[$nti][$ntj] sqrtprob=$3 \
prob=$prob > $probtresh\\n\";\n                $st\
ruct[$nti-1][$ntj-1] = $WEIGHT\n            }\n   \
         # store with zero-offset\n        }\n    \
}\n    close(FH);\n\n    # remove or gzi postscrip\
t\n    #\n    unlink($fps);\n    #\n    # or gzip\\
n    #$cmd = \"gzip -qf $fps\";\n    #system($cmd)\
;\n    #if ($? != 0) {\n    #    printf STDERR \"E\
RROR: gzip ($cmd) exited with error status %d\\n\"\
, $? >> 8;\n    #}\n\n    return \\@struct;\n}\n\n\
\n\n\n\nsub rnaseqfmt($)\n{\n    my ($seq) = @_;\n\
    # remove gaps\n    $seq =~ s/-//g;\n    # uppe\
rcase RNA\n    $seq = uc($seq);\n    # T -> U\n   \
 $seq =~ s/T/U/g;\n    # check for invalid charate\
rs\n    $_ = $seq;\n    s/[^$NUCALPH]//g;\n    ret\
urn $_;\n}\n\n\n\n\nsub usage(;$)\n{    \n    my (\
$errmsg) = @_;\n    if ($errmsg) {\n        print \
STDERR \"ERROR: $errmsg\\n\";\n    }\n    print ST\
DERR << \"EOF\";\n$myname:\n Creates a T-Coffee RN\
A structure library from RNAplfold prediction.\n S\
ee FIXME:citation\nUsage:\n $myname -in seq_file -\
out tcoffee_lib\nEOF\n    exit(1);\n}\n\nsub read_\
fasta_seq \n  {\n    my $f=$_[0];\n    my %hseq;\n\
    my (@seq, @com, @name);\n    my ($a, $s,$nseq)\
;\n\n    open (F, $f);\n    while (<F>)\n      {\n\
	$s.=$_;\n      }\n    close (F);\n\n    \n    @na\
me=($s=~/>(\\S*).*\\n[^>]*/g);\n    \n    @seq =($\
s=~/>.*.*\\n([^>]*)/g);\n    @com =($s=~/>(\\S*)(.\
*)\\n([^>]*)/g);\n\n\n    $nseq=$#name+1;\n  \n   \
 for ($a=0; $a<$nseq; $a++)\n      {\n	my $n=$name\
[$a];\n	my $s;\n	$hseq{$n}{name}=$n;\n	$s=$seq[$a]\
;$s=~s/\\s//g;\n	\n	$hseq{$n}{seq}=$s;\n	$hseq{$n}\
{com}=$com[$a];\n      }\n    return %hseq;\n  }\n\
\n\n\n\n\n\n\nmy $fmsq = \"\";\nmy $flib = \"\";\n\
my %OPTS;\nmy %seq;\nmy ($id, $nseq, $i);\nmy @nl;\
\n\nGetOptions(\"in=s\" => \\$fmsq, \"out=s\" => \\
\$flib);\n\nif (! -s $fmsq) {\n    usage(\"empty o\
r non-existant file \\\"$fmsq\\\"\")\n}\nif (lengt\
h($flib)==0) {\n    usage(\"empty out-filename\")\\
n}\n\n\n\n\n\n\n%seq=read_fasta_seq($fmsq);\n\n\n@\
nl=keys(%seq);\n\n$nseq=$#nl+1;\nopen FD_LIB, \">$\
flib\" or die \"can't open $flib!\";\ntcoffeelib_h\
eader($nseq, *FD_LIB);\nforeach $id (keys (%seq))\\
n  {\n    my ($seq, $fmtseq);\n    \n    $seq = $s\
eq{$id}{seq};\n    \n    $fmtseq = rnaseqfmt($seq)\
;# check here, formatting for folding important la\
ter\n    if (length($seq)!=length($fmtseq)) {\n   \
     print STDERR \"ERROR: invalid sequence $id is\
 not an RNA sequence. read seq is: $seq\\n\";\n   \
     exit\n      }\n   \n    tcoffeelib_header_add\
seq($id, uc($seq), *FD_LIB);\n  }\ntcoffeelib_comm\
ent(\"generated by $myname on \" . localtime(), *F\
D_LIB);\n\n\n\n$i=0;\nforeach $id (keys (%seq))\n \
 {\n    my ($cleanid, $seq, $bpm);\n    $seq=$seq{\
$id}{seq};\n    $cleanid = $id;\n    $cleanid =~ s\
,[/ ],_,g;# needed for rnaplfold\n    $seq = rnase\
qfmt($seq);\n    \n    $bpm = plfold($cleanid, rna\
seqfmt($seq), $PROBTRESH);       \n    \n    tcoff\
eelib_struct($i+1, length($seq), $bpm, *FD_LIB);\n\
    $i++;\n}\n\n\ntcoffeelib_footer(*FD_LIB);\nclo\
se FD_LIB;\nexit (0);\n\n","\n\n\n\n\n$cmd=join ' \
', @ARGV;\nif ($cmd=~/-infile=(\\S+)/){ $seqfile=$\
1;}\nif ($cmd=~/-outfile=(\\S+)/){ $libfile=$1;}\n\
\n\n\n%s=read_fasta_seq ($seqfile);\n\nopen (F, \"\
>$libfile\");\nforeach $name (keys (%s))\n  {\n   \
 my $tclib=\"$name.RNAplfold_tclib\";\n    print (\
F \">$name _F_ $tclib\\n\");\n    seq2RNAplfold2tc\
lib ($name, $s{$name}{seq}, $tclib);\n  }\nclose (\
F);\nexit (EXIT_SUCCESS);\n\nsub seq2RNAplfold2tcl\
ib\n  {\n    my ($name, $seq, $tclib)=@_;\n    my \
($tmp);\n    $n++;\n    $tmp=\"tmp4seq2RNAplfold_t\
clib.$$.$n.pep\";\n    open (RF, \">$tmp\");\n    \
print (RF \">$name\\n$seq\\n\");\n    close (RF);\\
n    \n    system \"t_coffee -other_pg RNAplfold2t\
clib.pl -in=$tmp -out=$tclib\";\n    \n    unlink \
($tmp);\n    return $tclib;\n  }\n    \n    \nsub \
read_fasta_seq \n  {\n    my $f=@_[0];\n    my %hs\
eq;\n    my (@seq, @com, @name);\n    my ($a, $s,$\
nseq);\n\n    open (F, $f);\n    while (<F>)\n    \
  {\n	$s.=$_;\n      }\n    close (F);\n\n    \n  \
  @name=($s=~/>(\\S*).*\\n[^>]*/g);\n    \n    @se\
q =($s=~/>.*.*\\n([^>]*)/g);\n    @com =($s=~/>\\S\
*(.*)\\n([^>]*)/g);\n\n    \n    $nseq=$#name+1;\n\
    \n    for ($a=0; $a<$nseq; $a++)\n      {\n	my\
 $n=$name[$a];\n	$hseq{$n}{name}=$n;\n	$hseq{$n}{s\
eq}=$seq[$a];\n	$hseq{$n}{com}=$com[$a];\n      }\\
n    return %hseq;\n  }\n","use Getopt::Long;\nuse\
 File::Path;\nuse Env;\nuse FileHandle;\nuse Cwd;\\
nuse Sys::Hostname;\nour $PIDCHILD;\nour $ERROR_DO\
NE;\nour @TMPFILE_LIST;\nour $EXIT_FAILURE=1;\nour\
 $EXIT_SUCCESS=0;\n\nour $REFDIR=getcwd;\nour $EXI\
T_SUCCESS=0;\nour $EXIT_FAILURE=1;\n\nour $PROGRAM\
=\"tc_generic_method.pl\";\nour $CL=$PROGRAM;\n\no\
ur $CLEAN_EXIT_STARTED;\nour $debug_lock=$ENV{\"DE\
BUG_LOCK\"};\nour $LOCKDIR=$ENV{\"LOCKDIR_4_TCOFFE\
E\"};\nif (!$LOCKDIR){$LOCKDIR=getcwd();}\nour $ER\
RORDIR=$ENV{\"ERRORDIR_4_TCOFFEE\"};\nour $ERRORFI\
LE=$ENV{\"ERRORFILE_4_TCOFFEE\"};\n&set_lock ($$);\
\nif (isshellpid(getppid())){lock4tc(getppid(), \"\
LLOCK\", \"LSET\", \"$$\\n\");}\n      \nour $prin\
t;\nmy ($fmsq1, $fmsq2, $output, $outfile, $arch, \
$psv, $hmmtop_home, $trim, $cov, $sample, $mode, $\
gor_home, $gor_seq, $gor_obs);\n\nGetOptions(\"-in\
=s\" => \\$fmsq1,\"-output=s\" =>\\$output ,\"-out\
=s\" => \\$outfile, \"-arch=s\" => \\$arch,\"-psv=\
s\" => \\$psv, \"-hmmtop_home=s\", \\$hmmtop_home,\
\"-trim=s\" =>\\$trim ,\"-print=s\" =>\\$print,\"-\
cov=s\" =>\\$cov , \"-sample=s\" =>\\$sample, \"-m\
ode=s\" =>\\$mode, \"-gor_home=s\"=>\\$gor_home, \\
"-gor_seq=s\"=>\\$gor_seq,\"-gor_obs=s\"=>\\$gor_o\
bs);\n\n\nif (!$mode){$mode = \"hmmtop\"}\nelsif (\
$mode eq \"hmmtop\"){;}\nelsif ($mode eq \"gor\"){\
;}\nelse {myexit(flush_error (\"-mode=$mode is unk\
nown\"));}\n\n\nour $HOME=$ENV{\"HOME\"};\nour $MC\
OFFEE=($ENV{\"MCOFFEE_4_TCOFFEE\"})?$ENV{\"MCOFFEE\
_4_TCOFFEE\"}:\"$HOME/.t_coffee/mcoffee\";\n\nif (\
$mode eq \"hmmtop\")\n  {\n    check_configuration\
 (\"hmmtop\");\n    if (-e $arch){$ENV{'HMMTOP_ARC\
H'}=$arch;}\n    elsif (-e $ENV{HMMTOP_ARCH}){$arc\
h=$ENV{HMMTOP_ARCH};}\n    elsif (-e \"$MCOFFEE/hm\
mtop.arch\"){$arch=$ENV{'HMMTOP_ARCH'}=\"$MCOFFEE/\
hmmtop.arch\";}\n    elsif (-e \"$hmmtop_home/hmmt\
op.arc\"){$arch=$ENV{'HMMTOP_ARCH'}=\"$hmmtop_home\
/hmmtop.arc\";}\n    else {myexit(flush_error ( \"\
Could not find ARCH file for hmmtop\"));}\n    \n \
   \n    if (-e $psv){$ENV{'HMMTOP_PSV'}=$psv;}\n \
   elsif (-e $ENV{HMMTOP_PSV}){$psv=$ENV{HMMTOP_PS\
V};}\n    elsif (-e \"$MCOFFEE/hmmtop.psv\"){$psv=\
$ENV{'HMMTOP_PSV'}=\"$MCOFFEE/hmmtop.psv\";}\n    \
elsif (-e \"$hmmtop_home/hmmtop.psv\"){$psv=$ENV{'\
HMMTOP_PSV'}=\"$hmmtop_home/hmmtop.psv\";}\n    el\
se {myexit(flush_error ( \"Could not find PSV file\
 for hmmtop\"));}\n  }\nelsif ($mode eq \"gor\")\n\
  {\n    our $GOR_SEQ;\n    our $GOR_OBS;\n    \n \
   check_configuration (\"gorIV\");\n    if (-e $g\
or_seq){$GOR_SEQ=$gor_seq;}\n    elsif (-e $ENV{GO\
R_SEQ}){$GOR_SEQ=$ENV{GOR_SEQ};}\n    elsif (-e \"\
$MCOFFEE/New_KS.267.seq\"){$GOR_SEQ=\"$MCOFFEE/New\
_KS.267.seq\";}\n    elsif (-e \"$gor_home/New_KS.\
267.seq\"){$GOR_SEQ=\"$gor_home/New_KS.267.seq\";}\
\n    else {myexit(flush_error ( \"Could not find \
SEQ file for gor\"));}\n\n    if (-e $gor_obs){$GO\
R_OBS=$gor_obs;}\n    elsif (-e $ENV{GOR_OBS}){$GO\
R_OBS=$ENV{GOR_OBS};}\n    elsif (-e \"$MCOFFEE/Ne\
w_KS.267.obs\"){$GOR_OBS=\"$MCOFFEE/New_KS.267.obs\
\";}\n    elsif (-e \"$gor_home/New_KS.267.obs\"){\
$GOR_OBS=\"$gor_home/New_KS.267.obs\";}\n    else \
{myexit(flush_error ( \"Could not find OBS file fo\
r gor\"));}\n  }\n\n\nif ( ! -e $fmsq1){myexit(flu\
sh_error (\"Could Not Read Input file $fmsq1\"));}\
\n\n\nmy $fmsq2=vtmpnam();\nmy $fmsq3=vtmpnam();\n\
my $tmpfile=vtmpnam();\nmy $predfile=vtmpnam();\n\\
nif ($trim){$trim_action=\" +trim _aln_%%$trim\\_K\
1 \";}\nif ($cov) {$cov_action= \" +sim_filter _al\
n_c$cov \";}\n&safe_system(\"t_coffee -other_pg se\
q_reformat -in $fmsq1 -action +convert 'BOUJXZ-' $\
cov_action $trim_action -output fasta_aln -out $fm\
sq2\");\nmy (%pred, %seq, %predA);\n\n\n%seq=read_\
fasta_seq($fmsq2);\n%seq=fasta2sample(\\%seq, $sam\
ple);\n\nif (1==2 && $mode eq \"hmmtop\" && $outpu\
t eq \"cons\")\n  {\n    fasta2hmmtop_cons($outfil\
e,\\%seq);\n  }\nelse\n  {\n    %pred=fasta2pred(\\
\%seq, $mode);\n    %predA=pred2aln (\\%pred, \\%s\
eq);\n    \n    \n    if (!$output || $output eq \\
"prediction\"){output_fasta_seq (\\%predA, $outfil\
e);}\n    elsif ($output eq \"color_html\"){pred2c\
olor (\\%pred,\\%seq, $outfile);}\n    elsif ($out\
put eq \"cons\"){pred2cons($outfile,\\%predA);}\n \
   else {flush_error (\"$output is an unknown outp\
ut mode\");}\n  }\n\nsub fasta2sample\n  {\n    my\
 $SR=shift;\n    my $it=shift;\n    my %S=%$SR;\n \
   \n    my $seq=index2seq_name (\\%S, 1);\n    my\
 $l=length($S{$seq}{seq});\n    my @sl=keys(%S);\n\
    my $nseq=$#sl+1;\n    my $index=$nseq;\n  \n  \
  if (!$sample) {return %S;}\n    for (my $a=0; $a\
<$it; $a++)\n      {\n	my $newseq=\"\";\n	my $nnam\
e=\"$seq\\_sampled_$index\";\n	for (my $p=0; $p<$l\
; $p++)\n	  {\n	    my $i=int(rand($nseq));\n	    \
\n	    my $name = $sl[$i];\n	    my $seq=$S{$name}\
{seq};\n	    my $r=substr ($seq, $p, 1);\n	    $ne\
wseq.=$r;\n	  }\n	$S{$nname}{name}=$nname;\n	$S{$n\
name}{seq}=$newseq;\n	$S{$nname}{com}=\"sampled\";\
\n	$S{$nname}{index}=++$index;\n      }\n    retur\
n %S;\n  }\n	      \nsub fasta2pred\n  {\n    my $\
s=shift;\n    my $mode=shift;\n\n    if ( $mode eq\
 \"hmmtop\"){return fasta2hmmtop_pred($s);}\n    e\
lsif ($mode eq \"gor\"){return fasta2gor_pred ($s)\
;}\n  }\nsub fasta2hmmtop_cons\n  {\n    my $outfi\
le=shift;\n    my $SR=shift;\n    \n    my $o = ne\
w FileHandle;\n    my $i = new FileHandle;\n    my\
 $tmp_in =vtmpnam();\n    my $tmp_out=vtmpnam();\n\
    my %seq=%$SR;\n    my %pred;\n    my $N=keys(%\
seq);\n    \n    output_fasta_seq (\\%seq,$tmp_in,\
 \"seq\");\n    `hmmtop -pi=mpred -if=$tmp_in -sf=\
FAS -pl 2>/dev/null >$tmp_out`;\n    open ($o, \">\
$outfile\");\n    open ($i, \"$tmp_out\");\n    wh\
ile (<$i>)\n      {\n	my $l=$_;\n	if (($l=~/>HP\\:\
\\s+(\\d+)\\s+(.*)/)){my $line=\">$2 NSEQ: $N\\n\"\
;print $o \"$line\";}\n	elsif ( ($l=~/.*pred(.*)/)\
)  {my $line=\"$1\\n\";print $o \"$line\";}\n     \
 }\n    close ($o);\n    close ($i);\n    return r\
ead_fasta_seq($tmp);\n  }\nsub fasta2hmmtop_pred\n\
  {\n    my $SR=shift;\n    my $o = new FileHandle\
;\n    my $i = new FileHandle;\n    my $tmp    =vt\
mpnam();\n    my $tmp_in =vtmpnam();\n    my $tmp_\
out=vtmpnam();\n    my %seq=%$SR;\n    my %pred;\n\
    \n\n    output_fasta_seq (\\%seq,$tmp_in, \"se\
q\");\n    `hmmtop -if=$tmp_in -sf=FAS -pl 2>/dev/\
null >$tmp_out`;\n    open ($o, \">$tmp\");\n    o\
pen ($i, \"$tmp_out\");\n    while (<$i>)\n      {\
\n	my $l=$_;\n	if (($l=~/>HP\\:\\s+(\\d+)\\s+(.*)/\
)){my $line=\">$2\\n\";print $o \"$line\";}\n	elsi\
f ( ($l=~/.*pred(.*)/))  {my $line=\"$1\\n\";print\
 $o \"$line\";}\n      }\n    close ($o);\n    clo\
se ($i);\n    return read_fasta_seq($tmp);\n  }\n \
   \n	\n	\n	    \n	\n	\n\n	\nsub fasta2gor_pred\n \
 {\n    my $SR=shift;\n    my $o = new FileHandle;\
\n    my $i = new FileHandle;\n    my $tmp    =vtm\
pnam();\n    my $tmp_in =vtmpnam();\n    my $tmp_o\
ut=vtmpnam();\n    my %seq=%$SR;\n    my %pred;\n \
   \n\n    output_fasta_seq (\\%seq,$tmp_in, \"seq\
\");\n    `gorIV -prd $tmp_in -seq $GOR_SEQ -obs $\
GOR_OBS >$tmp_out`;\n    open ($o, \">$tmp\");\n  \
  open ($i, \"$tmp_out\");\n    while (<$i>)\n    \
  {\n	my $l=$_;\n\n	\n	if ( $l=~/>/){print $o \"$l\
\";}\n	elsif ( $l=~/Predicted Sec. Struct./){$l=~s\
/Predicted Sec. Struct\\.//;print $o \"$l\";}\n   \
   }\n    close ($o);\n    close ($i);\n    return\
 read_fasta_seq($tmp);\n  }\n			\n			     \nsub in\
dex2seq_name\n  {\n    \n    my $SR=shift;\n    my\
 $index=shift;\n    \n    \n    my %S=%$SR;\n    \\
n    foreach my $s (%S)\n      {\n	if ( $S{$s}{ind\
ex}==$index){return $s;}\n      }\n    return \"\"\
;\n  }\n\nsub pred2cons\n  {\n    my $outfile=shif\
t;\n    my $predR=shift;\n    my $seq=shift;\n    \
my %P=%$predR;\n    my %C;\n    my ($s,@r,$nseq);\\
n    my $f= new FileHandle;\n\n    open ($f, \">$o\
utfile\");\n\n    if (!$seq){$seq=index2seq_name(\\
\%P,1);}\n    foreach my $s (keys(%P))\n      {\n	\
$nseq++;\n	$string= $P{$s}{seq};\n	$string = uc $s\
tring;\n	my @r=split (//,$string);\n	for (my $a=0;\
 $a<=$#r; $a++)\n	  {\n	    if (($r[$a]=~/[OHICE]/\
)){$C{$a}{$r[$a]}++;}\n	  }\n      }\n    @l=keys(\
%C);\n    \n    \n    $s=$P{$seq}{seq};\n    print\
 $f \">$seq pred based on $nseq\\n\";\n    @r=spli\
t (//,$s);\n    \n    for (my $x=0; $x<=$#r; $x++)\
\n      {\n	if ($r[$x] ne \"-\")\n	  {\n	    my $h\
=$C{$x}{H};\n	    my $i=$C{$x}{I};\n	    my $o=$C{\
$x}{O};\n	    my $c=$C{$x}{C};\n	    my $e=$C{$x}{\
E};\n	    my $l=$i+$o;\n	    \n	    if ($h>=$i && \
$h>=$o && $h>=$c && $h>=$e){$r[$x]='H';}\n	    els\
if ($i>=$o && $i>=$c && $i>=$e){$r[$x]='I';}\n	   \
 elsif ($o>=$c && $o>=$e){$r[$x]='O';}\n	    elsif\
 ($c>=$e){$r[$x]='C';}\n	    else {$r[$x]='E';}\n	\
  }\n      }\n    $j=join ('', @r);\n    print $f \
\"$j\\n\";\n    close ($f);\n    return $j;\n  }\n\
\nsub pred2aln\n  {\n    my $PR=shift;\n    my $AR\
=shift;\n    \n    my $f=new FileHandle;\n    my %\
P=%$PR;\n    my %A=%$AR;\n    my %PA;\n    my $tmp\
=vtmpnam();\n    my $f= new FileHandle;\n    \n   \
 open ($f, \">$tmp\");\n    foreach my $s (sort{$A\
{$a}{index}<=>$A{$b}{index}}(keys (%A)))\n      {\\
n	my (@list, $seq, @plist, @pseq, $L, $PL, $c, $w)\
;\n	my $seq;\n	my $seq=$A{$s}{seq};\n	my $pred=$P{\
$s}{seq};\n	$seq=pred2alnS($P{$s}{seq},$A{$s}{seq}\
);\n	print $f \">$s\\n$seq\\n\";\n      }\n    clo\
se ($f);\n    return read_fasta_seq ($tmp);\n  }\n\
sub pred2alnS\n  {\n    my $pred=shift;\n    my $a\
ln= shift;\n    my ($j,$a,$b);\n    my @P=split (/\
/, $pred);\n    my @A=split (//, $aln);\n    for (\
$a=$b=0;$a<=$#A; $a++)\n      {\n	if ($A[$a] ne \"\
-\"){$A[$a]=$P[$b++];}\n      }\n    if ($b!= ($#P\
+1)){add_warning (\"Could not thread sequence: $b \
$#P\");}\n    \n    $j= join ('', @A);\n    return\
 $j;\n  }\nsub pred2color\n  {\n    my $predP=shif\
t;\n    my $alnP=shift;\n    my $out=shift;\n    m\
y $F=new FileHandle;\n    my $struc=vtmpnam();\n  \
  my $aln=vtmpnam();\n    \n\n    output_fasta_seq\
 ($alnP, $aln);\n    my %p=%$predP;\n    \n    ope\
n ($F, \">$struc\");\n    \n    \n    foreach my $\
s (keys(%p))\n      {\n	\n	print $F \">$s\\n\";\n	\
my $s=uc($p{$s}{seq});\n	\n	$s=~s/[Oo]/0/g;\n	$s=~\
s/[Ee]/0/g;\n	\n	$s=~s/[Ii]/5/g;\n	$s=~s/[Cc]/5/g;\
\n	\n	$s=~s/[Hh]/9/g;\n	\n	print $F \"$s\\n\";\n  \
    }\n    close ($F);\n    \n    \n    \n    safe\
_system ( \"t_coffee -other_pg seq_reformat -in $a\
ln -struc_in $struc -struc_in_f number_fasta -outp\
ut color_html -out $out\");\n    return;\n  }\n	  \
\n    \nsub display_fasta_seq\n  {\n    my $SR=shi\
ft;\n    my %S=%$SR;\n    \n    foreach my $s (sor\
t{$S{$a}{index}<=>$S{$b}{index}}(keys (%S)))\n    \
  {\n	print STDERR \">$s\\n$S{$s}{seq}\\n\";\n    \
  }\n    close ($f);\n  }\nsub output_fasta_seq\n \
 {\n    my $SR=shift;\n    my $outfile=shift;\n   \
 my $mode =shift;\n    my $f= new FileHandle;\n   \
 my %S=%$SR;\n    \n    \n    open ($f, \">$outfil\
e\");\n    foreach my $s (sort{$S{$a}{index}<=>$S{\
$b}{index}}(keys (%S)))\n      {\n	my $seq=$S{$s}{\
seq};\n	if ( $mode eq \"seq\"){$seq=~s/\\-//g;}\n	\
print $f \">$s\\n$seq\\n\";\n      }\n    close ($\
f);\n  }\n      \nsub read_fasta_seq \n  {\n    my\
 $f=$_[0];\n    my %hseq;\n    my (@seq, @com, @na\
me);\n    my ($a, $s,$nseq);\n    my $index;\n    \
open (F, $f);\n    while (<F>)\n      {\n	$s.=$_;\\
n      }\n    close (F);\n\n    \n    @name=($s=~/\
>(\\S*).*\\n[^>]*/g);\n    \n    @seq =($s=~/>.*.*\
\\n([^>]*)/g);\n    @com =($s=~/>.*(.*)\\n([^>]*)/\
g);\n\n\n    $nseq=$#name+1;\n    \n  \n    for ($\
a=0; $a<$nseq; $a++)\n      {\n	my $n=$name[$a];\n\
	my $s;\n	$hseq{$n}{name}=$n;\n	$s=$seq[$a];$s=~s/\
\\s//g;\n	$hseq{$n}{index}=++$index;\n	$hseq{$n}{s\
eq}=$s;\n	$hseq{$n}{com}=$com[$a];\n      }\n    r\
eturn %hseq;\n  }\n\n\nsub file2head\n      {\n	my\
 $file = shift;\n	my $size = shift;\n	my $f= new F\
ileHandle;\n	my $line;\n	open ($f,$file);\n	read (\
$f,$line, $size);\n	close ($f);\n	return $line;\n \
     }\nsub file2tail\n      {\n	my $file = shift;\
\n	my $size = shift;\n	my $f= new FileHandle;\n	my\
 $line;\n	\n	open ($f,$file);\n	seek ($f,$size*-1,\
 2);\n	read ($f,$line, $size);\n	close ($f);\n	ret\
urn $line;\n      }\n\n\nsub vtmpnam\n      {\n	my\
 $r=rand(100000);\n	my $f=\"file.$r.$$\";\n	while \
(-e $f)\n	  {\n	    $f=vtmpnam();\n	  }\n	push (@T\
MPFILE_LIST, $f);\n	return $f;\n      }\n\nsub mye\
xit\n  {\n    my $code=@_[0];\n    if ($CLEAN_EXIT\
_STARTED==1){return;}\n    else {$CLEAN_EXIT_START\
ED=1;}\n    ### ONLY BARE EXIT\n    exit ($code);\\
n  }\nsub set_error_lock\n    {\n      my $name = \
shift;\n      my $pid=$$;\n\n      \n      &lock4t\
c ($$,\"LERROR\", \"LSET\", \"$$ -- ERROR: $name $\
PROGRAM\\n\");\n      return;\n    }\nsub set_lock\
\n  {\n    my $pid=shift;\n    my $msg= shift;\n  \
  my $p=getppid();\n    &lock4tc ($pid,\"LLOCK\",\\
"LRESET\",\"$p$msg\\n\");\n  }\nsub unset_lock\n  \
 {\n     \n    my $pid=shift;\n    &lock4tc ($pid,\
\"LLOCK\",\"LRELEASE\",\"\");\n  }\nsub shift_lock\
\n  {\n    my $from=shift;\n    my $to=shift;\n   \
 my $from_type=shift;\n    my $to_type=shift;\n   \
 my $action=shift;\n    my $msg;\n    \n    if (!&\
lock4tc($from, $from_type, \"LCHECK\", \"\")){retu\
rn 0;}\n    $msg=&lock4tc ($from, $from_type, \"LR\
EAD\", \"\");\n    &lock4tc ($from, $from_type,\"L\
RELEASE\", $msg);\n    &lock4tc ($to, $to_type, $a\
ction, $msg);\n    return;\n  }\nsub isshellpid\n \
 {\n    my $p=shift;\n    if (!lock4tc ($p, \"LLOC\
K\", \"LCHECK\")){return 0;}\n    else\n      {\n	\
my $c=lock4tc($p, \"LLOCK\", \"LREAD\");\n	if ( $c\
=~/-SHELL-/){return 1;}\n      }\n    return 0;\n \
 }\nsub isrootpid\n  {\n    if(lock4tc (getppid(),\
 \"LLOCK\", \"LCHECK\")){return 0;}\n    else {ret\
urn 1;}\n  }\nsub lock4tc\n	{\n	  my ($pid,$type,$\
action,$value)=@_;\n	  my $fname;\n	  my $host=hos\
tname;\n	  \n	  if ($type eq \"LLOCK\"){$fname=\"$\
LOCKDIR/.$pid.$host.lock4tcoffee\";}\n	  elsif ( $\
type eq \"LERROR\"){ $fname=\"$LOCKDIR/.$pid.$host\
.error4tcoffee\";}\n	  elsif ( $type eq \"LWARNING\
\"){ $fname=\"$LOCKDIR/.$pid.$host.warning4tcoffee\
\";}\n	  \n	  if ($debug_lock)\n	    {\n	      pri\
nt STDERR \"\\n\\t---lock4tc(tcg): $action => $fna\
me =>$value (RD: $LOCKDIR)\\n\";\n	    }\n\n	  if \
   ($action eq \"LCHECK\") {return -e $fname;}\n	 \
 elsif ($action eq \"LREAD\"){return file2string($\
fname);}\n	  elsif ($action eq \"LSET\") {return s\
tring2file ($value, $fname, \">>\");}\n	  elsif ($\
action eq \"LRESET\") {return string2file ($value,\
 $fname, \">\");}\n	  elsif ($action eq \"LRELEASE\
\") \n	    {\n	      if ( $debug_lock)\n		{\n		  m\
y $g=new FileHandle;\n		  open ($g, \">>$fname\");\
\n		  print $g \"\\nDestroyed by $$\\n\";\n		  clo\
se ($g);\n		  safe_system (\"mv $fname $fname.old\\
");\n		}\n	      else\n		{\n		  unlink ($fname);\n\
		}\n	    }\n	  return \"\";\n	}\n	\nsub file2stri\
ng\n	{\n	  my $file=@_[0];\n	  my $f=new FileHandl\
e;\n	  my $r;\n	  open ($f, \"$file\");\n	  while \
(<$f>){$r.=$_;}\n	  close ($f);\n	  return $r;\n	}\
\nsub string2file \n    {\n    my ($s,$file,$mode)\
=@_;\n    my $f=new FileHandle;\n    \n    open ($\
f, \"$mode$file\");\n    print $f  \"$s\";\n    cl\
ose ($f);\n  }\n\nBEGIN\n    {\n      srand;\n    \
\n      $SIG{'SIGUP'}='signal_cleanup';\n      $SI\
G{'SIGINT'}='signal_cleanup';\n      $SIG{'SIGQUIT\
'}='signal_cleanup';\n      $SIG{'SIGILL'}='signal\
_cleanup';\n      $SIG{'SIGTRAP'}='signal_cleanup'\
;\n      $SIG{'SIGABRT'}='signal_cleanup';\n      \
$SIG{'SIGEMT'}='signal_cleanup';\n      $SIG{'SIGF\
PE'}='signal_cleanup';\n      \n      $SIG{'SIGKIL\
L'}='signal_cleanup';\n      $SIG{'SIGPIPE'}='sign\
al_cleanup';\n      $SIG{'SIGSTOP'}='signal_cleanu\
p';\n      $SIG{'SIGTTIN'}='signal_cleanup';\n    \
  $SIG{'SIGXFSZ'}='signal_cleanup';\n      $SIG{'S\
IGINFO'}='signal_cleanup';\n      \n      $SIG{'SI\
GBUS'}='signal_cleanup';\n      $SIG{'SIGALRM'}='s\
ignal_cleanup';\n      $SIG{'SIGTSTP'}='signal_cle\
anup';\n      $SIG{'SIGTTOU'}='signal_cleanup';\n \
     $SIG{'SIGVTALRM'}='signal_cleanup';\n      $S\
IG{'SIGUSR1'}='signal_cleanup';\n\n\n      $SIG{'S\
IGSEGV'}='signal_cleanup';\n      $SIG{'SIGTERM'}=\
'signal_cleanup';\n      $SIG{'SIGCONT'}='signal_c\
leanup';\n      $SIG{'SIGIO'}='signal_cleanup';\n \
     $SIG{'SIGPROF'}='signal_cleanup';\n      $SIG\
{'SIGUSR2'}='signal_cleanup';\n\n      $SIG{'SIGSY\
S'}='signal_cleanup';\n      $SIG{'SIGURG'}='signa\
l_cleanup';\n      $SIG{'SIGCHLD'}='signal_cleanup\
';\n      $SIG{'SIGXCPU'}='signal_cleanup';\n     \
 $SIG{'SIGWINCH'}='signal_cleanup';\n      \n     \
 $SIG{'INT'}='signal_cleanup';\n      $SIG{'TERM'}\
='signal_cleanup';\n      $SIG{'KILL'}='signal_cle\
anup';\n      $SIG{'QUIT'}='signal_cleanup';\n    \
  \n      our $debug_lock=$ENV{\"DEBUG_LOCK\"};\n \
     \n      \n      \n      \n      foreach my $a\
 (@ARGV){$CL.=\" $a\";}\n      if ( $debug_lock ){\
print STDERR \"\\n\\n\\n********** START PG: $PROG\
RAM *************\\n\";}\n      if ( $debug_lock )\
{print STDERR \"\\n\\n\\n**********(tcg) LOCKDIR: \
$LOCKDIR $$ *************\\n\";}\n      if ( $debu\
g_lock ){print STDERR \"\\n --- $$ -- $CL\\n\";}\n\
      \n	     \n      \n      \n    }\nsub flush_e\
rror\n  {\n    my $msg=shift;\n    return add_erro\
r ($EXIT_FAILURE,$$, $$,getppid(), $msg, $CL);\n  \
}\nsub add_error \n  {\n    my $code=shift;\n    m\
y $rpid=shift;\n    my $pid=shift;\n    my $ppid=s\
hift;\n    my $type=shift;\n    my $com=shift;\n  \
  \n    $ERROR_DONE=1;\n    lock4tc ($rpid, \"LERR\
OR\",\"LSET\",\"$pid -- ERROR: $type\\n\");\n    l\
ock4tc ($$, \"LERROR\",\"LSET\", \"$pid -- COM: $c\
om\\n\");\n    lock4tc ($$, \"LERROR\",\"LSET\", \\
"$pid -- STACK: $ppid -> $pid\\n\");\n   \n    ret\
urn $code;\n  }\nsub add_warning \n  {\n    my $rp\
id=shift;\n    my $pid =shift;\n    my $command=sh\
ift;\n    my $msg=\"$$ -- WARNING: $command\\n\";\\
n    print STDERR \"$msg\";\n    lock4tc ($$, \"LW\
ARNING\", \"LSET\", $msg);\n  }\n\nsub signal_clea\
nup\n  {\n    print dtderr \"\\n**** $$ (tcg) was \
killed\\n\";\n    &cleanup;\n    exit ($EXIT_FAILU\
RE);\n  }\nsub clean_dir\n  {\n    my $dir=@_[0];\\
n    if ( !-d $dir){return ;}\n    elsif (!($dir=~\
/tmp/)){return ;}#safety check 1\n    elsif (($dir\
=~/\\*/)){return ;}#safety check 2\n    else\n    \
  {\n	`rm -rf $dir`;\n      }\n    return;\n  }\ns\
ub cleanup\n  {\n    #print stderr \"\\n----tc: $$\
 Kills $PIDCHILD\\n\";\n    #kill (SIGTERM,$PIDCHI\
LD);\n    my $p=getppid();\n    $CLEAN_EXIT_STARTE\
D=1;\n    \n    \n    \n    if (&lock4tc($$,\"LERR\
OR\", \"LCHECK\", \"\"))\n      {\n	my $ppid=getpp\
id();\n	if (!$ERROR_DONE) \n	  {\n	    &lock4tc($$\
,\"LERROR\", \"LSET\", \"$$ -- STACK: $p -> $$\\n\\
");\n	    &lock4tc($$,\"LERROR\", \"LSET\", \"$$ -\
- COM: $CL\\n\");\n	  }\n      }\n    my $warning=\
&lock4tc($$, \"LWARNING\", \"LREAD\", \"\");\n    \
my $error=&lock4tc($$,  \"LERROR\", \"LREAD\", \"\\
");\n    #release error and warning lock if root\n\
    \n    if (isrootpid() && ($warning || $error) \
)\n      {\n	\n	print STDERR \"**************** Su\
mmary *************\\n$error\\n$warning\\n\";\n\n	\
&lock4tc($$,\"LERROR\",\"RELEASE\",\"\");\n	&lock4\
tc($$,\"LWARNING\",\"RELEASE\",\"\");\n      } \n \
   \n    \n    foreach my $f (@TMPFILE_LIST)\n    \
  {\n	if (-e $f){unlink ($f);} \n      }\n    fore\
ach my $d (@TMPDIR_LIST)\n      {\n	clean_dir ($d)\
;\n      }\n    #No More Lock Release\n    #&lock4\
tc($$,\"LLOCK\",\"LRELEASE\",\"\"); #release lock \
\n\n    if ( $debug_lock ){print STDERR \"\\n\\n\\\
n********** END PG: $PROGRAM ($$) *************\\n\
\";}\n    if ( $debug_lock ){print STDERR \"\\n\\n\
\\n**********(tcg) LOCKDIR: $LOCKDIR $$ **********\
***\\n\";}\n  }\nEND \n  {\n    \n    &cleanup();\\
n  }\n   \n\nsub safe_system \n{\n  my $com=shift;\
\n  my $ntry=shift;\n  my $ctry=shift;\n  my $pid;\
\n  my $status;\n  my $ppid=getppid();\n  if ($com\
 eq \"\"){return 1;}\n  \n  \n\n  if (($pid = fork\
 ()) < 0){return (-1);}\n  if ($pid == 0)\n    {\n\
      set_lock($$, \" -SHELL- $com (tcg)\");\n    \
  exec ($com);\n    }\n  else\n    {\n      lock4t\
c ($$, \"LLOCK\", \"LSET\", \"$pid\\n\");#update p\
arent\n      $PIDCHILD=$pid;\n    }\n  if ($debug_\
lock){printf STDERR \"\\n\\t .... safe_system (fas\
ta_seq2hmm)  p: $$ c: $pid COM: $com\\n\";}\n\n  w\
aitpid ($pid,WTERMSIG);\n\n  shift_lock ($pid,$$, \
\"LWARNING\",\"LWARNING\", \"LSET\");\n\n  if ($? \
== $EXIT_FAILURE || lock4tc($pid, \"LERROR\", \"LC\
HECK\", \"\"))\n    {\n      if ($ntry && $ctry <$\
ntry)\n	{\n	  add_warning ($$,$$,\"$com failed [re\
try: $ctry]\");\n	  lock4tc ($pid, \"LRELEASE\", \\
"LERROR\", \"\");\n	  return safe_system ($com, $n\
try, ++$ctry);\n	}\n      elsif ($ntry == -1)\n	{\\
n	  if (!shift_lock ($pid, $$, \"LERROR\", \"LWARN\
ING\", \"LSET\"))\n	    {\n	      add_warning ($$,\
$$,\"$com failed\");\n	    }\n	  else\n	    {\n	  \
    lock4tc ($pid, \"LRELEASE\", \"LERROR\", \"\")\
;\n	    }\n	  return $?;}\n      else\n	{\n	  if (\
!shift_lock ($pid,$$, \"LERROR\",\"LERROR\", \"LSE\
T\"))\n	    {\n	      myexit(add_error ($EXIT_FAIL\
URE,$$,$pid,getppid(), \"UNSPECIFIED system\", $co\
m));\n	    }\n	}\n    }\n  return $?;\n}\n\nsub ch\
eck_configuration \n    {\n      my @l=@_;\n      \
my $v;\n      foreach my $p (@l)\n	{\n	  \n	  if  \
 ( $p eq \"EMAIL\")\n	    { \n	      if ( !($EMAIL\
=~/@/))\n		{\n		add_warning($$,$$,\"Could Not Use \
EMAIL\");\n		myexit(add_error ($EXIT_FAILURE,$$,$$\
,getppid(),\"EMAIL\",\"$CL\"));\n	      }\n	    }\\
n	  elsif( $p eq \"INTERNET\")\n	    {\n	      if \
( !&check_internet_connection())\n		{\n		  myexit(\
add_error ($EXIT_FAILURE,$$,$$,getppid(),\"INTERNE\
T\",\"$CL\"));\n		}\n	    }\n	  elsif( $p eq \"wge\
t\")\n	    {\n	      if (!&pg_is_installed (\"wget\
\") && !&pg_is_installed (\"curl\"))\n		{\n		  mye\
xit(add_error ($EXIT_FAILURE,$$,$$,getppid(),\"PG_\
NOT_INSTALLED:wget\",\"$CL\"));\n		}\n	    }\n	  e\
lsif( !(&pg_is_installed ($p)))\n	    {\n	      my\
exit(add_error ($EXIT_FAILURE,$$,$$,getppid(),\"PG\
_NOT_INSTALLED:$p\",\"$CL\"));\n	    }\n	}\n      \
return 1;\n    }\nsub pg_is_installed\n  {\n    my\
 @ml=@_;\n    my $r, $p, $m;\n    my $supported=0;\
\n    \n    my $p=shift (@ml);\n    if ($p=~/::/)\\
n      {\n	if (safe_system (\"perl -M$p -e 1\")==$\
EXIT_SUCCESS){return 1;}\n	else {return 0;}\n     \
 }\n    else\n      {\n	$r=`which $p 2>/dev/null`;\
\n	if ($r eq \"\"){return 0;}\n	else {return 1;}\n\
      }\n  }\n\n\n\nsub check_internet_connection\\
n  {\n    my $internet;\n    my $tmp;\n    &check_\
configuration ( \"wget\"); \n    \n    $tmp=&vtmpn\
am ();\n    \n    if     (&pg_is_installed    (\"w\
get\")){`wget www.google.com -O$tmp >/dev/null 2>/\
dev/null`;}\n    elsif  (&pg_is_installed    (\"cu\
rl\")){`curl www.google.com -o$tmp >/dev/null 2>/d\
ev/null`;}\n    \n    if ( !-e $tmp || -s $tmp < 1\
0){$internet=0;}\n    else {$internet=1;}\n    if \
(-e $tmp){unlink $tmp;}\n\n    return $internet;\n\
  }\nsub check_pg_is_installed\n  {\n    my @ml=@_\
;\n    my $r=&pg_is_installed (@ml);\n    if (!$r \
&& $p=~/::/)\n      {\n	print STDERR \"\\nYou Must\
 Install the perl package $p on your system.\\nRUN\
:\\n\\tsudo perl -MCPAN -e 'install $pg'\\n\";\n  \
    }\n    elsif (!$r)\n      {\n	myexit(flush_err\
or(\"\\nProgram $p Supported but Not Installed on \
your system\"));\n      }\n    else\n      {\n	ret\
urn 1;\n      }\n  }\n\n\n\n","\n\n\n\n\nmy $FMODE\
L =\"\"; \nmy $TMPDIR = \"/tmp\";\n\n\n\n\nmy $NUC\
ALPH = \"ACGTUNRYMKSWHBVD\";\nmy $PRIMNUCALPH = \"\
ACGTUN\";\nuse vars qw($NUCALPH $PRIMNUCALPH $TMPD\
IR);\n\n\nmy $errmsg;\nuse vars qw($errmsg);\n\n\n\
\nuse Getopt::Long;\nuse Cwd;\nuse File::Basename;\
\nuse File::Temp qw/ tempfile tempdir /;\nuse File\
::Copy;\nuse File::Path;\n\n\n\nsub usage(;$)\n{\n\
    my ($errmsg) = @_;\n    my $myname = basename(\
$0);\n\n    if ($errmsg) {\n        print STDERR \\
"ERROR: $errmsg\\n\";\n    }\n\n    print STDERR <\
< \"EOF\";\n    \n$myname: align two sequences by \
means of consan\\'s sfold\nUsage:\n $myname -i fil\
e -o file -d path\nOptions:\n -i|--in : pairwise i\
nput sequence file\n -o|--out: output alignment\n \
-d|--directory containing data\n\nEOF\n}\n\nsub re\
ad_stk_aln \n  {\n    my $f=$_[0];\n    my ($seq, \
$id);\n    \n    my %hseq;\n\n    open (STK, \"$f\\
");\n    while (<STK>)\n      {\n	if ( /^#/ || /^\\
\/\\// || /^\\s*$/){;}\n	else\n	  {\n	    ($id,$se\
q)=/(\\S+)\\s+(\\S+)/;\n	    $hseq{$id}{'seq'}.=$s\
eq;\n	  }\n      }\n    close (STK);\n    return %\
hseq;\n  }\nsub read_fasta_seq \n  {\n    my $f=$_\
[0];\n    my %hseq;\n    my (@seq, @com, @name);\n\
    my ($a, $s,$nseq);\n\n    open (F, $f);\n    w\
hile (<F>)\n      {\n	$s.=$_;\n      }\n    close \
(F);\n\n    \n    @name=($s=~/>(.*).*\\n[^>]*/g);\\
n    \n    @seq =($s=~/>.*.*\\n([^>]*)/g);\n    @c\
om =($s=~/>.*(.*)\\n([^>]*)/g);\n\n    \n    $nseq\
=$#name+1;\n    \n    for ($a=0; $a<$nseq; $a++)\n\
      {\n	my $n=$name[$a];\n	$hseq{$n}{name}=$n;\n\
	$hseq{$n}{seq}=$seq[$a];\n	$hseq{$n}{com}=$com[$a\
];\n      }\n    return %hseq;\n  }\n\n\n\nsub sfo\
ld_parseoutput($$)\n{\n    my ($frawout, $foutfa) \
= @_;\n    my %haln;\n    my ($fstk, $cmd, $id);\n\
    open FOUTFA, \">$foutfa\";\n    \n    $fstk = \
$frawout . \".stk\";\n    \n    # first line of ra\
w out contains info\n    # remaining stuff is stoc\
kholm formatted\n    $cmd = \"sed -e '1d' $frawout\
\";\n    system(\"$cmd > $fstk\");\n    if ($? != \
0) {\n        $errmsg = \"command failed with exit\
 status $?.\";\n        $errmsg .=  \"Command was \
\\\"$cmd\\\"\";\n        return -1;\n    }\n\n    \
# this gives an error message. just ignore it...\n\
    %haln=read_stk_aln ( $fstk);\n    foreach $i (\
keys (%haln))\n      {\n	my $s;\n	$s=$haln{$i}{'se\
q'};\n	$s =~ s/\\./-/g;\n	print FOUTFA \">$i\\n$s\\
\n\";\n      }\n    close FOUTFA;\n    return 0;\n\
}\n\n\n\n\nsub sfold_wrapper($$$$)\n{\n    \n    m\
y ($fs1, $fs2, $fmodel, $foutfa) = @_;\n    \n\n  \
  my ($cmd, $frawout, $ferrlog, $freadme, $ftimelo\
g, $fstk);\n\n    # add  basename($fmsqin) (unknow\
n here!)\n    $frawout = \"sfold.log\";\n    $ferr\
log = \"sfold.err\";\n    $ftimelog = \"sfold.time\
\";\n    $freadme =  \"sfold.README\";\n    $fstk \
= \"sfold.stk\";\n    \n    # prepare execution...\
\n    #\n    # ./tmp is essential for dswpalign\n \
   # otherwise you'll get a segfault\n    mkdir \"\
./tmp\";\n    \n    $cmd = \"sfold -m $fmodel $fs1\
 $fs2\";\n    open(FREADME,\">$freadme\");\n    pr\
int FREADME \"$cmd\\n\"; \n    close(FREADME);\n\n\
    # and go\n    #\n    system(\"/usr/bin/time -p\
 -o $ftimelog $cmd >$frawout 2>$ferrlog\");\n    i\
f ($? != 0) {\n        $errmsg = \"command failed \
with exit status $?\";\n        $errmsg .= \"comma\
nd was \\\"$cmd\\\". See \" . getcwd . \"\\n\";\n \
       return -1;\n    }\n\n    return sfold_parse\
output($frawout, $foutfa);\n}\n\n\n\n\n\n\n\nmy ($\
help, $fmsqin, $fmsaout);\nGetOptions(\"help\"  =>\
 \\$help,\n           \"in=s\" => \\$fmsqin,\n    \
       \"out=s\" => \\$fmsaout,\n	   \"data=s\" =>\
 \\$ref_dir);\n\n\n\nif ($help) {\n    usage();\n \
   exit(0);\n}\nif (! defined($fmsqin)) {\n    usa\
ge('missing input filename');\n    exit(1);\n}\nif\
 (! defined($fmsaout)) {\n    usage('missing outpu\
t filename');\n    exit(1);\n\n}\nif (scalar(@ARGV\
)) {\n    usage('Unknown remaining args');\n    ex\
it(1);\n}\n\n$FMODEL = \"$ref_dir/mix80.mod\";\nif\
 (! -e \"$FMODEL\") {\n    die(\"couldn't find sfo\
ld grammar model file. Expected $FMODEL\\n\");\n}\\
n\n\nmy %hseq=read_fasta_seq ($fmsqin);\nmy $id;\n\
\nforeach $id (keys(%hseq))\n  {\n    push(@seq_ar\
ray, $hseq{$id});\n  }\n\nif ( scalar(@seq_array) \
!= 2 ) {\n    die(\"Need *exactly* two sequences a\
s input (pairwise alignment!).\")\n}\n\n\n\nmy ($s\
ec, $min, $hour, $mday, $mon, $year, $wday, $yday,\
 $isdst) = localtime(time);\nmy $datei = sprintf(\\
"%4d-%02d-%02d\", $year+1900, $mon+1, $mday);\nmy \
$templ = basename($0) . \".\" . $datei . \".pid-\"\
 . $$ . \".XXXXXX\";\nmy $wd = tempdir ( $templ, D\
IR => $TMPDIR);\n\ncopy($fmsqin, \"$wd/\" . basena\
me($fmsqin) . \".org\"); # for reproduction\ncopy(\
$FMODEL, \"$wd\");\nmy $fmodel = basename($FMODEL)\
;\nmy $orgwd = getcwd;\nchdir $wd;\n\n\n\nmy @seps\
eqfiles;\nforeach $id (keys(%hseq)) {\n    my ($se\
q, $orgseq, $fname, $sout);\n    $seq=$hseq{$id}{'\
seq'};\n    \n    $fname = basename($fmsqin) . \"_\
$id.fa\";\n    # replace funnies in file/id name (\
e.g. \"/\" \" \" etc)\n    $fname =~ s,[/ ],_,g;\n\
    open (PF, \">$fname\");\n    print (PF \">$id\\
\n$seq\\n\");\n    close (PF);\n\n    push(@sepseq\
files, $fname);\n}\n\nmy ($f1, $f2, $fout);\n$f1 =\
 $sepseqfiles[0];\n$f2 = $sepseqfiles[1];\n$fout =\
 $wd . basename($fmsqin) . \".out.fa\";\nif (sfold\
_wrapper($f1, $f2, $fmodel, \"$fout\") != 0) {\n  \
  printf STDERR \"ERROR: See logs in $wd\\n\";\n  \
  exit(1);\n} else {\n    chdir $orgwd;\n    copy(\
$fout, $fmsaout);\n    rmtree($wd);\n   exit(0);\n\
}\n","\nuse Env qw(HOST);\nuse Env qw(HOME);\nuse \
Env qw(USER);\n\n\n$tmp=clean_cr ($ARGV[0]);\nopen\
 (F, $tmp);\n\nwhile ( <F>)\n  {\n    my $l=$_;\n \
   if ( $l=~/^# STOCKHOLM/){$stockholm=1;}\n    el\
sif ( $stockholm && $l=~/^#/)\n      {\n	$l=~/^#(\\
\S+)\\s+(\\S+)\\s+(\\S*)/g;\n	$l=\"_stockholmhasch\
_$1\\_stockholmspace_$2 $3\\n\";\n      }\n    $fi\
le.=$l;\n  }\nclose (F);\nunlink($tmp);\n$file1=$f\
ile;\n\n$file=~s/\\#/_hash_symbol_/g;\n$file=~s/\\\
@/_arobase_symbol_/g;\n\n\n$file=~s/\\n[\\.:*\\s]+\
\\n/\\n\\n/g;\n\n$file=~s/\\n[ \\t\\r\\f]+(\\b)/\\\
n\\1/g;\n\n\n$file=~s/(\\n\\S+)(\\s+)(\\S)/\\1_bla\
nk_\\3/g;\n\n$file=~s/[ ]//g;\n$file=~s/_blank_/ /\
g;\n\n\n\n$file =~s/\\n\\s*\\n/#/g;\n\n$file.=\"#\\
";\n$file =~s/\\n/@/g;\n\n\n\n\n@blocks=split /\\#\
/, $file;\nshift (@blocks);\n@s=split /\\@/, $bloc\
ks[0];\n$nseq=$#s+1;\n\n\n\n$file=join '@', @block\
s;\n@lines=split /\\@/,$file;\n\n$c=0;\n\nforeach \
$l (@lines)\n  {\n    if (!($l=~/\\S/)){next;}\n  \
  elsif ($stockholm && ($l=~/^\\/\\// || $l=~/STOC\
KHOLM/)){next;}#get read of STOCHOLM Terminator\n \
  \n    $l=~/(\\S+)\\s+(\\S*)/g;\n    $n=$1; $s=$2\
;\n    \n    $seq[$c].=$s;\n    $name[$c]=$n;\n   \
 $c++;\n    \n    if ( $c==$nseq){$c=0;}\n    \n  \
} \n\nif ( $c!=0)\n      {\n	print STDERR \"ERROR:\
 $ARGV[0] is NOT an MSA in Clustalw format: make s\
ure there is no blank line within a block [ERROR]\\
\n\";\n	exit (EXIT_FAILURE);\n      }\n\nfor ($a=0\
; $a< $nseq; $a++)\n  {\n    $name[$a]=cleanstring\
 ($name[$a]);\n    $seq[$a]=cleanstring ($seq[$a])\
;\n    $seq[$a]=breakstring($seq[$a], 60);\n    \n\
    $line=\">$name[$a]\\n$seq[$a]\\n\";\n    \n   \
 print \"$line\";\n  }\nexit (EXIT_SUCCESS);\n\nsu\
b cleanstring\n  {\n    my $s=@_[0];\n    $s=~s/_h\
ash_symbol_/\\#/g;\n    $s=~s/_arobase_symbol_/\\@\
/g;\n    $s=~s/[ \\t]//g;\n    return $s;\n  }\nsu\
b breakstring\n  {\n    my $s=@_[0];\n    my $size\
=@_[1];\n    my @list;\n    my $n,$ns, $symbol;\n \
   \n    @list=split //,$s;\n    $n=0;$ns=\"\";\n \
   foreach $symbol (@list)\n      {\n	if ( $n==$si\
ze)\n	  {\n	    $ns.=\"\\n\";\n	    $n=0;\n	  }\n	\
$ns.=$symbol;\n	$n++;\n      }\n    return $ns;\n \
   }\n\nsub clean_cr\n  {\n    my $f=@_[0];\n    m\
y $file;\n    \n    $tmp=\"f$.$$\";\n    \n    \n \
   open (IN, $f);\n    open (OUT, \">$tmp\");\n   \
 \n    while ( <IN>)\n      {\n	$file=$_;\n	$file=\
~s/\\r\\n/\\n/g;\n	$file=~s/\\n\\r/\\n/g;\n	$file=\
~s/\\r\\r/\\n/g;\n	$file=~s/\\r/\\n/g;\n	print OUT\
 \"$file\";\n      }\n    \n    close (IN);\n    c\
lose (OUT);\n    return $tmp;\n  }\n","use Env qw(\
HOST);\nuse Env qw(HOME);\nuse Env qw(USER);\n\n\n\
$query_start=-1;\n$query_end=-1;\n\nwhile (<>)\n  \
{\n    if ( /\\/\\//){$in_aln=1;}\n    elsif ( $in\
_aln && /(\\S+)\\s+(.*)/)\n      {\n\n\n	$name=$1;\
\n	\n\n	$seq=$2;\n	$seq=~s/\\s//g;\n        $seq=~\
s/\\~/\\-/g;\n	$seq=~s/\\./\\-/g;\n	if ( $list{$n}\
{'name'} && $list{$n}{'name'} ne $name)\n	  {\n	  \
  print \"$list{$n}{'name'} Vs $name\";\n	    \n	 \
   exit (EXIT_FAILURE);\n	  }\n	else\n	  {\n	    $\
list{$n}{'name'}= $name;\n	  }\n\n	$list{$n}{'seq'\
}=$list{$n}{'seq'}.$seq;\n	\n	$nseq=++$n;\n	\n    \
  }\n    else\n      {$n=0;}\n  }\n\n\nfor ($a=0; \
$a<$nseq; $a++)\n  {\n    print \">$list{$a}{'name\
'}\\n$list{$a}{'seq'}\\n\";\n  }\n      \n","\nuse\
 Env qw(HOST);\nuse Env qw(HOME);\nuse Env qw(USER\
);\n\n                                            \
            \nuse strict;                         \
                    \nuse warnings;\nuse diagnosti\
cs;\n\nmy $in_hit_list, my $in_aln=0, my(%name_lis\
t)=(),my (%list)=(),my $n_seq=0; my $test=0;\nmy($\
j)=0, my $n=0, my $nom, my $lg_query, my %vu=();\n\
\nopen (F, \">tmp\");\n\n$/=\"\\n\";\nwhile (<>)\n\
{\n    print F $_;\n    if($_ =~ /Query=\\s*(.+?)\\
\s/i) { $nom=$1;}\n\n    if ( /Sequences producing\
 significant alignments/){$in_hit_list=1;}\n    \n\
    if ($_=~ /^pdb\\|/i) { $_=~ s/pdb\\|//g; }\n  \
  if ($_=~ /^(1_\\d+)\\s+\\d+/) { $_=~ s/$1/QUERY/\
;}\n      \n    if ( /^(\\S+).+?\\s+[\\d.]+\\s+([\\
\de.-]+)\\s+$/ && $in_hit_list)	\n    {\n	my($id)=\
$1; # \n	$id=~ s/\\|/_/g; #\n	if ($id =~ /.+_$/) {\
 chop($id) }; #\n	$name_list{$n_seq++}=$id;\n	$nam\
e_list{$n_seq-1}=~ s/.*\\|//g;     \n    }\n  \n  \
  if (/query/i) {$in_aln=1;}\n    if ( /^(\\S+)\\s\
+(\\d+)\\s+([a-zA-Z-]+)\\s+(\\d+)/ || /^(\\S+)(\\s\
+)(\\-+)(\\s+)/ && ($in_aln == 1))\n    {\n	my $na\
me=$1;\n	my $start=$2;\n	my $seq=$3;\n	my $end=$4;\
\n		\n	if ($name =~ /QUERY/i) { $lg_query=length($\
seq); }\n\n	unless ($test > $n) #m\n	{\n	    my(@s\
eqq)= split('',$seq);\n	    my($gap_missing)= scal\
ar(@seqq);\n	    \n	    while ($gap_missing != $lg\
_query)  { unshift (@seqq,\"-\"); $gap_missing= sc\
alar(@seqq); }\n	    $seq=join('',@seqq);  #m\n	}\\
n	\n	if ($name =~ /QUERY/i)\n	{\n	    $n=0; %vu=()\
; $j=0;\n	    $list{$n}{'real_name'}=\"$nom\";\n	}\
	\n	else\n	{\n	    unless (exists $vu{$name}) { ++\
$j;}	\n	    $list{$n}{'real_name'}=$name_list{$j-1\
};\n	}\n		\n	$list{$n}{'name'}=$name;\n\n	$seq=~tr\
/a-z/A-Z/;\n	$list{$n}{'seq'}=$list{$n}{'seq'};\n	\
$list{$n}{'seq'}.=$seq;\n\n	$n++;\n	$vu{$name}++;\\
n	$test++;\n   } \n    \n}\n\nmy @numero=();\n\nfo\
r (my $a=0; $a<$n; $a++) #m\n{\n    my $long=lengt\
h($list{0}{'seq'});  \n    my $long1= length($list\
{$a}{'seq'});\n  \n    while ($long1 ne $long)\n  \
  {\n	$list{$a}{'seq'}.=\"-\";\n	$long1= length ($\
list{$a}{'seq'});\n    } \n \n    push (@numero,\"\
$list{$a}{'name'} $list{$a}{'real_name'}\\n\");\n}\
\n\nmy %dejavu=();\n\n\nfor (my $i=0; $i<=$#numero\
; $i++)\n{\n    my $s=\">$list{$i}{'real_name'}\\n\
$list{$i}{'seq'}\\n\";\n    my $k=0;\n    \n    if\
 (exists $dejavu{$numero[$i]}) {next;}\n    else\n\
    {	\n	for ($j=0; $j<$n ; $j++)\n	{\n	    if (\"\
$numero[$i]\" eq \"$numero[$j]\" && $j != $i )\n	 \
   {\n		++$k;\n		$s .=\">$list{$j}{'real_name'}\\n\
$list{$j}{'seq'}\\n\";\n	    }\n	}	\n    }\n    \n\
    if ($k>0) \n    {\n	my $cons;\n	open (SOR,\">t\
empo_aln2cons\"); print SOR $s;  close SOR ;\n	ope\
n (COM,\"t_coffee -other_pg seq_reformat -in tempo\
_aln2cons -action +aln2cons +upper |\") ; \n     	\
while (<COM>)\n	{	\n	    if (/^>/) { $cons =\">$li\
st{$i}{'real_name'}\\n\"; next;}\n	    $_=~ s/\\n/\
/g;\n	    $cons .=$_;\n	}\n	close COM; unlink (\"t\
empo_aln2cons\");\n	print $cons,\"\\n\"; print F $\
cons,\"\\n\";\n    }	\n    else  { print $s;  prin\
t F $s; }\n    \n    $dejavu{$numero[$i]}++;\n} #m\
\n\nexit;\n\n\n\n\n\n\n\n\n\n\n\n","use Env;\n\n\n\
$tmp_dir=\"\";\n$init_dir=\"\";\n$program=\"tc_gen\
eric_method.pl\";\n\n$blast=@ARGV[0];\n\n$name=\"q\
uery\";$seq=\"\";\n%p=blast_xml2profile($name,$seq\
,100, 0, 0, $blast);\n&output_profile (%p);\n\n\ns\
ub output_profile\n  {\n    my (%profile)=(@_);\n \
   my ($a);\n    for ($a=0; $a<$profile{n}; $a++)\\
n      {\n	\n	print \">$profile{$a}{name} $profile\
{$a}{comment}\\n$profile{$a}{seq}\\n\";\n      }\n\
    return;\n  }\nsub file_contains \n  {\n    my \
($file, $tag, $max)=(@_);\n    my ($n);\n    $n=0;\
\n    \n    if ( !-e $file && ($file =~/$tag/)) {r\
eturn 1;}\n    elsif ( !-e $file){return 0;}\n    \
else \n      {\n	open (FC, \"$file\");\n	while ( <\
FC>)\n	  {\n	    if ( ($_=~/$tag/))\n	      {\n		c\
lose (FC);\n		return 1;\n	      }\n	    elsif ($ma\
x && $n>$max)\n	      {\n		close (FC);\n		return 0\
;\n	      }\n	    $n++;\n	  }\n      }\n    close \
(FC);\n    return 0;\n  }\n	    \n	  \nsub file2st\
ring\n  {\n    my $f=@_[0];\n    my $string, $l;\n\
    open (F,\"$f\");\n    while (<F>)\n      {\n\n\
	$l=$_;\n	#chomp ($l);\n	$string.=$l;\n      }\n  \
  close (F);\n    $string=~s/\\r\\n//g;\n    $stri\
ng=~s/\\n//g;\n    return $string;\n  }\n\n\n\nsub\
 tag2value \n  {\n    \n    my $tag=(@_[0]);\n    \
my $word=(@_[1]);\n    my $return;\n    \n    $tag\
=~/$word=\"([^\"]+)\"/;\n    $return=$1;\n    retu\
rn $return;\n  }\n      \nsub hit_tag2pdbid\n  {\n\
    my $tag=(@_[0]);\n    my $pdbid;\n       \n   \
 $tag=~/id=\"(\\S+)\"/;\n    $pdbid=$1;\n    $pdbi\
d=~s/_//;\n    return $pdbid;\n  }\nsub id2pdbid \\
n  {\n    my $id=@_[0];\n  \n    if ($id =~/pdb/)\\
n      {\n	$id=~/pdb(.*)/;\n	$id=$1;\n      }\n   \
 $id=~s/[|¦_]//g;\n    return $id;\n  }\nsub set_b\
last_type \n  {\n    my $file =@_[0];\n    if (&fi\
le_contains ($file,\"EBIApplicationResult\",100)){\
$BLAST_TYPE=\"EBI\";}\n    elsif (&file_contains (\
$file,\"NCBI_BlastOutput\",100)) {$BLAST_TYPE=\"NC\
BI\";}\n    else\n      {\n	$BLAST_TYPE=\"\";\n   \
   }\n    return $BLAST_TYPE;\n  }\nsub blast_xml2\
profile \n  {\n    my ($name,$seq,$maxid, $minid, \
$mincov, $file)=(@_);\n    my (%p, $a, $string, $n\
);\n    \n\n\n    if ($BLAST_TYPE eq \"EBI\" || &f\
ile_contains ($file,\"EBIApplicationResult\",100))\
{%p=ebi_blast_xml2profile(@_);}\n    elsif ($BLAST\
_TYPE eq \"NCBI\" || &file_contains ($file,\"NCBI_\
BlastOutput\",100)){%p=ncbi_blast_xml2profile(@_);\
}\n    else \n      {\n	print \"************ ERROR\
: Blast Returned an unknown XML Format ***********\
***********\";\n	die;\n      }\n    for ($a=0; $a<\
$p{n}; $a++)\n      {\n	my $name=$p{$a}{name};\n	$\
p{$name}{seq}=$p{$a}{seq};\n      }\n    return %p\
;\n  }\nsub ncbi_blast_xml2profile \n  {\n    my (\
$name,$seq,$maxid, $minid, $mincov, $string)=(@_);\
\n    my ($L,$l, $a,$b,$c,$d,$nhits,@identifyerL);\
\n    \n    \n    $seq=~s/[^a-zA-Z]//g;\n    $L=le\
ngth ($seq);\n    \n    %hit=&xml2tag_list ($strin\
g, \"Hit\");\n    \n    \n    for ($nhits=0,$a=0; \
$a<$hit{n}; $a++)\n      {\n	my ($ldb,$id, $identi\
ty, $expectation, $start, $end, $coverage, $r);\n	\
my (%ID,%DE,%HSP);\n	\n	$ldb=\"\";\n\n	%ID=&xml2ta\
g_list ($hit{$a}{body}, \"Hit_id\");\n	$identifyer\
=$ID{0}{body};\n	\n	%DE=&xml2tag_list ($hit{$a}{bo\
dy}, \"Hit_def\");\n	$definition=$DE{0}{body};\n	\\
n	%HSP=&xml2tag_list ($hit{$a}{body}, \"Hsp\");\n	\
for ($b=0; $b<$HSP{n}; $b++)\n	  {\n	    my (%STAR\
T,%END,%E,%I,%Q,%M);\n\n	 \n	    %START=&xml2tag_l\
ist ($HSP{$b}{body}, \"Hsp_query-from\");\n	    %H\
START=&xml2tag_list ($HSP{$b}{body}, \"Hsp_hit-fro\
m\");\n	    \n	    %LEN=  &xml2tag_list ($HSP{$b}{\
body}, \"Hsp_align-len\");\n	    %END=  &xml2tag_l\
ist ($HSP{$b}{body}, \"Hsp_query-to\");\n	    %HEN\
D=  &xml2tag_list ($HSP{$b}{body}, \"Hsp_hit-to\")\
;\n	    %E=&xml2tag_list     ($HSP{$b}{body}, \"Hs\
p_evalue\");\n	    %I=&xml2tag_list     ($HSP{$b}{\
body}, \"Hsp_identity\");\n	    %Q=&xml2tag_list  \
   ($HSP{$b}{body}, \"Hsp_qseq\");\n	    %M=&xml2t\
ag_list     ($HSP{$b}{body}, \"Hsp_hseq\");\n	    \
\n	    for ($e=0; $e<$Q{n}; $e++)\n\n	      {\n		$\
qs=$Q{$e}{body};\n		$ms=$M{$e}{body};\n		if ($seq \
eq\"\"){$seq=$qs;$L=length($seq);}\n		\n		$expecta\
tion=$E{$e}{body};\n		$identity=($LEN{$e}{body}==0\
)?0:$I{$e}{body}/$LEN{$e}{body}*100;\n		$start=$ST\
ART{$e}{body};\n		$end=$END{$e}{body};\n		$Hstart=\
$HSTART{$e}{body};\n		$Hend=$HEND{$e}{body};\n	\n	\
	$coverage=(($end-$start)*100)/$L;\n\n	\n		if ($id\
entity>$maxid || $identity<$minid || $coverage<$mi\
ncov){next;}\n		@lr1=(split (//,$qs));\n		@lr2=(sp\
lit (//,$ms));\n		$l=$#lr1+1;\n		for ($c=0;$c<$L;$\
c++){$p[$nhits][$c]=\"-\";}\n		for ($d=0,$c=0; $c<\
$l; $c++)\n		  {\n		    $r=$lr1[$c];\n		    if ( $\
r=~/[A-Za-z]/)\n		      {\n			\n			$p[$nhits][$d +\
 $start-1]=$lr2[$c];\n			$d++;\n		      }\n		  }\n\
		$Qseq[$nhits]=$qs;\n		$Hseq[$nhits]=$ms;\n		$Qst\
artL[$nhits]=$start;\n		$HstartL[$nhits]=$Hstart;\\
n		$identityL[$nhits]=$identity;\n		$endL[$nhits]=\
$end;\n		$definitionL[$nhits]=$definition;\n		$ide\
ntifyerL[$nhits]=$identifyer;\n		$comment[$nhits]=\
\"$ldb|$identifyer [Eval=$expectation][id=$identit\
y%][start=$Hstart end=$Hend]\";\n		$nhits++;\n	   \
   }\n	  }\n      }\n    \n    $profile{n}=0;\n   \
 $profile{$profile{n}}{name}=$name;\n    $profile{\
$profile{n}}{seq}=$seq;\n    $profile {n}++;\n    \
\n    for ($a=0; $a<$nhits; $a++)\n      {\n	$n=$a\
+1;\n	\n	$profile{$n}{name}=\"$name\\_$a\";\n	$pro\
file{$n}{seq}=\"\";\n	$profile{$n}{Qseq}=$Qseq[$a]\
;\n	$profile{$n}{Hseq}=$Hseq[$a];\n	$profile{$n}{Q\
start}=$QstartL[$a];\n	$profile{$n}{Hstart}=$Hstar\
tL[$a];\n	$profile{$n}{identity}=$identityL[$a];\n\
	$profile{$n}{definition}=$definitionL[$a];\n	$pro\
file{$n}{identifyer}=$identifyerL[$a];\n	$profile{\
$n}{comment}=$comment[$a];\n	for ($b=0; $b<$L; $b+\
+)\n	  {\n	    if ($p[$a][$b])\n	      {\n		$profi\
le{$n}{seq}.=$p[$a][$b];\n	      }\n	    else\n	  \
    {\n		$profile{$n}{seq}.=\"-\";\n	      }\n	  }\
\n      }\n    \n    $profile{n}=$nhits+1;\n    re\
turn %profile;\n  }\nsub ebi_blast_xml2profile \n \
 {\n    my ($name,$seq,$maxid, $minid, $mincov, $s\
tring)=(@_);\n    my ($L,$l, $a,$b,$c,$d,$nhits,@i\
dentifyerL,$identifyer);\n    \n\n    \n    $seq=~\
s/[^a-zA-Z]//g;\n    $L=length ($seq);\n    %hit=&\
xml2tag_list ($string, \"hit\");\n    \n    for ($\
nhits=0,$a=0; $a<$hit{n}; $a++)\n      {\n	my ($ld\
b,$id, $identity, $expectation, $start, $end, $cov\
erage, $r);\n	my (%Q,%M,%E,%I);\n	\n	$ldb=&tag2val\
ue ($hit{$a}{open}, \"database\");\n	$identifyer=&\
tag2value ($hit{$a}{open}, \"id\");\n\n	$descripti\
on=&tag2value ($hit{$a}{open}, \"description\");\n\
	\n	%Q=&xml2tag_list ($hit{$a}{body}, \"querySeq\"\
);\n	%M=&xml2tag_list ($hit{$a}{body}, \"matchSeq\\
");\n	%E=&xml2tag_list ($hit{$a}{body}, \"expectat\
ion\");\n	%I=&xml2tag_list ($hit{$a}{body}, \"iden\
tity\");\n	\n\n	for ($b=0; $b<$Q{n}; $b++)\n	  {\n\
	    \n	    \n	    $qs=$Q{$b}{body};\n	    $ms=$M{\
$b}{body};\n	    if ($seq eq\"\"){$seq=$qs;$L=leng\
th($seq);}\n\n	    $expectation=$E{$b}{body};\n	  \
  $identity=$I{$b}{body};\n	    \n	    	    \n	   \
 $start=&tag2value ($Q{$b}{open}, \"start\");\n	  \
  $end=&tag2value ($Q{$b}{open}, \"end\");\n	    $\
startM=&tag2value ($M{$b}{open}, \"start\");\n	   \
 $endM=&tag2value ($M{$b}{open}, \"end\");\n	    $\
coverage=(($end-$start)*100)/$L;\n	    \n	   # pri\
nt \"$id: ID: $identity COV: $coverage [$start $en\
d]\\n\";\n	    \n	    \n	    if ($identity>$maxid \
|| $identity<$minid || $coverage<$mincov){next;}\n\
	    # print \"KEEP\\n\";\n\n	    \n	    @lr1=(spl\
it (//,$qs));\n	    @lr2=(split (//,$ms));\n	    $\
l=$#lr1+1;\n	    for ($c=0;$c<$L;$c++){$p[$nhits][\
$c]=\"-\";}\n	    for ($d=0,$c=0; $c<$l; $c++)\n	 \
     {\n		$r=$lr1[$c];\n		if ( $r=~/[A-Za-z]/)\n		\
  {\n		    \n		    $p[$nhits][$d + $start-1]=$lr2[\
$c];\n		    $d++;\n		  }\n	      }\n	  \n	    \n	 \
   $identifyerL[$nhits]=$identifyer;\n	    $commen\
t[$nhits]=\"$ldb|$identifyer [Eval=$expectation][i\
d=$identity%][start=$startM end=$endM]\";\n	    $n\
hits++;\n	  }\n      }\n    \n    $profile{n}=0;\n\
    $profile{$profile{n}}{name}=$name;\n    $profi\
le{$profile{n}}{seq}=$seq;\n    $profile {n}++;\n \
   \n    for ($a=0; $a<$nhits; $a++)\n      {\n	$n\
=$a+1;\n	$profile{$n}{name}=\"$name\\_$a\";\n	$pro\
file{$n}{seq}=\"\";\n	$profile{$n}{identifyer}=$id\
entifyerL[$a];\n	\n	$profile{$n}{comment}=$comment\
[$a];\n	for ($b=0; $b<$L; $b++)\n	  {\n	    if ($p\
[$a][$b])\n	      {\n		$profile{$n}{seq}.=$p[$a][$\
b];\n	      }\n	    else\n	      {\n		$profile{$n}\
{seq}.=\"-\";\n	      }\n	  }\n      }\n    $profi\
le{n}=$nhits+1;\n    \n    return %profile;\n  }\n\
\nsub blast_xml2hit_list\n  {\n    my $string=(@_[\
0]);\n    return &xml2tag_list ($string, \"hit\");\
\n  }\nsub xml2tag_list  \n  {\n    my ($string_in\
,$tag)=@_;\n    my $tag_in, $tag_out;\n    my %tag\
;\n    \n    if (-e $string_in)\n      {\n	$string\
=&file2string ($string_in);\n      }\n    else\n  \
    {\n	$string=$string_in;\n      }\n    $tag_in1\
=\"<$tag \";\n    $tag_in2=\"<$tag>\";\n    $tag_o\
ut=\"/$tag>\";\n    $string=~s/>/>##1/g;\n    $str\
ing=~s/</##2</g;\n    $string=~s/##1/<#/g;\n    $s\
tring=~s/##2/#>/g;\n    @l=($string=~/(\\<[^>]+\\>\
)/g);\n    $tag{n}=0;\n    $in=0;$n=-1;\n  \n \n\n\
    foreach $t (@l)\n      {\n\n	$t=~s/<#//;\n	$t=\
~s/#>//;\n	\n	if ( $t=~/$tag_in1/ || $t=~/$tag_in2\
/)\n	  {\n	 \n	    $in=1;\n	    $tag{$tag{n}}{open\
}=$t;\n	    $n++;\n	    \n	  }\n	elsif ($t=~/$tag_\
out/)\n	  {\n	    \n\n	    $tag{$tag{n}}{close}=$t\
;\n	    $tag{n}++;\n	    $in=0;\n	  }\n	elsif ($in\
)\n	  {\n	   \n	    $tag{$tag{n}}{body}.=$t;\n	  }\
\n      }\n  \n    return %tag;\n  }\n\n\n\n\n","u\
se Env qw(HOST);\nuse Env qw(HOME);\nuse Env qw(US\
ER);\nwhile (<>)\n  {\n    if ( /^>(\\S+)/)\n     \
 {\n	if ($list{$1})\n	  {\n	    print \">$1_$list{\
$1}\\n\";\n	    $list{$1}++;\n	  }\n	else\n	  {\n	\
    print $_;\n	    $list{$1}=1;\n	  }\n      }\n \
   else\n      {\n	print $_;\n      }\n  }\n      \
\n","\n\n\nuse Env qw(HOST);\nuse Env qw(HOME);\nu\
se Env qw(USER);\n\n\nopen (F,$ARGV[0]);\nwhile ( \
<>)\n  {\n    @x=/([^:,;\\)\\(\\s]+):[^:,;\\)\\(]*\
/g;\n    @list=(@list,@x);\n  }\n$n=$#list+1;\nfor\
each $n(@list){print \">$n\\nsequence\\n\";}\n\n\n\
close (F);\n","\nopen (F, $ARGV[0]);\n\nwhile ( <F\
>)\n  {\n    @l=($_=~/(\\S+)/g);\n    \n    $name=\
shift @l;\n    \n    print STDOUT \"\\n>$name\\n\"\
;\n    foreach $e (@l){$e=($e eq \"0\")?\"O\":\"I\\
";print \"$e\";}\n  }\nclose (F);\n\n		       \n  \
  \n","use Env qw(HOST);\nuse Env qw(HOME);\nuse E\
nv qw(USER);\n\n$tmp=\"$ARGV[0].$$\";\nopen (IN, $\
ARGV[0]);\nopen (OUT, \">$tmp\");\n\nwhile ( <IN>)\
\n  {\n    $file=$_;\n    $file=~s/\\r\\n/\\n/g;\n\
    $file=~s/\\n\\r/\\n/g;\n    $file=~s/\\r\\r/\\\
n/g;\n    $file=~s/\\r/\\n/g;\n    print OUT \"$fi\
le\";\n  }\nclose (IN);\nclose (OUT);\n\nopen (OUT\
, \">$ARGV[0]\");\nopen (IN, \"$tmp\");\n\nwhile (\
 <IN>)\n{\n  print OUT \"$_\";\n}\nclose (IN);\ncl\
ose (OUT);\nunlink ($tmp);\n\n"};
