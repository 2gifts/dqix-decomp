#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021ced48  (semantic: EnqueueEventTag53_021ced48)
extern "C" ARM void func_ov017_021ced48(unsigned char a0, unsigned char a1) {
    void* p = GetData02100044_0202ae24();
    unsigned char buf[0x14];
    unsigned char* b = buf + 4;
    buf[0] = 0x35;
    b[0] = a0;
    b[1] = a1;
    func_0205e330(p, buf, 0);
}
