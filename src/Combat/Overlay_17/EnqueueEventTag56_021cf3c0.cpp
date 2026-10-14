#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Vec3_021cf3c0 {
    int a1;
    int a2;
    int a3;
};

struct LocalEvt021cf3c0 {
    unsigned char tag;
    unsigned char pad0[3];
    int a1;
    int a2;
    int a3;
    short a4;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char rest : 6;
    signed char a7;
};

// USA: func_ov017_021cf3c0  (semantic: EnqueueEventTag56_021cf3c0)
extern "C" ARM void func_ov017_021cf3c0(struct Vec3_021cf3c0 v, short a4, unsigned char e5, unsigned char e6, signed char e7) {
    void* p = GetData02100044_0202ae24();
    struct LocalEvt021cf3c0 buf;
    buf.tag = 0x38;
    buf.a1 = v.a1;
    buf.a2 = v.a2;
    buf.a3 = v.a3;
    buf.a4 = a4;
    buf.bit0 = e5;
    buf.bit1 = e6;
    buf.a7 = e7;
    func_0205e330(p, &buf, 0);
}
