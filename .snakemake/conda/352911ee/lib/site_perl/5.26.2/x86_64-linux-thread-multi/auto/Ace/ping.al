# NOTE: Derived from blib/lib/Ace.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace;

#line 1830 "blib/lib/Ace.pm (autosplit into blib/lib/auto/Ace/ping.al)"
# Return true if the database is still connected.  This is oddly convoluted
# because there are numerous things that can go wrong, including:
#   1. server has gone away
#   2. server has timed out our connection! (grrrrr)
#   3. communications channel contains unread garbage and is in an inconsistent state
sub ping {
  my $self = shift;
  local($SIG{PIPE})='IGNORE';  # so we don't get a fatal exception during the check
  my $result = $self->raw_query('');
  return unless $result;  # server has gone away
  return if $result=~/broken connection|client time out/;  # server has timed us out  
  return unless $self->{database}->status() == STATUS_WAITING(); #communications oddness
  return 1;
}

# end of Ace::ping
1;
