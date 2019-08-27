# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 2072 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/commit.al)"
# commit changes from local copy to database copy
sub commit {
  my $self = shift;
  return unless my $db = $self->db;
  
  my ($retval,@cmd);
  my $name = $self->{'name'};
  return unless defined $name;
  
  $name =~ s/([^a-zA-Z0-9_-])/\\$1/g;
  return 1 unless exists $self->{'.update'} && $self->{'.update'};

  $Ace::Error = '';
  my $result = '';

  # bad design alert: the following breaks encapsulation
  if ($db->db->can('write')) { # new way for socket server
    my $cmd = join "\n","$self->{'class'} : $name",@{$self->{'.update'}};
    warn $cmd if $self->debug;
    $result = $db->raw_query($cmd,0,'parse');  # sets Ace::Error for us
  } else {   # old way for RPC server and local
    my $cmd = join('; ',"$self->{'class'} : $name",
		   @{$self->{'.update'}});
    warn $cmd if $self->debug;
    $result = $db->raw_query("parse = $cmd");
  }

  if (defined($result) and $result=~/write( or admin)? access/im) {  # this keeps changing
    $Ace::Error = "Write access denied";
  } elsif (defined($result) and $result =~ /sorry|parse error/mi) {
    $Ace::Error = $result;
  }
  return if $Ace::Error;
  undef $self->{'.update'};
  # this will force a fresh retrieval of the object
  # and synchronize our in-memory copy with the db
  delete $self->{'.right'};
  delete $self->{'.PATHS'};
  return 1;
}

# end of Ace::Object::commit
1;
