echo "USAGE: patchgen.sh VERSION_NUMBER"

flips --create $OOT_LE/../clean/ZELOOTMA.z64 $OOT_LE/zelda_ocarina_mq_dbg.z64 $OOT_LE/releases/oot_legendary_edition_ch$1_mqdb.bps
flips --create $OOT_LE/../clean/oot_v1.z64 $OOT_LE/zelda_ocarina_mq_dbg.z64 $OOT_LE/releases/oot_legendary_edition_ch$1_v1.bps
