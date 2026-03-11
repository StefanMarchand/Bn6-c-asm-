#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsound_8000808
\t.type\t sound_8000808,function
\t.thumb_func
sound_8000808:
\tpush\t{r4-r7,lr}
\tldr\tr5, .Lstandalone_dword_200A490
\tldr\tr7, [r5]
\tcmp\tr7, #32
\tblt\t.Lstore
\tb\t.Lreturn
.Lstore:
\tadd\tr6, r7, #1
\tstr\tr6, [r5]
\tlsl\tr7, r7, #4
\tadd\tr7, #12
\tadd\tr7, r7, r5
\tstmia\tr7!, {r0-r3}
.Lreturn:
\tpop\t{r4-r7,pc}
\t.align\t2, 0
.Lstandalone_dword_200A490:
\t.word\tdword_200A490
.Lfe1:
\t.size\t sound_8000808,.Lfe1-sound_8000808
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_sound_8000808.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsound_8000808\n" not in text:
        raise SystemExit(f"expected sound_8000808 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
