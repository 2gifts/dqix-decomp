#include "Combat/TryApplyElemFields.h"
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
#if defined(jpn)
    char pad0[0x28];
#else
    char pad0[0x5c];
#endif
    char* workBuffer;
};

struct StoreStruct;

extern "C" GlobalData* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" SkillData* _Z27GetBoundedField156_02171674Pvi(UnitEntry* entry, int index);
extern "C" GameObject* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState* gs, int id);
#if defined(jpn)
#define _Z35NotifyLocalizedResourceLoad020dd040iPc func_020dea34
#endif
extern "C" void _Z35NotifyLocalizedResourceLoad020dd040iPc(int id, char* buf);
extern "C" void func_02046608(GlobalData* messages, int a, const char* input, char* output, int b, int c, int d);
extern "C" void func_02046380(GlobalData* messages);
extern "C" int _Z21IsFlag0x18Bit0x200SetP10GameObject(GameObject* obj);
extern "C" int _Z22AdjustValueByFieldFlagPvj(GameObject* obj, unsigned int key);
extern "C" void _Z17StoreInArray0x8b0P11StoreStructii(GlobalData* messages, int index, int value);
extern "C" const char* _Z28CallFunc020e0434With02153694i(int key);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);
extern "C" void* _Z23FindElementByC40205d81cP15Struct_0205d81ci(Window* window, int key);
#if defined(jpn)
extern "C" void func_0205d304(Window* window, char* text, int a, int b, int c, int d, int e);
extern "C" void _Z14SetByteInRangePhih(unsigned char*, int, unsigned char);
extern "C" void _Z14SetByteAtIndexPhih(unsigned char*, int, unsigned char);
extern char data_ov000_02185169[];
#else
extern "C" void func_0205d304(Window* window, char* text, int a, int b, int c, int d, int e, int f);
#endif

// USA: func_ov000_02178d28
extern "C" ARM void func_ov000_02178d28(MenuState* menu, UnitEntry* entry) {
    char* text;
    GameObject* combatant;
    SkillData* skill;
    GameObject* target;
    GlobalData* messages;
    if (entry == NULL) {
        return;
    }
    int cursor = entry->cursor;
    char* buf = _Z26GetGlobalField0x1c020421a0v()->workBuffer;
#if defined(jpn)
    memset(buf, 0, 0x800);
#else
    memset(buf, 0, 0x960);
#endif
    GameState* gs = GameState::GetInstance();
    skill = _Z27GetBoundedField156_02171674Pvi(entry, cursor);
    if (skill == NULL) {
        return;
    }
    combatant = gs->GetCombatantByIndex(entry->combatantId);
    if (combatant == NULL) {
        return;
    }
    target = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, entry->combatantId);
    if (target == NULL) {
        return;
    }
#if !defined(jpn)
    char textBuf[0x800];
#endif
    _Z35NotifyLocalizedResourceLoad020dd040iPc(skill->kind, buf);
#if defined(jpn)
    text = buf;
#else
    func_02046608(_Z26GetGlobalField0x1c020421a0v(), 10, buf, textBuf, 0x72, 0, 0);
    text = textBuf;
#endif
    messages = _Z26GetGlobalField0x1c020421a0v();
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
#if defined(jpn)
    _Z14SetByteInRangePhih((unsigned char*)messages, 0, 3);
    _Z14SetByteInRangePhih((unsigned char*)messages, 1, 3);
    _Z14SetByteAtIndexPhih((unsigned char*)messages, 0, 1);
    _Z14SetByteAtIndexPhih((unsigned char*)messages, 1, 1);
    _Z20AppendString02042058PcPKc(text, data_ov000_02185169);
#else
    _Z20AppendString02042058PcPKc(text, _Z28CallFunc020e0434With02153694i(0x3ec));
#endif
    Window* window = &menu->window;
    if (_Z23FindElementByC40205d81cP15Struct_0205d81ci(window, 0x22) != NULL) {
#if defined(jpn)
        TryApplyElemFields0205d5d0((StructA0205d5d0*)window, 0x22, (int)text, 1);
#else
        TryApplyElemFields0205d5d0((StructA0205d5d0*)window, 0x22, (int)text, 1, 0);
#endif
        return;
    }
    int x = entry->x;
    int y = entry->y;
#if defined(jpn)
    window->left = 0xc;
#else
    window->left = 0x10;
#endif
#if defined(jpn)
    window->top = 6;
#else
    window->top = 10;
#endif
#if defined(jpn)
    window->x = (x >> 3) + 0x16;
#else
    window->x = (x >> 3) + 0x10;
#endif
    window->y = y >> 3;
    window->width = 7;
#if defined(jpn)
    window->height = 8;
#else
    window->height = 6;
#endif
    window->field_0xac = 10;
    window->field_0xae = 0xe;
    window->id = 0x22;
#if defined(jpn)
    func_0205d304(window, text, 0, 0, 0, 1, 0);
#else
    func_0205d304(window, text, 0, 0, 0, 1, 0, 0);
#endif
}
