# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2310 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/_asXML.al)"
sub _asXML {
  my($self,$out,$position,$level,$current_tag,$tag_level,$opts) = @_;

  do {
    my $name = $self->escapeXML($self->name);
    my $class = $self->class;
    my ($tagname,$attributes,$content) = ('','',''); # prevent uninitialized variable warnings
    my $tab = "    " x ($level-$position); # four spaces
    $current_tag ||= $class;
    $content = $name if $opts->{content};

    if ($self->isTag) {
      $current_tag = $tagname = $name;
      $tag_level = 0;
    } else {
      $tagname = $tag_level > 0 ? sprintf "%s-%d",$current_tag,$tag_level + 1 : $current_tag;
      $class = "#$class" unless $self->isObject;
      $attributes .= qq( class="$class") if $opts->{class};
      $attributes .= qq( value="$name")  if $opts->{value};
    }

    if (my $c = $self->comment) {
      $c = $self->escapeXML($c);
      $attributes .= qq( comment="$c");
    }

    if ($opts->{timestamps} && (my $timestamp = $self->timestamp)) {
      $timestamp = $self->escapeXML($timestamp);
      $attributes .= qq( timestamp="$timestamp");
    }

    $tagname = $self->_xmlNumber($tagname) if $tagname =~ /^\d/;
    
    unless (defined $self->right) { # lone tag
      $$out .= $self->isTag || !$opts->{content} ? qq($tab<$tagname$attributes />\n) 
	                                         : qq($tab<$tagname$attributes>$content</$tagname>\n);
    } elsif ($self->isTag) { # most tags are implicit in the XML tag names
      if (!XML_COLLAPSE_TAGS or $self->right->isTag) {
	$$out .= qq($tab<$tagname$attributes>\n);
	$level = $self->right->_asXML($out,$position,$level+1,$current_tag,$tag_level + !XML_COLLAPSE_TAGS,$opts);
	$$out .= qq($tab</$tagname>\n);
      } else {
	$level = $self->right->_asXML($out,$position+1,$level+1,$current_tag,$tag_level,$opts);
      }
    } else {
      $$out .=  qq($tab<$tagname$attributes>$content\n);
      $level = $self->right->_asXML($out,$position,$level+1,$current_tag,$tag_level+1,$opts);
      $$out  .= qq($tab</$tagname>\n);
    }

    $self = $self->down;
  } while defined $self;

  return --$level;
}

# end of Ace::Object::_asXML
1;
