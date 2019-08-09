# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 1852 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/timestamps.al)"
# Get or set whether we retrieve timestamps
sub timestamps {
  my $self = shift;
  $self->{'timestamps'} = $_[0] if defined $_[0];
  return $self->{'timestamps'};
}

# end of Ace::timestamps
1;
