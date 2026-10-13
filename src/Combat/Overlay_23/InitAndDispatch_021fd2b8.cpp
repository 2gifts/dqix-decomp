#include <globaldefs.h>
#include "Resource/FontBankLoader.h"



struct S_021fd2b8 {
    char pad0[0x20];
    int f20;
    int f24;
    unsigned char f28;
    unsigned char f29;
};

// USA: func_ov023_021fd2b8
ARM int InitAndDispatch_021fd2b8(struct S_021fd2b8* s) {
    FontBankLoader* val = GetGlobal02109400();
    func_02094ab0(val);
    BlankFunction02094b40(val);
    BlankFunction02094b34(val, s->f20, s->f24, s->f28, s->f29);
    return 1;
}
