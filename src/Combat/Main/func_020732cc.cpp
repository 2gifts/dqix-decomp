#include <globaldefs.h>

#include "GameState/GameState.h"

extern void* GetPtrField0x2a04(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);

struct Field150Holder02052e2c;
short* GetField150Ptr0x488_02052e2c(struct Field150Holder02052e2c* obj);
void TryClearFlags0x130(unsigned char*, unsigned short);

struct KeyedList0207c378;
extern "C" int func_0207c378(struct KeyedList0207c378* obj, int value, int amount, int key);
extern "C" void func_ov017_0218f5a4(void* a, int i, int b, int c, int d);

struct Slot020732cc {
    unsigned char pad0[8];
    unsigned int keyBits : 4;
    unsigned int rest0 : 28;
};

extern signed short data_020e8854[];
extern signed short data_020e8864[];

#if defined(jpn)
enum { CombatantSlotOffset = 0x144 };
#else
enum { CombatantSlotOffset = 0x150 };
#endif

// USA: func_020732cc
extern "C" ARM void func_020732cc(int arg0) {
    GameState* gs = GameState::GetInstance();
    void* res = func_ov017_0218b5b0();
    void* p2a04 = GetPtrField0x2a04(gs);
    GameObject* combatant = GetCombatantWithFlag0x100(gs, arg0);
    if (combatant != NULL) {
        int i;
        short* list;
        struct Slot020732cc* slot;
        for (i = 0; i < 8; i++) {
            signed short idx = data_020e8854[i];
            char* base = *(char**)((char*)combatant + CombatantSlotOffset) + 0x194;
            slot = (struct Slot020732cc*)(base + (unsigned char)data_020e8864[idx] * 0x20);
            list = GetField150Ptr0x488_02052e2c(
                (struct Field150Holder02052e2c*)combatant);
            if (list != NULL && slot != NULL) {
                if (list[idx] > 0) {
                    TryClearFlags0x130((unsigned char*)combatant, 4);
                    func_0207c378((struct KeyedList0207c378*)((char*)p2a04 + 0x1d4),
                                  list[idx], 1, slot->keyBits);
                }
                list[idx] = -1;
            }
        }
        func_ov017_0218f5a4(res, arg0, 0, 0, 0);
    }
}
