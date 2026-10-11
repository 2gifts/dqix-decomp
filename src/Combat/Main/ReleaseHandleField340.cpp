#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void func_020938f0(void* obj);

// USA: func_020939ac
ARM void ReleaseHandleField340(void* obj) {
    int token = (int)BackgroundLoader::GetInstance();
#if defined(jpn)
    if (*(int*)((char*)obj + 0x100) >= 0) {
#else
    if (*(int*)((char*)obj + 0x340) >= 0) {
#endif
#if defined(jpn)
        ((BackgroundLoader*)(token))->RemoveTask(*(int*)((char*)obj + 0x100));
#else
        ((BackgroundLoader*)(token))->RemoveTask(*(int*)((char*)obj + 0x340));
#endif
#if defined(jpn)
        *(int*)((char*)obj + 0x100) = -1;
#else
        *(int*)((char*)obj + 0x340) = -1;
#endif
    }
    func_020938f0(obj);
}
