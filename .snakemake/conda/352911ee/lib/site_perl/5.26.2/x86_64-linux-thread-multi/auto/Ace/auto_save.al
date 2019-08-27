# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2021 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/auto_save.al)"
sub auto_save {
  my $self = shift;
  if ($self->db && $self->db->can('auto_save')) {
    $self->db->auto_save;
  } else {
    $self->{'auto_save'} = $_[0] if defined $_[0];
    return $self->{'auto_save'};
  }
}

# end of Ace::auto_save
1;
