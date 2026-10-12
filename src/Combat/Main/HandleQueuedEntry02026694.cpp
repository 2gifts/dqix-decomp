#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


extern "C" int func_02026780(void* self, int a, int b);

struct List0202fec8;

#if defined(jpn)
#define data_020ef6d7 data_020ef5ca
#endif
extern int data_020ef6d7;

#if defined(jpn)
#define HandleQueuedEntry02026694 func_02025ff8
extern "C" ARM void func_02025ff8(char* self);
enum { kPendingOffset = 0x90c, kStateOffset = 0x90d, kCompleteOffset = 0x90e, kTaskOffset = 0x980, kSuccessOffset = 0x6cd };
#else
enum { kPendingOffset = 0x9b8, kStateOffset = 0x9b9, kCompleteOffset = 0x9ba, kTaskOffset = 0xa2c, kSuccessOffset = 0x779 };
#endif

// USA: func_02026694
ARM void HandleQueuedEntry02026694(char* self) {
    int obj;
    int out1;
    int out2;

    if (*(unsigned char*)(self + kPendingOffset) == 0) {
        return;
    }

    obj = (int)BackgroundLoader::GetInstance();

    if (*(unsigned char*)(self + kStateOffset) == 0) {
        ((BackgroundLoader*)(obj))->RemoveTask((int)(*(int*)(self + kTaskOffset)));
        ((BackgroundLoader*)((unsigned char*)obj))->AddFence();
        *(int*)(self + kTaskOffset) = ((BackgroundLoader*)(obj))->QueueLoadFile((const char*)((int)&data_020ef6d7), (SafeAllocator*)(0));
        *(unsigned char*)(self + kStateOffset) += 1;
        return;
    }

    if (*(unsigned char*)(self + kStateOffset) != 1) {
        return;
    }

    if (((BackgroundLoader*)(obj))->GetTaskStatus((int)(*(int*)(self + kTaskOffset))) == 0) {
        return;
    }

    out1 = 0;
    out2 = 0;
    ((BackgroundLoader*)((struct List0202fec8*)obj))->GetLoadedFileByID((int)(*(int*)(self + kTaskOffset)), (void**)(&out1), (unsigned int*)(&out2));

    if (func_02026780(self, out1, out2) == 0) {
        *(unsigned char*)(self + kCompleteOffset) = 1;
    } else {
        *(unsigned char*)(self + kSuccessOffset) = 1;
        *(unsigned char*)(self + kCompleteOffset) = 1;
    }

    ((BackgroundLoader*)(obj))->RemoveTask((int)(*(int*)(self + kTaskOffset)));
    *(int*)(self + kTaskOffset) = -1;
    *(unsigned char*)(self + kPendingOffset) = 0;
    *(unsigned char*)(self + kStateOffset) += 1;
}
