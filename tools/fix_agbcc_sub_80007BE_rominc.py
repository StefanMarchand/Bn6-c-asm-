#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsub_80007BE
\t.type\t sub_80007BE,function
\t.thumb_func
sub_80007BE:
\tpush\t{r4-r7,lr}
\tldr\tr5, dword_200A490_p
\tldr\tr7, [r5]
\tcmp\tr7, #0
\tbeq\tloc_80007F0
\tldrb\tr0, [r5,#4]
\tadd\tr0, #1
\tcmp\tr0, #26
\tblt\tloc_80007D2
\tmov\tr0, #0
loc_80007D2:
\tstrb\tr0, [r5,#4]
\tmov\tr0, #0
\tstr\tr0, [r5,#8]
\tmov\tr6, #12
\tadd\tr6, r6, r5
loc_80007DC:
\tldmia\tr6!, {r0-r3}
\tmov\tr4, sl
\tpush\t{r4}
\tldr\tr4, off_8000804
\tmov\tlr, r4
\tbx\tr3
loc_80007E8:
\tpop\t{r4}
\tmov\tsl, r4
\tsub\tr7, #1
\tbne\tloc_80007DC
loc_80007F0:
\tmov\tr0, #0
\tstr\tr0, [r5]
\tldr\tr6, [r5,#8]
\tcmp\tr6, #0
\tbeq\tlocret_8000800
\tldmia\tr6!, {r0-r3}
\tbl\tsound_8000808
locret_8000800:
\tpop\t{r4-r7,pc}
\t.balign 4, 0
off_8000804:
\t.word\tloc_80007E8+1
\t.size\t sub_80007BE,.-sub_80007BE
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_sub_80007BE_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_80007BE\n" not in text:
        raise SystemExit(f"expected sub_80007BE in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
