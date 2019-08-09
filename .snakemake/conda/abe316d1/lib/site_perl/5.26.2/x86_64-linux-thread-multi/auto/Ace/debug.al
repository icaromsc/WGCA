# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 1821 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/debug.al)"
# -------------------- AUTOLOADED SUBS ------------------

sub debug {
  my $package = shift;
  my $d = $DEBUG_LEVEL;
  $DEBUG_LEVEL = shift if @_;
  $d;
}

# end of Ace::debug
1;
