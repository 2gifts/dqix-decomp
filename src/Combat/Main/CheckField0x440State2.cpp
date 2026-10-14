#include <globaldefs.h>

// USA: func_0205cd6c
ARM int CheckField0x440State2_0205cd6c(unsigned char* obj) {
    int* p = *(int**)(obj + 0x440);
    if (p != NULL) {
        return p[2] == 2;
    }
    return 0;
}
