#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
int IsFlag10088Set_02010088(struct S_10088* obj);

struct FlagObj_021da9b0;
int IsFlagBit8Set_021da9b0(struct FlagObj_021da9b0* obj);

struct FlagObj_021da9c8;
int IsFlagBit19Set_021da9c8(struct FlagObj_021da9c8* obj);

struct FlagObj_021de25c;
int IsFlagBit5Set_021de25c(struct FlagObj_021de25c* obj);

int CheckFlag0x14Bit0x10Set_020882f8(unsigned char* obj);
unsigned short GetTableValue_0202053c(void* obj);

struct StatsInner_021eb1ec {
    char unk[0x3a];
    unsigned char byte0x3a;
    unsigned char low3:3;
    unsigned char bit3:1;
    unsigned char high4:4;
};

// USA: func_ov024_021eb1ec
ARM int CheckAndClearOrEvaluateFlags_021eb1ec(void* unused, int combatantId) {
    GameState* battle = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(battle, combatantId);
    if (combatant == NULL) {
        return 0;
    }
    if (((struct StatsInner_021eb1ec*)combatant->currentStats_)->byte0x3a != 0) {
        ((struct StatsInner_021eb1ec*)combatant->currentStats_)->byte0x3a = 0;
        return 0;
    }
    if (GetTableValue_0202053c(combatant) < 10) {
        return 0;
    }
    if (IsFlagBit19Set_021da9c8((struct FlagObj_021da9c8*)combatant)) {
        return 0;
    }
    if (IsFlagBit8Set_021da9b0((struct FlagObj_021da9b0*)combatant)) {
        return 0;
    }
    if (IsFlagBit5Set_021de25c((struct FlagObj_021de25c*)combatant)) {
        return 0;
    }
    if (CheckFlag0x14Bit0x10Set_020882f8((unsigned char*)combatant->currentStats_)) {
        return 0;
    }
    if (IsFlag10088Set_02010088((struct S_10088*)combatant)) {
        return 0;
    }
    return ((struct StatsInner_021eb1ec*)combatant->currentStats_)->bit3 == 0;
}
