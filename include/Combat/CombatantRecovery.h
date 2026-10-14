#pragma once

#include "GameState/GameState.h"

struct CombatantStatus {
    unsigned int flags;
    unsigned short hp;
    unsigned short mp;
    unsigned char status;
    unsigned int GetFlags() const { return flags; }
    unsigned short GetMP() const { return mp; }
    unsigned char GetStatus() const { return status; }
};

// The recovery flag is in the combatant extension, beyond the common GameObject.
// Keep the common base size unchanged: several other object types embed it.
struct CombatantRecovery : GameObject {
#if defined(jpn)
    unsigned char unknown13c[0x180 - 0x13c];
#else
    unsigned char unknown13c[0x18c - 0x13c];
#endif
    unsigned int recoveryFlags;
};

extern "C" void func_02048150(GameObject* object, int hp, int notify);
void ClearFieldBit02053fe4(GameObject* object, int hp, int notify);

typedef char CommonGameObjectSizeCheck[sizeof(GameObject) == 0x13c ? 1 : -1];
typedef char CombatantStatusHpCheck[offsetof(CombatantStatus, hp) == 4 ? 1 : -1];
typedef char CombatantStatusMpCheck[offsetof(CombatantStatus, mp) == 6 ? 1 : -1];
typedef char CombatantStatusByteCheck[offsetof(CombatantStatus, status) == 8 ? 1 : -1];
typedef char CommonGameObjectStatusCheck[offsetof(GameObject, combatFields_.savedState_130_) == 0x130 ? 1 : -1];
typedef char CommonGameObjectStatsCheck[offsetof(GameObject, baseStats_) == 0x134 ? 1 : -1];
#if defined(jpn)
typedef char CombatantRecoveryFlagCheck[offsetof(CombatantRecovery, recoveryFlags) == 0x180 ? 1 : -1];
#else
typedef char CombatantRecoveryFlagCheck[offsetof(CombatantRecovery, recoveryFlags) == 0x18c ? 1 : -1];
#endif
