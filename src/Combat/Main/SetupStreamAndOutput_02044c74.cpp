#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_0204c684(void* obj);
extern "C" int _Z25AllocateVRAMStagingMemoryj(int value);

#if defined(jpn)
enum { kFlagOffset = 0x7fe, kOutputValue = 12 };
#else
enum { kFlagOffset = 0x9cd, kOutputValue = 8 };
#endif

// USA: func_02044c74  (semantic: SetupStreamAndOutput_02044c74)
extern "C" ARM void func_02044c74(void* obj, void* out) {
    char* o = (char*)obj;
    char* dst = (char*)out;
    func_0204c684(out);
    void* buf = (void*)_Z25AllocateVRAMStagingMemoryj(0x4800);
    if (buf) {
        unsigned char* p = (unsigned char*)(o + 0x1000);
        if (p[kFlagOffset]) {
            p[kFlagOffset] = 0;
            memset(buf, 0, 0x4800);
        }
        *(short*)(dst + 0xac) = 0;
        *(short*)(dst + 0xae) = 6;
        *(short*)(dst + 0xa8) = 0x20;
        *(short*)(dst + 0xaa) = 0x12;
        *(void**)(dst + 0x8) = buf;
        *(int*)(dst + 0xa4) = 0x4800;
        *(int*)(dst + 0xa0) = 0;
        *(short*)(dst + 0xc2) = 0;
        *(short*)(dst + 0xb0) = 0;
        *(short*)(dst + 0xb2) = 0;
        *(short*)(dst + 0xb4) = kOutputValue;
        *(short*)(dst + 0xb6) = kOutputValue;
        *(short*)(dst + 0xb8) = kOutputValue;
        *(short*)(dst + 0xba) = kOutputValue;
    }
}
