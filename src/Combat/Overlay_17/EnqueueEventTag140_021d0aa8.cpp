#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d0aa8 {
    unsigned short valA;
    unsigned char valB;
};

struct LocalEvt021d0aa8 {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021d0aa8 sub;
    unsigned char pad2[12];
};

// USA: func_ov017_021d0aa8
ARM void EnqueueEventTag140_021d0aa8(unsigned short a, unsigned char b) {
    LocalEvt021d0aa8 buf;
    void* p = GetData02100044_0202ae24();
    Sub021d0aa8* s = &buf.sub;
    buf.tag = 0x8c;
    s->valA = a;
    s->valB = b;
    func_0205e330(p, &buf, 0);
}
