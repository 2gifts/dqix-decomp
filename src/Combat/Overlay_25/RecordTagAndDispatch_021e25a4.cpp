#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

int FindTagAndCopy_021e24d0(char* s, char* out2, char* out1);

#if defined(jpn)
struct Struct021ef988 { char pad[0xc]; unsigned int flags; };
#else
struct Struct021ef988 { char pad[0x1c]; unsigned int flags; };
#endif
extern Struct021ef988 data_ov025_021ef988;

// JPN: func_ov025_021e2abc
// USA: func_ov025_021e25a4  (semantic: RecordTagAndDispatch_021e25a4)
extern "C" ARM void func_ov025_021e25a4(char* s) {
    char buf2[0x50];
    char buf1[0x50];
    int d = (int)BackgroundLoader::GetInstance();
    if (!(data_ov025_021ef988.flags & 0x2000)) {
        ((BackgroundLoader*)((unsigned char*)d))->AddFence();
        data_ov025_021ef988.flags |= 0x2000;
    }
    if (FindTagAndCopy_021e24d0(s, buf2, buf1)) {
        ((BackgroundLoader*)(d))->QueueLoadFileInGP2((const char*)((int)buf2), (const char*)((int)buf1), (SafeAllocator*)(0));
    } else {
        ((BackgroundLoader*)(d))->QueueLoadFile((const char*)((int)s), (SafeAllocator*)(0));
    }
}
