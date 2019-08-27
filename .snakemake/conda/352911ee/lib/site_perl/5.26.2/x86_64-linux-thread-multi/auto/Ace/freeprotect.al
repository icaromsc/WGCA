# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2087 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/freeprotect.al)"
# these two only get loaded if the Ace::Freesubs .XS isn't compiled
sub freeprotect {
  my $class = shift;
  my $text = shift;
  $text =~ s/\n/\\n/g;
  $text =~ s/\t/\\t/g;
  $text =~ s/"/\\"/g;
  return qq("$text");
}

# end of Ace::freeprotect
1;
