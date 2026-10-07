#include <globaldefs.h>

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

extern int data_02108dd8;
extern int data_020f0d2c;
extern int data_020f0d30;

// KEEP-NAME
// USA: func_0207416c
extern "C" ARM int _Z25RunBufferedStream0207416ciiP12StreamHeaderi(int handler0, int handler1, struct StreamHeader* buffer, int length) {
    char local[0x430];
    data_02108dd8 = handler0;
    data_020f0d2c = handler1;
    _ZN6Script10InitializeEv((struct ResetStruct*)local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_020f0d30);
    _ZN6Script4LoadEPKvj((struct StreamState*)local, buffer, length);
    _ZN6Script7ExecuteEv((struct Struct02030774*)local);
    return 1;
}
