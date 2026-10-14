#include <globaldefs.h>

void CopyStringBounded_020464a4(char* src, char* dst, int size);

// USA: func_02046558
ARM void CopyStringToField046c_02046558(void* obj, char* src) {
    CopyStringBounded_020464a4(src, (char*)obj + 0x46c, 0x40);
}
