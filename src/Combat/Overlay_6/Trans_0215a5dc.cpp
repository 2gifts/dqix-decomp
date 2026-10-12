#include <globaldefs.h>

#if defined(jpn)
#define func_ov006_0215a5dc func_ov006_0215bbd4
enum { kChildPointer = 8 };
#define _Z25SetByte_021571b8_021571b8Pvh func_ov006_021587c0
#define _Z28CallIfFlag_021571cc_021571ccP30CallIfFlag0x800_021571ccStruct func_ov006_021587d4
#else
enum { kChildPointer = 0x10 };
#endif



extern "C" unsigned int _Z25SetByte_021571b8_021571b8Pvh(unsigned int, unsigned int);
extern "C" unsigned int _Z28CallIfFlag_021571cc_021571ccP30CallIfFlag0x800_021571ccStruct(unsigned int);

// USA: func_ov006_0215a5dc  (semantic: Trans_0215a5dc)
extern "C" ARM unsigned int func_ov006_0215a5dc(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r1 = *(unsigned char*)((char*)r4 + 0x38b);
    r0 = *(unsigned int*)((char*)r4 + kChildPointer);
    r0 = (unsigned int)_Z25SetByte_021571b8_021571b8Pvh(r0, r1);
    r0 = *(unsigned int*)((char*)r4 + kChildPointer);
    r0 = (unsigned int)_Z28CallIfFlag_021571cc_021571ccP30CallIfFlag0x800_021571ccStruct(r0);
    return r0;
}
