#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
#include <std_library_functions.h>

struct LoaderOwner0206461c {
    unsigned char padding[0x47c];
    int field_0x47c;
    unsigned char padding_0x480[0x14];
    int field_0x494;
};
struct Request0206461c {
    unsigned short id;
    unsigned char padding[3];
    char name[3];
};
struct Obj02064574;
struct StreamHeader;
extern Obj02064574 data_02108844;
extern char data_020f05dc[] __attribute__((aligned(4)));
int GetField5cb0Value(char*);
int GetField5cb4Value(char*);
extern "C" void _Z16SomeInit02064574P11Obj02064574iP12StreamHeaderiiii(Obj02064574*, int, StreamHeader*, int, int, int, int);
void* GetGlobal02109418();
extern "C" void func_02095578(void*);

static inline SafeAllocator* GetAllocator0206461c(GameResources* resources, int index) {
    return &resources->allocator_array_38[index];
}

// USA: func_0206461c
extern "C" ARM int func_0206461c(LoaderOwner0206461c* owner, Request0206461c* request) {
    GameState* state = GameState::GetInstance();
    BackgroundLoader::GetInstance();
    Obj02064574* object = &data_02108844;
    SafeAllocator* allocator = GetAllocator0206461c(func_ov017_0218b5b0(), 15);
    unsigned int size = 0;
    char name[4];
    char path[64];
    int first = GetField5cb0Value((char*)state);
    int second = GetField5cb4Value((char*)state);
    allocator->Reset();
    owner->field_0x47c = 0;
    owner->field_0x494 = 0;
    memcpy(name, request->name, 3);
    name[3] = 0;
    if (name[0] == 'F') name[1] = 0;
    BackgroundLoader::AddLockGlobal();
    sprintf(path, data_020f05dc, name);
    StreamHeader* file = (StreamHeader*)LoadFileIntoMemory(path, data_0211e33c, &size);
    if (file) _Z16SomeInit02064574P11Obj02064574iP12StreamHeaderiiii(object, (int)allocator, file, size, request->id, first, second);
    BackgroundLoader::RemoveLockGlobal();
    func_02095578(GetGlobal02109418());
    return 1;
}
