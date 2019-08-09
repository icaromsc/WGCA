# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2009 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/title.al)"
sub title {
  my $self = shift;
  my $status= $self->status;
  $status->{database}{title};
}

# end of Ace::title
1;
