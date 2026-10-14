#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
int IsFlag10088Set_02010088(struct S_10088* obj);

int IsCombatantFlag2Mask8192_021e6798(GameObject* combatant);

struct FlagObj_021da9b0;
int IsFlagBit8Set_021da9b0(struct FlagObj_021da9b0* obj);

int CheckFlag0x14Bit0x10Set_020882f8(unsigned char* obj);

struct FlagObj_021da9c8;
int IsFlagBit19Set_021da9c8(struct FlagObj_021da9c8* obj);

struct FlagObj_021de25c;
int IsFlagBit5Set_021de25c(struct FlagObj_021de25c* obj);

struct Struct_021fa76c {
    char unk[0x138];
    unsigned char* field0x138;
};

// USA: func_ov024_021fa76c
ARM int CheckAllFlagsClear_021fa76c(struct Struct_021fa76c* combatant) {
    if (IsFlag10088Set_02010088((struct S_10088*)combatant)) return 0;
    if (IsCombatantFlag2Mask8192_021e6798((GameObject*)combatant)) return 0;
    if (IsFlagBit8Set_021da9b0((struct FlagObj_021da9b0*)combatant)) return 0;
    if (CheckFlag0x14Bit0x10Set_020882f8(combatant->field0x138)) return 0;
    if (IsFlagBit19Set_021da9c8((struct FlagObj_021da9c8*)combatant)) return 0;
    return !IsFlagBit5Set_021de25c((struct FlagObj_021de25c*)combatant);
}
