#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d196c {
    unsigned short v0;
    unsigned short v2;
    int v4;
};

struct LocalEvt021d196c {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021d196c sub;
    unsigned char pad2[8];
};

// USA: func_ov017_021d196c
ARM void EnqueueEventTag175_021d196c(unsigned short a, unsigned short b, int c) {
    LocalEvt021d196c buf;
    void* p = GetData02100044_0202ae24();
    Sub021d196c* s = &buf.sub;
    buf.tag = 0xaf;
    s->v0 = a;
    s->v2 = b;
    s->v4 = c;
    func_0205e330(p, &buf, 0);
}
