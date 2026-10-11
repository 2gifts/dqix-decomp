#include <globaldefs.h>
#if defined(jpn)
#define data_020f14dc data_020f1628
#endif

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

struct Data021098e0 {
    void* field0;
    void* field4;
};
extern struct Data021098e0 data_021098e0;
extern int data_020f14dc;

// USA: func_02097ac0
ARM void InitAndRunScriptIfValid02097ac0(void* param0, void* param1, struct StreamHeader* param2, int param3) {
    char local[0x430];
    if (param2 != 0 && param3 != 0) {
        data_021098e0.field4 = param0;
        data_021098e0.field0 = &param1;
        _ZN6Script10InitializeEv((struct ResetStruct*)local);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_020f14dc);
        _ZN6Script4LoadEPKvj((struct StreamState*)local, param2, param3);
        _ZN6Script7ExecuteEv((struct Struct02030774*)local);
    }
}
