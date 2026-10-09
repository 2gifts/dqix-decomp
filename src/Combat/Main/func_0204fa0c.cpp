#include <globaldefs.h>
struct Window0204fa0c { char unknown0[0xc5]; unsigned char flags; };
extern "C" char* _Z21GetTableEntry020421b0i(int);
extern "C" void func_0204e1c8(Window0204fa0c*, char*, int, int, int, int, int, int);
// USA: func_0204fa0c
extern "C" ARM void func_0204fa0c(Window0204fa0c* window, short x, short y) {
    if (!(window->flags & 0x40)) return;
    short left = x - 6;
    short top = y - 2;
    short right = left + 8;
    short bottom = top + 8;
    short xs[4];
    short ys[4];
    xs[0] = left;
    xs[2] = left;
    xs[1] = right;
    xs[3] = right;
    ys[0] = top;
    ys[1] = top;
    ys[2] = bottom;
    ys[3] = bottom;
    unsigned char graphicIndex = 16;
    for (unsigned char i = 0; i < 4; ++i) {
        char* graphic = _Z21GetTableEntry020421b0i(graphicIndex);
        if (graphic) {
            func_0204e1c8(window, graphic, xs[i], ys[i], 8, 8, 0xf0, 15);
        }
        ++graphicIndex;
    }
}
