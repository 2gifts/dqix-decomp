#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020e0310 {
    char pad0[0x34];
};
struct Struct_0205c570;
struct Struct0205cf1c;
struct Obj0205eaa0;

struct Ctl {
    char pad0[0x5c];
    char *strings;
    char pad60[0x998 - 0x60];
    int w998;
    char pad99c[4];
    int w9a0;
};

struct Scene {
    char pad0[0x64];
    Container020e0310 cont64;
    char list98[0x3b8 - 0x98];
    unsigned char state;
    char pad3b9[2];
    unsigned char b3bb;
    unsigned char b3bc;
    unsigned char tab3bd[4];
    signed char b3c1;
    unsigned char b3c2;
    unsigned char b3c3;
    char pad3c4[0x3cc - 0x3c4];
    int w3cc;
    int w3d0;
    char pad3d4[0x3ec - 0x3d4];
    unsigned char b3ec;
    unsigned char b3ed;
    char pad3ee[2];
    unsigned char b3f0;
    unsigned char b3f1;
    unsigned char b3f2;
};

struct Sub1840 {
    char pad0[0xb3c];
    int wb3c;
};

struct Zone {
    char pad0[0x1840];
    Sub1840 sub;
};

static inline Sub1840 *GetSub(Zone *z) { return &z->sub; }
static inline int GetB3c(Sub1840 *s) { return s->wb3c; }

Ctl *GetGlobalField0x1c020421a0();
extern "C" int *func_0202ae18();
extern "C" Zone *func_02012fe4();
extern "C" void func_02046380(void *obj);
struct StoreStruct;
void StoreInArray0x8b0(StoreStruct*, int, int);
void SetByteInRange(unsigned char *, int, unsigned char);
int CheckField0NonZero(int *p);
extern "C" int func_0202c540(int *p);
extern "C" int func_0202c508(int *p);
struct Obj02046574;
void SetIndexedName02046574(Obj02046574*, int, char*);
const char * GetFieldByKey020e0434(Container020e0310*, int);
int AppendString02042058(char *dst, const char *src);
extern "C" void func_ov003_0215cab0(char *obj, void *flag);
extern "C" void func_ov003_0215ddc0(char *base);
extern "C" void func_ov003_0215df1c(void *self);
extern "C" void func_ov003_0215dd3c(char *obj);
struct Struct_0205d81c;
void SetElementFieldC2(Struct_0205d81c*, int, int);
void SetChannelAFlag0205cef8(void *obj);
void SetChannelBFlag0205cf04(void *obj);
int GetActiveScaledSum0205d794(Struct_0205c570 *);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0 *, int, int);
void ClearChannelAFlag0205cf10(void *p);
void ClearFlagByte0205cf1c(Struct0205cf1c *);
extern "C" int func_ov003_0215dcb8(char *obj);
ARM int IsFlagStateOrField98Eq2_0215dd00(char *self);

extern int data_02108760;

// USA: func_ov003_0215d150
extern "C" ARM void func_ov003_0215d150(Scene *self) {
    GameState *gs = GameState::GetInstance();
    Ctl *g       = GetGlobalField0x1c020421a0();
    int *a       = func_0202ae18();
    Zone *b      = func_02012fe4();

    if (g->w9a0 == 3) {
        *(unsigned char *) ((char *) g + 0x1000 + 0x9ae) = 0;
    }

    unsigned char state = self->state;
    int k1;

    if (state == 0) {
        func_02046380(g);
        StoreInArray0x8b0((StoreStruct*)g, 0, self->b3c3);
        SetByteInRange((unsigned char *) g, 0, 0);
        StoreInArray0x8b0((StoreStruct*)g, 1, self->w3cc);
        SetByteInRange((unsigned char *) g, 1, 0);

        int sb;
        sb = (self->w3d0 == 0) ? 1 : 0;
        if (CheckField0NonZero(a) != 0) {
            if (func_0202c540(a) != 0) {
                sb = 2;
            }
        }
        g->w998 = 1;

        char *buf = g->strings;
        if (self->b3f0 != 0) {
            SetIndexedName02046574((Obj02046574*)g, 0, (char*)(*(void **) ((char *) gs->GetPartyMemberByIndex(0) + 0x134)));

            int flag = 0;
            if (func_0202c508(a) != 0) {
                flag = (*(short *) ((char *) gs->GetUnknownGameObject() + 4) == 0) ? 1 : 0;
            }

            if (flag != 0) {
                AppendString02042058(buf, GetFieldByKey020e0434(&self->cont64, (short)0x64));
            }

            if (GetB3c(GetSub(b)) == 6) {
                k1 = 0x67;
            } else if (self->w3d0 != 0) {
                k1 = 0x65;
            } else {
                k1 = 0x68;
            }
            AppendString02042058(buf, GetFieldByKey020e0434(&self->cont64, (short)k1));

            if (flag == 0) {
                AppendString02042058(buf, GetFieldByKey020e0434(&self->cont64, (short)0x6f));
            } else {
                int k2;
                k2 = (self->w3d0 != 0) ? 0x66 : 0x69;
                AppendString02042058(buf, GetFieldByKey020e0434(&self->cont64, (short)k2));
            }
        } else {
            int k0 = sb + 0x3e8;
            AppendString02042058(buf, GetFieldByKey020e0434(&self->cont64, (short)k0));
        }

        func_ov003_0215cab0((char *) self, buf);
        self->state = self->state + 1;
    }

    if (state == 1) {
        if (g->w9a0 != 3) {
            return;
        }
        self->b3ec = 1;
        self->b3ed = 0;
        self->state = self->state + 1;
    }
    if (state == 2) {
        if (self->b3ec != 0) {
            return;
        }
        if (self->b3f2 == 0) {
            func_ov003_0215ddc0((char *) self);
        }
        func_ov003_0215df1c(self);
        SetElementFieldC2((Struct_0205d81c*)self->list98, 0, 0);
        self->state = self->state + 1;
    }
    if (state == 3) {
        self->b3c1 = 0;
        func_ov003_0215dd3c((char *) self);
        SetChannelAFlag0205cef8(self->list98);
        SetChannelBFlag0205cf04(self->list98);
        self->state = self->state + 1;
    }
    if (state == 4) {
        self->b3c2 = 1;
        self->b3c1 = GetActiveScaledSum0205d794((Struct_0205c570 *) self->list98);
        if (func_ov003_0215dcb8((char *) self) != 0) {
            self->b3c2 = 0;
            ResetEntryList0205d6a0((Entry_0205d6a0*)self->list98, 0);
            DispatchWithShortB4_0205eaa0((Obj0205eaa0 *) &data_02108760, 1, 0);
            ClearChannelAFlag0205cf10(self->list98);
            ClearFlagByte0205cf1c((Struct0205cf1c *) self->list98);
            switch (self->tab3bd[self->b3c1]) {
            case 0: self->b3bc = 2; break;
            case 1: self->b3bc = 3; break;
            case 2: self->b3bc = 4; break;
            }
            self->state = 0;
        } else {
            if (IsFlagStateOrField98Eq2_0215dd00((char *) self) != 0) {
                self->b3c2 = 0;
                ResetEntryList0205d6a0((Entry_0205d6a0*)self->list98, 0);
                ClearChannelAFlag0205cf10(self->list98);
                ClearFlagByte0205cf1c((Struct0205cf1c *) self->list98);
                self->b3bc = 4;
                self->state = 0;
            }
        }
    }
}
