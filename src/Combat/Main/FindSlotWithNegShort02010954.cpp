#include <globaldefs.h>
#if defined(jpn)
enum { kStride = 0x8cc };
#else
enum { kStride = 0x964 };
#endif

// USA: func_02010954
ARM void* FindSlotWithNegShort02010954(char* base) {
    int i;
    for (i = 0; i < 4; i++) {
        if (*(short*)(base + i * kStride + 0x9dc) < 0) {
            return base + 0x474 + i * kStride;
        }
    }
    return NULL;
}
