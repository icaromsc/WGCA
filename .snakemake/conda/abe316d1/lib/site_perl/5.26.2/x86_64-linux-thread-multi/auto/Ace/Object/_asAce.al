# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2229 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/_asAce.al)"
# This is unsatisfactory because it duplicates much of the code
# of asTable.
sub _asAce {
  my($self,$out,$level,$tags) = @_;

  # ugly optimization for speed
  if ($self->{'.raw'}){
    my ($a,$start,$end) = @{$self}{qw(.col .start_row .end_row)};
    my (@last);
    foreach (@{$self->{'.raw'}}[$start..$end]){
      my $j=1;
      $$out .= join("\t",@$tags) . "\t" if ($level==0) && (@$tags);
      my (@to_modify) = @{$_}[$a..$#{$_}];
      foreach (@to_modify) {
	my ($class,$name) =Ace->split($_);
	if (defined($name)) {
	  $name = $self->_ace_format($class,$name);
	  if (_isObject($class) || $name=~/[^\w.-]/) {
	    $name=~s/"/\\"/g; #escape quotes with slashes
	    $name = qq/\"$name\"/;
	  } 
	} else {
	  $name = $last[$j] if $name eq '';
	}
	$_ = $last[$j++] = $name;  
	$$out .= "$_\t";
      }
      $$out .= "\n";
      $level = 0;
    }
    chop($$out);
    return;
  }
  
  $$out .= join("\t",@$tags) . "\t" if ($level==0) && (@$tags);
  $$out .= $self->escape . "\t";
  if (defined $self->right) {
    push(@$tags,$self->escape);
    $self->right->_asAce($out,$level+1,$tags);
    pop(@$tags);
  }
  if ($self->down) {
    $$out .= "\n";
    $self->down->_asAce($out,0,$tags);
  }
}

# end of Ace::Object::_asAce
1;
