#include <globaldefs.h>

#if defined(jpn)
enum { FLAGS_OFFSET = 0x180 };
#else
enum { FLAGS_OFFSET = 0x18c };
#endif

#if defined(jpn)
#define ApplyFlag0x80ToBit0x1ClearFlag0x100 func_020555c0
extern "C" ARM void func_020555c0(void* obj);
#endif

// USA: func_02054248
ARM void ApplyFlag0x80ToBit0x1ClearFlag0x100(void* obj) {
    unsigned int* flags = (unsigned int*)((char*)obj + FLAGS_OFFSET);
    unsigned int value = *flags;
    if (!(value & 0x100)) {
        return;
    }
    if (value & 0x80) {
        *flags = value | 0x1;
    } else if (value & 0x80) {
        *flags = value & ~0x1;
    }
    *flags = *flags & ~0x100;
}
