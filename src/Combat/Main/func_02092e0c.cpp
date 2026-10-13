#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
struct Container020e0310 {
    unsigned int count : 12;
    unsigned int stringBytes : 19;
    unsigned int ownsStorage : 1;
    void* entries;
    char* strings;
};
struct MessageController {
    SafeAllocator allocator;
    Container020e0310 messages;
    char unknown20[0xc];
    int loadTask;
    short messageKey;
    short messageDelay;
    char unknown34[3];
    unsigned char flags;
    signed char namedPartySlot;
};
struct Obj02046574 {
    void* combatant;
#if defined(jpn)
    char unknown4[0x868 - 4];
#else
    char pad4[0x998-4];
#endif
    int active;
#if defined(jpn)
    char unknownAfterActive[0x1730 - 0x86c];
    int unknown1730;
    int unknown1734;
    char unknown1738[0x1789 - 0x1738];
#else
    char unknownAfterActive[0x195b - 0x99c];
#endif
    unsigned char flags;
#if defined(jpn)
    char unknownAfterFlags[0x17e1 - 0x178a];
#else
    char pad195c[0x19b1-0x195c];
#endif
    unsigned char state;
};
struct CombatantInfo02092e0c { int fields[3]; };
extern "C" Obj02046574* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046380(void*);
int GetField0x3acValue(GameState*);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(Obj02046574*, int, char*);
extern "C" void _Z30InitObjFromCombatantId020e4bf4Pvi(void*, int);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310*, int);
#if !defined(jpn)
extern "C" void func_0204500c(Obj02046574*, int, int, int);
#endif
extern "C" void func_02042b98(Obj02046574*, int, int, int, int);
#if defined(jpn)
extern "C" void func_0204500c(Obj02046574*, int, int);
extern "C" void func_02043270(Obj02046574*, int, int, int, int);
#endif
// USA: func_02092e0c
extern "C" ARM void func_02092e0c(MessageController* messages) {
    if (messages->messageKey >= 0) {
        Obj02046574* display = _Z26GetGlobalField0x1c020421a0v();
        func_02046380(display);
        GameState* state = GameState::GetInstance();
        GameObject* member = state->GetPartyMemberByIndex(GetField0x3acValue(state));
        if (member) _Z22SetIndexedName02046574P11Obj02046574iPc(display, 0, member->baseStats_->unk);
#if defined(jpn)
        member = state->GetPartyMemberByIndex(messages->namedPartySlot);
        if (member) _Z22SetIndexedName02046574P11Obj02046574iPc(display, 1, member->baseStats_->unk);
        func_0204500c(display, _Z21GetFieldByKey020e0434P17Container020e0310i(&messages->messages, messages->messageKey), 0);
        display->active = 1;
        if ((messages->flags & 1) && (messages->flags & 2)) {
            display->state = 0;
            display->unknown1730 = 12;
            display->unknown1734 = 16;
            func_02043270(display, display->unknown1730, 0x90, 0x100, 0x30);
            display->flags |= 2;
        }
#else
        CombatantInfo02092e0c info;
        _Z30InitObjFromCombatantId020e4bf4Pvi(&info, messages->namedPartySlot);
        display->combatant = &info;
        func_0204500c(display, _Z21GetFieldByKey020e0434P17Container020e0310i(&messages->messages, messages->messageKey), 0, 0xe3);
        display->active = 1;
        if ((messages->flags & 1) && (messages->flags & 2)) {
            display->state = 0;
            func_02042b98(display, 2, 0x92, 0xfc, 0x4a);
            display->flags |= 2;
        }
#endif
        messages->messageKey = -1;
        messages->messageDelay = 0x78;
    }
}
