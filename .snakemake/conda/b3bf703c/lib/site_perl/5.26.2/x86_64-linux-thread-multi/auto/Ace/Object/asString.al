# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 1768 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/asString.al)"
### Pretty-printed version ###
sub asString {
  my $self = shift;
  my $MAXWIDTH = shift || $DEFAULT_WIDTH;
  my $tabs = $self->asTable;
  return "$self" unless $tabs;
  my(@lines) = split("\n",$tabs);
  my($result,@max);
  foreach (@lines) {
    my(@fields) = split("\t");
    for (my $i=0;$i<@fields;$i++) {
      $max[$i] = length($fields[$i]) if
	!defined($max[$i]) or $max[$i] < length($fields[$i]);
    }
  }
  foreach (@max) { $_ = $MAXWIDTH if $_ > $MAXWIDTH; } # crunch long lines
  my $format1 = join(' ',map { "^"."<"x $max[$_] } (0..$#max)) . "\n";
  my $format2 =   ' ' . join('  ',map { "^"."<"x ($max[$_]-1) } (0..$#max)) . "~~\n";
  $^A = '';
  foreach (@lines) {
    my @data = split("\t");
    push(@data,('')x(@max-@data));
    formline ($format1,@data);
    formline ($format2,@data);
  }
  return ($result = $^A,$^A='')[0];
}

# end of Ace::Object::asString
1;
