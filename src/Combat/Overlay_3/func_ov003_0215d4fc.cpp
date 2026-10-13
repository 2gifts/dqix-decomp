#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Combat/EntryGetterTypes.h"

struct Scene {
    char pad0[0x64];
    char cont64[0x98 - 0x64];
    char list98[0x3b8 - 0x98];
    unsigned char state;
    char pad3b9[2];
    unsigned char b3bb;
    unsigned char b3bc;
    char pad3bd[0x3c4 - 0x3bd];
    unsigned char ids[4];
    char pad3c8[4];
    unsigned int w3cc;
    char pad3d0[0x3d8 - 0x3d0];
    float f3d8;
    char pad3dc[4];
    float f3e0;
    char pad3e4[4];
    int w3e8;
    unsigned char b3ec;
    unsigned char b3ed;
    char pad3ee[2];
    unsigned char b3f0;
    unsigned char b3f1;
    char pad3f2;
    unsigned char b3f3;
    unsigned char b3f4;
    unsigned char b3f5;
    char pad3f6[2];
    int w3f8;
};

struct Ctl {
    char pad0[0x998];
    int w998;
};

struct Ent {
    char pad0[0x12c];
    int key;
};

extern int data_02109bf4;
extern int data_02108760;

extern "C" int *func_0202ae18();
extern "C" void *_Z10GetWord0x0Pi(GameState *);
extern "C" Ctl *_Z26GetGlobalField0x1c020421a0v();
extern "C" void *_Z20GetGlobalPtr021075f4v();
extern "C" unsigned char *_Z15GetData02153637v();
extern "C" int func_0202c508(int *);
extern "C" void _Z24ReinitController02043204Pc(void *);
extern "C" unsigned char *_Z17GetPtrField0x2a04P9GameState(GameState *);
extern "C" void *_Z21GetFieldByKey020e0434P17Container020e0310i(void *, int);
extern "C" void func_ov003_0215cab0(Scene *, void *);
extern "C" void *_Z29FindEntryPointerByKey0203df78Pvi(void *, int);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(void *, int);
extern "C" void _Z30DispatchContextByState0209c678P13Actor0209c678i(void *, int);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void *, int, int);
extern "C" void func_0205e944(void *, int);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void *);
extern "C" void _Z24InitActorContext0209c20cP13Actor0209c20c(void *);
extern "C" void _Z36ResetAndDispatchActorContext0209c6d8Pvs(void *, short);
extern "C" void _Z21StoreInFirstEmptySlotPhh(unsigned char *, unsigned char);
extern "C" int _Z28GetEntryStatusForKey020e34bcP17Container020e34bci(unsigned char *, int);
extern "C" char *_Z19GetCombatantCheckedP9GameStatei(GameState *, int);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void _Z16Dispatch020e3428Pvi(void *, int);
extern "C" void _Z37ClearEntryIfCurrentArrMatches020e3468P13Entry020e3054i(void *, int);
extern "C" void func_ov017_021a2fa0(void *);
extern "C" void func_02012fe4();
extern "C" void func_ov017_0219bd1c(int, int, int, int);
extern "C" void func_ov017_021921fc(void *, int, int);
extern "C" int _Z25IsAnimationActive0209ca2cPv(void *);
extern "C" void _Z20StopAndReset0209c7fcPv(void *);
extern "C" void _Z34PropagateValueToActiveSlot02040b2cP11Obj02040b2ci(void *, int);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(void *, int, void *);

