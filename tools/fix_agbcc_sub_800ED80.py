#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsub_800ED80
\t.type\t sub_800ED80,function
\t.thumb_func
sub_800ED80:
\tldr\tr1, [r0, #124]
\tldr\tr2, off_800ED8C
\tldr\tr3, [r2]
\tbic\tr3, r1
\tstr\tr3, [r2]
\tmov\tpc, lr
off_800ED8C:
\t.word\teUsedAIDataBitfield
.Lfe1:
\t.size\t sub_800ED80,.Lfe1-sub_800ED80
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_sub_800ED80.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_800ED80\n" not in text:
        raise SystemExit(f"expected sub_800ED80 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
