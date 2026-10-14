#include <globaldefs.h>

extern "C" int func_02067fec(void*, int);

// USA: func_02068b1c
ARM int CheckField0PtrCheck02067fec_02068b1c(int a, unsigned char* obj) {
    unsigned int* p = *(unsigned int**)(obj + 0x0);
    if (p != NULL) {
        return func_02067fec(p, p[0]) == 0;
    }
    return 0;
}
