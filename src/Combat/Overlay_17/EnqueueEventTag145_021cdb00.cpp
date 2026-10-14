#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021cdb00  (semantic: EnqueueEventTag145_021cdb00)
extern "C" ARM void func_ov017_021cdb00(unsigned char a0, unsigned short a1, int a2, unsigned char a3) {
    void* p = GetData02100044_0202ae24();
    unsigned char buf[0x14];
    buf[0] = 0x91;
    unsigned char* q = buf + 4;
    q[0] = a3;
    q[1] = a0;
    *(unsigned short*)(q + 2) = a1;
    *(int*)(q + 4) = a2;
    func_0205e330(p, buf, 0);
}
