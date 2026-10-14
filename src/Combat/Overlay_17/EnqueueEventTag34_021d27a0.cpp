#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d27a0 {
    unsigned char v0;
    unsigned char v1;
    unsigned char v2;
};

struct LocalEvt021d27a0 {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021d27a0 sub;
    unsigned char pad2[13];
};

// USA: func_ov017_021d27a0
ARM void EnqueueEventTag34_021d27a0(int a, int b, int c) {
    LocalEvt021d27a0 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0x22;
    Sub021d27a0* s = &buf.sub;
    s->v0 = a;
    s->v1 = b;
    s->v2 = c;
    func_0205e330(p, &buf, 0);
}
