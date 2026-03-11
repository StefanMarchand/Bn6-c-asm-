#!/usr/bin/env python3
from pathlib import Path
import sys


EXPECTED = """\t.globl\tRunBattleObjectLogic
\t.type\t RunBattleObjectLogic,function
\t.thumb_func
RunBattleObjectLogic:
\tpush\t{r4, r5, r6, r7, lr}
\tsub\tsp, sp, #16
\tbl\tobject_Clear3RAMBytes_800371A
\tmov\tr0, #0
\tstr\tr0, [sp]
\tldr\tr7, .eBattleObjectsLinkedListStart_p
.processBattleObjectLoop:
\tldr\tr7, [r7, #4]
\tldr\tr0, .eBattleObjectsLinkedListSentinel_p
\tcmp\tr7, r0
\tbeq\t.reachedLinkedListSentinel
\tldr\tr0, .dword_200AF70_p
\tstr\tr7, [r0]
\tmov\tr5, #16
\tadd\tr5, r5, r7
\tldrb\tr4, [r5]
\tmov\tr6, r10
\tldr\tr6, [r6, #60]
\tldrb\tr0, [r6, #10]
\ttst\tr0, r0
\tbeq\t.loc_80031DC
\tmov\tr0, #4
\ttst\tr4, r0
\tbeq\t.doneCurrentBattleObject
.loc_80031DC:
\tbl\tbattle_isTimeStop
\tbeq\t.notInTimeStop
\tmov\tr0, #16
\ttst\tr4, r0
\tbeq\t.doneCurrentBattleObject
.notInTimeStop:
\tldrb\tr0, [r5, #2]
\tmov\tr1, #15
\tand\tr0, r1
\tlsl\tr0, r0, #2
\tldr\tr1, .BattleObjectFunctionJumptableTable_p
\tldr\tr0, [r0, r1]
\tldrb\tr1, [r5, #1]
\tlsl\tr1, r1, #2
\tldr\tr0, [r0, r1]
\tpush\t{r7}
\tmov\tlr, pc
\tbx\tr0
\tpop\t{r7}
.doneCurrentBattleObject:
\tbl\tobject_800372A
\tb\t.processBattleObjectLoop
.reachedLinkedListSentinel:
\tmov\tr0, #0
\tldr\tr1, .dword_200AF70_p
\tstr\tr0, [r1]
\tadd\tsp, sp, #16
\tpop\t{r4, r5, r6, r7, pc}
\t.balign 4, 0
.eBattleObjectsLinkedListStart_p:
\t.word\teBattleObjectsLinkedListStart
.eBattleObjectsLinkedListSentinel_p:
\t.word\teBattleObjectsLinkedListSentinel
.BattleObjectFunctionJumptableTable_p:
\t.word\t.BattleObjectFunctionJumptableTable
.BattleObjectFunctionJumptableTable:
\t.word\t0
\t.word\tT1BattleObjectJumptable
\t.word\t0
\t.word\tT3BattleObjectJumptable
\t.word\tT4BattleObjectJumptable
.dword_200AF70_p:
\t.word\teUnkBattleObjectLinkedList
.Lfe1:
\t.size\t RunBattleObjectLogic,.Lfe1-RunBattleObjectLogic
"""


def main() -> int:
    if len(sys.argv) != 2:
        raise SystemExit("usage: fix_agbcc_runbattleobjectlogic.py <path>")

    path = Path(sys.argv[1])
    text = path.read_text()
    if "\t.globl\tRunBattleObjectLogic\n" not in text:
        raise SystemExit(f"expected RunBattleObjectLogic in {path}")
    path.write_text(EXPECTED)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
