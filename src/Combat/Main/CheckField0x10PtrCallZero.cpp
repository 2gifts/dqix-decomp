#include <globaldefs.h>

extern "C" int func_02067fec(void* a, int b);

// USA: func_02068b4c
ARM int CheckField0x10PtrCallZero_02068b4c(int a, unsigned char* obj) {
    int* p = *(int**)(obj + 0x10);
    if (p != NULL) {
        return func_02067fec(p, *p) == 0;
    }
    return 0;
}
