#include <globaldefs.h>

#if defined(jpn)
enum { kModeOffset = 0x870, kFlagOffset = 0x17ea, kSubobjectOffset = 0x50 };
#else
enum { kModeOffset = 0x9a0, kFlagOffset = 0x19ba, kSubobjectOffset = 0x90 };
#endif

extern "C" void func_0205c96c(void* obj, int arg);

// USA: func_02044530
ARM void CallFunc0205c96cIfMode6AndFlag(char* base, int arg) {
    if (*(int*)(base + kModeOffset) != 6) return;
    if (*(unsigned char*)(base + kFlagOffset) == 0) return;
    func_0205c96c(base + kSubobjectOffset, arg);
}
