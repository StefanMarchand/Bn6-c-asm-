#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsound_8000642
\t.type\t sound_8000642,function
\t.thumb_func
sound_8000642:
\tpush\t{r4-r7,lr}
\tlsl\tr0, r0, #2
\tldr\tr7, .Lstandalone_off_8000704
\tldr\tr0, [r7, r0]
\tmov\tr3, sl
\tpush\t{r3}
\tldr\tr3, .Lstandalone_sub_814F9AC
\tbl\tsound_8000808
\tpop\t{r3}
\tmov\tsl, r3
\tpop\t{r4-r7,pc}
\t.align\t2, 0
.Lstandalone_off_8000704:
\t.word\toff_8000704
.Lstandalone_sub_814F9AC:
\t.word\tsub_814F9AC+1
.Lfe1:
\t.size\t sound_8000642,.Lfe1-sound_8000642
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_sound_8000642.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsound_8000642\n" not in text:
        raise SystemExit(f"expected sound_8000642 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
