# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 1914 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/parse_file.al)"
# Parse a file and return all the results
sub parse_file {
  my $self = shift;
  my ($file,$keepgoing) = @_;
  local(*ACE);
  local($/) = '';  # paragraph mode
  my(@objects,$errors);
  open(ACE,$file) || croak "$file: $!";
  while (<ACE>) {
    chomp;
    my $obj = $self->parse($_);
    unless ($obj) {
      $errors .= $Ace::Error;  # keep track of errors
      last unless $keepgoing;
    }
    push(@objects,$obj);
  }
  close ACE;
  $Ace::Error = $errors;
  return @objects;
}

# end of Ace::parse_file
1;
