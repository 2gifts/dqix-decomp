#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "System/Matrix.h"
#include <globaldefs.h>

struct Scene {
    char pad0[0x464];
    unsigned int flags;
    char pad468[0x4a3 - 0x468];
    unsigned char c4a3;
    unsigned char state;
    char pad4a5[0x4b0 - 0x4a5];
    int p4b0;
};

struct Node {
    char pad0[9];
    unsigned char b9;
    char pad_a[0xcd - 0xa];
    unsigned char bcd;
    unsigned char bce;
    unsigned char bcf;
};

struct Field150 {
    char pad0[0x14];
    unsigned char b14 : 1;
};

struct Holder {
    char pad0[8];
    int f8;
};

struct Res;
extern "C" Holder *func_02012fe4();
void DispatchWithGlobalContext020daf9c(int, int, int, int);
void SetAndLockBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
GameObject *GetCombatantWithFlag0x100(GameState *, int);
int GetField0x3acValue(GameState *);
struct Obj02033874;
void SetVecYFromValue02033874(Obj02033874*, int);
extern "C" void func_ov017_021af59c(Node *);
struct HeadList020469f8;
struct HeadNode020469f8;
void PrependNodeToHead(HeadList020469f8*, HeadNode020469f8*);
struct Struct021b11b0;
void InitState39_021b11b0(Struct021b11b0*);
extern "C" int *func_0202ae18();
int CheckField0NonZero(int *);
void EnqueueEventTag173_021d1810(int, int, signed char);
void *GetGlobal02109030();
extern "C" void func_02094030(void *, int, int, int);
unsigned int *GetDataPtr02114e04_020d6c00();
struct FlagWord020466f4;
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);
int GetField0x397cValue(GameState *);
struct Field150Holder02052e2c;
Field150 * GetField150Ptr0x488_02052e2c(Field150Holder02052e2c*);
extern "C" void func_ov017_021bbae4(Node *, int, int);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
struct ListHead02046b60;
int ListContainsId(ListHead02046b60*, int);
struct GameResources;
void SetBrightness(GameResources*, int, int);
extern "C" void func_ov017_0219bd1c(int, int, int, int);
int *GetField0x3f8Address(GameState *);
char *GetGlobalField0x1c020421a0();
void ReinitController02043204(char *);
extern "C" void func_02043124(char *);
unsigned char *GetFieldAt0x150(unsigned char *);
void ResetShortFields02086380(unsigned char *);
struct S021b6b8c;
void CallIfField24ThenSetFlag_021b6b8c(S021b6b8c*);
extern "C" void __clear(void *, int);

