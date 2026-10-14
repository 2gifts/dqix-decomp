#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021ce614 {
    unsigned char valA;
    unsigned char valB;
    unsigned char valC;
};

struct LocalEvt021ce614 {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021ce614 sub;
    unsigned char pad2[13];
};

// USA: func_ov017_021ce614
ARM void EnqueueEventTag176_021ce614(unsigned char a, unsigned char b, unsigned char c) {
    LocalEvt021ce614 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0xb0;
    Sub021ce614* s = &buf.sub;
    s->valA = a;
    s->valB = b;
    s->valC = c;
    func_0205e330(p, &buf, 0);
}
