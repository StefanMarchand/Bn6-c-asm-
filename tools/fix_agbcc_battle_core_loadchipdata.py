#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsomethingWriteChipParams_80126E4
\t.type\t somethingWriteChipParams_80126E4,function
\t.thumb_func
somethingWriteChipParams_80126E4:
\tpush\t{r4,r6,r7,lr}
\tmov\tr4, #1
\tb\tloc_80126F6
\t.globl\tloc_80126EA
\t.type\t loc_80126EA,function
\t.thumb_func
loc_80126EA:
\tpush\t{r4,r6,r7,lr}
\tmov\tr4, #0
\tb\tloc_80126F6
\tpush\t{r4,r6,r7,lr}
\tldr\tr7, [r5,#0x58]
\tadd\tr7, #0xa0
loc_80126F6:
\tstrh\tr0, [r7,#0x14]
\tbl\tgetChip8021DA8
\tmov\tr6, r0
\tldr\tr1, [r6,#0x10]
\tstr\tr1, [r7,#0xc]
\tldrh\tr0, [r7,#0x14]
\tldrb\tr1, [r5,#0x16]
\tbl\tsub_80109A4
\tldrb\tr1, [r6,#0xa]
\tlsl\tr1, r1, #0x10
\tadd\tr1, r1, r0
\tstr\tr1, [r7,#8]
\tldrb\tr1, [r6,#0x14]
\tstrb\tr1, [r7,#5]
\tmov\tr1, #0
\tstrh\tr1, [r7,#6]
\tldrb\tr1, [r6,#0xc]
\tstrb\tr1, [r7,#3]
\tldrb\tr1, [r6,#4]
\tldrb\tr2, [r6,#6]
\tldr\tr0, .Lbyte_80129E4_ptr
\tldrb\tr0, [r0,r2]
\torr\tr1, r0
\tstrb\tr1, [r7,#2]
\tmov\tr1, #0
\tstrb\tr1, [r7,#4]
\ttst\tr4, r4
\tbeq\tloc_801273A
\tldrb\tr0, [r5,#0x16]
\tldrh\tr1, [r7,#0x14]
\tbl\tsub_8021D14
loc_801273A:
\tldrb\tr0, [r6,#0xb]
\tpop\t{r4,r6,r7,pc}
\t.align\t2, 0
.Lbyte_80129E4_ptr:
\t.word\tbyte_80129E4
.Lfe1:
\t.size\t somethingWriteChipParams_80126E4,.Lfe1-somethingWriteChipParams_80126E4
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_battle_core_loadchipdata.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsomethingWriteChipParams_80126E4\n" not in text:
        raise SystemExit(f"expected somethingWriteChipParams_80126E4 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
