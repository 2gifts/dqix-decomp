#include <globaldefs.h>

extern "C" void func_0204b04c(void* p, int flag);

struct Elem0205d274 { char b[0x20]; };

struct Cont0205d274 {
    char pad0[0x98];
    Elem0205d274* list98;
    char pad9c[0x16];
    unsigned char countB2;
};

// USA: func_0205d274
ARM void CallFunc0204b04cOverList0x98(Cont0205d274* obj) {
    unsigned char i;
    if (obj->list98 == NULL) return;
    for (i = 0; i < obj->countB2; i++) {
        func_0204b04c(&obj->list98[i], 0);
    }
}
