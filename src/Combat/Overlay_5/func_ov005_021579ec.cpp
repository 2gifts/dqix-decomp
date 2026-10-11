#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cbd4 data_ov005_0215dfb4
#define data_ov005_0215cd60 data_ov005_0215e140
#define data_ov014_02189480 data_ov014_0218a2c0
#define data_ov014_02189498 data_ov014_0218a2d8
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194564 data_ov015_02195184
#define data_ov015_02194570 data_ov015_02195190
#define data_ov015_021945a0 data_ov015_021951c0
#define data_ov015_021945d0 data_ov015_021951f0
#define data_ov024_021ff17c data_ov023_021ff17c
#define func_ov005_02158560 func_ov005_02159b58
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct CursorFrame;

struct EquipmentMenu {
    char unk_0[R(0x19ac, 0x1a34)];
    char frame_[4];
};

extern "C" void func_ov005_02154d18(CursorFrame* frame, int x, int y);
extern "C" void func_ov005_02154d50(CursorFrame* frame, int width, int height);
extern "C" void func_ov005_021553b4(EquipmentMenu* self, int slot, int* x, int* y);

// USA: func_ov005_021579ec
extern "C" ARM void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot) {
    int x = 0;
    int y = 0;
    switch (state) {
    case 2:
        x = slot * 16 + 0x81;
        if (slot == 7)
            x--;
        func_ov005_02154d18((CursorFrame*)self->frame_, x << 12, 0x1000);
        func_ov005_02154d50((CursorFrame*)self->frame_, 0xf000, 0x11000);
        break;
    case 3:
        func_ov005_02154d18((CursorFrame*)self->frame_, 0x85000, 0x17000);
        func_ov005_02154d50((CursorFrame*)self->frame_, 0x76000, 0x16000);
        break;
    case 4:
    case 6:
        func_ov005_021553b4(self, slot, &x, &y);
        func_ov005_02154d18((CursorFrame*)self->frame_, x << 12, y << 12);
        func_ov005_02154d50((CursorFrame*)self->frame_, 0x18000, 0x18000);
        break;
    }
}
