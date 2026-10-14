#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Data021fff08 {
    char pad0[0x2];
    unsigned char flag;
    char pad1[0x9];
    short* field0xc;
};
extern struct Data021fff08 data_ov023_021fff08;

// USA: func_ov023_021f55b8  (semantic: SetShortIfFlagSet_021f55b8)
extern "C" ARM int func_ov023_021f55b8(struct Variant02030b0c* v) {
    if (data_ov023_021fff08.flag != 0) {
        *data_ov023_021fff08.field0xc = (short)((Script::Parameter*)v)->ToInt();
    }
    return 1;
}
