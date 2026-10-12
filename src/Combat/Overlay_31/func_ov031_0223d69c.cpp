#include <globaldefs.h>

struct InputCoordinates_0223d69c {
    char padding[0x28];
    unsigned short primaryX;
    unsigned short primaryY;
    unsigned short secondaryX;
    unsigned short secondaryY;
    char padding30[8];
    unsigned char selected:1;
    unsigned char otherFlags:7;
};

struct InputState_0223d69c {
    int field0;
    InputCoordinates_0223d69c* inner;
};

struct CoordinatePair_0223d69c {
    unsigned short x;
    unsigned short y;
};

extern InputState_0223d69c data_ov031_02290d40;

// USA: func_ov031_0223d69c
extern "C" ARM int func_ov031_0223d69c(void* output) {
    unsigned short x;
    unsigned short y;
    int disabled = *(unsigned short*)0x027fffa8 & 0x8000;
    if (disabled >> 15) return 0;
    InputCoordinates_0223d69c* input = data_ov031_02290d40.inner;
    CoordinatePair_0223d69c* pair = (CoordinatePair_0223d69c*)output;
    switch (input->selected) {
    case 0: {
        x = input->secondaryX;
        y = input->secondaryY;
        pair->x = x;
        pair->y = y;
        return 0;
    }
    default: {
    x = input->primaryX;
    y = input->primaryY;
    pair->x = x;
    pair->y = y;
    return 1;
    }
    }
}
