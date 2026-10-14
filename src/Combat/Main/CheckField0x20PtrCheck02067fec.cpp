#include <globaldefs.h>

extern "C" int func_02067fec(void*, int);

// USA: func_02068abc
ARM int CheckField0x20PtrCheck02067fec_02068abc(int a, unsigned char* obj) {
    unsigned int* p = *(unsigned int**)(obj + 0x20);
    if (p != NULL) {
        return func_02067fec(p, p[0]) == 0;
    }
    return 0;
}
