#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tmusicGameState_8000784
\t.type\t musicGameState_8000784,function
\t.thumb_func
musicGameState_8000784:
\tpush\t{r7,lr}
\tmov\tr1, sl
\tpush\t{r1}
\tldr\tr3, .Lstandalone_sub_814EA58
\tbl\tsound_8000808
\tpop\t{r1}
\tmov\tsl, r1
\tmov\tr7, sl
\tldr\tr7, [r7, #60]
\tmov\tr0, #255
\tstrb\tr0, [r7, #15]
\tpop\t{r7,pc}
\t.align\t2, 0
\t.word\t0
.Lstandalone_sub_814EA58:
\t.word\tsub_814EA58+1
\t.byte\t0
\t.byte\t0
.Lfe1:
\t.size\t musicGameState_8000784,.Lfe1-musicGameState_8000784
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_musicGameState_8000784.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tmusicGameState_8000784\n" not in text:
        raise SystemExit(f"expected musicGameState_8000784 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
