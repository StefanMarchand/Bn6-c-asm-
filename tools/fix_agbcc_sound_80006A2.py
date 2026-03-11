#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsound_80006A2
\t.type\t sound_80006A2,function
\t.thumb_func
sound_80006A2:
\tpush\t{r4-r7,lr}
\tcmp\tr0, #37
\tbgt\t.Lskip_bg_music_update
\tmov\tr7, sl
\tldr\tr7, [r7, #60]
\tstrb\tr0, [r7, #15]
.Lskip_bg_music_update:
\tmov\tr4, ip
\tmov\tr5, r8
\tmov\tr6, sb
\tmov\tr7, sl
\tpush\t{r4-r7}
\tldr\tr7, .Lstandalone_off_8000704
\tlsl\tr2, r2, #2
\tldr\tr7, [r7, r2]
\tmov\tr4, r0
\tmov\tr5, r1
\tldr\tr3, .Lstandalone_m4a_SongNumStart
\tbl\tsound_8000808
\tmov\tr0, r7
\tldr\tr3, .Lstandalone_sub_814EB1C
\tbl\tsound_8000808
\tmov\tr0, r7
\tmov\tr1, #255
\tmov\tr2, #0
\tldr\tr3, .Lstandalone_sub_814F9AC
\tbl\tsound_8000808
\tmov\tr0, r4
\tldr\tr3, .Lstandalone_sub_814E9F0
\tbl\tsound_8000808
\tmov\tr0, r7
\tmov\tr1, r5
\tldr\tr3, .Lstandalone_sub_814EAF0
\tbl\tsound_8000808
\tpop\t{r4-r7}
\tmov\tip, r4
\tmov\tr8, r5
\tmov\tsb, r6
\tmov\tsl, r7
\tpop\t{r4-r7,pc}
\t.align\t2, 0
.Lstandalone_off_8000704:
\t.word\toff_8000704
.Lstandalone_m4a_SongNumStart:
\t.word\tm4a_SongNumStart+1
.Lstandalone_sub_814EB1C:
\t.word\tsub_814EB1C+1
.Lstandalone_sub_814F9AC:
\t.word\tsub_814F9AC+1
.Lstandalone_sub_814E9F0:
\t.word\tsub_814E9F0+1
.Lstandalone_sub_814EAF0:
\t.word\tsub_814EAF0+1
.Lfe1:
\t.size\t sound_80006A2,.Lfe1-sound_80006A2
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_sound_80006A2.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsound_80006A2\n" not in text:
        raise SystemExit(f"expected sound_80006A2 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
