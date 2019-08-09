# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 1845 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/date_style.al)"
# Get or set the display style for dates
sub date_style {
  my $self = shift;
  $self->{'date_style'} = $_[0] if defined $_[0];
  return $self->{'date_style'};
}

# end of Ace::date_style
1;
