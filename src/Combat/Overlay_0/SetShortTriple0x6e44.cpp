#include <globaldefs.h>

#if defined(jpn)
enum { tripleOffset = 0x7034 };
#else
enum { tripleOffset = 0x6e44 };
#endif

// USA: func_ov000_02163440
ARM void SetShortTriple0x6e44(void* obj, unsigned short a, unsigned short b, unsigned short c) {
    *(unsigned short*)((char*)obj + tripleOffset) = a;
    *(unsigned short*)((char*)obj + tripleOffset + 2) = b;
    *(unsigned short*)((char*)obj + tripleOffset + 4) = c;
}
