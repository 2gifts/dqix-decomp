#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/Memory.h"
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

struct Stream0200fd14 {
    char *ptr;
};
void ReadStreamBlock0200fd14(Stream0200fd14 *stream, void *dst, unsigned int length);
extern "C" void *__clear(void *dst, int count);

struct Node020211b0 {
    unsigned char type;
    unsigned char id;
    unsigned char count;
    unsigned char pad3;
    short *data;
    int x;
    int y;
    Node020211b0 *next;
};

struct Entry020211b0 {
    unsigned short key1;
    unsigned char key2;
    unsigned char pad3;
    short val1;
    short val2;
};

struct Table020211b0 {
#if defined(jpn)
    char pad0[0x9d4];
#else
    char pad0[0xaa0];
#endif
    unsigned short count;
    Entry020211b0 entries[32];
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

// USA: func_020211b0
#if defined(jpn)
typedef int CompletedLoadTask;
#else
typedef int *CompletedLoadTask;
#endif
extern "C" ARM void func_020211b0(char *receiver, CompletedLoadTask taskID) {
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    Stream0200fd14 stream;
    stream.ptr              = 0;
    unsigned int fileLength = 0;
#if defined(jpn)
    loader->GetLoadedFileByID(taskID, (void **) &stream.ptr, &fileLength);
#else
    loader->GetLoadedFileByID(*taskID, (void **) &stream.ptr, &fileLength);
#endif

    unsigned short keys[16];
    unsigned char keyCount = 0;
    __clear(keys, sizeof(keys));
#if defined(jpn)
    enum { kNodeListOffset = 0x6a8 };
#else
    enum { kNodeListOffset = 0x754 };
#endif
    for (Node020211b0 *node = *(Node020211b0 **) (receiver + kNodeListOffset); node; node = node->next) {
        for (int i = 0; i < node->count; i++) {
            unsigned short key = node->data[i];
            if (key >= 20000 && key <= 29999) {
                keys[keyCount++] = key;
            }
        }
    }

    if (stream.ptr) {
        ((Table020211b0 *) receiver)->count = 0;
        VectorizedMemset(((Table020211b0 *) receiver)->entries, 0, 0x100);
        unsigned short recordCount = 0;
        ReadStreamBlock0200fd14(&stream, &recordCount, 2);
        for (int i = 0; i < recordCount; i++) {
            unsigned short key1;
            unsigned char key2;
            short val1;
            short val2;
            ReadStreamBlock0200fd14(&stream, &key1, 2);
            ReadStreamBlock0200fd14(&stream, &key2, 1);
            ReadStreamBlock0200fd14(&stream, &val1, 2);
            ReadStreamBlock0200fd14(&stream, &val2, 2);
            int found = 0;
            for (int j = 0; j < keyCount && !found; j++) {
                if (key1 == keys[j]) found = 1;
            }
            if (found) {
                Entry020211b0 *entry = &((Table020211b0 *) receiver)->entries[((Table020211b0 *) receiver)->count++];
                entry->key1          = key1;
                entry->key2          = key2;
                entry->val1          = val1;
                entry->val2          = val2;
            }
        }
    }

#if defined(jpn)
    BackgroundLoader::GetInstance()->RemoveTask(taskID);
#else
    BackgroundLoader::GetInstance()->RemoveTask(*taskID);
    *taskID = -1;
#endif
}
