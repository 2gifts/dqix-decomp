#include <globaldefs.h>

struct ThreeByteStruct {
    char pad[0x224];
    unsigned char f224;
    unsigned char f225;
    unsigned char f226;
};

// USA: func_020966cc
ARM void ClearThreeBytes_020966cc(struct ThreeByteStruct* s) {
    s->f224 = 0;
    s->f225 = 0;
    s->f226 = 0;
}
