#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct List0202fec8;
extern "C" {
}
extern "C" void func_ov023_021db314(void* obj, short* out, short* outCount);
extern "C" int func_020e0028(void* p, void* b, int out1, int out2, void* p2, int field84);
void InitAndAppendTextB_021e0eb8(void* obj);

// JPN: func_ov023_021e0ffc
// USA: func_ov023_021e0a90  (semantic: DispatchListEntryCodes_021e0a90)
extern "C" ARM int func_ov023_021e0a90(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x6c4};
#else
 enum {regionalOffset0=0x748};
#endif
    if (*(int*)((char*)obj + regionalOffset0) == -1) {
        return 0xd;
    }

    int listPtr = (int)BackgroundLoader::GetInstance();
    if (((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(*(int*)((char*)obj + regionalOffset0)))) {
        int out1;
        int out2;
        ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(*(int*)((char*)obj + regionalOffset0)), (void**)(&out1), (unsigned int*)(&out2));
#if defined(jpn)
        {
#else
        if (out1 != 0 && out2 != 0) {
#endif

            short codes[12];
            short count;
            func_ov023_021db314((char*)obj + 0x6c, codes, &count);
            func_020e0028((char*)obj + 0x8c, (char*)obj + 0x28, out1, out2, codes, (unsigned short)count);
        }

        ((BackgroundLoader*)(listPtr))->RemoveTask((int)(*(int*)((char*)obj + regionalOffset0)));
        *(int*)((char*)obj + regionalOffset0) = -1;
        InitAndAppendTextB_021e0eb8(obj);
        return 0xd;
    }

    return 0xb;
}