// USA: func_ov003_021638e4
extern "C" ARM void func_ov003_021638e4(Scene *self) {
    char *res;
    GameState *gs;
    unsigned char *gp;
    void *list;
    BackgroundLoader *loader;
    res    = (char *) func_ov017_0218b5b0();
    list   = *(void **) (res + 0x3000 + 0x6fc);
    gs     = GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    gp     = (unsigned char *)GetPtrField0x2a04(gs);
    func_02012fe4();
    unsigned char state = self->state;

    if (state == 0) {
        if (!(self->flags & 0x40) || self->p4b0 != 0) {
            DispatchWithGlobalContext020daf9c(1, 0, 1, 0);
            SetAndLockBrightness((GameResources*)res, 0x10, 0xf);
            self->state = self->state + 1;
        }
    } else if (state == 1) {
        if (IsBrightnessTransitionActive((GameResources*)res) == 0) {
            for (int i = 0; i < gp[0xf7c]; i++) {
                GameObject *c = GetCombatantWithFlag0x100(gs, (gp + i)[0xf78]);
                if (c != 0) {
                    c->obj3D_.MakeHidden();
                }
            }
            self->state = self->state + 1;
        }
    } else if (state == 2) {
        if (IsBrightnessTransitionActive((GameResources*)res) == 0 && loader->GetNumQueuedTasks() <= 0) {
            if (self->flags & 0x40) {
                GameObject *c = GetCombatantWithFlag0x100(gs, GetField0x3acValue(gs));
                if (c != 0) {
                    Vector3i *v = (Vector3i *) ((char *) c + 0x44);
                    v->x        = 0x5800;
                    v->y        = 0x199;
                    v->z        = -0x785;
                    SetVecYFromValue02033874((Obj02033874*)c, 0);
                }
                Node *n = *(Node **) (res + 0x3000 + 0xb30);
                func_ov017_021af59c(n);
                n->b9 = 2;
                PrependNodeToHead((HeadList020469f8*)list, (HeadNode020469f8*)n);
            } else {
                Node *n = *(Node **) (res + 0x3000 + 0xb34);
                InitState39_021b11b0((Struct021b11b0*)n);
                PrependNodeToHead((HeadList020469f8*)list, (HeadNode020469f8*)n);
            }
            self->state = self->state + 1;
        }
    } else if (state == 3) {
        if (self->flags & 0x40) {
            Vector3i saved[4];
            for (int i = 0; i < 4; i++) {
                GameObject *c = GetCombatantWithFlag0x100(gs, (gp + i)[0xf78]);
                if (c != 0) {
                    saved[i] = *(Vector3i *) ((char *) c + 0x44);
                    c->obj3D_.MakeVisible();
                }
            }
            if (CheckField0NonZero(func_0202ae18()) != 0) {
                EnqueueEventTag173_021d1810(0, -1, (signed char) GetField0x3acValue(gs));
                func_02094030(GetGlobal02109030(), 1, -1, 0);
            }
        } else {
            if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) {
                return;
            }
            Vector3i tmp;
            __clear(&tmp, 12);
            GameObject *p = gs->GetPartyMemberByIndex(0);
            if (p != 0) {
                tmp = *(Vector3i *) ((char *) p + 0x44);
            }
            for (int i = 0; i < 4; i++) {
                GameObject *c = GetCombatantWithFlag0x100(gs, i);
                if (c != 0) {
                    c->obj3D_.MakeVisible();
                    *(Vector3i *) ((char *) c + 0x44) = tmp;
                }
            }
        }
        self->state = self->state + 1;
    } else if (state == 4) {
        if (IsBrightnessTransitionActive((GameResources*)res) == 0) {
            ClearFlags020466f4((FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x80000);
            Holder *h   = func_02012fe4();
            Node *n     = *(Node **) (res + 0x3000 + 0x734);
            Field150 *f = GetField150Ptr0x488_02052e2c((Field150Holder02052e2c*)(gs->GetGameObjectByIndex(GetField0x397cValue(gs))));
            func_ov017_021bbae4(n, h->f8, 2);
            n->bcd = GetField0x397cValue(gs);
            n->bce = f->b14;
            if (self->flags & 0x40) {
                self->flags &= ~0x40;
                if (CheckField0NonZero(func_0202ae18()) != 0) {
                    n->bcf = 2;
                    AppendNodeToTail((TailList020469b4*)list, (TailNode020469b4*)n);
                }
                if (ListContainsId((ListHead02046b60*)list, 3) == 0) {
                    SetBrightness((GameResources*)res, 0, 8);
                }
            } else {
                n->bcf = 3;
                PrependNodeToHead((HeadList020469f8*)list, (HeadNode020469f8*)n);
                func_ov017_0219bd1c(1, 0, 0, 1);
                int *p                         = GetField0x3f8Address(gs);
                p[4]                           = 0x48cc;
                p[5]                           = 0x199;
                p[6]                           = -0x733;
                *(short *) ((char *) p + 0x1c) = 0;
                *((unsigned char *) p + 0x6e)  = 0x40;
                *((unsigned char *) p + 0xa)   = 0;
            }
            char *ctl = GetGlobalField0x1c020421a0();
            ReinitController02043204(ctl);
            func_02043124(ctl);
            self->c4a3  = 0x10;
            self->state = 0;
            for (signed char i = 0; i < 4; i++) {
                GameObject *m = gs->GetPartyMemberByIndex(i);
                if (m != 0) {
                    unsigned char *fld = GetFieldAt0x150((unsigned char *) m);
                    if (fld != 0) {
                        ResetShortFields02086380(fld);
                    }
                }
            }
            CallIfField24ThenSetFlag_021b6b8c((S021b6b8c*)(*(void **) (res + 0x3000 + 0xb00)));
        }
    }
}
