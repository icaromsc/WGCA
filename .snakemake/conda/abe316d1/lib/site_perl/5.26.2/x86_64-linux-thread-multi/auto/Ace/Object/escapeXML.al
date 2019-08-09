# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2366 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/escapeXML.al)"
sub escapeXML {
  my ($self,$string) = @_;
  $string =~ s/&/&amp;/g;
  $string =~ s/\"/&quot;/g;
  $string =~ s/</&lt;/g;
  $string =~ s/>/&gt;/g;
  return $string;
}

# end of Ace::Object::escapeXML
1;
