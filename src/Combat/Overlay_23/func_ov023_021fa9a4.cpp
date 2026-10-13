#include <globaldefs.h>

#if defined(jpn)
#endif
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov011_021849c8(void* ctx);

extern "C" {
    int func_ov023_021f6bb8(void* obj);
    void func_ov023_021f6bb0(void* obj, int v);
    void func_ov023_021fab48(void* obj, void* ctx, const void* fileData, int fileLength);
}

struct Obj021fa9a4 {
    char pad[0x1c];
    int state;
};

// USA: func_ov023_021fa9a4  (semantic: DispatchOrReturnField1c_021fa9a4)
extern "C" ARM int func_ov023_021fa9a4(struct Obj021fa9a4* obj, void* ctx) {
    void* node = func_ov011_021849c8(ctx);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int taskId = func_ov023_021f6bb8(node);
    if (loader->GetTaskStatus(taskId)) {
        if (loader->GetDetailedTaskStatus(taskId) == BackgroundLoader::TaskStatus_Complete) {
            void* fileData;
            unsigned int fileLength;
            loader->GetLoadedFileByID(taskId, &fileData, &fileLength);
            func_ov023_021fab48(obj, ctx, fileData, fileLength);
        }

        loader->RemoveTask(taskId);
        func_ov023_021f6bb0(node, -1);
        return 2;
    }
    return obj->state;
}
