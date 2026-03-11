#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tPlayMusic
\t.type\t PlayMusic,function
\t.thumb_func
PlayMusic:
\tpush\t{r1-r7,lr}
\tmov\tr7, sl
\tldr\tr7, [r7, #60]
\tldrb\tr1, [r7, #15]
\tcmp\tr0, r1
\tbeq\t.L1
\tstrb\tr0, [r7, #15]
\tcmp\tr0, #99
\tbne\t.L2
\tbl\tsound_8000630
\tb\t.L1
.L2:
\tbl\tm4a_800061E
.L1:
\tpop\t{r1-r7,pc}
.Lfe1:
\t.size\t PlayMusic,.Lfe1-PlayMusic
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_playmusic.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tPlayMusic\n" not in text:
        raise SystemExit(f"expected PlayMusic in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
