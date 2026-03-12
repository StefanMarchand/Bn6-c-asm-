#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """// () -> void
\tthumb_func_start sub_8046664
sub_8046664:
\tpush {r4-r7,lr}
\tbl sub_80466AA // () -> void
\tbl sub_804657C // () -> void
\tpop {r4-r7,pc}
\tthumb_func_end sub_8046664

\tthumb_func_start sub_8046670
sub_8046670:
\tpush {r4-r7,lr}
\tldr r5, off_80466D4 // =eStructArr2008450 
\tmov r4, #0x58 
\tmul r1, r4
\tadd r5, r5, r1
\tstrb r0, [r5,#1]
\tmov r0, #9
\tstrb r0, [r5]
\tstr r2, [r5,#4]
\tmov r0, #0
\tstr r0, [r5,#8]
\tmov r0, r5
\tpop {r4-r7,pc}
\tthumb_func_end sub_8046670
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_2_text_sprite_reset_wrappers_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_8046664\n" not in text:
        raise SystemExit(f"expected sub_8046664 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
