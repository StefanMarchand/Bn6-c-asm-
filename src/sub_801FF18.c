```c
#include "global.h"

static s32 sMenuState;
static s32 sMenuSelection;
static s32 sSubMenuPos;
static s32 sFrameCounter;

void sub_801FF18(void) {
    u16 input = gKeyState;

    sFrameCounter++;

    switch (sMenuState) {
        case 0:
            // Main menu state
            if (input & KEY_DOWN) {
                sMenuSelection++;
                if (sMenuSelection >= 4) {
                    sMenuSelection = 0;
                }
                sFrameCounter = 0;
            }
            if (input & KEY_UP) {
                sMenuSelection--;
                if (sMenuSelection < 0) {
                    sMenuSelection = 3;
                }
                sFrameCounter = 0;
            }
            if (input & KEY_A) {
                sSubMenuPos = 0;
                sMenuState = 1;
                sFrameCounter = 0;
            }
            if (input & KEY_B) {
                sMenuState = 3;
                sFrameCounter = 0;
            }
            break;

        case 1:
            // Submenu navigation state
            if (input & KEY_DOWN) {
                sSubMenuPos++;
                if (sSubMenuPos >= 3) {
                    sSubMenuPos = 0;
                }
                sFrameCounter = 0;
            }
            if (input & KEY_UP) {
                sSubMenuPos--;
                if (sSubMenuPos < 0) {
                    sSubMenuPos = 2;
                }
                sFrameCounter = 0;
            }
            if (input & KEY_A) {
                sMenuState = 2;
                sFrameCounter = 0;
            }
            if (input & KEY_B) {
                sMenuState = 0;
                sFrameCounter = 0;
            }
            break;

        case 2:
            // Action confirmation state
            if (input & KEY_A) {
                // Execute selected action
                if (sMenuSelection == 0 && sSubMenuPos == 0) {
                    // Action 0-0
                } else if (sMenuSelection == 0 && sSubMenuPos == 1) {
                    // Action 0-1
                } else if (sMenuSelection == 1 && sSubMenuPos == 0) {
                    // Action 1-0
                }
                sMenuState = 0;
                sFrameCounter = 0;
            }
            if (input & KEY_B) {
                sMenuState = 1;
                sFrameCounter = 0;
            }
            break;

        case 3:
            // Exit state
            if (sFrameCounter > 15) {
                // Trigger exit sequence
                sMenuState = 0;
            }
            break;

        default:
            sMenuState = 0;
            sMenuSelection = 0;
            sSubMenuPos = 0;
            sFrameCounter = 0;
            break;
    }

    // Additional state-dependent logic
    if (sMenuState == 0) {
        // Update main menu display
    } else if (sMenuState == 1) {
        // Update submenu display
    } else if (sMenuState == 2) {
        // Update confirmation display
    }

    // Handle input repeat for navigation
    if (sFrameCounter > 20) {
        if (input & (KEY_DOWN | KEY_UP)) {
            sFrameCounter = 15;
        }
    }
}
```
