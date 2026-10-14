#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { textOffset=0x28, textSize=0x800, width=12, height=7, xOffset=0x17, lineHeight=8 };
extern "C" void func_020de9cc(int id, char* buf);
#define NotifyLocalizedResourceLoad020dcfc8 func_020de9cc
#else
enum { textOffset=0x5c, textSize=0x960, width=16, height=8, xOffset=0x10, lineHeight=5 };
void NotifyLocalizedResourceLoad020dcfc8(int id, char* buf);
#endif
struct GlobalText {
    char pad0[textOffset];
    char* textBuf;
};

struct ActionInfo {
    char pad0[0x18];
    short messageId;
};

struct BattleActor {
    char pad0[0x22];
    signed char actionSlot;
    char pad23[0x44 - 0x23];
    int x;
    int y;
    int combatantId;
};

struct Struct_0205d81c;
struct StructA0205d5d0;

struct MessageWindow {
    char pad0[0xa0];
    short width;
    short height;
    short posX;
    short posY;
    short field_0xa8;
    short field_0xaa;
    short field_0xac;
    short field_0xae;
    char padB0;
    unsigned char kind;
};

struct BattleMenu {
    char pad0[0x188];
    struct MessageWindow window;
};

GlobalText* GetGlobalField0x1c020421a0();
void* GetFieldAt0x150_02053c6c(unsigned char* obj);
ActionInfo* GetPointerField_02171b9c_02171b9c(void* obj, int idx);
extern "C" void func_02046608(GlobalText* g, int a, char* src, char* dst, int b, int c, int d);
void* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
#if defined(jpn)
extern "C" void func_0205d304(void*, void*, int, int, int, int, int);
#define APPLY_TEXT(s,k,t) TryApplyElemFields0205d5d0(s,k,(int)t,1)
#define DRAW_TEXT(s,t) func_0205d304(s,t,0,0,0,1,0)
#else
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#define APPLY_TEXT(s,k,t) TryApplyElemFields0205d5d0(s,k,(int)t,1,0)
#define DRAW_TEXT(s,t) func_0205d304(s,t,0,0,0,1,0,0)
#endif

// USA: func_ov000_0217964c
extern "C" ARM void func_ov000_0217964c(BattleMenu* menu, BattleActor* actor) {
    char* msg;
    MessageWindow* window;
#if !defined(jpn)
    char buf[0x800];
#endif
    if (actor == NULL) {
        return;
    }
    char* text = GetGlobalField0x1c020421a0()->textBuf;
    memset(text, 0, textSize);
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), actor->combatantId);
    if (combatant == NULL) {
        return;
    }
    GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    ActionInfo* action = GetPointerField_02171b9c_02171b9c(actor, actor->actionSlot);
    if (action == NULL) {
        return;
    }
    if (action->messageId <= 0) {
        return;
    }
    NotifyLocalizedResourceLoad020dcfc8(action->messageId, text);
#if !defined(jpn)
    func_02046608(GetGlobalField0x1c020421a0(), 0xa, text, buf, 0x72, 0, 0);
#endif
    window = &menu->window;
#if defined(jpn)
    msg = text;
#else
    msg = buf;
#endif
    if (FindElementByC40205d81c((struct Struct_0205d81c*)window, 0x24) != NULL) {
        APPLY_TEXT((struct StructA0205d5d0*)window, 0x24, msg);
    } else {
        int x = actor->x;
        int y = actor->y;
        window->width = width;
        window->height = height;
        window->posX = (x >> 3) + xOffset;
        window->posY = y >> 3;
        window->field_0xa8 = 7;
        window->field_0xaa = lineHeight;
        window->field_0xac = 0xa;
        window->field_0xae = 0xe;
        window->kind = 0x24;
        DRAW_TEXT(window, msg);
    }
}
