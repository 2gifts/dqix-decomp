#include <globaldefs.h>

extern char data_021015a0;
void SetField0x48UnlessState9Or10_0202c848(int);
extern "C" int func_0202d788(unsigned short);

struct S0202d840 {
    unsigned short pad0;
    unsigned short f2;
    unsigned short pad1[2];
    unsigned short f8;
    unsigned short fa;
};

// USA: func_0202d840  (semantic: UpdateSlotBitmaskAndDispatchNext_0202d840)
extern "C" ARM void func_0202d840(struct S0202d840* obj) {
    if (obj->f2 != 0) {
        SetField0x48UnlessState9Or10_0202c848(obj->f2);
        *(int*)(&data_021015a0 + 0x10) = 9;
        return;
    }
    unsigned short hi = *(unsigned short*)(&data_021015a0 + 0x6);
    unsigned short lo = obj->fa;
    unsigned short idx = obj->f8;
    if (hi > lo) {
        *(unsigned short*)(&data_021015a0 + 0x6) = lo;
        *(unsigned short*)(&data_021015a0 + 0xc) = 1 << (idx - 1);
    } else if (hi == lo) {
        unsigned short bits = *(unsigned short*)(&data_021015a0 + 0xc);
        *(unsigned short*)(&data_021015a0 + 0xc) = bits | (1 << (idx - 1));
    }
    unsigned short next = (unsigned short)(idx + 1);
    int r = func_0202d788(next);
    if (r == 0x18) {
        *(int*)(&data_021015a0 + 0x10) = 7;
        return;
    }
    if (r != 2) {
        *(int*)(&data_021015a0 + 0x10) = 9;
    }
}
