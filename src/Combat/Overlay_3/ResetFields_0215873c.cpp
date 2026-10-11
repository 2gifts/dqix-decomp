#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

// USA: func_ov003_0215873c
ARM void ResetFields_0215873c(void* obj) {
    *(int*)((char*)obj + R(0x208,0x20c)) = -1;
    *(int*)((char*)obj + R(0x328,0x32c)) = 0;
    *((unsigned char*)obj + R(0x204,0x208)) = 0;
}
