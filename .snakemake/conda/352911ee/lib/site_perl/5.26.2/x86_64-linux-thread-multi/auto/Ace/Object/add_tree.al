# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 1984 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/add_tree.al)"
# Use this method to add an entire subobject to the right of the tag.
# The tree may come from another database.
sub add_tree {
  my $self = shift;
  my($tag,$value,@rest) = rearrange([['TAG','PATH'],['VALUE','TREE']],@_);
  croak "Value must be an Ace::Object" unless ref($value) && $value->isa('Ace::Object');

  unless ($tag =~ /\./) {
    my $model = $self->model;
    my @intermediate_tags = $model->path($tag);
    $tag = join '.',@intermediate_tags,$tag;
  }

  # position at the indicated tag, creating it if necessary
  my (@tags) = $self->_split_tags($tag);
  my $p = $self;
  foreach (@tags) {
    $p = $p->_insert($_);
  }
  # Copy the subtree too
  if ($p->{'.right'}) {
    $p = $p->{'.right'};
    while (1) { 
      last unless $p->{'.down'};
      $p = $p->{'.down'};
    }
    $p->{'.down'} = $value->{'.right'};
  } else {
    $p->{'.right'} = $value->{'.right'};
  }
  push(@{$self->{'.update'}},map { join(' ',@tags,$_) } split("\n",$value->asAce));
  delete $self->{'.PATHS'}; # uncache cached values
  $self->_dirty(1);
  1;
}

# end of Ace::Object::add_tree
1;
