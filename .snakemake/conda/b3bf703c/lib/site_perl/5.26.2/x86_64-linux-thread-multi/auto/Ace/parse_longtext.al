# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 1894 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/parse_longtext.al)"
# Parse a single object as longtext and return the result
# as an object
sub parse_longtext {
  my $self  = shift;
  my ($title,$body) = @_;
      my $mm = "parse =
Longtext $title
$body
***LongTextEnd***
" ;
  $mm =~ s/\//\\\//g ;
  $mm =~ s/\n/\\n/g ;
  $mm .= "\n" ;
  my $result = $self->raw_query($mm) ;
  $Ace::Error = $result=~/sorry|parse error/mi ? $result : '';
  my @results = $self->_list(1,0);
  return $results[0];
}

# end of Ace::parse_longtext
1;
