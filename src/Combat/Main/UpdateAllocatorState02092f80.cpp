#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"



struct List0202fec8;

extern "C" {
    void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);
}

#if defined(jpn)
extern int data_020f143c;
#endif
extern int data_020f1368;
extern int data_020f1382;

struct Obj02092f80 {
    unsigned char pad0[0x2c];
    int field_2c;
    unsigned char pad2c[0x34 - 0x30];
    unsigned char field_34;
    unsigned char field_35;
    unsigned char field_36;
    unsigned char field_37;
};

#if defined(jpn)
#define UpdateAllocatorState02092f80 func_020938bc
extern "C" ARM void func_020938bc(Obj02092f80* obj);
#endif

// USA: func_02092f80
ARM void UpdateAllocatorState02092f80(Obj02092f80* obj) {
    int ctx = (int)BackgroundLoader::GetInstance();
    unsigned char state = obj->field_35;

    if (state == 0) {
#if defined(jpn)
        obj->field_2c = ((BackgroundLoader*)(ctx))->QueueLoadFile((const char*)((int)&data_020f143c), (SafeAllocator*)(0));
#else
        obj->field_2c = ((BackgroundLoader*)(ctx))->QueueLoadFileInGP2((const char*)((int)&data_020f1368), (const char*)((int)&data_020f1382), (SafeAllocator*)(0));
#endif
        obj->field_35++;
    } else if (state == 1) {
        if (((BackgroundLoader*)(ctx))->GetTaskStatus((int)(obj->field_2c))) {
            int out1, out2;
            ((BackgroundLoader*)((struct List0202fec8*)ctx))->GetLoadedFileByID((int)(obj->field_2c), (void**)(&out1), (unsigned int*)(&out2));
            ((SafeAllocator*)obj)->Reset();
            func_020dfec0((char*)obj + 0x14, obj, (void*)out1, (unsigned int)out2);
            ((BackgroundLoader*)(ctx))->RemoveTask((int)(obj->field_2c));
            obj->field_2c = -1;
            obj->field_35++;
        }
    } else if (state == 2) {
        obj->field_34 = 3;
        obj->field_35 = 0;
        if (obj->field_37 & 0x1) obj->field_34 = 1;
        if (!(obj->field_37 & 0x8)) obj->field_37 |= 0x4;
        obj->field_36 = 0;
    }
}
