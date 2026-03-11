#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tzeroFill_80007B2
\t.type\t zeroFill_80007B2,function
\t.thumb_func
zeroFill_80007B2:
\tpush\t{lr}
\tldr\tr0, dword_200A490_p
\tldr\tr1, numWords
\tbl\tZeroFillByWord
\tpop\t{pc}
.Lfe1:
\t.size\t zeroFill_80007B2,.Lfe1-zeroFill_80007B2
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_zeroFill_80007B2_rominc.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tzeroFill_80007B2\n" not in text:
        raise SystemExit(f"expected zeroFill_80007B2 in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
