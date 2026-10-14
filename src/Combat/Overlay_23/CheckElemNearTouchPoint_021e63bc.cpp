#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c* s, int key);

extern unsigned char data_02114e54;

// USA: func_ov023_021e63bc  (semantic: CheckElemNearTouchPoint_021e63bc)
extern "C" ARM int func_ov023_021e63bc(unsigned char* obj) {
    int key = obj[0x1371];
    Elem_0205d81c* elem = FindElementByC40205d81c((Struct_0205d81c*)(obj + 0xac), key);
    short* pos = (short*)((char*)elem + 0xac);
    unsigned char* d = &data_02114e54;
    int boundA = *(int*)(d + 0x38);
    int x = pos[0];
    int ytop = pos[1];
    x = (short)(x << 3) + 0xa;
    ytop = (short)(ytop << 3) + 0x10;
    int boundB = *(int*)(d + 0x3c);
    if (x <= boundA && boundA <= x + 0x10 && ytop <= boundB && boundB <= ytop + 8)
        return 1;
    if (x <= boundA && boundA <= x + 0x10 && ytop + 0xc <= boundB && boundB <= ytop + 0x14)
        return -1;
    return 0;
}
