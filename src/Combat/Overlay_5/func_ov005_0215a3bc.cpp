#include <globaldefs.h>
#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif


#if defined(jpn)
#define func_ov005_0215a3bc func_ov005_0215b910
#endif

struct EquipmentMenu {
    char unknown_0[R(0x3d44, 0x3dcc)];
    unsigned int flags_;
};

struct MenuContext {
    char unknown_0[R(0x34f8, 0x3708)];
    int* unknown_ptr_3708;
};

extern "C" MenuContext* func_ov017_0218b5b0();
extern "C" void* _Z19GetField1c_021a193cPi(int* p);
extern "C" void _Z32SetShiftedFieldsAndCall_021e32ccPvii(void* self, int x, int y);

// USA: func_ov005_0215a3bc
extern "C" ARM void func_ov005_0215a3bc(EquipmentMenu* self) {
    short x = R(0x81, 0x80);
    short y = R(0xb4, 0xb0);
    if (self->flags_ & 0x80000) {
        x++;
        y++;
        self->flags_ &= ~0x80000;
    }
    _Z32SetShiftedFieldsAndCall_021e32ccPvii(_Z19GetField1c_021a193cPi(func_ov017_0218b5b0()->unknown_ptr_3708), x, y);
}
