```c
#include "global.h"
#include "asm01.h"

void sub_801FF18(void) {
    u32 r0, r1, r2, r3, r4, r5, r6, r7;
    
    r0 = gMenuData->unk2;
    if (r0 != 0) {
        r0--;
        gMenuData->unk2 = r0;
        return;
    }
    
    r4 = gMenuData->unk1;
    r5 = gMenuData->unk4;
    r6 = gMenuData->unk6;
    
    if (gMenuData->unk0 & 0x20) {
        r2 = gMenuData->unk8;
        if (r2 != 0) {
            r2--;
            gMenuData->unk8 = r2;
            return;
        }
        
        r7 = gMenuData->unkA;
        r0 = sub_801FFD6(r4, r5, r6, r7);
        r1 = r0 & 0xFF;
        
        switch (r1) {
            case 0:
                gMenuData->unk0 &= ~0x20;
                r0 = gMenuData->unk12;
                if (r0 != 0) {
                    r0--;
                    gMenuData->unk12 = r0;
                }
                break;
                
            case 1:
                r0 = gMenuData->unkC;
                if (r0 != 0) {
                    r0--;
                    gMenuData->unkC = r0;
                    if (r0 == 0) {
                        gMenuData->unk0 |= 0x40;
                    }
                }
                break;
                
            case 2:
                r0 = gMenuData->unkE;
                if (r0 != 0) {
                    r0--;
                    gMenuData->unkE = r0;
                }
                break;
                
            case 3:
                r0 = gMenuData->unk10;
                if (r0 != 0) {
                    r0--;
                    gMenuData->unk10 = r0;
                }
                break;
        }
        
        gMenuData->unk8 = 4;
        return;
    }
    
    r0 = sub_80200A0();
    r1 = r0 & 0xFF;
    
    if (r1 == 0) {
        return;
    }
    
    r2 = gMenuData->unk0;
    
    if (r1 == 1) {
        if (r2 & 1) {
            r3 = gMenuData->unk2;
            if (r3 != 0) {
                r3--;
                gMenuData->unk2 = r3;
                return;
            }
            
            r0 = gMenuData->unkC;
            if (r0 == 0) {
                gMenuData->unk0 |= 0x40;
            }
        }
    }
    
    if (r1 == 2) {
        if (r2 & 2) {
            r3 = gMenuData->unk2;
            if (r3 != 0) {
                r3--;
                gMenuData->unk2 = r3;
                return;
            }
            
            r0 = gMenuData->unkE;
            if (r0 == 0) {
                gMenuData->unk0 |= 0x40;
            }
        }
    }
    
    if (r1 == 3) {
        if (r2 & 4) {
            r3 = gMenuData->unk2;
            if (r3 != 0) {
                r3--;
                gMenuData->unk2 = r3;
                return;
            }
            
            r0 = gMenuData->unk10;
            if (r0 == 0) {
                gMenuData->unk0 |= 0x40;
            }
        }
    }
    
    if (r1 == 4) {
        if (r2 & 8) {
            r3 = gMenuData->unk2;
            if (r3 != 0) {
                r3--;
                gMenuData->unk2 = r3;
                return;
            }
            
            r0 = gMenuData->unk12;
            if (r0 == 0) {
                gMenuData->unk0 |= 0x40;
            }
        }
    }
}
```
