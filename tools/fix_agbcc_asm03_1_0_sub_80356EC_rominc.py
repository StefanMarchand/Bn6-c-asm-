#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\tthumb_func_start sub_80356EC
sub_80356EC:
\tpush {r4-r7,lr}
\tldr r0, off_8035784 // =dword_2000DC0
\tldr r1, off_8035788 // =0x100
\tbl ZeroFillByWord // (mut_mem: *mut (), num_bytes: usize) -> ()
\tpop {r4-r7,pc}
\tthumb_func_end sub_80356EC
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_1_0_sub_80356EC_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_80356EC\n" not in text:
        raise SystemExit(f"expected sub_80356EC in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
