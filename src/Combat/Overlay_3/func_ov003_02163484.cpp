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
    char pad48a[0x494 - 0x48a];
    short h494;
    char pad496[0x49f - 0x496];
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
struct StatusOwner02081198;
void SetEntryNibbleByShortId(StatusOwner02081198*, int, int);
struct StatusOwner02081164;
void SetEntryFlag0x2ByShortId(StatusOwner02081164*, int, int);
extern "C" void func_020813ec(void *, int);
struct Obj0208203c;
void ResetWithSub0208203c(Obj0208203c*);
int FindMappedMemberId02080468(void *, int);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(Obj0205eaa0 *, int, int);
struct Cont0207fe44;
void CallFunc0204c804OverAllElems(Cont0207fe44*);
Elem * GetElementAtIndex_02160bd0_02160bd0(void*, int);
extern "C" int func_ov003_02160a68(Scene *);
extern "C" int func_ov003_02160854(Scene *);
extern "C" void func_ov003_021612c0(Scene *);
extern "C" int func_ov003_02161344(Scene *);
void SetOrClearFlag40_02166f80(void*, int, int);
extern "C" void func_ov003_02166220(Scene *);
extern "C" void func_ov003_02166184(Scene *);
extern "C" void func_ov003_021668fc(Scene *);

// USA: func_ov003_02163484
extern "C" ARM void func_ov003_02163484(Scene *self) {
    unsigned char state = self->state;
    Entries *entries    = self->entries;

    if (state == 0) {
        self->h480 = -1;
        self->h488 = 6;
        self->h474 = -1;
        if (self->h494 < 0) {
            self->h494 = FindMappedMemberId02080468(entries, self->h488);
        }
        entries->sel = self->h494;
        SetEntryNibbleByShortId((StatusOwner02081198*)entries, 0x18, 1);
        SetEntryFlag0x2ByShortId((StatusOwner02081164*)entries, 0x18, 1);
        func_020813ec(entries, 0x18);
        SetOrClearFlag40_02166f80(self, self->h488, 0);
        func_ov003_02166220(self);
        ResetWithSub0208203c((Obj0208203c*)self->sub308);
        self->p470 = 0;
        self->flags |= 0x780000;
        if (self->flags & 1) {
            *(unsigned int *) ((int) self + 0x64 + 0x400) |= 0x800000;
        }
        self->state = self->state + 1;
    } else if (state == 1) {
        self->p470 = &self->h494;
        self->flags |= 1;
        func_ov003_02166184(self);
        if (self->flags & 0x1000000) {
            self->flags |= 0x780000;
            if (self->flags & 1) {
                *(unsigned int *) ((int) self + 0x64 + 0x400) |= 0x800000;
            }
        }
        if (func_ov003_02160854(self) != 0) {
            int idx = self->h494 - FindMappedMemberId02080468(entries, self->h488);
            idx += self->c49f * 4;
            Elem *elem = GetElementAtIndex_02160bd0_02160bd0(self, idx);
            if (elem == 0) {
                return;
            }
            if (elem->v < 0) {
                return;
            }
            DispatchWithShortB4_0205eaa0((Obj0205eaa0 *) &data_02108760, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->sub308);
            self->p470 = 0;
            int m      = elem->m;
            if (m == 3) {
                SetOrClearFlag40_02166f80(self, self->h488, 1);
                self->h484  = 0x58;
                self->state = 0;
            } else if (m == 2 || m == 1 || m == 4) {
                SetOrClearFlag40_02166f80(self, self->h488, 1);
                self->h484  = 0x57;
                self->state = 0;
            } else {
                self->h480 = elem->v;
                SetOrClearFlag40_02166f80(self, self->h488, 1);
                self->h484  = 0x19;
                self->state = self->state + 1;
                self->flags |= 0x20;
            }
        } else if (func_ov003_02160a68(self) != 0) {
            ResetWithSub0208203c((Obj0208203c*)self->sub308);
            self->p470 = 0;
            CallFunc0204c804OverAllElems((Cont0207fe44*)entries);
            self->flags |= 0x80000;
            self->h484  = 2;
            self->c4a3  = 1;
            self->state = 0;
        }
    } else if (state == 2) {
        func_ov003_021612c0(self);
        self->state = self->state + 1;
    } else if (state == 3) {
        int r = func_ov003_02161344(self);
        if (r != -1) {
            if (r == 1) {
                self->h484  = 0x1a;
                self->state = self->state + 1;
                self->flags |= 0x20;
            }
        } else {
            CallFunc0204c804OverAllElems((Cont0207fe44*)entries);
            self->h484  = 0x1c;
            self->h486  = 2;
            self->c4a3  = 1;
            self->state = 0;
            self->flags |= 0x80000;
            self->state = 0;
        }
    } else if (state == 4) {
        CallFunc0204c804OverAllElems((Cont0207fe44*)entries);
        self->flags |= 0x80000;
        self->h484  = 2;
        self->c4a3  = 1;
        self->state = 0;
        func_ov003_021668fc(self);
    } else if (state == 5) {
        CallFunc0204c804OverAllElems((Cont0207fe44*)entries);
        self->flags |= 0x80000;
        self->h484  = 2;
        self->c4a3  = 1;
        self->state = 0;
    } else if (state == 100) {
        func_ov003_021612c0(self);
        self->state = 0x65;
    } else if (state == 101) {
        int r = func_ov003_02161344(self);
        if (r != -1) {
            if (r == 1) {
                self->h484  = 0x18;
                self->state = 0;
            }
        } else {
            self->h484  = 0x1c;
            self->h486  = 2;
            self->c4a3  = 1;
            self->state = 0;
        }
    }
}
