#include <globaldefs.h>

#if defined(jpn)
enum { POINTER_FIELD_OFFSET = 0x144 };
#else
enum { POINTER_FIELD_OFFSET = 0x150 };
#endif

// USA: func_02053c4c
ARM void SetPointerFields02053c4c(char* obj, char* p) {
    *(char**)(obj + POINTER_FIELD_OFFSET) = p;
    *(char**)(obj + 0x134) = p + 0x3c;
    *(char**)(obj + 0x130) = p + 0x18;
    *(char**)(obj + 0x138) = p + 0x94;
}
