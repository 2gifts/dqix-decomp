#include <globaldefs.h>

struct S02079ce8 {
    unsigned int f : 12;
};

// USA: func_02079ce8
// JPN: func_0207ab58
ARM int GetLow12BitsTimes8(struct S02079ce8* p) {
    return p->f * 8;
}
