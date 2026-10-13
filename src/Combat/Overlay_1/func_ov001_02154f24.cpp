#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <GameState/GameState.h>
#include <Resource/Brightness.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/AllocatorUnion.h>
#include <Memory/HMRFAllocator.h>
#include <std_library_functions.h>

struct Struct_0203cf58;
struct TagValueEntry020e385c;
struct LoadState02154f24
{
    char pad_0x0[8];
    unsigned short lookupId;
    unsigned short state;
    char pad_0xc[7];
    unsigned char pathVariant;
    char pad_0x14[4];
    unsigned short tag;
    char pad_0x1a[0x3e - 0x1a];
    char name[0x50 - 0x3e];
    unsigned short flags;
    char pad_0x52[0x74 - 0x52];
    int firstLoad;
    int secondLoad;
    SafeAllocator allocator;
    unsigned int savedSize;
    char pad_0x94[8];
    unsigned char alternatePath;
    char pad_0x9d[0x110 - 0x9d];
    int optionalLoad;
};
struct LoadArguments02154f24
{
    unsigned short slot;
};
struct LookupRecord02154f24
{
    char pad_0x0[8];
    unsigned int index;
    char pad_0xc[0x34 - 0xc];
};
void* GetGlobalPtr021075f4();
extern "C" LoadArguments02154f24* func_02012fe4();
extern "C" void* func_0202ae18();
unsigned int GetBitsInField0(unsigned int*, unsigned int);
void EmptyStub02012de4(AllocatorUnion*);
extern "C" void func_020a0cc4(int);
extern "C" void func_0203e0a0(void*, int);
extern "C" void func_ov017_021a316c(GameResources*);
void InitWithExtendedRegion0203cf58(Struct_0203cf58*);
void TailForward02012da4(AllocatorUnion*, void*);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
extern "C" void __clear(void*, unsigned int);
extern "C" void* func_0205ec34();
int LookupAndForEachNode020649b0(void*, int, void*);
extern "C" void func_0206f81c(void*);
TagValueEntry020e385c* GetData02153660();
void* FindEntryByTagAndValue(TagValueEntry020e385c*, int, int);
extern "C" int func_0202c508(void*);
void ResetTaggedEntryAndNotifyOverlay020e3994(TagValueEntry020e385c*, int, int);
void RegisterTaggedEntryAndNotifyOverlay020e392c(TagValueEntry020e385c*, int, int);
int GetField0x3acValue(GameState*);
void SetEntryBitUnlessMatching020e39d4(TagValueEntry020e385c*, int, int, int);
extern AllocatorUnion data_02114e20;
extern const char data_ov001_02164bef[];
extern const char data_ov001_02164c01[];
extern const char data_ov001_02164c13[];
extern const char data_ov001_02164c21[];
extern const char data_ov001_02164c26[];
extern const char data_ov001_02164c2d[];
extern const char data_ov001_02164c39[];

static inline SafeAllocator* GetAllocator02154f24(GameResources* resources, int index)
{
    return &resources->allocator_array_38[index];
}

// USA: func_ov001_02154f24
extern "C" ARM int func_ov001_02154f24(LoadState02154f24* self)
{
    GameState* game = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* list = GetGlobalPtr021075f4();
    LoadArguments02154f24* arguments = func_02012fe4();
    void* other = func_0202ae18();
    if (!GetBitsInField0((unsigned int*)resources, 0x1000))
    {
        if (!AlwaysTrue02094b4c(GetGlobal02109400()))
        {
            return self->state;
        }
    }
    if (IsBrightnessTransitionActive(resources))
    {
        return self->state;
    }
    EmptyStub02012de4(&data_02114e20);
    func_020a0cc4(0x40400);
    EmptyStub02012de4(&data_02114e20);
    if ((self->flags & 1) && !GetBitsInField0((unsigned int*)resources, 0x1000))
    {
        func_0203e0a0(list, arguments->slot);
        func_ov017_021a316c(resources);
        InitWithExtendedRegion0203cf58((Struct_0203cf58*)GetGlobalPtr021075f4());
        SafeAllocator* previousAllocator = GetAllocator02154f24(resources, 7);
        self->savedSize = previousAllocator->GetSize();
        void* oldAllocator = previousAllocator->GetSignedAllocator();
        previousAllocator->Destroy();
        TailForward02012da4(&data_02114e20, oldAllocator);
    }
    else if (self->flags & 4)
    {
        func_0203e0a0(list, arguments->slot);
        func_ov017_021a316c(resources);
        InitWithExtendedRegion0203cf58((Struct_0203cf58*)GetGlobalPtr021075f4());
        resources->allocator_array_38[7].Reset();
    }
    unsigned int size = 0x40400;
    if (self->flags & 8)
    {
        size -= 0xa000;
    }
    if (self->flags & 1)
    {
        size += self->savedSize;
    }
    if (!GetBitsInField0((unsigned int*)resources, 0x1000))
    {
        void* memory = AllocateAligned4(&data_02114e20, size);
        self->allocator.CreateTypeA(memory, size);
        self->allocator.Reset();
    }
    else
    {
        ((HMRFAllocator*)self->allocator.pSignedAlloc)->Free(1);
    }
    EmptyStub02012de4(&data_02114e20);
    char filename[80];
    if (self->alternatePath)
    {
        sprintf(filename, data_ov001_02164bef, self->name);
    }
    else if (self->pathVariant)
    {
        sprintf(filename, data_ov001_02164c01, self->name);
    }
    else
    {
        sprintf(filename, data_ov001_02164c13, self->name);
    }
    int length = strlen(filename) - 4;
    memcpy(filename + length, data_ov001_02164c21, 4);
    char basename[16];
    __clear(basename, 16);
    memcpy(basename, self->name, strlen(self->name) - 4);
    char firstFile[16];
    sprintf(firstFile, data_ov001_02164c26, basename);
    char secondFile[32];
    sprintf(secondFile, data_ov001_02164c2d, basename);
    loader->AddFence();
    self->firstLoad = loader->QueueLoadFileInGP2(filename, firstFile, &self->allocator);
    self->secondLoad = loader->QueueLoadFileInGP2(filename, secondFile, &self->allocator);
    if (self->flags & 0x200)
    {
        self->optionalLoad = loader->QueueLoadFile(data_ov001_02164c39, &self->allocator);
    }
    void* context = func_0205ec34();
    LookupRecord02154f24 record;
    record.index = self->lookupId;
    if (LookupAndForEachNode020649b0(context, 10, &record))
    {
        func_0206f81c(&record);
    }
    TagValueEntry020e385c* table = GetData02153660();
    void* found = FindEntryByTagAndValue(table, 1, 0x71e8);
    if (func_0202c508(other) && !found && !FindEntryByTagAndValue(table, 1, self->tag))
    {
        ResetTaggedEntryAndNotifyOverlay020e3994(table, 1, -1);
        RegisterTaggedEntryAndNotifyOverlay020e392c(table, 1, self->tag);
    }
    SetEntryBitUnlessMatching020e39d4(table, GetField0x3acValue(game), 1, self->tag);
    return 2;
}
