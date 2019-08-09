# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2150 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/_unregister_iterator.al)"
sub _unregister_iterator {
  my ($self,$iterator) = @_;
  $self->_restore_iterator($iterator);
  delete $self->{iterators}{$iterator};
}

# end of Ace::_unregister_iterator
1;
