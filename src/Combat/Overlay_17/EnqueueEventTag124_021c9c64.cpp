#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void func_ov017_021c9954(int a, int b, int c, void* d);

// USA: func_ov017_021c9c64  (semantic: EnqueueEventTag124_021c9c64)
extern "C" ARM void func_ov017_021c9c64(unsigned short a0, unsigned char a1) {
    void* p = GetData02100044_0202ae24();
    unsigned char buf[0x14];
    buf[0] = 0x7c;
    *(unsigned short*)(buf + 4) = a0;
    buf[6] = a1;
    func_0205e330(p, buf, 0);
    func_ov017_021c9954(a0, 1, a1, (void*)-1);
}
