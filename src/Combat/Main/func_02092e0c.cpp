#include <globaldefs.h>
#include "GameState/GameState.h"
struct Container020e0310 { char data[0x1c]; };
struct Obj02092e0c {
    char pad[0x14];
    Container020e0310 container;
    short key;
    short timer;
    char pad34[3];
    unsigned char flags;
    signed char combatantId;
};
struct Obj02046574 {
    void* combatant;
    char pad4[0x998-4];
    int field_0x998;
    char pad99c[0x195b-0x99c];
    unsigned char flags;
    char pad195c[0x19b1-0x195c];
    unsigned char field_0x19b1;
};
struct CombatantInfo02092e0c { int fields[3]; };
extern "C" Obj02046574* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046380(void*);
int GetField0x3acValue(GameState*);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(Obj02046574*, int, char*);
extern "C" void _Z30InitObjFromCombatantId020e4bf4Pvi(void*, int);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310*, int);
extern "C" void func_0204500c(Obj02046574*, int, int, int);
extern "C" void func_02042b98(Obj02046574*, int, int, int, int);
// USA: func_02092e0c
extern "C" ARM void func_02092e0c(Obj02092e0c* obj) {
    if (obj->key >= 0) {
        Obj02046574* display = _Z26GetGlobalField0x1c020421a0v();
        func_02046380(display);
        GameState* state = GameState::GetInstance();
        GameObject* member = state->GetPartyMemberByIndex(GetField0x3acValue(state));
        if (member) _Z22SetIndexedName02046574P11Obj02046574iPc(display, 0, member->baseStats_->unk);
        CombatantInfo02092e0c info;
        _Z30InitObjFromCombatantId020e4bf4Pvi(&info, obj->combatantId);
        display->combatant = &info;
        func_0204500c(display, _Z21GetFieldByKey020e0434P17Container020e0310i(&obj->container, obj->key), 0, 0xe3);
        display->field_0x998 = 1;
        if ((obj->flags & 1) && (obj->flags & 2)) {
            display->field_0x19b1 = 0;
            func_02042b98(display, 2, 0x92, 0xfc, 0x4a);
            display->flags |= 2;
        }
        obj->key = -1;
        obj->timer = 0x78;
    }
}
