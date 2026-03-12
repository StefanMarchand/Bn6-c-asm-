#!/usr/bin/env python3
import sys


ASM = """\tthumb_func_start sub_804668A
sub_804668A:
\tpush {r4-r7,lr}
\tmov r0, #0
\tstrb r0, [r5]
\tbl sprite_makeUnscalable
\tpop {r4-r7,pc}
\tthumb_func_end sub_804668A
"""


def main() -> None:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_2_text_sprite_clear_804668A_rominc.py <path>")
    with open(sys.argv[1], "w", encoding="ascii") as f:
        f.write(ASM)


if __name__ == "__main__":
    main()
