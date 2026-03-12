#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """// () -> void
\tthumb_func_start sub_804657C
sub_804657C:
\tpush {r4-r7,lr}
\t// memBlock
\tldr r0, off_80466D4 // =eStructArr2008450 
\t// size
\tldr r1, off_804659C // =0x528 
\tbl ZeroFillByWord // (mut_mem: *mut (), num_bytes: usize) -> ()
\tldr r5, off_80466D4 // =eStructArr2008450 
\tmov r7, #0
loc_804658A:
\tmov r0, #0x20 
\tstrb r0, [r5,#2]
\tstrb r7, [r5,#3]
\tadd r5, #0x58 
\tadd r7, #1
\tcmp r7, #0xf
\tblt loc_804658A
\tpop {r4-r7,pc}
\t.balign 4, 0
off_804659C:
\t.word 0x528
\tthumb_func_end sub_804657C

// (void *a1) -> void
\tthumb_func_start sub_80465A0
sub_80465A0:
\tpush {r4-r7,lr}
loc_80465A2:
\tldrb r7, [r0]
\tcmp r7, #0xff
\tbeq locret_80465BA
\tpush {r0}
\tldrh r2, [r0,#2]
\tldrb r1, [r0,#1]
\tldrb r0, [r0]
\tbl sub_8046670
\tpop {r0}
\tadd r0, #4
\tb loc_80465A2
locret_80465BA:
\tpop {r4-r7,pc}
\tthumb_func_end sub_80465A0

"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm03_2_text_sprite_wrappers_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_804657C\n" not in text:
        raise SystemExit(f"expected sub_804657C in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
