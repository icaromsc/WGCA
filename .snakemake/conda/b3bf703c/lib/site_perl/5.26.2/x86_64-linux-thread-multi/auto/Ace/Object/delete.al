# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2020 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/delete.al)"
################# delete a portion of the tree #############
# Only changes local copy until you perform commit() #
#  returns true if this is a valid thing to do.
sub delete {
  my $self = shift;
  my($tag,$oldvalue,@rest) = rearrange([['TAG','PATH'],['VALUE','OLDVALUE','OLD']],@_);

  # flatten array refs into array
  my @values;
  @values = map { ref($_) && ref($_) eq 'ARRAY' ? @$_ : $_ } ($oldvalue,@rest) 
    if defined($oldvalue);

  unless ($tag =~ /\./) {
    my $model = $self->model;
    my @intermediate_tags = $model->path($tag);
    $tag = join '.',@intermediate_tags,$tag;
  }

  my $row = join(".",($tag,map { (my $x = $_) =~s/\./\\./g; $x } @values));
  my $subtree = $self->at($row,undef,1);  # returns the parent

  if (@values
      && defined($subtree->{'.right'})
      && "$subtree->{'.right'}" eq $oldvalue) {
    $subtree->{'.right'} = $subtree->{'.right'}->down;
  } else {
    $subtree->{'.down'} = $subtree->{'.down'}->{'.down'}
  }

  push(@{$self->{'.update'}},join(' ','-D',
				 map { Ace->freeprotect($_) } ($self->_split_tags($tag),@values)));
  delete $self->{'.PATHS'}; # uncache cached values
  $self->_dirty(0);
  $self->db->file_cache_delete($self);
  1;
}

# end of Ace::Object::delete
1;
