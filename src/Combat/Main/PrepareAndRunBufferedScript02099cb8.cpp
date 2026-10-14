#include <globaldefs.h>
#if defined(jpn)
#define data_020f15ac data_020f1714
#define data_020f1574 data_020f16dc
#endif
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

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
        ((Script*)((struct ResetStruct*)buf))->Initialize();
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, data_020f1574);
        ((Script*)((struct StreamState*)buf))->Load(header, count);
        ((Script*)((struct Struct02030774*)buf))->Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
}
