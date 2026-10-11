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

extern "C" StoreStruct* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" PartyMember* _ZN9GameState21GetPartyMemberByIndexEi(GameState* gs, int idx);
extern "C" SkillEntry* func_ov000_02170cf8(MenuEntry* entry, int key);
extern "C" GameObject* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState* gs, int idx);
#if defined(jpn)
#define _Z35NotifyLocalizedResourceLoad020dd040iPc func_020dea34
#endif
extern "C" void _Z35NotifyLocalizedResourceLoad020dd040iPc(int id, char* buf);
extern "C" void func_02046608(StoreStruct* store, int kind, char* src, char* dst, int a, int b, int c);
extern "C" void func_02046380(StoreStruct* store);
extern "C" int _Z21IsFlag0x18Bit0x200SetP10GameObject(GameObject* obj);
extern "C" int _Z22AdjustValueByFieldFlagPvj(GameObject* obj, unsigned int flag);
extern "C" void _Z17StoreInArray0x8b0P11StoreStructii(StoreStruct* store, int index, int value);
extern "C" const char* _Z28CallFunc020e0434With02153694i(int key);
extern "C" void _Z20AppendString02042058PcPKc(char* dst, const char* src);
extern "C" void* _Z23FindElementByC40205d81cP15Struct_0205d81ci(ElemList* list, int key);
#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(ElemList* list, int key, char* text, int a);
#else
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(ElemList* list, int key, char* text, int a, unsigned char b);
#endif
#if defined(jpn)
extern "C" void func_0205d304(ElemList* list, char* text, int a, int b, int c, int d, int e);
extern "C" void _Z14SetByteInRangePhih(unsigned char*, int, unsigned char);
extern "C" void _Z14SetByteAtIndexPhih(unsigned char*, int, unsigned char);
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
    char* buf = _Z26GetGlobalField0x1c020421a0v()->textBuffer;
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
    PartyMember* member = _ZN9GameState21GetPartyMemberByIndexEi(gs, entry->combatantId);
    if (member == 0) {
        return;
    }
    SkillEntry* skill = func_ov000_02170cf8(entry, data_ov000_02183510[member->stats->vocation]);
    GameObject* flagged = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, entry->combatantId);
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
    func_02046608(_Z26GetGlobalField0x1c020421a0v(), 10, buf, text, 0x72, 0, 0);
    msg = text;
#endif
    store = _Z26GetGlobalField0x1c020421a0v();
    func_02046380(store);
    int value;
    if (_Z21IsFlag0x18Bit0x200SetP10GameObject(combatant) != 0) {
        value = 0;
    } else if (skill->adjustFlag >= 0xff) {
        value = entry->value;
    } else {
        value = _Z22AdjustValueByFieldFlagPvj(flagged, skill->adjustFlag);
    }
    _Z17StoreInArray0x8b0P11StoreStructii(store, 0, value);
    _Z17StoreInArray0x8b0P11StoreStructii(store, 1, entry->value);
#if defined(jpn)
    _Z14SetByteInRangePhih((unsigned char*)store, 0, 3);
    _Z14SetByteInRangePhih((unsigned char*)store, 1, 3);
    _Z14SetByteAtIndexPhih((unsigned char*)store, 0, 1);
    _Z14SetByteAtIndexPhih((unsigned char*)store, 1, 1);
    _Z20AppendString02042058PcPKc(msg, data_ov000_02185169);
#else
    _Z20AppendString02042058PcPKc(msg, _Z28CallFunc020e0434With02153694i(0x3ec));
#endif
    ElemList* list = &menu->elements;
    if (_Z23FindElementByC40205d81cP15Struct_0205d81ci(list, 0x16) != 0) {
#if defined(jpn)
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(list, 0x16, msg, 1);
#else
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(list, 0x16, msg, 1, 0);
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
