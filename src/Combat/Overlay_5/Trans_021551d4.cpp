#if defined(jpn)
#define R(j,u) (j)
#define _Z23EmptyDestructor0205cb60Pv func_0205deb8
#define _Z25ResetDisplayState02155480P11Obj02155480 func_ov006_02156b68
#define data_ov011_021889a0 data_ov011_02189700
#define data_ov013_02187dd8 data_ov013_02188cf0
#define func_ov006_02154fe4 func_ov006_02156730
#define func_ov006_021570fc func_ov006_02158704
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" unsigned int func_ov005_02155544();

// USA: func_ov005_021551d4  (semantic: Trans_021551d4)
extern "C" ARM unsigned int func_ov005_021551d4(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)func_ov005_02155544();
    r0 = r4 + 0x3000;
    r2 = *(unsigned int*)((char*)r0 + R(0xd44,0xdcc));
    r1 = 0x0;
    r2 = r2 | 0x20;
    *(unsigned int*)((char*)r0 + R(0xd44,0xdcc)) = (unsigned int)r2;
    *(unsigned char*)((char*)r0 + R(0xd21,0xda9)) = (unsigned char)r1;
    return r0;
}
