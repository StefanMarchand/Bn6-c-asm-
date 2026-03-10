# BN6 Decomp Guide (ASM → C Workflow)

This repo is intended to evolve into a mixed **C + ASM** decompilation of Mega Man Battle Network 6 (Falzar/Gregar).

At the moment, the build is only a placeholder, but the workflow below describes how future work should proceed once the real disassembly is in place.

## Goals

- Keep a **byte-identical** ROM when replacing ASM functions with C.
- Make tasks predictable and easy for both humans and agents.
- Track progress in machine-readable JSON (`decomp_plan.json`, `build_status.json`).

## High-Level Flow

For each function we want to decompile:

1. **Pick a function** from `decomp_plan.json` with `"status": "todo"`.
2. **Study the ASM** in the relevant file (once the disassembly is imported).
3. **Use a decompiler** (e.g., Ghidra) to get a high-level view.
4. **Write equivalent C** in `src/` and add any needed structs/types in `include/`.
5. **Build and compare** the resulting ROM with the reference.
6. **Iterate** on the C until the output matches (or is at least well-understood).
7. **Update `decomp_plan.json`** for that function:
   - `"status": "matching"` when you have a confirmed match.
   - `"status": "nonmatching"` if you land a useful but not-perfect version.

## Files & Conventions

- `asm/` – original ASM files (once imported).
- `src/` – new C files.
- `include/` – headers and shared structs.
- `Makefile` – build system; later will compile both ASM and C into a ROM.
- `build_status.json` – machine-readable build metadata.
- `decomp_plan.json` – list of functions and their status.

### `build_status.json` format

Example after a successful build:

```json
{
  "lastBuild": "2026-03-10T21:50:00Z",
  "success": true,
  "sha1": "0676ecd4d58a976af3346caebb44b9b6489ad099",
  "errors": []
}
```

### `decomp_plan.json` format

Example structure:

```json
{
  "files": [
    {
      "name": "battle_core",
      "priority": 1,
      "functions": [
        {
          "label": "InitBattle",
          "address": "08012345",
          "status": "todo",
          "notes": "Initial battle setup."
        },
        {
          "label": "LoadChipData",
          "address": "08012678",
          "status": "todo",
          "notes": "Loads chip stats into memory."
        }
      ]
    }
  ]
}
```

Allowed `status` values:

- `"todo"` – not started.
- `"in_progress"` – currently being worked on.
- `"matching"` – C version matches original output.
- `"nonmatching"` – C is useful but does not match bit-for-bit.

## Recommended Agent Workflow

For an OpenClaw/Codex-style coding agent:

1. Read `docs/DECOMP_GUIDE.md` and `decomp_plan.json`.
2. Select a `"todo"` function based on priority.
3. Implement the ASM → C conversion in `src/` + `include/`.
4. Run `make` and check `build_status.json`.
5. Update the function entry in `decomp_plan.json`.
6. Commit with a message like:
   - `decomp: InitBattle matching`
   - `decomp: LoadChipData nonmatching (needs review)`

This guide will be refined once the real BN6 disassembly is imported.
