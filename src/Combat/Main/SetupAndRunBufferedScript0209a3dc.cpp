#include <globaldefs.h>

#if defined(jpn)
#define data_020f1628 data_020f1790
#define data_020f1608 data_020f1770
#endif

#if defined(jpn)
#define func_0209a3dc func_0209c130
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
extern char data_020f1608[];

struct Ctx0209a3dc { void* field0; };
extern struct Ctx0209a3dc* data_02109ba4;

// USA: func_0209a3dc  (semantic: SetupAndRunBufferedScript0209a3dc)
extern "C" ARM void func_0209a3dc(struct Ctx0209a3dc* ctx, void* value) {
    unsigned int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(data_020f1628, data_0211e33c, &count);
    if (header != NULL) {
        ctx->field0 = value;
        data_02109ba4 = ctx;
        _ZN6Script10InitializeEv((struct ResetStruct*)buf);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, data_020f1608);
        _ZN6Script4LoadEPKvj((struct StreamState*)buf, header, count);
        _ZN6Script7ExecuteEv((struct Struct02030774*)buf);
        data_02109ba4 = NULL;
    }
    BackgroundLoader::RemoveLockGlobal();
}
