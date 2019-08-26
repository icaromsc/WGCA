# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2225 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/date.al)"
sub date {
  my $self = shift;
  my $time = shift || time;
  my ($sec,$min,$hour,$day,$mon,$year) = localtime($time);
  $year += 1900;   # avoid Y3K bug
  sprintf("%4d-%02d-%02d",$year,$mon+1,$day);
}

1;
# end of Ace::date
