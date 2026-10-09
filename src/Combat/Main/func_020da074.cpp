#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/HPXEAllocator.h"
#include "Filesystem/BackgroundLoader.h"
struct SlotManager020da034 { char unknown0[8]; unsigned short usedMask; char unknowna[2]; int slots[1]; int scriptId; };
struct Struct02012dd0 { void* field0; HPXEAllocator* alloc; };
int* GetGlobal02109418();
extern "C" unsigned int _Z19GetMaxAlloc02012dd0P14Struct02012dd0(Struct02012dd0*);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion*, void*);
extern "C" void _Z19ReleaseSlot020da034P19SlotManager020da034i(SlotManager020da034*, int);
extern "C" void func_0209576c(int*, SafeAllocator*, void*, unsigned int, int);
extern "C" void func_02095d30(int*, int, int);
extern AllocatorUnion data_02114e20;

// USA: func_020da074
extern "C" ARM void func_020da074(SlotManager020da034* manager) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int* interpreter = GetGlobal02109418();
    void* data;
    unsigned int length;
    loader->GetLoadedFileByID(manager->slots[0], &data, &length);
    if (_Z19GetMaxAlloc02012dd0P14Struct02012dd0((Struct02012dd0*)&data_02114e20) > 0x400) {
        SafeAllocator allocator;
        allocator.ResetAllocatorPointer();
        allocator.ResetAllocatorPointer();
        void* buffer = AllocateAligned4(&data_02114e20, 0x400);
        allocator.CreateTypeA(buffer, 0x400);
        allocator.Reset();
        func_0209576c(interpreter, &allocator, data, length, 0);
        func_02095d30(interpreter, manager->scriptId, 0);
        SignedAllocatorHeader* memory = allocator.GetSignedAllocator();
        if (memory) {
            allocator.Destroy();
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, memory);
        }
    }
    _Z19ReleaseSlot020da034P19SlotManager020da034i(manager, 0);
}
