#include <globaldefs.h>

struct S_b20c {
    int field0;
    int field4;
    unsigned char field8;
};

// USA: func_0205b20c
ARM void ClearTwoWordsAndByte_0205b20c(struct S_b20c* obj) {
    obj->field0 = 0;
    obj->field4 = 0;
    obj->field8 = 0;
}
