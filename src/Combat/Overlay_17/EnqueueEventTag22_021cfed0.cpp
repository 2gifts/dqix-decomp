#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021cfed0 {
    unsigned char valA;
    unsigned char valB;
};

struct LocalEvt021cfed0 {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021cfed0 sub;
    unsigned char pad2[14];
};

// USA: func_ov017_021cfed0
ARM void EnqueueEventTag22_021cfed0(unsigned char a, unsigned char b) {
    LocalEvt021cfed0 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0x16;
    Sub021cfed0* s = &buf.sub;
    s->valA = a;
    s->valB = b;
    func_0205e330(p, &buf, 0);
}
