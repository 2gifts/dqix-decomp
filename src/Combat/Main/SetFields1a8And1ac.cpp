#include <globaldefs.h>

struct S02053f4c {
#if defined(jpn)
    char unk[0x19c];
#else
    char unk[0x1a8];
#endif
    int field1a8;
    int field1ac;
};

// USA: func_02053f4c
ARM void SetFields1a8And1ac(struct S02053f4c* obj, int val1, int val2) {
    obj->field1a8 = val1;
    obj->field1ac = val2;
}
