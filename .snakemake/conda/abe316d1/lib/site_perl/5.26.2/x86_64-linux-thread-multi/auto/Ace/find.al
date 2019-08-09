# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2031 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/find.al)"
# Perform an ace query and return the result
sub find {
  my $self = shift;
  my ($query,$count,$offset,$filled,$total) = rearrange(['QUERY','COUNT',
							 'OFFSET',['FILL','FILLED'],'TOTAL'],@_);
  $offset += 0;
  $query = "find $query" unless $query=~/^find/i;
  my $cnt = $self->count(-query=>$query);
  $$total = $cnt if defined $total;
  return $cnt unless wantarray;
  $filled ? $self->_fetch($count,$offset) : $self->_list($count,$offset);
}

# end of Ace::find
1;
