#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(unsigned char* context, unsigned int key);
struct S020a13c4;
void ClearStruct020a13c4(S020a13c4* table);
struct StreamHeader;
void SetupGlobalAndRunScript020a147c(void*, void*, StreamHeader*, int, int, unsigned short, unsigned char);
int LoadBattleBlock020ac460(void* destination);
extern "C" void __clear(void* destination, int length);
struct Array020a15bc;
struct Elem020a15bc;
Elem020a15bc* FindElementByField020a15bc(Array020a15bc* table, int id);

extern void* data_ov004_021707c8;
#if defined(jpn)
extern char data_ov004_02170c94[];
#else
extern char data_ov004_0217039a[];
extern char data_ov004_021703af[];
#endif

// USA: func_ov004_021567f8
// KEEP-NAME
extern "C" ARM int func_ov004_021567f8(void* context) {
    char* base = (char*)func_ov011_021845f8((unsigned char*)context, 4);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    SafeAllocator* allocator = (SafeAllocator*)(base + 4);
#if defined(jpn)
    *(void**)((char*)&data_ov004_021707c8 + 8) = allocator->Allocate(0x14);
    BackgroundLoader::AddLockGlobal();
    unsigned int length = 0;
    void* file = LoadFileIntoMemory(data_ov004_02170c94, data_0211e33c, &length);
#else
    *(void**)((char*)&data_ov004_021707c8 + 12) = allocator->Allocate(0x14);
    int task = loader->QueueLoadFileInGP2(data_ov004_0217039a, data_ov004_021703af, 0);
    if (task < 0) return 0;
    while (!loader->GetTaskStatus(task)) {
        loader->RemoveAllLocks();
    }
    if (loader->GetDetailedTaskStatus(task) != 2) {
        loader->RemoveTask(task);
        return 0;
    }
    void* file;
    unsigned int length;
    loader->GetLoadedFileByID(task, &file, &length);
#endif
    if (file != 0) {
#if defined(jpn)
        ClearStruct020a13c4(*(S020a13c4**)((char*)&data_ov004_021707c8 + 8));
        SetupGlobalAndRunScript020a147c(*(void**)((char*)&data_ov004_021707c8 + 8), allocator, (StreamHeader*)file, length, 0, 0, 0xf);
#else
        ClearStruct020a13c4(*(S020a13c4**)((char*)&data_ov004_021707c8 + 12));
        SetupGlobalAndRunScript020a147c(*(void**)((char*)&data_ov004_021707c8 + 12), allocator, (StreamHeader*)file, length, 0, 0, 0xf);
#endif
    }
#if defined(jpn)
    BackgroundLoader::RemoveLockGlobal();
#else
    loader->RemoveTask(task);
#endif
    if (file == 0) return 0;

#if defined(jpn)
    short* titleIds = (short*)allocator->Allocate(0x3c0);
    *(short**)((char*)&data_ov004_021707c8 + 4) = titleIds;
    memset(titleIds, 0, 0x3c0);
#else
    short* titleIds = (short*)allocator->Allocate(0x3c0);
    *(short**)((char*)&data_ov004_021707c8 + 8) = titleIds;
    memset(titleIds, 0, 0x3c0);
#endif
    unsigned int titleFlags[15];
    __clear(titleFlags, sizeof(titleFlags));
    LoadBattleBlock020ac460(titleFlags);

    int index, id, count;
    for (count = 0, index = 0; index < 0x1e0; index++) {
        id = index + 1;
#if defined(jpn)
        Array020a15bc* table = *(Array020a15bc**)((char*)&data_ov004_021707c8 + 8);
#else
        Array020a15bc* table = *(Array020a15bc**)((char*)&data_ov004_021707c8 + 12);
#endif
        if (FindElementByField020a15bc(table, (short)id)) {
            int word = id / 32;
            int bit = id % 32;
            if (titleFlags[word] & (1u << bit)) {
#if defined(jpn)
                (*(short**)((char*)&data_ov004_021707c8 + 4))[count] = id;
#else
                (*(short**)((char*)&data_ov004_021707c8 + 8))[count] = id;
#endif
                count++;
            }
        }
    }
#if defined(jpn)
    data_ov004_021707c8 = allocator->Allocate(0x3c0);
    memset(data_ov004_021707c8, 0, 0x3c0);
#else
    short* scratchIds = (short*)allocator->Allocate(0x3c0);
    *(short**)((char*)&data_ov004_021707c8 + 4) = scratchIds;
    memset(scratchIds, 0, 0x3c0);
    data_ov004_021707c8 = allocator->Allocate(0x1000);
    memset(data_ov004_021707c8, 0, 0x1000);
#endif
    return 0;
}
