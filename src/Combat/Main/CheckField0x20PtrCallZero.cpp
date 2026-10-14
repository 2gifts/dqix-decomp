#include <globaldefs.h>

extern "C" int func_02067f9c(void* a, int b);

// USA: func_02068c9c
ARM int CheckField0x20PtrCallZero_02068c9c(int a, unsigned char* obj) {
    int* p = *(int**)(obj + 0x20);
    if (p != NULL) {
        return func_02067f9c(p, *p) == 0;
    }
    return 0;
}
