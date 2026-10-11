#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_02154e58 func_ov006_021565b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" unsigned int func_ov006_02154e58(unsigned int, unsigned int);

// USA: func_ov006_02158038  (semantic: Trans_02158038)
extern "C" ARM unsigned int func_ov006_02158038(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    r1 = *(unsigned char*)((char*)r0 + 0x38f);
    cc = (int)(r1) - (int)(0x0);
    if (cc == 0) { return r0; }
    r0 = *(unsigned int*)((char*)r0 + R(8, 0x10));
    r0 = (unsigned int)func_ov006_02154e58(r0, r1);
    return r0;
}
