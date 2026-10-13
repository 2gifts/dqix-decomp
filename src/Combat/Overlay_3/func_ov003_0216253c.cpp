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
    char pad476[0x480 - 0x476];
    short h480;
    char pad482[0x484 - 0x482];
    short h484;
    short h486;
    short h488;
    char pad48a[0x48c - 0x48a];
    short h48c;
    char pad48e[0x49f - 0x48e];
    signed char c49f;
    char pad4a0[0x4a3 - 0x4a0];
    unsigned char c4a3;
    unsigned char state;
};

struct Elem {
    signed char v : 6;
    char pad1[0x13f - 1];
    unsigned char m : 3;
};

extern int data_02108760;
extern "C" unsigned int *_Z27GetDataPtr02114e04_020d6c00v();
extern "C" void _Z23SetEntryNibbleByShortIdP19StatusOwner02081198ii(void *, int, int);
extern "C" void _Z24SetEntryFlag0x2ByShortIdP19StatusOwner02081164ii(void *, int, int);
extern "C" void func_020813ec(void *, int);
extern "C" void func_ov003_02165c9c(Scene *);
extern "C" void _Z20ResetWithSub0208203cP11Obj0208203c(void *);
extern "C" int _Z26FindMappedMemberId02080468Pvi(void *, int);
extern "C" void _Z16OrBitsIntoField0Pjj(unsigned int *, unsigned int);
extern "C" void func_ov003_02165bd8(Scene *);
extern "C" void _Z26ApplyElementEffect02161438Pv(Scene *);
extern "C" int func_ov003_02160854(Scene *);
extern "C" unsigned char *_Z17GetPtrField0x2a04P9GameState(GameState *);
extern "C" int _Z25CompareThreshold_021614e8i(int);
struct Obj0205eaa0;
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0 *, int, int);
extern "C" void _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(void *);
extern "C" Elem *_Z35GetElementAtIndex_02160bd0_02160bd0Pvi(Scene *, int);
extern "C" int *func_0202ae18();
extern "C" int _Z18CheckField0NonZeroPi(int *);
extern "C" int func_0202c508(int *);
extern "C" void _Z21ClearFlag320_02195540Ph(unsigned char *);
extern "C" int _Z39CountValidCombatantsMinusField_02160b84v(Scene *);
extern "C" int func_ov003_02160a68(Scene *);
extern "C" void func_ov003_021612c0(Scene *);
extern "C" int func_ov003_02161344(Scene *);
extern "C" void func_ov003_02161480(Scene *);
extern "C" int func_ov003_021669f0(Scene *);

