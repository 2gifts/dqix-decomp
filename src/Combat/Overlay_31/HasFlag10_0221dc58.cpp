#include <globaldefs.h>

// USA: func_ov031_0221dc58  (semantic: HasFlag10_0221dc58)
// JPN: func_ov031_0221e438
extern "C" THUMB bool func_ov031_0221dc58(int flags) {
    bool result = false;
    if (flags & 0x10) result = true;
    return result;
}
