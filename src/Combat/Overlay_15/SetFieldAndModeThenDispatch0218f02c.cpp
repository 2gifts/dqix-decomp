#include <globaldefs.h>

#include "Combat/Overlay15ViewerContext.h"

struct Self0218f02c {
    int f0;
    unsigned char pad[0x1c - 4];
    unsigned char f1c;
};

// USA: func_ov015_0218f02c
ARM void SetFieldAndModeThenDispatch0218f02c(struct Self0218f02c* self, int a1, int mode) {
    self->f0 = a1;
    switch (mode) {
        case 0: self->f1c = 0; break;
        case 1: self->f1c = 1; break;
        case 2: self->f1c = 3; break;
        case 3: self->f1c = 2; break;
        case 4: self->f1c = 2; break;
        case 5: self->f1c = 5; break;
        case 6: self->f1c = 6; break;
        case 7: self->f1c = 4; break;
    }
    func_ov015_0218bcb0(self);
}
