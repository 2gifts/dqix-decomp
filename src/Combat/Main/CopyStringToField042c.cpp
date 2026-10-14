#include <globaldefs.h>

void CopyStringBounded_020464a4(char* src, char* dst, int size);

// USA: func_0204653c
ARM void CopyStringToField042c_0204653c(void* obj, char* src) {
#if defined(jpn)
    CopyStringBounded_020464a4(src, (char*)obj + 0x2fc, 0x40);
#else
    CopyStringBounded_020464a4(src, (char*)obj + 0x42c, 0x40);
#endif
}
