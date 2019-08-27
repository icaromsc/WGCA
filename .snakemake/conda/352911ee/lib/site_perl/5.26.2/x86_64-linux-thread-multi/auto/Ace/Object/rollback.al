# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2113 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/rollback.al)"
# undo changes
sub rollback {
    my $self = shift;
    undef $self->{'.update'};
    # this will force object to be reloaded from database
    # next time it is needed.
    delete $self->{'.right'};
    delete $self->{'.PATHS'};
    1;
}

# end of Ace::Object::rollback
1;
