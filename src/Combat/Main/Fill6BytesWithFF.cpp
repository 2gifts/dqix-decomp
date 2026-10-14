#include <globaldefs.h>

// USA: func_020a18d4
ARM void Fill6BytesWithFF_020a18d4(char* p) {
    unsigned int i;
    for (i = 0; i < 6; i++) {
        p[i] = -1;
    }
}
