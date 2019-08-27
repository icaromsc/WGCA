# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 1796 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/asGif.al)"
# run a series of GIF commands and return the Gif and the semi-parsed
# "boxes" structure.  Commands is typically a series of mouseclicks
# ($gif,$boxes) = $aceObject->asGif(-clicks=>[[$x1,$y1],[$x2,$y2]...],
#                                   -dimensions=>[$x,$y]);
sub asGif {
  my $self = shift;
  my ($clicks,$dimensions,$display,$view,$coords,$getcoords) = rearrange(['CLICKS',
									  ['DIMENSIONS','DIM'],
									  'DISPLAY',
									  'VIEW',
									  'COORDS',
									  'GETCOORDS',
									  ],@_);
  $display = "-D $display" if $display;
  $view    = "-view $view" if $view;
  my $c;
  if ($coords) {
    $c    =  ref($coords) ? "-coords @$coords" : "-coords $coords";
  }
  my @commands;
  if ($view || $c || $self->class =~ /Map/i) {
      @commands = "gif map \"@{[$self->name]}\" $view $c";
  } else {
      @commands = "gif display $display $view @{[$self->class]} \"@{[$self->name]}\"";
  }
  push(@commands,"Dimensions @$dimensions") if ref($dimensions);
  push(@commands,map { "mouseclick @{$_}" } @$clicks) if ref($clicks);

  if ($getcoords) { # just want the coordinates
    my ($start,$stop);
    my $data = $self->db->raw_query(join(' ; ',@commands));    
    return unless $data =~ /\"[^\"]+\" ([\d.-]+) ([\d.-]+)/;
    ($start,$stop) = ($1,$2);
    return ($start,$stop);
  }

  push(@commands,"gifdump -");

  # do the query
  my $data = $self->db->raw_query(join(' ; ',@commands));

  # A $' has been removed here to improve speed -- tim.cutts@incyte.com 2 Sep 1999

  # did this query succeed?
  my ($bytes, $trim);
  return unless ($bytes, $trim) = $data=~m!^// (\d+) bytes\n\0*(.+)!sm;

  my $gif = substr($trim,0,$bytes);

  # now process the boxes
  my @b;
  my @boxes = split("\n",substr($trim,$bytes));
  foreach (@boxes) {
    last if m!^//!;
    chomp;
    my ($left,$top,$right,$bottom,$class,$name,$comments) = 
      m/^\s*\d*\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\w+):"(.+)"\s*(.*)/;
    next unless defined $left;
    $comments=~s/\s+$//; # sometimes there's extra white space at the end
    my $box = {'coordinates'=>[$left,$top,$right,$bottom],
	       'class'=>$class,
	       'name' =>$name,
	       'comment'=>$comments};
    push (@b,$box);
  }
  return ($gif,\@b);
}

# end of Ace::Object::asGif
1;
