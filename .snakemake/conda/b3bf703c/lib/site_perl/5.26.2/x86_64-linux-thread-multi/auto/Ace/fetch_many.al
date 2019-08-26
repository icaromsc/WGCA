# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2123 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/fetch_many.al)"
################## iterators ##################
# Fetch many objects in iterative style
sub fetch_many {
  my $self = shift;
  my ($class,$pattern,$filled,$query,$chunksize) = rearrange( ['CLASS',
							       ['PATTERN','NAME'],
							       ['FILL','FILLED'],
							       'QUERY',
							       'CHUNKSIZE'],@_);
  $pattern ||= '*';
  $pattern = Ace->freeprotect($pattern);
  if (defined $query) {
    $query = "query $query" unless $query=~/^query\s/;
  } elsif (defined $class) {
    $query = qq{query find $class $pattern};
  } else {
    croak "must call fetch_many() with the -class or -query arguments";
  }
  my $iterator = Ace::Iterator->new($self,$query,$filled,$chunksize);
  return $iterator;
}

# end of Ace::fetch_many
1;
