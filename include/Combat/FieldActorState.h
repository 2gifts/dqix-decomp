#pragma once

#include "Combat/ObjectStateInitialization.h"

// Shared prefix of the field actors initialized by func_02076a8c and updated
// by TickActorAndDispatchPhase02076b58. The type name is part of the existing
// dispatcher and member-function-table ABI.
struct Obj02076b58 {
    ObjectStatePrefix base;
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

struct ShadowInfo;
struct Attributes02078998;

// Extent initialized by func_02076a8c. This does not assert the full actor size.
struct FieldMonsterState {
    Obj02076b58 actor;
    Vector3fix targetPosition;
    unsigned short unknown164;
    unsigned short combatantId;
    unsigned short unknown168;
    unsigned short unknown16a;
    unsigned char unknown16c[4];
    fix32_t height;
    short rise;
    unsigned short unknown176;
    unsigned char unknown178[2];
    unsigned char rising;
    unsigned char unknown17b;
    unsigned char unknown17c;
    unsigned char flags;
    unsigned char unknown17e;
    unsigned char unknown17f;
    ShadowInfo* shadowInfo;
    Attributes02078998* attributes;
};

typedef char FieldMonsterTargetOffsetCheck[offsetof(FieldMonsterState, targetPosition) == 0x158 ? 1 : -1];
typedef char FieldMonsterFlagsOffsetCheck[offsetof(FieldMonsterState, flags) == 0x17d ? 1 : -1];
typedef char FieldMonsterShadowOffsetCheck[offsetof(FieldMonsterState, shadowInfo) == 0x180 ? 1 : -1];
typedef char FieldMonsterAttributesOffsetCheck[offsetof(FieldMonsterState, attributes) == 0x184 ? 1 : -1];
typedef char FieldMonsterInitializedExtentCheck[sizeof(FieldMonsterState) == 0x188 ? 1 : -1];

extern "C" void func_02076a8c(FieldMonsterState* monster);
