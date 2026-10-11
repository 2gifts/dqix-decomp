#include <globaldefs.h>
#if defined(jpn)
enum { entryStride = 0x488 };
#else
enum { entryStride = 0x448 };
#endif

// USA: func_ov000_0217fcc4  (semantic: ClearField24Bit0_0217fcc4)
extern "C" ARM void func_ov000_0217fcc4(void* obj, int id) {
    if (id < 0) {
        int i;
        for (i = 0; i < 4; i++) {
            signed char j = *((signed char*)obj + i + 0x6c);
            void* e = (char*)obj + 0x158 + 0x800 + j * entryStride;
            if (*(int*)((char*)e + 0x4c) >= 0) {
                unsigned char v = *((unsigned char*)e + 0x24);
                v &= ~1;
                *((unsigned char*)e + 0x24) = v;
            }
        }
        return;
    }
    int i;
    for (i = 0; i < 4; i++) {
        signed char j = *((signed char*)obj + i + 0x6c);
        void* e = (char*)obj + 0x158 + 0x800 + j * entryStride;
        if (id == *(int*)((char*)e + 0x4c)) {
            unsigned char v = *((unsigned char*)e + 0x24);
            v &= ~1;
            *((unsigned char*)e + 0x24) = v;
            return;
        }
    }
}
