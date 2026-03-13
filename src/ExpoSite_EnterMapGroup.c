```c
#include "global.h"

static void ExpoSite_EnterMapGroup_Sub(void);

static void ExpoSite_EnterMapGroup_Sub(void) {
    u32 i;
    u32 j;
    
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            gUnknown_0200A000[i * 8 + j] = 0;
        }
    }
    
    gUnknown_02009800 = 0;
    gUnknown_02009804 = 0;
    gUnknown_02009808 = 0;
    gUnknown_0200980C = 0;
    gUnknown_02009810 = 0;
    gUnknown_02009814 = 0;
    gUnknown_02009818 = 0;
    gUnknown_0200981C = 0;
    gUnknown_02009820 = 0;
    gUnknown_02009824 = 0;
    gUnknown_02009828 = 0;
    gUnknown_0200982C = 0;
    gUnknown_02009830 = 0;
    gUnknown_02009834 = 0;
    gUnknown_02009838 = 0;
    gUnknown_0200983C = 0;
}

void ExpoSite_EnterMapGroup(void) {
    ExpoSite_EnterMapGroup_Sub();
    
    gMapGroup = 0x9;
    gMapNumber = 0x0;
    gAreaID = 0x9;
    
    gUnknown_03005CB0 = 0;
    gUnknown_03005CB4 = 0;
    
    sub_080308B0();
    sub_080308E0();
    
    gUnknown_03005000 = 1;
    gUnknown_03005004 = 0;
    
    gUnknown_02009840 = 0;
    gUnknown_02009844 = 0;
    gUnknown_02009848 = 0;
    gUnknown_0200984C = 0;
    gUnknown_02009850 = 0;
    gUnknown_02009854 = 0;
    gUnknown_02009858 = 0;
    gUnknown_0200985C = 0;
    
    gUnknown_02009860 = 0;
    gUnknown_02009864 = 0;
    gUnknown_02009868 = 0;
    gUnknown_0200986C = 0;
    
    gUnknown_02009870 = 0;
    gUnknown_02009874 = 0;
    gUnknown_02009878 = 0;
    gUnknown_0200987C = 0;
}
```
