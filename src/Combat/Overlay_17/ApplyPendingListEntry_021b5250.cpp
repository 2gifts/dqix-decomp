#include <globaldefs.h>

#if defined(jpn)
enum { kHalfwordArrayOffset = 0x40, kPendingEntryOffset = 0x2f4 };
#else
enum { kHalfwordArrayOffset = 0x44, kPendingEntryOffset = 0x2f8 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void __clear(void* buf, int size);
struct HalfwordArray {
    unsigned short arr[12];
    unsigned short count;
};
ARM unsigned short CopyHalfwordArrayByCount(struct HalfwordArray* src, struct HalfwordArray* dst);
void* Clear12Bytes0206efc4(void* obj);
struct Src0206f170;
#if defined(jpn)
extern "C" void func_0206f230(void* entries, SafeAllocator* allocator, Src0206f170* source, int length, short* keys, int keyCount);
#else
extern "C" void func_0206f230(void* entries, SafeAllocator* allocator, Src0206f170* source, int length, short* keys, int keyCount, SafeAllocator* stringAllocator, unsigned char* keySizes);
#endif

extern char data_ov017_021d7bc3;

struct LoadedEntryResources {
    char unknown0[0x10];
    SafeAllocator* allocator;
    SafeAllocator* stringAllocator;
    char unknown18[kHalfwordArrayOffset - 0x18];
    HalfwordArray keys;
    char unknownAfterKeys[kPendingEntryOffset - kHalfwordArrayOffset - sizeof(HalfwordArray)];
    char entries[12];
};

struct EntryLoadRequest {
    char unknown0[8];
    LoadedEntryResources* resources;
    int taskId;
    unsigned char state;
    char unknown11[3];
    unsigned char* keySizes;
};

// USA: func_ov017_021b5250  (semantic: ApplyPendingListEntry_021b5250)
extern "C" ARM void func_ov017_021b5250(EntryLoadRequest* request) {
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(request->taskId)) {
        return;
    }

    if (loader->GetDetailedTaskStatus(request->taskId) == BackgroundLoader::TaskStatus_Complete) {
        unsigned int fileLength;
        void* fileData;
        loader->GetLoadedFileByID(request->taskId, &fileData, &fileLength);
        if (fileData != NULL) {
            LoadedEntryResources* resources = request->resources;
            unsigned short keys[12];
            __clear(keys, sizeof(keys));
            short keyCount = (short)CopyHalfwordArrayByCount(&resources->keys, (HalfwordArray*)keys);
            char* pending = request->resources->entries;
            Clear12Bytes0206efc4(pending);
            LoadedEntryResources* currentResources = request->resources;
            func_0206f230(pending, currentResources->allocator, (Src0206f170*)fileData, fileLength, (short*)keys, keyCount
#if !defined(jpn)
                , currentResources->stringAllocator, request->keySizes
#endif
            );
        }
    }

    loader->RemoveTask(request->taskId);
    request->taskId = -1;
    request->taskId = loader->QueueLoadFile(&data_ov017_021d7bc3, NULL);
    request->state = 7;
}
