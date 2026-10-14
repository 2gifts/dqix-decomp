#include <globaldefs.h>
#include "Resource/Script.h"

struct Data02108cec0206da80 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    short half4;
    short half6;
    short half8;
    short halfa;
    short halfc;
    short pade;
    void* field10;
    void* field14;
};
extern struct Data02108cec0206da80 data_02108cec;

struct ResetStruct;
struct StreamState;
struct StreamHeader;
struct Struct02030774;
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);
extern int data_020f0994;

// USA: func_0206da80
extern "C" ARM int func_0206da80(int* param0, unsigned char param1, unsigned char param2, unsigned char param3, int arg5, int arg6, struct StreamHeader* arg7, int arg8) {
    char local[0x430];
    if (data_02108cec.field10 != 0) {
        *param0 = 0;
        data_02108cec.halfa = 0;
        data_02108cec.half8 = -1;
        data_02108cec.half4 = -1;
        data_02108cec.half6 = -1;
    }
    *param0 = 0;
    data_02108cec.byte2 = param1;
    data_02108cec.byte1 = param2;
    data_02108cec.byte0 = param3;
    data_02108cec.halfc = arg5;
    data_02108cec.field10 = param0;
    data_02108cec.field14 = (void*)arg6;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_020f0994);
    ((Script*)((struct StreamState*)local))->Load(arg7, arg8);
    ((Script*)((struct Struct02030774*)local))->Execute();
    return 1;
}
