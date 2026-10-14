#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "GameState/GameState.h"

struct StoreStruct {
#if defined(jpn)
    char pad0[0x28];
#else
    char pad0[0x5c];
#endif
    char* textBuffer;
};

struct ElemList {
    char pad0[0xa0];
    short field_0xa0;
    short field_0xa2;
    short x;
    short y;
    short field_0xa8;
    short field_0xaa;
    short field_0xac;
    short field_0xae;
    char padb0;
    unsigned char field_0xb1;
};

struct BattleMenu {
    char pad0[0x188];
    ElemList elements;
};

struct MenuEntry {
    char pad0[0xe];
    short value;
    char pad10[0x44 - 0x10];
    int x;
    int y;
    int combatantId;
};

struct SkillEntry {
    char pad0[4];
    unsigned int nameId : 12;
    unsigned int pad4 : 20;
    unsigned int adjustFlag : 8;
};

struct PartyStats {
#if defined(jpn)
    char pad0[0x8b8];
#else
    char pad0[0x950];
#endif
    int vocation;
};

struct PartyMember {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    PartyStats* stats;
};

#if defined(jpn)
#define data_ov000_02183510 data_ov000_02184590
#endif
extern unsigned short data_ov000_02183510[];

StoreStruct* GetGlobalField0x1c020421a0(void);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" SkillEntry* func_ov000_02170cf8(MenuEntry* entry, int key);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gs, int idx);
#if defined(jpn)
#define _Z35NotifyLocalizedResourceLoad020dd040iPc func_020dea34
#endif
extern "C" void _Z35NotifyLocalizedResourceLoad020dd040iPc(int id, char* buf);
extern "C" void func_02046608(StoreStruct* store, int kind, char* src, char* dst, int a, int b, int c);
extern "C" void func_02046380(StoreStruct* store);
int IsFlag0x18Bit0x200Set_ov000_02153a8c(GameObject* obj);
int AdjustValueByFieldFlag_020dd290(void*, unsigned int);
void StoreInArray0x8b0_020465c0(StoreStruct* store, int index, int value);
const char* CallFunc020e0434With02153694_020e51cc(int key);
void AppendString02042058(char* dst, const char* src);
struct Struct_0205d81c;
void* FindElementByC40205d81c(Struct_0205d81c*, int);
#if defined(jpn)
extern "C" void func_0205d304(ElemList* list, char* text, int a, int b, int c, int d, int e);
void SetByteInRange_020465f0(unsigned char*, int, unsigned char);
void SetByteAtIndex_020465d8(unsigned char*, int, unsigned char);
extern char data_ov000_02185169[];
#else
extern "C" void func_0205d304(ElemList* list, char* text, int a, int b, int c, int d, int e, int f);
#endif

// USA: func_ov000_02179cdc
extern "C" ARM void func_ov000_02179cdc(BattleMenu* menu, MenuEntry* entry) {
    char* msg;
    StoreStruct* store;
    if (entry == 0) {
        return;
    }
    char* buf = GetGlobalField0x1c020421a0()->textBuffer;
#if defined(jpn)
    memset(buf, 0, 0x800);
#else
    memset(buf, 0, 0x960);
#endif
    GameState* gs = GameState::GetInstance();
    GameObject* combatant = gs->GetCombatantByIndex(entry->combatantId);
    if (combatant == 0) {
        return;
    }
    PartyMember* member = (PartyMember*)gs->GetPartyMemberByIndex(entry->combatantId);
    if (member == 0) {
        return;
    }
    SkillEntry* skill = func_ov000_02170cf8(entry, data_ov000_02183510[member->stats->vocation]);
    GameObject* flagged = GetCombatantWithFlag0x100_0200ff1c(gs, entry->combatantId);
    if (flagged == 0) {
        return;
    }
    _Z35NotifyLocalizedResourceLoad020dd040iPc(skill->nameId, buf);
#if !defined(jpn)
    char text[0x800];
#endif
#if defined(jpn)
    msg = buf;
#else
    func_02046608(GetGlobalField0x1c020421a0(), 10, buf, text, 0x72, 0, 0);
    msg = text;
#endif
    store = GetGlobalField0x1c020421a0();
    func_02046380(store);
    int value;
    if (IsFlag0x18Bit0x200Set_ov000_02153a8c(combatant) != 0) {
        value = 0;
    } else if (skill->adjustFlag >= 0xff) {
        value = entry->value;
    } else {
        value = AdjustValueByFieldFlag_020dd290(flagged, skill->adjustFlag);
    }
    StoreInArray0x8b0_020465c0(store, 0, value);
    StoreInArray0x8b0_020465c0(store, 1, entry->value);
#if defined(jpn)
    SetByteInRange_020465f0((unsigned char*)store, 0, 3);
    SetByteInRange_020465f0((unsigned char*)store, 1, 3);
    SetByteAtIndex_020465d8((unsigned char*)store, 0, 1);
    SetByteAtIndex_020465d8((unsigned char*)store, 1, 1);
    AppendString02042058(msg, data_ov000_02185169);
#else
    AppendString02042058(msg, CallFunc020e0434With02153694_020e51cc(0x3ec));
#endif
    ElemList* list = &menu->elements;
    if (FindElementByC40205d81c((Struct_0205d81c*)list, 0x16) != 0) {
#if defined(jpn)
        TryApplyElemFields0205d5d0((StructA0205d5d0*)list, 0x16, (int)msg, 1);
#else
        TryApplyElemFields0205d5d0((StructA0205d5d0*)list, 0x16, (int)msg, 1, 0);
#endif
        return;
    }
    int x = entry->x;
    int y = entry->y;
#if defined(jpn)
    list->field_0xa0 = 0xc;
#else
    list->field_0xa0 = 0x10;
#endif
#if defined(jpn)
    list->field_0xa2 = 6;
#else
    list->field_0xa2 = 0xa;
#endif
#if defined(jpn)
    list->x = (x >> 3) + 0x16;
#else
    list->x = (x >> 3) + 0x10;
#endif
#if defined(jpn)
    list->y = y >> 3;
#else
    list->y = (short)(y >> 3) + 3;
#endif
    list->field_0xa8 = 7;
#if defined(jpn)
    list->field_0xaa = 8;
#else
    list->field_0xaa = 6;
#endif
    list->field_0xac = 0xa;
    list->field_0xae = 0xe;
    list->field_0xb1 = 0x16;
#if defined(jpn)
    func_0205d304(list, msg, 1, 0, 0, 1, 0);
#else
    func_0205d304(list, msg, 1, 0, 0, 1, 0, 0);
#endif
}
