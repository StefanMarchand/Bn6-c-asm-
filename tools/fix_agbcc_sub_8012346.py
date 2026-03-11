#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tsub_8012346
\t.type\t sub_8012346,function
\t.thumb_func
sub_8012346:
\tpush\t{lr}
\tldr\tr0, .Lstandalone_pool
\tbl\tloc_80126EA
\tpop\t{pc}
\t.align\t2, 0
.Lstandalone_pool:
\t.word\toff_80126D0
.Lfe1:
\t.size\t sub_8012346,.Lfe1-sub_8012346
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_sub_8012346.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tsub_8012346\n" not in text:
        raise SystemExit(f"expected sub_8012346 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
