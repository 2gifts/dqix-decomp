#include <globaldefs.h>

#if defined(jpn)
enum { kEntryHalfOffset = 0x116 };
#else
enum { kEntryHalfOffset = 0x11a };
#endif


// USA: func_ov017_021bbbec  (semantic: SetField11a_021bbbec)
extern "C" ARM void func_ov017_021bbbec(void* obj, unsigned short v) {
    *(unsigned short*)((char*)obj + kEntryHalfOffset) = v;
}
