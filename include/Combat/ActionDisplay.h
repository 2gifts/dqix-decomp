#pragma once

#include "System/Matrix.h"
#include "System/Memory.h"
#include <globaldefs.h>

struct CombatActionPosition {
    Vector3i position;
    unsigned char elementId;
    unsigned char palette;
    unsigned char type;
    signed char variant;
    unsigned char group;
    unsigned char flag11;
    unsigned char flag12;
    unsigned char flag13;
    unsigned char combatantId;
    unsigned char unknown15[3];

    inline CombatActionPosition() {
        VectorizedMemset(this, 0, sizeof(CombatActionPosition));
        variant     = -1;
        combatantId = 0xff;
    }
};

static inline int IsNonCombatantAction(unsigned char type) {
    return type >= 0x74;
}

extern int data_020e70f0[][4][2];
extern int data_020e70f4[][4][2];

extern "C" {
int func_020236dc(CombatActionPosition *entries, unsigned char *groups, Vector3i *position);
void func_02023b5c(void *receiver, int tileX, int tileY, int xOffset, int yOffset, unsigned char flag);
void func_02023d84(void *receiver, CombatActionPosition *entries, int count, int tileX, int tileY, int xOffset, int yOffset,
                   int flags);
void func_02024e78(void *receiver);
void func_020251bc(void *receiver);
}
