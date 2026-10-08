#include <globaldefs.h>

struct EquipmentMenu {
    char unk_0[0x3dbc];
    unsigned char kind_;
    char unk_3dbd[0x3dcc - 0x3dbd];
    unsigned int flags_;
    char unk_3dd0[0x3df4 - 0x3dd0];
    unsigned char pageCounts_[8];
};

struct MenuContext {
    char unk_0[0x3708];
    int* unknown_ptr_3708;
};

extern "C" MenuContext* func_ov017_0218b5b0();
extern "C" void* _Z19GetField1c_021a193cPi(int* p);
extern "C" void _Z37SetShiftedFieldsAndCallTwice_021e31e4Pviiis(void* self, int leftX, int leftY, int rightX, short rightY);

// USA: func_ov005_0215a2c8
extern "C" ARM void func_ov005_0215a2c8(EquipmentMenu* self) {
    if (self->pageCounts_[self->kind_] == 1)
        return;
    short leftX = 0x8e;
    short leftY = 0xa0;
    if (self->flags_ & 0x20000) {
        leftX--;
        leftY++;
        self->flags_ &= ~0x20000;
    }
    short rightX = 0xeb;
    short rightY = 0xa0;
    if (self->flags_ & 0x40000) {
        rightX++;
        rightY++;
        self->flags_ &= ~0x40000;
    }
    _Z37SetShiftedFieldsAndCallTwice_021e31e4Pviiis(_Z19GetField1c_021a193cPi(func_ov017_0218b5b0()->unknown_ptr_3708), leftX, leftY, rightX, rightY);
}
