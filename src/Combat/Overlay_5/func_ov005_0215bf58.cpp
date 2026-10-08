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

struct MemberScreen
{
    char unk_0[0x4fc];
    int member_;
};

struct GameResources
{
    char unk_0[0x3708];
    int* unknown_ptr_3708;
};

struct Container020dedd0;
struct Element020de650;

struct EquipmentSlot
{
    short item_;
    char unk_2[0x1c - 2];
};

struct EquipmentMenu
{
    char unk_0[0xdf4];
    Container020dedd0* items_;
    char unk_df8[0x19b8 - 0xdf8];
    unsigned short infoFlags_;
    char unk_19ba[0x2d90 - 0x19ba];
    EquipmentSlot slots_[24];
    char unk_3030[0x3dbb - 0x3030];
    signed char slot_;
};

extern "C" void func_ov005_021562b8(EquipmentMenu* self);
extern "C" void func_ov005_0215730c(EquipmentMenu* self);
extern "C" GameResources* func_ov017_0218b5b0(void);
extern "C" MemberScreen* _Z19GetField1c_021a193cPi(int* obj);
extern "C" Element020de650* _Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0* c, int key);
extern "C" int func_020dd4c4(signed char member, Element020de650* entry);
extern "C" void _Z28DispatchByIdxAndCond021551fcPchi(EquipmentMenu* self, int member, int change);

extern "C" TouchState data_02114e54;

// USA: func_ov005_0215bf58
extern "C" ARM void func_ov005_0215bf58(EquipmentMenu* self)
{
    int touched = 0;
    if (data_02114e54.touching_ || (data_02114e54.unk_5f != 0 && data_02114e54.unk_24 != 0) ||
        data_02114e54.unk_54 != 0)
    {
        func_ov005_021562b8(self);
        touched = 1;
    }
    if (!touched)
        func_ov005_0215730c(self);
    int member = _Z19GetField1c_021a193cPi(func_ov017_0218b5b0()->unknown_ptr_3708)->member_;
    Element020de650* entry = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->items_, self->slots_[self->slot_].item_);
    if (entry != NULL)
    {
        if (func_020dd4c4(member, entry))
            self->infoFlags_ |= 0x100;
        else
            self->infoFlags_ &= ~0x100;
    }
    _Z28DispatchByIdxAndCond021551fcPchi(self, member, 0);
}
