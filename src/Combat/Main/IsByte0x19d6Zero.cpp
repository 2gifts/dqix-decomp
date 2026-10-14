#include <globaldefs.h>

struct B88e4Obj {
    char unk[0x19d6];
    unsigned char field;
};

// USA: func_020688e4
ARM int IsByte0x19d6Zero_020688e4(int unused, struct B88e4Obj* obj) {
    return obj->field == 0;
}
