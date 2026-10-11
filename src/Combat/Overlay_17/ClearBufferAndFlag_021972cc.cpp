#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
static const int kBufferOffset = 0x4208;
#else
static const int kBufferOffset = 0x44b8;
#endif

// USA: func_ov017_021972cc
ARM void ClearBufferAndFlag_021972cc(char* p) {
    memset(p + kBufferOffset, 0, 8);
    *(unsigned char*)(p + kBufferOffset + 8) = 0;
}
