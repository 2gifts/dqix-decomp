#include <globaldefs.h>
#include "Resource/FontBankLoader.h"


struct Self2f00 {
    char pad0[0x36];
    unsigned char f36;
    unsigned char f37;
};

// USA: func_02092f00  (semantic: UpdateStateMachine02092f00)
extern "C" ARM void func_02092f00(struct Self2f00* self) {
    unsigned char flags = self->f37;
    if (flags & 8) return;
    if (!(flags & 4)) return;
    FontBankLoader* globalVal = GetGlobal02109400();
    if (self->f36 == 0) {
        BlankFunction02094b3c(globalVal, 0xa);
        BlankFunction02094b30(globalVal, 0x1f8, 0);
        self->f36 = self->f36 + 1;
        return;
    }
    if (self->f36 != 1) return;
    if (AlwaysTrue02094b4c(globalVal)) {
        self->f37 = self->f37 & ~4;
        self->f36 = 0;
    }
}
