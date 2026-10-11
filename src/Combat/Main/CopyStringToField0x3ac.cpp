#include <globaldefs.h>

void CopyStringBounded(char* src, char* dst, int size);

#if defined(jpn)
enum { STRING_FIELD_OFFSET = 0x27c };
#else
enum { STRING_FIELD_OFFSET = 0x3ac };
#endif

// USA: func_02046504
ARM void CopyStringToField0x3ac(char* base, char* src) {
    CopyStringBounded(src, base + STRING_FIELD_OFFSET, 0x40);
}
