#include <globaldefs.h>
#if defined(jpn)
enum { kRegion2d8 = 0x228 };
enum { kRegion2dc = 0x22c };
enum { kRegion2e6 = 0x236 };
enum { kRegion2e7 = 0x237 };
enum { kRegion998 = 0x868 };
enum { kRegion160 = 0x15c };
enum { kRegion1d0 = 0x1cc };
enum { kRegion1d4 = 0x1d0 };
enum { kRegion204 = 0x200 };
enum { kRegion208 = 0x204 };
enum { kRegion20c = 0x208 };
#else
enum { kRegion2d8 = 0x2d8 };
enum { kRegion2dc = 0x2dc };
enum { kRegion2e6 = 0x2e6 };
enum { kRegion2e7 = 0x2e7 };
enum { kRegion998 = 0x998 };
enum { kRegion160 = 0x160 };
enum { kRegion1d0 = 0x1d0 };
enum { kRegion1d4 = 0x1d4 };
enum { kRegion204 = 0x204 };
enum { kRegion208 = 0x208 };
enum { kRegion20c = 0x20c };
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/Cache.h"
#include "std_library_functions.h"

extern "C" void func_ov023_021eb26c(void* obj);
struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
struct Obj0207fcb8;
void ClearAllBuffers0207fcb8(struct Obj0207fcb8* obj);
struct Cont0207fd44;
void CallFunc0204b04cOverList0x2c(struct Cont0207fd44* obj);
struct Cont0207fd88;
void CallFunc0204b088OverList0x2c(struct Cont0207fd88* obj);
struct NotifyEntriesStruct0207f8bc;
void FlushNotifyEntries(struct NotifyEntriesStruct0207f8bc* p);
extern "C" int LoadToMainBG1CharacterData(int src, int offset, unsigned int size);
void ReinitController02043204(char* obj);
extern "C" void func_02043124(void* self);

struct Controller020421a0 {
    char pad0[kRegion2d8];
    int field_0x2d8;
    char pad2dc[kRegion2e6 - kRegion2dc];
    unsigned char field_0x2e6;
    char pad2e7[kRegion998 - kRegion2e7];
    int active;
};
Controller020421a0* GetGlobalField0x1c020421a0(void);

struct Ctrl021549a8 {
    SafeAllocator* allocs;
    char pad04[0xc - 0x4];
    void* charBuf;
    char pad10[0x18 - 0x10];
    void* list;
    char pad1c[kRegion160 - 0x1c];
    char flags160[kRegion1d0 - kRegion160];
    int task;
    char pad1d4[kRegion204 - kRegion1d4];
    void* scene;
    char pad208[kRegion20c - kRegion208];
    int task2;
};

// JPN: func_ov003_02156090
// USA: func_ov003_021549a8
extern "C" ARM void func_ov003_021549a8(Ctrl021549a8* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->task >= 0) {
        loader->RemoveTask(self->task);
        self->task = -1;
    }
    if (self->task2 >= 0) {
        loader->RemoveTask(self->task2);
        self->task2 = -1;
    }
    if (self->scene != NULL) {
        func_ov023_021eb26c(self->scene);
        self->scene = NULL;
    }

    unsigned int* reg = (unsigned int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(unsigned short*)0x4000050 = 0;
    ClearFlag0x10IfSet((struct Struct02074bd0*)self->flags160);

    void* list = self->list;
    if (list != NULL) {
        ClearAllBuffers0207fcb8((struct Obj0207fcb8*)list);
        CallFunc0204b04cOverList0x2c((struct Cont0207fd44*)list);
        CallFunc0204b088OverList0x2c((struct Cont0207fd88*)list);
        FlushNotifyEntries((struct NotifyEntriesStruct0207f8bc*)list);
    }

    if (self->charBuf != NULL) {
        memset(self->charBuf, 0, 0x20);
        CleanInvalidateCacheRange(self->charBuf, 0x20);
        LoadToMainBG1CharacterData((int)self->charBuf, 0, 0x20);
    }
    self->charBuf = NULL;

    Controller020421a0* g = GetGlobalField0x1c020421a0();
    if (g->active != 0) {
        ReinitController02043204((char*)g);
        func_02043124(g);
    }
    g->field_0x2d8 = 0;
    g->field_0x2e6 = 1;

    if (self->allocs != NULL) {
        for (unsigned char i = 0; i < 8; i++) {
            self->allocs[i].Destroy();
        }
    }
}
