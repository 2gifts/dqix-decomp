#pragma once

#include "World/Object3D.h"

// Shared prefix of the field actors initialized by func_02076a8c and updated
// by TickActorAndDispatchPhase02076b58. The type name is part of the existing
// dispatcher and member-function-table ABI.
struct Obj02076b58 {
    Object3D object;
    unsigned char unknown_ac[0x130 - 0xac];
    int phase;
    int unknown_134;
    unsigned char unknown_138;
    unsigned char unknown_139;
    unsigned char unknown_13a;
    unsigned char unknown_13b;
    unsigned char unknown_13c;
    unsigned char unknown_13d[3];
    int unknown_140;
    int unknown_144;
    int unknown_148;
    int elapsedTime;
    int tickCount;
    int phaseElapsedTime;
};

typedef char VerifyFieldActorPhaseOffset[offsetof(Obj02076b58, phase) == 0x130 ? 1 : -1];
typedef char VerifyFieldActorElapsedOffset[offsetof(Obj02076b58, elapsedTime) == 0x14c ? 1 : -1];
typedef char VerifyFieldActorTickOffset[offsetof(Obj02076b58, tickCount) == 0x150 ? 1 : -1];
typedef char VerifyFieldActorPhaseTimeOffset[offsetof(Obj02076b58, phaseElapsedTime) == 0x154 ? 1 : -1];
typedef char VerifyFieldActorPrefixSize[sizeof(Obj02076b58) == 0x158 ? 1 : -1];

void TickActorAndDispatchPhase02076b58(Obj02076b58* actor);
