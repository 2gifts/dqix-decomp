#include <globaldefs.h>

#if defined(jpn)
enum { POINTER_FIELD_OFFSET = 0x190 };
#else
enum { POINTER_FIELD_OFFSET = 0x19c };
#endif

struct Field0x19cData {
    short f0;
    char f2;
    char f3;
    char f4;
    char pad[3];
    int f8;
};

// USA: func_02053da0
ARM void SetAndClearField0x19c(char* obj, struct Field0x19cData* p) {
    *(struct Field0x19cData**)(obj + POINTER_FIELD_OFFSET) = p;
    p->f0 = 0;
    p->f2 = 0;
    p->f3 = 0;
    p->f4 = 0;
    p->f8 = 0;
}
