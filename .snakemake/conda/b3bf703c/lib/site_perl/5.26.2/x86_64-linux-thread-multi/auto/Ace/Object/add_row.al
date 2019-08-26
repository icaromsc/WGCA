# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 1928 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/add_row.al)"
################# add a new row #############
#  Only changes local copy until you perform commit() #
#  returns true if this is a valid thing to do #
sub add_row {
  my $self = shift;
  my($tag,@newvalue) = rearrange([['TAG','PATH'],'VALUE'],@_);

  # flatten array refs into array
  my @values = map { ref($_) && ref($_) eq 'ARRAY' ? @$_ : $_ } @newvalue;

  # make sure that this entry doesn't already exist
  unless ($tag =~ /\./) {
    my $model = $self->model;
    my @intermediate_tags = $model->path($tag);
    $tag = join '.',@intermediate_tags,$tag;
  }
  my $row = join(".",($tag,map { (my $x = $_) =~s/\./\\./g; $x } @values));
  return if $self->at($row);  # an identical row already exists in the object

  # If we get here then we need to turn @values into an array of Ace::Objects
  # for insertion.  Also need to link them together into a row.
  my $previous;
  foreach (@values) {
    if (ref($_) && $_->isa('Ace::Object')) {
      $_ = $_->_clone;
    } else {
      $_ = $self->new('scalar',$_);
    }
    $previous->{'.right'} = $_ if defined $previous;
    $previous = $_;
    $_->{'.right'} = undef; # make sure it doesn't automatically expand!
  }

  # position at the indicated tag (creating it if necessary)
  my (@tags) = $self->_split_tags($tag);
  my $p = $self;
  foreach (@tags) {
    $p = $p->_insert($_);
  }
  if ($p->{'.right'}) {
    $p = $p->{'.right'};
    while (1) { 
      last unless $p->{'.down'};
      $p = $p->{'.down'};
    }
    $p->{'.down'} = $values[0];
  } else {
    $p->{'.right'} = $values[0];
  }

  push(@{$self->{'.update'}},join(' ',map { Ace->freeprotect($_) } (@tags,@values)));
  delete $self->{'.PATHS'}; # uncache cached values
  $self->_dirty(1);
  1;
}

# end of Ace::Object::add_row
1;
