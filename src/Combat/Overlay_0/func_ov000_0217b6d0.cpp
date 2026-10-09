#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c570;
struct Struct_0205def8;
struct Obj0205eaa0;

extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570* s);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8* s, int clear, int key);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void* obj, int key);
extern "C" int _Z20IsBitFlagSet0217c4e8Pvi(void* obj, int bit);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern "C" void func_ov000_021716d0(void* obj);
void* GetFieldAt0x150(unsigned char* obj);
extern "C" int _Z35CheckFlagsOrField_0217ab48_0217ab48Pv(void* obj);
extern "C" void func_ov000_0217629c(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02176e3c(void* ctx, void* obj, int sel, int a, int b, int c);

struct MenuCtx_0217b6d0 {
    char pad0[0x188];
    char list[0x1d72 - 0x188];
    unsigned short flags;
};

struct MenuGlobals_0217b6d0 {
    int field0;
    int field4;
    MenuCtx_0217b6d0* ctx;
    short cur;
};

struct MemberInfo_0217b6d0 {
    char pad0[0x962];
    unsigned short lastSpell;
};

struct Window_0217b6d0 {
    char pad0[0xb8];
    unsigned char state;
};

struct MenuObj_0217b6d0 {
    char pad0[0x10];
    signed char selections[8];
    signed char depth;
    char pad19[0x1e - 0x19];
    short selected;
    char pad20[0x26 - 0x20];
    unsigned short actionId;
    char pad28[0x38 - 0x28];
    Window_0217b6d0* window;
    char pad3c[0x4c - 0x3c];
    int memberIndex;
    char pad50[0x444 - 0x50];
    unsigned char field444;
};

extern MenuGlobals_0217b6d0 data_ov000_02184294;
extern unsigned short data_02114e30;
extern char data_02108760;

// USA: func_ov000_0217b6d0
extern "C" ARM int func_ov000_0217b6d0(MenuObj_0217b6d0* obj, int arg1, int arg2) {
    MenuCtx_0217b6d0* ctx;
    short cur;
    data_ov000_02184294.ctx->flags |= 0x100;
    short prev = obj->selected;
    cur = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570*)obj->window);
    obj->selected = cur;
    ctx = data_ov000_02184294.ctx;
    _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8*)ctx->list, 1, 0x23);
    if (prev != cur) {
        return -1;
    }
    int t = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    int active = (t | _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(obj->window, 0x14)) != 0;
    if (active || obj->field444 != 0) {
        if (!_Z20IsBitFlagSet0217c4e8Pvi(obj, cur)) {
            return obj->selections[obj->depth];
        }
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8*)ctx->list, 0, 0x23);
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0*)&data_02108760, 1, 0);
        func_ov000_021716d0(obj);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(obj->memberIndex);
        if (member != NULL) {
            MemberInfo_0217b6d0* info = (MemberInfo_0217b6d0*)GetFieldAt0x150((unsigned char*)member);
            if (info != NULL) {
                info->lastSpell = obj->actionId;
            }
        }
        if (obj->selections[obj->depth] != 0x64) {
            obj->window->state = 0x10;
        }
        return obj->selections[obj->depth];
    }
    if (_Z35CheckFlagsOrField_0217ab48_0217ab48Pv(obj)) {
        func_ov000_0217629c(obj);
        obj->selections[obj->depth] = 0;
        obj->depth--;
        obj->selected = -1;
        obj->actionId = 0;
        func_ov000_0217ab8c(obj, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.ctx, obj, obj->selections[obj->depth], data_ov000_02184294.field4, data_ov000_02184294.field0, 0);
    }
    return -1;
}
