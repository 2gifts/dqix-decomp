#include <globaldefs.h>

#if defined(jpn)
enum { kObjectEventFlagOffset = 0x2c6 };
#else
enum { kObjectEventFlagOffset = 0x2d2 };
#endif


#if defined(jpn)
#define ApplyEventTag38Fields_021ce3ac func_ov017_021ce854
#endif
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
void SetField0x2d0(void* obj, unsigned char value);
void SetField0x2d1(void* obj, unsigned char value);
void SetByte0x1c8(unsigned char* obj, unsigned char value);
void SetByte0x1c9(unsigned char* obj, unsigned char value);

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
#if defined(jpn)
extern "C"
#endif
ARM void ApplyEventTag38Fields_021ce3ac(int unused0, LocalEvt021ce3ac* evt, GameState* battleStruct) {
    GameObject* c = GetCombatantWithFlag0x1000(battleStruct, evt->field4);
    if (c == NULL) {
        return;
    }
    ((void (*)(void*, int))SetField0x2d0)(c, evt->field6);
    ((void (*)(void*, int))SetField0x2d1)(c, evt->field7);
    ((void (*)(void*, int))SetByte0x1c8)(c, evt->field8);
    ((void (*)(void*, int))SetByte0x1c9)(c, evt->field9);
    *((unsigned char*)c + kObjectEventFlagOffset) = evt->fielda;
}
