# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 1887 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/tags.al)"
### Return list of all the tags in the object ###
sub tags {
    my $self = shift;
    my $current = $self->right;
    my @tags;
    while (defined($current)) {
	push(@tags,$current);
	$current = $current->down;
    }
    return @tags;
}

# end of Ace::Object::tags
1;
