# BN6 C + ASM Decomp & Tooling

This repo is the starting point for a **Mega Man Battle Network 6** (BN6) mixed C + ASM project and tooling ecosystem. The long‑term goal is to make BN6 modding as accessible as modern Pokémon ROM hacking:

- Decompile key parts of BN6 into readable C while keeping a byte‑perfect ROM build.
- Define machine‑readable JSON schemas for chips, enemies, encounters, shops, NaviCust, text, etc.
- Provide CLI tools (`bn6-extract`, `bn6-apply`) so mods can be described and applied via JSON.
- Eventually build a GUI/IDE ("EXE Studio") on top of those tools.

This repo will hold the **game code and build system** (ASM + C). Supporting specs and tools may live in sibling repos but are designed to integrate cleanly.

For the full roadmap, see [`docs/ROADMAP.md`](docs/ROADMAP.md) (to be added soon).
