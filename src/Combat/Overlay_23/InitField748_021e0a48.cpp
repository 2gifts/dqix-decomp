#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct020dfc40;
void ResetAndDetach020dfc6c(struct Struct020dfc40*);


#if defined(jpn)
extern int data_020f2cb0;
#else
extern int data_020f2a1c;
#endif
#if defined(jpn)
extern int data_020f2cac;
#else
extern int data_020f2a10;
#endif


// JPN: func_ov023_021e0fb4
// USA: func_ov023_021e0a48
ARM int InitField748_021e0a48(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x6c4};
#else
 enum {regionalOffset0=0x748};
#endif
    int listPtr = (int)BackgroundLoader::GetInstance();
    ResetAndDetach020dfc6c((struct Struct020dfc40*)((char*)obj + 0x8c));
#if defined(jpn)
    *(int*)((char*)obj + regionalOffset0) = ((BackgroundLoader*)(listPtr))->QueueLoadFileInGP2((const char*)(data_020f2cb0), (const char*)(data_020f2cac), (SafeAllocator*)(0));
#else
    *(int*)((char*)obj + regionalOffset0) = ((BackgroundLoader*)(listPtr))->QueueLoadFileInGP2((const char*)(data_020f2a1c), (const char*)(data_020f2a10), (SafeAllocator*)(0));
#endif

    return 0xc;
}
