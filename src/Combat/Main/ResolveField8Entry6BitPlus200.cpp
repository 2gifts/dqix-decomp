#include <globaldefs.h>

extern int CallFunc020e0434With021536ac_020e51e4(int value);
extern "C" void* func_020e462c(void* a, int b, int c, void* d);

struct Node020e4810 {
    int field0;
    int field4;
    unsigned int f8_lo : 18;
    unsigned int f8_hi : 6;
};

// USA: func_020e4810
ARM void* ResolveField8Entry6BitPlus200(void* arg0, struct Node020e4810* p) {
    void* result = arg0;
    if (p->field4 != 0) {
        int entry = CallFunc020e0434With021536ac_020e51e4((short)(p->f8_hi + 0xc8));
        result = func_020e462c(arg0, entry, p->field4, p);
    }
    return result;
}
