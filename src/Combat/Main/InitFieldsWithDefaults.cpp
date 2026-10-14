#include <globaldefs.h>

struct S_a64bc {
    int field0;
    int field4;
    signed char field8;
    signed char field9;
    signed char fielda;
    signed char fieldb;
    int fieldc;
};

// USA: func_020a64bc
ARM void InitFieldsWithDefaults_020a64bc(struct S_a64bc* p) {
    p->field0 = 0;
    p->field4 = 0;
    p->field8 = -1;
    p->field9 = 1;
    p->fielda = 0;
    p->fieldb = 0;
    p->fieldc = -1;
}
