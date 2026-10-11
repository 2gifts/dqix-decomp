#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02079870
ARM void ClearFourRegions02079870(char* obj) {
    memset(obj, 0, 0xc);
    memset(obj + 0xc, 0, 0xc);
    memset(obj + 0x18, 0, 0xc);
    memset(obj + 0x24, 0, 0xc);
}
