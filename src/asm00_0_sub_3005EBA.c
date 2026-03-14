#include "asm00_0_sub_3005EBA.h"

// EWRAM function: Fill a rectangle in a background tilemap.
// The BG tilemap is 32x32 tiles (64 bytes per row, 2 bytes per tile).
// Coordinates wrap/clip: only tiles within 0-31 in both X and Y are written.
//
// Registers (ARM calling convention):
//   r0 = startX (saved to stack for reuse)
//   r1 = startY
//   r2 = bgNum (shifted left by 11 to get BG offset: 32*32*2 = 2048)
//   r3 = tileVal (16-bit value to write)
//   [stack+0] = endX (exclusive)
//   [stack+4] = endY (exclusive)
//
// The function iterates Y outer, X inner, checking (X|Y) & ~0x1F to skip
// out-of-bounds tiles efficiently.
void sub_3005EBA(int startX, int startY, int bgNum, int tileVal, int endX, int endY)
{
    // r10 (gToolkit) -> offset 0x28 = iBGTileIdBlocks_Ptr
    // bgNum << 11 selects which BG (each BG tilemap is 32*32*2 = 2048 bytes)
    unsigned short *bgBase = (unsigned short *)((char *)gToolkit->iBGTileIdBlocks_Ptr + (bgNum << 11));

    // Compute the exclusive end coordinates
    int xEnd = endX + startX;
    int yEnd = endY + startY;

    // Iterate over the rectangle
    for (int y = startY; y < yEnd; y++) {
        // Inner loop starts at startX each row
        for (int x = startX; x < xEnd; x++) {
            // Check if both X and Y are within [0, 31]
            // If (x | y) has any bit set at position 5 or above, one is out of range
            if ((unsigned int)(x | y) < 32) {
                // Tilemap offset: row*64 + col*2, or equivalently (y<<6) + (x<<1)
                // Since bgBase is unsigned short*, we use (y<<5) + x
                bgBase[(y << 5) + x] = (unsigned short)tileVal;
            }
        }
    }
}
