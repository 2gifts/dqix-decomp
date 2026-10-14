#include <globaldefs.h>
#include "std_library_functions.h"

struct Canvas0204e998;
struct Entry_0205d6a0;
int CheckField0x9cSetWhenField0xd4Present_0204c7e0(unsigned char* obj);
void InitAndFillIndexBuffer0204c964(struct Canvas0204e998* canvas);
void* CopyStaticData02174da4(int unused, void* dest);
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);
void SetChannelBFlag0205cf04(void* obj);
void SetChannelAFlag0205cef8(void* obj);
void SetupDualPointerTables0205cf28(unsigned char* obj, int a, int count, int b);
extern "C" void func_0205bb04(void* cursor, int index);
extern "C" void func_0205d7a0(unsigned char* obj, int val);
int GetGlobalField0x1c020421a0(void);
extern "C" void func_ov000_0217737c(void* obj, void* buf);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif
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
#if defined(jpn)
    char pad_23a[0x1fa1 - 0x188 - sizeof(struct Window02177184)];
#else
    char pad_23a[0x1d69 - 0x188 - sizeof(struct Window02177184)];
#endif
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
    if (CheckField0x9cSetWhenField0xd4Present_0204c7e0(canvas)) {
        InitAndFillIndexBuffer0204c964((struct Canvas0204e998*)canvas);
        menu->flags &= ~2;
        return;
    }
    int entries[4];
    CopyStaticData02174da4((int)menu, entries);
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (entries[i] >= 0) {
            count++;
        }
    }
    menu->selection = 0;
    ResetEntryList0205d6a0((struct Entry_0205d6a0*)window, 1);
    SetChannelBFlag0205cf04(window);
    SetChannelAFlag0205cef8(window);
    SetupDualPointerTables0205cf28((unsigned char*)window, 1, count, 0);
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
#if defined(jpn)
    void* buf = *(void**)(GetGlobalField0x1c020421a0() + 0x28);
    memset(buf, 0, 0x800);
#else
    void* buf = *(void**)(GetGlobalField0x1c020421a0() + 0x5c);
    memset(buf, 0, 0x960);
#endif
    func_ov000_0217737c(menu, buf);
#if defined(jpn)
    func_0205d304(window, buf, 0, 1, 0, 1, 0);
#else
    func_0205d304(window, buf, 0, 1, 0, 1, 0, 0);
#endif
    func_ov000_0217a8f4(menu);
}
