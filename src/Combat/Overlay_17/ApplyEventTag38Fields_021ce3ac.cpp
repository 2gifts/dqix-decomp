#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kObjectEventFlagOffset = 0x2c6 };
#else
enum { kObjectEventFlagOffset = 0x2d2 };
#endif

GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
void SetField0x2d0(void*, int);
void SetField0x2d1(void*, int);
void SetByte0x1c8(unsigned char*, int);
void SetByte0x1c9(unsigned char*, int);

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
    SetField0x2d0(c, evt->field6);
    SetField0x2d1(c, evt->field7);
    SetByte0x1c8((unsigned char*)c, evt->field8);
    SetByte0x1c9((unsigned char*)c, evt->field9);
    *((unsigned char*)c + kObjectEventFlagOffset) = evt->fielda;
}
