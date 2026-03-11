#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tPlaySoundEffect
\t.type\t PlaySoundEffect,function
\t.thumb_func
PlaySoundEffect:
\tpush\t{r1-r7,lr}
\tbl\tm4a_800061E
\tpop\t{r1-r7,pc}
.Lfe1:
\t.size\t PlaySoundEffect,.Lfe1-PlaySoundEffect
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_play_sound_effect.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tPlaySoundEffect\n" not in text:
        raise SystemExit(f"expected PlaySoundEffect in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
