#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

#if defined(jpn)
extern int data_020f2cb0;
extern int data_020f2ca4;
#else
extern int data_020f2a1c;
extern int data_020f2a14;
#endif


struct ElemFields_021e05e4 {
    unsigned int pad0[2];
    unsigned int lowBits : 4;
    unsigned int rest : 28;
};

// JPN: func_ov023_021e0b70
// USA: func_ov023_021e05e4
ARM int ClearBufferAndCheckField_021e05e4(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x6f0, regionalOffset1=0x62c, regionalOffset2=0x80, regionalOffset3=0x6bc};
#else
 enum {regionalOffset0=0x774, regionalOffset1=0x630, regionalOffset2=0x100, regionalOffset3=0x740};
#endif
    int listPtr = (int)BackgroundLoader::GetInstance();

    if (*(unsigned short*)((char*)obj + regionalOffset0) & 0x1000) return 8;
    if (*(void**)((char*)obj + 0x4c) == 0) return 3;

    memset((char*)obj + regionalOffset1, 0, regionalOffset2);

#if defined(jpn)
    int result = ((BackgroundLoader*)(listPtr))->QueueLoadFileInGP2((const char*)(data_020f2cb0), (const char*)(data_020f2ca4), (SafeAllocator*)(0));
#else
    int result = ((BackgroundLoader*)(listPtr))->QueueLoadFileInGP2((const char*)(data_020f2a1c), (const char*)(data_020f2a14), (SafeAllocator*)(0));
#endif

    *(int*)((char*)obj + regionalOffset3) = result;

    unsigned int fieldVal = ((struct ElemFields_021e05e4*)(*(void**)((char*)obj + 0x4c)))->lowBits;
    int cond = fieldVal <= 7;
    if (cond != 0) return 3;

    if (*(unsigned short*)((char*)obj + regionalOffset0) & 0x400) return 3;
    return 8;
}
