#include <globaldefs.h>

extern "C" {
void *_ZN9GameState11GetInstanceEv(void);
int _Z26FindMappedMemberId02080468Pvi(void *, int);
void _Z20ResetWithSub0208203cP11Obj0208203c(void *);
int func_ov003_021550dc(void *);
void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(void *, int, int);
int _Z27GetField0x3acValue_020100a8P9GameState(void *);
int _Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(void *, int);
void _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(void *);
void *_Z26GetPtrField0x2a04_02010828P9GameState(void *);
int func_ov003_02155208(void *);
void func_ov003_02155580(void *, int);
int func_ov003_02155618(void *);
int func_ov003_02155fc0(void *, int);
void func_ov003_02158334(void *);
}

extern char data_02108760[];

struct Obj02156d40 {
#if defined(jpn)
    char pad0[0x2a];
#else
    char pad0[0x36];
#endif
    short f36;
};

struct Q02156d40 {
    char pad0[0xf7c];
    unsigned char f7c;
};

struct Ctrl02156d40 {
    char pad00[8];
    void *f08;
    char pad0c[0xc];
    void *f18;
    char pad1c[0x80 - 0x1c];
    char sub80[0x80];
#if defined(jpn)
    char pad100[0x1de - 0x100];
#else
    char pad100[0x1e2 - 0x100];
#endif
    short f1e2;
    char pad1e4[2];
    short f1e6;
    short f1e8;
    char pad1ea[2];
    short cmd;
    char pad1ee[4];
    unsigned char f1f2[5];
    char f1f7;
    unsigned char mode;
    unsigned char state;
    char pad1fa;
    unsigned char f1fb;
    unsigned int flags;
};

// USA: func_ov003_02156d40
extern "C" ARM void func_ov003_02156d40(struct Ctrl02156d40 *self) {
    void *gs              = _ZN9GameState11GetInstanceEv();
    struct Q02156d40 *q   = (struct Q02156d40 *) _Z26GetPtrField0x2a04_02010828P9GameState(gs);
    struct Obj02156d40 *p = (struct Obj02156d40 *) self->f18;
    if (self->state == 0) {
        func_ov003_02155580(self, 0);
        self->state = self->state + 1;
        return;
    }
    if (self->state == 1) {
        int r = func_ov003_02155618(self);
        if (r != -1) {
            if (r == 1) {
                if (self->f1fb == 0) {
                    self->f1f7  = _Z27GetField0x3acValue_020100a8P9GameState(gs);
                    self->state = 0;
                    if (_Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(self, self->f1f7)) {
                        self->cmd  = 8;
                        self->mode = 7;
                        _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(p);
                        return;
                    }
                    self->flags = self->flags | 2;
                    self->cmd   = 9;
                    self->mode  = 3;
                    self->state = 0;
                } else {
                    self->f1f7  = self->f1f2[0];
                    self->cmd   = 6;
                    self->mode  = 2;
                    self->state = self->state + 1;
                }
            }
        } else {
            self->cmd  = 3;
            self->mode = 7;
        }
        return;
    }
    if (self->state == 2) {
        self->f1e6 = 3;
        switch (q->f7c) {
            case 3: self->f1e6 = 4; break;
            case 4: self->f1e6 = 5; break;
        }
        if (self->f1e2 < 0) {
            self->f1e2 = _Z26FindMappedMemberId02080468Pvi(p, self->f1e6);
            self->f1e8 = self->f1e2;
        }
        p->f36 = self->f1e2;
        func_ov003_02158334(self);
        _Z20ResetWithSub0208203cP11Obj0208203c(self->sub80);
        self->f08   = 0;
        self->state = self->state + 1;
        return;
    }
    if (self->state != 3) {
        return;
    }
    self->f08 = &self->f1e2;
    if (func_ov003_021550dc(self) != 0) {
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(data_02108760, 1, 0);
        _Z20ResetWithSub0208203cP11Obj0208203c(self->sub80);
        self->f08  = 0;
        short d    = (short) (self->f1e2 - _Z26FindMappedMemberId02080468Pvi(p, self->f1e6));
        self->f1f7 = self->f1f2[d];
        if (func_ov003_02155fc0(self, self->f1f7) != 0) {
            self->cmd  = 0x31;
            self->mode = 7;
            _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(p);
            return;
        }
        if (_Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(self, self->f1f7)) {
            self->cmd  = 8;
            self->mode = 7;
            _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(p);
            return;
        }
        self->flags = self->flags | 2;
        self->cmd   = 9;
        self->mode  = 3;
        self->state = 0;
        _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(p);
        return;
    }
    if (func_ov003_02155208(self) == 0) {
        return;
    }
    self->f08  = 0;
    self->cmd  = 7;
    self->mode = 7;
    _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(p);
}
