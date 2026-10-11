#include <globaldefs.h>
#if defined(jpn)
#define data_020f1917 data_020f1a7f
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

struct Global02109d94_020a13e4 {
    unsigned char field0;
    char pad1;
    unsigned short field2;
    void* field4;
    void* field8;
    int fieldC;
};
extern struct Global02109d94_020a13e4 data_02109d94;

extern int data_020f1917;
extern int data_020f192c;
extern int data_020f18ec;

// JPN: func_020a315c
// USA: func_020a13e4
ARM void SetupGlobalAndRunScript020a13e4(void* param0, void* param1, int param2, unsigned short param3, unsigned char param4) {
    if (param1 != 0) {
        int localVar;
        void* result;
        data_02109d94.field4 = param0;
        data_02109d94.field8 = param1;
        data_02109d94.fieldC = param2;
        data_02109d94.field2 = param3;
        data_02109d94.field0 = param4;
        BackgroundLoader::AddLockGlobal();
        localVar = 0;
        #if defined(jpn)
        result = LoadFileIntoMemory((const char*)&data_020f1917, data_0211e33c, (unsigned int*)&localVar);
#else
        result = ExtractFileFromGP2((const char*)&data_020f1917, (const char*)&data_020f192c, (unsigned int*)&localVar);
#endif
        if (result != 0) {
            struct ResetStruct local;
            _ZN6Script10InitializeEv(&local);
            _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&local, &data_020f18ec);
            _ZN6Script4LoadEPKvj((struct StreamState*)&local, (struct StreamHeader*)result, localVar);
            _ZN6Script7ExecuteEv((struct Struct02030774*)&local);
        }
        BackgroundLoader::RemoveLockGlobal();
    }
}
