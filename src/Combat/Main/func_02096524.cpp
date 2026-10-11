#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* dataPtr);

void* LoadFileIntoMemory(const char*, void*, unsigned int*);

extern char data_020f14b0[] __attribute__((aligned(4)));
extern char data_0211e33c[];
extern int data_020f1444;

struct Manager02109404 {
    char pad[0x10];
    char* f10;
};
extern struct Manager02109404 data_02109404;

// USA: func_02096524
extern "C" ARM void func_02096524(char* ctx) {
    unsigned int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();
    void* header = LoadFileIntoMemory(data_020f14b0, data_0211e33c, &count);
    if (header != 0) {
        char* slot = ctx + 0xac;
        struct Manager02109404* manager = &data_02109404;
        manager->f10 = slot;
        unsigned int len = count;
        _ZN6Script10InitializeEv((struct ResetStruct*)buf);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, &data_020f1444);
        _ZN6Script4LoadEPKvj((struct StreamState*)buf, (struct StreamHeader*)header, len);
        _ZN6Script7ExecuteEv((struct Struct02030774*)buf);
    }
    BackgroundLoader::RemoveLockGlobal();
}
