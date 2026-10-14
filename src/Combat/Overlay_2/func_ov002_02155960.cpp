#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_0205d81c;
struct Struct_0205def8;
struct Outer020e28dc;
struct Ctx020e263c;

struct Elem_0205d81c {
    unsigned char field_0x0[0xc5];
    unsigned char flags;
};

struct BattleManager {
    unsigned char field_0x0[0x998];
    int blocked;
    int field_0x99c;
    int state;
};

struct BattleElementRegion {
    unsigned int header;
    unsigned char entries[0xba4];
    unsigned char current[0x130];
};

class BattleActor {
public:
    unsigned int field_0x0;
    union {
        Outer020e28dc* owner;
        Ctx020e263c* context;
    } connection;
    unsigned char field_0x8[0x48];
    unsigned char model[0x864];
    unsigned char effect[0x614];
    BattleElementRegion elements;
    int delta;
    unsigned char field_0x1ba4[0x14];
    int state;
    int previousState;
    int mode;
    int field_0x1bc4;
    int displayMode;
    int pending;
    unsigned char field_0x1bd0[0x44];
    unsigned short field_0x1c14;
    unsigned char field_0x1c16[0x1a];
    unsigned char busy;
    unsigned char field_0x1c31[0x92];
    unsigned char effectEnabled;
    unsigned char elementsUpdated;
    unsigned char field_0x1cc5[0x7a3];
    void* optional;
    unsigned char field_0x246c[0x10];
    unsigned int flags;
    unsigned char field_0x2480[5];
    unsigned char active;
    unsigned char field_0x2486;
    unsigned char pendingState;
};

typedef void (BattleActor::*BattleHandler)();
struct BattleTarget {
    unsigned char data[0x34];
};

extern "C" int func_ov017_021959b4();
void SetTag2aIfNotAlreadyFlagged_02155024(unsigned char*);
int GetGlobalField0x1c020421a0();
extern "C" void func_ov023_021e7404(void*, int);
void ClearFlagBit1IfEnabled_02156178(unsigned char*);
extern "C" void func_ov023_021eb43c(void*);
extern "C" int func_ov002_02154c30(void*);
void SyncElementFlags0215b648(unsigned char*);
extern "C" void func_ov002_02156bc8(BattleActor*);
extern "C" void func_ov002_02156c7c(BattleActor*);
extern "C" void func_ov002_021561b0(BattleActor*);
Elem_0205d81c* FindElementForFieldB0_0205d8c4(Struct_0205d81c*);
int IsField0x9cEqual3_0204c7cc(unsigned char*);
void SetFieldAt0x30_0205bc24(void*, int);
int GetInnerFlagBit0020e28dc(Outer020e28dc*);
void UpdateEntryStateAndPosition(Ctx020e263c*, int);
extern "C" int func_0205d0e0(Struct_0205d81c*, int);
int CheckFlagOrThreshold_02161b48(char*, int);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short*, int);
extern "C" void* func_0205ec34();
int LookupAndForEachNode020649b0(void*, int, void*);
extern "C" void func_0206f81c(void*);
extern "C" void func_ov023_021dca88(void*);
void CopyByteField0215aa14(char*);
int GetField5cb0Value_0201079c(char*);
void SetElementFlag0x20ByKey0205def8(Struct_0205def8*, int, int);
void SetElementFieldC2_0205deb4(Struct_0205d81c*, int, int);
extern "C" void func_ov002_0215bba8(BattleActor*);
extern unsigned short data_02114e30[0x10];
extern unsigned int data_ov002_0216d3a8;
extern BattleHandler data_020e6d5c;
extern BattleHandler data_ov002_0216cd74[44];

static inline BattleElementRegion* GetElements(BattleActor* actor) { SDK_NULL_ASSERT(actor); return &actor->elements; }

