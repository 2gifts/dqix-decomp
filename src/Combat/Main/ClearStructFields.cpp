#include <globaldefs.h>

struct InitStruct2075 {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    char unk28[0x28];
    int field50;
    int field54;
    int field58;
    short field5c;
    char field5e;
    char field5f;
    int field60;
    int field64;
    int field68;
    int field6c;
};

// USA: func_02075d64
ARM void ClearStructFields_02075d64(struct InitStruct2075* p) {
    p->field0 = 0;
    p->field4 = 0;
    p->fieldc = 0;
    p->field8 = 0;
    p->field10 = 0;
    p->field18 = 0;
    p->field1c = 0;
    p->field20 = 0;
    p->field24 = 0;
    p->field50 = 0;
    p->field54 = 0;
    p->field5c = 0;
    p->field5f = 0;
    p->field60 = 0;
    p->field64 = 0;
    p->field68 = 0;
    p->field6c = 0;
}
