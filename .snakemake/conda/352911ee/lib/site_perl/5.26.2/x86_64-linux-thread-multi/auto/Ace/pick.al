# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 2065 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/pick.al)"
sub pick {
    my ($self,$class,$item) = @_;
    $Ace::Error = '';
    # assumption of uniqueness of name is violated by some classes!
    #    return () unless $self->count($class,$item) == 1;
    return unless $self->count($class,$item) >= 1;

    # if we get here, then we've got some data to return.
    # yes, we're repeating code slightly...
    my @result;
    my $ts = $self->{'timestamps'} ? '-T' : '';
    my $result = $self->raw_query("show -j $ts");
    unless ($result =~ /(\d+) object dumped/m) {
	$Ace::Error = 'Unexpected close during pick';
	return;
    }

    @result = grep (!m!^\s*//!,split("\n\n",$result));
    return $result[0];
}

# end of Ace::pick
1;
