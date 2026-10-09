#include <globaldefs.h>

struct Struct_0205d81c;

struct Elem_0205d81c {
    char pad0[0xa8];
    short width;
    short height;
    short x;
    short y;
};

extern "C" struct Elem_0205d81c* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c* s, int key);
extern "C" void _Z23ApplyElemFields0205d904Ph(unsigned char* obj);

// USA: func_ov000_02176210
extern "C" ARM void func_ov000_02176210(struct Struct_0205d81c* s, int key1, int key2) {
    struct Elem_0205d81c* first = _Z23FindElementByC40205d81cP15Struct_0205d81ci(s, key1);
    struct Elem_0205d81c* second = _Z23FindElementByC40205d81cP15Struct_0205d81ci(s, key2);
    if (first == NULL || second == NULL) return;

    short firstY = first->y;
    short firstHeight = first->height;
    short secondWidth = second->width;
    short firstWidth = first->width;
    short secondHeight = second->height;
    first->x = 0x20 - firstWidth;
    first->y = firstY;
    short secondX = 0x20 - secondWidth;
    short secondY = firstY + firstHeight;
    if (secondY + secondHeight > 0x18) secondY = firstY - secondHeight;
    second->x = secondX;
    second->y = secondY;
    _Z23ApplyElemFields0205d904Ph((unsigned char*)s);
}
