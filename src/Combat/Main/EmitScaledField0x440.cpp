#include <globaldefs.h>

extern "C" void func_0202f45c(void*, int, int, int, int, int, int);

struct RectSub0202f404 {
    short field0;
    short field2;
    short field4;
    short field6;
    int   field8;
    int   fieldc;
    int   field10;
    int   field14;
};

// USA: func_0202f404
ARM void EmitScaledField0x440_0202f404(void* obj, int a, int b) {
    struct RectSub0202f404* s = *(struct RectSub0202f404**)((char*)obj + 0x440);
    if (s != NULL && s->field8 != 0) {
        func_0202f45c(obj, s->field0 << 12, s->field2 << 12,
                      s->field4 * s->field10, s->field6 * s->field14, a, b);
    }
}
