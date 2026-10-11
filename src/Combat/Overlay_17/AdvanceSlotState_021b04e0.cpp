// JPN: func_ov017_021b0b78
#if defined(jpn)
enum { RegionOffset950 = 0x8b8 };
#else
enum { RegionOffset950 = 0x950 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Ctx021b04e0 {
    char pad0[0xa];
    unsigned char byteA;
    char pad1[0x21 - 0xb];
    unsigned char state21;
    unsigned char idx22;
};

extern "C" void func_ov017_021d0b30(int a, int b, int c);
extern "C" void* func_ov017_021b0fe0(int a, int b);
extern "C" void func_ov017_021d1118(int a, int b, int c, int d);
extern "C" void func_ov017_021d1014(int a, int b, int c);
int GetFieldAt0x150(unsigned char* obj);
void* GetData02100044(void);
int CheckSlotsAllFree0205e488(void* obj);

// USA: func_ov017_021b04e0
ARM unsigned char AdvanceSlotState_021b04e0(struct Ctx021b04e0* self) {
    GameState* bs = GameState::GetInstance();
    unsigned char state = self->state21;
    if (state == 0) {
        unsigned char* ptr = (unsigned char*)GetPtrField0x2a04(bs);
        unsigned char idx = self->idx22;
        if (ptr[0xf7c] == idx) {
            func_ov017_021d0b30(4, 0, 0);
            return 0xb;
        }
        unsigned char slot = (ptr + idx)[0xf78];
        self->idx22 = idx + 1;
        GameObject* combatant = GetCombatantWithFlag0x100(bs, slot);
        if (combatant == NULL) {
            return self->byteA;
        }
        int field150 = GetFieldAt0x150((unsigned char*)combatant);
        int v = *(int*)((char*)field150 + RegionOffset950) & 0xff;
        func_ov017_021b0fe0(slot, v);
        func_ov017_021d1118(-1, 5, 1, 1);
        func_ov017_021d1014(-1, 1, 1);
        self->state21 = self->state21 + 1;
    } else if (state == 1) {
        void* data = GetData02100044();
        if (CheckSlotsAllFree0205e488(data) != 0) {
            self->state21 = 0;
        }
    }
    return self->byteA;
}
