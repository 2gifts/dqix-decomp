#include <globaldefs.h>
#include "World/ZoneFeatures.h"

struct Struct0201ce10 {
    int f00;
    int pad04[6];
    int f1c;
    int f20[12];
    short f50;
    short f52;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
};

// USA: func_0201ce10
ARM void ZoneFeatures::Opcode68Entry::Reset() {
    struct Struct0201ce10* p = (struct Struct0201ce10*)this;
    p->f00 = 0;
    p->f1c = -1;
    p->f50 = 0;
    p->f52 = 0;
    p->f54 = 0;
    p->f64 = 0;
    p->f68 = 0;
    p->f58 = 0;
    p->f5c = 0;
    p->f60 = 0;
    p->f20[0] = 0;
    p->f20[1] = 0;
    p->f20[2] = 0;
    p->f20[3] = 0;
    p->f20[4] = 0;
    p->f20[5] = 0;
    p->f20[6] = 0;
    p->f20[7] = 0;
    p->f20[8] = 0;
    p->f20[9] = 0;
    p->f20[10] = 0;
    p->f20[11] = 0;
    p->f6c = -1;
}
