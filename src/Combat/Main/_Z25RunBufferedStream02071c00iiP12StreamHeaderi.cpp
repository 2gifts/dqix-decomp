#include <globaldefs.h>
#include "Resource/Script.h"

struct StreamHeader;

struct ResetStruct {
    int w0;
    int w4;
    int w8;
    int wc;
    int w10;
    int w14;
    int w18;
    int w1c;
    int w20;
    int w24;
    int w28;
    char pad[0x400];
    unsigned char b42c;
};

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct* p, void* q);

struct Global02108d98 {
    unsigned short h0;
    char pad0[2];
    int field4;
    int field8;
    int fieldC;
};
extern struct Global02108d98 data_02108d98;

extern int data_020f0c78;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02071c00
ARM int RunBufferedStream02071c00(int arg0, int arg1, struct StreamHeader* header, int length) {
    struct ResetStruct local;

    data_02108d98.fieldC = arg0;
    data_02108d98.field8 = arg1;
    data_02108d98.field4 = 0;
    data_02108d98.h0 = 0;

    ((Script*)&local)->Initialize();
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&local, &data_020f0c78);
    ((Script*)&local)->Load(header, length);
    ((Script*)&local)->Execute();
}
