#include <globaldefs.h>

struct ClampFieldPairStruct {
    char pad[0x1c];
    unsigned short f1c;
    unsigned short f1e;
    char pad2[0x6c - 0x20];
    unsigned short f6c;
    unsigned short f6e;
};

// USA: func_020863e0
ARM void ClampFieldPairToMax_020863e0(struct ClampFieldPairStruct* s) {
    if (s->f6c < s->f1c) s->f1c = s->f6c;
    if (s->f6e < s->f1e) s->f1e = s->f6e;
}
