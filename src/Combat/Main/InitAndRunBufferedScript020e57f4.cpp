#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

extern int data_021536c4;
extern int data_020f2e2c;

// USA: func_020e57f4
ARM int InitAndRunBufferedScript020e57f4(int handler0, int handler1, struct StreamHeader* buffer, int length) {
    char local[0x430];
    *(int*)((char*)&data_021536c4 + 4) = handler0;
    *(int*)&data_021536c4 = handler1;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_020f2e2c);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct02030774*)local))->Execute();
    return 0;
}