// USA: func_ov002_02155960
extern "C" ARM int func_ov002_02155960(BattleActor* actor, int delta) {
    if (func_ov017_021959b4() != 0)
        SetTag2aIfNotAlreadyFlagged_02155024((unsigned char*)actor);
    BattleManager* manager = (BattleManager*)GetGlobalField0x1c020421a0();
    actor->delta = delta;
    if (actor->effectEnabled != 0)
        func_ov023_021e7404(actor->effect, actor->delta);
    ClearFlagBit1IfEnabled_02156178((unsigned char*)actor);
    if (actor->optional != 0)
        func_ov023_021eb43c(actor->optional);
    if (actor->state != 0) {
        actor->elementsUpdated = 0;
        actor->elementsUpdated = func_ov002_02154c30(actor->elements.current);
        SyncElementFlags0215b648((unsigned char*)actor);
        if ((actor->flags & 0x20) == 0) {
            func_ov002_02156bc8(actor);
            func_ov002_02156c7c(actor);
        }
        func_ov002_021561b0(actor);
        Elem_0205d81c* element = FindElementForFieldB0_0205d8c4((Struct_0205d81c*)&actor->elements);
        if (element != 0 && IsField0x9cEqual3_0204c7cc((unsigned char*)element) != 0 && (element->flags & 2) == 0)
            SetFieldAt0x30_0205bc24(GetElements(actor)->entries, -1);
        if (actor->connection.owner != 0 && GetInnerFlagBit0020e28dc(actor->connection.owner) != 0) {
            UpdateEntryStateAndPosition(actor->connection.context, actor->delta);
        } else {
            actor->displayMode = func_0205d0e0((Struct_0205d81c*)&actor->elements, actor->delta);
        }
    }
    if (actor->active != 0) {
        if ((actor->state == 4 && actor->mode == 1 && CheckFlagOrThreshold_02161b48((char*)actor, 1) != 0) ||
                TestFlag0SetAndFlag1Clear_02012444(data_02114e30, 0x800) != 0) {
            if (manager->blocked == 0)
                actor->pendingState = 1;
        }
        if (actor->pendingState == 1) {
            BattleTarget target;
            if (LookupAndForEachNode020649b0(func_0205ec34(), 0x16, &target) != 0)
                func_0206f81c(&target);
            if (actor->flags & 1)
                func_ov023_021dca88(actor->model);
            actor->state = 0x2b;
            actor->previousState = 0x2b;
            actor->pendingState = 2;
        }
    }
    actor->pending = 0;
    if (actor->state == 0x26 && manager->blocked != 0 && manager->state == 5)
        return 0;
    if ((data_ov002_0216d3a8 & 1) == 0) {
        BattleHandler empty = data_020e6d5c;
        data_ov002_0216cd74[8] = empty;
        data_ov002_0216cd74[18] = empty;
        data_ov002_0216cd74[19] = empty;
        data_ov002_0216cd74[22] = empty;
        data_ov002_0216cd74[26] = empty;
        data_ov002_0216cd74[27] = empty;
        data_ov002_0216cd74[29] = empty;
        data_ov002_0216cd74[32] = empty;
        data_ov002_0216cd74[40] = empty;
        data_ov002_0216cd74[41] = empty;
        data_ov002_0216cd74[43] = empty;
        data_ov002_0216d3a8 |= 1;
    }
    if (data_ov002_0216cd74[actor->state] == 0)
        return (actor->flags & 1) == 0;
    (actor->*data_ov002_0216cd74[actor->state])();
    if (actor->state != 0 && actor->state != 0x1e && actor->state != 0x2a && actor->busy == 0 && actor->mode == 1) {
        manager = (BattleManager*)GetGlobalField0x1c020421a0();
        if (TestFlag0SetAndFlag1Clear_02012444(data_02114e30, 0x800) != 0 && manager->blocked == 0) {
            if (actor->state == 0x21)
                CopyByteField0215aa14((char*)actor);
            if (actor->state == 0xf) {
                SetTag2aIfNotAlreadyFlagged_02155024((unsigned char*)actor);
            } else {
                if (actor->flags & 1)
                    func_ov023_021dca88(actor->model);
                actor->state = 0x2b;
                actor->field_0x1c14 = 0;
            }
        }
    }
    if (GetField5cb0Value_0201079c((char*)GameState::GetInstance()) == 1 || actor->active != 0) {
        SetElementFlag0x20ByKey0205def8((Struct_0205def8*)&actor->elements, 0, 0x29);
    }
    SetElementFieldC2_0205deb4((Struct_0205d81c*)&actor->elements, 0x29, 0);
    SetElementFieldC2_0205deb4((Struct_0205d81c*)&actor->elements, 0x28, 0);
    func_ov002_0215bba8(actor);
    return 0;
}
