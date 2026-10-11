#include <globaldefs.h>
#if defined(jpn)
enum { kRegion45c = 0x284 };
enum { kRegion4a0 = 0x2c8 };
#else
enum { kRegion45c = 0x45c };
enum { kRegion4a0 = 0x4a0 };
#endif


extern "C" void func_ov003_021666c4(void* self);

// JPN: func_ov003_02166534
// USA: func_ov003_0216664c
ARM void UpdateSignedField4a0_0216664c(void* self) {
    int flags = *(int*)((char*)self + kRegion45c);
    int changed = 0;
    if (flags & 0x10) {
        signed char v = *((signed char*)self + kRegion4a0);
        changed = 1;
        *((signed char*)self + kRegion4a0) = v + 1;
    } else if (flags & 0x20) {
        signed char v = *((signed char*)self + kRegion4a0);
        changed = 1;
        *((signed char*)self + kRegion4a0) = v - 1;
    }
    signed char v = *((signed char*)self + kRegion4a0);
    if (v >= 2) {
        *((signed char*)self + kRegion4a0) = 0;
    } else if (v < 0) {
        *((signed char*)self + kRegion4a0) = 1;
    }
    if (changed) {
        func_ov003_021666c4(self);
    }
}
