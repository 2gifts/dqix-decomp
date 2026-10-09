#include <globaldefs.h>

struct Struct_0205bcdc;
struct Struct_0205c4a8;
struct Struct_0205bb84;

struct Cursor0217c158 {
    char unk_0[4];
    char selection[0x50];
    int unk_54;
    char unk_58[0x68 - 0x58];
    int rows;
};

struct Combatant0217c158 {
    char unk_0[0x18];
    short hp;
};

struct Menu0217c158 {
    char unk_0[0x10];
    signed char modes[8];
    signed char depth;
    char unk_19[0x1e - 0x19];
    short field_1e;
    unsigned char field_20;
    char unk_21;
    signed char field_22;
    char unk_23[0x2c - 0x23];
    short field_2c;
    char unk_2e[0x38 - 0x2e];
    Cursor0217c158* cursor;
    char unk_3c[0x3f0 - 0x3c];
    Combatant0217c158* slots[0x10];
};

extern "C" int func_0205dd08(Cursor0217c158* cursor);
extern "C" void _Z33AdvanceWrappedAccumulator0205c4a8P15Struct_0205c4a8i(struct Struct_0205c4a8* s, int delta);
extern "C" int _Z24ComputeScaledSum0205bb84P15Struct_0205bb84(struct Struct_0205bb84* s);
extern "C" void _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(struct Struct_0205bcdc* s, int index);
extern "C" void func_0205bb04(void* s, int index);
extern "C" int abs(int);

// USA: func_ov000_0217c158
extern "C" ARM int func_ov000_0217c158(Menu0217c158* menu) {
    int delta;
    int index;
    signed char rows;
    short prev;
    int prevColumn;
    Cursor0217c158* cursor;

    delta = func_0205dd08(menu->cursor);
    if (delta == 0) {
        return 0;
    }
    cursor = menu->cursor;
    _Z33AdvanceWrappedAccumulator0205c4a8P15Struct_0205c4a8i((struct Struct_0205c4a8*)&cursor->unk_54, delta);
    index = _Z24ComputeScaledSum0205bb84P15Struct_0205bb84((struct Struct_0205bb84*)&cursor->unk_54);
    _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci((struct Struct_0205bcdc*)cursor->selection, index);
    switch (menu->modes[menu->depth]) {
    case 0xf:
        menu->field_20 = index;
        break;
    case 0x10:
        menu->field_1e = index;
        break;
    case 0x11: {
        prevColumn = menu->field_22 & 3;
        prev = index;
        rows = cursor->rows;
        short column = index & 3;
        if ((short)abs(column - prevColumn) == 1 && prevColumn < column) {
            if (menu->slots[index] == 0) {
                index = rows * 4;
            }
        }
        while (menu->slots[index] == 0) {
            index--;
        }
        while (menu->slots[index] != 0) {
            if (menu->slots[index]->hp > 0) {
                break;
            }
            index--;
        }
        if (prev != index) {
            _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci((struct Struct_0205bcdc*)cursor->selection, index);
            func_0205bb04(&cursor->unk_54, index);
        }
        menu->field_22 = index;
        menu->field_2c = -1;
        menu->field_22 = index;
        break;
    }
    }
    return 1;
}
