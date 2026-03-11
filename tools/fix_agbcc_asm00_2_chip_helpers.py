#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsub_800EDD0
\t.type\t sub_800EDD0,function
\t.thumb_func
sub_800EDD0:
\tpush\t{r5-r7,lr}
\tsub\tsp, sp, #4
\tstr\tr1, [sp]
\tmov\tr5, r0
\tldrh\tr0, [r5,#40]
\tbl\tsub_800F29C
\tcmp\tr0, #2
\tbne\tloc_800EE1A
\tldrb\tr0, [r5,#22]
\tbl\tgetBattleHandAddr_8010018
\tmov\tr4, r0
\tldrb\tr6, [r0]
\tadd\tr1, r6, r6
\tadd\tr0, r0, r1
\tadd\tr0, #2
\tmov\tr7, r0
\tldrh\tr0, [r7]
\tldr\tr1, [sp]
\tbl\tsub_800EF34
\tmov\tr3, r1
\tldrh\tr2, [r7,#24]
\tadd\tr2, r2, r0
\tldrh\tr0, [r7,#36]
\tadd\tr2, r2, r0
\tldrh\tr1, [r7,#12]
\tldrh\tr0, [r7]
\tmov\tr7, #68
\tadd\tr7, r7, r6
\tldrb\tr7, [r4,r7]
\tadd\tr6, #62
\tldrb\tr4, [r4,r6]
\tlsl\tr4, r4, #8
\tadd\tr4, r4, r7
\tb\tloc_800EE22
loc_800EE1A:
\tldrh\tr0, [r5,#42]
\tmov\tr1, #0
\tmov\tr2, #0
\tldrb\tr3, [r5,#26]
loc_800EE22:
\tadd\tsp, sp, #4
\tpop\t{r5-r7,pc}
\t.size\t sub_800EDD0,.-sub_800EDD0
\t.globl\tsub_800EE26
\t.type\t sub_800EE26,function
\t.thumb_func
sub_800EE26:
\tpush\t{r5-r7,lr}
\tmov\tr5, r0
\tldrh\tr0, [r5,#40]
\tbl\tsub_800F29C
\tcmp\tr0, #2
\tbne\tloc_800EE8E
\tldrb\tr0, [r5,#22]
\tbl\tsub_802E070
\tmov\tr6, r0
\tbl\tsub_800EE98
\tldrh\tr0, [r6,#52]
\tmov\tr1, #0
\tbl\tsub_800EF34
\tpush\t{r0,r1}
\tldrh\tr0, [r6,#52]
\tbl\tgetChip8021DA8
\tldrb\tr0, [r0,#15]
\tstrb\tr0, [r7,#29]
\tldrh\tr0, [r6,#52]
\tldrb\tr1, [r5,#22]
\tbl\tsub_80109A4
\tmov\tr1, r0
\tpop\t{r2,r3}
\tpush\t{r1-r3}
\tldrh\tr0, [r6,#52]
\tbl\tgetChip8021DA8
\tldrb\tr0, [r0,#9]
\tpop\t{r1-r3}
\tmov\tr4, #2
\ttst\tr0, r4
\tbeq\tloc_800EE7A
\tldrh\tr4, [r6,#54]
\tadd\tr2, r2, r4
\tmov\tr4, #0
\tstrh\tr4, [r6,#54]
loc_800EE7A:
\tmov\tr4, #4
\ttst\tr0, r4
\tbeq\tloc_800EE88
\tldrh\tr4, [r6,#56]
\tadd\tr2, r2, r4
\tmov\tr4, #0
\tstrh\tr4, [r6,#56]
loc_800EE88:
\tmov\tr4, #0
\tldrh\tr0, [r6,#52]
\tb\tlocret_800EE96
loc_800EE8E:
\tldrh\tr0, [r5,#42]
\tmov\tr1, #0
\tmov\tr2, #0
\tldrb\tr3, [r5,#26]
locret_800EE96:
\tpop\t{r5-r7,pc}
\t.size\t sub_800EE26,.-sub_800EE26
\t.globl\tsub_800EE98
\t.type\t sub_800EE98,function
\t.thumb_func
sub_800EE98:
\tpush\t{r0-r4,lr}
\tldrb\tr0, [r5,#22]
\tldrh\tr1, [r6,#52]
\tbl\tsub_802E830
\tmov\tr4, r0
\tldrb\tr0, [r5,#22]
\tbl\tbattle_networkInvert
\ttst\tr0, r0
\tbne\tloc_800EEBA
\tmov\tr0, r4
\tbl\tsub_801E2BA
\tmov\tr0, #141
\tbl\tPlaySoundEffect
loc_800EEBA:
\tldrh\tr0, [r6,#52]
\tbl\tgetChip8021DA8
\tmov\tr4, r0
\tldrb\tr0, [r4,#22]
\tmov\tr1, #128
\ttst\tr0, r1
\tbne\tlocret_800EEE2
\tldrb\tr0, [r4,#7]
\tadd\tr0, r0, r0
\tldr\tr1, off_800EEF4
\tldrh\tr0, [r1,r0]
\tldr\tr2, off_800EEF0
\tadd\tr3, r6, r6
\tstrh\tr0, [r2,r3]
\tldrh\tr1, [r6,#40]
\tsub\tr1, r1, r0
\tbge\tloc_800EEE0
\tmov\tr1, #0
loc_800EEE0:
\tstrh\tr1, [r6,#40]
locret_800EEE2:
\tpop\t{r0-r4,pc}
\t.word\t0, 0
\t.byte\t0, 0, 0, 0
\t.balign 4, 0
off_800EEF0:
\t.word\tword_200F3C4
off_800EEF4:
\t.word\tbyte_800EEF8
byte_800EEF8:
\t.byte\t0x0, 0x15, 0x0, 0x2A, 0x0, 0x40, 0xFF, 0xFF, 0xFF, 0xFF
\t.size\t sub_800EE98,.-sub_800EE98
\t.globl\tsub_800EF02
\t.type\t sub_800EF02,function
\t.thumb_func
sub_800EF02:
\tpush\t{r5-r7,lr}
\tmov\tr6, r0
\tldrh\tr0, [r5,#40]
\tbl\tsub_800F29C
\tcmp\tr0, #2
\tbne\tloc_800EF2A
\tmov\tr0, r6
\tmov\tr1, #0
\tbl\tsub_800EF34
\tpush\t{r0,r1}
\tmov\tr0, r6
\tldrb\tr1, [r5,#22]
\tbl\tsub_80109A4
\tmov\tr1, r0
\tpop\t{r2,r3}
\tmov\tr0, r6
\tb\tlocret_800EF32
loc_800EF2A:
\tldrh\tr0, [r5,#42]
\tmov\tr1, #0
\tmov\tr2, #0
\tldrb\tr3, [r5,#26]
locret_800EF32:
\tpop\t{r5-r7,pc}
\t.size\t sub_800EF02,.-sub_800EF02
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm00_2_chip_helpers.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_800EDD0\n" not in text:
        raise SystemExit(f"expected sub_800EDD0 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
