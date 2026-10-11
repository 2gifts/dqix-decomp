#include <globaldefs.h>

struct Elem_0205d81c {
    char pad0[0xac];
    short posX;
    short posY;
};

struct Struct_0205d81c;
extern "C" struct Elem_0205d81c* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c* s, int key);
int CheckField0x9cSetWhenField0xd4Present(unsigned char* obj);

struct ShortArrays0204c610;
void GetFourShortsAtIndex(struct ShortArrays0204c610* base, int index, short* out0, short* out1, short* out2, short* out3);

struct Obj_021703f0 {
    char pad0[1];
    signed char state;
    char pad2[4];
    signed char row;
    char pad7;
    signed char index;
    char pad9[0x3c - 0x9];
    struct Struct_0205d81c* list;
    char pad40[4];
    unsigned char* owner;
};

// JPN: func_ov003_0216fca8
// USA: func_ov003_021703f0
extern "C" ARM void func_ov003_021703f0(struct Obj_021703f0* obj, short* outX, short* outY) {
    if (obj->state == 5) {
        if (obj->owner != 0 && CheckField0x9cSetWhenField0xd4Present(obj->owner) != 0) {
#if defined(jpn)
            *outX = 0x2c;
            *outY = obj->index * 17 + 0x3a;
#else
            struct Elem_0205d81c* elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci(obj->list, 0);
            if (elem == 0) return;
            short ex = elem->posX << 3;
            short ey = elem->posY << 3;
            short x0, y0, w, h;
            GetFourShortsAtIndex((struct ShortArrays0204c610*)elem, obj->index, &x0, &y0, &w, &h);
            int x = x0;
            int y = y0;
            x = (short)(x + ex);
            y = (short)(y + ey);
            *outX = x - 0x10;
            *outY = y - 2;
#endif
        } else {
            *outX = 0;
            *outY = 0;
        }
    } else if (obj->state == 4 || obj->state == 2) {
        *outX = 4;
        *outY = obj->row * 16 + 0x2b;
    } else {
        *outX = 0;
        *outY = 0;
    }
}
