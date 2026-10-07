#include <globaldefs.h>

struct Variant02030b0c { int tag; union { int i; float f; } u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

extern int data_020f0d2c;
extern short* data_02108dd8;

// USA: func_02074060
extern "C" ARM int func_02074060(struct Variant02030b0c* p) {
    int i;
    int slot = _ZNK6Script9Parameter5ToIntEv(p++);
    if (slot != data_020f0d2c) {
        return 1;
    }
    data_02108dd8[0] = (short)slot;
    for (i = 0; i < 3; i++) {
        *((short*)((char*)data_02108dd8 + 2 * i + 2)) = (short)_ZNK6Script9Parameter5ToIntEv(p);
        struct Variant02030b0c* q = p + 1;
        p += 2;
        *((short*)((char*)data_02108dd8 + 2 * i + 8)) = (short)_ZNK6Script9Parameter5ToIntEv(q);
    }
    data_02108dd8[7] = (short)_ZNK6Script9Parameter5ToIntEv(p);
    data_02108dd8[8] = (short)_ZNK6Script9Parameter5ToIntEv(p + 1);
    data_02108dd8[9] = 0;
    return 1;
}
