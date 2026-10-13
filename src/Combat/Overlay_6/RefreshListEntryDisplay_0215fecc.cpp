#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct ResultSprite {
    char unknown0[0x70];
};

struct AlchemyMenu {
#if defined(jpn)
    char unknown0[4];
#else
    char unknown0[0xc];
#endif
    SafeAllocator* allocators;
#if defined(jpn)
    char unknown8[0x3b8 - 8];
#else
    char unknown10[0x3b8 - 0x10];
#endif
    ResultSprite resultSprite;
    int resultTask;
};

extern "C" void func_02076080(ResultSprite* sprite, SafeAllocator* allocator, void* file, unsigned int size);

// USA: func_ov006_0215fecc
extern "C" ARM int func_ov006_0215fecc(AlchemyMenu* menu) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(menu->resultTask))
        return 0;
    SafeAllocator* allocator = &menu->allocators[9];
    allocator->Reset();
    void* file = NULL;
    unsigned int fileSize = 0;
    loader->GetLoadedFileByID(menu->resultTask, &file, &fileSize);
    func_02076080(&menu->resultSprite, allocator, file, fileSize);
    loader->RemoveTask(menu->resultTask);
    menu->resultTask = -1;
    return 1;
}
