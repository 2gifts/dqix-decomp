#include <globaldefs.h>

// USA: func_02010810
ARM void SetField5cbcValue_02010810(char* obj, int value) {
#if defined(jpn)
    *(int*)(obj + 0x5a5c) = value;
#else
    *(int*)(obj + 0x5cbc) = value;
#endif
}
