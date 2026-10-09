#include <globaldefs.h>

struct Owner_021931cc {};
struct Struct021931b4 : Owner_021931cc {
    char pad0[0x34];
    int selection;
    signed char mode;
    char pad39[0x194-0x39];
    int current;
    int previous;
    char pad19c[8];
    int state;
    char pad1a8[0x268-0x1a8];
    short indices[0x2e];
    int cursor;
};
struct MenuEntry { char pad[0xb]; unsigned char state; };
extern "C" int func_ov015_021925a8(Struct021931b4*);
extern "C" void func_ov015_02191874(Struct021931b4*);
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
extern unsigned short data_02114e30;
extern "C" int func_ov015_02191284(int*);
extern "C" void func_ov015_02191ea4(Struct021931b4*, int);
extern "C" void func_ov015_02191f04(Struct021931b4*);
extern "C" void func_ov015_02192064(Struct021931b4*, int);
extern "C" MenuEntry* func_ov015_02193160(Struct021931b4*, int, int*);
extern "C" void _Z22PushArrayValue021931b4P14Struct021931b4i(Struct021931b4*, int);
extern "C" int _Z11Pop021931ccP14Owner_021931cc(Owner_021931cc*);
extern "C" void func_ov015_02192700(Struct021931b4*, int);

// USA: func_ov015_02191668
extern "C" ARM void func_ov015_02191668(Struct021931b4* self) {
    if (func_ov015_021925a8(self)) return;
    if (self->state == 0x27) func_ov015_02191874(self);
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 1)) {
        int index = func_ov015_02191284(&self->cursor);
        self->indices[self->state] = index;
        switch (self->state) {
        case 0x24: func_ov015_02191ea4(self, index); break;
        case 0x26: func_ov015_02191f04(self); break;
        case 0x25: func_ov015_02192064(self, index); break;
        case 0x27: break;
        default:
            int start = 0;
            func_ov015_02193160(self, self->state, &start);
            index += start;
            MenuEntry* entry = func_ov015_02193160(self, self->state, &index);
            if (entry->state) {
                _Z22PushArrayValue021931b4P14Struct021931b4i(self, self->state);
                self->state = entry->state;
                func_ov015_02192700(self, 0);
            }
            break;
        }
    } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) {
        if (self->state > 0x23) {
            self->indices[self->state] = func_ov015_02191284(&self->cursor);
            self->state = _Z11Pop021931ccP14Owner_021931cc(self);
            func_ov015_02192700(self, 0);
        } else {
            int previous = self->current;
            self->current = self->previous;
            self->previous = previous;
            int state;
            do { state = _Z11Pop021931ccP14Owner_021931cc(self); } while (state >= 0x23);
            if (self->mode >= 0) {
                switch (self->mode) {
                case 0: case 1:
                    while (state >= 0xf) state = _Z11Pop021931ccP14Owner_021931cc(self);
                    break;
                case 2:
                    while (state >= 0x21) state = _Z11Pop021931ccP14Owner_021931cc(self);
                    break;
                }
                self->mode = -1;
                if (self->current == 1) self->current = 0;
            }
            self->state = state;
            func_ov015_02192700(self, 0);
            self->selection = 0;
        }
    }
}
