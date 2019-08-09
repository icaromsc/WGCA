# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2167 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/_restore_iterator.al)"
# horrid method that keeps the database's view of
# iterators in synch with our view
sub _restore_iterator {
  my $self = shift;
  my $iterator = shift;

  # no such iterator known, return false
  return unless $self->{iterators}{$iterator};

  # make other iterators save themselves
  $self->_alert_iterators;

  # fetch the list of iterators stored on the stack
  my $list = $self->{iterator_stack};
  # spick not supported. Abandon ship
  return if @$list > 1 and $self->{no_spick};

  # Find the iterator in our list. This mirrors the
  # position in the server stack
  my $i;
  for ($i=0; $i<@$list; $i++) {
    last if $list->[$i] eq $iterator;
  }
  return unless $i < @$list;

  # Sse spop if the list size is 1.  Otherwise use spick, which is
  # only supported in hacked versions of the server.
  my $result = $i == 0 ? $self->raw_query("spop",'no_alert') 
                       : $self->raw_query("spick $i",'no_alert');
  
  if ($result =~ /Keyword spick does not match/) {
    # _restore_iterator will now only work for a single iterator (non-reentrantly)
    $self->{no_spick}++;
    $self->raw_query('spop','no_alert') foreach @$list;  # empty database stack
    $self->{iterator_stack} = [];             # and local copy
    return;
  }

  unless (($result =~ /The stack now holds (\d+) keyset/ && ($1 == (@$list-1) ))
	  or 
	  ($result =~ /stack is (now )?empty/ && @$list == 1)
	 ) {
    $Ace::Error = 'Unexpected result from spick: $result';
    return;
  }

  splice(@$list,$i,1);   # remove from position
  return 1;
}

# end of Ace::_restore_iterator
1;
