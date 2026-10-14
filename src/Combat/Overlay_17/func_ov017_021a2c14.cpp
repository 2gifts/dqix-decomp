#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/FileAccessor.h"
#include "Filesystem/LowNitroHandle.h"
#include "World/Zone3D.h"
extern "C" char* strcpy(char*, const char*);
extern "C" int sprintf(char*, const char*, ...);
extern "C" char* strstr(const char*, const char*);

struct Pool020401fc;
struct Struct_0203cfb4;
struct StreamHeader;
struct EntryList_203dce4;
struct PositionHolder021a2c14 { int field0; Vector3i position; };
struct Entry021a2c14 { unsigned int flags; unsigned char padding4[0x10]; PositionHolder021a2c14* holder; Object3D* actor; };
#if defined(jpn)
enum { ZoneStateOffset = 0x58c };
#define func_0203d028 func_0203d560
#define data_ov017_021d76a6 data_ov017_021d7ae6
#define data_ov017_021d76bb data_ov017_021d7afb
#define data_ov017_021d76bf data_ov017_021d7aff
#define data_ov017_021d76c9 data_ov017_021d7b09
#define data_ov017_021d76d1 data_ov017_021d7b11
#define data_ov017_021d76d4 data_ov017_021d7b14
#else
enum { ZoneStateOffset = 0x5dc };
#endif
void* GetGlobalPtr021075f4_0203cf4c();
int GetField5cb0Value_0201079c(char*);
int GetField5cb4Value_020107d0(char*);
int GetField5cb8Value_02010804(char*);
void Init0203cfb4(Struct_0203cfb4*);
Pool020401fc* EmptyStub0203d004(void*);
void InitPool020401fc(Pool020401fc*, unsigned int, SafeAllocator*);
void* GetPtrField0x94_0203cffc(void*);
void* GetPtrField0x90_0203cff4(void*);
void ClearFirstWord0206da74(int*);
void ClearFirstWord02064e20(int*);
extern "C" void func_0206da80(void*, int, int, int, int, SafeAllocator*, const void*, int);
void InitCommandStreamSession02064e2c(int, int, int, StreamHeader*, int);
extern "C" void func_02064e88(void*, void*, SafeAllocator*);
extern "C" void func_0203d028(void*, int, SafeAllocator*, unsigned char*);
extern "C" void func_0203e2c4(void*, unsigned short);
extern "C" void* func_02012fe4();
Entry021a2c14* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4*, int);
extern "C" int func_02018fbc(void*, Vector3i*);
extern char data_ov017_021d76a6[];
extern unsigned char data_0211e33c[];
extern char data_ov017_021d76bb[];
extern char data_ov017_021d76bf[];
extern char data_ov017_021d76c9[];
extern char data_ov017_021d76d1[];
extern char data_ov017_021d76d4[];

// USA: func_ov017_021a2c14
extern "C" ARM int func_ov017_021a2c14(GameResources* object, Zone3D_StructPtr_8* request) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* context = GetGlobalPtr021075f4_0203cf4c();
    SafeAllocator* allocator = &object->allocator_array_38[7];
    unsigned char* zoneState = reinterpret_cast<unsigned char*>(object) + ZoneStateOffset;
    int id = request->unknown_0_;
    int field0 = GetField5cb0Value_0201079c((char*)game);
    int field1 = GetField5cb4Value_020107d0((char*)game);
    int field2 = GetField5cb8Value_02010804((char*)game);
    Init0203cfb4((Struct_0203cfb4*)context);
    if (loader->GetNumQueuedTasks() > 0) return 0;
    char path[0x50];
    NarcHandle archive;
    NitroVM vm;
    char resourcePath[0x50];
    char scriptPath[0x50];
    char prefix[8];
    unsigned int archiveSize;
    strcpy(prefix, request->mapShortName_);
    prefix[3] = 0;
    if (prefix[0] == 'F') prefix[1] = 0;
    BackgroundLoader::AddLockGlobal();
    sprintf(path, data_ov017_021d76a6, prefix);
    if (!LoadFileIntoMemory(path, data_0211e33c, &archiveSize)) {
        InitPool020401fc(EmptyStub0203d004(context), 12, allocator);
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
    void* resourceList = GetPtrField0x94_0203cffc(context);
    ClearFirstWord0206da74((int*)resourceList);
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
    void* scriptList = GetPtrField0x90_0203cff4(context);
    ClearFirstWord02064e20((int*)scriptList);
    scriptIndex = 0;
    while (PrepareReadFileInNARCByID(&vm, &archive, scriptIndex)) {
        NitroVM_WriteOutFilePath(&vm, scriptPath, 0x50);
        const void* data = archive.GetFileByIndex(scriptIndex);
        length = vm.fileInfo.endOffset - vm.fileInfo.startOffset;
        if (strstr(scriptPath, data_ov017_021d76c9)) {
            InitCommandStreamSession02064e2c((int)scriptList, (int)resourceList, (int)allocator, (StreamHeader*)data, length);
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
        Entry021a2c14* entry = GetEntryUnlessFlag0x8000_0203dce4((EntryList_203dce4*)context, entryIndex);
        if (!entry || (entry->flags & 0x800) || (entry->flags & 0x1000)) continue;
        if (entry->holder) {
            Vector3i holderPosition = entry->holder->position;
            holderPosition.y = func_02018fbc(zone, &holderPosition);
            entry->holder->position = holderPosition;
        } else if (entry->actor) {
            Vector3i actorPosition = entry->actor->position_;
            actorPosition.y = func_02018fbc(zone, &actorPosition);
            entry->actor->position_ = actorPosition;
        }
    }
    return 1;
}
