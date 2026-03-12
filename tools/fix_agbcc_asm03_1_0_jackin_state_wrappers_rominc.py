#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\tthumb_local_start
sub_80342DC:
\tpush {lr}
\tmov r0, #4
\tstrb r0, [r5]
\tpop {pc}
\tthumb_func_end sub_80342DC

\tthumb_local_start
sub_80342E4:
\tpush {lr}
\tmov r0, #8
\tstrb r0, [r5]
\tpop {pc}
\tthumb_func_end sub_80342E4

\tthumb_local_start
sub_80342EC:
\tpush {lr}
\tmov r7, r10
\tldr r0, [r7,#oToolkit_MainJumptableIndexPtr]
\tmov r1, #4
\tstrb r1, [r0]
\tbl zeroFillVRAM // () -> ()
\tbl ZeroFillGFX30025c0
\tmov r7, r10
\tldr r0, [r7,#oToolkit_GameStatePtr]
\tmov r1, #0
\tstrb r1, [r0,#oGameState_EnterMapFadeParam1]
\tmov r1, #0x10
\tstrb r1, [r0,#oGameState_EnterMapFadeParam2]
\tbl map_triggerEnterMapOnWarp_8005C04
\tbl navi_80340F6
\tpop {pc}
\tthumb_func_end sub_80342EC
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_1_0_jackin_state_wrappers_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_80342DC\n" not in text:
        raise SystemExit(f"expected sub_80342DC in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
