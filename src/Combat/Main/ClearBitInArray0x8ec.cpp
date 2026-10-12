#include <globaldefs.h>

#if defined(jpn)
enum { BIT_ARRAY_OFFSET = 0x854 };
#else
enum { BIT_ARRAY_OFFSET = 0x8ec };
#endif

#if defined(jpn)
#define ClearBitInArray0x8ec func_02084434
extern "C" ARM void func_02084434(unsigned char* obj, int index);
#endif

// USA: func_02083b28
ARM void ClearBitInArray0x8ec(unsigned char* obj, int index) {
    unsigned char* p = obj + BIT_ARRAY_OFFSET;
    p[index / 8] &= ~(1 << (index % 8));
}
