#include <globaldefs.h>

#if defined(jpn)
#define func_ov003_0217dc40 func_ov003_0217c8e0
#endif
#include "Filesystem/BackgroundLoader.h"

int GetGlobalField0x1c020421a0(void);

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);
void ReinitController02043204(char* obj);
extern "C" void func_ov003_0217db88(void* obj);

// USA: func_ov003_0217dc40  (semantic: ReinitEntryListAndController_0217dc40)
extern "C" ARM void func_ov003_0217dc40(char* obj) {
    int g = GetGlobalField0x1c020421a0();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    int v = *(int*)(obj + 0xc);
    if (v != -1) {
        int gd = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(gd))->RemoveTask((int)(v));
    }
    ResetEntryList0205d6a0(*(struct Entry_0205d6a0**)(obj + 0x90), 0);
    ReinitController02043204((char*)g);
    func_ov003_0217db88(obj);
}
