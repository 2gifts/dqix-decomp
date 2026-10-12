#include <globaldefs.h>

extern "C" void NSBXX_Model_SetDiffuseReflectionColor(void*, unsigned int);

#if defined(jpn)
#define NotifyActiveSlots02018f30 func_02018cd0
extern "C" ARM void func_02018cd0(unsigned char* obj);
enum { kModelOffset = 0x50c, kColorOffset = 0x56 };
#else
enum { kModelOffset = 0x4ec, kColorOffset = 0x36 };
#endif

// USA: func_02018f30
ARM void NotifyActiveSlots02018f30(unsigned char* obj) {
    int i;
    for (i = 0; i < 2; i++) {
        void* p = *(void**)(obj + i * 0xac + kModelOffset);
        if (p != NULL) {
            NSBXX_Model_SetDiffuseReflectionColor(p, *(unsigned short*)(obj + kColorOffset));
        }
    }
}
