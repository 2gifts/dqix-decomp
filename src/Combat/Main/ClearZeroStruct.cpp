#include <globaldefs.h>

struct ZeroStruct {
    int field0;
    int field4;
    unsigned char field8;
    unsigned char field9;
    unsigned char fieldA;
    unsigned char fieldB;
};

// USA: func_020e1568
ARM void ClearZeroStruct_020e1568(struct ZeroStruct* s) {
    s->field0 = 0;
    s->field4 = 0;
    s->field9 = 0;
    s->field8 = 0;
    s->fieldB = 0;
    s->fieldA = 0;
}
