# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 1864 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/timestamp.al)"
############## timestamp and comment information ############
sub timestamp {
    my $self = shift;
    return $self->{'.timestamp'} = $_[0] if defined $_[0];
    if ($self->db && !$self->{'.timestamp'}) {
      $self->_fill;
      $self->_parse;
    }
    return $self->{'.timestamp'} if $self->{'.timestamp'};
    return unless defined $self->right;
    return $self->{'.timestamp'} = $self->right->timestamp;
}

# end of Ace::Object::timestamp
1;
