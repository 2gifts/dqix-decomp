#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

void ClearStruct16(void* p);

#if defined(jpn)
extern int data_020f2cb0;
#else
extern int data_020f2a1c;
#endif
extern int data_020f2a28;

// JPN: func_ov023_021e10a8
// USA: func_ov023_021e0b54
ARM int InitField74c_021e0b54(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x6c8};
#else
 enum {regionalOffset0=0x74c};
#endif
    int listPtr = (int)BackgroundLoader::GetInstance();
    ClearStruct16((char*)obj + 0x7c);
#if defined(jpn)
    *(int*)((char*)obj + regionalOffset0) = ((BackgroundLoader*)(listPtr))->QueueLoadFileInGP2((const char*)(data_020f2cb0), (const char*)(data_020f2a28), (SafeAllocator*)(0));
#else
    *(int*)((char*)obj + regionalOffset0) = ((BackgroundLoader*)(listPtr))->QueueLoadFileInGP2((const char*)(data_020f2a1c), (const char*)(data_020f2a28), (SafeAllocator*)(0));
#endif

    return 0xe;
}
