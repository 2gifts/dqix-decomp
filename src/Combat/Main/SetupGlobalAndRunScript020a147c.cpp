#include <globaldefs.h>
#include "Resource/Script.h"

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

struct StreamState;
struct StreamHeader;

struct Struct02030774;

struct Global02109d94_020a147c {
    unsigned char field0;
    char pad1;
    unsigned short field2;
    void* field4;
    void* field8;
    int fieldC;
};
extern struct Global02109d94_020a147c data_02109d94;

extern int data_020f18ec;

// USA: func_020a147c
ARM void SetupGlobalAndRunScript020a147c(void* param0, void* param1, struct StreamHeader* param2, int param3, int param4, unsigned short param5, unsigned char param6) {
    if (param1 != 0 && param2 != 0 && param3 != 0) {
        struct ResetStruct local;
        data_02109d94.field4 = param0;
        data_02109d94.field8 = param1;
        data_02109d94.fieldC = param4;
        data_02109d94.field2 = param5;
        data_02109d94.field0 = param6;
        ((Script*)&local)->Initialize();
        ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f18ec);
        ((Script*)((struct StreamState*)&local))->Load(param2, param3);
        ((Script*)((struct Struct02030774*)&local))->Execute();
    }
}
