#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
extern "C" void _Z13SetField0x2d0Pvh(void* obj, int value);
extern "C" void _Z13SetField0x2d1Pvh(void* obj, int value);
extern "C" void _Z12SetByte0x1c8Phh(void* obj, int value);
extern "C" void _Z12SetByte0x1c9Phh(void* obj, int value);

struct LocalEvt021ce3ac {
    unsigned char pad0[4];
    unsigned short field4;
    signed char field6;
    signed char field7;
    signed char field8;
    signed char field9;
    unsigned char fielda;
};

// USA: func_ov017_021ce3ac
ARM void ApplyEventTag38Fields_021ce3ac(int unused0, LocalEvt021ce3ac* evt, GameState* battleStruct) {
    GameObject* c = GetCombatantWithFlag0x1000(battleStruct, evt->field4);
    if (c == NULL) {
        return;
    }
    _Z13SetField0x2d0Pvh(c, evt->field6);
    _Z13SetField0x2d1Pvh(c, evt->field7);
    _Z12SetByte0x1c8Phh(c, evt->field8);
    _Z12SetByte0x1c9Phh(c, evt->field9);
    *((unsigned char*)c + 0x2d2) = evt->fielda;
}
