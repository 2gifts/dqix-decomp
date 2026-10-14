#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/SpriteAffineTransform.h"

#if defined(jpn)
#define REGION(j,u) (j)
#else
#define REGION(j,u) (u)
#endif

struct InfoWindowLoad021ddae4 {
    char beforeAllocator[0x44];
    SafeAllocator* allocator;
    char beforeRenderer[REGION(0x128,0x12c) - 0x48];
    SpriteContext0205ac40 renderer;
    char beforeDisplayState[REGION(0x6f9,0x77d) - REGION(0x128,0x12c) - sizeof(SpriteContext0205ac40)];
    signed char displayState;
    signed char pendingState;
    int task;
};

struct ActiveEntry02046900;
int CountActiveEntries(ActiveEntry02046900* entry);
struct Rec020467f0;
void* FindRecordByIndex(Rec020467f0* rec, int index, void** out, int* out44);
extern "C" int func_0205a528(void* renderer, void* data, int kind, int allocator);

// USA: func_ov023_021ddae4
extern "C" ARM void func_ov023_021ddae4(void* obj) {
    InfoWindowLoad021ddae4* view = (InfoWindowLoad021ddae4*)obj;
    if (view->task < 0) return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(view->task)) return;
    view->allocator->Reset();
    void* record;
    void* file;
    unsigned int length;
    int kind;
    loader->GetLoadedFileByID(view->task, &file, &length);
#if !defined(jpn)
    if (file != 0 && length != 0)
#endif
    {
        int count = CountActiveEntries((ActiveEntry02046900*)file);
        for (int i = 0; i < count; i++) {
            void* data = FindRecordByIndex((Rec020467f0*)file, i, &record, &kind);
            func_0205a528(&view->renderer, data, kind, (int)view->allocator);
        }
    }
    view->displayState = view->pendingState;
    loader->RemoveTask(view->task);
    view->task = -1;
}
