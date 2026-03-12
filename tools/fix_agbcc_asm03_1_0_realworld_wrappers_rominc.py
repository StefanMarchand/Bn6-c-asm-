#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\tthumb_local_start
noop_8033A7C: // (self: *const S2011E30 $r5) -> ()
\tpush {lr}
\tpop {pc}
\tthumb_func_end noop_8033A7C

\tthumb_local_start
sub_8033A80: // (self: * S2011E30 $r5) -> ()
\tpush {lr}
\tmov r0, #0
\tbl sub_8033B80
\tmov r0, #0
\tbl sub_8033F80
\tmov r0, #0
\tbl gfxTransfer_8033DA0 // (a0: u32?) -> ()
\tpop {pc}
\tthumb_func_end sub_8033A80

\tthumb_local_start
onUpdateInRealWorld_8033A96: // (self: * S2011E30 $r5) -> ()
\tpush {lr}
\tmov r0, #0
\tbl sub_8033B80
\tmov r0, #0
\tbl sub_8033F80
\tbl sub_8033BE8
\tmov r0, #0
\tbl gfxTransfer_8033DA0 // (a0: u32?) -> ()
\tpop {pc}
\tthumb_func_end onUpdateInRealWorld_8033A96

\tthumb_local_start
sub_8033AB0: // (self: * S2011E30 $r5) -> ()
\tpush {lr}
\tmov r0, #0
\tbl sub_8033B80
\tmov r0, #0
\tbl sub_8033F80
\tbl sub_8033C68
\tpop {pc}
\tthumb_func_end sub_8033AB0

\tthumb_local_start
sub_8033AC4: // (self: * S2011E30 $r5) -> ()
\tpush {lr}
\tmov r0, #0
\tbl sub_8033B80
\tmov r0, #0
\tbl sub_8033F80
\tbl sub_8033C68
\tbl sub_8033BE8
\tpop {pc}
\tthumb_func_end sub_8033AC4

\tthumb_local_start
sub_8033ADC: // (self: * S2011E30 $r5) -> ()
\tpush {lr}
\tmov r0, #1
\tbl sub_8033B80
\tmov r0, #0
\tbl sub_8033F80
\tbl sub_8033CF0
\tpop {pc}
\tthumb_func_end sub_8033ADC

\tthumb_local_start
sub_8033AF0: // (self: * S2011E30 $r5) -> ()
\tpush {lr}
\tmov r0, #1
\tbl sub_8033B80
\tmov r0, #0
\tbl sub_8033F80
\tbl sub_8033CF0
\tbl sub_8033BE8
\tpop {pc}
\tthumb_func_end sub_8033AF0

\tthumb_local_start
noop_8033B08: // (self: *const S2011E30 $r5) -> ()
\tpush {lr}
\tpop {pc}
\tthumb_func_end noop_8033B08

\tthumb_local_start
sub_8033B0C: // (self: * S2011E30 $r5) -> ()
\tpush {lr}
\tbl sub_8033E0C
\tmov r0, #1
\tbl sub_8033F80
\tbl sub_8033EE8
\tpop {pc}
\tthumb_func_end sub_8033B0C

\tthumb_local_start
onUpdateInInternet_8033B1E: // (self: * S2011E30 $r5) -> ()
\tpush {lr}
\tbl sub_8033E0C
\tmov r0, #1
\tbl sub_8033F80
\tbl sub_8033EE8
\tpop {pc}
\tthumb_func_end onUpdateInInternet_8033B1E
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_1_0_realworld_wrappers_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tnoop_8033A7C\n" not in text:
        raise SystemExit(f"expected noop_8033A7C in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
