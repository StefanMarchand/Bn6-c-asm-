#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\tthumb_local_start
sub_8026450:
\tpush {r4,r6,r7,lr}
\tsub sp, sp, #0x10
\tstr r6, [sp]
\tstr r7, [sp,#4]
\tstr r0, [sp,#8]
\tstr r1, [sp,#0xc]
\tmov r4, r2
\tbl object_getFrontDirection // () -> int
\tmov r6, r0
loc_8026464:
\tmov r0, #0
\tldrsb r0, [r4,r0]
\tcmp r0, #0x7f
\tbeq loc_80264A2
\tmul r0, r6
\tldr r2, [sp,#8]
\tadd r0, r0, r2
\tbmi loc_802649E
\tcmp r0, #6
\tbgt loc_802649E
\tmov r1, r0
\tmul r1, r6
\tldr r2, [sp]
\tmul r2, r6
\tcmp r1, r2
\tbgt loc_802649E
\tmov r1, #1
\tldrsb r1, [r4,r1]
\tldr r2, [sp,#0xc]
\tadd r1, r1, r2
\tbmi loc_802649E
\tcmp r1, #3
\tbgt loc_802649E
\tpush {r0,r1}
\tbl sub_800E680
\tcmp r0, #0
\tpop {r0,r1}
\tbne loc_80264A4
loc_802649E:
\tadd r4, #2
\tb loc_8026464
loc_80264A2:
\tmov r0, #0
loc_80264A4:
\tadd sp, sp, #0x10
\tpop {r4,r6,r7,pc}
\tthumb_func_end sub_8026450

\tthumb_local_start
sub_80264A8:
\tpush {r4,r6,r7,lr}
\tsub sp, sp, #0x10
\tstr r6, [sp]
\tstr r7, [sp,#4]
\tstr r0, [sp,#8]
\tstr r1, [sp,#0xc]
\tmov r4, r2
\tbl object_getFrontDirection // () -> int
\tmov r6, r0
loc_80264BC:
\tmov r0, #0
\tldrsb r0, [r4,r0]
\tcmp r0, #0x7f
\tbeq loc_802650A
\tmul r0, r6
\tldr r2, [sp,#8]
\tadd r0, r0, r2
\tbmi loc_8026506
\tcmp r0, #6
\tbgt loc_8026506
\tmov r1, r0
\tmul r1, r6
\tldr r2, [sp]
\tmul r2, r6
\tcmp r1, r2
\tbgt loc_8026506
\tmov r1, #1
\tldrsb r1, [r4,r1]
\tldr r2, [sp,#0xc]
\tadd r1, r1, r2
\tbmi loc_8026506
\tcmp r1, #3
\tbgt loc_8026506
\tpush {r0,r1}
\tbl sub_800E680
\tcmp r0, #0
\tpop {r0,r1}
\tbeq loc_8026506
\tldr r2, [sp]
\tldr r3, [sp,#4]
\tpush {r0,r1}
\tbl sub_8026510
\tcmp r0, #0
\tpop {r0,r1}
\tbne loc_802650C
loc_8026506:
\tadd r4, #2
\tb loc_80264BC
loc_802650A:
\tmov r0, #0
loc_802650C:
\tadd sp, sp, #0x10
\tpop {r4,r6,r7,pc}
\tthumb_func_end sub_80264A8
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_0_beast_scan_helpers_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_8026450\n" not in text:
        raise SystemExit(f"expected sub_8026450 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
