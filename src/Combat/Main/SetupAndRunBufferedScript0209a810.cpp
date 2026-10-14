#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

#include "std_library_functions.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* dataPtr);

extern char data_020f1668[];
extern char data_0211e33c[];
extern char data_020f1640[];

struct Ctx0209a810 { void* field0; };
extern struct Ctx0209a810* data_02109ba8;

// USA: func_0209a810
ARM void SetupAndRunBufferedScript0209a810(struct Ctx0209a810* ctx, void* value) {
    unsigned int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();

    if (LoadFileIntoMemory(data_020f1668, data_0211e33c, &count) != NULL) {
        ctx->field0 = value;
        memset(value, 0, 0x550);
        data_02109ba8 = ctx;
        ((Script*)((struct ResetStruct*)buf))->Initialize();
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, data_020f1640);
        ((Script*)((struct StreamState*)buf))->Load((struct StreamHeader*)data_0211e33c, count);
        ((Script*)((struct Struct02030774*)buf))->Execute();
        data_02109ba8 = NULL;
    }
    BackgroundLoader::RemoveLockGlobal();
}
