// asm00_0_mem_utils.c
// Memory utility functions: ZeroFill and Copy in byte/halfword/word/eight-word variants
//
// All 8 functions are implemented as hand-matched assembly in _rominc.s files.
// This C file exists for documentation and build system integration.

#include "asm00_0_sound.h"

// ZeroFillByByte - fill memory with zero, byte by byte (backwards)
// r0 = dest, r1 = num_bytes
// Simple loop: sub r1, #1 / strb r2, [r0,r1] / bne

// ZeroFillByHalfword - fill memory with zero, halfword by halfword
// Uses CpuSet with fill+halfword mask 0x1000000

// ZeroFillByWord - fill memory with zero, word by word
// Uses CpuSet with fill+word mask 0x5000000

// ZeroFillByEightWords - fill memory with zero, 8-word blocks
// Uses CpuFastSet with fill mask 0x1000000

// CopyBytes - copy memory byte by byte (backwards)
// r0 = src, r1 = dest, r2 = num_bytes

// CopyHalfwords - copy memory halfword by halfword
// Uses CpuSet with copy+halfword mask 0x0

// CopyWords - copy memory word by word
// Uses CpuSet with copy+word mask 0x4000000

// CopyByEightWords - copy memory in 8-word blocks
// Uses CpuFastSet with copy mask 0x0
