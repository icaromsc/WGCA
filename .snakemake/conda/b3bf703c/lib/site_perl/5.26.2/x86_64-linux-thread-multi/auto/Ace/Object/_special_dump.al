# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 1742 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/_special_dump.al)"
sub _special_dump {
  my $self = shift;
  my $dump_format = shift;
  return unless $self->db->count($self->class,$self->name);
  my $result = $self->db->raw_query($dump_format);
  $result =~ s!^//.*!!ms;
  $result;
}

# end of Ace::Object::_special_dump
1;
