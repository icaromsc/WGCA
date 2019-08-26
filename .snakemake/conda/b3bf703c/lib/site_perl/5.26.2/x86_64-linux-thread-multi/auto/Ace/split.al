# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2097 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/split.al)"
sub split {
  my $class = shift;
  my $text = shift;
  $text =~ s/\\n/\n/g;
  $text =~ s/\\t/\t/g;
  my ($id,$ts);
  ($class,$id,$ts) = $text=~m/^\?(.+)(?<!\\)\?(.+)(?<!\\)\?([^?]*)$/s;
  $class ||= '';  # fix uninitialized variable warnings
  $id    ||= '';
  $class =~ s/\\\?/?/g;
  $id =~  s/\\\?/?/g;
  return ($class,$id) unless $ts;
  return ($class,$id,$ts);  # return timestamp
}

# end of Ace::split
1;
