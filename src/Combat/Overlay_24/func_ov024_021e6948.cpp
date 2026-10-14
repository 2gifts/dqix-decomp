#include <globaldefs.h>
#include "GameState/GameState.h"

struct Stats_021e6948 {
    char pad0[0x21];
    unsigned char rank21;
};

struct Cbt_021e6948 {
    char pad0[0x138];
    struct Stats_021e6948* stats;
};

struct Battle_021e6948;

struct Ctx_021e6948 {
    char pad0[0x10];
    struct Battle_021e6948* battle;
};

struct Cbt_021e6948* GetCombatantByID(int, int);
float LookupTableC0_02074938(int v);
struct GameObject;
int IsCombatantFlag2Mask32_021e67b0(GameObject*);
struct GameState;
void* GetPtrField0x2a04_02010828(GameState*);
struct ArrayContainsByteStruct;
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct*, int);
void IncrementByteCounterCapped0x63_0215a8d4(unsigned char*, int);
extern "C" int func_ov000_02156068(struct Battle_021e6948* battle, int id, int kind, int mode);
struct Random;
int NextRandomMax(Random*, int);
struct FlagObj_021dd260;
int IsFlagBit24Set_021dd260(FlagObj_021dd260*);

// USA: func_ov024_021e6948
extern "C" ARM int func_ov024_021e6948(struct Ctx_021e6948* ctx, int targetId, int a, int b) {
    float dmg = (float)a * (float)b / 8.0f;
    struct Cbt_021e6948* target = GetCombatantByID((int)ctx->battle, targetId);
    if (target) {
        if (target->stats->rank21 <= 3) {
            dmg = dmg * LookupTableC0_02074938((signed char)target->stats->rank21);
        }
        if (IsCombatantFlag2Mask32_021e67b0((GameObject*)target)) {
            dmg = dmg * LookupTableC0_02074938(1);
        }
        if (ArrayContainsByte_02086ef0((ArrayContainsByteStruct*)(GetPtrField0x2a04_02010828((GameState*)GameState::GetInstance())), targetId) &&
            target && target->stats->rank21 == 1) {
            IncrementByteCounterCapped0x63_0215a8d4((unsigned char*)ctx->battle, 0);
        }
    }
    if (dmg > 0 && func_ov000_02156068(ctx->battle, targetId, 0, 1)) {
        dmg = NextRandomMax((Random*)ctx->battle, 2);
    }
    if (IsFlagBit24Set_021dd260((FlagObj_021dd260*)target)) {
        dmg = 0.5f * dmg;
    }
    return dmg;
}
