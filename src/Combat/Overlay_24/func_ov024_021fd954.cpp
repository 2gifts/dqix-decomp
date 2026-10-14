#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

int GetFieldAt0x150_02053c6c(unsigned char* obj);
int TestBitInArray0x8ec_02083b00(unsigned char* obj, int index);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned int index);
struct S_10088;
int IsFlag10088Set_02010088(struct S_10088* obj);
struct S88514;
int CheckFlag0x2AndState2_02088514(struct S88514* obj);
struct FlagObj_021da9b0;
int IsFlagBit8Set_021da9b0(struct FlagObj_021da9b0* p);
int CheckFlag0x14Bit0x10Set_020882f8(unsigned char* p);
struct FlagObj_021de25c;
int IsFlagBit5Set_021de25c(struct FlagObj_021de25c* p);
struct Combatant_2088660;
int IsField0x18Flag0x80Set_02088660(struct Combatant_2088660* p);
struct S_flag2b;
int IsFlagBit2Set_021fb430(struct S_flag2b* p);
struct S_flag4b;
int IsFlagBit4Set_021fb448(struct S_flag4b* p);
struct S_flag131072;
int IsFlagBit131072Set_021fb478(struct S_flag131072* p);
struct S_flag4000000;
int IsFlagBit67108864Set_021edc08(struct S_flag4000000* p);
struct FlagObj_021e47dc;
int IsFlagBit22Set_021e47dc(struct FlagObj_021e47dc* p);
struct AddEntryList_021f6a1c;
void AddEntryIfUnderLimit16_021f6a1c(struct AddEntryList_021f6a1c* obj, void* src);
extern "C" void func_ov024_021f6a4c(void* dst, void* src);
extern "C" void func_ov024_021fd858(void* obj);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int unused, int val);

struct Combatant_021fd954 {
    char pad0[4];
    short id;
    char pad6[0x138 - 0x6];
    struct ModifiableCombatStats* stats;
    char pad13c[0x150 - 0x13c];
    unsigned char* field150;
};

struct Combatant_021fd954* GetCombatantByID(int unused, int id);

struct Entry_021fd954 {
    float value;
    unsigned char id;
    unsigned char flag5;
    unsigned char index;
    unsigned char percent;
    unsigned char code;
};
struct EntryList_021fd954 {
    char raw[0xc8];
    EntryList_021fd954() { memset(this, 0, sizeof(*this)); }
};
struct Action_021fd954 {
    char pad0[8];
    unsigned int pad8_lo : 8;
    unsigned int mode : 2;
    unsigned int pad8_hi : 22;
    char padc[4];
    unsigned int flags10;
    unsigned int pad14 : 28;
    unsigned int targetKind : 4;
    unsigned int kind : 5;
    unsigned int pad18 : 27;
};
struct Battle_021fd954 {
    char pad[0x8e18];
    unsigned char* partyWork;
};
struct Obj_021fd954 {
    struct Battle_021fd954* battle;
    short field4;
    struct Combatant_021fd954* actor;
    char padc[0x64c - 0xc];
    struct Action_021fd954* action;
    char pad650[0x658 - 0x650];
    struct EntryList_021fd954* list;
    struct Entry_021fd954 entry;
    struct Combatant_021fd954* target;
    int targetId;
};