// USA: func_ov003_0216253c
extern "C" ARM void func_ov003_0216253c(Scene *self) {
    Entries *entries    = self->entries;
    unsigned int *data  = _Z27GetDataPtr02114e04_020d6c00v();
    unsigned char state = self->state;

    if (state == 0) {
        self->h480   = -1;
        self->c49f   = 0;
        self->h488   = 6;
        self->h48c   = -1;
        self->h474   = self->h48c;
        entries->sel = self->h48c;
        _Z23SetEntryNibbleByShortIdP19StatusOwner02081198ii(entries, 0x15, 1);
        _Z24SetEntryFlag0x2ByShortIdP19StatusOwner02081164ii(entries, 0x15, 1);
        func_020813ec(entries, 0x15);
        func_ov003_02165c9c(self);
        _Z20ResetWithSub0208203cP11Obj0208203c(self->sub308);
        self->p470 = 0;
        self->flags |= 0x780000;
        if (self->flags & 1) {
            self->flags |= 0x800000;
        }
        self->state = self->state + 1;
    } else if (state == 1) {
        self->h484 = 0x48;
        self->flags |= 2;
        self->state = 4;
    } else if (state == 4) {
        self->h480   = -1;
        self->c49f   = 0;
        self->h488   = 6;
        self->h48c   = _Z26FindMappedMemberId02080468Pvi(entries, self->h488);
        self->h474   = self->h48c;
        entries->sel = self->h48c;
        _Z23SetEntryNibbleByShortIdP19StatusOwner02081198ii(entries, 0x15, 1);
        _Z24SetEntryFlag0x2ByShortIdP19StatusOwner02081164ii(entries, 0x15, 1);
        func_020813ec(entries, 0x15);
        func_ov003_02165c9c(self);
        self->flags |= 0x780000;
        if (self->flags & 1) {
            self->flags |= 0x800000;
        }
        _Z20ResetWithSub0208203cP11Obj0208203c(self->sub308);
        self->p470  = 0;
        self->state = self->state + 1;
        _Z16OrBitsIntoField0Pjj(data, 0x40);
        self->flags |= 0x400;
    } else if (state == 5) {
        self->p470 = &self->h48c;
        self->flags |= 1;
        func_ov003_02165bd8(self);
        if (self->flags & 0x1000000) {
            self->flags |= 0x780000;
            if (self->flags & 1) {
                self->flags |= 0x800000;
            }
        }
        int idx = self->h48c - 0x15 + self->c49f * 4;
        _Z26ApplyElementEffect02161438Pv(self);
        if (func_ov003_02160854(self) != 0) {
            if (idx == *(_Z17GetPtrField0x2a04P9GameState(GameState::GetInstance()) + 0x2000 + 0xc8c)) {
                if (_Z25CompareThreshold_021614e8i((int) self) != 0) {
                    return;
                }
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0 *) &data_02108760, 1, 0);
                _Z20ResetWithSub0208203cP11Obj0208203c(self->sub308);
                self->p470 = 0;
                _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(entries);
                self->flags |= 0x80000;
                self->h484  = 0x4d;
                self->state = 100;
                self->flags |= 0x800;
            }
            Elem *elem = _Z35GetElementAtIndex_02160bd0_02160bd0Pvi(self, idx);
            if (elem == NULL) {
                return;
            }
            int v = elem->v;
            if (v < 0) {
                return;
            }
            self->h480 = v;
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0 *) &data_02108760, 1, 0);
            _Z20ResetWithSub0208203cP11Obj0208203c(self->sub308);
            self->p470 = 0;
            _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(entries);
            self->flags |= 0x80000;
            self->flags |= 8;
            unsigned char *g = (unsigned char *) func_ov017_0218b5b0();
            int *p           = func_0202ae18();
            if (_Z18CheckField0NonZeroPi(p) != 0 && func_0202c508(p) != 0) {
                _Z21ClearFlag320_02195540Ph(g);
            }
            int a = *(_Z17GetPtrField0x2a04P9GameState(GameState::GetInstance()) + 0xf7c);
            int n = _Z39CountValidCombatantsMinusField_02160b84v(self);
            if (a + n == 4) {
                _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(entries);
                self->flags |= 0x80000;
                self->h484  = 6;
                self->h486  = 2;
                self->c4a3  = 1;
                self->state = 0;
            } else {
                int m = elem->m;
                if (m == 2 || m == 4) {
                    self->h484  = 0x52;
                    self->state = 9;
                    self->flags |= 2;
                    self->flags |= 0x8000;
                } else if (m == 3) {
                    self->h484  = 0x53;
                    self->state = 9;
                    self->flags |= 2;
                    self->flags |= 0x8000;
                } else {
                    self->h484  = 0x3d;
                    self->state = 8;
                    self->flags |= 2;
                    self->flags |= 0x8000;
                }
            }
            self->flags |= 0x800;
        } else {
            if (func_ov003_02160a68(self) == 0) {
                return;
            }
            _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(entries);
            self->flags |= 0x80000;
            self->h484  = 2;
            self->c4a3  = 1;
            self->state = 0;
            self->flags |= 0x800;
        }
    } else if (state == 6) {
        func_ov003_021612c0(self);
        self->state = self->state + 1;
    } else if (state == 7) {
        int r = func_ov003_02161344(self);
        if (r != -1) {
            if (r == 1) {
                self->h484  = 7;
                self->c4a3  = 3;
                self->state = 0;
                self->flags |= 0x100;
            }
        } else {
            self->h480  = -1;
            self->h484  = 4;
            self->state = 4;
            self->flags &= ~8;
        }
    } else if (state == 8) {
        func_ov003_02161480(self);
        self->state = 10;
    } else if (state == 9) {
        func_ov003_02161480(self);
        self->state = 11;
    } else if (state == 10) {
        if (func_ov003_021669f0(self) != 0) {
            self->c4a3  = 7;
            self->state = 0;
        }
    } else if (state == 11) {
        if (func_ov003_021669f0(self) != 0) {
            self->c4a3  = 1;
            self->h484  = 2;
            self->state = 0;
        }
    } else if (state == 100) {
        func_ov003_021612c0(self);
        self->state = self->state + 1;
    } else if (state == 101) {
        int r = func_ov003_02161344(self);
        if (r != -1) {
            if (r == 1) {
                self->h484  = 0x4e;
                self->c4a3  = 4;
                self->state = 0;
                self->flags |= 2;
            }
        } else {
            if (*(_Z17GetPtrField0x2a04P9GameState(GameState::GetInstance()) + 0x2000 + 0xc8c) == 0) {
                self->state = 0;
            } else {
                self->h484  = 4;
                self->state = 4;
            }
        }
    }
}
