#include <globaldefs.h>
#include "GameState/GameState.h"

struct IndexedHalfword020656d0 {
    char padding0[0x40];
    int field40, field44, field48;
    unsigned short* table;
    char padding50[0x1c];
    unsigned int count;
    char padding70[8];
    unsigned int index;
    char padding7c[0x10];
    unsigned char* child;
    char padding90[0x882];
    unsigned char field912;
    char padding913[0x85];
    void* active;
    int field99c;
    unsigned int state;
    char padding9a4[0xe94];
    int entry, value, field1840, savedValue;
    char padding1848[0x119];
    unsigned char timer;
    char padding1962[0x4c];
    unsigned char field19ae, field19af;
    char padding19b0[6];
    unsigned char field19b6;
    char padding19b7[6];
    unsigned char field19bd, field19be, field19bf, field19c0, field19c1;
    char padding19c2[0xb];
    unsigned char field19cd, field19ce, field19cf;
    char padding19d0[3];
    unsigned char field19d3;
};
struct Input020440cc { char padding[0x44]; unsigned int ticks; char padding48[0xc]; unsigned char active; };
struct EntryList_203dce4;
struct Child02040af0;
struct Obj0205eaa0;
struct State02045688;
extern unsigned short data_02114e30;
extern Input020440cc data_02114e54;
extern Obj0205eaa0 data_02108760;
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
unsigned short GetIndexedHalfword(IndexedHalfword020656d0*);
EntryList_203dce4* GetGlobalPtr021075f4();
Child02040af0* GetEntryUnlessFlag0x8000(EntryList_203dce4*, int);
extern "C" void _Z29SetValueOnActiveChild02040af0P13Child02040af0i(Child02040af0*, int);
extern "C" void func_0206b104(IndexedHalfword020656d0*);
extern "C" void func_0206b224(IndexedHalfword020656d0*);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
extern "C" int _Z20IsHighByteFF02044494PvS_(void*, void*);
extern "C" int _Z16Dispatch02044420PvS_(void*, void*);
extern "C" void _Z25CheckAndClearFlag020656e4Pv(void*);
typedef void (*AdvanceToken020440cc)(void*, int);
void SetFlag0x2IfByte0xd4Not3(unsigned char*);
extern "C" void _Z26ProcessPendingFlag02045688P13State02045688(State02045688*);
extern "C" void _Z23InitCombatSlots02043040Pc(char*);
extern "C" void func_02043124(IndexedHalfword020656d0*);
extern "C" void _Z28ResetControllerState020430b0Pc(char*);

// USA: func_020440cc
extern "C" ARM int func_020440cc(IndexedHalfword020656d0* self) {
    if (!self->active) return 1;
    if (!self->field19c1) {
        if (self->field19c0) return 0;
    }
    unsigned short mask = 0x403;
    int triggered = 0;
    if (self->field19bf) mask |= 0x200;
    if (self->field19cf) mask |= 0x100;
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, mask)) triggered = 1;
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0xf0)) triggered = 1;
    if (data_02114e54.active && data_02114e54.ticks < 20) triggered = 1;
    if (GetIndexedHalfword(self) == 0xff0c) {
        unsigned int ticks = GameState::GetInstance()->GetTickCount();
        if (self->timer) {
            if (self->timer <= ticks) {
                self->timer = 0;
                triggered = 1;
            } else self->timer -= ticks;
        }
    }
    if (!triggered) return 0;
    switch (self->state) {
    case 0:
        if (self->field19be) return 0;
        if (GetIndexedHalfword(self) == 0xff02) {
            Child02040af0* entry = GetEntryUnlessFlag0x8000(GetGlobalPtr021075f4(), self->entry);
            if (entry) _Z29SetValueOnActiveChild02040af0P13Child02040af0i(entry, self->value);
        }
        return 1;
    case 1:
        self->field19ae = 0;
        self->field19af = 0;
        self->field19cd = 1;
        self->field40 = 0;
        self->field44 = 0;
        self->field912 = 0;
        func_0206b104(self);
        self->state = 5;
        func_0206b224(self);
        if (!self->field19d3) _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
        break;
    case 3:
        self->field19bd = 0;
        break;
    case 2: {
        unsigned short command = GetIndexedHalfword(self);
        if (command == 0xff1f) {
            int stopA = 0xff01;
            int stopB = 0xff03;
            int store = 0xff2c;
            int childFlag = 0xff12;
            unsigned short token;
            while (self->index < self->count) {
                token = self->table[self->index];
                if (_Z20IsHighByteFF02044494PvS_(self, &token)) {
                    int skip = _Z16Dispatch02044420PvS_(self, &token);
                    if (skip) {
                        self->index = self->index + skip + 1;
                        continue;
                    }
                    if (token == stopA || token == stopB) break;
                    if (token == store) {
                        self->savedValue = self->value;
                        self->field19b6 = 1;
                        reinterpret_cast<AdvanceToken020440cc>(_Z25CheckAndClearFlag020656e4Pv)(self, 1);
                    } else if (token == childFlag && self->child) {
                        SetFlag0x2IfByte0xd4Not3(self->child);
                    }
                }
                ++self->index;
            }
            _Z26ProcessPendingFlag02045688P13State02045688(reinterpret_cast<State02045688*>(self));
            self->state = 0;
            _Z23InitCombatSlots02043040Pc(reinterpret_cast<char*>(self));
            func_02043124(self);
            _Z28ResetControllerState020430b0Pc(reinterpret_cast<char*>(self));
        } else {
            if (!self->field19d3) _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
            self->state = 5;
            ++self->index;
            self->field912 = 0;
        }
        break;
    }
    }
    return 0;
}
