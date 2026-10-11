#include <globaldefs.h>
#if defined(jpn)
#define data_020f1744 data_020f18ac
#define data_020f1718 data_020f1880
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

extern char data_020f1744;
extern char data_0211e33c;
extern char data_020f1718;

// USA: func_0209cbcc
ARM void RunScriptIfAvailable0209cbcc(void) {
    int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();
    if (LoadFileIntoMemory(&data_020f1744, &data_0211e33c, (unsigned int*)&count) != 0) {
        _ZN6Script10InitializeEv((struct ResetStruct*)buf);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, &data_020f1718);
        _ZN6Script4LoadEPKvj((struct StreamState*)buf, (struct StreamHeader*)&data_0211e33c, count);
        _ZN6Script7ExecuteEv((struct Struct02030774*)buf);
    }
    BackgroundLoader::RemoveLockGlobal();
}
