#include <globaldefs.h>
#if defined(jpn)
#define data_020f1b14 data_020f1c8c
#define data_020f1b04 data_020f1c7c
#endif
#include "Filesystem/BackgroundLoader.h"


struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

int LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" int _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* buffer);

extern char data_020f1b14;
extern char data_0211e33c;
extern char data_020f1b04;

// USA: func_020a6194
ARM void RunScriptIfAvailable020a6194(void) {
    int count;
    char buf[0x430];
    int header;

    BackgroundLoader::AddLockGlobal();
    count = 0;
    header = LoadFileIntoMemory(&data_020f1b14, &data_0211e33c, (unsigned int*)&count);
    if (header != 0) {
        _ZN6Script10InitializeEv((struct ResetStruct*)buf);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, &data_020f1b04);
        _ZN6Script4LoadEPKvj((struct StreamState*)buf, (struct StreamHeader*)header, count);
        _ZN6Script7ExecuteEv((struct Struct02030774*)buf);
    }
    BackgroundLoader::RemoveLockGlobal();
}
