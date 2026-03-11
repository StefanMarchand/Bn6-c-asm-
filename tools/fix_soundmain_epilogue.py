#!/usr/bin/env python3
from pathlib import Path
import sys


def main() -> int:
    path = Path(sys.argv[1])
    text = path.read_text()
    original = "\tpop\t{r1}\n\tbx\tr1\n"
    replacement = "\tpop\t{pc}\n"
    if original not in text:
        raise SystemExit(f"expected wrapper epilogue not found in {path}")
    text = text.replace(original, replacement, 1)

    start = text.find("\t.globl\tcall_m4aSoundMain\n")
    end_marker = "\t.size\t call_m4aSoundMain,.Lfe1-call_m4aSoundMain\n"
    end = text.find(end_marker, start)
    if start == -1 or end == -1:
        raise SystemExit(f"expected wrapper body not found in {path}")
    end += len(end_marker)
    path.write_text(text[start:end])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
