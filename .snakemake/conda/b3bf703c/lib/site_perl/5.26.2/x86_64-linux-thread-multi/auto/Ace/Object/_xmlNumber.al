# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2375 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/_xmlNumber.al)"
sub _xmlNumber {
  my $self = shift;
  my $tag  = shift;
  $tag =~ s/^(\d)/
        $1 eq '0' ? 'zero'
      : $1 eq '1' ? 'one'
      : $1 eq '2' ? 'two'
      : $1 eq '3' ? 'three'
      : $1 eq '4' ? 'four'
      : $1 eq '5' ? 'five'
      : $1 eq '6' ? 'six'
      : $1 eq '7' ? 'seven'
      : $1 eq '8' ? 'eight'
      : $1 eq '9' ? 'nine'
      : $1/ex;
  $tag;
}

1;
# end of Ace::Object::_xmlNumber
