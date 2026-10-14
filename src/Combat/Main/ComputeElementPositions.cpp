#include <globaldefs.h>

struct Wf11SubData {
    char unk[0x38];
    unsigned char fieldX;
    unsigned char fieldY;
};

struct Wf11Outer {
    int unk0;
    struct Wf11SubData* sub;
};

// USA: func_020e1e24
ARM void ComputeElementPositions_020e1e24(struct Wf11Outer* obj, unsigned short* outX, unsigned short* outY, int index) {
    *outX = obj->sub->fieldX + 0xc;
    *outY = obj->sub->fieldY + 8 + (index << 4);
}
