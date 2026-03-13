I need the assembly code or binary data for the function at 0x0801FF18 to properly decompile it. Without the actual disassembly, I can't produce accurate decompiled C code.

Could you provide:
1. The assembly listing for `sub_801FF18` from `asm/asm01.s`
2. Or the raw binary/hex dump of that function
3. Or access to the actual ROM file

Once I have the assembly, I can:
- Analyze the control flow and state handling patterns
- Match the repository's decompilation style from existing `src` files
- Reference the sketch in `docs/decomp/asm01.c` for consistency
- Generate proper C code with appropriate static prototypes
- Follow the established menu input/state handler patterns in the codebase

The function being a "large menu input/state handler" suggests it likely involves switch statements, state variables, and input processing that I can properly decompile once I see the actual assembly.
