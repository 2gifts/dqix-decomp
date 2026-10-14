#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader {
    int field0;
    int size;
};

struct Struct02030774;

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

extern int data_020f0b80;

struct Data02108d70 {
    short h0;
    unsigned short h2;
    short h4;
    unsigned short h6;
    char pad8[0xc - 0x8];
    int w0xc;
    char pad10[0x18 - 0x10];
    int w0x18;
    char pad1c[0x20 - 0x1c];
    int w0x20;
};
extern struct Data02108d70 data_02108d70;

struct Obj02071488 {
    char pad0[7];
    unsigned char f7;
    unsigned char f8;
    char pad9[0x46 - 0x9];
    short f46;
};

// USA: func_02071488
ARM int RunScriptAndAdjustObj02071488(struct StreamHeader* buffer, int length, int assetId, struct Obj02071488* obj) {
    char local[0x430];

    data_02108d70.w0x20 = (int)obj;
    data_02108d70.w0x18 = assetId;
    data_02108d70.w0xc = 0;
    data_02108d70.h4 = 0;

    ((Script*)((struct ResetStruct*)local))->Initialize();
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_020f0b80);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct02030774*)local))->Execute();

    obj->f7 = 0;
    obj->f8 = 0;
    if (assetId >= 0x5208 && assetId < 0x9c40) {
        obj->f7 = 1;
        if (obj->f46 >= 0) {
            obj->f46 = obj->f46 + data_02108d70.h2;
        }
    } else if (assetId >= 0x9c40) {
        obj->f8 = 1;
        if (obj->f46 >= 0) {
            obj->f46 = obj->f46 + data_02108d70.h6;
        }
    }

    return data_02108d70.w0xc;
}
