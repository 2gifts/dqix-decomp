#include <globaldefs.h>

extern "C" void* func_0205ec34(void);

// USA: func_ov017_02198f70
ARM void SetFieldFromHelper491_02198f70(void* unused, int val) {
    unsigned char* p = (unsigned char*)func_0205ec34();
    p[0x491] = val;
}
