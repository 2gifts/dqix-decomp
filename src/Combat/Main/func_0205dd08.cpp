#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;

struct Elem_0205d81c* FindElementForFieldB0_0205d8c4(struct Struct_0205d81c* s);
int IsField0x9cEqual3_0204c7cc(unsigned char* obj);
void SelectCoordsByFlag0x24_02012a84(unsigned char* obj, int* out1, int* out2);

extern unsigned char data_02114e54;

struct Obj_0205dd08 {
    char pad0[0x98];
    void* f98;
    void* f9c;
};

struct Rect_0205dd08 {
    char pad0[0xa8];
    short height;
    short x;
    short y;
    short width;
    char pad1[0x15];
    unsigned char fc5;
};

// USA: func_0205dd08
extern "C" ARM int func_0205dd08(struct Obj_0205dd08* obj) {
    struct Rect_0205dd08* e;
    int touchY, touchX;
    short top, right, bottom, tx, ty;

    if (obj->f98 == NULL) return 0;
    if (obj->f9c == NULL) return 0;
    if ((&data_02114e54)[0x55] == 0) return 0;

    e = (struct Rect_0205dd08*)FindElementForFieldB0_0205d8c4((struct Struct_0205d81c*)obj);
    if (e == NULL) return 0;
    if (IsField0x9cEqual3_0204c7cc((unsigned char*)e) == 0) return 0;
    if ((e->fc5 & 8) == 0) return 0;

    SelectCoordsByFlag0x24_02012a84(&data_02114e54, &touchY, &touchX);

    top = e->y * 8;
    bottom = top + (short)(e->height * 8);
    right = (short)(e->width * 8) + (short)(e->x * 8);
    ty = (short)touchY;
    tx = (short)touchX;

    if (right - 12 < tx && tx < right) {
        if (top < ty && ty < top + 12) return -1;
        if (bottom - 12 < ty && ty < bottom) return 1;
    }
    return 0;
}
