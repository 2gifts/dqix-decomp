#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* dataPtr);

extern char data_0211e33c[];
extern int data_020f0cc8;

struct Global02108db0_020727f8 {
    unsigned char field0;
    char pad1;
    unsigned short field2;
    void* field4;
    void* field8;
    int fieldc;
    void* field10;
};
extern struct Global02108db0_020727f8 data_02108db0;

// USA: func_020727f8
ARM void SubmitScriptFromFile020727f8(void* param0, const char* path, int param2, void* param3, unsigned char stackArg) {
    unsigned int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(path, data_0211e33c, &count);
    if (header != 0) {
        data_02108db0.field10 = param0;
        data_02108db0.fieldc = 0;
        data_02108db0.field8 = &param2;
        data_02108db0.field2 = 1;
        data_02108db0.field4 = param3;
        data_02108db0.field0 = stackArg;

        ((Script*)((struct ResetStruct*)buf))->Initialize();
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, &data_020f0cc8);
        ((Script*)((struct StreamState*)buf))->Load(header, count);
        ((Script*)((struct Struct02030774*)buf))->Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
}
