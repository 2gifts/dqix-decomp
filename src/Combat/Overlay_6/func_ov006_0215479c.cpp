#include <globaldefs.h>
#include "Graphics/OBJImage.h"

struct Struct0215479c {
    struct InitStruct02075cdcStruct base;
    int f70;
    short f74;
    short f76;
    short f78;
    unsigned char f7a;
};

// USA: func_ov006_0215479c
extern "C" ARM void func_ov006_0215479c(struct Struct0215479c* self) {
    InitStruct02075cdc(&self->base);
    self->f70 = -1;
    self->f74 = -1;
    self->f7a = self->f76 = self->f78 = 0;
}
