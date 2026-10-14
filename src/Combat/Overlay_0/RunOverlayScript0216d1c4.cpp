#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

extern int data_ov000_02184264;
extern int data_ov000_02183b5c;

// USA: func_ov000_0216d1c4
ARM void RunOverlayScript0216d1c4(int arg0, struct StreamHeader* buffer, int length, int* out) {
    char local[0x430];
    *(int*)((char*)&data_ov000_02184264 + 0x8) = arg0;
    *(int*)((char*)&data_ov000_02184264 + 0x4) = 0;
    *(int*)((char*)&data_ov000_02184264 + 0x0) = 0;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_ov000_02183b5c);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct02030774*)local))->Execute();
    *out = *(int*)&data_ov000_02184264;
}
