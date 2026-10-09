#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct GlobalText {
    char pad0[0x5c];
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

extern "C" GlobalText* _Z26GetGlobalField0x1c020421a0v();
void* GetFieldAt0x150(unsigned char* obj);
extern "C" ActionInfo* _Z33GetPointerField_02171b9c_02171b9cPvi(void* obj, int idx);
extern "C" void _Z35NotifyLocalizedResourceLoad020dcfc8iPc(int id, char* buf);
extern "C" void func_02046608(GlobalText* g, int a, char* src, char* dst, int b, int c, int d);
extern "C" void* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c* s, int key);
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0* s, int key, int buf, int a, unsigned char b);
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);

// USA: func_ov000_0217964c
extern "C" ARM void func_ov000_0217964c(BattleMenu* menu, BattleActor* actor) {
    char buf[0x800];
    if (actor == NULL) {
        return;
    }
    char* text = _Z26GetGlobalField0x1c020421a0v()->textBuf;
    memset(text, 0, 0x960);
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), actor->combatantId);
    if (combatant == NULL) {
        return;
    }
    GetFieldAt0x150((unsigned char*)combatant);
    ActionInfo* action = _Z33GetPointerField_02171b9c_02171b9cPvi(actor, actor->actionSlot);
    if (action == NULL) {
        return;
    }
    if (action->messageId <= 0) {
        return;
    }
    _Z35NotifyLocalizedResourceLoad020dcfc8iPc(action->messageId, text);
    func_02046608(_Z26GetGlobalField0x1c020421a0v(), 0xa, text, buf, 0x72, 0, 0);
    char* msg;
    MessageWindow* window = &menu->window;
    msg = buf;
    if (_Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c*)window, 0x24) != NULL) {
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)window, 0x24, (int)msg, 1, 0);
    } else {
        int x = actor->x;
        int y = actor->y;
        window->width = 0x10;
        window->height = 8;
        window->posX = (x >> 3) + 0x10;
        window->posY = y >> 3;
        window->field_0xa8 = 7;
        window->field_0xaa = 5;
        window->field_0xac = 0xa;
        window->field_0xae = 0xe;
        window->kind = 0x24;
        func_0205d304(window, msg, 0, 0, 0, 1, 0, 0);
    }
}
