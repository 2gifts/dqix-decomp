#include "GameState/GameState.h"
#include <globaldefs.h>

struct Run02012fe4;
extern "C" struct Run02012fe4 *func_02012fe4(void);
extern "C" void func_0205d7a0(void *list, int index);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int *out, unsigned char a, unsigned char b, unsigned char c, int d);
extern "C" char *_Z26GetGlobalField0x1c020421a0v(void);
struct Container0205a330;
extern "C" void _Z22IterateEntries0205a330P17Container0205a330i(struct Container0205a330 *c, int arg);
struct Struct_0205c570;
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
extern unsigned short data_02114e30;
int TestFlag0SetAndFlag1Clear(unsigned short *obj, int mask);
extern "C" int func_0205d97c(void *p);
struct Entry_0205d6a0;
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0 *a, int flag);
extern "C" void _Z24ReinitController02043204Pc(char *obj);
struct Obj0205eaa0;
extern struct Obj0205eaa0 data_02108760;
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *obj, int a, int b);
extern "C" void func_ov017_021baedc(void *self, int flag);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4 *list, struct TailNode020469b4 *node);
extern "C" void _Z27InitAndResetHeader_0219e310Phi(unsigned char *obj, int arg);
void *GetField0x3f8Address(GameState *state);
extern "C" void _Z18InitStruct02070378Pc(char *obj);

struct State_0217d6ac;
extern "C" void func_ov003_0217dd60(State_0217d6ac *self);
extern "C" int func_ov003_0217e1e4(State_0217d6ac *self);
extern "C" void func_ov003_0217dfb4(State_0217d6ac *self);

struct Progress02012fe4 {
    unsigned char pad0[0xb3c];
    int chapter;
};

struct Run02012fe4 {
    unsigned char pad0[0x1840];
    struct Progress02012fe4 progress;
};

static inline struct Progress02012fe4 *GetProgress(struct Run02012fe4 *run) { return &run->progress; }
static inline int GetChapter(struct Progress02012fe4 *progress) { return progress->chapter; }

struct BattleEvent_0217d6ac {
    unsigned char pad0[0x8];
    unsigned short messageId;
    unsigned char padA[0x10b - 0xa];
    unsigned char active;
};

struct EventRecord_0217d6ac {
    unsigned short id;
    unsigned char pad2[0x7 - 0x2];
    unsigned char field_0x7;
    unsigned char pad8[0xc - 0x8];
    unsigned char field_0xc;
    unsigned char padD[0x14 - 0xd];
    int field_0x14;
    int field_0x18;
};

struct State_0217d6ac {
    unsigned char pad0[0x4];
    unsigned char state;
    signed char busy;
    unsigned char pad6[0x14 - 0x6];
    int field_0x14;
    unsigned char ids[0x32 - 0x18];
    unsigned char count;
    unsigned char pad33[0x90 - 0x33];
    void *list;
};

// USA: func_ov003_0217d6ac
extern "C" ARM void func_ov003_0217d6ac(State_0217d6ac *self) {
    GameState *gs;
    char *res;
    char *global;
    int extra;
    int sel;
    struct TailList020469b4 *list;
    struct Run02012fe4 *current;
    res     = (char *) func_ov017_0218b5b0();
    list    = *(struct TailList020469b4 **) (res + 0x36fc);
    current = func_02012fe4();
    if (self->busy == 0) {
        func_0205d7a0(self->list, 0);
        func_ov003_0217dd60(self);
        ColorEffect_ConfigureAlphaBlend((unsigned int *) 0x04000050, 4, 1, 10, 6);
        self->busy = 1;
        return;
    }
    if (self->busy != 1) return;

    gs                                = GameState::GetInstance();
    global                            = _Z26GetGlobalField0x1c020421a0v();
    struct Container0205a330 *entries = *(struct Container0205a330 **) (global + 0x2e0);
    _Z22IterateEntries0205a330P17Container0205a330i(entries, gs->GetTickCount());
    global[0x19ae] = 0;
    _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) self->list);
    extra = 0;
    if (self->count > 1) {
        extra = func_ov003_0217e1e4(self);
    }
    sel = -1;
    if (IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)self->list, 0x14) == 1) {
        sel = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) self->list);
    } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601) != 0) {
        sel = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) self->list);
    } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) != 0) {
        sel = -2;
    } else if (func_0205d97c(self->list) == 2) {
        sel = -2;
    }
    if (self->field_0x14 != 0 || extra != 0) {
        func_ov003_0217dfb4(self);
    }
    if (sel == -2) {
        self->state = 4;
        self->busy  = 0;
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0 *) self->list, 0);
        _Z24ReinitController02043204Pc(global);
        return;
    }
    if (sel == -1) return;

    self->state = 4;
    self->busy  = 0;
    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
    _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0 *) self->list, 0);
    _Z24ReinitController02043204Pc(global);
    BattleEvent_0217d6ac *event = *(BattleEvent_0217d6ac **) (res + 0x3734);
    func_ov017_021baedc(event, 1);
    event->active = 1;
    switch (GetChapter(GetProgress(current))) {
        case 0:
        case 1:
        case 2: event->messageId = 0xd067; break;
        case 3:
        case 4: event->messageId = 0xd068; break;
        case 5: event->messageId = 0xd069; break;
        case 6: event->messageId = 0xd06a; break;
    }
    AppendNodeToTail(list, (struct TailNode020469b4 *) event);
    if (sel != 0) {
        unsigned char *header = *(unsigned char **) (res + 0x370c);
        _Z27InitAndResetHeader_0219e310Phi(header, 0);
        EventRecord_0217d6ac *record = (EventRecord_0217d6ac *) GetField0x3f8Address(gs);
        _Z18InitStruct02070378Pc((char *) record);
        record->id         = self->ids[sel] + 0xc544;
        record->field_0x7  = 1;
        record->field_0x14 = 0x2b8;
        record->field_0x18 = -0x7b33;
        record->field_0xc  = 1;
        AppendNodeToTail(list, (struct TailNode020469b4 *) header);
    } else {
        unsigned char *header = *(unsigned char **) (res + 0x370c);
        _Z27InitAndResetHeader_0219e310Phi(header, 0);
        EventRecord_0217d6ac *record = (EventRecord_0217d6ac *) GetField0x3f8Address(gs);
        _Z18InitStruct02070378Pc((char *) record);
        record->id         = 0xc3bc;
        record->field_0x7  = 1;
        record->field_0x14 = 0x266;
        record->field_0x18 = -0x7b33;
        record->field_0xc  = 1;
        AppendNodeToTail(list, (struct TailNode020469b4 *) header);
    }
}
