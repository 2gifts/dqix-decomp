#include <globaldefs.h>
#include "GameState/GameState.h"

struct Sub {
    int p0;
    int field4;
    char p8[0xc];
    int value;
    char p18[0x38];
};
struct Window {
    char p0[4];
    Sub a;
    Sub b;
};
struct Menu {
    char p0[0xc];
    short s0c;
    char p0e[2];
    signed char stack[8];
    signed char stackTop;
    signed char v19;
    signed char v1a;
    signed char v1b;
    signed char v1c;
    signed char v1d;
    short v1e;
    signed char v20;
    signed char v21;
    signed char v22;
    signed char v23;
    unsigned char flags24;
    char p25[0x30 - 0x25];
    signed char* list;
    signed char count;
    char p35[3];
    Window* window;
    char p3c[0x4c - 0x3c];
    int member;
#if defined(jpn)
    char p50[0xc6 - 0x50];
#else
    char p50[0x86 - 0x50];
#endif
    signed char total;
    char p87[0x442 - 0x87];
    signed char s442;
    char p443;
    unsigned char s444;
};
struct GlobalRoot {
#if defined(jpn)
    char p[0x1faa];
#else
    char p[0x1d72];
#endif
    unsigned short flags;
};
struct Global {
#if defined(jpn)
    GlobalRoot* root;
    int field0;
    int field4;
#else
    int field0;
    int field4;
    GlobalRoot* root;
#endif
};
struct Slots02083960;
struct Struct_0205ba68;

extern Global data_ov000_02184294;

extern "C" int _Z20CountNonZero02171698P9S02171698(Menu*);
extern "C" int _Z20CountNonZero021719c0P9S021719c0(Menu*);
GameObject* GetCombatantWithFlag0x100(GameState*, int);
int GetFieldAt0x150(unsigned char*);
int CountPositiveSlots02083960(Slots02083960*);
extern "C" void _Z25ClearChannelAFlag0205cf10Pv(Window*);
extern "C" void _Z21ClearFlagByte0205cf1cP14Struct0205cf1c(Window*);
extern "C" void _Z23SetChannelAFlag0205cef8Pv(Window*);
extern "C" void _Z23SetChannelBFlag0205cf04Pv(Window*);
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(Sub*, int, int, int);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(Sub*, int);
extern "C" void _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(Sub*, int);
extern "C" void func_0205bb04(Sub*, int);

// USA: func_ov000_0217ab8c
extern "C" ARM void func_ov000_0217ab8c(Menu* self, int arg1, int arg2) {
    int step, visible, pages, total, selected;
    Window* w;
    if (self->member < 0 || !(self->flags24 & 1) || self->s0c == 0 || (w = self->window) == 0) {
        return;
    }
    switch (self->stack[self->stackTop]) {
    case 13:
        selected = self->v1c;
        step = 2;
        visible = 3;
        pages = 1;
        total = 6;
        break;
    case 14:
        visible = 1;
        step = arg2;
        pages = visible;
        total = arg2;
        selected = self->v1d;
        break;
    case 15:
        if (_Z20CountNonZero02171698P9S02171698(self) >= 4) {
            step = 1;
            visible = 4;
            pages = (_Z20CountNonZero02171698P9S02171698(self) + 3) / 4;
        } else {
            step = 1;
            visible = _Z20CountNonZero02171698P9S02171698(self);
            pages = step;
        }
        self->v19 = w->b.value;
        total = _Z20CountNonZero02171698P9S02171698(self);
        selected = self->v20;
        if (selected < 0 || total <= selected) {
            selected = 0;
            self->v20 = 0;
        }
        break;
    case 16:
        if (_Z20CountNonZero021719c0P9S021719c0(self) >= 4) {
            step = 1;
            visible = 4;
            pages = (_Z20CountNonZero021719c0P9S021719c0(self) + 3) / 4;
        } else {
            step = 1;
            visible = _Z20CountNonZero021719c0P9S021719c0(self);
            pages = step;
        }
        self->v1a = w->b.value;
        total = _Z20CountNonZero021719c0P9S021719c0(self);
        selected = self->v1e;
        if (selected < 0 || total <= selected) {
            selected = 0;
            self->v1e = 0;
        }
        break;
    case 17: {
        GameState* gs = GameState::GetInstance();
        GameObject* unit = GetCombatantWithFlag0x100(gs, self->member);
        int field = GetFieldAt0x150((unsigned char*)unit);
        if (field != 0) {
            int n = CountPositiveSlots02083960((Slots02083960*)field);
            pages = (self->total - n + 3) / 4 + (n + 3) / 4;
            self->v1b = w->b.value;
            total = pages * 4;
            selected = self->v22;
            step = 1;
            visible = 4;
        }
        break;
    }
    case 18:
    case 19:
    case 20:
        if (self->s444 != 0) {
            for (int i = 0; i < self->count; i++) {
                if (self->s442 == self->list[i]) {
                    self->v21 = i;
                    break;
                }
            }
            self->s442 = -1;
            self->s444 = 0;
        }
        visible = self->count;
        step = 1;
        pages = step;
        total = visible;
        selected = self->v21;
        break;
    case 21:
        step = 1;
        visible = step;
        pages = step;
        total = step;
        selected = self->v23;
        break;
    default:
        _Z25ClearChannelAFlag0205cf10Pv(w);
        _Z21ClearFlagByte0205cf1cP14Struct0205cf1c(self->window);
        return;
    }
    _Z23SetChannelAFlag0205cef8Pv(self->window);
    _Z23SetChannelBFlag0205cf04Pv(self->window);
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(&w->a, step, visible, 0);
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(&w->b, step, visible, 0);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci(&w->a, total);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci(&w->b, total);
    w->a.field4 = pages;
    w->b.field4 = pages;
    _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(&w->a, selected);
    func_0205bb04(&w->b, selected);
    data_ov000_02184294.root->flags &= ~0x100;
}
