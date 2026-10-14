#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021cbfb8 {
    unsigned short valA;
    unsigned char valB;
};

struct LocalEvt021cbfb8 {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021cbfb8 sub;
    unsigned char pad2[9];
};

// USA: func_ov017_021cbfb8
ARM void EnqueueEventTag129_021cbfb8(unsigned short a, unsigned char b) {
    LocalEvt021cbfb8 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0x81;
    Sub021cbfb8* s = &buf.sub;
    s->valA = a;
    s->valB = b;
    func_0205e330(p, &buf, 0);
}
