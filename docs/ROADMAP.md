# BN6 C + ASM Decomp & Tooling Roadmap

Owner: Stefan  
Status: Bootstrap

This document is a focused version of the broader `mmbn-bn6-tooling` plan, tailored to this repository.

## Vision

Turn this repo into the canonical **BN6 Falzar/Gregar decomp + build** project:

- Start from an ASM disassembly (dism-exe/bn6f and related work).
- Gradually move functionality into C while keeping a **byte-identical ROM**.
- Expose game data via well-typed structs and headers so external tools can interact safely.
- Keep everything predictable and scriptable so OpenClaw/LLM agents can assist.

Higher-level data specs and tools (JSON schemas, CLIs, GUI) will live in sibling repos but depend on the code and knowledge here.

## Phases for This Repo

### Phase 1 – Build & Compare

**Goal:** Reliable, automated builds of a clean BN6 ROM.

- Add the necessary build system (Makefile, linker script, tools) to:
  - Build `bn6f.gba` (Falzar) from source.
  - Verify the output via SHA1 against a known good dump.
- Introduce a machine-readable build status file:

  ```json
  {
    "lastBuild": "2026-03-10T00:00:00Z",
    "success": true,
    "sha1": "0676ecd4d58a976af3346caebb44b9b6489ad099",
    "errors": []
  }
  ```

  This allows agents to quickly check whether the repo currently builds cleanly.

### Phase 2 – C Integration

**Goal:** Allow writing C alongside ASM, with matching output.

- Add `src/` and `include/` directories.
- Configure the build system to:
  - Compile C files with appropriate GBA flags (e.g. `-mthumb -march=armv4t -O2`), using either devkitARM or an agbcc-style toolchain.
  - Link C object files together with the existing ASM objects.
- Confirm that adding an empty C file does not break the build or change the ROM hash.

### Phase 3 – Decomp Plan & Flow

**Goal:** Structured, agent-friendly task list for ASM→C conversion.

- Introduce `docs/DECOMP_GUIDE.md` explaining the standard process:
  - Choose a function (address + label).
  - Inspect it in Ghidra.
  - Write equivalent C in `src/`.
  - Build and compare.
  - Iterate until matching.
- Add `decomp_plan.json` with entries like:

  ```json
  {
    "files": [
      {
        "name": "battle_core",
        "priority": 1,
        "functions": [
          { "label": "InitBattle", "address": "08012345", "status": "todo" },
          { "label": "LoadChipData", "address": "08012678", "status": "todo" }
        ]
      }
    ]
  }
  ```

- Define standard statuses: `"todo"`, `"in_progress"`, `"matching"`, `"nonmatching"`.

This structure is designed so OpenClaw agents can pick tasks autonomously.

### Phase 4 – Structs & Headers

**Goal:** Make BN6 data structures explicit.

- As functions are decompiled, introduce headers under `include/` for:
  - Chips
  - Viruses/enemies
  - Encounters
  - NaviCust programs
  - Shops
  - Script/event types
- These will later drive JSON schema definitions in the `bn6-data-spec` repo.

### Phase 5 – Documentation Hooks

**Goal:** Keep the knowledge here usable elsewhere.

- Maintain minimal but precise docs under `docs/`:
  - `docs/data_layout.md` – overview of key tables and structures.
  - `docs/maps_and_scripts.md` – pointers to map/script formats as they are understood.
  - `docs/tooling_integration.md` – how external tools are expected to interact with this repo (headers, offsets, build artifacts).

## Automation

Long term, this repo should support:

- A `bn6-decomp-worker` agent that:
  - Reads `decomp_plan.json`.
  - Proposes C for a function.
  - Runs the build.
  - Updates status and commits.
- A CI workflow (GitHub Actions) that:
  - Builds on every push.
  - Verifies the ROM hash.

These automation pieces will be added once the basic build and structure are in place.

---

For a broader, cross-repo view of the MMBN BN6 tooling ecosystem (including JSON tooling and GUIs), see the workspace-level document `projects/mmbn-bn6-tooling.md` in Stefan's OpenClaw environment.
