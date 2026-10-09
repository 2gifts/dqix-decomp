#include <globaldefs.h>

#include "Combat/WorkRecord.h"
#include "std_library_functions.h"


// USA: func_0206bf2c
ARM void ClearWorkRecord0206bf2c(struct Rec0206bf2c* obj) {
    obj->field0 = 0;
    obj->field2 = 0;
    obj->field4 = 0;
    obj->field5 = 0;
    obj->field7 = 0;
    obj->field8 = 0;
    obj->flagsA_b0 = 0;
    obj->flagsA_b1 = 0;
    obj->flagsA_b2 = 0;
    obj->flagsA_b3 = 0;
    obj->flagsA_b4 = 0;
    obj->fieldC = 0;
    obj->fieldB = 0;
    obj->field1e = 0;
    memset(obj->pad24, 0, sizeof(obj->pad24));
    obj->field1f = 0;
    obj->field34 = 0;
    obj->field38 = 0x7a;
    unsigned int tmp46 = obj->field38 - 0x7b;
    obj->field3c = 0;
    obj->field40 = 0;
    obj->field44 = 0;
    obj->field46 = (unsigned short)tmp46;
    memset(obj->pad10, 0, sizeof(obj->pad10));
    obj->field1c = 0;
    memset(obj->pad48, 0, sizeof(obj->pad48));
    obj->field54 = 0;
    obj->field58 = 0;
    obj->field5c = 0;
    obj->field60 = 0;
    obj->field20 = 0;
    obj->field64 = 0;
    obj->field68 = 0;
    obj->field6c = 0;
    obj->field70 = 0;
}
