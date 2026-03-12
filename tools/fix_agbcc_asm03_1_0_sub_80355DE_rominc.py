#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\tthumb_func_start sub_80355DE
sub_80355DE:
\tldr r1, off_80355E8 // =byte_80984C8
\tmov r2, #0x14
\tmul r2, r0
\tadd r0, r1, r2
\tmov pc, lr
off_80355E8:
\t.word byte_80984C8
\tthumb_func_end sub_80355DE
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_1_0_sub_80355DE_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_80355DE\n" not in text:
        raise SystemExit(f"expected sub_80355DE in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
