# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2136 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/_asHTML.al)"
sub _asHTML {
  my($self,$out,$position,$level,$morph_code) = @_;
  do {
    $$out .= "<TR ALIGN=LEFT VALIGN=TOP>" unless $position;
    $$out .= "<TD></TD>" x ($level-$position-1);
    my ($cell,$prune,$did_it_myself) = $morph_code->($self);
    $$out .= $did_it_myself ? $cell : "<TD>$cell</TD>";
    if ($self->comment) {
      my ($cell,$p,$d) = $morph_code->($self->comment);
      $$out .= $d ? $cell : "<TD>$cell</TD>";
      $$out .= "</TR>\n" . "<TD></TD>" x $level unless $self->down && !defined($self->right);
    }
    $level = $self->right->_asHTML($out,$level,$level+1,$morph_code) if defined($self->right) && !$prune;
    $$out .= "</TR>\n" if defined($self = $self->down);
    $position = 0;
  } while defined $self;
  return --$level;
}

# end of Ace::Object::_asHTML
1;
