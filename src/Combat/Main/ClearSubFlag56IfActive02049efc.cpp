#include <globaldefs.h>

struct S_10088;
int IsFlag10088Set_02010088(struct S_10088* obj);

struct Sub02049efc {
    unsigned char pad[0x56];
    unsigned char field56;
};
struct Obj02049efc {
    unsigned char pad[0x13c];
    struct Sub02049efc* sub;
};

// USA: func_02049efc
ARM void ClearSubFlag56IfActive02049efc(struct Obj02049efc* obj) {
    if (obj->sub == NULL) return;
    if (IsFlag10088Set_02010088((struct S_10088*)obj)) {
        obj->sub->field56 = 0;
    }
}
