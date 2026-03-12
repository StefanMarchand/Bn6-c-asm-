#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tm4a_800061E
\t.type\t m4a_800061E,function
\t.thumb_func
m4a_800061E:
\tpush\t{lr}
\tmov\tr1, sl
\tpush\t{r1}
\tldr\tr3, off_800086C
\tbl\tsound_8000808
\tpop\t{r1}
\tmov\tsl, r1
\tpop\t{pc}
\t.size\t m4a_800061E,.-m4a_800061E
\t.globl\tsound_8000630
\t.type\t sound_8000630,function
\t.thumb_func
sound_8000630:
\tpush\t{lr}
\tmov\tr1, sl
\tpush\t{r1}
\tldr\tr3, off_8000870
\tbl\tsound_8000808
\tpop\t{r1}
\tmov\tsl, r1
\tpop\t{pc}
\t.size\t sound_8000630,.-sound_8000630
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm00_0_sound_wrappers.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tm4a_800061E\n" not in text:
        raise SystemExit(f"expected m4a_800061E in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
