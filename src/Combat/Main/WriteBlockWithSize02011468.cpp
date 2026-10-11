#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02011468
// Copies 'size' bytes from 'src' into the buffer at +0x5718 and stores the size byte at +0x571c.
ARM void WriteBlockWithSize02011468(void* obj, int size, void* src) {
#if defined(jpn)
    memcpy((char*)obj + 0x54b8, src, size);
#else
    memcpy((char*)obj + 0x5718, src, size);
#endif
#if defined(jpn)
    *((char*)obj + 0x54bc) = (char)size;
#else
    *((char*)obj + 0x571c) = (char)size;
#endif
}
