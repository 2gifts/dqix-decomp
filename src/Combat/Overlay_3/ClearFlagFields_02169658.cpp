#include <globaldefs.h>

// USA: func_ov003_02169658
ARM void ClearFlagFields_02169658(void* obj) {
    unsigned char* p = (unsigned char*)obj;
#if defined(jpn)
    enum { fieldBase = 0x598 };
#else
    enum { fieldBase = 0x59c };
#endif
    p[fieldBase] = 0;
    p[fieldBase + 1] = 0;
    p[fieldBase + 2] = 0;
    p[fieldBase + 10] = 0;
    p[fieldBase + 11] = 0;
}
