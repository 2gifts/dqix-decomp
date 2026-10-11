// USA: func_ov003_0216d818
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

int GetGlobalField0x1c020421a0();
void ReinitController02043204(char* obj);

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);

extern "C" void func_ov003_0216d77c(void* obj);

ARM void ResetGlobalsAndReinit_0216d818(char* obj) {
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    ReinitController02043204((char*)GetGlobalField0x1c020421a0());
#if defined(jpn)
    enum { entriesOffset = 0x1150 };
#else
    enum { entriesOffset = 0x12c0 };
#endif
    ResetEntryList0205d6a0(*(struct Entry_0205d6a0**)(obj + entriesOffset), 0);
    func_ov003_0216d77c(obj);
}
