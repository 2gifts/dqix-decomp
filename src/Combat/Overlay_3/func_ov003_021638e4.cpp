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
extern "C" unsigned char *_Z17GetPtrField0x2a04P9GameState(GameState *);
extern "C" Holder *func_02012fe4();
extern "C" void _Z33DispatchWithGlobalContext020daf9ciiii(int, int, int, int);
extern "C" void _Z20SetAndLockBrightnessP13GameResourcesii(char *, int, int);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(char *);
extern "C" GameObject *_Z25GetCombatantWithFlag0x100P9GameStatei(GameState *, int);
extern "C" int _Z18GetField0x3acValueP9GameState(GameState *);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(void *, int);
extern "C" void func_ov017_021af59c(Node *);
extern "C" void _Z17PrependNodeToHeadP16HeadList020469f8P16HeadNode020469f8(void *, Node *);
extern "C" void _Z20InitState39_021b11b0P14Struct021b11b0(Node *);
extern "C" int *func_0202ae18();
extern "C" int _Z18CheckField0NonZeroPi(int *);
extern "C" void _Z27EnqueueEventTag173_021d1810tth(int, int, int);
extern "C" void *_Z17GetGlobal02109030v();
extern "C" void func_02094030(void *, int, int, int);
extern "C" unsigned int *_Z27GetDataPtr02114e04_020d6c00v();
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(unsigned int *, unsigned int);
extern "C" int _Z19GetField0x397cValueP9GameState(GameState *);
extern "C" Field150 *_Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c(GameObject *);
extern "C" void func_ov017_021bbae4(Node *, int, int);
extern "C" void _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(void *, Node *);
extern "C" int _Z14ListContainsIdP16ListHead02046b60i(void *, int);
extern "C" void _Z13SetBrightnessP13GameResourcesii(char *, int, int);
extern "C" void func_ov017_0219bd1c(int, int, int, int);
extern "C" int *_Z20GetField0x3f8AddressP9GameState(GameState *);
extern "C" char *_Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z24ReinitController02043204Pc(char *);
extern "C" void func_02043124(char *);
extern "C" unsigned char *_Z15GetFieldAt0x150Ph(unsigned char *);
extern "C" void _Z24ResetShortFields02086380Ph(unsigned char *);
extern "C" void _Z33CallIfField24ThenSetFlag_021b6b8cP9S021b6b8c(void *);
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
    gp     = _Z17GetPtrField0x2a04P9GameState(gs);
    func_02012fe4();
    unsigned char state = self->state;

    if (state == 0) {
        if (!(self->flags & 0x40) || self->p4b0 != 0) {
            _Z33DispatchWithGlobalContext020daf9ciiii(1, 0, 1, 0);
            _Z20SetAndLockBrightnessP13GameResourcesii(res, 0x10, 0xf);
            self->state = self->state + 1;
        }
    } else if (state == 1) {
        if (_Z28IsBrightnessTransitionActiveP13GameResources(res) == 0) {
            for (int i = 0; i < gp[0xf7c]; i++) {
                GameObject *c = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, (gp + i)[0xf78]);
                if (c != 0) {
                    c->obj3D_.MakeHidden();
                }
            }
            self->state = self->state + 1;
        }
    } else if (state == 2) {
        if (_Z28IsBrightnessTransitionActiveP13GameResources(res) == 0 && loader->GetNumQueuedTasks() <= 0) {
            if (self->flags & 0x40) {
                GameObject *c = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, _Z18GetField0x3acValueP9GameState(gs));
                if (c != 0) {
                    Vector3i *v = (Vector3i *) ((char *) c + 0x44);
                    v->x        = 0x5800;
                    v->y        = 0x199;
                    v->z        = -0x785;
                    _Z24SetVecYFromValue02033874P11Obj02033874i(c, 0);
                }
                Node *n = *(Node **) (res + 0x3000 + 0xb30);
                func_ov017_021af59c(n);
                n->b9 = 2;
                _Z17PrependNodeToHeadP16HeadList020469f8P16HeadNode020469f8(list, n);
            } else {
                Node *n = *(Node **) (res + 0x3000 + 0xb34);
                _Z20InitState39_021b11b0P14Struct021b11b0(n);
                _Z17PrependNodeToHeadP16HeadList020469f8P16HeadNode020469f8(list, n);
            }
            self->state = self->state + 1;
        }
    } else if (state == 3) {
        if (self->flags & 0x40) {
            Vector3i saved[4];
            for (int i = 0; i < 4; i++) {
                GameObject *c = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, (gp + i)[0xf78]);
                if (c != 0) {
                    saved[i] = *(Vector3i *) ((char *) c + 0x44);
                    c->obj3D_.MakeVisible();
                }
            }
            if (_Z18CheckField0NonZeroPi(func_0202ae18()) != 0) {
                _Z27EnqueueEventTag173_021d1810tth(0, -1, (signed char) _Z18GetField0x3acValueP9GameState(gs));
                func_02094030(_Z17GetGlobal02109030v(), 1, -1, 0);
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
                GameObject *c = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, i);
                if (c != 0) {
                    c->obj3D_.MakeVisible();
                    *(Vector3i *) ((char *) c + 0x44) = tmp;
                }
            }
        }
        self->state = self->state + 1;
    } else if (state == 4) {
        if (_Z28IsBrightnessTransitionActiveP13GameResources(res) == 0) {
            _Z18ClearFlags020466f4P16FlagWord020466f4j(_Z27GetDataPtr02114e04_020d6c00v(), 0x80000);
            Holder *h   = func_02012fe4();
            Node *n     = *(Node **) (res + 0x3000 + 0x734);
            Field150 *f = _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c(
                gs->GetGameObjectByIndex(_Z19GetField0x397cValueP9GameState(gs)));
            func_ov017_021bbae4(n, h->f8, 2);
            n->bcd = _Z19GetField0x397cValueP9GameState(gs);
            n->bce = f->b14;
            if (self->flags & 0x40) {
                self->flags &= ~0x40;
                if (_Z18CheckField0NonZeroPi(func_0202ae18()) != 0) {
                    n->bcf = 2;
                    _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(list, n);
                }
                if (_Z14ListContainsIdP16ListHead02046b60i(list, 3) == 0) {
                    _Z13SetBrightnessP13GameResourcesii(res, 0, 8);
                }
            } else {
                n->bcf = 3;
                _Z17PrependNodeToHeadP16HeadList020469f8P16HeadNode020469f8(list, n);
                func_ov017_0219bd1c(1, 0, 0, 1);
                int *p                         = _Z20GetField0x3f8AddressP9GameState(gs);
                p[4]                           = 0x48cc;
                p[5]                           = 0x199;
                p[6]                           = -0x733;
                *(short *) ((char *) p + 0x1c) = 0;
                *((unsigned char *) p + 0x6e)  = 0x40;
                *((unsigned char *) p + 0xa)   = 0;
            }
            char *ctl = _Z26GetGlobalField0x1c020421a0v();
            _Z24ReinitController02043204Pc(ctl);
            func_02043124(ctl);
            self->c4a3  = 0x10;
            self->state = 0;
            for (signed char i = 0; i < 4; i++) {
                GameObject *m = gs->GetPartyMemberByIndex(i);
                if (m != 0) {
                    unsigned char *fld = _Z15GetFieldAt0x150Ph((unsigned char *) m);
                    if (fld != 0) {
                        _Z24ResetShortFields02086380Ph(fld);
                    }
                }
            }
            _Z33CallIfField24ThenSetFlag_021b6b8cP9S021b6b8c(*(void **) (res + 0x3000 + 0xb00));
        }
    }
}
