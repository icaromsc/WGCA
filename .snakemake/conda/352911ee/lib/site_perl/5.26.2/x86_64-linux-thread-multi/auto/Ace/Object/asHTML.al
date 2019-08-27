# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 1717 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/asHTML.al)"
# AUTOLOADED METHODS GO HERE

### Return the pretty-printed HTML table representation ###
### may pass a code reference to add additional formatting to cells ###
sub asHTML {
    my $self = shift;
    my ($modify_code) = rearrange(['MODIFY'],@_);
    return unless defined($self->right);
    my $string = "<TABLE BORDER>\n<TR ALIGN=LEFT VALIGN=TOP><TH>$self</TH>";
    $modify_code = \&_default_makeHTML unless $modify_code;
    $self->right->_asHTML(\$string,1,2,$modify_code);
    $string .= "</TR>\n</TABLE>\n";
    return $string;
}

# end of Ace::Object::asHTML
1;
