#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsub_800060A
\t.type\t sub_800060A,function
\t.thumb_func
sub_800060A:
\tpush\t{r1-r7,lr}
\tldr\tr1, .Lstandalone_byte_2010B90
\tldrb\tr1, [r1]
\tcmp\tr1, #0
\tbne\tloc_8000616
\tmov\tr1, #255
loc_8000616:
\tldr\tr3, .Lstandalone_sound_8000822
\tbl\tsound_8000808
\tpop\t{r1-r7,pc}
\t.align\t2, 0
.Lstandalone_byte_2010B90:
\t.word\tbyte_2010B90
.Lstandalone_sound_8000822:
\t.word\tsound_8000822+1
.Lfe1:
\t.size\t sub_800060A,.Lfe1-sub_800060A
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_sub_800060A.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_800060A\n" not in text:
        raise SystemExit(f"expected sub_800060A in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
