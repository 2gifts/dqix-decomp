#include <globaldefs.h>

extern char data_02114e54;

struct Elem_0205df38 {
    char pad0[0xa8];
    short height;
    short x;
    short y;
    short width;
};

struct Struct_0205d81c {
    char pad0[0x98];
    void* f98;
    struct Elem_0205df38* f9c;
};

void SelectCoordsByFlag0x24(unsigned char* obj, int* out1, int* out2);
extern "C" struct Elem_0205df38* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c* s, int key);

// USA: func_0205df38
extern "C" ARM int func_0205df38(struct Struct_0205d81c* s, int key) {
    int touchY, touchX;
    struct Elem_0205df38* e;
    unsigned char* g;
    short y, h, w, x;
    int yhi, whi;

    if (s->f98 == 0) return 0;
    if (s->f9c == 0) return 0;

    g = (unsigned char*)&data_02114e54;
    if (g[0x55] == 0) goto zero;

    SelectCoordsByFlag0x24(g, &touchY, &touchX);

    e = _Z23FindElementByC40205d81cP15Struct_0205d81ci(s, key);
    if (e == 0) goto zero;

    y = e->y;
    h = e->height;
    w = e->width;
    x = e->x;
    yhi = (short)(y + h);
    whi = (short)(w + x);

    if (touchY > ((y << 0x13) >> 0x10)) {
        if (touchY < ((yhi << 0x13) >> 0x10)) {
            if (touchX > ((w << 0x13) >> 0x10)) {
                if (touchX < ((whi << 0x13) >> 0x10)) {
                    return 1;
                }
            }
        }
    }
zero:
    return 0;
}