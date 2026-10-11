#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "std_library_functions.h"

struct HeaderStruct0209562c;
struct StreamHeader;
ARM void SetupHeaderAndRunBufferedScript0209562c(struct HeaderStruct0209562c* header, int param1,
    struct StreamHeader* buffer, int length, unsigned short param4, int param5, int param6);

extern "C" void* func_02012fe4();
int GetField5cb0Value(char* obj);
int GetField5cb4Value(char* obj);
extern int data_020f1474;
extern char data_02109418[] __attribute__((aligned(4)));

struct Holder02095578 {
    char pad[0x164 - sizeof(SafeAllocator)];
    SafeAllocator allocs[2];
    SafeAllocator* GetAt(int i) { return &allocs[i]; }
};

// USA: func_02095578
extern "C" ARM int func_02095578(void) {
    char path[0x40];
    unsigned int len;
    GameState* bs;
    void* move;
    struct HeaderStruct0209562c* header;
    GameResources* res;
    SafeAllocator* type;
    unsigned short id;
    int cb0;
    int cb4;
    void* file;

    bs = GameState::GetInstance();
    move = func_02012fe4();
    header = (struct HeaderStruct0209562c*)&data_02109418;
    res = func_ov017_0218b5b0();
    (int)BackgroundLoader::GetInstance();
    type = ((Holder02095578*)res)->GetAt(1);
    id = *(unsigned short*)move;
    cb0 = GetField5cb0Value((char*)bs);
    cb4 = GetField5cb4Value((char*)bs);
    BackgroundLoader::AddLockGlobal();
    sprintf(path, (const char*)&data_020f1474);
    file = LoadFileIntoMemory(path, data_0211e33c, &len);
    if (file != NULL) {
        SetupHeaderAndRunBufferedScript0209562c(header, (int)type, (struct StreamHeader*)file, len, id, cb0, cb4);
    }
    BackgroundLoader::RemoveLockGlobal();
    return file == NULL ? 0 : 1;
}
