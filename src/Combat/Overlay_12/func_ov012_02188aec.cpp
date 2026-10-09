#include <globaldefs.h>
#include "GameState/GameState.h"

struct Profile02188aec {
    unsigned int year : 12;
    unsigned int month : 4;
    unsigned int day : 5;
    unsigned int design : 4;
    unsigned int female : 1;
    unsigned int initialized : 1;
    unsigned int designChosen : 1;
    unsigned int remaining : 4;
};
struct Save02188aec { char field_0[0x569c]; Profile02188aec profile; };
struct Struct0205de24 { char data[0x133c - 0xac]; };
struct Struct_0205c570;
struct Obj021e6e20;
struct Obj0205eaa0;
struct Editor02188aec {
    char field_0[0xac];
    Struct0205de24 window;
    char field_133c[0x34];
    unsigned char step;
    unsigned char state;
    char field_1372[0x2e];
    unsigned char active;
    char field_13a1[0x53];
    unsigned int design;
};
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(Struct0205de24*, unsigned char, unsigned char);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(Struct_0205c570*);
extern "C" int _Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20(Obj021e6e20*);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
extern "C" void _Z22BuildMessageF_0218a974Pc(char*);
extern "C" void func_ov023_021e6e60(Editor02188aec*);
extern "C" int func_ov023_021e6de4(Editor02188aec*);
extern "C" void func_ov012_0218adac(Editor02188aec*, int, int, int);
extern "C" void func_ov012_0218930c(Editor02188aec*, int);
extern Obj0205eaa0 data_02108760;

// USA: func_ov012_02188aec
extern "C" ARM void func_ov012_02188aec(Editor02188aec* self) {
    Profile02188aec* profile = &((Save02188aec*)GameState::GetInstance())->profile;
    if (self->step == 0) {
        self->step++;
        self->step++;
        return;
    } else if (self->step == 1) {
        self->step++;
        return;
    } else if (self->step == 2) {
        self->active = 0;
        self->design = (profile->design - profile->female) / 2;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(&self->window, 0, 3);
        func_ov023_021e6e60(self);
        _Z22BuildMessageF_0218a974Pc((char*)self);
        self->step++;
        return;
    } else if (self->step == 3) {
        self->active = 1;
        int selection = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)&self->window);
        if (self->design != selection) {
            self->design = selection;
            func_ov012_0218adac(self, 0, (self->design << 1) + profile->female, 0);
        }
        int finished = 0;
        if (func_ov023_021e6de4(self)) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
            Profile02188aec* current = &((Save02188aec*)GameState::GetInstance())->profile;
            current->design = (self->design << 1) + current->female;
            current->designChosen = 1;
            finished = 1;
        } else if (_Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20((Obj021e6e20*)self)) {
            self->design = (profile->design - profile->female) / 2;
            finished = 1;
            func_ov012_0218adac(self, 0, -1, 0);
        }
        if (finished) self->step++;
        return;
    } else if (self->step == 4) {
        self->step++;
        return;
    } else if (self->step == 5) {
        self->state = 1;
        self->step = 1;
        func_ov012_0218930c(self, 1);
    }
}
