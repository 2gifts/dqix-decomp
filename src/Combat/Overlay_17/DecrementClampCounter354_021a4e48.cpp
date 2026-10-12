#include <globaldefs.h>
#if defined(jpn)
#define READ_BASE 0x4100
#define READ_OFFSET 0x34
#define WRITE_OFFSET 0x134
#else
#define READ_BASE 0x4300
#define READ_OFFSET 0x54
#define WRITE_OFFSET 0x354
#endif

// USA: func_ov017_021a4e48
ARM void DecrementClampCounter354_021a4e48(unsigned char* obj) {
    signed char v = *(signed char*)(obj + READ_BASE + READ_OFFSET);
    *(signed char*)(obj + 0x4000 + WRITE_OFFSET) = v - 1;
    signed char v2 = *(signed char*)(obj + READ_BASE + READ_OFFSET);
    if (v2 < 0) {
        *(signed char*)(obj + 0x4000 + WRITE_OFFSET) = 0;
    }
}
