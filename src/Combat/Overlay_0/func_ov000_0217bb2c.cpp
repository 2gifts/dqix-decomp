#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c570;
struct Obj0205eaa0;
struct S_10088;

extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570* s);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern "C" int _Z35CheckFlagsOrField_0217ab48_0217ab48Pv(void* obj);
int IsFlag10088Set(struct S_10088* obj);
GameObject* GetCombatantWithFlag0x100(GameState* gameState, int combatantId);

struct MenuEntry_0217bb2c {
    char pad0[4];
    unsigned int id : 12;
    unsigned int rest4 : 20;
    char pad8[0x10];
    unsigned int low18 : 5;
    unsigned int kind : 7;
    unsigned int rest18 : 20;
};

extern "C" int func_ov000_0217b518(void* obj, int arg1, int arg2);
extern "C" int func_ov000_0217b6d0(void* obj, int arg1, int arg2);
extern "C" int func_ov000_0217b8a4(void* obj, int arg1, int arg2);
extern "C" void func_ov000_0217629c(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" MenuEntry_0217bb2c* func_ov000_02170cf8(void* obj, int val);
extern "C" void func_ov000_02176e3c(void* ctx, void* obj, int sel, int a, int b, int c);

struct MenuCtx_0217bb2c {
    char pad0[0x188];
#if defined(jpn)
    char list[0x1faa - 0x188];
#else
    char list[0x1d72 - 0x188];
#endif
    unsigned short flags;
};

struct MenuGlobals_0217bb2c {
#if defined(jpn)
    MenuCtx_0217bb2c* ctx;
    int field0;
    int field4;
#else
    int field0;
    int field4;
    MenuCtx_0217bb2c* ctx;
#endif
};

struct MenuObj_0217bb2c {
    char pad0[0x10];
    signed char selections[8];
    signed char depth;
    char pad19[0x21 - 0x19];
    signed char cursor;
    char pad22[0x26 - 0x22];
    unsigned short actionId;
    char pad28[0x2e - 0x28];
    signed char field2e;
    char pad2f[0x30 - 0x2f];
    signed char* order;
    char pad34[0x38 - 0x34];
    void* window;
#if defined(jpn)
    char pad3c[0x47d - 0x3c];
#else
    char pad3c[0x43d - 0x3c];
#endif
    signed char field43d;
    char pad43e[0x441 - 0x43e];
    signed char field441;
    signed char field442;
    char pad443;
    unsigned char field444;
};

extern MenuGlobals_0217bb2c data_ov000_02184294;
extern unsigned short data_02114e30;
extern char data_02108760;

// USA: func_ov000_0217bb2c
extern "C" ARM int func_ov000_0217bb2c(MenuObj_0217bb2c* obj, int arg1, int arg2) {
    data_ov000_02184294.ctx->flags |= 0x100;
    obj->cursor = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570*)obj->window);
    obj->field2e = -1;
    if (obj->field441 != arg1) {
        obj->field441 = arg1;
        obj->field442 = obj->order[obj->cursor];
        obj->field444 = 1;
        func_ov000_0217629c(obj);
        obj->selections[obj->depth] = 0;
        obj->depth--;
        obj->cursor = -1;
        obj->field2e = -1;
        func_ov000_0217ab8c(obj, arg1, arg2);
        int result = -1;
        switch (obj->selections[obj->depth]) {
        case 0xf:
            result = func_ov000_0217b518(obj, data_ov000_02184294.field4, data_ov000_02184294.field0);
            break;
        case 0x10:
            result = func_ov000_0217b6d0(obj, data_ov000_02184294.field4, data_ov000_02184294.field0);
            break;
        case 0x11:
            result = func_ov000_0217b8a4(obj, data_ov000_02184294.field4, data_ov000_02184294.field0);
            break;
        }
        return result;
    }
    int t = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    int active = (t | IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)obj->window, 0x14)) != 0;
    if (active) {
        GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), obj->order[obj->cursor]);
        if (combatant == NULL) {
            return -1;
        }
        int ok = !IsFlag10088Set((struct S_10088*)combatant);
        MenuEntry_0217bb2c* entry = func_ov000_02170cf8(obj, obj->actionId);
        if (entry != NULL) {
            if (entry->kind == 0x12) {
                ok = IsFlag10088Set((struct S_10088*)combatant);
            }
            if (entry->id == 0x26 || entry->id == 0x27 || entry->id == 0x54) {
                ok = 1;
            }
        } else {
            ok = 1;
        }
        if (ok) {
            obj->field43d = obj->selections[obj->depth];
            obj->field2e = obj->order[obj->cursor];
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0*)&data_02108760, 1, 0);
            obj->depth++;
            obj->selections[obj->depth] = 100;
        }
    } else if (_Z35CheckFlagsOrField_0217ab48_0217ab48Pv(obj)) {
        func_ov000_0217629c(obj);
        obj->selections[obj->depth] = 0;
        obj->depth--;
        obj->cursor = -1;
        obj->field2e = -1;
        func_ov000_0217ab8c(obj, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.ctx, obj, obj->selections[obj->depth], data_ov000_02184294.field4, data_ov000_02184294.field0, 0);
    }
    return -1;
}
