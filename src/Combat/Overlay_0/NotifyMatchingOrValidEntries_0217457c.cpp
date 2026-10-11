#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x488
#else
#define REGION_OFFSET_0 0x448
#endif


extern "C" void func_ov000_02170db0(void* p);

// USA: func_ov000_0217457c  (semantic: NotifyMatchingOrValidEntries_0217457c)
extern "C" ARM void func_ov000_0217457c(void* obj, int id) {
    if (id < 0) {
        int i;
        for (i = 0; i < 4; i++) {
            signed char j = *((signed char*)obj + i + 0x6c);
            void* e = (char*)obj + 0x158 + 0x800 + j * REGION_OFFSET_0;
            if (*(int*)((char*)e + 0x4c) >= 0) {
                func_ov000_02170db0(e);
            }
        }
        return;
    }
    int i;
    for (i = 0; i < 4; i++) {
        signed char j = *((signed char*)obj + i + 0x6c);
        void* e = (char*)obj + 0x158 + 0x800 + j * REGION_OFFSET_0;
        if (id == *(int*)((char*)e + 0x4c)) {
            func_ov000_02170db0(e);
            return;
        }
    }
}
