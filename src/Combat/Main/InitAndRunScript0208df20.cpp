#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

struct Data02108fd4 {
    void* field0;
    int field4;
    void* field8;
    void* fieldC;
};
extern struct Data02108fd4 data_02108fd4;
extern int data_020f1258;

struct Struct0208df20 { int field0; short field4; };

// USA: func_0208df20
ARM void InitAndRunScript0208df20(struct Struct0208df20* param0, void* param1, int param2, int param3, int param4, void* param5) {
    char local[0x430];
    param0->field0 = 0;
    param0->field4 = 0;
    data_02108fd4.fieldC = param1;
    data_02108fd4.field4 = param4;
    data_02108fd4.field0 = &param5;
    data_02108fd4.field8 = param0;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f1258);
    ((Script*)((struct StreamState*)local))->Load((struct StreamHeader*)param2, param3);
    ((Script*)((struct Struct02030774*)local))->Execute();
}
