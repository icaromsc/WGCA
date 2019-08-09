# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 1751 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/asTable.al)"
#### As tab-delimited table ####
sub asTable {
    my $self = shift;
    my $string = "$self\t";
    my $right = $self->right;
    $right->_asTable(\$string,1,2) if defined($right);
    return $string . "\n";
}

# end of Ace::Object::asTable
1;
