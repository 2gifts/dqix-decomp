#include <globaldefs.h>

extern "C" int func_02067fec(void*, int);

// USA: func_02068a5c
ARM int CheckField0x18PtrCheck02067fec_02068a5c(int a, unsigned char* obj) {
    unsigned int* p = *(unsigned int**)(obj + 0x18);
    if (p != NULL) {
        return func_02067fec(p, p[0]) == 0;
    }
    return 0;
}
