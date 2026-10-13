#include <globaldefs.h>
#include "Resource/FontBankLoader.h"


struct LoaderSub_021561b0 {
    char pad[0x47a];
    unsigned char state;
    unsigned char pad47b;
    unsigned int flags;
};

struct Loader_021561b0 {
    char pad[0x2000];
    struct LoaderSub_021561b0 sub;
};

// USA: func_ov002_021561b0  (semantic: ResetOrFinalizeLoaderState_021561b0)
extern "C" ARM void func_ov002_021561b0(struct Loader_021561b0* self) {
    unsigned int flags = self->sub.flags;
    if ((flags & 2) == 0) {
        return;
    }
    unsigned char state = self->sub.state;
    if (state == 0) {
        FontBankLoader* g = GetGlobal02109400();
        func_02094ab0(g);
        BlankFunction02094b3c(g, 0xc);
        BlankFunction02094b34(g, 0x64, 0x208, 0, 0);
        self->sub.state = self->sub.state + 1;
        return;
    }
    if (state != 1) {
        return;
    }
    if (!AlwaysTrue02094b4c(GetGlobal02109400())) {
        return;
    }
    self->sub.flags = self->sub.flags & ~2;
    self->sub.state = 0;
}
