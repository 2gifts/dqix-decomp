#include <globaldefs.h>

#if defined(jpn)
#define BYTE_LOOKUP_COUNT 0x54c1
#define BYTE_LOOKUP_VALUES 0x54bd
#else
#define BYTE_LOOKUP_COUNT 0x5721
#define BYTE_LOOKUP_VALUES 0x571d
#endif

// USA: func_02011518
ARM int GetCheckedSignedByte(void* obj, unsigned int idx) {
    if (idx < ((unsigned char*)obj)[BYTE_LOOKUP_COUNT]) {
        return ((signed char*)obj + idx)[BYTE_LOOKUP_VALUES];
    }
    return -1;
}
