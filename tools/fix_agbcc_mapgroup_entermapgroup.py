#!/usr/bin/env python3
from pathlib import Path
import sys


FUNCTIONS = {
    "CentralTown_EnterMapGroup": {
        "warp_literal": "off_804E688",
        "warp_table": "off_804E38C",
        "sprite_state_literal": "off_804E68C",
        "state_literal": "off_804E690",
        "state_table": "off_804E9CC",
        "sprite_literal": "off_804E694",
        "sprite_table": "off_804E698",
        "spawn": "CentralTown_SpawnMapObjectsForMap",
    },
    "CyberAcademy_EnterMapGroup": {
        "warp_literal": "off_80526E4",
        "warp_table": "off_8052244",
        "sprite_state_literal": "off_80526E8",
        "state_literal": "off_80526EC",
        "state_table": "off_8052EE8",
        "sprite_literal": "off_80526F0",
        "sprite_table": "off_80526F4",
        "spawn": "CyberAcademy_SpawnMapObjectsForMap",
    },
    "SeasideTown_EnterMapGroup": {
        "warp_literal": "off_8059614",
        "warp_table": "off_8059294",
        "sprite_state_literal": "off_8059618",
        "state_literal": "off_805961C",
        "state_table": "off_8059DE8",
        "sprite_literal": "off_8059620",
        "sprite_table": "off_8059624",
        "spawn": "SeasideTown_SpawnMapObjectsForMap",
    },
    "GreenTown_EnterMapGroup": {
        "warp_literal": "off_805DF64",
        "warp_table": "off_805DD24",
        "sprite_state_literal": "off_805DF68",
        "state_literal": "off_805DF6C",
        "state_table": "off_805E1FC",
        "sprite_literal": "off_805DF70",
        "sprite_table": "off_805DF74",
        "spawn": "GreenTown_SpawnMapObjectsForMap",
    },
    "SkyTown_EnterMapGroup": {
        "warp_literal": "off_80603C8",
        "warp_table": "off_8060184",
        "sprite_state_literal": "off_80603CC",
        "state_literal": "off_80603D0",
        "state_table": "off_80606BC",
        "sprite_literal": "off_80603D4",
        "sprite_table": "off_80603D8",
        "spawn": "SkyTown_SpawnMapObjectsForMap",
    },
    "ExpoSite_EnterMapGroup": {
        "warp_literal": "off_8062B0C",
        "warp_table": "off_8062728",
        "sprite_state_literal": "off_8062B10",
        "state_literal": "off_8062B14",
        "state_table": "off_8063008",
        "sprite_literal": "off_8062B18",
        "sprite_table": "off_8062B1C",
        "spawn": "ExpoSite_SpawnMapObjectsForMap",
    },
}


EXPECTED = """\t.globl\t{func}
\t.type\t {func},function
\t.thumb_func
{func}:
\tpush\t{{r4-r7,lr}}
\tmov\tr7, r10
\tldr\tr0, {warp_literal}
\tldr\tr1, [r7, #20]
\tldrb\tr2, [r5, #5]
\tlsl\tr4, r2, #2
\tadd\tr0, r0, r4
\tldr\tr0, [r0]
\tstr\tr0, [r1, #20]
\tldrb\tr0, [r5, #4]
\tldrb\tr1, [r5, #5]
\tbl\tinitMapTilesState_803037c
\tldrb\tr0, [r5, #4]
\tldrb\tr1, [r5, #5]
\tbl\tdecompressCoordEventData_8030aa4
\tldr\tr0, [r5, #36]
\tldr\tr1, [r5, #40]
\tldr\tr2, [r5, #44]
\tldrb\tr3, [r5, #4]
\tldrb\tr4, [r5, #5]
\tbl\tcamera_init_802FF4C
\tbl\tdecompAndCopyMapTiles_8030472
\tldr\tr0, {sprite_state_literal}
\tbl\tinitUncompSpriteState_80028d4
\tldrb\tr1, [r5, #5]
\tlsl\tr1, r1, #2
\tldr\tr0, {sprite_literal}
\tldr\tr0, [r0, r1]
\tbl\tuncompSprite_8002906
\tbl\tchatbox_uncompMapTextArchives_803FD08
\tbl\t{spawn}
\tldr\tr0, {state_literal}
\tldrb\tr1, [r5, #5]
\tlsl\tr1, r1, #2
\tldr\tr0, [r0, r1]
\tstr\tr0, [r5, #100]
\tpop\t{{r4-r7,pc}}
\t.balign 4, 0
{warp_literal}:
\t.word\t{warp_table}
{sprite_state_literal}:
\t.word\tunk_2037800
{state_literal}:
\t.word\t{state_table}
{sprite_literal}:
\t.word\t{sprite_table}
.Lfe1:
\t.size\t {func},.Lfe1-{func}
"""


def main() -> int:
    if len(sys.argv) != 3:
        raise SystemExit("usage: fix_agbcc_mapgroup_entermapgroup.py <path> <func>")

    path = Path(sys.argv[1])
    func = sys.argv[2]
    if func not in FUNCTIONS:
        raise SystemExit(f"unsupported function: {func}")

    text = path.read_text()
    if f"\t.globl\t{func}\n" not in text:
        raise SystemExit(f"expected {func} in {path}")

    path.write_text(EXPECTED.format(func=func, **FUNCTIONS[func]))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
