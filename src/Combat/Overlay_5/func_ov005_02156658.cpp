#include <globaldefs.h>

struct EquipmentMenu {
    char unk_0[0x3db8];
    unsigned char mode_;
    char unk_3db9[3];
    unsigned char kind_;
    char unk_3dbd[15];
    unsigned int flags_;
};

extern "C" int func_ov005_02158560(EquipmentMenu*, unsigned char, int);
extern "C" void func_ov005_0215792c(EquipmentMenu*, int);
extern "C" void func_ov005_021579ec(EquipmentMenu*, unsigned char, unsigned char);
extern "C" int func_ov005_021585fc(EquipmentMenu*, int);
extern "C" void func_ov005_021555c0(EquipmentMenu*);

// USA: func_ov005_02156658
extern "C" ARM void func_ov005_02156658(EquipmentMenu* self, int x, int y) {
    int changed = 0;
    if ((self->flags_ & 4) && y > 1 && y < 19 && x > 129 && x < 255) {
        unsigned char kind = self->kind_;
        int start = 113;
        for (int i = 0; i < 8; ++i) {
            start += 16;
            if (i == 7) --start;
            int end = start + 16;
            if (x >= start && x < end) { kind = i; break; }
        }
        self->flags_ |= 0x100;
        changed = func_ov005_02158560(self, kind, 0);
        func_ov005_0215792c(self, 2);
        func_ov005_021579ec(self, self->mode_, kind);
    }
    if ((self->flags_ & 8) && y > 157 && y < 174) {
        int direction = 0;
        if (x > 137 && x < 153) direction = -1;
        if (x > 230 && x < 246) direction = 1;
        if (direction == 0) return;
        changed = func_ov005_021585fc(self, direction);
        if (direction < 0) self->flags_ |= 0x20000;
        else self->flags_ |= 0x40000;
    }
    if (changed) func_ov005_021555c0(self);
}
