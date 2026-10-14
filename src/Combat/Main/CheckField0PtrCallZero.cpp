#include <globaldefs.h>

extern "C" int func_02067f9c(void* a, int b);

// USA: func_02068cfc
ARM int CheckField0PtrCallZero_02068cfc(int a, unsigned char* obj) {
    int* p = *(int**)(obj + 0x0);
    if (p != NULL) {
        return func_02067f9c(p, *p) == 0;
    }
    return 0;
}
