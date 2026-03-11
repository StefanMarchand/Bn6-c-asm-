#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsub_800ED90
\t.type\t sub_800ED90,function
\t.thumb_func
sub_800ED90:
\tpush\t{r5,r7,lr}
\tmov\tr5, r0
\tldrh\tr0, [r5,#40]
\tbl\tsub_800F29C
\tcmp\tr0, #2
\tbne\tloc_800EDC6
\tldrb\tr0, [r5,#22]
\tbl\tgetBattleHandAddr_8010018
\tldrb\tr1, [r0]
\tadd\tr1, r1, r1
\tadd\tr0, r0, r1
\tadd\tr0, #2
\tmov\tr7, r0
\tldrh\tr0, [r7]
\tmov\tr1, #0
\tbl\tsub_800EF34
\tldrh\tr2, [r7,#24]
\tadd\tr2, r2, r0
\tldrh\tr0, [r7,#36]
\tadd\tr2, r2, r0
\tldrh\tr1, [r7,#12]
\tldrh\tr0, [r7]
\tldrb\tr3, [r5,#26]
\tpop\t{r5,r7,pc}
loc_800EDC6:
\tldrh\tr0, [r5,#42]
\tmov\tr1, #0
\tmov\tr2, #0
\tldrb\tr3, [r5,#26]
\tpop\t{r5,r7,pc}
.Lfe1:
\t.size\t sub_800ED90,.Lfe1-sub_800ED90
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_sub_800ED90.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_800ED90\n" not in text:
        raise SystemExit(f"expected sub_800ED90 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
