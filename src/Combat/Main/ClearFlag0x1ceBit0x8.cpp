#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x1c2 };
#else
enum { FIELD_OFFSET = 0x1ce };
#endif

#if defined(jpn)
#define ClearFlag0x1ceBit0x8 func_02039814
extern "C" ARM void func_02039814(unsigned char* obj);
#endif

// USA: func_02039dbc
ARM void ClearFlag0x1ceBit0x8(unsigned char* obj) {
    obj[FIELD_OFFSET] &= ~8;
}
