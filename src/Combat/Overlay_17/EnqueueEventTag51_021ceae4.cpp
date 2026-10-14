#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021ceae4 {
    unsigned char valA;
    unsigned char valB;
    unsigned char pad;
    unsigned char valC;
};

struct LocalEvt021ceae4 {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021ceae4 sub;
    unsigned char pad2[12];
};

// USA: func_ov017_021ceae4
ARM void EnqueueEventTag51_021ceae4(unsigned char a, unsigned char b, unsigned char c) {
    LocalEvt021ceae4 buf;
    void* p = GetData02100044_0202ae24();
    Sub021ceae4* s = &buf.sub;
    buf.tag = 0x33;
    s->valA = a;
    s->valB = b;
    s->valC = c;
    func_0205e330(p, &buf, 0);
}
