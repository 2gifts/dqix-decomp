#include <globaldefs.h>

extern "C" int func_02067f9c(void* a, int b);

// USA: func_02068c6c
ARM int CheckField0x18PtrCallZero_02068c6c(int a, unsigned char* obj) {
    int* p = *(int**)(obj + 0x18);
    if (p != NULL) {
        return func_02067f9c(p, *p) == 0;
    }
    return 0;
}
