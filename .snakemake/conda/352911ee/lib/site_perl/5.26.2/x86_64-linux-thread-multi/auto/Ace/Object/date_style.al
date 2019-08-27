# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2129 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/date_style.al)"
### Get or set the date style (actually calls through to the database object) ###
sub date_style {
  my $self = shift;
  return unless $self->db;
  return $self->db->date_style(@_);
}

# end of Ace::Object::date_style
1;
