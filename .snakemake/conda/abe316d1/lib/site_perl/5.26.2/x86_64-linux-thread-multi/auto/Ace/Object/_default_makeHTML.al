# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2191 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/_default_makeHTML.al)"
# This is the default code that will be called during construction of
# the HTML table.  It returns a two-member list consisting of the modified
# entry and (optionally) a true value if we are to prune here.  The returned string
# will be placed inside a <TD></TD> tag.  There's nothing you can do about that.
sub _default_makeHTML {
  my $self = shift;
  my ($string,$prune) = ("$self",0);
  return ($string,$prune) unless $self->isObject || $self->isTag;

  if ($self->isTag) {
    $string = "<B>$self</B>";
  } elsif ($self->isComment) {
    $string = "<I>$self</I>";
  }  else {
    $string = qq{<FONT COLOR="blue">$self</FONT>} ;
  }
  return ($string,$prune);
}

# end of Ace::Object::_default_makeHTML
1;
