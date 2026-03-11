#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsub_80007A0
\t.type\t sub_80007A0,function
\t.thumb_func
sub_80007A0:
\tpush\t{r1-r7,lr}
\tmov\tr1, sl
\tpush\t{r1}
\tldr\tr3, off_800089C
\tbl\tsound_8000808
\tpop\t{r1}
\tmov\tsl, r1
\tpop\t{r1-r7,pc}
.Lfe1:
\t.size\t sub_80007A0,.Lfe1-sub_80007A0
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_sub_80007A0_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_80007A0\n" not in text:
        raise SystemExit(f"expected sub_80007A0 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
