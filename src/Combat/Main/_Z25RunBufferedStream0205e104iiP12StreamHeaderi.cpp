#include <globaldefs.h>

struct StreamHeader;

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);
extern "C" int _ZN6Script4LoadEPKvj(struct ResetStruct* s, struct StreamHeader* buffer, int length);
extern "C" int _ZN6Script7ExecuteEv(struct ResetStruct* p);

extern void* data_02108740[];
extern int data_020f051c;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0205e104
extern "C" ARM int _Z25RunBufferedStream0205e104iiP12StreamHeaderi(int arg0, int arg1, struct StreamHeader* buffer, int length) {
    char local[0x430];
    if (arg0 && buffer && length) {
        data_02108740[1] = (void*)arg0;
        data_02108740[0] = (void*)arg1;
        _ZN6Script10InitializeEv((struct ResetStruct*)local);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_020f051c);
        _ZN6Script4LoadEPKvj((struct ResetStruct*)local, buffer, length);
        _ZN6Script7ExecuteEv((struct ResetStruct*)local);
    }
}