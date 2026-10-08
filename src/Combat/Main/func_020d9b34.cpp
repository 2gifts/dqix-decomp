#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

extern AllocatorUnion data_02114e20;
extern const char data_020f2810[];
extern const char data_020f2826[];

struct Struct02012dd0;
extern "C" unsigned int _Z19GetMaxAlloc02012dd0P14Struct02012dd0(Struct02012dd0* self);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
void OrBitsIntoField0(unsigned int* obj, unsigned int mask);
struct Obj020397cc;
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(struct Obj020397cc* obj, int arg1);
int GetGlobal02109400(void);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" int _Z18AlwaysTrue02094b4cv(void);
extern "C" void _Z21BlankFunction02094b40v();
extern "C" void func_02094ab0(void* obj);
extern "C" void _Z21BlankFunction02094b30v(void* a, int b, int c);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(SafeAllocator* self, void* bufferStart, unsigned int bufferSize);
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(BackgroundLoader* self, const char* gp2, const char* innerFile, SafeAllocator* alloc);
extern "C" void func_02046380(void* global);
extern "C" void func_0204500c(void* global, void* entry, int a, int b);
extern "C" void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);
struct Obj02046574;
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(struct Obj02046574* obj, int index, char* name);
struct Container020e0310;
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);

struct Obj020d9d60 {
    char pad[0x58];
    SafeAllocator allocator;
};
extern "C" void _Z22ShutdownObject020d9d60P11Obj020d9d60(struct Obj020d9d60* self);

struct Obj020d9b34 {
    unsigned char pad0[0x1];
    unsigned char field1;
    unsigned char pad1[0x8 - 0x2];
    signed char field8;
    unsigned char state;
    unsigned char pad2[0xc - 0xa];
    int taskId;
    char name[0x40 - 0x10];
    char container[0x58 - 0x40];
    SafeAllocator allocator;
};

// USA: func_020d9b34
extern "C" ARM void func_020d9b34(struct Obj020d9b34* self) {
    if (self->state == 0) {
        if (_Z19GetMaxAlloc02012dd0P14Struct02012dd0((Struct02012dd0*)&data_02114e20) < 0x400) {
            self->field1 = 1;
            return;
        }
        _Z27CancelPendingAction020397ccP11Obj020397cci((struct Obj020397cc*)GameState::GetInstance()->GetUnknownGameObject(), 1);
        OrBitsIntoField0((unsigned int*)_Z27GetDataPtr02114e04_020d6c00v(), 0xe);
        self->allocator.ResetAllocatorPointer();
        _ZN13SafeAllocator11CreateTypeAEPvj(&self->allocator, AllocateAligned4(&data_02114e20, 0x400), 0x400);
        self->allocator.Reset();
        self->taskId = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(BackgroundLoader::GetInstance(), data_020f2810, data_020f2826, NULL);
        self->state++;
    } else if (self->state == 1) {
        BackgroundLoader* bl = BackgroundLoader::GetInstance();
        if (bl->GetTaskStatus(self->taskId) == 0) return;
        if (bl->GetDetailedTaskStatus(self->taskId) != 2) {
            bl->RemoveTask(self->taskId);
            self->taskId = -1;
            _Z22ShutdownObject020d9d60P11Obj020d9d60((struct Obj020d9d60*)self);
            self->field1 = 1;
        } else {
            void* fileData;
            unsigned int size;
            bl->GetLoadedFileByID(self->taskId, &fileData, &size);
            func_020dfec0(&self->container, &self->allocator, fileData, size);
            bl->RemoveTask(self->taskId);
            self->taskId = -1;
            self->state++;
        }
    } else if (self->state == 2) {
        int g = GetGlobal02109400();
        _Z21BlankFunction02094b40v();
        func_02094ab0((void*)g);
        _Z21BlankFunction02094b30v((void*)g, 0x207, 0);
        self->state++;
    } else if (self->state == 3) {
        GetGlobal02109400();
        if (_Z18AlwaysTrue02094b4cv() == 0) return;
        void* g = (void*)_Z26GetGlobalField0x1c020421a0v();
        func_02046380(g);
        _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574*)g, 0, self->name);
        func_0204500c(g, (void*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)&self->container, self->field8), 0, 0xe3);
        *(int*)((char*)g + 0x998) = 1;
        self->state++;
    } else if (self->state == 4) {
        if (*(int*)((char*)_Z26GetGlobalField0x1c020421a0v() + 0x998) == 0) {
            _Z22ShutdownObject020d9d60P11Obj020d9d60((struct Obj020d9d60*)self);
            self->field1 = 1;
        }
    }
}