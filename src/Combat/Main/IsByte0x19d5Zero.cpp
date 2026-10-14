#include <globaldefs.h>

struct B88ccObj {
    char unk[0x19d5];
    unsigned char field;
};

// USA: func_020688cc
ARM int IsByte0x19d5Zero_020688cc(int unused, struct B88ccObj* obj) {
    return obj->field == 0;
}
