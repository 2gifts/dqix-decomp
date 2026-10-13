#include <globaldefs.h>
#include "std_library_functions.h"

// KEEP-NAME
// USA: func_02011a74
// JPN: func_020117e4
ARM void CopyStringToField0x649e(char* obj, unsigned int index, const char* source) {
    if (source == NULL) return;
#if defined(jpn)
    char* destination = obj + 0x621e;
#else
    char* destination = obj + 0x649e;
#endif
    if (destination == NULL) return;
    if (index > 3) return;
#if defined(jpn)
    destination += index * 32;
#endif
    strcpy(destination, source);
}
