#include <globaldefs.h>

struct S_a28e0 {
    char pad[0x270];
    signed char field270;
    char pad2[3];
    int field274;
    int field278;
    int field27c;
    int field280;
    int field284;
    int field288;
};

// USA: func_020a28e0
ARM void ResetField270Block_020a28e0(struct S_a28e0* p) {
    p->field270 = -1;
    p->field274 = 0;
    p->field278 = 0;
    p->field27c = 0;
    p->field280 = 0;
    p->field284 = 0;
    p->field288 = 0;
}
