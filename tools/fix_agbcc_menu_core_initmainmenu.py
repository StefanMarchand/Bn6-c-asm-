#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsub_801FFD6
\t.type\t sub_801FFD6,function
\t.thumb_func
sub_801FFD6:
\tpush\t{r4-r7,lr}
\tsub\tsp, sp, #8
\tstr\tr0, [sp,#4]
\tcmp\tr0, #1
\tbeq\tloc_80200A0
\tmov\tr1, #8
\ttst\tr0, r1
\tbeq\tloc_801FFEA
\tnop
\tb\tloc_802004E
loc_801FFEA:
\tldr\tr4, .Lpool0
\tldr\tr5, .Lpool1
\tmov\tr6, r10
\tldr\tr6, [r6,#0x18]
\tldr\tr7, .Lpool2
\tldrh\tr1, [r5,#2]
\tmov\tr2, #0xfc
\tlsl\tr2, r2, #8
\tand\tr2, r1
\tbeq\tloc_802001C
\tmov\tr0, #0
\tbl\tsub_800A0D6
\tldrb\tr1, [r5,#6]
\tstrb\tr1, [r6,#0x14]
\tldrh\tr1, [r5,#0xc]
\tldr\tr0, .Lpool3
\tstrh\tr1, [r0,#0x2c]
\tmov\tr0, #4
\tldrsb\tr0, [r5,r0]
\ttst\tr0, r0
\tblt\tloc_802001C
\tlsl\tr0, r0, #2
\tldr\tr1, [r5,#8]
\tstr\tr1, [r7,r0]
loc_802001C:
\tadd\tr5, #0x10
\tldr\tr7, .Lpool4
\tldrb\tr1, [r4]
\ttst\tr1, r1
\tbeq\tloc_8020030
\tldrh\tr1, [r5,#2]
\tmov\tr2, #0xfc
\tlsl\tr2, r2, #8
\tand\tr2, r1
\tbeq\tloc_802004E
loc_8020030:
\tmov\tr0, #1
\tbl\tsub_800A0D6
\tldrb\tr1, [r5,#6]
\tstrb\tr1, [r6,#0x15]
\tldrh\tr1, [r5,#0xc]
\tldr\tr0, .Lpool5
\tstrh\tr1, [r0,#0x2c]
\tmov\tr0, #4
\tldrsb\tr0, [r5,r0]
\ttst\tr0, r0
\tblt\tloc_802004E
\tlsl\tr0, r0, #2
\tldr\tr1, [r5,#8]
\tstr\tr1, [r7,r0]
loc_802004E:
\tldr\tr1, [sp,#4]
\tmov\tr2, #0x10
\ttst\tr1, r2
\tbeq\tloc_802005A
\tnop
\tb\tloc_80200A0
loc_802005A:
\tldr\tr5, .Lpool6
\tmov\tr0, r10
\tldr\tr0, [r0,#4]
\tldrh\tr1, [r0]
\tstrh\tr1, [r5,#2]
\tstr\tr1, [sp]
\tmov\tr0, r10
\tldr\tr0, [r0,#0x18]
\tldrb\tr1, [r0,#0x11]
\tstrb\tr1, [r5,#6]
\tmov\tr0, #4
\tbl\tsub_803F740
\tstrh\tr0, [r5,#0xc]
\tldrb\tr0, [r4,#2]
\tmov\tr1, #1
\ttst\tr0, r1
\tbeq\tloc_8020094
\tmov\tr0, #3
\tldrsb\tr0, [r4,r0]
\tsub\tr0, #1
\tstrb\tr0, [r4,#3]
\tblt\tloc_8020094
\tstrb\tr0, [r5,#4]
\tlsl\tr0, r0, #2
\tldr\tr1, .Lpool7
\tldr\tr0, [r0,r1]
\tstr\tr0, [r5,#8]
\tb\tloc_80200A0
loc_8020094:
\tldrb\tr0, [r4,#2]
\tmov\tr1, #1
\tbic\tr0, r1
\tstrb\tr0, [r4,#2]
\tmov\tr0, #0xff
\tstrb\tr0, [r5,#4]
loc_80200A0:
\tadd\tsp, sp, #8
\tpop\t{r4-r7,pc}
\t.align\t2, 0
\t.Lpool0:
\t.word\teStruct203F7D8
\t.Lpool1:
\t.word\tunk_20399F0
\t.Lpool2:
\t.word\tdword_203F4A0
\t.Lpool3:
\t.word\tunk_2036120
\t.Lpool4:
\t.word\tdword_203F5A0
\t.Lpool5:
\t.word\tunk_20362F0
\t.Lpool6:
\t.word\teStruct2036780
\t.Lpool7:
\t.word\tdword_203CBE0
.Lfe1:
\t.size\t sub_801FFD6,.Lfe1-sub_801FFD6
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_menu_core_initmainmenu.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_801FFD6\n" not in text:
        raise SystemExit(f"expected sub_801FFD6 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
