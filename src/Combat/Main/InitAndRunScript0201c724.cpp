#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

extern int data_020ef2bc;
extern int data_020ef2c0;

struct Data020fdc14 {
    int field0;
    void* field4;
    int field8;
};
extern struct Data020fdc14 data_020fdc14;

// USA: func_0201c724  (semantic: InitAndRunScript0201c724)
extern "C" ARM void func_0201c724(int param0, void* param1, struct StreamHeader* param2, int param3) {
    char local[0x430];
    data_020fdc14.field4 = param1;
    data_020ef2bc = param0;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_020ef2c0);
    ((Script*)((struct StreamState*)local))->Load(param2, param3);
    ((Script*)((struct Struct02030774*)local))->Execute();
    data_020fdc14.field4 = 0;
    data_020ef2bc = -1;
}
