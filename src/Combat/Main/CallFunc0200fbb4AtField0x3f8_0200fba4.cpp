#include <globaldefs.h>
#include "Combat/Main/CopyRecord0200fbb4.h"

// Pass the source through unchanged; only the destination gains the field offset.
// USA: func_0200fba4
extern "C" ARM void* _Z37CallFunc0200fbb4AtField0x3f8_0200fba4Pv(void* obj, const void* src) {
    return func_0200fbb4(
        (CopyRecord0200fbb4*)((char*)obj + 0x3f8),
        (const CopyRecord0200fbb4*)src);
}
