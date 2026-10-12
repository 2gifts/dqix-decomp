#include <globaldefs.h>

#if defined(jpn)
#define func_ov006_0215f9e8 func_ov006_02160d5c
enum { kMenuPointer = 0xc };
#else
enum { kMenuPointer = 0x14 };
#endif



extern "C" unsigned int _Z26SetEntryFirstField02080fa8P17Container02080fa8ii(unsigned int, unsigned int, unsigned int);
extern "C" unsigned int func_020813ec(unsigned int, unsigned int);

// USA: func_ov006_0215f9e8  (semantic: Trans_0215f9e8)
extern "C" ARM unsigned int func_ov006_0215f9e8(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r2 = *(unsigned char*)((char*)r4 + 0x38b);
    r0 = *(unsigned int*)((char*)r4 + kMenuPointer);
    r1 = 0x3d;
    r0 = (unsigned int)_Z26SetEntryFirstField02080fa8P17Container02080fa8ii(r0, r1, r2);
    r0 = *(unsigned int*)((char*)r4 + kMenuPointer);
    r1 = 0xa;
    r0 = (unsigned int)func_020813ec(r0, r1);
    r0 = r4 + 0x300;
    r1 = 0xa;
    *(unsigned short*)((char*)r0 + 0x6e) = (unsigned short)r1;
    return r0;
}
