#include <globaldefs.h>

#if defined(jpn)
#define func_ov006_0215fecc func_ov006_02161230
enum { kAllocatorOwner = 4 };
#else
enum { kAllocatorOwner = 0xc };
#endif


#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct List0202fec8;
extern "C" void func_02076080(void* a, void* b, int c, int d);

// USA: func_ov006_0215fecc  (semantic: RefreshListEntryDisplay_0215fecc)
extern "C" ARM int func_ov006_0215fecc(char* self) {
    void* list = (void*)(int)BackgroundLoader::GetInstance();
    if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(*(int*)(self + 0x428)))) {
        return 0;
    }
    char* base = *(char**)(self + kAllocatorOwner);
    SafeAllocator* alloc = (SafeAllocator*)(base + 0xb4);
    alloc->Reset();
    int out1 = 0;
    int out2 = 0;
    ((BackgroundLoader*)((struct List0202fec8*)list))->GetLoadedFileByID((int)(*(int*)(self + 0x428)), (void**)(&out1), (unsigned int*)(&out2));
    func_02076080(self + 0x3b8, alloc, out1, out2);
    ((BackgroundLoader*)(list))->RemoveTask((int)(*(int*)(self + 0x428)));
    *(int*)(self + 0x428) = -1;
    return 1;
}
