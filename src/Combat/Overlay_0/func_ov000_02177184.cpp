#include <globaldefs.h>
#include "std_library_functions.h"

struct Canvas0204e998;
struct Entry_0205d6a0;
int CheckField0x9cSetWhenField0xd4Present(unsigned char* obj);
extern "C" void _Z30InitAndFillIndexBuffer0204c964P14Canvas0204e998(struct Canvas0204e998* canvas);
extern "C" void* _Z22CopyStaticData02174da4iPv(int unused, void* dest);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0* a, int flag);
extern "C" void _Z23SetChannelBFlag0205cf04Pv(void* obj);
extern "C" void _Z23SetChannelAFlag0205cef8Pv(void* obj);
extern "C" void _Z30SetupDualPointerTables0205cf28Phiii(unsigned char* obj, int a, int count, int b);
extern "C" void func_0205bb04(void* cursor, int index);
extern "C" void func_0205d7a0(unsigned char* obj, int val);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void func_ov000_0217737c(void* obj, void* buf);
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
extern "C" void func_ov000_0217a8f4(void* obj);

struct Window02177184 {
    char pad_0[0x54];
    char cursor[4];
    int field_0x58;
    char pad_5c[0x9c - 0x5c];
    unsigned char* canvas;
    short left;
    short top;
    short width;
    short height;
    short field_0xa8;
    short field_0xaa;
    short field_0xac;
    short field_0xae;
    char pad_b0;
    unsigned char field_0xb1;
};

struct Menu02177184 {
    char pad_0[0x188];
    struct Window02177184 window;
    char pad_23a[0x1d69 - 0x188 - sizeof(struct Window02177184)];
    signed char selection;
    char pad_1d6a[0x1d72 - 0x1d6a];
    unsigned short flags;
};

// USA: func_ov000_02177184
extern "C" ARM void func_ov000_02177184(struct Menu02177184* menu, int active) {
    if (!active) {
        return;
    }
    struct Window02177184* window = &menu->window;
    unsigned char* canvas = window->canvas;
    if (CheckField0x9cSetWhenField0xd4Present(canvas)) {
        _Z30InitAndFillIndexBuffer0204c964P14Canvas0204e998((struct Canvas0204e998*)canvas);
        menu->flags &= ~2;
        return;
    }
    int entries[4];
    _Z22CopyStaticData02174da4iPv((int)menu, entries);
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (entries[i] >= 0) {
            count++;
        }
    }
    menu->selection = 0;
    _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)window, 1);
    _Z23SetChannelBFlag0205cf04Pv(window);
    _Z23SetChannelAFlag0205cef8Pv(window);
    _Z30SetupDualPointerTables0205cf28Phiii((unsigned char*)window, 1, count, 0);
    window->field_0x58 = 1;
    func_0205bb04(window->cursor, 0);
    if (count == 3) {
        window->left = 8;
        window->top = 6;
    }
    if (count == 4) {
        window->left = 8;
        window->top = 1;
    }
    window->width = 9;
    window->height = 1;
    if (count == 3) {
        window->field_0xa8 = 0xc;
        window->field_0xaa = 8;
    }
    if (count == 4) {
        window->field_0xa8 = 0xc;
        window->field_0xaa = 4;
    }
    window->field_0xac = 0xa;
    window->field_0xae = 0xb;
    window->field_0xb1 = 1;
    func_0205d7a0((unsigned char*)window, menu->selection);
    void* buf = *(void**)(_Z26GetGlobalField0x1c020421a0v() + 0x5c);
    memset(buf, 0, 0x960);
    func_ov000_0217737c(menu, buf);
    func_0205d304(window, buf, 0, 1, 0, 1, 0, 0);
    func_ov000_0217a8f4(menu);
}
