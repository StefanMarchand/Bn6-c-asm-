#!/usr/bin/env python3
from pathlib import Path
import sys


ROMINC = Path(__file__).resolve().parents[1] / "src" / "chips" / "asm02_chip_pack_rominc.s"


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_asm02_chip_pack_rominc.py <path>")

    path = Path(sys.argv[1])
    path.write_text(ROMINC.read_text())
    return 0


if __name__ == "__main__":
    raise SystemExit(main())