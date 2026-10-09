#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);

struct Container020e0310;
extern "C" char* _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);

struct Obj0203c108 {
    char pad[0x14];
    short idx;
};
extern "C" void _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(struct Obj0203c108* obj, char* fmt);

int IsFlag0x18Bit0x200Set(GameObject* obj);
int AdjustValueByFieldFlag(void* obj, unsigned int value);

struct Entry02171458 {
    int name;
    unsigned int id : 12;
    unsigned int rest4 : 20;
    unsigned int value : 8;
    unsigned int rest8 : 24;
};

extern "C" int func_ov000_02171210(struct Entry02171458* entry, void* menu);
extern "C" struct Entry02171458* func_ov000_02170cf8(void* menu, int id);
extern "C" void* __clear(void* dst, int count);
extern "C" void func_020e4864(int a, char* b, int c, int d, int e, int f);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char* src, char* dst, int flag);

struct MenuState02171458 {
    char pad0[6];
    short limit;
    signed char results[8];
    signed char depth;
    char pad11[0x15 - 0x11];
    unsigned char field15;
    char pad16[0x18 - 0x16];
    signed char cursor;
    char pad19[0x1e - 0x19];
    unsigned short selectedId;
};

struct Menu02171458 {
    char pad0[4];
    struct Container020e0310* container;
    struct MenuState02171458 state;
    char pad28[0x4c - 0x28];
    int combatantId;
    struct Obj0203c108 label;
    char pad66[0x9c - 0x66];
    struct Entry02171458* entries[1];
};

// USA: func_ov000_02171458
extern "C" ARM void func_ov000_02171458(struct Menu02171458* menu) {
    func_02012fe4();
    struct MenuState02171458* state = &menu->state;
    int cursor = state->cursor;
    if (menu->entries[cursor] == NULL) {
        state->depth++;
        state->results[menu->state.depth] = 0xe;
        state->field15 = 0;
        _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(&menu->label, _Z21GetFieldByKey020e0434P17Container020e0310i(menu->container, 5));
        return;
    }
    GameObject* c = GetCombatantWithFlag0x100(GameState::GetInstance(), menu->combatantId);
    int value = menu->entries[cursor]->value;
    if (c != NULL && IsFlag0x18Bit0x200Set(c)) {
        value = 0;
    } else if (menu->entries[cursor]->id == 0x28) {
        value = 0x14;
    } else if (menu->entries[cursor]->value >= 0xff) {
        value = 1;
    } else {
        value = AdjustValueByFieldFlag(c, value);
    }
    if (menu->state.limit < value) {
        state->depth++;
        state->results[menu->state.depth] = 0x1a;
        return;
    }
    state->selectedId = menu->entries[cursor]->id;
    state->depth++;
    state->results[state->depth] = func_ov000_02171210(menu->entries[cursor], menu);
    struct Entry02171458* entry = func_ov000_02170cf8(menu, state->selectedId);
    if (entry == NULL) {
        return;
    }
    char buf1[0x80];
    __clear(buf1, 0x80);
    char buf2[0x80];
    __clear(buf2, 0x80);
    func_020e4864(entry->name, buf1, 1, 0, 0, 0);
    _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(buf1, buf2, 0);
    _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(&menu->label, buf2);
}
