#include <globaldefs.h>
#if defined(jpn)
enum { kRegion1000 = 0xf00 };
enum { kRegion46 = 0xc2 };
#else
enum { kRegion1000 = 0x1000 };
enum { kRegion46 = 0x46 };
#endif

extern "C" int func_ov023_021dc488(void* obj);

// JPN: func_ov003_02173a94
// USA: func_ov003_02174988
ARM void ClearFlag80AtOffset1000_02174988(char* self) {
    if ((*(unsigned short*)(self + kRegion1000 + kRegion46) & 0x80) == 0) {
        return;
    }
    if (func_ov023_021dc488(self + 0x3c) != 0) {
        *(unsigned short*)(self + kRegion1000 + kRegion46) &= ~0x80;
    }
}
