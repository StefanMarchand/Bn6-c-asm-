#!/usr/bin/env python3
import sys


ASM = """\tthumb_func_start sub_80468E0
sub_80468E0:
\tpush {r4-r7,lr}
\tmov r0, #0
\tstrb r0, [r5]
\tbl sprite_makeUnscalable
\tpop {r4-r7,pc}
\tthumb_func_end sub_80468E0

\tthumb_func_start sub_80468EC
sub_80468EC:
\tpush {r4-r7,lr}
\tldr r5, off_8046928 // =byte_2011860 
\tmov r1, #0x58 
\tmul r1, r0
\tadd r5, r5, r1
\tmov r0, #0
\tstrb r0, [r5]
\tbl sprite_makeUnscalable
\tpop {r4-r7,pc}
\tthumb_func_end sub_80468EC

\tthumb_local_start
sub_8046900:
\tpush {r4-r7,lr}
\tldr r5, off_8046928 // =byte_2011860 
\tmov r7, #0
loc_8046906:
\tldrb r0, [r5]
\ttst r0, r0
\tbeq loc_8046910
\tbl sub_80468E0
loc_8046910:
\tadd r5, #0x58 
\tadd r7, #1
\tcmp r7, #5
\tblt loc_8046906
\tpop {r4-r7,pc}
\tthumb_func_end sub_8046900
"""


def main() -> None:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_2_text_sprite_clear_80468E0_rominc.py <path>")
    with open(sys.argv[1], "w", encoding="ascii") as f:
        f.write(ASM)


if __name__ == "__main__":
    main()
