#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d1810 {
    unsigned short v0;
    unsigned short v2;
    unsigned char v4;
};

struct LocalEvt021d1810 {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021d1810 sub;
    unsigned char pad2[10];
};

// USA: func_ov017_021d1810
ARM void EnqueueEventTag173_021d1810(int a, int b, signed char c) {
    LocalEvt021d1810 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0xad;
    Sub021d1810* s = &buf.sub;
    s->v0 = a;
    s->v2 = b;
    s->v4 = c;
    func_0205e330(p, &buf, 0);
}
