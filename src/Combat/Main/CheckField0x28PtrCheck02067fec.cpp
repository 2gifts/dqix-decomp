#include <globaldefs.h>

extern "C" int func_02067fec(void*, int);

// USA: func_02068aec
ARM int CheckField0x28PtrCheck02067fec_02068aec(int a, unsigned char* obj) {
    unsigned int* p = *(unsigned int**)(obj + 0x28);
    if (p != NULL) {
        return func_02067fec(p, p[0]) == 0;
    }
    return 0;
}
