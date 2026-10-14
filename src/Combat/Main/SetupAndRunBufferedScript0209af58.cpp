#include <globaldefs.h>
#include "Resource/Script.h"

struct LocalStruct0209af58 {
    void* field0;
    int field4;
    int field8;
};
extern struct LocalStruct0209af58* data_02109bac;

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* dataPtr);
extern char data_020f1680[];

// USA: func_0209af58
ARM void SetupAndRunBufferedScript0209af58(void* param0, struct StreamHeader* param1, int param2, int param3, int param4) {
    if (param1 != 0) {
        struct LocalStruct0209af58 local;
        char buf[0x430];

        data_02109bac = &local;
        data_02109bac->field0 = param0;
        data_02109bac->field4 = param4;
        data_02109bac->field8 = 0;

        ((Script*)((struct ResetStruct*)buf))->Initialize();
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, data_020f1680);
        ((Script*)((struct StreamState*)buf))->Load(param1, param2);
        ((Script*)((struct Struct02030774*)buf))->Execute();
    }
}
