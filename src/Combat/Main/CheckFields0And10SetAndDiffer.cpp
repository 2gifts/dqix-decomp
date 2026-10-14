#include <globaldefs.h>

struct B88fcObj {
    int field0;
    char unk[0xc];
    int field10;
};

// USA: func_020688fc
ARM int CheckFields0And10SetAndDiffer_020688fc(int unused, struct B88fcObj* obj) {
    int a = obj->field0;
    int b = obj->field10;
    if (a != 0 && b != 0) {
        return a != b;
    }
    return 0;
}
