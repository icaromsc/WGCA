# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 1954 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/class_count.al)"
# Return a hash of all the classes and the number of objects in each
sub class_count {
  my $self = shift;
  return $self->raw_query('classes') =~ /^\s+(\S+) (\d+)/gm;
}

# end of Ace::class_count
1;
