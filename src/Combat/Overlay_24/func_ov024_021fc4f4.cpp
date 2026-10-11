#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

int GetFieldAt0x150(unsigned char* obj);
void* GetData02108e10(void);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
struct S_10088;
int IsFlag10088Set(struct S_10088* obj);
struct AddEntryList_021f6a1c;
extern "C" void _Z31AddEntryIfUnderLimit16_021f6a1cP21AddEntryList_021f6a1cPv(struct AddEntryList_021f6a1c* obj, void* src);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int unused, int val);

struct Entry_021fc4f4 {
    float value;
    unsigned char id;
    unsigned char flag5;
    unsigned char index;
    unsigned char percent;
    unsigned char code;
};
struct EntryList_021fc4f4 {
    char raw[0xc8];
    EntryList_021fc4f4() { memset(this, 0, sizeof(*this)); }
};
struct Actor_021fc4f4 { char pad0[4]; short id; };
struct Action_021fc4f4 {
    char pad0[8];
    unsigned int pad8_lo : 8;
    unsigned int mode : 2;
    unsigned int pad8_hi : 22;
    char padc[4];
    unsigned int flags10;
    unsigned int pad14 : 28;
    unsigned int targetKind : 4;
};
struct Battle_021fc4f4 {
    char pad[0x8e18];
    unsigned char* partyWork;
};
struct StatsFlags_021fc4f4 { char pad[0x14]; int flags; };
struct Obj_021fc4f4 {
    struct Battle_021fc4f4* battle;
    short field4;
    unsigned char field6;
    struct Actor_021fc4f4* actor;
    char padc[0x128 - 0xc];
    int field128;
    char pad12c[0x134 - 0x12c];
    int field134;
    char pad138[0x64c - 0x138];
    struct Action_021fc4f4* action;
};

// JPN: func_ov024_021fccc0
// USA: func_ov024_021fc4f4
extern "C" ARM void func_ov024_021fc4f4(struct Obj_021fc4f4* obj) {
    if (obj->field6 == 0) return;
    struct Actor_021fc4f4* actor = obj->actor;
    GetFieldAt0x150((unsigned char*)actor);
    GetData02108e10();
    struct Action_021fc4f4* action = obj->action;
    if (action->mode == 1) return;
    GetCombatantByID((int)obj->battle, (short)obj->field128);

    int count = 0;
    struct EntryList_021fc4f4 list;
    memset(&list, 0, sizeof(list));
    for (int i = 0; i < 4; i++) {
        if (!TestBitAt0x34(obj->battle->partyWork, i & 0xff)) continue;
        if (action->targetKind == 1 && i != obj->field4) continue;
        GameObject* c = GetCombatantByID((int)obj->battle, (short)i);
        if (!c) continue;
        if (!IsFlag10088Set((struct S_10088*)c)) continue;
        if ((action->flags10 & 0x400) && (((struct StatsFlags_021fc4f4*)c->currentStats_)->flags & 0x200)) continue;
        struct Entry_021fc4f4 e;
        float percent = 100.0f;
        e.value = c->currentStats_->primaryStats.currHP;
        e.flag5 = 0;
        e.index = i;
        count++;
        e.percent = (int)percent;
        e.code = 5;
        _Z31AddEntryIfUnderLimit16_021f6a1cP21AddEntryList_021f6a1cPv((struct AddEntryList_021f6a1c*)&list, &e);
    }
    if (count >= 2 && obj->field134 + count >= 3) {
        GetCombatantByID((int)obj->battle, 0);
        int target = actor->id & 0xff;
        if (action->targetKind == 3) target = 0xff;
        func_ov024_021f9874(obj, &list, 0, target);
    }
}
