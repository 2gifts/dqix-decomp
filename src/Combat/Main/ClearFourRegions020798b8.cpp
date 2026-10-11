#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020798b8
ARM void ClearFourRegions020798b8(char* obj) {
    memset(obj, 0, 0xc);
    memset(obj + 0xc, 0, 0xc);
    memset(obj + 0x18, 0, 0xc);
    memset(obj + 0x24, 0, 0xc);
}
