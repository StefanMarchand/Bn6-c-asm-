#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsound_8000808
\t.type\t sound_8000808,function
\t.thumb_func
sound_8000808:
\tpush\t{r4-r7,lr}
\tldr\tr5, dword_200A490_p
\tldr\tr7, [r5]
\tcmp\tr7, #0x20
\tblt\tloc_8000814
\tb\tlocret_8000820
loc_8000814:
\tadd\tr6, r7, #1
\tstr\tr6, [r5]
\tlsl\tr7, r7, #4
\tadd\tr7, #0xc
\tadd\tr7, r7, r5
\tstmia\tr7!, {r0-r3}
locret_8000820:
\tpop\t{r4-r7,pc}
\t.size\t sound_8000808,.-sound_8000808
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_sound_8000808_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsound_8000808\n" not in text:
        raise SystemExit(f"expected sound_8000808 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
