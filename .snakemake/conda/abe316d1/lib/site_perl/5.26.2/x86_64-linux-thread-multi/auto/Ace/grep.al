# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2044 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/grep.al)"
#########################################################
# Grep function returns count in a scalar context, list
# of retrieved objects in a list context.
sub grep {
  my $self = shift;
  my ($pattern,$count,$offset,$filled,$filltag,$total,$long) = 
      rearrange(['PATTERN','COUNT','OFFSET',['FILL','FILLED'],'FILLTAG','TOTAL','LONG'],@_);
  $offset += 0;
  my $grep = defined($long) && $long ? 'LongGrep' : 'grep';
  my $r = $self->raw_query("$grep $pattern");
  my ($cnt) = $r =~ /Found (\d+) objects/m;
  $$total = $cnt if defined $total;
  return $cnt if !wantarray;
  if ($filltag) {
    @h = $self->_fetch($count,$offset,$filltag);
  } else {
    @h = $filled ? $self->_fetch($count,$offset) : $self->_list($count,$offset);
  }
  @h;
}

# end of Ace::grep
1;
