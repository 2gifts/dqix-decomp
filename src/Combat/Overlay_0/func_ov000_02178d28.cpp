#include <globaldefs.h>
#include "GameState/GameState.h"

struct SkillData {
    char pad0[4];
    unsigned int kind : 12;
    unsigned int pad4 : 20;
    unsigned int adjustKey : 8;
};

struct UnitEntry {
    char pad0[0xe];
    short power;
    char pad10[0x20 - 0x10];
    signed char cursor;
    char pad21[0x44 - 0x21];
    int x;
    int y;
    int combatantId;
};

struct Window {
    char pad0[0xa0];
    short left;
    short top;
    short x;
    short y;
    short width;
    short height;
    short field_0xac;
    short field_0xae;
    char padb0;
    unsigned char id;
};

struct MenuState {
    char pad0[0x188];
    Window window;
};

struct GlobalData {
    char pad0[0x5c];
    char* workBuffer;
};

struct StoreStruct;

extern "C" GlobalData* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" SkillData* _Z27GetBoundedField156_02171674Pvi(UnitEntry* entry, int index);
extern "C" GameObject* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState* gs, int id);
extern "C" void _Z35NotifyLocalizedResourceLoad020dd040iPc(int id, char* buf);
extern "C" void func_02046608(GlobalData* messages, int a, const char* input, char* output, int b, int c, int d);
extern "C" void func_02046380(GlobalData* messages);
extern "C" int _Z21IsFlag0x18Bit0x200SetP10GameObject(GameObject* obj);
extern "C" int _Z22AdjustValueByFieldFlagPvj(GameObject* obj, unsigned int key);
extern "C" void _Z17StoreInArray0x8b0P11StoreStructii(GlobalData* messages, int index, int value);
extern "C" const char* _Z28CallFunc020e0434With02153694i(int key);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);
extern "C" void* _Z23FindElementByC40205d81cP15Struct_0205d81ci(Window* window, int key);
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(Window* window, int key, char* text, int d, unsigned char e);
extern "C" void func_0205d304(Window* window, char* text, int a, int b, int c, int d, int e, int f);

// USA: func_ov000_02178d28
extern "C" ARM void func_ov000_02178d28(MenuState* menu, UnitEntry* entry) {
    if (entry == NULL) {
        return;
    }
    int cursor = entry->cursor;
    char* buf = _Z26GetGlobalField0x1c020421a0v()->workBuffer;
    memset(buf, 0, 0x960);
    GameState* gs = GameState::GetInstance();
    SkillData* skill = _Z27GetBoundedField156_02171674Pvi(entry, cursor);
    if (skill == NULL) {
        return;
    }
    GameObject* combatant = gs->GetCombatantByIndex(entry->combatantId);
    if (combatant == NULL) {
        return;
    }
    GameObject* target = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, entry->combatantId);
    if (target == NULL) {
        return;
    }
    char textBuf[0x800];
    _Z35NotifyLocalizedResourceLoad020dd040iPc(skill->kind, buf);
    func_02046608(_Z26GetGlobalField0x1c020421a0v(), 10, buf, textBuf, 0x72, 0, 0);
    char* text = textBuf;
    GlobalData* messages = _Z26GetGlobalField0x1c020421a0v();
    func_02046380(messages);
    int value;
    if (_Z21IsFlag0x18Bit0x200SetP10GameObject(combatant)) {
        value = 0;
    } else if (skill->kind == 0x28 && entry->power < 0x14) {
        value = 0x14;
    } else if (skill->adjustKey >= 0xff) {
        value = entry->power;
    } else {
        value = _Z22AdjustValueByFieldFlagPvj(target, skill->adjustKey);
    }
    _Z17StoreInArray0x8b0P11StoreStructii(messages, 0, value);
    _Z17StoreInArray0x8b0P11StoreStructii(messages, 1, entry->power);
    _Z20AppendString02042058PcPKc(text, _Z28CallFunc020e0434With02153694i(0x3ec));
    Window* window = &menu->window;
    if (_Z23FindElementByC40205d81cP15Struct_0205d81ci(window, 0x22) != NULL) {
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(window, 0x22, text, 1, 0);
        return;
    }
    int x = entry->x;
    int y = entry->y;
    window->left = 0x10;
    window->top = 10;
    window->x = (x >> 3) + 0x10;
    window->y = y >> 3;
    window->width = 7;
    window->height = 6;
    window->field_0xac = 10;
    window->field_0xae = 0xe;
    window->id = 0x22;
    func_0205d304(window, text, 0, 0, 0, 1, 0, 0);
}
