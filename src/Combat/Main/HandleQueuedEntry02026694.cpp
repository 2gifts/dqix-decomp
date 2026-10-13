#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Obj02026780;
extern "C" int func_02026780(Obj02026780* context, void* archive, unsigned int archiveSize);

#if defined(jpn)
#define data_020ef6d7 data_020ef5ca
#define HandleQueuedEntry02026694 func_02025ff8
extern "C" ARM void func_02025ff8(char* context);
enum { SuccessOffset = 0x6cd };
#else
enum { SuccessOffset = 0x779 };
#endif


extern const char data_020ef6d7[];

struct TreasureLoadContextPrefix {
    unsigned char unknown0[SuccessOffset];
    unsigned char succeeded;
    unsigned char unknownAfterSuccess[0x23e];
    unsigned char pending;
    unsigned char state;
    unsigned char complete;
    unsigned char unknownAfterComplete[0x71];
    int taskId;
};

// USA: func_02026694
ARM void HandleQueuedEntry02026694(char* context) {
    TreasureLoadContextPrefix* request = reinterpret_cast<TreasureLoadContextPrefix*>(context);
    if (request->pending == 0) return;

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (request->state == 0) {
        loader->RemoveTask(request->taskId);
        loader->AddFence();
        request->taskId = loader->QueueLoadFile(data_020ef6d7, NULL);
        request->state++;
        return;
    }
    if (request->state != 1) return;
    if (loader->GetTaskStatus(request->taskId) == 0) return;

    void* archive = NULL;
    unsigned int archiveSize = 0;
    loader->GetLoadedFileByID(request->taskId, &archive, &archiveSize);
    if (func_02026780(reinterpret_cast<Obj02026780*>(context), archive, archiveSize) == 0) {
        request->complete = 1;
    } else {
        request->succeeded = 1;
        request->complete = 1;
    }
    loader->RemoveTask(request->taskId);
    request->taskId = -1;
    request->pending = 0;
    request->state++;
}
