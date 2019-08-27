# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2015 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/version.al)"
sub version {
  my $self = shift;
  my $status= $self->status;
  $status->{database}{version};
}

# end of Ace::version
1;
