#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\tthumb_local_start
sub_80265FE:
\tpush {r6,r7,lr}
\tmov r6, r0
\tmov r7, r1
\tmov r1, #2
\tbeq locret_802661A
\tmov r1, #2
\tpush {r0,r1}
\tbl sub_800E680
\tcmp r0, #0
\tpop {r0,r1}
\tbne locret_802661A
\tmov r0, r6
\tmov r1, r7
locret_802661A:
\tpop {r6,r7,pc}
\tthumb_func_end sub_80265FE

\tthumb_local_start
sub_802661C:
\tldrb r0, [r5,#oBattleObject_PanelX]
\tldrb r1, [r5,#oBattleObject_PanelY]
\tmov pc, lr
\tthumb_func_end sub_802661C
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_0_beast_panel_helpers_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_80265FE\n" not in text:
        raise SystemExit(f"expected sub_80265FE in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
