# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 1916 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/isComment.al)"
# sub isTimestamp {
#   my $self = shift;
#   return 1 if $self->class eq 'UserSession';
#   return;
# }

sub isComment {
  my $self = shift;
  return 1 if $self->class eq 'Comment';
  return;
}

# end of Ace::Object::isComment
1;
