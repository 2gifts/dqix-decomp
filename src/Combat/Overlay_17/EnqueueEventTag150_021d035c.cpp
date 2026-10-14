#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d035c {
    unsigned char valA;
    unsigned char valB;
    unsigned char valC;
};

struct LocalEvt021d035c {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021d035c sub;
    unsigned char pad2[13];
};

// USA: func_ov017_021d035c
ARM void EnqueueEventTag150_021d035c(unsigned char a, unsigned char b, unsigned char c) {
    LocalEvt021d035c buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0x96;
    Sub021d035c* s = &buf.sub;
    s->valA = a;
    s->valB = b;
    s->valC = c;
    func_0205e330(p, &buf, 0);
}
