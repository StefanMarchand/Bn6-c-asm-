#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsound_800068A
\t.type\t sound_800068A,function
\t.thumb_func
sound_800068A:
\tpush\t{r4-r7,lr}
\tldr\tr7, .Lstandalone_off_8000704
\tlsl\tr0, r0, #2
\tldr\tr0, [r7, r0]
\tmov\tr2, sl
\tpush\t{r2}
\tldr\tr3, .Lstandalone_sub_814E87C
\tbl\tsound_8000808
\tpop\t{r2}
\tmov\tsl, r2
\tpop\t{r4-r7,pc}
\t.align\t2, 0
.Lstandalone_off_8000704:
\t.word\toff_8000704
.Lstandalone_sub_814E87C:
\t.word\tsub_814E87C+1
.Lfe1:
\t.size\t sound_800068A,.Lfe1-sound_800068A
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_sound_800068A.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsound_800068A\n" not in text:
        raise SystemExit(f"expected sound_800068A in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
