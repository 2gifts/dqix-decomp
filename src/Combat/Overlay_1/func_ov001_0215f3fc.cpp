#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <Combat/WorkRecord.h>
#include <std_library_functions.h>

struct SlotArray_0203e03c;
struct SlotArray0203dd10;
struct Node020408c8;
struct TaggedValue0215f3fc
{
    int type;
    int value;
};
struct Obj0203f02c
{
    void* context;
    char pad_0x4[0x4c];
    unsigned int flags;
};
struct StreamEntry0215f3fc
{
    char pad_0x0[8];
    void* descriptor;
    Rec0206bf2c* record;
    char pad_0x10[4];
    Obj0203f02c* motion;
    char pad_0x18[8];
};
struct StreamDescriptor0215f3fc
{
    unsigned short field_0x0;
    unsigned char type;
    unsigned char pad_0x3;
    char name[16];
};
struct StreamRecord0215f3fc
{
    char data[0x70];
};
struct StreamResources0215f3fc
{
    char pad_0x0[0x2cc];
    StreamRecord0215f3fc records[33];
};
void* GetGlobalPtr021075f4();
int GetWord0x0(int*);
extern "C" const char* func_ov017_021d612c(void*);
int FindEmptySlotIndex(SlotArray_0203e03c*);
extern "C" void func_ov017_021d6134(void*, int);
unsigned int LoadResourceIntoGlobalBuffer_0215a750(const char*, void**);
extern "C" int func_ov017_021d60f4(TaggedValue0215f3fc*);
void Init020404c0(int*);
void InitializeRandomMotion0203c794(void*);
void EmptyStub0203d004();
void SetField0xc(int*, int);
void SetField0x8(int*, int);
void UpdateElementStream0203f02c(Obj0203f02c*, int, int, char*, int, int);
extern "C" void func_0203f138(Obj0203f02c*, int);
void SetActiveChildShorts020408c8(Node020408c8*, short, short, short);
void SetSlotIfIndexBelow32(SlotArray0203dd10*, unsigned int, int);
extern const char data_ov001_021657ad[];
extern const char data_ov001_021657b2[];
extern const char data_ov001_021657be[];
extern SafeAllocator* data_ov001_021658b8[];
extern const char data_ov001_021657ce[];
extern const char data_ov001_021657d1[];

// USA: func_ov001_0215f3fc
extern "C" ARM int func_ov001_0215f3fc(TaggedValue0215f3fc* arguments, int count)
{
    GameState* game = GameState::GetInstance();
    void* list = GetGlobalPtr021075f4();
    StreamResources0215f3fc* resources = (StreamResources0215f3fc*)GetWord0x0((int*)game);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!resources)
    {
        return 0;
    }
    const char* name = func_ov017_021d612c(arguments++);
    int slot = FindEmptySlotIndex((SlotArray_0203e03c*)list);
    if (slot == -1)
    {
        return 0;
    }
    func_ov017_021d6134(arguments++, slot);
    if (slot >= 32)
    {
        return 0;
    }
    char filename[80];
    if (strstr(name, data_ov001_021657ad))
    {
        sprintf(filename, data_ov001_021657b2, name);
    }
    else
    {
        sprintf(filename, data_ov001_021657be, name);
    }
    void* file;
    unsigned int length;
    int locked = 0;
    loader->GetLoadedFileByName(filename, &file, &length);
    if (!file)
    {
        BackgroundLoader::AddLockGlobal();
        locked = 1;
        if (!LoadResourceIntoGlobalBuffer_0215a750(filename, &file))
        {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }
    int allocatorIndex = 0;
    if (count >= 3)
    {
        allocatorIndex = func_ov017_021d60f4(arguments++);
    }
    SafeAllocator* allocator = data_ov001_021658b8[allocatorIndex];
    int recordIndex = 27;
    if (count >= 4)
    {
        recordIndex = func_ov017_021d60f4(arguments);
    }
    StreamEntry0215f3fc* entry = (StreamEntry0215f3fc*)allocator->Allocate(0x20);
    if (!entry)
    {
        if (locked)
        {
            BackgroundLoader::RemoveLockGlobal();
        }
        return 0;
    }
    Init020404c0((int*)entry);
    Rec0206bf2c* record = (Rec0206bf2c*)allocator->Allocate(0x78);
    if (!record)
    {
        if (locked)
        {
            BackgroundLoader::RemoveLockGlobal();
        }
        return 0;
    }
    ClearWorkRecord0206bf2c(record);
    StreamDescriptor0215f3fc* descriptor = (StreamDescriptor0215f3fc*)allocator->Allocate(0x14);
    if (!descriptor)
    {
        if (locked)
        {
            BackgroundLoader::RemoveLockGlobal();
        }
        return 0;
    }
    memset(descriptor, 0, 0x14);
    entry->motion = (Obj0203f02c*)allocator->Allocate(0x9c);
    if (!entry->motion)
    {
        if (locked)
        {
            BackgroundLoader::RemoveLockGlobal();
        }
        return 0;
    }
    InitializeRandomMotion0203c794(entry->motion);
    typedef void* (*ContextStub0215f3fc)(void*);
    void* context = ((ContextStub0215f3fc)EmptyStub0203d004)(list);
    if (entry->motion)
    {
        entry->motion->context = context;
    }
    descriptor->type = 3;
    if (strstr(name, data_ov001_021657ad))
    {
        int nameLength = 5;
        if (strstr(name, data_ov001_021657ce))
        {
            nameLength = 7;
            entry->motion->flags |= 8;
        }
        memcpy(descriptor->name, name, nameLength);
        descriptor->name[nameLength] = 0;
    }
    else
    {
        sprintf(descriptor->name, data_ov001_021657d1, name);
    }
    SetField0xc((int*)entry, (int)record);
    SetField0x8((int*)entry, (int)descriptor);
    StreamRecord0215f3fc* recordBase = resources->records;
    char* recordData = recordBase[recordIndex].data;
    unsigned int loadedLength = length;
    void* loadedFile = file;
    if (entry->motion)
    {
        UpdateElementStream0203f02c(entry->motion, (int)(filename + 9), (int)allocator,
            recordData, (int)loadedFile, loadedLength);
    }
    if (entry->motion)
    {
        func_0203f138(entry->motion, 1);
    }
    if (locked)
    {
        BackgroundLoader::RemoveLockGlobal();
    }
    SetActiveChildShorts020408c8((Node020408c8*)entry, 0x8f, 0x8f, 0x8f);
    SetSlotIfIndexBelow32((SlotArray0203dd10*)list, slot, (int)entry);
    return 1;
}
