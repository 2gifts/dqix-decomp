#include <globaldefs.h>

// USA: func_0201079c
ARM int GetField5cb0Value(char* obj) {
#if defined(jpn)
    return *(int*)(obj + 0x5a50);
#else
    return *(int*)(obj + 0x5cb0);
#endif
}
