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

GlobalData* GetGlobalField0x1c020421a0(void);
extern "C" void* memset(void* dst, int c, unsigned int n);
SkillData* GetBoundedField156_02171674(void*, int);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gs, int id);
#if defined(jpn)
#define _Z35NotifyLocalizedResourceLoad020dd040iPc func_020dea34
#endif
extern "C" void _Z35NotifyLocalizedResourceLoad020dd040iPc(int id, char* buf);
extern "C" void func_02046608(GlobalData* messages, int a, const char* input, char* output, int b, int c, int d);
extern "C" void func_02046380(GlobalData* messages);
int IsFlag0x18Bit0x200Set_ov000_02153a8c(GameObject* obj);
int AdjustValueByFieldFlag_020dd290(void*, unsigned int);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
const char* CallFunc020e0434With02153694_020e51cc(int key);
int AppendString02042058(char* dst, const char* src);
struct Struct_0205d81c;
void* FindElementByC40205d81c(Struct_0205d81c*, int);
#if defined(jpn)
extern "C" void func_0205d304(Window* window, char* text, int a, int b, int c, int d, int e);
void SetByteInRange_020465f0(unsigned char*, int, unsigned char);
void SetByteAtIndex_020465d8(unsigned char*, int, unsigned char);
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
    char* buf = GetGlobalField0x1c020421a0()->workBuffer;
#if defined(jpn)
    memset(buf, 0, 0x800);
#else
    memset(buf, 0, 0x960);
#endif
    GameState* gs = GameState::GetInstance();
    skill = GetBoundedField156_02171674(entry, cursor);
    if (skill == NULL) {
        return;
    }
    combatant = gs->GetCombatantByIndex(entry->combatantId);
    if (combatant == NULL) {
        return;
    }
    target = GetCombatantWithFlag0x100_0200ff1c(gs, entry->combatantId);
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
    func_02046608(GetGlobalField0x1c020421a0(), 10, buf, textBuf, 0x72, 0, 0);
    text = textBuf;
#endif
    messages = GetGlobalField0x1c020421a0();
    func_02046380(messages);
    int value;
    if (IsFlag0x18Bit0x200Set_ov000_02153a8c(combatant)) {
        value = 0;
    } else if (skill->kind == 0x28 && entry->power < 0x14) {
        value = 0x14;
    } else if (skill->adjustKey >= 0xff) {
        value = entry->power;
    } else {
        value = AdjustValueByFieldFlag_020dd290(target, skill->adjustKey);
    }
    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, value);
    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 1, entry->power);
#if defined(jpn)
    SetByteInRange_020465f0((unsigned char*)messages, 0, 3);
    SetByteInRange_020465f0((unsigned char*)messages, 1, 3);
    SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
    SetByteAtIndex_020465d8((unsigned char*)messages, 1, 1);
    AppendString02042058(text, data_ov000_02185169);
#else
    AppendString02042058(text, CallFunc020e0434With02153694_020e51cc(0x3ec));
#endif
    Window* window = &menu->window;
    if (FindElementByC40205d81c((Struct_0205d81c*)window, 0x22) != NULL) {
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
