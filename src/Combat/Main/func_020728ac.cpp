#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

extern int data_020f0cc8;

struct Data02108db0 {
    unsigned char f0;
    char pad1;
    short f2;
    int f4;
    int f8;
    int fc;
    int f10;
};
extern struct Data02108db0 data_02108db0;

// USA: func_020728ac
extern "C" ARM void func_020728ac(int param0, int param1, struct StreamHeader* buffer, int length, int stack5, unsigned short stack6, unsigned char stack7) {
    char local[0x430];
    data_02108db0.f10 = param0;
    data_02108db0.fc = param1;
    data_02108db0.f8 = stack5;
    data_02108db0.f2 = stack6;
    data_02108db0.f4 = 0;
    data_02108db0.f0 = stack7;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_020f0cc8);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct02030774*)local))->Execute();
}
