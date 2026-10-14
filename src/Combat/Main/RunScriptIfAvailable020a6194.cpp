#include <globaldefs.h>
#if defined(jpn)
#define data_020f1b14 data_020f1c8c
#define data_020f1b04 data_020f1c7c
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

int LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" int _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* buffer);

extern char data_020f1b14;
extern char data_0211e33c;
extern char data_020f1b04;

// USA: func_020a6194
ARM void RunScriptIfAvailable020a6194(void*) {
    int count;
    char buf[0x430];
    int header;

    BackgroundLoader::AddLockGlobal();
    count = 0;
    header = LoadFileIntoMemory(&data_020f1b14, &data_0211e33c, (unsigned int*)&count);
    if (header != 0) {
        ((Script*)((struct ResetStruct*)buf))->Initialize();
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, &data_020f1b04);
        ((Script*)((struct StreamState*)buf))->Load((struct StreamHeader*)header, count);
        ((Script*)((struct Struct02030774*)buf))->Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
}
