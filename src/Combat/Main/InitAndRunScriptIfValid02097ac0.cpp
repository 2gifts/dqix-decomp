#include <globaldefs.h>
#include "Resource/Script.h"
#if defined(jpn)
#define data_020f14dc data_020f1628
#endif

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

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
        ((Script*)((struct ResetStruct*)local))->Initialize();
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_020f14dc);
        ((Script*)((struct StreamState*)local))->Load(param2, param3);
        ((Script*)((struct Struct02030774*)local))->Execute();
    }
}
