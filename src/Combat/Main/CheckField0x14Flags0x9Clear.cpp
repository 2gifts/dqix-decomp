#include <globaldefs.h>

// USA: func_0208830c
ARM int CheckField0x14Flags0x9Clear_0208830c(unsigned char* obj) {
    int x = *(int*)(obj + 0x14);
    if (x & 1) {
        return 0;
    }
    if (x & 8) {
        return 0;
    }
    return (x & 0x1000000) == 0;
}
