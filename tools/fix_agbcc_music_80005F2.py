#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tmusic_80005F2
\t.type\t music_80005F2,function
\t.thumb_func
music_80005F2:
\tpush\t{r1-r7,lr}
\tmov\tr7, sl
\tldr\tr7, [r7, #60]
\tstrb\tr0, [r7, #15]
\tcmp\tr0, #99
\tbne\tloc_8000604
\tbl\tsound_8000630
\tb\tlocret_8000608
loc_8000604:
\tbl\tm4a_800061E
locret_8000608:
\tpop\t{r1-r7,pc}
.Lfe1:
\t.size\t music_80005F2,.Lfe1-music_80005F2
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_music_80005F2.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tmusic_80005F2\n" not in text:
        raise SystemExit(f"expected music_80005F2 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
