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

\tthumb_local_start
sub_802668A:
\tpush {lr}
\tldr r0, off_8026810 // =byte_802678E
\tbl sub_80265D0
\tpop {pc}
\tthumb_func_end sub_802668A

\tthumb_local_start
sub_8026694:
\tpush {lr}
\tldr r0, off_8026814 // =byte_8026791
\tbl sub_80265D0
\tpop {pc}
\tthumb_func_end sub_8026694

\tthumb_local_start
sub_802669E:
\tpush {lr}
\tldr r0, off_8026818 // =byte_8026794
\tbl sub_80265D0
\tbl sub_80265FE
\tpop {pc}
\tthumb_func_end sub_802669E

\tthumb_local_start
sub_80266AC:
\tpush {lr}
\tmov r0, r6
\tmov r1, r7
\tldr r2, off_802681C // =byte_802679B
\tbl sub_80264A8
\tpop {pc}
\tthumb_func_end sub_80266AC

\tthumb_local_start
sub_80266BA:
\tpush {lr}
\tmov r2, #0
\tldrb r0, [r5,#oBattleObject_Alliance]
\tldrb r1, [r5,#oBattleObject_DirectionFlip]
\teor r0, r1
\tmov r1, #1
\teor r0, r1
\tmov r1, #5
\tmul r0, r1
\tadd r0, #1
\tcmp r0, r6
\tbne loc_80266D4
\tmov r2, #2
loc_80266D4:
\tldr r0, off_8026820 // =byte_80267A6
\tadd r0, r0, r2
\tbl sub_80265D0
\tpop {pc}
\tthumb_func_end sub_80266BA

\tthumb_local_start
sub_80266DE:
\tpush {lr}
\tldr r0, off_8026824 // =byte_80267AB
\tbl sub_80265D0
\tpop {pc}
\tthumb_func_end sub_80266DE
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
