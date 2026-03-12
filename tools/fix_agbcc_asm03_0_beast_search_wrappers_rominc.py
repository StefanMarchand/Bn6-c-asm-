#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\tthumb_local_start
sub_8026650:
\tpush {lr}
\tldr r0, off_80267FC // =byte_8026753 
\tbl sub_80265D0
\tpop {pc}
\tthumb_func_end sub_8026650

\tthumb_local_start
sub_802665A:
\tpush {lr}
\tldr r0, off_8026800 // =byte_802675A 
\tbl sub_80265D0
\tbl sub_80265FE
\tpop {pc}
\tthumb_func_end sub_802665A

\tthumb_local_start
sub_8026668:
\tpush {lr}
\tldr r0, off_8026804 // =byte_8026761 
\tbl sub_80265D0
\tpop {pc}
\tthumb_func_end sub_8026668

\tthumb_local_start
sub_8026672:
\tpush {lr}
\tldr r0, off_8026808 // =byte_802676E 
\tbl sub_80265D0
\tpop {pc}
\tthumb_func_end sub_8026672

\tthumb_local_start
sub_802667C:
\tpush {lr}
\tldr r0, off_802680C // =byte_8026781 
\tbl sub_80265D0
\tbl sub_80265FE
\tpop {pc}
\tthumb_func_end sub_802667C
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_0_beast_search_wrappers_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_8026650\n" not in text:
        raise SystemExit(f"expected sub_8026650 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
