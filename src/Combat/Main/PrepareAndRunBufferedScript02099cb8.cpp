#include <globaldefs.h>
#if defined(jpn)
#define data_020f15ac data_020f1714
#define data_020f1574 data_020f16dc
#endif
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"


struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* dataPtr);

extern char data_020f15ac[];
extern char data_0211e33c[];
extern char data_020f1574[];

// USA: func_02099cb8
ARM void PrepareAndRunBufferedScript02099cb8(char* param0) {
    int count;
    char buf[0x430];

    memset(param0, 0, 0x12c);
    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(data_020f15ac, data_0211e33c, (unsigned int*)&count);
    if (header != 0) {
        _ZN6Script10InitializeEv((struct ResetStruct*)buf);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, data_020f1574);
        _ZN6Script4LoadEPKvj((struct StreamState*)buf, header, count);
        _ZN6Script7ExecuteEv((struct Struct02030774*)buf);
    }
    BackgroundLoader::RemoveLockGlobal();
}
