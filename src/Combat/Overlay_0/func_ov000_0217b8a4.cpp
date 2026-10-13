// USA: func_ov000_0217b8a4
#include <globaldefs.h>

struct Struct_0205c570;
struct Struct_0205bcdc;
struct Struct_0205def8;
struct Obj_0205da38;
struct Obj0205eaa0;
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(Struct_0205c570*);
extern "C" int abs(int);
extern "C" void _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(Struct_0205bcdc*, int);
extern "C" void func_0205bb04(void*, int);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(Struct_0205def8*, int, int);
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
#if defined(jpn)
extern "C" void func_ov000_02171e60(void*);
#else
extern "C" void func_ov000_02171e60(void*);
#endif
extern "C" int _Z35CheckFlagsOrField_0217ab48_0217ab48Pv(void*);
extern "C" void func_ov000_0217629c(void*);
extern "C" void func_ov000_0217ab8c(void*, int, int);
extern "C" void func_ov000_02176e3c(void*, void*, int, int, int, int);
struct MenuContext0217b8a4 {
    char pad_0[0x188];
#if defined(jpn)
    char list[0x1faa - 0x188];
#else
    char list[0x1d72 - 0x188];
#endif
    unsigned short flags;
};
struct MenuGlobals0217b8a4 {
#if defined(jpn)
    MenuContext0217b8a4* context;
    int field_0;
    int field_4;
#else
    int field_0;
    int field_4;
    MenuContext0217b8a4* context;
#endif
};
struct MenuWindow0217b8a4 {
    char pad_0[4];
    char selection[0x54 - 4];
    char controls[0x68 - 0x54];
    int row;
    char pad_6c[0xb8 - 0x6c];
    unsigned char state;
};
struct MenuItem0217b8a4 { char pad_0[0x18]; short count; };
struct Menu0217b8a4 {
    char pad_0[0x10];
    signed char selections[8];
    signed char depth;
    char pad_19[0x22 - 0x19];
    signed char cursor;
    char pad_23[0x2c - 0x23];
    short selectedCount;
    char pad_2e[0x38 - 0x2e];
    MenuWindow0217b8a4* window;
#if defined(jpn)
    char pad_3c[0x430 - 0x3c];
#else
    char pad_3c[0x3f0 - 0x3c];
#endif
    MenuItem0217b8a4* items[21];
    unsigned char field_444;
};
extern MenuGlobals0217b8a4 data_ov000_02184294;
extern unsigned short data_02114e30;
extern Obj0205eaa0 data_02108760;

// USA: func_ov000_0217b8a4
extern "C" ARM int func_ov000_0217b8a4(Menu0217b8a4* obj, int arg1, int arg2) {
    signed char row;
    data_ov000_02184294.context->flags |= 0x100;
    MenuWindow0217b8a4* window = obj->window;
    signed char previous = obj->cursor;
    signed char cursor = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)obj->window);
    row = window->row;
    signed char originalCursor = cursor;
    signed char oldColumn = obj->cursor & 3;
    signed char newColumn = cursor & 3;
    if ((signed char)abs(newColumn - oldColumn) == 1 && oldColumn < newColumn) {
        if (!obj->items[cursor]) cursor = row * 4;
    }
    while (!obj->items[cursor]) cursor--;
    while (obj->items[cursor]) {
        if (obj->items[cursor]->count > 0) break;
        cursor--;
    }
    if (originalCursor != cursor) {
        _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci((Struct_0205bcdc*)window->selection, cursor);
        func_0205bb04(window->controls, cursor);
    }
    obj->cursor = cursor;
    obj->selectedCount = -1;
    MenuContext0217b8a4* context = data_ov000_02184294.context;
    _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((Struct_0205def8*)context->list, 1, 0x24);
    if (previous != cursor) return -1;
    int flag = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    int active = (flag | IsActiveElementFlag2Set0205da38((Obj_0205da38*)obj->window, 0x14)) != 0;
    if (active || obj->field_444) {
        MenuItem0217b8a4* item = obj->items[cursor];
        if (!item) return -1;
        short count = item->count;
        if (count <= 0) return -1;
        obj->selectedCount = count;
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((Struct_0205def8*)context->list, 0, 0x24);
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
#if defined(jpn)
        func_ov000_02171e60(obj);
#else
        func_ov000_02171e60(obj);
#endif
        if (obj->selections[obj->depth] != 100) obj->window->state = 0x11;
        return obj->selections[obj->depth];
    }
    if (_Z35CheckFlagsOrField_0217ab48_0217ab48Pv(obj)) {
        func_ov000_0217629c(obj);
        obj->selections[obj->depth] = 0;
        obj->depth--;
        obj->cursor = -1;
        func_ov000_0217ab8c(obj, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.context, obj, obj->selections[obj->depth], data_ov000_02184294.field_4, data_ov000_02184294.field_0, 0);
    }
    return -1;
}
