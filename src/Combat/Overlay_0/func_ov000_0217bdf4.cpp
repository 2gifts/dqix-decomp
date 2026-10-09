#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c570;
struct Struct_0205def8;
struct Obj0205eaa0;

extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570* s);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8* s, int clear, int key);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void* obj, int key);
void* GetFieldAt0x150(unsigned char* obj);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
void* GetData02108e10(void);
extern "C" void* _Z24SearchBothTables02079e2cPci(char* p, int key);
extern "C" int _Z35CheckFlagsOrField_0217ab48_0217ab48Pv(void* obj);
extern "C" void func_ov000_021718a4(void* obj);
extern "C" void func_ov000_0217629c(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02176e3c(void* ctx, void* obj, int sel, int a, int b, int c);

struct MenuCtx_0217bdf4 {
    char pad0[0x188];
    char list[0x1d72 - 0x188];
    unsigned short flags;
};

struct MenuGlobals_0217bdf4 {
    int field0;
    int field4;
    MenuCtx_0217bdf4* ctx;
};

struct TableEntry_0217bdf4 {
    int field0;
    unsigned int id : 12;
};

struct MemberInfo_0217bdf4 {
    char pad0[0x950];
    int spellKind;
};

struct MenuObj_0217bdf4 {
    char pad0[0x10];
    signed char selections[8];
    signed char depth;
    char pad19[0x1d - 0x19];
    signed char field1d;
    char pad1e[0x23 - 0x1e];
    signed char field23;
    char pad24[0x26 - 0x24];
    unsigned short field26;
    char pad28[0x38 - 0x28];
    void* field38;
    char pad3c[0x4c - 0x3c];
    int memberIndex;
    char pad50[0x444 - 0x50];
    unsigned char field444;
};

extern MenuGlobals_0217bdf4 data_ov000_02184294;
extern unsigned short data_02114e30;
extern char data_02108760;
extern short data_ov000_02183658[];

// USA: func_ov000_0217bdf4
extern "C" ARM int func_ov000_0217bdf4(MenuObj_0217bdf4* obj, int arg1, int arg2) {
    data_ov000_02184294.ctx->flags |= 0x100;
    obj->field23 = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570*)obj->field38);
    MenuCtx_0217bdf4* ctx = data_ov000_02184294.ctx;
    _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8*)ctx->list, 1, 0x16);
    int t = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    int active = (t | _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(obj->field38, 0x14)) != 0;
    if (active || obj->field444 != 0) {
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(obj->memberIndex);
        if (member == NULL) {
            return -1;
        }
        int kind = ((MemberInfo_0217bdf4*)GetFieldAt0x150((unsigned char*)member))->spellKind;
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0*)&data_02108760, 1, 0);
        obj->field1d = 0;
        void* data = GetData02108e10();
        if (data == NULL) {
            return -1;
        }
        TableEntry_0217bdf4* entry = (TableEntry_0217bdf4*)_Z24SearchBothTables02079e2cPci((char*)data, data_ov000_02183658[kind]);
        if (entry == NULL) {
            return -1;
        }
        obj->field26 = entry->id;
        func_ov000_021718a4(obj);
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8*)ctx->list, 0, 0x16);
        return obj->selections[obj->depth];
    }
    if (_Z35CheckFlagsOrField_0217ab48_0217ab48Pv(obj)) {
        func_ov000_0217629c(obj);
        obj->selections[obj->depth] = 0;
        obj->depth--;
        obj->field23 = -1;
        obj->field1d = -1;
        obj->field26 = 0;
        func_ov000_0217ab8c(obj, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.ctx, obj, obj->selections[obj->depth], data_ov000_02184294.field4, data_ov000_02184294.field0, 0);
    }
    return -1;
}
