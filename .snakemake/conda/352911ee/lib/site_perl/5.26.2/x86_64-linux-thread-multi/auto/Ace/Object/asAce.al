# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 1760 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/asAce.al)"
#### In "ace" format ####
sub asAce {
  my $self = shift;
  my $string = $self->isRoot ? join(' ',$self->class,':',$self->escape) . "\n" : '';
  $self->right->_asAce(\$string,0,[]);
  return "$string\n\n";
}

# end of Ace::Object::asAce
1;
