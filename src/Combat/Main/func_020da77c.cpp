#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern const char data_020f2889[];
extern const char data_020f28a1[];
extern const char data_020f28a6[];
extern const char data_020f28ac[];
extern const char data_020f28bb[];

extern "C" int sprintf(char*, const char*, ...);

struct HandleStruct {
    int field0;
    unsigned char field4;
    char pad0[3];
    int taskId;
};

struct LoadRequest {
    int field0;
    unsigned char field4;
};

struct LoadState {
    SafeAllocator* allocator;
    char unknown04[9];
    unsigned char flags;
    unsigned char resourceKind;
};

void RunCombatFlagStateAction(void*);
HandleStruct* FindEntryWithField8Neg1(unsigned char*);
void ResetHandleFields(HandleStruct*);

// USA: func_020da77c
extern "C" ARM int func_020da77c(LoadState* state, unsigned char kind, LoadRequest* req) {
    BackgroundLoader* loader;
    HandleStruct* entry;
    SafeAllocator* allocator;
    int result;
    char path[0x80];
    loader = BackgroundLoader::GetInstance();
    if (!loader) return 0;
    if (state->flags & 1) return 0;
    if (state->resourceKind != 0) {
        RunCombatFlagStateAction(state);
    }
    allocator = state->allocator;
    if (!allocator) return 0;
    allocator->Reset();
    state->flags = 0;
    state->resourceKind = kind;
    entry = FindEntryWithField8Neg1((unsigned char*)state);
    if (!entry) return 0;
    entry->field0 = req->field0;
    entry->field4 = req->field4;
    result = -1;
    switch (state->resourceKind) {
    case 1:
        sprintf(path, data_020f2889, data_020f28a1);
        result = loader->QueueLoadGP1(path, allocator);
        break;
    case 2:
        sprintf(path, data_020f2889, data_020f28a6);
        result = loader->QueueLoadGP1(path, allocator);
        break;
    case 3:
        sprintf(path, data_020f28ac, data_020f28bb);
        result = loader->QueueLoadFile(path, allocator);
        break;
    }
    if (result == -1) {
        ResetHandleFields(entry);
        return 0;
    }
    entry->taskId = result;
    state->flags |= 1;
    return 1;
}
