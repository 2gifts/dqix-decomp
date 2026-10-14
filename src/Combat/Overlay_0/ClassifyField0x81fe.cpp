#include <globaldefs.h>

struct SubObj0215fc60 { char pad[0xfe]; unsigned short val; };

// USA: func_ov000_0215fc60
ARM int ClassifyField0x81fe_ov000_0215fc60(char* base) {
    unsigned short v = ((struct SubObj0215fc60*)(base + 0x8100))->val;
    if (v == 0x320) return 1;
    if (v == 0x321) return 2;
    return 0;
}
