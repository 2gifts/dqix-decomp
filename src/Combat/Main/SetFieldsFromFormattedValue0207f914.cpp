#include <globaldefs.h>

#if defined(jpn)
enum { kResultOffset = 0x1c };
#else
enum { kResultOffset = 0x20 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);

extern char data_020f0fd0[];
extern char data_020f0fdc[];
extern char data_020f0fe7[];

struct Obj0207f914 {
    char pad0[0x14];
    int field0x14;
    char pad1[kResultOffset - 0x18];
    int field0x20;
    int field0x24;
    int field0x28;
};

#if defined(jpn)
extern "C" ARM void func_02080654(struct Obj0207f914* obj, int p1, int p2) {
    if (p1 != 0 && p2 != 0) {
        obj->field0x14 = p1;
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        obj->field0x20 = loader->QueueLoadFile((const char*)p2, (SafeAllocator*)0);
    }
}
#else
// USA: func_0207f914
ARM void SetFieldsFromFormattedValue0207f914(struct Obj0207f914* obj, int p1, int p2, int p3) {
    if (p1 != 0 && p2 != 0 && p3 != 0) {
        obj->field0x14 = p1;
        int field4 = (int)BackgroundLoader::GetInstance();
        char bufA[0x20];
        __clear(bufA, 0x20);
        char bufB[0x20];
        __clear(bufB, 0x20);
        char bufC[0x20];
        __clear(bufC, 0x20);
        sprintf(bufC, data_020f0fd0, p3);
        sprintf(bufB, data_020f0fdc, p3);
        sprintf(bufA, data_020f0fe7, p3);
        obj->field0x20 = ((BackgroundLoader*)(field4))->QueueLoadFileInGP2((const char*)(p2), (const char*)((int)bufC), (SafeAllocator*)(0));
        obj->field0x24 = ((BackgroundLoader*)(field4))->QueueLoadFileInGP2((const char*)(p2), (const char*)((int)bufB), (SafeAllocator*)(0));
        obj->field0x28 = ((BackgroundLoader*)(field4))->QueueLoadFileInGP2((const char*)(p2), (const char*)((int)bufA), (SafeAllocator*)(0));
    }
}

#endif
