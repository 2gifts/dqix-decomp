// JPN: func_ov017_021cccd8
#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150(unsigned char* obj);
void SetBit0x954StoreIndex0x950(unsigned char* obj, int index);
int GetField0x3acValue(GameState* battle);
extern "C" void func_020897b4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern "C" void _Z27InitAndRequeueEntry020e3b8cPciiiiiih(char* mgr, int index, int p3, int p4, int p5, int p6, int p7, unsigned char p8);

struct Evt021cc830 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned short id : 3;
    unsigned short value : 8;
    unsigned short slot : 4;
    unsigned short flagBit : 1;
    unsigned short field6;
    unsigned int field8;
    unsigned char fieldc;
    unsigned char fieldd;
    unsigned char fielde;
};

// USA: func_ov017_021cc830
extern "C" ARM void func_ov017_021cc830(void* unused0, struct Evt021cc830* evt, GameState* battle, char* mgr) {
    GameObject* c = GetCombatantWithFlag0x100(battle, evt->id);
    if (c == NULL) return;
    unsigned char* work = (unsigned char*)GetFieldAt0x150((unsigned char*)c);
    if (work == NULL) return;

    int slot = evt->slot;
    SetBit0x954StoreIndex0x950(work, slot);
    *(unsigned short*)(work + slot * 2 + 0x16c) = evt->value;
    *(work + slot + 0x186) = evt->fieldc;

    if (evt->flagBit) {
        if (evt->fieldd != 0) {
            unsigned short saved = *(unsigned short*)(work + 0x564);
            func_020897b4(evt->id, evt->value, slot, 0, evt->fielde, 0, 0, 0, 0);
            if (GetField0x3acValue(battle) == evt->id) {
                *(unsigned short*)(work + 0x564) = saved;
            }
        } else {
            int flags = 0;
            flags |= 3;
            if (evt->fielde == 0) flags |= 4;
            _Z27InitAndRequeueEntry020e3b8cPciiiiiih(mgr, evt->id, evt->value, slot, 0, flags, evt->field8, evt->fielde);
            return;
        }
    }
    *(unsigned int*)(work + slot * 4 + 0x138) = evt->field8;
}
