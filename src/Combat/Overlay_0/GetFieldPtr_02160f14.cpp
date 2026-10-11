#include <globaldefs.h>

#if defined(jpn)
enum { kFieldLowOffset = 0x394, kFieldHighOffset = 0x800 };
#else
enum { kFieldLowOffset = 0x18, kFieldHighOffset = 0xc00 };
#endif

// JPN: func_ov000_02162680
// USA: func_ov000_02160f14  (semantic: GetFieldPtr_02160f14)
extern "C" ARM void* func_ov000_02160f14(void* obj) {
    char* p = (char*)obj + kFieldLowOffset;
    return p + kFieldHighOffset;
}
