#include <globaldefs.h>

struct HalfwordTriple0202e98c;
void ClearThreeHalfwords(struct HalfwordTriple0202e98c* p);

struct TargetHalfwords0202e95c {
    char pad[0x212];
    unsigned short field212;
    unsigned short field214;
    unsigned short field216;
};

// USA: func_0202e95c
ARM void SetTargetHalfwords0202e95c(TargetHalfwords0202e95c* obj, short a, unsigned short b) {
    if (b != 0) {
        obj->field214 = a;
        obj->field216 = b;
        return;
    }
    ClearThreeHalfwords((struct HalfwordTriple0202e98c*)obj);
    obj->field212 = a;
}
