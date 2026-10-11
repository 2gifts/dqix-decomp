#include <globaldefs.h>
#include "Util/Random.h"

#if defined(jpn)
enum { kRandomOffset = 0x218 };
#else
enum { kRandomOffset = 0x29c };
#endif

// JPN: func_ov000_02162660
// USA: func_ov000_02160ef8
ARM struct Random* GetRandomFromObj02160ef8(unsigned char* obj) {
    return *(struct Random**)(obj + kRandomOffset);
}
