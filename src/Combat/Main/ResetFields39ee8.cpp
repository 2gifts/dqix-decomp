#include <globaldefs.h>

struct ResetStruct_39ee8 {
    unsigned short f0;
    char pad2[3];
    unsigned char f5;
    unsigned char f6;
    unsigned char f7;
    unsigned short f8;
};

// USA: func_02039ee8
ARM void ResetFields39ee8_02039ee8(struct ResetStruct_39ee8* s) {
    s->f0 = 0;
    s->f5 = 0;
    s->f6 = 0;
    s->f8 = 0;
    s->f7 = 0;
}
