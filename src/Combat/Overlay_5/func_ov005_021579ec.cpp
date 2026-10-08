#include <globaldefs.h>

struct CursorFrame;

struct EquipmentMenu {
    char unk_0[0x1a34];
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
