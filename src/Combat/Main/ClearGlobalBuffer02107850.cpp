#include <globaldefs.h>
#include "std_library_functions.h"

extern int data_02107850;

// USA: func_02048994
ARM void ClearGlobalBuffer02107850_02048994(void) {
    memset(&data_02107850, 0, 0x20);
}
