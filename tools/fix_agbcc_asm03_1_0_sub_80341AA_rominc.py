#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\tthumb_func_start sub_80341AA
sub_80341AA:
\tpush {lr}
\tldr r0, off_80341F4 // =byte_2011A40
\tmov r1, #0xc
\tbl ZeroFillByWord // (mut_mem: *mut (), num_bytes: usize) -> ()
\tpop {pc}
\tthumb_func_end sub_80341AA
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_1_0_sub_80341AA_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_80341AA\n" not in text:
        raise SystemExit(f"expected sub_80341AA in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
