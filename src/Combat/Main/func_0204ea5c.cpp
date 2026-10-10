#include <globaldefs.h>

struct Wnd0204cd60 {
    char pad0[8];
    unsigned char* buf;
    short arrA[18];
    short arrB[18];
    short arrC[18];
    short arrD[18];
    char pad9C[4];
    int fA0;
    int fA4;
    short fA8;
    short fAA;
    char padAC[4];
    short fB0;
    short fB2;
    char padB4[2];
    short fB6;
    char padB8[2];
    short fBA;
    short fBC;
    short fBE;
    char padC0[5];
    unsigned char flags;
    unsigned char fC6;
    unsigned char fC7;
    char padC8[0x10];
    unsigned char bit0 : 2;
    unsigned char useBg : 1;
    unsigned char bit3 : 5;
    char padD9[2];
    signed char margins[4];
};

extern "C" int func_0204fd00(Wnd0204cd60* ctx, int mask);
extern "C" void func_0204f914(Wnd0204cd60* wnd, int mode, short x0, short y0, short x1, short y1);
extern "C" void* _Z21GetTableEntry020421b0i(int idx);
extern "C" void func_0204e1c8(Wnd0204cd60* wnd, char* entry, int x, int y, int w, int h, int color, int font);

// USA: func_0204ea5c
extern "C" ARM void func_0204ea5c(Wnd0204cd60* wnd) {
    if (wnd->flags & 0x10) {
        return;
    }
    if (!func_0204fd00(wnd, 1)) {
        func_0204f914(wnd, 0, 0, 0, 8, 8);
        char* entry = (char*)_Z21GetTableEntry020421b0i(21);
        if (entry) {
            func_0204e1c8(wnd, entry, 0, 0, 8, 8, 0xf0, 0xf);
        }
    }
    if (!func_0204fd00(wnd, 2)) {
        func_0204f914(wnd, 0, (short)((wnd->fA8 - 1) << 3), 0, (short)(wnd->fA8 << 3), 8);
        char* entry = (char*)_Z21GetTableEntry020421b0i(22);
        if (entry) {
            func_0204e1c8(wnd, entry, (short)((wnd->fA8 - 1) << 3), 0, 8, 8, 0xf0, 0xf);
        }
    }
    if (!func_0204fd00(wnd, 4)) {
        func_0204f914(wnd, 0, 0, (short)((wnd->fAA - 1) << 3), 8, (short)(wnd->fAA << 3));
        char* entry = (char*)_Z21GetTableEntry020421b0i(24);
        if (entry) {
            func_0204e1c8(wnd, entry, 0, (short)((wnd->fAA - 1) << 3), 8, 8, 0xf0, 0xf);
        }
    }
    if (!func_0204fd00(wnd, 8)) {
        func_0204f914(wnd, 0, (short)((wnd->fA8 - 1) << 3), (short)((wnd->fAA - 1) << 3), (short)(wnd->fA8 << 3), (short)(wnd->fAA << 3));
        char* entry = (char*)_Z21GetTableEntry020421b0i(23);
        if (entry) {
            func_0204e1c8(wnd, entry, (short)((wnd->fA8 - 1) << 3), (short)((wnd->fAA - 1) << 3), 8, 8, 0xf0, 0xf);
        }
    }
}
