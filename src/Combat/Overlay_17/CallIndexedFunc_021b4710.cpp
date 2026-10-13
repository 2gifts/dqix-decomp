#include <globaldefs.h>

typedef void (*FuncPtr021b4710)(void*);

struct VTable021b4710 {
    FuncPtr021b4710 funcs[9];
};
extern VTable021b4710 data_ov017_021d6bd8;

struct Obj021b4710 {
    unsigned char pad[0x10];
    unsigned char index;
};

// USA: func_ov017_021b4710
ARM void CallIndexedFunc_021b4710(Obj021b4710* p, void* context) {
    VTable021b4710 local = data_ov017_021d6bd8;
    local.funcs[p->index](p);
}
