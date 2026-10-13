#include <globaldefs.h>

struct Obj021f9d14 {
    char pad[0x20];
    unsigned short* table;
    unsigned short count;
    unsigned short width;
    unsigned short x;
    unsigned short y;
};

struct Obj021f9bdc;
void DivModField26_021f9bdc(struct Obj021f9bdc* o, int divisor);
extern "C" int func_ov023_021f98e0(void* node, void* obj);

// USA: func_ov023_021f9d14  (semantic: FindSlotAndDispatch_021f9d14)
extern "C" ARM int func_ov023_021f9d14(struct Obj021f9d14* obj, void* param2) {
    int y = obj->y;
    int x = obj->x;
    int width = obj->width;
    int idx = x * width + y;
    while (obj->table[idx] == 0) {
        if (y == 0) {
            if (x == 0) break;
            y = width - 1;
            x--;
        } else if (y > 0) {
            y--;
        }
        idx = x * width + y;
    }
    idx = x * width + y;
    if (obj->table[idx] == 0) idx = 0;
    DivModField26_021f9bdc((struct Obj021f9bdc*)obj, (unsigned short)idx);
    return func_ov023_021f98e0(obj, param2);
}
