#if defined(jpn)
#define SUBSTRUCT_LAST_BYTE_OFFSET 0x7ca6
#else
#define SUBSTRUCT_LAST_BYTE_OFFSET 0x7f7a
#endif
#if defined(jpn)
#define SUBSTRUCT_ARRAY_OFFSET 0x7ca2
#else
#define SUBSTRUCT_ARRAY_OFFSET 0x7f76
#endif
#if defined(jpn)
#define SUBSTRUCT_BYTE1_OFFSET 0x7ca1
#else
#define SUBSTRUCT_BYTE1_OFFSET 0x7f75
#endif
#if defined(jpn)
#define SUBSTRUCT_BYTE0_OFFSET 0x7ca0
#else
#define SUBSTRUCT_BYTE0_OFFSET 0x7f74
#endif
#include <globaldefs.h>

// JPN: func_0200f99c
// USA: func_0200fb40
ARM void ClearSubstructBytes(void* obj) {
    char* base = (char*)obj;
    unsigned char i;
    base[SUBSTRUCT_BYTE0_OFFSET] = 0;
    base[SUBSTRUCT_BYTE1_OFFSET] = 0;
    for (i = 0; i < 4; i++) {
        (base + i)[SUBSTRUCT_ARRAY_OFFSET] = 0;
    }
    base[SUBSTRUCT_LAST_BYTE_OFFSET] = 0;
}
