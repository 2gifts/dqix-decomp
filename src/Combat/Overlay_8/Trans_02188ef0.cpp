#include <globaldefs.h>

extern "C" unsigned int _Z18InitFlags_021eb414Pc(unsigned int, unsigned int);

// USA: func_ov008_02188ef0  (semantic: Trans_02188ef0)
extern "C" ARM unsigned int func_ov008_02188ef0(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    r4 = r0;
    r0 = *(unsigned int*)((char*)r4 + 0xb18);
    cc = (int)(r0 & 0x100000);
    if (cc == 0) { return r0; }
    cc = (int)(r0 & 0x200000);
    if (cc != 0) { return r0; }
    r0 = *(unsigned char*)((char*)r4 + 0xb2a);
    if (r0 != 0) { return r0; }
    r0 = *(unsigned int*)((char*)r4 + 0xb08);
    if (r0 == 0) { goto L48; }
    r1 = r0 + 0x400;
    r1 = *(unsigned short*)((char*)r1 + 0x38);
    cc = (int)(r1 & 0x4);
    if (cc != 0) { goto L48; }
    r0 = (unsigned int)_Z18InitFlags_021eb414Pc(r0, r1);
L48:;
    r1 = 0x0;
    *(unsigned char*)((char*)r4 + 0xb13) = (unsigned char)r1;
    r0 = 0xd;
    *(unsigned char*)((char*)r4 + 0xb10) = (unsigned char)r0;
    *(unsigned char*)((char*)r4 + 0xb11) = (unsigned char)r1;
    r0 = *(unsigned char*)((char*)r4 + 0xb2a);
    r0 = r0 + 0x1;
    *(unsigned char*)((char*)r4 + 0xb2a) = (unsigned char)r0;
    return r0;
}
