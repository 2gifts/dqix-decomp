#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0205d81c;
struct StructA0205d5d0;

struct Elem_0205d81c {
    char pad[0xc2];
    short field_0xc2;
};

struct Panel_02178074 {
    char pad_0x0[0x58];
    int pageCount;
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

struct TextWorkspace {
#if defined(jpn)
    char unknown0[0x28];
#else
    char unknown0[0x5c];
#endif
    char* textBuffer;
};

TextWorkspace* GetGlobalField0x1c020421a0();
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
extern "C" void func_ov000_021781f8(struct Owner_02178074* obj, struct InStruct_02178074* in);
extern "C" void func_ov000_0217c638(struct Owner_02178074* obj, int a, int b);
extern "C" void func_ov000_0217831c(struct Owner_02178074* obj, void* textBuffer);
extern "C" void func_ov000_02176210(struct Panel_02178074* panel, int slot, int key);
#if defined(jpn)
extern "C" void func_0205d304(struct Panel_02178074* panel, void* textBuffer, int a, int b, int c, int d, int e);
#else
extern "C" void func_0205d304(struct Panel_02178074* panel, void* textBuffer, int a, int b, int c, int d, int e, int f);
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
    char* textBuffer;
#endif
    int pageCount = panel->pageCount;
#if defined(jpn)
    textBuffer = GetGlobalField0x1c020421a0()->textBuffer;
#else
    char* textBuffer = GetGlobalField0x1c020421a0()->textBuffer;
#endif
#if defined(jpn)
    memset(textBuffer, 0, 0x800);
#else
    memset(textBuffer, 0, 0x960);
#endif
    func_ov000_0217831c(obj, textBuffer);
    int multiplePages = (pageCount > 1) ? 1 : 0;
#if defined(jpn)
    func_0205d304(&obj->panel, textBuffer, 0, 0, multiplePages, 1, 0);
#else
    func_0205d304(panel, textBuffer, 0, 0, multiplePages, 1, 0, 0);
#endif
    struct Elem_0205d81c* elem = FindElementByC40205d81c((struct Struct_0205d81c*)panel, 0x21);
    if (elem != 0) {
        elem->field_0xc2 = 0;
    }
#if defined(jpn)
    func_ov000_02176210(&obj->panel, 7, 0x21);
#else
    func_ov000_02176210(panel, 7, 0x21);
#endif
#if defined(jpn)
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)&obj->panel, 7, (int)textBuffer, 1);
#else
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)panel, 7, (int)textBuffer, 1, 0);
#endif
}
