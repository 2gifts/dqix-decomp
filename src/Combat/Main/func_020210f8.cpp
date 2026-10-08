#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct State0xbb1c;
struct Obj0203bb3c;

void ClearFields0x8(State0xbb1c *state);
void SetupAndDispatchCharTransfer0203bb3c(Obj0203bb3c *state, char *source, SafeAllocator *allocator, int category,
                                          unsigned short flags);

struct Entry02021578 {
    int field0;
    char *name;
    char pad8[0x1c];
};

struct CharacterTransferReceiverPrefix {
    char unknown0[0x20];
    Entry02021578 *entries;
    int entryCount;
    char unknown28[0x48];
    int unknown70;
    int unknown74;
};

// USA: func_020210f8
extern "C" ARM void func_020210f8(char *receiver, int *handles, SafeAllocator *allocator) {
    if (handles == NULL) return;

    CharacterTransferReceiverPrefix *state = reinterpret_cast<CharacterTransferReceiverPrefix *>(receiver);
    BackgroundLoader *loader               = BackgroundLoader::GetInstance();
    void *fileData                         = NULL;
    unsigned int fileLength                = 0;
    state->unknown70                       = state->unknown74 + 1;

    for (int index = 0; index < state->entryCount; index++) {
        loader->GetLoadedFileByID(handles[index], &fileData, &fileLength);
        ClearFields0x8(reinterpret_cast<State0xbb1c *>(state->entries[index].pad8));
        SetupAndDispatchCharTransfer0203bb3c(reinterpret_cast<Obj0203bb3c *>(state->entries[index].pad8),
                                             static_cast<char *>(fileData), allocator, 1, 0);
        BackgroundLoader::GetInstance()->RemoveTask(handles[index]);
        handles[index] = -1;
    }
}
