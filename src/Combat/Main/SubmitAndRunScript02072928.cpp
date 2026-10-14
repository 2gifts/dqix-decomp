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

extern int data_020f0cc8;

struct Global02108db0_02072928 {
    unsigned char field0;
    char pad1;
    unsigned short field2;
    void* field4;
    void* field8;
    int fieldc;
    void* field10;
};
extern struct Global02108db0_02072928 data_02108db0;

// USA: func_02072928
ARM void SubmitAndRunScript02072928(void* param0, struct StreamHeader* param1, int param2, int param3, void* stackArg5, unsigned char stackArg6) {
    data_02108db0.field10 = param0;
    data_02108db0.fieldc = 0;
    data_02108db0.field8 = &param3;
    data_02108db0.field2 = 1;
    data_02108db0.field4 = stackArg5;
    data_02108db0.field0 = stackArg6;

    struct ResetStruct local;
    ((Script*)&local)->Initialize();
    ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f0cc8);
    ((Script*)((struct StreamState*)&local))->Load(param1, param2);
    ((Script*)((struct Struct02030774*)&local))->Execute();
}
