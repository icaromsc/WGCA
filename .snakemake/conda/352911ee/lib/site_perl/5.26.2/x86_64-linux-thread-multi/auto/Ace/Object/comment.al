# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 1877 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/comment.al)"
sub comment {
    my $self = shift;
    return $self->{'.comment'} = $_[0] if defined $_[0];
    if ($self->db && !$self->{'.comment'}) {
      $self->_fill;
      $self->_parse;
    }
    return $self->{'.comment'};
}

# end of Ace::Object::comment
1;
