static void sub_801FF18(void)
{
    u16 input = gJoypad.held;
    u16 pressed = gJoypad.pressed;

    switch (gMenuState) {
        case 0:
            if (pressed & A_BUTTON) {
                gMenuState = 1;
                sub_801FFD6();
            }
            if (pressed & B_BUTTON) {
                gMenuState = 2;
                sub_801FFD6();
            }
            if (pressed & START_BUTTON) {
                gMenuState = 3;
                sub_801FFD6();
            }
            if (pressed & SELECT_BUTTON) {
                gMenuState = 4;
                sub_801FFD6();
            }
            break;
        case 1:
            if (pressed & A_BUTTON) {
                gMenuState = 5;
                sub_801FFD6();
            }
            if (pressed & B_BUTTON) {
                gMenuState = 0;
                sub_801FFD6();
            }
            if (input & DPAD_UP) {
                gMenuState = 6;
                sub_801FFD6();
            }
            if (input & DPAD_DOWN) {
                gMenuState = 7;
                sub_801FFD6();
            }
            break;
        case 2:
            if (pressed & A_BUTTON) {
                gMenuState = 8;
                sub_801FFD6();
            }
            if (pressed & B_BUTTON) {
                gMenuState = 0;
                sub_801FFD6();
            }
            if (input & DPAD_LEFT) {
                gMenuState = 9;
                sub_801FFD6();
            }
            if (input & DPAD_RIGHT) {
                gMenuState = 10;
                sub_801FFD6();
            }
            break;
        case 3:
            if (pressed & A_BUTTON) {
                gMenuState = 11;
                sub_801FFD6();
            }
            if (pressed & B_BUTTON) {
                gMenuState = 0;
                sub_801FFD6();
            }
            if (input & DPAD_UP) {
                gMenuState = 12;
                sub_801FFD6();
            }
            if (input & DPAD_DOWN) {
                gMenuState = 13;
                sub_801FFD6();
            }
            break;
        case 4:
            if (pressed & A_BUTTON) {
                gMenuState = 14;
                sub_801FFD6();
            }
            if (pressed & B_BUTTON) {
                gMenuState = 0;
                sub_801FFD6();
            }
            if (input & DPAD_LEFT) {
                gMenuState = 15;
                sub_801FFD6();
            }
            if (input & DPAD_RIGHT) {
                gMenuState = 16;
                sub_801FFD6();
            }
            break;
        case 5:
            if (pressed & A_BUTTON) {
                gMenuState = 17;
                sub_801FFD6();
            }
            if (pressed & B_BUTTON) {
                gMenuState = 1;
                sub_801FFD6();
            }
            break;
        case 6:
            if (pressed & A_BUTTON) {
                gMenuState = 18;
                sub_801FFD6();
            }
            if (pressed & B_BUTTON) {
                gMenuState = 1;
                sub_801FFD6();
            }
            break;
        case 7:
            if (pressed & A_BUTTON) {
                gMenuState = 19;
                sub_801FFD6();
            }
            if (pressed & B_BUTTON) {
                gMenuState = 1;
                sub_801FFD6();
            }
            break;
        case 8:
            if (pressed & A_BUTTON) {
                gMenuState = 20;
                sub_801FFD6();
            }
            if (pressed & B_BUTTON) {
                gMenuState = 2;
                sub_801FFD6();
            }
            break;
        case 9:
            if (pressed & A_BUTTON) {
                gMenuState = 21;
                sub_801FFD6();
            }
            if (pressed & B_BUTTON) {
                gMenuState = 2;
                sub_801FFD6();
            }
            break;
        case 10:
            if (pressed & A_BUTTON) {
                gMenuState = 22;
                sub_801FFD6();
            }
            if (pressed & B_BUTTON) {
                gMenuState = 2;
                sub_801FFD6();
            }
            break;
        default:
            gMenuState = 0;
            sub_801FFD6();
            break;
    }
}
