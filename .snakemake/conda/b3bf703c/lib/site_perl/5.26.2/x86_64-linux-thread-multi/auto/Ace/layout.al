# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 1946 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/layout.al)"
# Return the layout, which contains classes that should be displayed
sub layout {
  my $self = shift;
  my $result = $self->raw_query('layout');
  $result=~s{\n(\s*\n|//.*\n|\0)+\Z}{}m;  # get rid of extraneous information
  $result;
}

# end of Ace::layout
1;
