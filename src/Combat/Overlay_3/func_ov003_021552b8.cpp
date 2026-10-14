#include "GameState/GameState.h"
#include <globaldefs.h>
#if defined(jpn)
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif

struct Container020e0310;
struct Obj02046574;

struct MsgGlobals021552b8 {
    void *subject;
    char pad4[0xc];
    void *subject2;
    char pad14[0x28 - 0x14];
    void *extra;
    char pad2c[LOW_REGION(0x868,0x998) - 0x2c];
    int active;
    int active2;
    int phase;
};

struct PartyData021552b8 {
    char pad0[LOW_REGION(0x8b8,0x950)];
    int vocation;
};

struct PartyObj021552b8 {
#if defined(jpn)
    char pad0[0x134];
    void* name;
    char pad138[0x144 - 0x138];
#else
    char pad0[0x150];
#endif
    PartyData021552b8 *data;
};

struct MsgScene021552b8 {
    char pad0[4];
    void *ptr4;
    char pad8[0xe4 - 8];
    char messages[LOW_REGION(0x1e8,0x1ec) - 0xe4];
    short curId;
    short nextId;
    char pad1f0[0x1f7 - 0x1f0];
    signed char slot;
    unsigned char mode;
    unsigned char sub;
    unsigned char step;
    char pad1fb;
    unsigned int flags;
};

struct StrObj021552b8 {
    char data[0xc];
};

MsgGlobals021552b8 *GetGlobalField0x1c020421a0();
extern "C" void func_02046380(MsgGlobals021552b8 *);
int GetArrayEntryByIndex_02156034(void *);
extern "C" void *_Z21GetFieldByKey020e0434P17Container020e0310i(void *, int);
void InitObjFromCombatantId020e4bf4(void *, int);
extern "C" void func_020e4b34(void *, void *, int, int, int, int, int, int, int, int, int, int);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(MsgGlobals021552b8 *, int, void *);
#if defined(jpn)
extern "C" void func_0204500c(MsgGlobals021552b8*, void*, int);
#endif
#if !defined(jpn)
extern "C" void func_0204500c(MsgGlobals021552b8 *, void *, int, int);
#endif
int IsFieldEq3At_021538e0(void *);
void ReinitController02043204(char *);
extern "C" void func_02043124(MsgGlobals021552b8 *);

// USA: func_ov003_021552b8
extern "C" ARM void func_ov003_021552b8(MsgScene021552b8 *self) {
    MsgGlobals021552b8 *g = GetGlobalField0x1c020421a0();
    if (self->step == 0) {
#if !defined(jpn)
        int id = self->curId;
#endif
        if (self->flags & 1) {
#if defined(jpn)
            int id = self->curId;
#endif
            switch (id) {
                case 6: id = 0x1b; break;
                case 7: id = 0x1c; break;
                case 8: id = 0x1d; break;
                case 9: id = 0x1e; break;
                case 10: id = 0x1f; break;
                case 11: id = 0x20; break;
                case 12: id = 0x21; break;
                case 13: id = 0x22; break;
                case 0x30: id = 0x32; break;
                case 0x31: id = 0x33; break;
            }
            self->curId = id;
        }
        func_02046380(g);
        GameState *gs           = GameState::GetInstance();
        PartyObj021552b8 *party = (PartyObj021552b8 *) gs->GetPartyMemberByIndex(self->slot);
#if defined(jpn)
        void* name = 0;
        int vocation = 0;
        if (party) {
            vocation = party->data->vocation;
            name = party->name;
        }
        _Z22SetIndexedName02046574P11Obj02046574iPc(g, 0, name);
        short key = GetArrayEntryByIndex_02156034(self) + 0x23;
        _Z22SetIndexedName02046574P11Obj02046574iPc(g, 1, _Z21GetFieldByKey020e0434P17Container020e0310i(self->messages, key));
        _Z22SetIndexedName02046574P11Obj02046574iPc(g, 2, _Z21GetFieldByKey020e0434P17Container020e0310i(self->messages, (short)(vocation + 0x23)));
        _Z22SetIndexedName02046574P11Obj02046574iPc(g, 3, _Z21GetFieldByKey020e0434P17Container020e0310i(self->messages, (short)(vocation + 0x34)));
        func_0204500c(g, _Z21GetFieldByKey020e0434P17Container020e0310i(self->messages, self->curId), 0);
#else
        int vocation            = 0;
        if (party) {
            vocation = party->data->vocation;
        }
        short key = GetArrayEntryByIndex_02156034(self) + 0x23;
        void *a   = _Z21GetFieldByKey020e0434P17Container020e0310i(self->messages, key);
        void *b   = _Z21GetFieldByKey020e0434P17Container020e0310i(self->messages, (short) (vocation + 0x23));
        StrObj021552b8 unit;
        InitObjFromCombatantId020e4bf4(&unit, self->slot);
        g->subject  = &unit;
        g->subject2 = &unit;
        StrObj021552b8 obj;
        void *pick = a;
        if (id == 0x10 || id == 0x13 || id == 0x16) {
            pick = b;
        }
        func_020e4b34(&obj, pick, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        g->extra = &obj;
        _Z22SetIndexedName02046574P11Obj02046574iPc(g, 1, a);
        _Z22SetIndexedName02046574P11Obj02046574iPc(g, 2, b);
        _Z22SetIndexedName02046574P11Obj02046574iPc(
            g, 3, _Z21GetFieldByKey020e0434P17Container020e0310i(self->messages, (short) (vocation + 0x34)));
        func_0204500c(g, _Z21GetFieldByKey020e0434P17Container020e0310i(self->messages, id), 0, 0xe3);
#endif
        g->active  = 1;
        g->active2 = 1;
        self->step++;
    } else if (self->step == 1) {
        if (g->active == 0) {
            self->curId  = self->nextId;
            self->nextId = -1;
            self->mode   = 7;
            self->step   = 0;
            if (IsFieldEq3At_021538e0(self->ptr4) == 0) {
                self->mode = 5;
                self->sub  = 0;
            }
        } else if (g->phase == 3) {
            self->curId  = self->nextId;
            self->nextId = -1;
            if (self->curId < 0 && (self->flags & 2)) {
                ReinitController02043204((char *) g);
                func_02043124(g);
                self->flags &= ~2;
            }
            self->step = 0;
        }
    }
}
