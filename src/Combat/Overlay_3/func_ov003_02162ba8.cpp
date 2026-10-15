#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/CombatantRecovery.h"

struct StatusOwner02081198;
struct StatusOwner02081164;
struct Obj0208203c;
struct Obj0205eaa0;
struct Cont0207fe44;

struct Sub64 {
    unsigned char pad[0x400];
    unsigned int f400;
};
struct SelfT {
    unsigned char pad[0x64];
    Sub64 cont;
};
struct Obj150 {
    unsigned char pad[0x56b];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

static inline void SetF400(Sub64 *p) {
    p->f400 |= 0x800000;
}

void SetEntryNibbleByShortId(StatusOwner02081198 *, int, int);
void SetEntryFlag0x2ByShortId(StatusOwner02081164 *, int, int);
extern "C" void func_020813ec(void *, int);
int FindMappedMemberId02080468(void *, int);
void ResetWithSub0208203c(Obj0208203c *);
extern "C" void func_ov003_02165888(unsigned char *, int);
extern "C" void func_ov003_02160794(unsigned char *);
extern "C" int func_ov003_02160854(unsigned char *);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0 *, int, int);
int CountFlaggedCombatants_02161544(void *);
void CallFunc0204c804OverAllElems(Cont0207fe44 *);
extern "C" int func_ov003_02160a68(unsigned char *);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *);
extern "C" void func_ov003_02161480(unsigned char *);
extern "C" void func_ov003_02166f40(unsigned char *);

extern int data_02108760;

// USA: func_ov003_02162ba8
extern "C" ARM void func_ov003_02162ba8(unsigned char *self) {
    GameState *gs       = GameState::GetInstance();
    unsigned char state = self[0x4a4];
    void *r4            = *(void **) (self + 0x324);
    short *sp           = (short *) (self + 0x84 + 0x400);

    if (state == 0) {
        *(short *) (self + 0x482) = -1;
        *(short *) (self + 0x488) = 0x13;
        SetEntryNibbleByShortId((StatusOwner02081198 *) r4, 0x12, 1);
        SetEntryFlag0x2ByShortId((StatusOwner02081164 *) r4, 0x12, 1);
        func_020813ec(r4, 0x12);
        *(short *) (self + 0x48e)                = FindMappedMemberId02080468(r4, *(short *) (self + 0x488));
        *(short *) (self + 0x474)                = *(short *) (self + 0x48e);
        *(short *) ((unsigned char *) r4 + 0x36) = *(short *) (self + 0x48e);
        ResetWithSub0208203c((Obj0208203c *) (self + 0x308));
        *(int *) (self + 0x470) = 0;
        func_ov003_02165888(self, 1);
        *(unsigned int *) (self + 0x464) |= 0x580000;
        if (*(unsigned int *) (self + 0x464) & 1) {
            ((SelfT *) self)->cont.f400 |= 0x800000;
        }
        self[0x4a4]++;
    } else if (state == 1) {
        func_ov003_02160794(self);
        *(short **) (self + 0x470) = (short *) (self + 0x8e + 0x400);
        if (*(unsigned int *) (self + 0x464) & 0x1000000) {
            *(unsigned int *) (self + 0x464) |= 0x580000;
            if (*(unsigned int *) (self + 0x464) & 1) {
                ((SelfT *) self)->cont.f400 |= 0x800000;
            }
            func_ov003_02165888(self, 1);
        }
        if (func_ov003_02160854(self) != 0) {
            short idx = *(short *) (self + 0x48e) - FindMappedMemberId02080468(r4, *(short *) (self + 0x488));
            if (self[0x4ad] <= idx) return;
            *(short *) (self + 0x482) = (self + idx)[0x4a9];
            DispatchWithShortB4_0205eaa0((Obj0205eaa0 *) &data_02108760, 1, 0);
            ResetWithSub0208203c((Obj0208203c *) (self + 0x308));
            *(int *) (self + 0x470) = 0;
            if (CountFlaggedCombatants_02161544(self) == 0) {
                CallFunc0204c804OverAllElems((Cont0207fe44 *) r4);
                *(unsigned int *) (self + 0x464) |= 0x80000;
                sp[0]       = 0x49;
                sp[1]       = 2;
                self[0x4a3] = 1;
                self[0x4a4] = 0;
            } else {
                CallFunc0204c804OverAllElems((Cont0207fe44 *) r4);
                *(unsigned int *) (self + 0x464) |= 0x80000;
                self[0x4a4]++;
            }
        } else {
            if (func_ov003_02160a68(self) == 0) return;
            ResetWithSub0208203c((Obj0208203c *) (self + 0x308));
            *(int *) (self + 0x470) = 0;
            CallFunc0204c804OverAllElems((Cont0207fe44 *) r4);
            *(unsigned int *) (self + 0x464) |= 0x80000;
            sp[0]       = 2;
            self[0x4a3] = 1;
            self[0x4a4] = 0;
        }
    } else if (state == 2) {
        unsigned char saved = self[0x4a3];
        self[0x4a3]         = 0x10;
        GameObject *c       = GetCombatantWithFlag0x100_0200ff1c(gs, *(short *) (self + 0x482));
        if (c == 0) return;
        unsigned char *o = GetFieldAt0x150_02053c6c((unsigned char *) c);
        self[0x4a3]      = saved;
        int f            = (*(short *) (o + 0x454) > 0);
        if (c->combatFields_.savedState_130_->flags & 1) {
            sp[0]       = 0xc;
            sp[1]       = 2;
            self[0x4a3] = 1;
            self[0x4a4] = 0;
        } else {
            int n = ((Obj150 *) o)->hi;
            if (n == 2 || n == 4) {
                sp[0] = 0x54;
                if (f != 0) sp[1] = 0xe;
                self[0x4a4] = 5;
            } else if (n == 3) {
                sp[0] = 0x55;
                if (f != 0) sp[1] = 0x1f;
                self[0x4a4] = 5;
            } else {
                sp[0]       = 0xb;
                self[0x4a3] = 8;
                self[0x4a4] = 0;
                func_ov003_02161480(self);
                *(unsigned int *) (self + 0x464) |= 0x202;
            }
        }
        *(unsigned int *) (self + 0x464) |= 0x10;
    } else if (state == 5) {
        func_ov003_02161480(self);
        func_ov003_02166f40(self);
        sp[0]       = 2;
        self[0x4a3] = 1;
        self[0x4a4] = 0;
    }
}
