#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\tthumb_func_start sub_8046696
sub_8046696:
\tpush {r4-r7,lr}
\tldr r5, off_80466D4 // =eStructArr2008450 
\tmov r1, #0x58 
\tmul r1, r0
\tadd r5, r5, r1
\tmov r0, #0
\tstrb r0, [r5]
\tbl sprite_makeUnscalable
\tpop {r4-r7,pc}
\tthumb_func_end sub_8046696
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_2_text_sprite_clear_8046696_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_8046696\n" not in text:
        raise SystemExit(f"expected sub_8046696 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
