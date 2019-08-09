# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2276 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/_to_ace_date.al)"
sub _to_ace_date {
  my $self = shift;
  my $string = shift;
  return $string unless lc($self->date_style) eq 'ace';
  %MO = (Jan=>1,Feb=>2,Mar=>3,
	 Apr=>4,May=>5,Jun=>6,
	 Jul=>7,Aug=>8,Sep=>9,
	 Oct=>10,Nov=>11,Dec=>12) unless %MO;
  my ($day,$mo,$yr) = split(" ",$string);
  return "$yr-$MO{$mo}-$day";
}

# end of Ace::Object::_to_ace_date
1;
