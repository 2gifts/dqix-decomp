#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "System/Memory.h"

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
char* FindEntryAndGetNext(void* a, char* b, unsigned int* outSize);
int GetCharBlock(void* file, void** out);
struct Hdr02b0288;
int FindPlttChunkAndRelocate(struct Hdr02b0288* h, void** out);
extern "C" void func_020c9be0(void);

extern AllocatorUnion data_02114e20;
extern unsigned char data_0211e33c[0x30000];
extern const char data_020f290c;
extern const char data_020f2925;
extern const char data_020f2936;

struct CharBlockData020db0f0 {
    char pad[0x10];
    unsigned int size;
    void* data;
};

struct PlttChunkData020db0f0 {
    char pad[0xc];
    void* data;
};

struct Manager020db0f0 {
    SafeAllocator allocator;
    char pad[0x40 - sizeof(SafeAllocator)];
    void* charBuf;
    unsigned int charBufSize;
    void* plttBuf;
    unsigned int plttBufSize;
};

// USA: func_020db0f0
ARM void LoadObjLoadingGraphicsResources(Manager020db0f0* mgr) {
    unsigned int fileLength;
    unsigned int characterFileLength;
    unsigned int paletteFileLength;
    char* ncgrEntry;
    Hdr02b0288* nclrEntry;
    CharBlockData020db0f0* charBlock;
    PlttChunkData020db0f0* plttChunk;
    void* buf;

    mgr->allocator.CreateTypeA(AllocateAligned4(&data_02114e20, 0x300), 0x300);
    mgr->allocator.Reset();
    BackgroundLoader::AddLockGlobal();

    buf = data_0211e33c;

    fileLength = 0;
    LoadFileIntoMemory(&data_020f290c, buf, &fileLength);

    characterFileLength = 0;
    paletteFileLength = 0;
    ncgrEntry = FindEntryAndGetNext(buf, (char*)&data_020f2925, &characterFileLength);
    nclrEntry = (Hdr02b0288*)FindEntryAndGetNext(buf, (char*)&data_020f2936, &paletteFileLength);

    charBlock = NULL;
    if (!GetCharBlock(ncgrEntry, (void**)&charBlock)) {
        func_020c9be0();
    }

    mgr->charBufSize = charBlock->size;
    mgr->charBuf = mgr->allocator.Allocate(mgr->charBufSize);
    VectorizedInvertedMemcpy(charBlock->data, mgr->charBuf, mgr->charBufSize);

    plttChunk = NULL;
    if (!FindPlttChunkAndRelocate(nclrEntry, (void**)&plttChunk)) {
        func_020c9be0();
    }

    mgr->plttBufSize = 0x20;
    mgr->plttBuf = mgr->allocator.Allocate(mgr->plttBufSize);
    VectorizedInvertedMemcpy(plttChunk->data, mgr->plttBuf, mgr->plttBufSize);

    BackgroundLoader::RemoveLockGlobal();
}
