```c
#include "global.h"
#include "menu.h"
#include "input.h"

static void sub_801FF18(void) {
    u8 *menuState = &gMenuState;
    u32 input = GetMenuInput();
    
    switch (*menuState) {
        case 0:
            if (input & A_BUTTON) {
                *menuState = 1;
                PlaySoundEffect(0);
            }
            break;
            
        case 1:
            if (input & B_BUTTON) {
                *menuState = 0;
                PlaySoundEffect(1);
            }
            else if (input & A_BUTTON) {
                *menuState = 2;
                PlaySoundEffect(0);
            }
            break;
            
        case 2:
            if (input & B_BUTTON) {
                *menuState = 1;
                PlaySoundEffect(1);
            }
            else if (input & DPAD_LEFT) {
                // Handle left navigation
            }
            else if (input & DPAD_RIGHT) {
                // Handle right navigation
            }
            break;
            
        case 3:
            // Additional state handling
            break;
    }
}
```
