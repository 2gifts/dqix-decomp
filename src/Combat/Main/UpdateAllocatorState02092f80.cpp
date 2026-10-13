#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"



struct Container020dffc8 {
    unsigned int count : 12;
    unsigned int stringBytes : 19;
    unsigned int ownsStorage : 1;
    void* elements;
    void* strings;
};

extern "C" int func_020dfec0(Container020dffc8* dest, SafeAllocator* allocator, void* fileData, unsigned int size);

#if defined(jpn)
extern const char data_020f143c[];
#endif
extern const char data_020f1368[];
extern const char data_020f1382[];

struct Obj02092f80 {
    SafeAllocator allocator;
    Container020dffc8 container;
    unsigned char unknown20[0xc];
    int taskId;
    unsigned char pad2c[0x34 - 0x30];
    unsigned char field_34;
    unsigned char field_35;
    unsigned char field_36;
    unsigned char field_37;
};

// USA: func_02092f80
ARM void UpdateAllocatorState02092f80(Obj02092f80* obj) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned char state = obj->field_35;

    if (state == 0) {
#if defined(jpn)
        obj->taskId = loader->QueueLoadFile(data_020f143c, NULL);
#else
        obj->taskId = loader->QueueLoadFileInGP2(data_020f1368, data_020f1382, NULL);
#endif
        obj->field_35++;
    } else if (state == 1) {
        if (loader->GetTaskStatus(obj->taskId)) {
            void* fileData;
            unsigned int fileSize;
            loader->GetLoadedFileByID(obj->taskId, &fileData, &fileSize);
            obj->allocator.Reset();
            func_020dfec0(&obj->container, &obj->allocator, fileData, fileSize);
            loader->RemoveTask(obj->taskId);
            obj->taskId = -1;
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
