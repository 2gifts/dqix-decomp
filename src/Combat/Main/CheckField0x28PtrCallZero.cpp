#include <globaldefs.h>

extern "C" int func_02067f9c(void* a, int b);

// USA: func_02068ccc
ARM int CheckField0x28PtrCallZero_02068ccc(int a, unsigned char* obj) {
    int* p = *(int**)(obj + 0x28);
    if (p != NULL) {
        return func_02067f9c(p, *p) == 0;
    }
    return 0;
}
