#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\tthumb_func_start renderTextGfx_8045F8C
renderTextGfx_8045F8C:
\tpush {lr}
\tpush {r7}
\tmov r7, r10
\tldr r7, [r7,#oToolkit_Unk200a220_Ptr]
\tstr r0, [r7,#0x40]
\tpop {r7}
\tlsl r1, r1, #1
\tldrh r1, [r0,r1]
\tadd r0, r0, r1
\tmov r1, r8
\tpush {r1}
\tmov r1, r9
\tpush {r1}
\tldr r1, off_8045FB8 // =sub_3006B94+1 
\tmov lr, pc
\tbx r1
\tpop {r1}
\tmov r9, r1
\tpop {r1}
\tmov r8, r1
\tpop {pc}
\t.balign 4, 0x00
off_8045FB8:
\t.word sub_3006B94+1
\tthumb_func_end renderTextGfx_8045F8C

\tthumb_func_start sub_8045FBC
sub_8045FBC:
\tpush {lr}
\tpush {r0-r3}
\tmov r0, #0
\tmov r3, #0
\tb loc_8045FEE
\tthumb_func_end sub_8045FBC

\tthumb_func_start sub_8045FC6
sub_8045FC6:
\tpush {lr}
\tpush {r0-r3}
\tmov r0, #1
\tmov r3, #0
\tb loc_8045FEE
\tthumb_func_end sub_8045FC6

\tthumb_func_start sub_8045FD0
sub_8045FD0:
\tpush {lr}
\tpush {r0-r3}
\tmov r0, #1
\tmov r3, #1
\tb loc_8045FEE
\tpush {lr}
\tpush {r0-r3}
\tmov r0, #0
\tmov r3, #1
\tb loc_8045FEE
loc_8045FE4:
\tpush {lr}
\tpush {r0-r3}
\tmov r0, #2
\tmov r3, #0
\tb loc_8045FEE
loc_8045FEE:
\tmov r2, r10
\tldr r2, [r2,#oToolkit_Unk200a220_Ptr]
\tstrb r0, [r2,#3]
\tstrb r3, [r2,#4]
\tlsr r0, r1, #0x10
\tldr r1, off_8046030 // =dword_3006B84
\tldr r0, [r1,r0]
\tstr r0, [r2,#0x38]
\tpop {r0-r3}
\tlsl r1, r1, #0x10
\tlsr r1, r1, #0xf
\tldrh r1, [r0,r1]
\tadd r0, r0, r1
\tmov r1, r12
\tpush {r1}
\tmov r1, r9
\tpush {r1}
\tmov r1, r8
\tpush {r1}
\tldr r1, off_804602C // =sub_8046154+1 
\tmov lr, pc
\tbx r1
\tpop {r1}
\tmov r8, r1
\tpop {r1}
\tmov r9, r1
\tpop {r1}
\tmov r12, r1
\tldr r1, off_8046034 // =byte_200A220 
\tldr r0, [r1,#0x3c] // (dword_200A25C - 0x200a220)
\tpop {pc}
\t.balign 4, 0
off_804602C:
\t.word sub_8046154+1
off_8046030:
\t.word dword_3006B84
off_8046034:
\t.word byte_200A220
\tthumb_func_end sub_8045FD0
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_2_text_render_wrappers_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\trenderTextGfx_8045F8C\n" not in text:
        raise SystemExit(f"expected renderTextGfx_8045F8C in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
