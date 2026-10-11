#include <globaldefs.h>
#if defined(jpn)
enum { kRegion30 = 0xc };
enum { kRegion394 = 0x27c };
enum { kRegion228 = 0x110 };
enum { kRegion435c = 0x413c };
#else
enum { kRegion30 = 0x30 };
enum { kRegion394 = 0x394 };
enum { kRegion228 = 0x228 };
enum { kRegion435c = 0x435c };
#endif

#include "std_library_functions.h"

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void* thisPtr, unsigned int size);

struct FmtTable021602bc { char rows[4][kRegion30]; };

// JPN: func_ov003_02160468
// USA: func_ov003_021602bc
extern "C" ARM void func_ov003_021602bc(char* obj) {
    char* langData = (char*)func_ov017_0218b5b0();

    for (int i = 0; i < 4; i++) {
        (*(void***)(obj + kRegion394))[i] = 0;
        void* buf = _ZN13SafeAllocator8AllocateEj(obj + kRegion228, kRegion30);
        (*(void***)(obj + kRegion394))[i] = buf;
        void* p = (*(void***)(obj + kRegion394))[i];
        memset(p, 0, kRegion30);

        FmtTable021602bc* table = (FmtTable021602bc*)(langData + kRegion435c);
        char* fmt = table->rows[i];
        if (fmt != 0) {
            void* dst = (*(void***)(obj + kRegion394))[i];
#if defined(jpn)
            memcpy(dst, fmt, 0xc);
#else
            sprintf((char*)dst, fmt);
#endif
        }
    }
}
