#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define func_ov000_02178074 func_ov000_021795bc
#endif

struct Struct_0205d81c;
struct StructA0205d5d0;

struct Elem_0205d81c {
    char pad[0xc2];
    short field_0xc2;
};

struct Panel_02178074 {
    char pad_0x0[0x58];
    int field_0x58;
    char pad_0x5c[0x44];
    short width;
    short height;
    short tileX;
    short tileY;
    short field_0xa8;
    short field_0xaa;
    short field_0xac;
    short field_0xae;
    char pad_0xb0;
    unsigned char field_0xb1;
};

struct Owner_02178074 {
    char pad[0x188];
    struct Panel_02178074 panel;
};

struct InStruct_02178074 {
    char pad[0x44];
    int x;
    int y;
};

extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" struct Elem_0205d81c* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c* s, int key);
#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0* a, int b, int c, int d);
#else
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
#endif

extern "C" void func_ov000_021781f8(struct Owner_02178074* obj, struct InStruct_02178074* in);
extern "C" void func_ov000_0217c638(struct Owner_02178074* obj, int a, int b);
extern "C" void func_ov000_0217831c(struct Owner_02178074* obj, void* buf);
extern "C" void func_ov000_02176210(struct Panel_02178074* panel, int slot, int key);
#if defined(jpn)
extern "C" void func_0205d304(struct Panel_02178074* panel, void* buf, int a, int b, int c, int d, int e);
#else
extern "C" void func_0205d304(struct Panel_02178074* panel, void* buf, int a, int b, int c, int d, int e, int f);
#endif

// USA: func_ov000_02178074
extern "C" ARM void func_ov000_02178074(struct Owner_02178074* obj, struct InStruct_02178074* in, int arg2, int arg3) {
    if (in == 0) {
        return;
    }
    int x = in->x;
    int y = in->y;
    func_ov000_021781f8(obj, in);
    func_ov000_0217c638(obj, arg2, arg3);
    struct Panel_02178074* panel = &obj->panel;
#if defined(jpn)
    panel->width = 0x10;
#else
    panel->width = 0x12;
#endif
    panel->height = 9;
#if defined(jpn)
    panel->tileX = (x >> 3) + 9;
#else
    panel->tileX = (x >> 3) + 0xe;
#endif
    panel->tileY = y >> 3;
    panel->field_0xa8 = 0xc;
    panel->field_0xaa = 8;
    panel->field_0xac = 0xa;
    panel->field_0xae = 0xc;
    panel->field_0xb1 = 7;
#if defined(jpn)
    void* buf;
#endif
    int count = panel->field_0x58;
#if defined(jpn)
    buf = *(void**)((char*)_Z26GetGlobalField0x1c020421a0v() + 0x28);
#else
    void* buf = *(void**)((char*)_Z26GetGlobalField0x1c020421a0v() + 0x5c);
#endif
#if defined(jpn)
    memset(buf, 0, 0x800);
#else
    memset(buf, 0, 0x960);
#endif
    func_ov000_0217831c(obj, buf);
    int flag = (count > 1) ? 1 : 0;
#if defined(jpn)
    func_0205d304(&obj->panel, buf, 0, 0, flag, 1, 0);
#else
    func_0205d304(panel, buf, 0, 0, flag, 1, 0, 0);
#endif
    struct Elem_0205d81c* elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c*)panel, 0x21);
    if (elem != 0) {
        elem->field_0xc2 = 0;
    }
#if defined(jpn)
    func_ov000_02176210(&obj->panel, 7, 0x21);
#else
    func_ov000_02176210(panel, 7, 0x21);
#endif
#if defined(jpn)
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)&obj->panel, 7, (int)buf, 1);
#else
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)panel, 7, (int)buf, 1, 0);
#endif
}
