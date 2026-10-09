#include <globaldefs.h>
#include <GameState/GameState.h>

struct Outer020e28dc;
struct Struct_0205c570;

struct MenuElement {
    char unk_0[0xac];
    short col_;
    short row_;
    char unk_b0[0xbc - 0xb0];
    short offsetX_;
    short offsetY_;
    char unk_c0[0xc4 - 0xc0];
    unsigned char kind_;
};

struct EquipmentMenu {
    char unk_0[0xe64];
    Outer020e28dc* yesNo_;
    void* yesNoState_;
    char unk_e6c[0xee4 - 0xe6c];
    char window_[0x3db8 - 0xee4];
    unsigned char state_;
    char unk_3db9[0x3dbc - 0x3db9];
    unsigned char kind_;
};

extern "C" MenuElement* _Z21FindElementForFieldB0P15Struct_0205d81c(void* window);
int GetInnerFlagBit0020e28dc(Outer020e28dc* p);
extern "C" void func_0205ae8c(void* obj);
int CheckField0x9cSetWhenField0xd4Present(unsigned char* obj);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(Struct_0205c570* window);
extern "C" void* _Z19GetField1c_021a193cPi(int* p);
extern "C" void func_ov023_021e3304(void* cursor, short x, short y);

// USA: func_ov005_0215a7ec
extern "C" ARM void func_ov005_0215a7ec(EquipmentMenu* self) {
    MenuElement* elem = _Z21FindElementForFieldB0P15Struct_0205d81c(self->window_);
    if (elem != NULL) {
        unsigned char kind = elem->kind_;
        if (self->yesNo_ != NULL && GetInnerFlagBit0020e28dc(self->yesNo_)) {
            func_0205ae8c(self->yesNoState_);
        } else if (kind == 1 && CheckField0x9cSetWhenField0xd4Present((unsigned char*)elem)) {
            short x = (short)(elem->col_ << 3) + elem->offsetX_;
            short y = (short)(elem->row_ << 3) + elem->offsetY_;
            if (kind == 2) {
                x = 0xd4;
                int sum = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)self->window_);
                if (sum == 0)
                    y = 0x57;
                else if (sum == 1)
                    y = 0x65;
            }
            func_ov023_021e3304(_Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]), x - 8, y - 2);
        }
    }
    if (self->state_ == 0) {
        short y = self->kind_ * 0x18 + 4;
        void* cursor = _Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]);
        func_ov023_021e3304(cursor, 0x74, y);
    }
}
