# NOTE: Derived from blib/lib/Ace/Object.pm.
# Changes made here will be lost when autosplit is run again.
# See AutoSplit.pm.
package Ace::Object;

#line 1732 "blib/lib/Ace/Object.pm (autosplit into blib/lib/auto/Ace/Object/asDNA.al)"
### Get the FASTA-format DNA/Peptide representation for this object ###
### (if appropriate) ###
sub asDNA {
  return shift()->_special_dump('dna');
}

# end of Ace::Object::asDNA
1;
