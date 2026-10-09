#include <globaldefs.h>
#include "std_library_functions.h"

struct Elem_0205d81c {
    char pad0[0xc2];
    short fieldC2;
};

struct Struct_0205d81c {
    char pad0[0x54];
    int field54;
    char pad1[0xa0 - 0x58];
    short fieldA0;
    short fieldA2;
    short x;
    short y;
    short fieldA8;
    short fieldAA;
    short fieldAC;
    short fieldAE;
    char pad2;
    unsigned char fieldB1;
};

struct GlobalField1c {
    char pad0[0x5c];
    void* buffer;
};

struct Entry02178ba8 {
    char pad0[0x44];
    int x;
    int y;
};

struct Obj02178ba8 {
    char pad0[0x188];
    Struct_0205d81c panel;
};

extern "C" GlobalField1c* _Z26GetGlobalField0x1c020421a0v();
extern "C" int _Z18GetField0_0205bafcPv(void* obj);
extern "C" Elem_0205d81c* _Z23FindElementByC40205d81cP15Struct_0205d81ci(Struct_0205d81c* s, int key);
extern "C" void func_ov000_02178d28(Obj02178ba8* obj, Entry02178ba8* entry);
extern "C" void func_ov000_0217ab8c(Entry02178ba8* entry, int a, int b);
extern "C" void func_ov000_02178f28(Obj02178ba8* obj, Entry02178ba8* entry, void* buf);
extern "C" void func_0205d304(Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e, int f);
extern "C" void func_ov000_02176210(Struct_0205d81c* s, int a, int b);

// USA: func_ov000_02178ba8
extern "C" ARM void func_ov000_02178ba8(Obj02178ba8* obj, Entry02178ba8* entry, int arg2, int arg3) {
    func_ov000_02178d28(obj, entry);
    int x = entry->x;
    int y = entry->y;
    func_ov000_0217ab8c(entry, arg2, arg3);
    Struct_0205d81c* panel = &obj->panel;
    panel->fieldA0 = 0x10;
    panel->fieldA2 = 9;
    panel->x = (x >> 3) + 0x10;
    panel->y = y >> 3;
    panel->fieldA8 = 0xc;
    panel->fieldAA = 8;
    panel->fieldAC = 0xa;
    panel->fieldAE = 0xc;
    panel->fieldB1 = 0xf;
    int flag = 0;
    if (_Z18GetField0_0205bafcPv(&panel->field54) > 4) {
        flag = 1;
    }
    void* buf = _Z26GetGlobalField0x1c020421a0v()->buffer;
    memset(buf, 0, 0x960);
    func_ov000_02178f28(obj, entry, buf);
    func_0205d304(panel, buf, 0, 0, flag, 1, 0, 0);
    Elem_0205d81c* elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci(panel, 0x22);
    if (elem != NULL) {
        elem->fieldC2 = 0;
    }
    func_ov000_02176210(&obj->panel, 0xf, 0x22);
}
