#include <globaldefs.h>

#if defined(jpn)
enum { kModeOffset = 0x870, kFlagOffset = 0x17ea, kSubobjectOffset = 0x50 };
#else
enum { kModeOffset = 0x9a0, kFlagOffset = 0x19ba, kSubobjectOffset = 0x90 };
#endif
#if defined(jpn)
#define func_0205c96c func_0205dcd4
#endif


extern "C" void func_0205c96c(void* obj, int arg);

#if defined(jpn)
#define CallFunc0205c96cIfMode6AndFlag func_02044c5c
extern "C" ARM void func_02044c5c(char* base, int arg);
#endif

// USA: func_02044530
ARM void CallFunc0205c96cIfMode6AndFlag(char* base, int arg) {
    if (*(int*)(base + kModeOffset) != 6) return;
    if (*(unsigned char*)(base + kFlagOffset) == 0) return;
    func_0205c96c(base + kSubobjectOffset, arg);
}
