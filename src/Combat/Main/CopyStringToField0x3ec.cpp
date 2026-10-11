#include <globaldefs.h>

void CopyStringBounded(char* src, char* dst, int size);

#if defined(jpn)
enum { STRING_FIELD_OFFSET = 0x2bc };
#else
enum { STRING_FIELD_OFFSET = 0x3ec };
#endif

// USA: func_02046520
ARM void CopyStringToField0x3ec(char* base, char* src) {
    CopyStringBounded(src, base + STRING_FIELD_OFFSET, 0x40);
}
