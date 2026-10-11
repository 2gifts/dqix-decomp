#include <globaldefs.h>
#if defined(jpn)
#define data_020f2b6c data_020f2cc4
#define data_020f2b71 data_020f2cc9
#endif
#include "std_library_functions.h"

extern const char data_020f2b6c[];
extern const char data_020f2b71[];

// USA: func_020e05f8
ARM int ReplaceBinExtensionWithNat020e05f8(char* dst, const char* fmt) {
    if (!dst || !fmt) return 0;
    sprintf(dst, fmt);
    char* p = strstr(dst, data_020f2b6c);
    if (p) strcpy(p, data_020f2b71);
    return 1;
}
