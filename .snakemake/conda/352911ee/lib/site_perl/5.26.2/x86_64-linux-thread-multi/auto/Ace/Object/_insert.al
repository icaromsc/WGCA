# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2210 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/_insert.al)"
# Insert a new tag or value.
# Local only. Will not affect the database.
# Returns the inserted tag, or the preexisting
# tag, if already there.
sub _insert {
    my ($self,$tag) = @_;
    my $p = $self->{'.right'};
    return $self->{'.right'} = $self->new('tag',$tag)
	unless $p;
    while ($p) {
	return $p if "$p" eq $tag;
	last unless $p->{'.down'};
	$p = $p->{'.down'};
    }
    # if we get here, then we didn't find it, so
    # insert at the bottom
    return $p->{'.down'} = $self->new('tag',$tag);
}

# end of Ace::Object::_insert
1;
