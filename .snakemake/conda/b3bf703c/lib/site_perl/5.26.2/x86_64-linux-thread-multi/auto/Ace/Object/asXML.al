# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2288 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/asXML.al)"
### Return an XML syntax representation  ###
### Consider this feature experimental   ###
sub asXML {
    my $self = shift;
    return unless defined($self->right);

    my ($do_content,$do_class,$do_value,$do_timestamps) = rearrange([qw(CONTENT CLASS VALUE TIMESTAMPS)],@_);
    $do_content    = 0 unless defined $do_content;
    $do_class      = 1 unless defined $do_class;
    $do_value      = 1 unless defined $do_value;
    $do_timestamps = 1 unless (defined $do_timestamps && !$do_timestamps) || !$self->db->timestamps;
    my %options = (content    => $do_content,
		   class      => $do_class,
		   value      => $do_value,
		   timestamps => $do_timestamps);
    my $name = $self->escapeXML($self->name);
    my $class = $self->class;
    my $string = '';
    $self->_asXML(\$string,0,0,'',0,\%options);
    return $string;
}

# end of Ace::Object::asXML
1;
