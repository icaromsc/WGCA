# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 1899 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/kill.al)"
################# kill an object ################
# Removes the object from the database immediately.
sub kill {
  my $self = shift;
  return unless my $db = $self->db;
  return 1 unless $db->count($self->class,$self->name);
  my $result = $db->raw_query("kill");
  if (defined($result) and $result=~/write access/im) {  # this keeps changing
    $Ace::Error = "Write access denied";
    return;
  }
  # uncache cached values and clear the object out
  # as best we can
  delete @{$self}{qw[.PATHS .right .raw .down]};
  1;
}

# end of Ace::Object::kill
1;
