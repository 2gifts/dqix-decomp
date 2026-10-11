#include <globaldefs.h>

#if defined(jpn)
#define func_ov006_02154fe4 func_ov006_02156730
#endif

extern "C" void func_ov023_021dfad8(char* obj);
struct Cont0207fd88;
void CallFunc0204b088OverList0x2c(Cont0207fd88* obj);

struct Flags27f {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
};

// USA: func_ov006_02154fe4
extern "C" ARM void func_ov006_02154fe4(void* obj) {
    char* o = (char*)obj;
    if (!*(unsigned char*)(o + 0xadc)) return;
    if (*(unsigned char*)(o + 0x1000 + 0x2bd)) {
        volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
        unsigned int f = (*reg & 0x1f00) >> 8;
        *reg = (*reg & ~0x1f00) | ((f | 1) << 8);
        *(unsigned char*)(o + 0x1000 + 0x2bd) = 0;
    }
    func_ov023_021dfad8(o + 0x2e4 + 0x800);
    if (((Flags27f*)(o + 0x1000 + 0x27f))->bit1) return;
    Cont0207fd88* p = *(Cont0207fd88**)(o + 0x1d4);
    if (p == 0) return;
    CallFunc0204b088OverList0x2c(p);
}
