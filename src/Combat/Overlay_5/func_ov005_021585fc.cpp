#include <globaldefs.h>

struct EquipmentMenu {
    char unk_0[0x3daa];
    unsigned char pageStep_;
    char unk_3dab[0x3dbc - 0x3dab];
    unsigned char kind_;
    signed char page_;
    unsigned char unk_3dbe;
    signed char lastPage_;
    char unk_3dc0[0x3dcc - 0x3dc0];
    unsigned int flags_;
    char unk_3dd0[0x3df4 - 0x3dd0];
    unsigned char pageCounts_[8];
};

struct Obj0205eaa0;

extern "C" char data_02108760[];

extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* sound, int effect, int unk);

// USA: func_ov005_021585fc
extern "C" ARM int func_ov005_021585fc(EquipmentMenu* self, int direction) {
    unsigned char last = self->pageCounts_[self->kind_] - 1;
    signed char page = self->page_;
    signed char next = page + direction;
    if (next < 0)
        next = last;
    if (next > last)
        next = 0;
    int changed = 1;
    if (next == page)
        changed = 0;
    if (changed) {
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
        if (direction < 0)
            self->flags_ |= 0x20000;
        else
            self->flags_ |= 0x40000;
        self->unk_3dbe = self->kind_;
        self->lastPage_ = self->page_;
        self->page_ = next;
        self->flags_ |= 0x40;
        self->pageStep_ = 0;
    }
    return changed;
}
