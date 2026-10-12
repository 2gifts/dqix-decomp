#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x1c2 };
#else
enum { FIELD_OFFSET = 0x1ce };
#endif

#if defined(jpn)
#define ClearFlag0x1ceBit0x1 func_020392fc
extern "C" ARM void func_020392fc(unsigned char* obj);
#endif

// USA: func_020398a4
ARM void ClearFlag0x1ceBit0x1(unsigned char* obj) {
    obj[FIELD_OFFSET] &= ~1;
}
