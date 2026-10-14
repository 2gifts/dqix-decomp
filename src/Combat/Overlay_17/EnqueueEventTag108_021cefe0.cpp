#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021cefe0 {
    unsigned short valA;
    unsigned char valB;
    unsigned char valC;
};

struct LocalEvt021cefe0 {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021cefe0 sub;
    unsigned char pad2[12];
};

// USA: func_ov017_021cefe0
ARM void EnqueueEventTag108_021cefe0(unsigned short a, unsigned char b, unsigned char c) {
    LocalEvt021cefe0 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0x6c;
    Sub021cefe0* s = &buf.sub;
    s->valA = a;
    s->valB = b;
    s->valC = c;
    func_0205e330(p, &buf, 0);
}
