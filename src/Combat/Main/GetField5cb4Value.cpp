#include <globaldefs.h>

// USA: func_020107d0
ARM int GetField5cb4Value_020107d0(char* obj) {
#if defined(jpn)
    return *(int*)(obj + 0x5a54);
#else
    return *(int*)(obj + 0x5cb4);
#endif
}
