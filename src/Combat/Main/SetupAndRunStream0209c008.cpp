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

struct StreamHeader;
struct StreamState;

struct Struct02030774;

extern int data_020f16f8;

struct LocalA0209c008 {
    void* field0;
    unsigned short field4;
    unsigned short field6;
    int field8;
};
extern struct LocalA0209c008* data_02109bc8;

// USA: func_0209c008  (semantic: SetupAndRunStream0209c008)
extern "C" ARM void func_0209c008(void* obj, struct StreamHeader* buffer, int length, int idFlag, int mulVal, int addVal) {
    struct LocalA0209c008 local;
    local.field0 = obj;
    local.field4 = mulVal * 100 + addVal;
    local.field6 = idFlag;
    local.field8 = 1;
    data_02109bc8 = &local;

    struct ResetStruct local2;
    ((Script*)&local2)->Initialize();
    ((Script*)&local2)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f16f8);
    ((Script*)((struct StreamState*)&local2))->Load(buffer, length);
    ((Script*)((struct Struct02030774*)&local2))->Execute();
}
