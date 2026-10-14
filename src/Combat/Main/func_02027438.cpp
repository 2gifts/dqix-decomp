#include <globaldefs.h>

class FlagWord02046708;

FlagWord02046708* GetDataPtr02114e04_020d6c00();
bool TestFlags02046708(FlagWord02046708* flags, unsigned int mask);

#define TILE_PHASE02027438(v) ((v) < 0 ? (v) % 8 + 8 : (v) % 8)

struct ScrollState02027438 {
    char pad0[0x14];
    int mode;
    char pad1[0x44 - 0x18];
    int scrollX;
    int scrollY;
};

// USA: func_02027438  (semantic: UpdateSubBG0ScrollForMode02027438)
extern "C" ARM void func_02027438(struct ScrollState02027438* state) {
    if (TestFlags02046708(GetDataPtr02114e04_020d6c00(), 0x41)) {
        return;
    }
    switch (state->mode) {
    case 0: {
        int x = state->scrollX;
        int phaseX = TILE_PHASE02027438(x);
        int y = state->scrollY;
        int phaseY = TILE_PHASE02027438(y);
        *(volatile unsigned int*)0x4001010 =
            ((phaseX + 0x80) & 0x1ff) | (((phaseY + 0x20) << 16) & 0x1ff0000);
        break;
    }
    case 2:
    case 3: {
        int y = state->scrollY;
        int phaseY = TILE_PHASE02027438(y);
        *(volatile unsigned int*)0x4001010 = ((phaseY + 0x20) << 16) & 0x1ff0000;
        break;
    }
    case 4: {
        int y = state->scrollY;
        int phaseY = TILE_PHASE02027438(y);
        *(volatile unsigned int*)0x4001010 = ((0x20 - phaseY) << 16) & 0x1ff0000;
        break;
    }
    default:
        *(volatile unsigned int*)0x4001010 = 0;
        break;
    }
}
