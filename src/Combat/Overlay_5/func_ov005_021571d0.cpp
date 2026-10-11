#if defined(jpn)
#define R(j,u) (j)
#define func_ov005_02158560 func_ov005_02159b58
#define func_ov005_021585fc func_ov005_02159bf4
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Node0205bacc;

struct MenuList {
    int unk_0;
    int active_;
    char unk_8[0x3c - 0x8];
    unsigned char unk_3c;
    unsigned char unk_3d;
};

struct EquipmentMenu {
    char unk_0[R(0x196c, 0x19f4)];
    MenuList cursor_;
    char unk_1a32[0x3db8 - 0x19f4 - sizeof(MenuList)];
    unsigned char state_;
    char unk_3db9[0x3dbb - 0x3db9];
    signed char slot_;
    unsigned char kind_;
};

extern "C" void _Z12Init0205bef8P15Struct_0205bef8(Struct_0205bef8* s);
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(Struct_0205ba68* s, int a, int count, int mode);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(Node0205bacc* s, int val);
extern "C" void func_0205bb04(void* s, int index);

// USA: func_ov005_021571d0
extern "C" ARM void func_ov005_021571d0(EquipmentMenu* self) {
    int cols;
    short rows;
    int mode;
    int count;
    int active;
    short index;
    unsigned char flagA;
    unsigned char flagB;
    switch (self->state_) {
    case 0:
        rows = 8;
        cols = 1;
        mode = 0;
        count = 8;
        active = 1;
        flagA = 0;
        flagB = 1;
        index = self->kind_;
        break;
    case 2:
        rows = 1;
        cols = 8;
        mode = 0;
        active = 1;
        count = 8;
        flagA = 1;
        flagB = 0;
        index = self->kind_;
        break;
    case 3:
        rows = 1;
        cols = 8;
        mode = 0;
        active = 1;
        count = 8;
        flagA = 1;
        flagB = 0;
        index = self->kind_;
        break;
    case 4:
    case 6:
        mode = 1;
        cols = 4;
        rows = 4;
        active = 1;
        flagA = 1;
        index = self->slot_ - 8;
        count = 0x10;
        flagB = 0;
        break;
    }
    _Z12Init0205bef8P15Struct_0205bef8((Struct_0205bef8*)&self->cursor_);
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((Struct_0205ba68*)&self->cursor_, cols, rows, mode);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((Node0205bacc*)&self->cursor_, count);
    self->cursor_.active_ = active;
    func_0205bb04(&self->cursor_, index);
    self->cursor_.unk_3c = flagA;
    self->cursor_.unk_3d = flagB;
}
