#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsound_80006A2
\t.type\t sound_80006A2,function
\t.thumb_func
sound_80006A2:
\tpush\t{r4-r7,lr}
\tcmp\tr0, #0x25
\tbgt\tloc_80006B0
\tmov\tr7, r10
\tldr\tr7, [r7,#oToolkit_GameStatePtr]
\tstrb\tr0, [r7,#oGameState_BGMusicIndicator]
\tb\tloc_80006B0
loc_80006B0:
\tmov\tr4, r12
\tmov\tr5, r8
\tmov\tr6, r9
\tmov\tr7, r10
\tpush\t{r4-r7}
\tldr\tr7, off_8000700
\tlsl\tr2, r2, #2
\tldr\tr7, [r7,r2]
\tmov\tr4, r0
\tmov\tr5, r1
\tldr\tr3, off_8000884
\tbl\tsound_8000808
\tmov\tr0, r7
\tldr\tr3, off_8000888
\tbl\tsound_8000808
\tmov\tr0, r7
\tmov\tr1, #0xff
\tmov\tr2, #0
\tldr\tr3, off_800088C
\tbl\tsound_8000808
\tmov\tr0, r4
\tldr\tr3, off_8000890
\tbl\tsound_8000808
\tmov\tr0, r7
\tmov\tr1, r5
\tldr\tr3, off_8000894
\tbl\tsound_8000808
\tpop\t{r4-r7}
\tmov\tr12, r4
\tmov\tr8, r5
\tmov\tr9, r6
\tmov\tr10, r7
\tpop\t{r4-r7,pc}
\t.word\toff_2010890
\t.balign 4, 0
.Lfe1:
\t.size\t sound_80006A2,.Lfe1-sound_80006A2
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_sound_80006A2_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsound_80006A2\n" not in text:
        raise SystemExit(f"expected sound_80006A2 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
