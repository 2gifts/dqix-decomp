#include <globaldefs.h>

// USA: func_02010804
ARM int GetField5cb8Value_02010804(char* obj) {
#if defined(jpn)
    return *(int*)(obj + 0x5a58);
#else
    return *(int*)(obj + 0x5cb8);
#endif
}
