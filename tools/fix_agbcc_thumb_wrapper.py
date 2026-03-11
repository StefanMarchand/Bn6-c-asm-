#!/usr/bin/env python3
from pathlib import Path
import sys


def main() -> int:
    if len(sys.argv) != 3:
        raise SystemExit("usage: fix_agbcc_thumb_wrapper.py <path> <symbol>")

    path = Path(sys.argv[1])
    symbol = sys.argv[2]
    text = path.read_text()

    original = "\tpop\t{r1}\n\tbx\tr1\n"
    replacement = "\tpop\t{pc}\n"
    if original not in text:
        raise SystemExit(f"expected wrapper epilogue not found in {path}")
    text = text.replace(original, replacement, 1)

    start = text.find(f"\t.globl\t{symbol}\n")
    end_marker = f"\t.size\t {symbol},.Lfe1-{symbol}\n"
    end = text.find(end_marker, start)
    if start == -1 or end == -1:
        raise SystemExit(f"expected wrapper body not found for {symbol} in {path}")
    end += len(end_marker)
    path.write_text(text[start:end])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
