#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void __clear(void* dst, unsigned int size);
extern "C" int _Z35GetCombatSignedByteAt0x2c8d02039730Pvi(void* unused, int index);
extern "C" void _Z33AppendFieldTagWithLookup_0219a544PhPcii(unsigned char* a, char* buf, int type, int value);
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
extern "C" int func_0205d0e0(void* objPtr, int val);
extern "C" void _Z27ClearFourHalfwords_0219a644Pv(unsigned char* base, int value);

struct Shorts0219a388 { short v[4]; };
struct Bytes0219a388 { unsigned char v[4]; };
struct Ints0219a388 { int v[7]; };

extern struct Shorts0219a388 data_ov017_021d6458;
extern struct Shorts0219a388 data_ov017_021d6450;
extern struct Shorts0219a388 data_ov017_021d6448;
extern struct Bytes0219a388 data_ov017_021d6444;
extern struct Ints0219a388 data_ov017_021d6484;

struct Window0219a388 {
    unsigned char pad0[0xa0];
    short x;
    short field_a2;
    short y;
    short width;
    short field_a8;
    short field_aa;
    short field_ac;
    short field_ae;
    unsigned char pad_b0;
    unsigned char type;
    unsigned char pad_b2[3];
    unsigned char field_b5;
};

// USA: func_ov017_0219a388
extern "C" ARM void func_ov017_0219a388(unsigned char* base) {
    GameState* gs = GameState::GetInstance();
    GameObject* protagonist = gs->GetProtagonist();
    struct Shorts0219a388 xs = data_ov017_021d6458;
    struct Shorts0219a388 ys = data_ov017_021d6450;
    struct Shorts0219a388 widths = data_ov017_021d6448;
    struct Bytes0219a388 types = data_ov017_021d6444;
    struct Ints0219a388 indices = data_ov017_021d6484;
    char buf[0x80];
    Window0219a388* win = *(Window0219a388**)(base + 0x3000 + 0xcb0);
    int i;

    for (i = 0; i < 4; i++) {
        win->x = xs.v[i];
        win->field_a2 = 2;
        win->y = ys.v[i];
        win->width = widths.v[i];
        win->field_a8 = 2;
        win->field_aa = 2;
        win->field_ac = 0xa;
        win->field_ae = 0xb;
        unsigned char type = types.v[i];
        win->type = type;
        win->field_b5 = 1;
        __clear(buf, 0x80);
        _Z33AppendFieldTagWithLookup_0219a544PhPcii(base, buf, type, (signed char)_Z35GetCombatSignedByteAt0x2c8d02039730Pvi(protagonist, indices.v[i]));
        func_0205d304(win, buf, 0, 0, 0, 1, 0, 0);
        func_0205d0e0(win, gs->GetTickCount());
    }
    _Z27ClearFourHalfwords_0219a644Pv(base, 0xff);
}
