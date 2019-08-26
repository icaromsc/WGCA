# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2156 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/_asTable.al)"
# This function is overly long because it is optimized to prevent parsing
# parts of the tree that haven't previously been parsed.
sub _asTable {
    my($self,$out,$position,$level) = @_;
    do {
      if ($self->{'.raw'}) {  # we still have raw data, so we can optimize
	my ($a,$start,$end) = @{$self}{ qw(.col .start_row .end_row) };
	my @to_append = map { join("\t",@{$_}[$a..$#{$_}]) } @{$self->{'.raw'}}[$start..$end];
	my $new_row;
	foreach (@to_append) {
	  # hack alert
	  s/(\?.*?[^\\]\?.*?[^\\]\?)\S*/$self->_ace_format(Ace->split($1))/eg;
	  if ($new_row++) {
	    $$out .= "\n";
	    $$out .= "\t" x ($level-1) 
	  }
	  $$out .= $_;
	}
	return $level-1;
      }

      $$out .= "\t" x ($level-$position-1);
      $$out .= $self->name . "\t";
      if ($self->comment) {
	$$out .= $self->comment;
	$$out .= "\n" . "\t" x $level unless $self->down && !defined($self->right);
      }
      $level = $self->right->_asTable($out,$level,$level+1)
	if defined $self->right;
      $$out .= "\n" if defined($self = $self->down);
      $position = 0;
    } while defined $self;
    return --$level;
}

# end of Ace::Object::_asTable
1;
