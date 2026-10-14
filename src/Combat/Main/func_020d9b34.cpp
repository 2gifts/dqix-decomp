#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
extern const char data_020f2a18[];
extern "C" void func_020728ac(int, int, void*, int, int, unsigned short, unsigned char);
struct TableA68;
void* FindEntryByKey(TableA68*, int);
extern "C" void func_0204500c(void*, void*, int);
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif

extern AllocatorUnion data_02114e20;
extern const char data_020f2810[];
extern const char data_020f2826[];

struct Struct02012dd0;
unsigned int GetMaxAlloc02012dd0(Struct02012dd0* self);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0(unsigned int* obj, unsigned int mask);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
int GetGlobalField0x1c020421a0(void);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(SafeAllocator* self, void* bufferStart, unsigned int bufferSize);
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(BackgroundLoader* self, const char* gp2, const char* innerFile, SafeAllocator* alloc);
extern "C" void func_02046380(void* global);
#if !defined(jpn)
extern "C" void func_0204500c(void* global, void* entry, int a, int b);
#endif
extern "C" void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);
struct Obj02046574;
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* name);
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);

struct Obj020d9d60 {
    char pad[REGION_VALUE(0x24, 0x58)];
    SafeAllocator allocator;
};
void ShutdownObject020d9d60(struct Obj020d9d60* self);

struct Obj020d9b34 {
    unsigned char pad0[0x1];
    unsigned char field1;
    unsigned char pad1[0x8 - 0x2];
    signed char field8;
    unsigned char state;
    unsigned char pad2[0xc - 0xa];
    int taskId;
    char name[REGION_VALUE(0x1c, 0x40) - 0x10];
    char container[REGION_VALUE(0x24 - 0x1c, 0x58 - 0x40)];
    SafeAllocator allocator;
};

// USA: func_020d9b34
extern "C" ARM void func_020d9b34(struct Obj020d9b34* self) {
    if (self->state == 0) {
        if (GetMaxAlloc02012dd0((Struct02012dd0*)&data_02114e20) < 0x400) {
            self->field1 = 1;
            return;
        }
        CancelPendingAction020397cc((struct Obj020397cc*)GameState::GetInstance()->GetUnknownGameObject(), 1);
        OrBitsIntoField0((unsigned int*)GetDataPtr02114e04_020d6c00(), 0xe);
        self->allocator.ResetAllocatorPointer();
        _ZN13SafeAllocator11CreateTypeAEPvj(&self->allocator, AllocateAligned4(&data_02114e20, 0x400), 0x400);
        self->allocator.Reset();
#if defined(jpn)
        self->taskId = BackgroundLoader::GetInstance()->QueueLoadFile(data_020f2a18, NULL);
#else
        self->taskId = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(BackgroundLoader::GetInstance(), data_020f2810, data_020f2826, NULL);
#endif
        self->state++;
    } else if (self->state == 1) {
        BackgroundLoader* bl = BackgroundLoader::GetInstance();
        if (bl->GetTaskStatus(self->taskId) == 0) return;
        if (bl->GetDetailedTaskStatus(self->taskId) != 2) {
            bl->RemoveTask(self->taskId);
            self->taskId = -1;
            ShutdownObject020d9d60((struct Obj020d9d60*)self);
            self->field1 = 1;
        } else {
            void* fileData;
            unsigned int size;
            bl->GetLoadedFileByID(self->taskId, &fileData, &size);
#if defined(jpn)
            func_020728ac((int)&self->container, (int)&self->allocator, fileData, size, 0, 0, 0);
#else
            func_020dfec0(&self->container, &self->allocator, fileData, size);
#endif
            bl->RemoveTask(self->taskId);
            self->taskId = -1;
            self->state++;
        }
    } else if (self->state == 2) {
        FontBankLoader* g = GetGlobal02109400();
        BlankFunction02094b40(g);
        func_02094ab0(g);
        BlankFunction02094b30(g, 0x207, 0);
        self->state++;
    } else if (self->state == 3) {
        if (AlwaysTrue02094b4c(GetGlobal02109400()) == 0) return;
        void* g = (void*)GetGlobalField0x1c020421a0();
        func_02046380(g);
        SetIndexedName02046574((struct Obj02046574*)g, 0, self->name);
#if defined(jpn)
        func_0204500c(g, FindEntryByKey((TableA68*)&self->container, self->field8), 0);
#else
        func_0204500c(g, (void*)GetFieldByKey020e0434((struct Container020e0310*)&self->container, self->field8), 0, 0xe3);
#endif
        *(int*)((char*)g + REGION_VALUE(0x868, 0x998)) = 1;
        self->state++;
    } else if (self->state == 4) {
        if (*(int*)((char*)GetGlobalField0x1c020421a0() + REGION_VALUE(0x868, 0x998)) == 0) {
            ShutdownObject020d9d60((struct Obj020d9d60*)self);
            self->field1 = 1;
        }
    }
}
