#include <globaldefs.h>
#include "GameState/GameState.h"

struct FlagObj_021da998;
struct FlagObj_021dd260;
struct FlagObj_021e47dc;
struct S_flag4000000;
struct FlagObj_021dd010;
struct Combatant_2088660;
struct S_flag2b;
struct S_flag4b;
struct S_flag1024;
int IsFlagBit8388608Set_021da998(FlagObj_021da998*);
int IsFlagBit24Set_021dd260(FlagObj_021dd260*);
int IsFlagBit22Set_021e47dc(FlagObj_021e47dc*);
int IsFlagBit67108864Set_021edc08(S_flag4000000*);
int IsFlagBit8Set_021dd010(FlagObj_021dd010*);
int IsField0x18Flag0x80Set_02088660(Combatant_2088660*);
int IsFlagBit2Set_021fb430(S_flag2b*);
int IsFlagBit4Set_021fb448(S_flag4b*);
int IsCombatantFlag2Mask512_021eadfc(GameObject*);
int IsFlagBit1024Set_021fcac0(S_flag1024*);

struct CombatStats021fc754 {
    unsigned char field_0[0x14];
    unsigned int statusFlags;
    unsigned int conditionFlags;
    unsigned char field_1c[0x58 - 0x1c];
    signed int attackBuff : 3;
    signed int defenseBuff : 3;
    signed int agilityBuff : 3;
    signed int charmBuff : 3;
    signed int magicalMightBuff : 3;
    signed int magicalMendingBuff : 3;
    signed int field_18 : 3;
    signed int field_21 : 3;
    signed int field_24 : 3;
    signed int field_27 : 3;
    unsigned int field_30 : 2;
};
static inline CombatStats021fc754* GetStats021fc754(GameObject* object) {
    return (CombatStats021fc754*)object->currentStats_;
}
struct StatusScore021fc754 { unsigned char active; signed char weight; };
struct BuffScore021fc754 { signed char level; signed char weight; };
union StatusTable021fc754 { StatusScore021fc754 entries[22]; signed char bytes[44]; };
union BuffTable021fc754 { BuffScore021fc754 entries[10]; signed char bytes[20]; };
extern const StatusTable021fc754 data_ov024_021ff026;
extern const BuffTable021fc754 data_ov024_021fefd6;
struct Entry021fc754 { float value; unsigned char id, flag5, index, percent, code; };
struct AddEntryList_021f6a1c { Entry021fc754 entries[16]; int count; float threshold; };
void AddEntryIfUnderLimit16_021f6a1c(AddEntryList_021f6a1c*, void*);
struct Battle021fc754 {
    unsigned char field_0[4];
    short id;
    unsigned char field_6[0x7c - 6];
    GameObject* entries[8];
    int count;
};
extern "C" int func_ov024_021fe698(Battle021fc754*, int);
extern "C" void func_ov024_021f9874(Battle021fc754*, AddEntryList_021f6a1c*, int, int);

// USA: func_ov024_021fc754
extern "C" ARM void func_ov024_021fc754(Battle021fc754* battle) {
    if (!func_ov024_021fe698(battle, 1)) return;
    int total = 0;
    for (int i = 0; i < battle->count; i++) {
        GameObject* object = battle->entries[i];
        if (!object) continue;
        int score = 0;
        StatusTable021fc754 statuses = data_ov024_021ff026;
        statuses.entries[0].active = IsFlagBit8388608Set_021da998((FlagObj_021da998*)object);
        statuses.entries[1].active = IsFlagBit24Set_021dd260((FlagObj_021dd260*)object);
        statuses.entries[2].active = (GetStats021fc754(object)->statusFlags & 0x200) != 0;
        statuses.entries[3].active = (GetStats021fc754(object)->statusFlags & 0x8000000) != 0;
        statuses.entries[4].active = (GetStats021fc754(object)->statusFlags & 0x10000000) != 0;
        statuses.entries[5].active = (GetStats021fc754(object)->statusFlags & 0x20000000) != 0;
        statuses.entries[6].active = (GetStats021fc754(object)->statusFlags & 0x100000) != 0;
        statuses.entries[7].active = IsFlagBit22Set_021e47dc((FlagObj_021e47dc*)object);
        statuses.entries[8].active = IsFlagBit67108864Set_021edc08((S_flag4000000*)object);
        statuses.entries[9].active = (GetStats021fc754(object)->statusFlags & 0x40000000) != 0;
        statuses.entries[10].active = IsFlagBit8Set_021dd010((FlagObj_021dd010*)object);
        statuses.entries[11].active = IsFlagBit67108864Set_021edc08((S_flag4000000*)object);
        statuses.entries[12].active = (GetStats021fc754(object)->statusFlags & 0x200000) != 0;
        statuses.entries[13].active = (GetStats021fc754(object)->statusFlags & 0x80000000) != 0;
        statuses.entries[14].active = IsField0x18Flag0x80Set_02088660((Combatant_2088660*)object->currentStats_);
        statuses.entries[15].active = (GetStats021fc754(object)->conditionFlags & 8) != 0;
        statuses.entries[16].active = (GetStats021fc754(object)->conditionFlags & 0x10) != 0;
        statuses.entries[17].active = IsFlagBit2Set_021fb430((S_flag2b*)object);
        statuses.entries[18].active = IsFlagBit4Set_021fb448((S_flag4b*)object);
        statuses.entries[19].active = IsCombatantFlag2Mask512_021eadfc(object);
        statuses.entries[20].active = IsFlagBit1024Set_021fcac0((S_flag1024*)object);
        statuses.entries[21].active = (GetStats021fc754(object)->conditionFlags & 0x100) != 0;
        for (int j = 0; j < 22; j++) {
            unsigned char active = (unsigned char)statuses.bytes[j * 2];
            int weight = statuses.bytes[j * 2 + 1];
            if (active) score += weight;
        }
        BuffTable021fc754 buffs = data_ov024_021fefd6;
        buffs.entries[0].level = GetStats021fc754(object)->attackBuff;
        buffs.entries[1].level = GetStats021fc754(object)->defenseBuff;
        buffs.entries[2].level = GetStats021fc754(object)->agilityBuff;
        buffs.entries[3].level = GetStats021fc754(object)->charmBuff;
        buffs.entries[4].level = GetStats021fc754(object)->magicalMightBuff;
        buffs.entries[5].level = GetStats021fc754(object)->magicalMendingBuff;
        buffs.entries[6].level = GetStats021fc754(object)->field_18;
        buffs.entries[7].level = GetStats021fc754(object)->field_21;
        buffs.entries[8].level = GetStats021fc754(object)->field_24;
        buffs.entries[9].level = GetStats021fc754(object)->field_27;
        for (int j = 0; j < 10; j++) {
            int level = buffs.bytes[j * 2];
            int weight = buffs.bytes[j * 2 + 1];
            if (level > 0) score += weight * level;
            else if (level < 0) score += weight * level * 3;
        }
        total += score;
    }
    if (total > 0) {
        AddEntryList_021f6a1c list;
        memset(&list, 0, sizeof(list));
        Entry021fc754 entry;
        entry.value = total;
        entry.flag5 = 1;
        entry.index = 0;
        entry.percent = 100;
        entry.code = 6;
        AddEntryIfUnderLimit16_021f6a1c(&list, &entry);
        func_ov024_021f9874(battle, &list, 0, (unsigned char)battle->id);
    }
}
