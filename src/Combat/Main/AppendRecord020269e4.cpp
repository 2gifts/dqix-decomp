#if defined(jpn)
#define RECORD_ARRAY_OFFSET 0x6d8
#else
#define RECORD_ARRAY_OFFSET 0x784
#endif
#if defined(jpn)
#define RECORD_COUNT_OFFSET 0x6d4
#else
#define RECORD_COUNT_OFFSET 0x780
#endif
#include <globaldefs.h>
#include "System/Memory.h"

// JPN: func_02026348
// USA: func_020269e4
ARM void AppendRecord020269e4(char* obj, const void* src) {
    unsigned char count = *(unsigned char*)(obj + RECORD_COUNT_OFFSET);
    if (count >= 0x14) return;
    if (src == NULL) return;
    VectorizedInvertedMemcpy(src, obj + RECORD_ARRAY_OFFSET + count * 0x1c, 0x1c);
    *(unsigned char*)(obj + RECORD_COUNT_OFFSET) += 1;
}