// USA: func_ov003_0215d4fc
extern "C" ARM void func_ov003_0215d4fc(Scene *self) {
    GameState *gs    = GameState::GetInstance();
    void *res        = _Z10GetWord0x0Pi(gs);
    Ctl *ctl         = _Z26GetGlobalField0x1c020421a0v();
    int *a           = func_0202ae18();
    void *b          = _Z20GetGlobalPtr021075f4v();
    GameObject *c    = gs->GetUnknownGameObject();
    unsigned char *d = _Z15GetData02153637v();
    unsigned char state;
    int i;
    int sb;
    sb = 0;
    if (func_0202c508(a) != 0) {
        if (*(short *) ((char *) gs->GetUnknownGameObject() + 4) == 0) {
            sb = 1;
        }
    }
    state = self->state;

    if (state == 0) {
        if (self->b3f3 != 0) {
            _Z24ReinitController02043204Pc(ctl);
            self->state = self->state + 1;
            return;
        }
        int key = 0x3f2;
        if (self->w3cc > *(unsigned int *) (_Z17GetPtrField0x2a04P9GameState(gs) + 0xf6c)) {
            key = 0x3fc;
            if (self->b3f0 != 0) {
                if (sb != 0) {
                    key        = 0x6c;
                    self->b3f1 = 1;
                } else {
                    key = 0x72;
                }
            }
            func_ov003_0215cab0(self, _Z21GetFieldByKey020e0434P17Container020e0310i(self->cont64, key));
            self->state = 8;
            return;
        }
        if (self->b3f0 != 0) {
            key = 0x6a;
        }
        func_ov003_0215cab0(self, _Z21GetFieldByKey020e0434P17Container020e0310i(self->cont64, key));
        self->b3bb = 2;
        void *e = _Z29FindEntryPointerByKey0203df78Pvi(b, (*(Ent **) ((char *) func_ov017_0218b5b0() + 0x3000 + 0x710))->key);
        if (e != 0) {
            self->w3f8 = GetOffset0x54FromFallbackChain((Entry_203dce4*)e);
        }
        self->state = self->state + 1;
    }
    if (state == 1) {
        if (ctl->w998 != 0) {
            return;
        }
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(self->list98, 0);
        _Z30DispatchContextByState0209c678P13Actor0209c678i(&data_02109bf4, 0x10);
        _Z13SetBrightnessP13GameResourcesii(res, -16, 0x3c);
        func_0205e944(&data_02108760, 0);
        self->b3f5  = 1;
        self->state = self->state + 1;
    }
    if (state == 2) {
        if (_Z28IsBrightnessTransitionActiveP13GameResources(res) != 0) {
            return;
        }
        _Z24InitActorContext0209c20cP13Actor0209c20c(&data_02109bf4);
        _Z36ResetAndDispatchActorContext0209c6d8Pvs(&data_02109bf4, 0x37);
        self->w3e8  = 0xb4;
        self->state = self->state + 1;
    }
    if (state == 3) {
        _Z21StoreInFirstEmptySlotPhh(d, 1);
        self->state = self->state + 1;
    }
    if (state == 4) {
        int status = _Z28GetEntryStatusForKey020e34bcP17Container020e34bci(d, 1);
        if (status == 1 || self->b3f4 != 0) {
            unsigned char *p              = _Z17GetPtrField0x2a04P9GameState(gs);
            *(unsigned int *) (p + 0xf6c) = *(unsigned int *) (p + 0xf6c) - self->w3cc;
            for (i = 0; i < 4; i++) {
                if (self->ids[i] != 0xff) {
                    char *m                                          = _Z19GetCombatantCheckedP9GameStatei(gs, self->ids[i]);
                    *(unsigned short *) (*(char **) (m + 0x130) + 4) = *(unsigned short *) (*(char **) (m + 0x134) + 0x30);
                    *(unsigned short *) (*(char **) (m + 0x130) + 6) = *(unsigned short *) (*(char **) (m + 0x134) + 0x32);
                    func_ov017_021c9e00(self->ids[i], 0, 0, 1);
                }
            }
            if (func_0202c508(a) != 0) {
                switch (self->b3bc) {
                    case 2: gs->SetDayTimer(self->f3d8); break;
                    case 3: gs->SetDayTimer(self->f3e0); break;
                }
            }
            _Z16Dispatch020e3428Pvi(d, 1);
            self->state = self->state + 1;
        } else if ((unsigned int) (status - 3) <= 2) {
            _Z37ClearEntryIfCurrentArrMatches020e3468P13Entry020e3054i(d, 1);
            self->state = 3;
        }
    }
    if (state == 5) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() <= 0) {
            func_ov017_021a2fa0((void *) func_ov017_0218b5b0());
            func_02012fe4();
            func_ov017_0219bd1c(1, 0, 0, 0);
            func_ov017_021921fc((char *) c + 0x44, *(short *) ((char *) c + 0xae), 1);
            self->state = self->state + 1;
        }
    }
    if (state == 6) {
        if (_Z25IsAnimationActive0209ca2cPv(&data_02109bf4) != 0) {
            return;
        }
        _Z20StopAndReset0209c7fcPv(&data_02109bf4);
        _Z13SetBrightnessP13GameResourcesii(res, 0, 0x3c);
        func_0205e944(&data_02108760, 0x7f);
        self->b3ec = 1;
        self->b3ed = 0;
        void *e = _Z29FindEntryPointerByKey0203df78Pvi(b, (*(Ent **) ((char *) func_ov017_0218b5b0() + 0x3000 + 0x710))->key);
        if (e != 0) {
            _Z34PropagateValueToActiveSlot02040b2cP11Obj02040b2ci(e, self->w3f8);
        }
        self->state = self->state + 1;
    } else if (self->state == 7) {
        if (self->b3ec != 0) {
            return;
        }
        if (_Z28IsBrightnessTransitionActiveP13GameResources(res) != 0) {
            return;
        }
        self->b3f5 = 0;
        if (self->b3f4 != 0) {
            return;
        }
        if (self->b3f3 != 0) {
            self->state = self->state + 1;
            return;
        }
        ctl->w998 = 1;
        _Z22SetIndexedName02046574P11Obj02046574iPc(ctl, 0, *(void **) ((char *) gs->GetUnknownGameObject() + 0x134));
        int key = 0x3f3;
        if (self->b3f0 != 0) {
            if (sb == 0) {
                key = 0x71;
            } else if (self->b3bc == 2) {
                key = 0x6b;
            } else {
                key = 0x6d;
            }
        }
        func_ov003_0215cab0(self, _Z21GetFieldByKey020e0434P17Container020e0310i(self->cont64, key));
        self->state = self->state + 1;
    }
    if (self->state == 8 && ctl->w998 == 0) {
        self->b3bc  = 5;
        self->state = 0;
    }
}
