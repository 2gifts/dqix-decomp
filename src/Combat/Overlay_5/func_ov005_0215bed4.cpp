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

struct EquipmentMenu;

extern "C" void func_ov005_021562b8(EquipmentMenu* self);
extern "C" void func_ov005_0215730c(EquipmentMenu* self);
extern "C" GameResources* func_ov017_0218b5b0(void);
extern "C" MemberScreen* _Z19GetField1c_021a193cPi(int* obj);
extern "C" void _Z28DispatchByIdxAndCond021551fcPchi(EquipmentMenu* self, int member, int change);

extern "C" TouchState data_02114e54;

// USA: func_ov005_0215bed4
extern "C" ARM void func_ov005_0215bed4(EquipmentMenu* self)
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
    _Z28DispatchByIdxAndCond021551fcPchi(self,_Z19GetField1c_021a193cPi(func_ov017_0218b5b0()->unknown_ptr_3708)->member_, 0);
}
