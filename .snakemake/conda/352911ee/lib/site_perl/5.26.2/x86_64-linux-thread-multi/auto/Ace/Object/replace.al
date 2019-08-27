# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2058 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/replace.al)"
################# delete a portion of the tree #############
# Only changes local copy until you perform commit() #
#  returns true if this is a valid thing to do #
sub replace {
  my $self = shift;
  my($tag,$oldvalue,$newvalue,@rest) = rearrange([['TAG','PATH'],
						  ['OLDVALUE','OLD'],
						  ['NEWVALUE','NEW']],@_);
    $self->delete($tag,$oldvalue);
    $self->add($tag,$newvalue,@rest);
    delete $self->{'.PATHS'}; # uncache cached values
    1;
}

# end of Ace::Object::replace
1;
