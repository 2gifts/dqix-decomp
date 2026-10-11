#include <globaldefs.h>

// USA: func_02053cc4
ARM void SetFieldAt0x188(unsigned char* obj, int value) {
#if defined(jpn)
    *(int*)(obj + 0x17c) = value;
#else
    *(int*)(obj + 0x188) = value;
#endif
}
