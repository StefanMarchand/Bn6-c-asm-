#include "asm03_0_beast_helpers.h"

int sub_8026450(int panelX, int panelY, const signed char *offsets)
{
    int maxX;
    int direction;

    maxX = panelX;
    direction = object_getFrontDirection();
    while (1) {
        int candidateX;
        int candidateY;

        if (*offsets == 0x7F) {
            return 0;
        }

        candidateX = (*offsets * direction) + panelX;
        if (candidateX >= 0 && candidateX <= 6 && (candidateX * direction) <= (maxX * direction)) {
            candidateY = offsets[1] + panelY;
            if (candidateY >= 0 && candidateY <= 3 && sub_800E680(candidateX, candidateY) != 0) {
                return candidateX;
            }
        }

        offsets += 2;
    }
}

int sub_80264A8(int panelX, int panelY, const signed char *offsets)
{
    int maxX;
    int direction;

    maxX = panelX;
    direction = object_getFrontDirection();
    while (1) {
        int candidateX;
        int candidateY;

        if (*offsets == 0x7F) {
            return 0;
        }

        candidateX = (*offsets * direction) + panelX;
        if (candidateX >= 0 && candidateX <= 6 && (candidateX * direction) <= (maxX * direction)) {
            candidateY = offsets[1] + panelY;
            if (candidateY >= 0 && candidateY <= 3 && sub_800E680(candidateX, candidateY) != 0
                && sub_8026510(candidateX, candidateY, maxX) != 0) {
                return candidateX;
            }
        }

        offsets += 2;
    }
}
