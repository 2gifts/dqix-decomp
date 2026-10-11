#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021dd4cc func_ov023_021ddcbc
#endif
#include "Filesystem/BackgroundLoader.h"


extern int data_ov023_021fdb40;
extern int data_ov023_021fdb52;
extern int data_ov023_021fdb60;
extern int data_ov023_021fdb72;

// USA: func_ov023_021dd4cc  (semantic: SetCombatMode_021dd4cc)
extern "C" ARM void func_ov023_021dd4cc(void* objRaw, int mode) {
    char* obj = (char*)objRaw;
    int dataResult = (int)BackgroundLoader::GetInstance();
    signed char scratchVal = *(signed char*)(obj + 0x77d);
    if (mode == scratchVal) {
        if (*(int*)(obj + 0x780) < 0) return;
        ((BackgroundLoader*)(dataResult))->RemoveTask((int)(*(int*)(obj + 0x780)));
        *(int*)(obj + 0x780) = -1;
        obj[0x77e] = *(signed char*)(obj + 0x700 + 0x7d);
        return;
    }
    signed char other = *(signed char*)(obj + 0x77e);
    if (mode == other) return;
    if (*(int*)(obj + 0x780) >= 0) {
        ((BackgroundLoader*)(dataResult))->RemoveTask((int)(*(int*)(obj + 0x780)));
        *(int*)(obj + 0x780) = -1;
        obj[0x77e] = -1;
    }
    int result;
    if (mode == 2) {
        result = ((BackgroundLoader*)(dataResult))->QueueLoadFileInGP2((const char*)((int)&data_ov023_021fdb40), (const char*)((int)&data_ov023_021fdb52), (SafeAllocator*)(0));
    } else {
        result = ((BackgroundLoader*)(dataResult))->QueueLoadFileInGP2((const char*)((int)&data_ov023_021fdb60), (const char*)((int)&data_ov023_021fdb72), (SafeAllocator*)(0));
    }
    *(int*)(obj + 0x780) = result;
    *(unsigned short*)(obj + 0x774) |= 8;
    obj[0x77e] = (char)mode;
}
