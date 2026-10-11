#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_02011ab8
ARM void ClearRegion0x649e(char* obj) {
#if defined(jpn)
    VectorizedMemset(obj + 0x621e, 0, 0x80);
#else
    VectorizedMemset(obj + 0x649e, 0, 0x40);
#endif
}
