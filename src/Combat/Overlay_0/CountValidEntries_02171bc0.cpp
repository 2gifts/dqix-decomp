#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x430
#else
#define REGION_OFFSET_0 0x3f0
#endif


// USA: func_ov000_02171bc0  (semantic: CountValidEntries_02171bc0)
extern "C" ARM int func_ov000_02171bc0(char* arr) {
    signed char count = 0;
    for (int i = 0; i < 0x10; i++) {
        void* p = *(void**)(arr + i * 4 + REGION_OFFSET_0);
        if (p != 0) {
            short v = *(short*)((char*)p + 0x18);
            if (v > 0) {
                count = (signed char)(count + 1);
            }
        }
    }
    return count;
}
