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

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* p, void* q);

struct LocalA0209bc98 {
    void* field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
};

struct Data02109bb00209bc98 {
    struct LocalA0209bc98* current;
};
extern struct Data02109bb00209bc98 data_02109bb0;
extern int data_020f16c0;

// USA: func_0209bc98
ARM void SetupAndRunBufferedScript0209bc98(void* param0, struct StreamHeader* param1, int param2, int param3, int arg5, int arg6, int arg7) {
    if (param1 != 0) {
        struct LocalA0209bc98 local;
        data_02109bb0.current = &local;
        data_02109bb0.current->field0 = param0;
        data_02109bb0.current->field4 = arg5;
        data_02109bb0.current->field8 = arg6;
        data_02109bb0.current->fieldc = arg7;
        data_02109bb0.current->field10 = 1;
        data_02109bb0.current->field14 = 0;

        struct ResetStruct local2;
        ((Script*)&local2)->Initialize();
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&local2, &data_020f16c0);
        ((Script*)((struct StreamState*)&local2))->Load(param1, param2);
        ((Script*)((struct Struct02030774*)&local2))->Execute();
    }
}
