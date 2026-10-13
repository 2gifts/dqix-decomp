#include <globaldefs.h>

#if defined(jpn)
enum { kEntryHalfOffset = 0x118 };
#else
enum { kEntryHalfOffset = 0x11c };
#endif

// USA: func_ov017_021bbc04  (semantic: GetHalfwordAtField284_021bbc04)
extern "C" ARM unsigned short func_ov017_021bbc04(void* obj) {
    return *(unsigned short*)((char*)obj + kEntryHalfOffset);
}
