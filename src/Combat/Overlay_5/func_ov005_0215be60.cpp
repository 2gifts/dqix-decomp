#include <globaldefs.h>

struct TouchState
{
    char unk_0[0x24];
    unsigned short unk_24;
    char unk_26[0x54 - 0x26];
    unsigned char unk_54;
    unsigned char touching_;
    char unk_56[0x5f - 0x56];
    unsigned char unk_5f;
};

struct EquipmentMenu
{
    char unk_0[0x1244];
    char infoWindow_[4];
};

extern "C" void func_ov023_021dcae0(void* window, int item);
extern "C" void func_ov005_021562b8(EquipmentMenu* self);
extern "C" void func_ov005_0215730c(EquipmentMenu* self);

extern "C" TouchState data_02114e54;

// USA: func_ov005_0215be60
extern "C" ARM void func_ov005_0215be60(EquipmentMenu* self)
{
    func_ov023_021dcae0(self->infoWindow_, -1);
    int touched = 0;
    if (data_02114e54.touching_ || (data_02114e54.unk_5f != 0 && data_02114e54.unk_24 != 0) ||
        data_02114e54.unk_54 != 0)
    {
        func_ov005_021562b8(self);
        touched = 1;
    }
    if (touched)
        return;
    func_ov005_0215730c(self);
}
