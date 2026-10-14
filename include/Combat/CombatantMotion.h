#ifndef COMBAT_COMBATANTMOTION_H
#define COMBAT_COMBATANTMOTION_H

#include <globaldefs.h>
#include "std_library_functions.h"

class Object3D;
struct Container02040c2c;
struct SpriteMotion02040c2c;
struct ModelEffect02040c2c;

struct Obj02040c2c {
    unsigned int flags;
    unsigned int idleDelay;
    char pad_08[0x4];
    Container02040c2c* settings;
    Object3D* attachment;
    SpriteMotion02040c2c* spriteMotion;
    ModelEffect02040c2c* modelMotion;
};

extern "C" void func_02040c2c(Obj02040c2c* entry, void* context,
                            int elapsedTicks, int movementTicks);

typedef char VerifyCombatantMotionSize[sizeof(Obj02040c2c) == 0x1c ? 1 : -1];
typedef char VerifyCombatantMotionSettingsOffset[offsetof(Obj02040c2c, settings) == 0xc ? 1 : -1];
typedef char VerifyCombatantMotionSpriteOffset[offsetof(Obj02040c2c, spriteMotion) == 0x14 ? 1 : -1];

#endif
