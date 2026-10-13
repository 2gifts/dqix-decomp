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

struct OverlayController {
    char unknown0[0xc];
    int backgroundTask;
#if defined(jpn)
    char unknown10[0x8c - 0x10];
#else
    char unknown10[0x90 - 0x10];
#endif
    Entry_0205d6a0* entryList;
};

// USA: func_ov003_0217dc40  (semantic: ReinitEntryListAndController_0217dc40)
extern "C" ARM void func_ov003_0217dc40(OverlayController* obj) {
    int g = GetGlobalField0x1c020421a0();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
#if !defined(jpn)
    int task = obj->backgroundTask;
    if (task != -1) {
        BackgroundLoader::GetInstance()->RemoveTask(task);
    }

#endif
    ResetEntryList0205d6a0(obj->entryList, 0);
    ReinitController02043204((char*)g);
    func_ov003_0217db88(obj);
}
