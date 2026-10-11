#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020d3c08
ARM void ResetStruct020d3c08(char* obj) {
#if defined(jpn)
    memset(obj, 0, 0xa0);
#else
    memset(obj, 0, 0xb4);
#endif
#if defined(jpn)
    *(int*)(obj + 0xa0) = 0;
#else
    *(int*)(obj + 0xb4) = 0;
#endif
}
