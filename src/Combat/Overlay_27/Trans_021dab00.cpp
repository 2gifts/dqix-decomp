#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" unsigned int _Z16DrainWriteBufferv();
extern "C" unsigned int _Z22DispatchEvent_021dcf44iii(unsigned int, unsigned int, unsigned int);
extern "C" unsigned int _Z25CleanInvalidateCacheRangePKvj(unsigned int, unsigned int, unsigned int);

// USA: func_ov027_021dab00  (semantic: Trans_021dab00)
extern "C" ARM unsigned int func_ov027_021dab00(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    unsigned int r6 = 0;
    r6 = r0;
    r4 = r2;
    r2 = r6 + 0x1f;
    r5 = r1;
    r0 = r4;
    r1 = r2 & ~0x1f;
    r0 = (unsigned int)_Z25CleanInvalidateCacheRangePKvj(r0, r1, r2);
    r0 = (unsigned int)_Z16DrainWriteBufferv();
    r0 = r4;
    r1 = r6;
    r2 = r5;
    r0 = (unsigned int)_Z22DispatchEvent_021dcf44iii(r0, r1, r2);
    return r0;
}
