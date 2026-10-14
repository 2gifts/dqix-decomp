#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
struct Field150Holder02052e2c;
short* GetField150Ptr0x488_02052e2c(struct Field150Holder02052e2c* obj);

struct LocalEvt021c44d8 {
    unsigned char pad0[4];
    unsigned char field4;
    unsigned char field5;
    unsigned char field6;
    unsigned char field7;
    unsigned char field8;
    unsigned char pad9;
    short fielda;
    short fieldc;
    short fielde;
    signed char field10;
};

struct Entry150_021c44d8 {
    char pad[0x14];
    unsigned char bit0 : 1;
    unsigned char bits1_3 : 3;
    unsigned char bits4_7 : 4;
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
    short f16;
    short f18;
    short f1a;
};

// USA: func_ov017_021c44d8  (semantic: CopyEventBitsIntoEntry_021c44d8)
extern "C" ARM void func_ov017_021c44d8(int unused0, struct LocalEvt021c44d8* evt, GameState* battleStruct, int unused3, struct SearchStruct0202c1a4* search) {
    if (evt->field10 >= 0) {
        signed char cur = GetSearchStructCurrentArrEntry(search);
        if (evt->field10 != cur) return;
    }
    unsigned char key = evt->field4;
    signed char cur2 = GetSearchStructCurrentArrEntry(search);
    if (key == cur2) return;

    GameObject* c = GetCombatantWithFlag0x100_0200ff1c(battleStruct, key);
    if (!c) return;

    struct Entry150_021c44d8* entry = (struct Entry150_021c44d8*)GetField150Ptr0x488_02052e2c((struct Field150Holder02052e2c*)c);
    if (!entry) return;

    entry->lowNibble = evt->field5;
    entry->bits4_7 = evt->field6;
    entry->bits1_3 = evt->field7;
    entry->bit0 = evt->field8;
    entry->f16 = evt->fielda;
    entry->f18 = evt->fieldc;
    entry->f1a = evt->fielde;
}
