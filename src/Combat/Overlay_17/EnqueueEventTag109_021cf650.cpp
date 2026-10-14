#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021cf650 {
    int valB;
    int valC;
    unsigned short valA;
};

struct LocalEvt021cf650 {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021cf650 sub;
    unsigned char pad2[2];
};

// USA: func_ov017_021cf650
ARM void EnqueueEventTag109_021cf650(unsigned short a, int b, int c) {
    LocalEvt021cf650 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0x6d;
    Sub021cf650* s = &buf.sub;
    s->valB = b;
    s->valC = c;
    s->valA = a;
    func_0205e330(p, &buf, 0);
}
