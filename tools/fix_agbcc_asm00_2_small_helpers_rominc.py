#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsub_800F29C
\t.type\t sub_800F29C,function
\t.thumb_func
sub_800F29C:
\tpush\t{lr}
\tbl\tsub_80182B4
\tldrb\tr2, [r0]
\tldrb\tr1, [r0,#2]
\tldrb\tr0, [r0,#1]
\tpop\t{pc}
\t.size\t sub_800F29C,.-sub_800F29C
\t.globl\tsub_800F2AA
\t.type\t sub_800F2AA,function
\t.thumb_func
sub_800F2AA:
\tpush\t{lr}
\tldrh\tr1, [r5,#40]
\tbl\tnullsub_3
\tpop\t{pc}
\t.size\t sub_800F2AA,.-sub_800F2AA
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm00_2_small_helpers_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_800F29C\n" not in text:
        raise SystemExit(f"expected sub_800F29C in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
