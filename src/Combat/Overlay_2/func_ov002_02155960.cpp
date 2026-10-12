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
extern "C" void _Z36SetTag2aIfNotAlreadyFlagged_02155024Ph(unsigned char*);
extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_ov023_021e7404(void*, int);
extern "C" void _Z31ClearFlagBit1IfEnabled_02156178Ph(unsigned char*);
extern "C" void func_ov023_021eb43c(void*);
extern "C" int func_ov002_02154c30(void*);
extern "C" void _Z24SyncElementFlags0215b648Ph(unsigned char*);
extern "C" void func_ov002_02156bc8(BattleActor*);
extern "C" void func_ov002_02156c7c(BattleActor*);
extern "C" void func_ov002_021561b0(BattleActor*);
Elem_0205d81c* FindElementForFieldB0(Struct_0205d81c*);
int IsField0x9cEqual3(unsigned char*);
void SetFieldAt0x30(void*, int);
extern "C" int _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(Outer020e28dc*);
void UpdateEntryStateAndPosition(Ctx020e263c*, int);
extern "C" int func_0205d0e0(Struct_0205d81c*, int);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char*, int);
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
extern "C" void* func_0205ec34();
extern "C" int _Z28LookupAndForEachNode020649b0PviS_(void*, int, void*);
extern "C" void func_0206f81c(void*);
extern "C" void func_ov023_021dca88(void*);
extern "C" void _Z21CopyByteField0215aa14Pc(char*);
int GetField5cb0Value(char*);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(Struct_0205def8*, int, int);
void SetElementFieldC2(Struct_0205d81c*, int, int);
extern "C" void func_ov002_0215bba8(BattleActor*);
extern unsigned short data_02114e30[0x10];
extern unsigned int data_ov002_0216d3a8;
extern BattleHandler data_020e6d5c;
extern BattleHandler data_ov002_0216cd74[44];

static inline BattleElementRegion* GetElements(BattleActor* actor) {
    BattleElementRegion* elements = &actor->elements;
    return elements;
}

// USA: func_ov002_02155960
extern "C" ARM int func_ov002_02155960(BattleActor* actor, int delta) {
    if (func_ov017_021959b4() != 0)
        _Z36SetTag2aIfNotAlreadyFlagged_02155024Ph((unsigned char*)actor);
    BattleManager* manager = (BattleManager*)_Z26GetGlobalField0x1c020421a0v();
    actor->delta = delta;
    if (actor->effectEnabled != 0)
        func_ov023_021e7404(actor->effect, actor->delta);
    _Z31ClearFlagBit1IfEnabled_02156178Ph((unsigned char*)actor);
    if (actor->optional != 0)
        func_ov023_021eb43c(actor->optional);
    if (actor->state != 0) {
        actor->elementsUpdated = 0;
        actor->elementsUpdated = func_ov002_02154c30(actor->elements.current);
        _Z24SyncElementFlags0215b648Ph((unsigned char*)actor);
        if ((actor->flags & 0x20) == 0) {
            func_ov002_02156bc8(actor);
            func_ov002_02156c7c(actor);
        }
        func_ov002_021561b0(actor);
        Elem_0205d81c* element = FindElementForFieldB0((Struct_0205d81c*)&actor->elements);
        if (element != 0 && IsField0x9cEqual3((unsigned char*)element) != 0 && (element->flags & 2) == 0)
            SetFieldAt0x30(GetElements(actor)->entries, -1);
        if (actor->connection.owner != 0 && _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(actor->connection.owner) != 0) {
            UpdateEntryStateAndPosition(actor->connection.context, actor->delta);
        } else {
            actor->displayMode = func_0205d0e0((Struct_0205d81c*)&actor->elements, actor->delta);
        }
    }
    if (actor->active != 0) {
        if ((actor->state == 4 && actor->mode == 1 && _Z29CheckFlagOrThreshold_02161b48Pci((char*)actor, 1) != 0) ||
                TestFlag0SetAndFlag1Clear(data_02114e30, 0x800) != 0) {
            if (manager->blocked == 0)
                actor->pendingState = 1;
        }
        if (actor->pendingState == 1) {
            BattleTarget target;
            if (_Z28LookupAndForEachNode020649b0PviS_(func_0205ec34(), 0x16, &target) != 0)
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
        manager = (BattleManager*)_Z26GetGlobalField0x1c020421a0v();
        if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x800) != 0 && manager->blocked == 0) {
            if (actor->state == 0x21)
                _Z21CopyByteField0215aa14Pc((char*)actor);
            if (actor->state == 0xf) {
                _Z36SetTag2aIfNotAlreadyFlagged_02155024Ph((unsigned char*)actor);
            } else {
                if (actor->flags & 1)
                    func_ov023_021dca88(actor->model);
                actor->state = 0x2b;
                actor->field_0x1c14 = 0;
            }
        }
    }
    if (GetField5cb0Value((char*)GameState::GetInstance()) == 1 || actor->active != 0) {
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((Struct_0205def8*)&actor->elements, 0, 0x29);
    }
    SetElementFieldC2((Struct_0205d81c*)&actor->elements, 0x29, 0);
    SetElementFieldC2((Struct_0205d81c*)&actor->elements, 0x28, 0);
    func_ov002_0215bba8(actor);
    return 0;
}
