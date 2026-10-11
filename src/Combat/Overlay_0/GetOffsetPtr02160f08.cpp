#include <globaldefs.h>

#if defined(jpn)
enum { kFieldLowOffset = 0x31c, kFieldHighOffset = 0x3400 };
#else
enum { kFieldLowOffset = 0x760, kFieldHighOffset = 0x3000 };
#endif

// USA: func_ov000_02160f08
ARM void* GetOffsetPtr02160f08(void* obj) {
    return (char*)obj + kFieldLowOffset + kFieldHighOffset;
}
