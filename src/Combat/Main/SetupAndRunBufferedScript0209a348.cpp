#include <globaldefs.h>

#if defined(jpn)
#define data_020f1628 data_020f1790
#endif
#include "Filesystem/BackgroundLoader.h"


struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* dataPtr);

extern char data_020f1628[];
extern char data_0211e33c[];
extern char data_020f15e8[];

struct Ctx0209a348 { void* field0; };
extern struct Ctx0209a348* data_02109ba4;

#if defined(jpn)
#define SetupAndRunBufferedScript0209a348 func_0209c09c
extern "C" ARM void func_0209c09c(struct Ctx0209a348* ctx, void* value);
#endif

// USA: func_0209a348
ARM void SetupAndRunBufferedScript0209a348(struct Ctx0209a348* ctx, void* value) {
    unsigned int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(data_020f1628, data_0211e33c, &count);
    if (header != NULL) {
        ctx->field0 = value;
        data_02109ba4 = ctx;
        _ZN6Script10InitializeEv((struct ResetStruct*)buf);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, data_020f15e8);
        _ZN6Script4LoadEPKvj((struct StreamState*)buf, header, count);
        _ZN6Script7ExecuteEv((struct Struct02030774*)buf);
        data_02109ba4 = NULL;
    }
    BackgroundLoader::RemoveLockGlobal();
}
