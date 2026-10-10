#include <globaldefs.h>
#include "std_library_functions.h"
#include "System/Graphics.h"

extern "C" void func_02047554(void* object, int mode, int param1, int value);

struct UvBlock0202f45c {
    int v[8][2];
};
extern struct UvBlock0202f45c data_020e73fc;

struct Inner0202f45c {
    char pad0[0x18];
    unsigned short field18;
};

// USA: func_0202f45c
extern "C" ARM void func_0202f45c(void* obj, int p1, int p2, int p3, int p4, int p5) {
    if (p3 < 0x8000 || p4 < 0x8000) return;

    GXFIFO_TEXIMAGE_PARAMS = 0x20030000;
    GXFIFO_POLYGON_ATTRIBUTES = 0x3b1200c0;
    GXFIFO_MATRIX_PUSH = 0;
    GXFIFO_MATRIX_TRANSLATE = p1 + 0x3000;
    GXFIFO_MATRIX_TRANSLATE = p2 + 0x3000;
    GXFIFO_MATRIX_TRANSLATE = 0x400000;
    GXFIFO_MATRIX_SCALE = p3 - 0x6000;
    GXFIFO_MATRIX_SCALE = p4 - 0x6000;
    GXFIFO_MATRIX_SCALE = 0x1000;
    GXFIFO_POLYGON_BEGIN = 1;
    GXFIFO_VERTEX_COLOR = 0;
    GXFIFO_VERTEX_16 = 0;
    GXFIFO_VERTEX_16 = 0;
    GXFIFO_VERTEX_16 = 0x1000;
    GXFIFO_VERTEX_16 = 0;
    GXFIFO_VERTEX_16 = 0x10001000;
    GXFIFO_VERTEX_16 = 0;
    GXFIFO_VERTEX_16 = 0x10000000;
    GXFIFO_VERTEX_16 = 0;
    GXFIFO_POLYGON_END = 0;
    GXFIFO_MATRIX_POP = 1;

    if (p5 == 0) return;

    int v3 = (int)((p3 - 0x8000) / 6.0f);
    int v4 = (int)((p4 - 0x8000) / 6.0f);

    int xy[8][2];
    xy[0][0] = p1 - 0x1000;
    xy[0][1] = p2 - 0x1000;
    xy[1][0] = (p1 + 0x3000) - (v3 & ~0xfff);
    xy[1][1] = p2 - 0x1000;
    xy[2][0] = (p1 + p3) - 0x7000;
    xy[2][1] = p2 - 0x1000;
    xy[3][0] = (p1 + p3) - 0x7000;
    xy[3][1] = (p2 + 0x3000) - (v4 & ~0xfff);
    xy[4][0] = (p1 + p3) - 0x7000;
    xy[4][1] = (p2 + p4) - 0x7000;
    xy[5][0] = (p1 + 0x3000) - (v3 & ~0xfff);
    xy[5][1] = (p2 + p4) - 0x7000;
    xy[6][0] = p1 - 0x1000;
    xy[6][1] = (p2 + p4) - 0x7000;
    xy[7][0] = p1 - 0x1000;
    xy[7][1] = (p2 + 0x3000) - (v4 & ~0xfff);

    struct UvBlock0202f45c uv = data_020e73fc;
    uv.v[1][0] = v3;
    uv.v[5][0] = v3;
    uv.v[3][1] = v4;
    uv.v[7][1] = v4;

    unsigned char* entry = (unsigned char*)obj;
    for (int i = 0; i < 8; ++i) {
        int* xrow = xy[i];
        int* urow = uv.v[i];
        GXFIFO_MATRIX_PUSH = 0;
        int posY = xrow[1];
        GXFIFO_MATRIX_TRANSLATE = xrow[0];
        GXFIFO_MATRIX_TRANSLATE = posY;
        GXFIFO_MATRIX_TRANSLATE = 0x400000;
        int texV = urow[1];
        GXFIFO_MATRIX_SCALE = urow[0];
        GXFIFO_MATRIX_SCALE = texV;
        GXFIFO_MATRIX_SCALE = 0x1000;
        Inner0202f45c* inner = *(Inner0202f45c**)((char*)obj + 0x440);
        unsigned short value = inner->field18;
        *(unsigned short*)(entry + 0x80) = value;
        func_02047554(entry, 0, 1, value);
        GXFIFO_MATRIX_POP = 1;
        entry += 0x88;
    }
}
