#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\t{func}
\t.type\t {func},function
\t.thumb_func
{func}:
\tpush\t{{lr}}
\tmov\tr0, r10
\tldr\tr0, [r0, #60]
\tldrb\tr0, [r0, #5]
\tlsl\tr0, r0, #2
\tldr\tr1, {literal}
\tldr\tr0, [r1, r0]
\tbl\tSpawnObjectsFromList
\tpop\t{{pc}}
\t.balign 4, 0
{literal}:
\t.word\t{table}
.Lfe1:
\t.size\t {func},.Lfe1-{func}
"""


def main() -> int:
    if len(sys.argv) != 5:
        raise SystemExit("usage: fix_agbcc_mapgroup_spawn.py <path> <func> <literal> <table>")

    path = Path(sys.argv[1])
    func = sys.argv[2]
    literal = sys.argv[3]
    table = sys.argv[4]
    text = path.read_text()
    if f"\t.globl\t{func}\n" not in text:
        raise SystemExit(f"expected {func} in {path}")
    path.write_text(EXPECTED.format(func=func, literal=literal, table=table))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
