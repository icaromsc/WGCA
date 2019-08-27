# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2112 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/classes.al)"
# Return a list of all the classes known to the server.
sub classes {
  my ($self,$invisible) = @_;
  my $query = defined($invisible) && $invisible ?
    "query find class !buried" 
      :
    "query find class visible AND !buried";
  $self->raw_query($query);
  return $self->_list;
}

# end of Ace::classes
1;
