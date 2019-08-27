# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2217 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/datetime.al)"
sub datetime {
  my $self = shift;
  my $time = shift || time;
  my ($sec,$min,$hour,$day,$mon,$year) = localtime($time);
  $year += 1900;   # avoid Y3K bug
  sprintf("%4d-%02d-%02d %02d:%02d:%02d",$year,$mon+1,$day,$hour,$min,$sec);
}

# end of Ace::datetime
1;
