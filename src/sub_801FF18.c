```c
#include "global.h"
#include "menu.h"

static void sub_801FF18(void) {
    u32 state = gMenuState;
    u32 input = gButtonPress;

    switch (state) {
        case 0:
            if (input & A_BUTTON) {
                gMenuState = 1;
            } else if (input & B_BUTTON) {
                gMenuState = 2;
            }
            break;
        case 1:
            if (input & A_BUTTON) {
                gMenuState = 3;
            } else if (input & B_BUTTON) {
                gMenuState = 0;
            }
            break;
        case 2:
            if (input & A_BUTTON) {
                gMenuState = 4;
            } else if (input & B_BUTTON) {
                gMenuState = 0;
            }
            break;
        case 3:
            if (input & A_BUTTON) {
                gMenuState = 5;
            } else if (input & B_BUTTON) {
                gMenuState = 1;
            }
            break;
        case 4:
            if (input & A_BUTTON) {
                gMenuState = 6;
            } else if (input & B_BUTTON) {
                gMenuState = 2;
            }
            break;
        case 5:
            if (input & A_BUTTON) {
                gMenuState = 7;
            } else if (input & B_BUTTON) {
                gMenuState = 3;
            }
            break;
        case 6:
            if (input & A_BUTTON) {
                gMenuState = 8;
            } else if (input & B_BUTTON) {
                gMenuState = 4;
            }
            break;
        case 7:
            if (input & A_BUTTON) {
                gMenuState = 9;
            } else if (input & B_BUTTON) {
                gMenuState = 5;
            }
            break;
        case 8:
            if (input & A_BUTTON) {
                gMenuState = 10;
            } else if (input & B_BUTTON) {
                gMenuState = 6;
            }
            break;
        case 9:
            if (input & A_BUTTON) {
                gMenuState = 11;
            } else if (input & B_BUTTON) {
                gMenuState = 7;
            }
            break;
        case 10:
            if (input & A_BUTTON) {
                gMenuState = 12;
            } else if (input & B_BUTTON) {
                gMenuState = 8;
            }
            break;
        default:
            break;
    }
}
```
