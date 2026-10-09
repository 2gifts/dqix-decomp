#include <globaldefs.h>
#include "GameState/GameState.h"

struct StoreStruct {
    char pad0[0x5c];
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
    char pad0[0x950];
    int vocation;
};

struct PartyMember {
    char pad0[0x150];
    PartyStats* stats;
};

extern unsigned short data_ov000_02183510[];

extern "C" StoreStruct* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" PartyMember* _ZN9GameState21GetPartyMemberByIndexEi(GameState* gs, int idx);
extern "C" SkillEntry* func_ov000_02170cf8(MenuEntry* entry, int key);
extern "C" GameObject* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState* gs, int idx);
extern "C" void _Z35NotifyLocalizedResourceLoad020dd040iPc(int id, char* buf);
extern "C" void func_02046608(StoreStruct* store, int kind, char* src, char* dst, int a, int b, int c);
extern "C" void func_02046380(StoreStruct* store);
extern "C" int _Z21IsFlag0x18Bit0x200SetP10GameObject(GameObject* obj);
extern "C" int _Z22AdjustValueByFieldFlagPvj(GameObject* obj, unsigned int flag);
extern "C" void _Z17StoreInArray0x8b0P11StoreStructii(StoreStruct* store, int index, int value);
extern "C" const char* _Z28CallFunc020e0434With02153694i(int key);
extern "C" void _Z20AppendString02042058PcPKc(char* dst, const char* src);
extern "C" void* _Z23FindElementByC40205d81cP15Struct_0205d81ci(ElemList* list, int key);
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(ElemList* list, int key, char* text, int a, unsigned char b);
extern "C" void func_0205d304(ElemList* list, char* text, int a, int b, int c, int d, int e, int f);

// USA: func_ov000_02179cdc
extern "C" ARM void func_ov000_02179cdc(BattleMenu* menu, MenuEntry* entry) {
    if (entry == 0) {
        return;
    }
    char* buf = _Z26GetGlobalField0x1c020421a0v()->textBuffer;
    memset(buf, 0, 0x960);
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
    char text[0x800];
    func_02046608(_Z26GetGlobalField0x1c020421a0v(), 10, buf, text, 0x72, 0, 0);
    char* msg = text;
    StoreStruct* store = _Z26GetGlobalField0x1c020421a0v();
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
    _Z20AppendString02042058PcPKc(msg, _Z28CallFunc020e0434With02153694i(0x3ec));
    ElemList* list = &menu->elements;
    if (_Z23FindElementByC40205d81cP15Struct_0205d81ci(list, 0x16) != 0) {
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(list, 0x16, msg, 1, 0);
        return;
    }
    int x = entry->x;
    int y = entry->y;
    list->field_0xa0 = 0x10;
    list->field_0xa2 = 0xa;
    list->x = (x >> 3) + 0x10;
    list->y = (short)(y >> 3) + 3;
    list->field_0xa8 = 7;
    list->field_0xaa = 6;
    list->field_0xac = 0xa;
    list->field_0xae = 0xe;
    list->field_0xb1 = 0x16;
    func_0205d304(list, msg, 1, 0, 0, 1, 0, 0);
}
