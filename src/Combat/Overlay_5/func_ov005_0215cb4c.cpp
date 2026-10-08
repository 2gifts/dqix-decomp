#include <globaldefs.h>

struct Struct0209c830;

struct EquipmentMenu
{
    char unk_0[0x3dcc];
    unsigned int flags_;
    char unk_3dd0[0x3df3 - 0x3dd0];
    unsigned char fadeStep_;
};

extern "C" void _Z27SetValueAndActivate0209c830P14Struct0209c830t(Struct0209c830* p, unsigned short value);
extern "C" int _Z25IsAnimationActive0209ca2cPv(void* obj);

extern "C" Struct0209c830 data_02109bf4;

// USA: func_ov005_0215cb4c
extern "C" ARM int func_ov005_0215cb4c(EquipmentMenu* self)
{
    if (!(self->flags_ & 0x10000))
        return 0;
    unsigned char step = self->fadeStep_;
    if (step == 0)
    {
        _Z27SetValueAndActivate0209c830P14Struct0209c830t(&data_02109bf4, 0x3d);
        self->fadeStep_++;
    }
    if (step == 1)
    {
        if (_Z25IsAnimationActive0209ca2cPv(&data_02109bf4))
            return 1;
        self->flags_ &= ~0x10000;
        self->fadeStep_ = 0;
        return 0;
    }
    return 1;
}
