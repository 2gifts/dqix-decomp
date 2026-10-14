#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct List0202fec8;

struct InitStruct2075;
void ClearStructFields_02075d64(struct InitStruct2075* p);

extern "C" void func_02076080(void* a, void* b, int c, int d);

// USA: func_ov023_021e0328
extern "C" ARM int func_ov023_021e0328(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x6b4, regionalOffset1=0x6f0};
#else
 enum {regionalOffset0=0x738, regionalOffset1=0x774};
#endif
    if (*(int*)((char*)obj + regionalOffset0) == -1) {
        return 5;
    }

    int listPtr = (int)BackgroundLoader::GetInstance();
    if (((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(*(int*)((char*)obj + regionalOffset0)))) {
        int out1, out2;
        ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(*(int*)((char*)obj + regionalOffset0)), (void**)(&out1), (unsigned int*)(&out2));
        ClearStructFields_02075d64(*(struct InitStruct2075**)((char*)obj + 0xc8));

#if defined(jpn)
        if (out1 != 0) {
#else
        if (out1 != 0 && out2 != 0) {
#endif

            ((SafeAllocator*)(*(void**)((char*)obj + 0x40)))->Reset();
            func_02076080(*(void**)((char*)obj + 0xc8), *(void**)((char*)obj + 0x40), out1, out2);
            *(unsigned short*)((char*)obj + regionalOffset1) &= ~8;
        }

        ((BackgroundLoader*)(listPtr))->RemoveTask((int)(*(int*)((char*)obj + regionalOffset0)));
        *(int*)((char*)obj + regionalOffset0) = -1;

        int tmpC4 = *(int*)((char*)obj + 0xc4);
        *(int*)((char*)obj + 0xc4) = *(int*)((char*)obj + 0xc8);
        *(int*)((char*)obj + 0xc8) = tmpC4;

        int tmp3c = *(int*)((char*)obj + 0x3c);
        *(int*)((char*)obj + 0x3c) = *(int*)((char*)obj + 0x40);
        *(int*)((char*)obj + 0x40) = tmp3c;

        *(unsigned short*)((char*)obj + regionalOffset1) |= 2;
        return 5;
    }

    return 3;
}
