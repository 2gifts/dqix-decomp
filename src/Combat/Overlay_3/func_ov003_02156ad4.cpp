#include <globaldefs.h>

extern "C" {
void* _ZN9GameState11GetInstanceEv(void);
int _Z26FindMappedMemberId02080468Pvi(void*, int);
void func_020813ec(void*, int);
void _Z20ResetWithSub0208203cP11Obj0208203c(void*);
int func_ov003_021550dc(void*);
void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(void*, int, int);
int _Z18GetField0x3acValueP9GameState(void*);
int _Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(void*, int);
void _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(void*);
void* _Z17GetPtrField0x2a04P9GameState(void*);
void* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
int _Z13GetTableValuePv(void*);
int func_ov003_02155208(void*);
}

extern char data_02108760[];

struct ModeArgs02156ad4 {
    short cmd;
    short arg;
};

struct Ctrl02156ad4 {
    char pad00[8];
    void* f08;
    char pad0c[0xc];
    void* f18;
    char pad1c[0x80 - 0x1c];
    char sub80[0x80];
    char pad100[0x1e0 - 0x100];
    short f1e0;
    char pad1e2[4];
    short f1e6;
    char pad1e8[0x1ec - 0x1e8];
    struct ModeArgs02156ad4 modeArgs;
    char pad1f0[2];
    unsigned char f1f2;
    char pad1f3[4];
    char f1f7;
    unsigned char mode;
    unsigned char state;
    char pad1fa;
    unsigned char f1fb;
    unsigned int flags;
};

struct Obj02156ad4 {
    char pad0[0x36];
    short f36;
};

struct Q02156ad4 {
    char pad0[0xf78];
    unsigned char f78[4];
    unsigned char f7c;
};

// USA: func_ov003_02156ad4
extern "C" ARM void func_ov003_02156ad4(struct Ctrl02156ad4* self) {
    struct Obj02156ad4* p = (struct Obj02156ad4*)self->f18;
    struct ModeArgs02156ad4* modeArgs = &self->modeArgs;
    int i;
    if (self->state == 0) {
        self->f1e6 = 2;
        if (self->f1e0 < 0) {
            self->f1e0 = _Z26FindMappedMemberId02080468Pvi(p, self->f1e6);
        }
        p->f36 = self->f1e0;
        func_020813ec(p, self->f1e6);
        _Z20ResetWithSub0208203cP11Obj0208203c(self->sub80);
        self->f08 = 0;
        self->state = self->state + 1;
        return;
    }
    if (self->state != 1) {
        return;
    }
    self->f08 = &self->f1e0;
    if (func_ov003_021550dc(self) != 0) {
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(data_02108760, 1, 0);
        _Z20ResetWithSub0208203cP11Obj0208203c(self->sub80);
        self->f08 = 0;
        void* gs = _ZN9GameState11GetInstanceEv();
        switch (self->f1e0) {
        case 8:
            if (self->f1fb == 0) {
                self->f1f7 = _Z18GetField0x3acValueP9GameState(gs);
                self->state = 0;
                if (_Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(self, self->f1f7)) {
                    modeArgs->cmd = 8;
                    self->mode = 7;
                    _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(p);
                    return;
                }
                self->flags = self->flags | 2;
                modeArgs->cmd = 9;
                self->mode = 3;
                self->state = 0;
            } else {
                self->f1f7 = self->f1f2;
                modeArgs->cmd = 6;
                self->mode = 2;
                self->state = 2;
            }
            break;
        case 9: {
            unsigned char st;
            if (self->f1fb == 0) {
                self->f1f7 = _Z18GetField0x3acValueP9GameState(gs);
                modeArgs->cmd = 0xe;
                self->mode = 4;
                st = 2;
            } else {
                modeArgs->cmd = 0xe;
                modeArgs->arg = 0xf;
                self->mode = 4;
                st = 0;
            }
            self->state = st;
            unsigned char count;
            struct Q02156ad4* q;
            void* gs2 = _ZN9GameState11GetInstanceEv();
            q = (struct Q02156ad4*)_Z17GetPtrField0x2a04P9GameState(gs2);
            count = q->f7c;
            int found;
            for (i = 0; i < count; i++) {
                void* m = _ZN9GameState21GetPartyMemberByIndexEi(gs2, q->f78[i]);
                if (m != 0 && _Z13GetTableValuePv(m) == 0x63) {
                    found = 1;
                    goto found_done;
                }
            }
            found = 0;
        found_done:
            if (found == 0) {
                modeArgs->arg = 0x42;
                self->mode = 7;
            }
            break;
        }
        default:
            break;
        }
        _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(p);
    } else {
        if (func_ov003_02155208(self) != 0) {
            self->f08 = 0;
            _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(p);
            modeArgs->cmd = 5;
            self->mode = 7;
        }
    }
}
