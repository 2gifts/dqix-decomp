#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Combat/Overlay_0/GetCombatantByID.h>

struct FlagObj_021da998;
struct FlagObj_021dd260;
struct S_flag100000;
struct FlagObj_021e47dc;
struct S_flag4000000;
struct S_flag40000000;
struct S_flag200000;
struct S_flag80000000;
struct Combatant_2088660;
struct S_flag8b;
struct StatusFields {
    char pad0[0x18];
    unsigned int flags_;
    char pad1C[0x3c];
    unsigned int knownBuffs_ : 21;
    signed int field21_ : 3;
    signed int field24_ : 3;
    signed int field27_ : 3;
};

extern unsigned short data_ov024_021fea3c[4];
extern "C" int func_ov000_0215e9fc(int, unsigned short*, int, int);
extern "C" int _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(FlagObj_021da998*);
extern "C" int _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(FlagObj_021dd260*);
extern "C" int _Z31IsCombatantFlagMask512_021eda60P10GameObject(GameObject*);
extern "C" int _Z37IsCombatantFlagMask134217728_021edbc0P10GameObject(GameObject*);
extern "C" int _Z37IsCombatantFlagMask268435456_021edbd8P10GameObject(GameObject*);
extern "C" int _Z37IsCombatantFlagMask536870912_021edbf0P10GameObject(GameObject*);
extern "C" int _Z28IsFlagBit1048576Set_021edc20P12S_flag100000(S_flag100000*);
extern "C" int _Z23IsFlagBit22Set_021e47dcP16FlagObj_021e47dc(FlagObj_021e47dc*);
extern "C" int _Z29IsFlagBit67108864Set_021edc08P13S_flag4000000(S_flag4000000*);
extern "C" int _Z31IsFlagBit1073741824Set_021edc50P14S_flag40000000(S_flag40000000*);
extern "C" int _Z28IsFlagBit2097152Set_021edc38P12S_flag200000(S_flag200000*);
extern "C" int _Z31IsFlagBit2147483648Set_021edc68P14S_flag80000000(S_flag80000000*);
int IsField0x18Flag0x80Set(Combatant_2088660*);
extern "C" int _Z22IsFlagBit8Set_021f273cP8S_flag8b(S_flag8b*);

// USA: func_ov024_021f3e64
extern "C" ARM int func_ov024_021f3e64(int* context, int unused, int unused2, int* outCount, short* outTargets) {
    unsigned short targets[4];
    unsigned short* destination = targets;
    unsigned short* source = data_ov024_021fea3c;
    int remaining = 4;
    do {
        unsigned short* output = destination++;
        *output = *source++;
    } while (--remaining);
    int count = func_ov000_0215e9fc(*context, targets, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    *outCount = 0;
    for (int i = 0; i < count; ++i) {
        GameObject* target = GetCombatantByID(*context, (short)targets[i]);
        if (!target) continue;
        if (_Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998((FlagObj_021da998*)target)
            || _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260((FlagObj_021dd260*)target)
            || _Z31IsCombatantFlagMask512_021eda60P10GameObject(target)
            || _Z37IsCombatantFlagMask134217728_021edbc0P10GameObject(target)
            || _Z37IsCombatantFlagMask268435456_021edbd8P10GameObject(target)
            || _Z37IsCombatantFlagMask536870912_021edbf0P10GameObject(target)
            || _Z28IsFlagBit1048576Set_021edc20P12S_flag100000((S_flag100000*)target)
            || _Z23IsFlagBit22Set_021e47dcP16FlagObj_021e47dc((FlagObj_021e47dc*)target)
            || _Z29IsFlagBit67108864Set_021edc08P13S_flag4000000((S_flag4000000*)target)
            || _Z31IsFlagBit1073741824Set_021edc50P14S_flag40000000((S_flag40000000*)target)
            || _Z29IsFlagBit67108864Set_021edc08P13S_flag4000000((S_flag4000000*)target)
            || _Z28IsFlagBit2097152Set_021edc38P12S_flag200000((S_flag200000*)target)
            || _Z31IsFlagBit2147483648Set_021edc68P14S_flag80000000((S_flag80000000*)target)
            || IsField0x18Flag0x80Set((Combatant_2088660*)target->currentStats_)
            || _Z22IsFlagBit8Set_021f273cP8S_flag8b((S_flag8b*)target)
            || (((StatusFields*)target->currentStats_)->flags_ & 2)
            || (((StatusFields*)target->currentStats_)->flags_ & 4)
            || (((StatusFields*)target->currentStats_)->flags_ & 0x200)
            || (((StatusFields*)target->currentStats_)->flags_ & 0x400)
            || (((StatusFields*)target->currentStats_)->flags_ & 0x100)
            || target->currentStats_->attackBuff > 0
            || target->currentStats_->defenseBuff > 0
            || target->currentStats_->agilityBuff > 0
            || target->currentStats_->charmBuff != 0
            || target->currentStats_->magicalMightBuff > 0
            || target->currentStats_->magicalMendingBuff != 0
            || target->currentStats_->unkBuff18 > 0
            || ((StatusFields*)target->currentStats_)->field21_ != 0
            || ((StatusFields*)target->currentStats_)->field24_ != 0
            || ((StatusFields*)target->currentStats_)->field27_ != 0) found = 1;
    }
    if (!found) return 0;
    *outCount = count;
    memcpy(outTargets, targets, 8);
    return 1;
}
