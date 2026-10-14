#include <globaldefs.h>

struct Wf11Outer;
void ComputeElementPositions_020e1e24(struct Wf11Outer* obj, unsigned short* outX, unsigned short* outY, int index);

struct AdjustedPosObj020e2604 {
    char pad0[0x10];
    struct Wf11Outer* outer;
    char index;
    char pad1[3];
    short x;
    short y;
};

// USA: func_020e2604
ARM void ComputeAdjustedElementPosition(struct AdjustedPosObj020e2604* self) {
    ComputeElementPositions_020e1e24(self->outer, (unsigned short*)&self->x, (unsigned short*)&self->y, self->index);
    self->x -= 0x10;
    self->y -= 2;
}
