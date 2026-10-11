#include <globaldefs.h>

// USA: func_0201081c
ARM int GetField5cbcValue(char* obj) {
#if defined(jpn)
    return *(int*)(obj + 0x5a5c);
#else
    return *(int*)(obj + 0x5cbc);
#endif
}
