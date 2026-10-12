#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021dd4cc func_ov023_021ddcbc
#endif
#include "Filesystem/BackgroundLoader.h"


#if defined(jpn)
extern char data_ov023_021fce18[];
extern char data_ov023_021fce2d[];
enum { ModeFlagsOffset = 0x6f0, CurrentModeOffset = 0x6f9, PendingModeOffset = 0x6fa, ModeTaskOffset = 0x6fc };
#else
extern int data_ov023_021fdb40;
extern int data_ov023_021fdb52;
extern int data_ov023_021fdb60;
extern int data_ov023_021fdb72;
enum { ModeFlagsOffset = 0x774, CurrentModeOffset = 0x77d, PendingModeOffset = 0x77e, ModeTaskOffset = 0x780 };
#endif

// USA: func_ov023_021dd4cc  (semantic: SetCombatMode_021dd4cc)
extern "C" ARM void func_ov023_021dd4cc(void* objRaw, int mode) {
    char* obj = (char*)objRaw;
    int dataResult = (int)BackgroundLoader::GetInstance();
    signed char scratchVal = *(signed char*)(obj + CurrentModeOffset);
    if (mode == scratchVal) {
        if (*(int*)(obj + ModeTaskOffset) < 0) return;
        ((BackgroundLoader*)(dataResult))->RemoveTask((int)(*(int*)(obj + ModeTaskOffset)));
        *(int*)(obj + ModeTaskOffset) = -1;
        obj[PendingModeOffset] = *(signed char*)(obj + CurrentModeOffset);
        return;
    }
    signed char other = *(signed char*)(obj + PendingModeOffset);
    if (mode == other) return;
    if (*(int*)(obj + ModeTaskOffset) >= 0) {
        ((BackgroundLoader*)(dataResult))->RemoveTask((int)(*(int*)(obj + ModeTaskOffset)));
        *(int*)(obj + ModeTaskOffset) = -1;
        obj[PendingModeOffset] = -1;
    }
    int result;
    if (mode == 2) {
#if defined(jpn)
        result = ((BackgroundLoader*)(dataResult))->QueueLoadFile(data_ov023_021fce18, (SafeAllocator*)(0));
#else
        result = ((BackgroundLoader*)(dataResult))->QueueLoadFileInGP2((const char*)((int)&data_ov023_021fdb40), (const char*)((int)&data_ov023_021fdb52), (SafeAllocator*)(0));
#endif
    } else {
#if defined(jpn)
        result = ((BackgroundLoader*)(dataResult))->QueueLoadFile(data_ov023_021fce2d, (SafeAllocator*)(0));
#else
        result = ((BackgroundLoader*)(dataResult))->QueueLoadFileInGP2((const char*)((int)&data_ov023_021fdb60), (const char*)((int)&data_ov023_021fdb72), (SafeAllocator*)(0));
#endif
    }
    *(int*)(obj + ModeTaskOffset) = result;
    *(unsigned short*)(obj + ModeFlagsOffset) |= 8;
    obj[PendingModeOffset] = (char)mode;
}
