# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2145 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/_register_iterator.al)"
sub _register_iterator {
  my ($self,$iterator) = @_;
  $self->{iterators}{$iterator} = $iterator;
}

# end of Ace::_register_iterator
1;
