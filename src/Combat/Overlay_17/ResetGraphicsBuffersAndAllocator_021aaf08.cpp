#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "std_library_functions.h"

struct NotifyEntriesStruct0207f8bc;
void FlushNotifyEntries(struct NotifyEntriesStruct0207f8bc* p);
extern "C" int func_ov017_0218b5b0(void);
void* GetDataPtr02114e04_020d6c00(void);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToMainBG2CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" void LoadToMainBG1ScreenData(void* p, int a, int b);
extern "C" int LoadToMainBG2ScreenData(int arg0, int arg1, unsigned int arg2);

extern int data_02114e20;

// USA: func_ov017_021aaf08  (semantic: ResetGraphicsBuffersAndAllocator_021aaf08)
extern "C" ARM void func_ov017_021aaf08(char* self) {
    int listPtr = (int)BackgroundLoader::GetInstance();
    if (*(int*)(self + 0x50) >= 0) {
        ((BackgroundLoader*)(listPtr))->RemoveTask((int)(*(int*)(self + 0x50)));
        *(int*)(self + 0x50) = -1;
    }

    if (*(void**)(self + 0x18) != 0) {
        FlushNotifyEntries(*(struct NotifyEntriesStruct0207f8bc**)(self + 0x18));
        *(void**)(self + 0x18) = 0;
    }

    int h = func_ov017_0218b5b0();
    void* d = GetDataPtr02114e04_020d6c00();
    ClearBitsInField4((unsigned int*)h, 0x80);
    ClearFlags020466f4((struct FlagWord020466f4*)d, 0x200);

    SafeAllocator* allocator = (SafeAllocator*)(self + 0x24);
    void* p = allocator->GetSignedAllocator();
    allocator->Destroy();
    if (p) {
        TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
    }

    int buf = *(int*)(self + 0x8);
    if (buf != 0) {
        memset((void*)buf, 0, 0x800);
        CleanInvalidateCacheRange(*(void**)(self + 0x8), 0x800);
        LoadToMainBG1CharacterData(*(int*)(self + 0x8), 0, 0x20);
        LoadToMainBG2CharacterData(*(int*)(self + 0x8), 0, 0x20);
        LoadToMainBG1ScreenData(*(void**)(self + 0x8), 0, 0x800);
        LoadToMainBG2ScreenData(*(int*)(self + 0x8), 0, 0x800);
        *(int*)(self + 0x8) = 0;
    }
    *(int*)(self + 0x64) = 0;
}
