#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct EntryArray0207efdc;
struct StreamHeader;

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
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* p, void* q);

extern void* data_02108ed8[2];
extern int data_020f0f88;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0207ef74
ARM void LoadEntryArrayFromStream0207ef74(struct EntryArray0207efdc* param0, SafeAllocator* param1, struct StreamHeader* param2, int param3) {
    if (param1 != 0 && param2 != 0 && param3 != 0) {
        struct ResetStruct local;
        data_02108ed8[1] = param0;
        data_02108ed8[0] = param1;
        _ZN6Script10InitializeEv(&local);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&local, &data_020f0f88);
        _ZN6Script4LoadEPKvj((struct StreamState*)&local, param2, param3);
        _ZN6Script7ExecuteEv((struct Struct02030774*)&local);
    }
}
