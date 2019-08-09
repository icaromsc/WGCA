# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 1936 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/new.al)"
# Create a new Ace::Object in the indicated database
# (doesn't actually write into database until you do a commit)
sub new {
  my $self = shift;
  my ($class,$name) = rearrange([qw/CLASS NAME/],@_);
  return if $self->fetch($class,$name);
  my $obj = $self->class_for($class,$name)->new($class,$name,$self);
  return $obj;
}

# end of Ace::new
1;
