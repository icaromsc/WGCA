# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 1960 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/status.al)"
# Return a hash of miscellaneous status information from the server
# (to be expanded later)
sub status {
  my $self = shift;
  my $data = $self->raw_query('status');
  study $data;

  my %status;

  # -Code section
  my ($program)    = $data=~/Program:\s+(.+)/m;
  my ($aceversion) = $data=~/Version:\s+(.+)/m;
  my ($build)      = $data=~/Build:\s+(.+)/m;
  $status{code}    = { program=>$program,
		       version=>$aceversion,
		       build  =>$build};

  # -Database section
  my ($title)      = $data=~/Title:\s+(.+)/m;
  my ($name)       = $data=~/Name:\s+(.+)/m;
  my ($release)    = $data=~/Release:\s+(.+)/m;
  my ($directory)  = $data=~/Directory:\s+(.+)/m;
  my ($session)    = $data=~/Session:\s+(\d+)/m;
  my ($user)       = $data=~/User:\s+(.+)/m;
  my ($write)      = $data=~/Write Access:\s+(.+)/m;
  my ($address)    = $data=~/Global Address:\s+(\d+)/m;
  $status{database} = {
		       title     => $title,
		       version   => $name,
		       dbformat  => $release,
		       directory => $directory,
		       session   => $session,
		       user      => $user,
		       write     => $write,
		       address   => $address,
		       };

  # other info - not all
  my ($classes)   = $data=~/classes:\s+(\d+)/;
  my ($keys)      = $data=~/keys:\s+(\d+)/;
  my ($memory)    = $data=~/blocks:\s+\d+,\s+allocated \(kb\):\s+(\d+)/;
  $status{resources} = {
		      classes => $classes,
		      keys    => $keys,
		      memory  => $memory * 1024,
		      };
  return wantarray ? %status : \%status;
}

# end of Ace::status
1;
