#include <globaldefs.h>
#if defined(jpn)
enum { kRecordStride = 0x8cc };
#else
enum { kRecordStride = 0x964 };
#endif


// USA: func_020108f0
ARM void* FindRecordByShortField020108f0(void* obj, int value) {
    if (value < 0 || value >= 4) {
        return NULL;
    }
    for (int i = 0; i < 4; i++) {
        int offset = i * kRecordStride;
        short v = *(short*)((char*)obj + offset + 0x9dc);
        if (value == v) {
            return (char*)obj + 0x74 + 0x400 + offset;
        }
    }
    return NULL;
}
