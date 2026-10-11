#if defined(jpn)
#define R(j,u) (j)
#define data_ov015_02193fa0 data_ov015_02194ae0
#define data_ov015_02193fc8 data_ov015_02194b08
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct ResetStruct {
    int w0;
    int w4;
    int w8;
    int wc;
    int w10;
    int w14;
    int w18;
    int w1c;
    int w20;
    int w24;
    int w28;
    char pad[0x400];
    unsigned char b42c;
};
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamHeader;
struct StreamState;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* p, void* q);
extern "C" void func_ov015_0218b828();
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char* path, void* buf, unsigned int* outLen);

extern int data_0211e33c;
extern int data_ov015_02193fc8;
extern void* data_ov015_02194560;
extern int data_ov015_02193fa0;

// USA: func_ov015_0218ba44  (semantic: InitAndRunStream_0218ba44)
extern "C" ARM void func_ov015_0218ba44(void* self, const char* path) {
    func_ov015_0218b828();
    BackgroundLoader::AddLockGlobal();

    unsigned int length;
    void* buffer;
    if (path != 0) {
        buffer = _Z18LoadFileIntoMemoryPKcPvPj(path, &data_0211e33c, &length);
    } else {
        buffer = _Z18LoadFileIntoMemoryPKcPvPj((const char*)&data_ov015_02193fc8, &data_0211e33c, &length);
    }

    if (buffer != 0) {
        data_ov015_02194560 = self;

        struct ResetStruct local;
        _ZN6Script10InitializeEv(&local);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&local, &data_ov015_02193fa0);
        _ZN6Script4LoadEPKvj((struct StreamState*)&local, (struct StreamHeader*)buffer, length);
        _ZN6Script7ExecuteEv((struct Struct02030774*)&local);
    }

    BackgroundLoader::RemoveLockGlobal();
}
