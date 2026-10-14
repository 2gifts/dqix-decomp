#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021cbeb0 {
    unsigned char valA;
    unsigned char pad;
    unsigned short valB;
};

struct LocalEvt021cbeb0 {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021cbeb0 sub;
    unsigned char pad2[12];
};

// USA: func_ov017_021cbeb0
ARM void EnqueueEventTag127_021cbeb0(unsigned char a, unsigned short b) {
    LocalEvt021cbeb0 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0x7f;
    Sub021cbeb0* s = &buf.sub;
    s->valA = a;
    s->valB = b;
    func_0205e330(p, &buf, 0);
}
