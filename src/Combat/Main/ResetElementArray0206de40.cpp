#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
extern "C" void func_0206ef94(unsigned char* arr);
#define ResetElementArray0206de40 func_0206ef94
#endif

// USA: func_0206de40
ARM void ResetElementArray0206de40(unsigned char* arr) {
    int i;
    for (i = 0; i < 5; i++) {
        unsigned char* base = arr + i * 0x1c;
        base[0] = 1;
        base[1] = 1;
        base[2] = 1;
        memset(base + 3, 0, 4);
        memset(base + 8, 0, 8);
        memset(base + 0x10, 0, 4);
        memset(base + 0x14, 0, 8);
    }
}
