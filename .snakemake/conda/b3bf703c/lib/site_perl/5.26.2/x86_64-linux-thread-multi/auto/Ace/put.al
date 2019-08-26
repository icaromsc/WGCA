# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 1859 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/put.al)"
# Add one or more objects to the database
sub put {
  my $self = shift;
  my @objects = @_;
  my $count = 0;
  $Ace::Error = '';
  foreach my $object (@objects) {
    croak "Can't put a non-Ace object into an Ace database"
      unless $object->isa('Ace::Object');
    croak "Can't put a non-object into a database"
      unless $object->isObject;
    $object = $object->fetch unless $object->isRoot;  # make sure we're putting root object
    my $data = $object->asAce;
    $data =~ s/\n/; /mg;
    my $result = $self->raw_query("parse = $data");
    $Ace::Error = $result if $result =~ /sorry|parse error/mi;
    return $count if $Ace::Error;
    $count++;  # bump if succesful
  }
  return $count;
}

# end of Ace::put
1;
