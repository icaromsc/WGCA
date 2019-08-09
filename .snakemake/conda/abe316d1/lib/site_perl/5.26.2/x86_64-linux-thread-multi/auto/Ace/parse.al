# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 1881 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/parse.al)"
# Parse a single object and return the result as an object
sub parse {
  my $self = shift;
  my $ace_data = shift;
  my @lines = split("\n",$ace_data);
  foreach (@lines) { s/;/\\;/;  } # protect semicolons  
  my $query = join("; ",@lines);
  my $result = $self->raw_query("parse = $query");
  $Ace::Error = $result=~/sorry|parse error/mi ? $result : '';
  my @results = $self->_list(1,0);
  return $results[0];
}

# end of Ace::parse
1;
