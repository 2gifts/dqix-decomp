#include <globaldefs.h>

#if defined(jpn)
#define REGION_BASE1 (0x194 + 0x1c00)
#define REGION_COUNT1 8
#define REGION_STRIDE1 0x38
#else
#define REGION_BASE1 (0x30c + 0x1800)
#define REGION_COUNT1 3
#define REGION_STRIDE1 0x18
#endif

extern "C" void* func_ov000_02161318(void* obj, int id);
void ReleaseGlobalEntry0203c198(char* obj);

// USA: func_ov000_02181608  (semantic: ReleaseAllGlobalEntries_02181608)
extern "C" ARM void func_ov000_02181608(void* obj) {
    for (int i = 0; i < 4; i++) {
        char* entry = (char*)func_ov000_02161318(obj, i);
        if (entry) {
            ReleaseGlobalEntry0203c198(entry + 0x50);
        }
    }
    char* base1 = (char*)obj + REGION_BASE1;
    for (int j = 0; j < REGION_COUNT1; j++) {
        ReleaseGlobalEntry0203c198(base1 + j * REGION_STRIDE1);
    }
#if !defined(jpn)
    char* base2 = (char*)obj + 0x5c + 0x1c00;
    for (int j = 0; j < 8; j++) {
        ReleaseGlobalEntry0203c198(base2 + j * 0x18);
    }
#endif
}
