#include <globaldefs.h>
#if defined(jpn)
#define data_020f1b97 data_020f1d0f
#define data_020f1b6c data_020f1ce4
#endif
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

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* p, void* q);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

#if defined(jpn)
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern char data_0211e33c[];
#else
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
#endif

struct Pair020a818c { void* a; void* b; };
extern struct Pair020a818c data_02109fe0;

extern int data_020f1b97;
extern int data_020f1baa;
extern int data_020f1b6c;

// JPN: func_020a9f10
// USA: func_020a818c  (semantic: SetupPairAndRunBufferedScript_020a818c)
extern "C" ARM void func_020a818c(void* param0, void* param1) {
    BackgroundLoader::AddLockGlobal();
    int localVar = 0;
    #if defined(jpn)
    void* result = LoadFileIntoMemory((const char*)&data_020f1b97, data_0211e33c, (unsigned int*)&localVar);
#else
    void* result = ExtractFileFromGP2((const char*)&data_020f1b97, (const char*)&data_020f1baa, (unsigned int*)&localVar);
#endif
    if (result != 0) {
        struct ResetStruct local;
        data_02109fe0.a = param1;
        data_02109fe0.b = param0;
        _ZN6Script10InitializeEv(&local);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&local, &data_020f1b6c);
        _ZN6Script4LoadEPKvj((struct StreamState*)&local, (struct StreamHeader*)result, localVar);
        _ZN6Script7ExecuteEv((struct Struct02030774*)&local);
    }
    BackgroundLoader::RemoveLockGlobal();
}
