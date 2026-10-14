#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d2c34 {
    unsigned char v0;
    unsigned char v1;
    unsigned char v2;
};

struct LocalEvt021d2c34 {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021d2c34 sub;
    unsigned char pad2[13];
};

// USA: func_ov017_021d2c34
ARM void EnqueueEventTag36_021d2c34(unsigned char a, unsigned char b, unsigned char c) {
    LocalEvt021d2c34 buf;
    void* p = GetData02100044_0202ae24();
    Sub021d2c34* s = &buf.sub;
    buf.tag = 0x24;
    s->v0 = a;
    s->v1 = b;
    s->v2 = c;
    func_0205e330(p, &buf, 0);
}
