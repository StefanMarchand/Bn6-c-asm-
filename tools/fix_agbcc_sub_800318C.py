#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsub_800318C
\t.type\t sub_800318C,function
\t.thumb_func
sub_800318C:
\tldr\tr0, off_80031A4
\tldr\tr1, off_80031A8
\tldr\tr2, off_80031A0
\tmov\tr3, #0
\tstr\tr3, [r2]
\tstr\tr3, [r0]
\tstr\tr1, [r0, #4]
\tstr\tr0, [r1]
\tstr\tr3, [r1, #4]
\tmov\tpc, lr
off_80031A0:
\t.word\teUnkBattleObjectLinkedList
off_80031A4:
\t.word\teBattleObjectsLinkedListStart
off_80031A8:
\t.word\teBattleObjectsLinkedListSentinel
.Lfe1:
\t.size\t sub_800318C,.Lfe1-sub_800318C
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_sub_800318C.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_800318C\n" not in text:
        raise SystemExit(f"expected sub_800318C in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
