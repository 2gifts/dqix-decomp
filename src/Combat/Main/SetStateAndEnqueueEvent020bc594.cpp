#include <globaldefs.h>

void EnqueueEvent0x4_020d1e50(int, int);

struct S020bc594 {
    unsigned char pad[0x2e];
    unsigned char state;
    unsigned char pad2[0x3c - 0x2e - 1];
    unsigned char kind;
};

// USA: func_020bc594  (semantic: SetStateAndEnqueueEvent020bc594)
extern "C" ARM void func_020bc594(S020bc594* obj, int val) {
    if (obj != 0 && val != obj->state) {
        EnqueueEvent0x4_020d1e50(obj->kind, val);
        obj->state = (unsigned char)val;
    }
}
