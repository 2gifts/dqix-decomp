#include <globaldefs.h>
#if defined(jpn)
#define data_020f15d4 data_020f173c
#define data_020f15c4 data_020f172c
#endif
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

void* LoadFileIntoMemory(const char*, void*, unsigned int*);

extern char data_020f15d4[];
extern char data_0211e33c[];
extern char data_020f15c4[];

// USA: func_02099f6c
ARM void PrepareAndRunBufferedScript02099f6c(char* param0) {
    int count;
    char buf[0x430];

    memset(param0, 0, 0x150);
    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(data_020f15d4, data_0211e33c, (unsigned int*)&count);
    if (header != 0) {
        ((Script*)((struct ResetStruct*)buf))->Initialize();
        ((Script*)buf)->SetOpcodeLookup((Script::OpcodeLookupEntry*)data_020f15c4);
        ((Script*)((struct StreamState*)buf))->Load(header, count);
        ((Script*)((struct Struct02030774*)buf))->Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
}
