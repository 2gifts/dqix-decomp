#include <globaldefs.h>

// USA: func_ov000_02165480
ARM void SetPtrFieldIfNonNull0x13c_ov000_02165480(void* obj, int val) {
    int* p = *(int**)((char*)obj + 0x13c);
    if (p != NULL) {
        *p = val;
    }
}
