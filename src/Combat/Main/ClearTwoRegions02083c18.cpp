#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02083c18
ARM void ClearTwoRegions02083c18(char* obj) {
#if defined(jpn)
    memset(obj + 0x854, 0, 0x24);
#else
    memset(obj + 0x8ec, 0, 0x24);
#endif
#if defined(jpn)
    memset(obj + 0x878, 0, 9);
#else
    memset(obj + 0x910, 0, 9);
#endif
}
