#!/usr/bin/env python3
import sys


ASM = """// () -> void
\tthumb_local_start
sub_80466AA:
\tpush {r4-r7,lr}
\tldr r5, off_80466D4 // =eStructArr2008450 
\tmov r7, #0
loc_80466B0:
\tldrb r0, [r5]
\ttst r0, r0
\tbeq loc_80466BA
\tbl sub_804668A
loc_80466BA:
\tadd r5, #0x58 
\tadd r7, #1
\tcmp r7, #0xf
\tblt loc_80466B0
\tpop {r4-r7,pc}
\tthumb_func_end sub_80466AA
"""


def main() -> None:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_2_text_sprite_clear_80466AA_rominc.py <path>")
    with open(sys.argv[1], "w", encoding="ascii") as f:
        f.write(ASM)


if __name__ == "__main__":
    main()
