#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/FileAccessor.h"
#include "Filesystem/LowNitroHandle.h"
extern "C" char* strcpy(char*, const char*);
extern "C" int sprintf(char*, const char*, ...);
extern "C" char* strstr(const char*, const char*);

struct Pool020401fc;
struct Struct_0203cfb4;
struct StreamHeader;
struct EntryList_203dce4;
union Position021a2c14 { struct { int x, y, z; }; Vector3i vector; };
struct PositionHolder021a2c14 { int field0; Position021a2c14 position; };
struct Actor021a2c14 { unsigned char padding0[0x44]; Position021a2c14 position; };
struct Entry021a2c14 { unsigned int flags; unsigned char padding4[0x10]; PositionHolder021a2c14* holder; Actor021a2c14* actor; };
struct Object021a2c14 { unsigned char padding0[0xc4]; SafeAllocator allocator; unsigned char paddingD8[0x104]; unsigned char state[0x400]; unsigned char zoneState[4]; };
struct Request021a2c14 { unsigned short id; unsigned char padding2[3]; char name[1]; };
void* GetGlobalPtr021075f4();
int GetField5cb0Value(char*);
int GetField5cb4Value(char*);
int GetField5cb8Value(char*);
extern "C" void _Z12Init0203cfb4P15Struct_0203cfb4(Struct_0203cfb4*);
extern "C" void _Z17EmptyStub0203d004v();
typedef Pool020401fc* (*EmptyStubAbi021a2c14)(void*);
extern "C" void _Z16InitPool020401fcP12Pool020401fcjP13SafeAllocator(Pool020401fc*, unsigned int, SafeAllocator*);
void* GetPtrField0x94(void*);
void* GetPtrField0x90(void*);
extern "C" void _Z22ClearFirstWord0206da74Pi(int*);
extern "C" void _Z22ClearFirstWord02064e20Pi(int*);
extern "C" void func_0206da80(void*, int, int, int, int, SafeAllocator*, const void*, int);
extern "C" void _Z32InitCommandStreamSession02064e2ciiiP12StreamHeaderi(int, int, int, StreamHeader*, int);
extern "C" void func_02064e88(void*, void*, SafeAllocator*);
extern "C" void func_0203d028(void*, int, SafeAllocator*, unsigned char*);
extern "C" void func_0203e2c4(void*, unsigned short);
extern "C" void* func_02012fe4();
Entry021a2c14* GetEntryUnlessFlag0x8000(EntryList_203dce4*, int);
extern "C" int func_02018fbc(void*, Position021a2c14*);
extern char data_ov017_021d76a6[];
extern unsigned char data_0211e33c[];
extern char data_ov017_021d76bb[];
extern char data_ov017_021d76bf[];
extern char data_ov017_021d76c9[];
extern char data_ov017_021d76d1[];
extern char data_ov017_021d76d4[];

// USA: func_ov017_021a2c14
extern "C" ARM int func_ov017_021a2c14(Object021a2c14* object, Request021a2c14* request) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* context = GetGlobalPtr021075f4();
    SafeAllocator* allocator = &object->allocator;
    unsigned char* zoneState = object->zoneState;
    int id = request->id;
    int field0 = GetField5cb0Value((char*)game);
    int field1 = GetField5cb4Value((char*)game);
    int field2 = GetField5cb8Value((char*)game);
    _Z12Init0203cfb4P15Struct_0203cfb4((Struct_0203cfb4*)context);
    if (loader->GetNumQueuedTasks() > 0) return 0;
    char path[0x50];
    NarcHandle archive;
    NitroVM vm;
    char resourcePath[0x50];
    char scriptPath[0x50];
    Position021a2c14 holderPosition;
    Position021a2c14 actorPosition;
    char prefix[8];
    unsigned int archiveSize;
    strcpy(prefix, request->name);
    prefix[3] = 0;
    if (prefix[0] == 'F') prefix[1] = 0;
    BackgroundLoader::AddLockGlobal();
    sprintf(path, data_ov017_021d76a6, prefix);
    if (!LoadFileIntoMemory(path, data_0211e33c, &archiveSize)) {
        _Z16InitPool020401fcP12Pool020401fcjP13SafeAllocator(((EmptyStubAbi021a2c14)_Z17EmptyStub0203d004v)(context), 12, allocator);
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    if (!archive.Initialize(data_ov017_021d76bb, data_0211e33c)) {
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    NitroVM_Initialize(&vm);
    unsigned int resourceIndex;
    unsigned int scriptIndex;
    int length;
    void* resourceList = GetPtrField0x94(context);
    _Z22ClearFirstWord0206da74Pi((int*)resourceList);
    resourceIndex = 0;
    while (PrepareReadFileInNARCByID(&vm, &archive, resourceIndex)) {
        NitroVM_WriteOutFilePath(&vm, resourcePath, 0x50);
        const void* data = archive.GetFileByIndex(resourceIndex);
        length = vm.fileInfo.endOffset - vm.fileInfo.startOffset;
        if (strstr(resourcePath, data_ov017_021d76bf)) {
            func_0206da80(resourceList, field0, field1, field2, id, allocator, data, length);
        }
        NitroVM_FinishRead(&vm);
        ++resourceIndex;
    }
    void* scriptList = GetPtrField0x90(context);
    _Z22ClearFirstWord02064e20Pi((int*)scriptList);
    scriptIndex = 0;
    while (PrepareReadFileInNARCByID(&vm, &archive, scriptIndex)) {
        NitroVM_WriteOutFilePath(&vm, scriptPath, 0x50);
        const void* data = archive.GetFileByIndex(scriptIndex);
        length = vm.fileInfo.endOffset - vm.fileInfo.startOffset;
        if (strstr(scriptPath, data_ov017_021d76c9)) {
            _Z32InitCommandStreamSession02064e2ciiiP12StreamHeaderi((int)scriptList, (int)resourceList, (int)allocator, (StreamHeader*)data, length);
            if (strstr(scriptPath, data_ov017_021d76d1) && !strstr(scriptPath, data_ov017_021d76d4)) {
                func_02064e88(scriptList, resourceList, allocator);
            }
        }
        NitroVM_FinishRead(&vm);
        ++scriptIndex;
    }
    archive.Destroy();
    BackgroundLoader::RemoveLockGlobal();
    func_0203d028(context, 0, allocator, zoneState);
    func_0203e2c4(context, id);
    void* zone = func_02012fe4();
    for (int entryIndex = 0; entryIndex < 32; ++entryIndex) {
        Entry021a2c14* entry = GetEntryUnlessFlag0x8000((EntryList_203dce4*)context, entryIndex);
        if (!entry || (entry->flags & 0x800) || (entry->flags & 0x1000)) continue;
        if (entry->holder) {
            holderPosition = entry->holder->position;
            holderPosition.y = func_02018fbc(zone, &holderPosition);
            entry->holder->position.vector = holderPosition.vector;
        } else if (entry->actor) {
            actorPosition = entry->actor->position;
            actorPosition.y = func_02018fbc(zone, &actorPosition);
            entry->actor->position.vector = actorPosition.vector;
        }
    }
    return 1;
}
