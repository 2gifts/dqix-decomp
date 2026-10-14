#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021cfd5c {
    unsigned short valB;
    unsigned short valC;
    unsigned char valA;
};

struct LocalEvt021cfd5c {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021cfd5c sub;
    unsigned char pad2[7];
};

// USA: func_ov017_021cfd5c
ARM void EnqueueEventTag164_021cfd5c(unsigned char a, unsigned short b, unsigned short c) {
    LocalEvt021cfd5c buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0xa4;
    Sub021cfd5c* s = &buf.sub;
    s->valA = a;
    s->valB = b;
    s->valC = c;
    func_0205e330(p, &buf, 0);
}