// USA: func_ov024_021fd954
extern "C" ARM void func_ov024_021fd954(struct Obj_021fd954* obj, int statusType) {
    struct Action_021fd954* action;
    int targetKind;
    int i;
    struct Combatant_021fd954* c;
    int found;
    struct Combatant_021fd954* actor;
    actor = obj->actor;
    GetFieldAt0x150_02053c6c((unsigned char*)actor);
    action = obj->action;
    if (action->mode == 1) return;
    targetKind = action->targetKind;
    if (targetKind == 6) {
        if (TestBitInArray0x8ec_02083b00(actor->field150, 0xe6)) {
            targetKind = 3;
        } else {
            targetKind = 2;
        }
    }
    if (targetKind != 2 && targetKind != 1 && targetKind != 4 && targetKind != 3) return;

    struct EntryList_021fd954 list;
    memset(&list, 0, sizeof(list));
    found = 0;
    for (i = 0; i < 4; i++) {
        if (targetKind == 1 && i != obj->field4) continue;
        if (!TestBitAt0x34_020a35e0(obj->battle->partyWork, i & 0xff)) continue;
        c = GetCombatantByID((int)obj->battle, (short)i);
        if (!c) continue;
        if (IsFlag10088Set_02010088((struct S_10088*)c)) continue;
        if ((action->flags10 & 0x400) && (*(unsigned int*)((char*)c->stats + 0x14) & 0x200)) continue;

        bool ok = false;
        int code = 8;
        if (statusType == 2) {
            if (CheckFlag0x2AndState2_02088514((struct S88514*)c->stats)) ok = true;
        } else if (statusType == 3) {
            if (IsFlagBit8Set_021da9b0((struct FlagObj_021da9b0*)c)) ok = true;
        } else if (statusType == 4) {
            if (CheckFlag0x14Bit0x10Set_020882f8((unsigned char*)c->stats)) ok = true;
        } else if (statusType == 7) {
            if (IsFlagBit5Set_021de25c((struct FlagObj_021de25c*)c)) ok = true;
        } else if (statusType == 0x11) {
            struct ModifiableCombatStats* s = c->stats;
            if (s->attackBuff <= 0) ok = true;
            if (s->primaryStats.attack >= 999) ok = false;
            code = 7;
        } else if (statusType == 0x12) {
            struct ModifiableCombatStats* s = c->stats;
            if (s->defenseBuff <= 0) ok = true;
            if (s->primaryStats.defense >= 999) ok = false;
            code = 7;
        } else if (statusType == 0x13) {
            struct ModifiableCombatStats* s = c->stats;
            if (s->agilityBuff <= 0) ok = true;
            if (s->primaryStats.agility >= 999) ok = false;
            code = 7;
        } else if (statusType == 0x14) {
            struct ModifiableCombatStats* s = c->stats;
            if (s->magicalMightBuff <= 0) ok = true;
            if ((unsigned short)s->primaryStats.magicalMight >= 999) ok = false;
            code = 7;
        } else if (statusType == 0x15) {
            struct ModifiableCombatStats* s = c->stats;
            if (s->magicalMendingBuff <= 0) ok = true;
            if ((unsigned short)s->primaryStats.magicalMending >= 999) ok = false;
            code = 7;
        } else if (statusType == 0x16) {
            if (c->stats->unkBuff18 <= 0) ok = true;
            code = 7;
        } else if (statusType == 0x17) {
            if ((((*(int*)((char*)c->stats + 0x58)) << 8) >> 29) <= 0) ok = true;
            code = 7;
        } else if (statusType == 0xd) {
            if (!IsField0x18Flag0x80Set_02088660((struct Combatant_2088660*)c->stats)) ok = true;
            code = 7;
        } else if (statusType == 0xe) {
            if (!IsFlagBit2Set_021fb430((struct S_flag2b*)c) && !IsFlagBit4Set_021fb448((struct S_flag4b*)c)
                && !IsFlagBit131072Set_021fb478((struct S_flag131072*)c)) ok = true;
            code = 7;
        } else if (statusType == 0xf) {
            if (!IsFlagBit2Set_021fb430((struct S_flag2b*)c) && !IsFlagBit4Set_021fb448((struct S_flag4b*)c)
                && !IsFlagBit131072Set_021fb478((struct S_flag131072*)c)) ok = true;
            code = 7;
        } else if (statusType == 0x10) {
            if (!IsFlagBit67108864Set_021edc08((struct S_flag4000000*)c)) ok = true;
            code = 7;
        } else if (statusType == 0xb) {
            if (!IsFlagBit22Set_021e47dc((struct FlagObj_021e47dc*)c)) ok = true;
            code = 7;
        }

        struct Entry_021fd954 e;
        memset(&e, 0, sizeof(e));
        int percent = 50;
        if (ok) {
            percent = 100;
            found = 1;
        }
        e.value = 0.0f;
        e.id = statusType;
        e.flag5 = 0;
        e.index = i;
        e.percent = percent;
        e.code = code;
        AddEntryIfUnderLimit16_021f6a1c((struct AddEntryList_021f6a1c*)&list, &e);
        if (action->kind != 0) {
            obj->list = &list;
            func_ov024_021f6a4c(&obj->entry, &e);
            obj->target = c;
            obj->targetId = c->id;
            func_ov024_021fd858(obj);
        }
        if (targetKind == 2 || targetKind == 1) {
            int value = (unsigned char)c->id;
            if (found) func_ov024_021f9874(obj, &list, 0, value);
            memset(&list, 0, sizeof(list));
            found = 0;
        }
    }
    if (targetKind == 4 || targetKind == 3) {
        GetCombatantByID((int)obj->battle, 0);
        int value = (unsigned char)actor->id;
        if (targetKind == 3) value = 0xff;
        if (found) func_ov024_021f9874(obj, &list, 0, value);
    }
}
