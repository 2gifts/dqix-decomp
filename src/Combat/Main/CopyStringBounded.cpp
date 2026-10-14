#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020464a4
ARM void CopyStringBounded_020464a4(char* src, char* dst, int size) {
    if (src == NULL || dst == NULL) return;
    strncpy(dst, src, size - 1);
    dst[size - 1] = 0;
}
