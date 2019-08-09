# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2156 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/_save_iterator.al)"
sub _save_iterator {
  my $self = shift;
  my $iterator = shift;
  return unless $self->{iterators}{$iterator};
  $self->{iterator_stack} ||= [];
  return 1 if grep { $_ eq $iterator } @{$self->{iterator_stack}};
  $self->raw_query("spush",'no_alert');
  unshift @{$self->{iterator_stack}},$iterator;
  1;  # result code -- CHANGE THIS LATER
}

# end of Ace::_save_iterator
1;
