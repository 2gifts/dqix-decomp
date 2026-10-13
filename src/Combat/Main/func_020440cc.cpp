#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/MessageSystem.h"

struct Input020440cc {
    unsigned char unknown0[0x44];
    unsigned int ticks;
    unsigned char unknown48[0xc];
    unsigned char active;
};
struct IndexedHalfword020656d0;
struct EntryList_203dce4;
struct Entry_203dce4;
struct Child02040af0;
struct Obj0205eaa0;
struct State02045688;
extern unsigned short data_02114e30;
extern Input020440cc data_02114e54;
extern Obj0205eaa0 data_02108760;
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
void* GetGlobalPtr021075f4();
Entry_203dce4* GetEntryUnlessFlag0x8000(EntryList_203dce4*, int);
void SetValueOnActiveChild02040af0(Child02040af0*, int);
extern "C" void func_0206b104(MessageSystem*);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
int CheckAndClearFlag020656e4(void*, int);
void SetFlag0x2IfByte0xd4Not3(unsigned char*);
void ProcessPendingFlag02045688(State02045688*);
extern "C" void func_02043124(MessageSystem*);
unsigned short GetIndexedHalfword(IndexedHalfword020656d0*);
void InitCombatSlots02043040(char*);
void ResetControllerState020430b0(char*);

#if defined(jpn)
extern "C" void func_0206cba0(MessageSystem*);
extern "C" bool func_02069430(MessageSystem*, unsigned short);
extern "C" int func_02069444(MessageSystem*, unsigned short);
#else
extern "C" void func_0206b224(MessageSystem*);
bool IsHighByteFF02044494(void*, void*);
int Dispatch02044420(void*, void*);
#endif

// USA: func_020440cc
// JPN: func_02044894
extern "C" ARM int func_020440cc(MessageSystem* self) {
    IndexedHalfword020656d0* stream = reinterpret_cast<IndexedHalfword020656d0*>(self);
    if (!self->active) return 1;
    if (!self->b19c1) {
        if (self->b19c0) return 0;
    }
    unsigned short mask = 0x403;
    int triggered = 0;
    if (self->b19bf) mask |= 0x200;
#if defined(jpn)
    if (self->flags17ff.flag1) mask |= 0x100;
#else
    if (self->b19cf) mask |= 0x100;
#endif
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, mask)) triggered = 1;
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0xf0)) triggered = 1;
    if (data_02114e54.active && data_02114e54.ticks < 20) triggered = 1;
    if (GetIndexedHalfword(stream) == 0xff0c) {
        unsigned int ticks = GameState::GetInstance()->GetTickCount();
        if (self->inputDelay) {
            if (self->inputDelay <= ticks) {
                self->inputDelay = 0;
                triggered = 1;
            } else self->inputDelay -= ticks;
        }
    }
    if (!triggered) return 0;
    switch (self->mode) {
    case 0:
        if (self->b19be) return 0;
        if (GetIndexedHalfword(stream) == 0xff02) {
            Entry_203dce4* entry = GetEntryUnlessFlag0x8000(static_cast<EntryList_203dce4*>(GetGlobalPtr021075f4()), self->selectedEntry);
            if (entry) SetValueOnActiveChild02040af0(reinterpret_cast<Child02040af0*>(entry), self->selectedValue);
        }
        return 1;
    case 1:
        self->b19ae = 0;
        self->b19af = 0;
        self->b19cd = 1;
        self->stream40 = 0;
        self->stream44 = 0;
        self->b912 = 0;
        func_0206b104(self);
#if defined(jpn)
        func_0206cba0(self);
        self->mode = 5;
        if (!self->flags17ff.flag5) DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
#else
        self->mode = 5;
        func_0206b224(self);
        if (!self->b19d3) DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
#endif
        break;
    case 3:
        self->b19bd = 0;
        break;
    case 2: {
        unsigned short command = GetIndexedHalfword(stream);
#if defined(jpn)
        if (command == 0xff21) {
#else
        if (command == 0xff1f) {
#endif
            int stopA = 0xff01;
            int stopB = 0xff03;
#if defined(jpn)
            int store = 0xff2e;
#else
            int store = 0xff2c;
#endif
            int childFlag = 0xff12;
            unsigned short token;
            while (self->tokenIndex < self->tokenCount) {
                token = self->firstLineBuffer[self->tokenIndex];
#if defined(jpn)
                if (func_02069430(self, token)) {
                    int skip = func_02069444(self, token);
#else
                if (IsHighByteFF02044494(self, &token)) {
                    int skip = Dispatch02044420(self, &token);
#endif
                    if (skip) {
                        self->tokenIndex = self->tokenIndex + skip + 1;
                        continue;
                    }
                    if (token == stopA || token == stopB) break;
                    if (token == store) {
                        self->pendingValue = self->selectedValue;
                        self->pendingValueActive = 1;
                        CheckAndClearFlag020656e4(self, 1);
                    } else if (token == childFlag && self->child) {
                        SetFlag0x2IfByte0xd4Not3(self->child);
                    }
                }
                ++self->tokenIndex;
            }
            ProcessPendingFlag02045688(reinterpret_cast<State02045688*>(self));
            self->mode = 0;
            InitCombatSlots02043040(reinterpret_cast<char*>(self));
            func_02043124(self);
            ResetControllerState020430b0(reinterpret_cast<char*>(self));
        } else {
#if defined(jpn)
            if (!self->flags17ff.flag5) DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
#else
            if (!self->b19d3) DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
#endif
            self->mode = 5;
            ++self->tokenIndex;
            self->b912 = 0;
        }
        break;
    }
    }
    return 0;
}
