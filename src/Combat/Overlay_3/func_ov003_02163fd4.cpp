#include "GameState/GameState.h"
#include <globaldefs.h>

struct Entries {
    char pad0[0x36];
    short sel;
};

struct Scene {
    char pad0[0x308];
    char sub308[0x324 - 0x308];
    Entries *entries;
    char pad328[0x464 - 0x328];
    unsigned int flags;
    char pad468[0x470 - 0x468];
    short *p470;
    short h474;
    char pad476[0x484 - 0x476];
    short h484;
    short h486;
    short h488;
    short h48a;
    char pad48c[0x49e - 0x48c];
    unsigned char c49e;
    char pad49f[0x4a3 - 0x49f];
    unsigned char c4a3;
    unsigned char state;
};

extern int data_02108760;
extern "C" void func_020813ec(void *, int);
extern "C" void _Z20ResetWithSub0208203cP11Obj0208203c(void *);
extern "C" int _Z26FindMappedMemberId02080468Pvi(void *, int);
extern "C" unsigned char *_Z17GetPtrField0x2a04P9GameState(GameState *);
extern "C" char *_Z10GetWord0x0Pi(GameState *);
struct Obj0205eaa0;
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0 *, int, int);
extern "C" void _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(void *);
extern "C" int _Z39CountValidCombatantsMinusField_02160b84v(Scene *);
extern "C" int _Z34CheckField0AndBattleState_02160b50v(Scene *);
extern "C" int func_ov003_02160a68(Scene *);
extern "C" int func_ov003_02160854(Scene *);
extern "C" void _Z35SetEntryLowNibbleAndElement02080c68Pvii(void *, int, int);
extern "C" void _Z25SetOrClearFlag40_02166f80Pvii(Scene *, int, int);

// USA: func_ov003_02163fd4
extern "C" ARM void func_ov003_02163fd4(Scene *self) {
    unsigned char state = self->state;
    Entries *entries    = self->entries;

    if (state == 0) {
        _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(entries);
        int idx    = -1;
        self->c49e = _Z34CheckField0AndBattleState_02160b50v(self);
        switch (self->c49e) {
            case 0: self->h488 = 0x19; break;
            case 1:
                self->h488 = 0x1a;
                idx        = 0;
                break;
            case 2:
                self->h488 = 0x1b;
                idx        = 1;
                break;
        }
        func_020813ec(entries, idx);
        self->h48a   = _Z26FindMappedMemberId02080468Pvi(entries, self->h488);
        self->h474   = self->h48a;
        entries->sel = self->h48a;
        func_020813ec(entries, self->h488);
        _Z20ResetWithSub0208203cP11Obj0208203c(self->sub308);
        self->state = self->state + 1;
        self->flags &= ~0x300;
        *(unsigned char *) (_Z10GetWord0x0Pi(GameState::GetInstance()) + 0x4000 + 0x354) = 0xa;
    } else if (state == 1) {
        self->p470 = &self->h48a;
        _Z35SetEntryLowNibbleAndElement02080c68Pvii(entries, self->h488, 0);
        short *p = &self->h484;
        if (func_ov003_02160854(self) != 0) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0 *) &data_02108760, 1, 0);
            _Z20ResetWithSub0208203cP11Obj0208203c(self->sub308);
            self->p470 = 0;
            switch (self->h48a) {
                case 0xa6:
                    if ((int) *(_Z17GetPtrField0x2a04P9GameState(GameState::GetInstance()) + 0xf7c) > 1) {
                        p[0]        = 3;
                        p[1]        = 4;
                        self->c4a3  = 0xb;
                        self->state = 0;
                    } else {
                        _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(entries);
                        p[0]        = 3;
                        self->c4a3  = 0xb;
                        self->state = 2;
                    }
                    break;
                case 0xa7:
                    if (*(_Z17GetPtrField0x2a04P9GameState(GameState::GetInstance()) + 0xf7c) == 4) {
                        p[0] = 0x14;
                        p[1] = 1;
                    } else {
                        _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(entries);
                        self->c4a3  = 0xd;
                        self->state = 0xb;
                    }
                    break;
                case 0xa9:
                    _Z25SetOrClearFlag40_02166f80Pvii(self, self->h488, 1);
                    if (_Z39CountValidCombatantsMinusField_02160b84v(self) == 0) {
                        self->c4a3  = 0xe;
                        self->state = 0;
                    } else {
                        p[0]        = 0x1f;
                        p[1]        = 1;
                        self->state = 2;
                    }
                    break;
                case 0xaa:
                    _Z25SetOrClearFlag40_02166f80Pvii(self, self->h488, 1);
                    p[0]        = 0x11;
                    self->c4a3  = 0xc;
                    self->state = 0;
                    break;
                case 0xc0:
                case 0xc2:
                    self->flags |= 0x2000;
                    _Z25SetOrClearFlag40_02166f80Pvii(self, self->h488, 1);
                    p[0] = 0x31;
                    p[1] = 1;
                    break;
                case 0xc1:
                case 0xc3:
                    self->flags |= 0x2000;
                    _Z25SetOrClearFlag40_02166f80Pvii(self, self->h488, 1);
                    p[0] = 0x32;
                    p[1] = 1;
                    break;
                case 0xa8:
                    self->flags |= 0x2000;
                    _Z25SetOrClearFlag40_02166f80Pvii(self, self->h488, 1);
                    p[0] = 0x10;
                    p[1] = 1;
                    break;
                case 0xab:
                    self->flags |= 0x2000;
                    _Z25SetOrClearFlag40_02166f80Pvii(self, self->h488, 1);
                    p[0] = 0x1e;
                    p[1] = 1;
                    break;
                case 0xbb:
                case 0xbc:
                case 0xbd:
                    _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(entries);
                    p[0] = 0x2d;
                    break;
            }
            _Z35SetEntryLowNibbleAndElement02080c68Pvii(entries, self->h488, 1);
        } else if (func_ov003_02160a68(self) != 0) {
            _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(entries);
            p[0] = 0x2d;
        }
    } else if (state == 2) {
        _Z25SetOrClearFlag40_02166f80Pvii(self, self->h488, 0);
        self->state = 1;
    }
}
