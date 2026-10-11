// JPN: func_ov017_021b0c5c
#if defined(jpn)
enum { RegionOffset950 = 0x8b8 };
#else
enum { RegionOffset950 = 0x950 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Ctx021b05c4 {
    char pad0[0xa];
    unsigned char byteA;
    char pad1[0xc - 0xb];
    unsigned char byteC;
    char pad2[0x1b - 0xd];
    unsigned char arr1b[4];
    char pad3[0x23 - 0x1f];
    unsigned char byte23;
    unsigned char byte24;
    unsigned char byte25;
};

void EnqueueEventTag23Field_021d0d58(void);
int GetFieldAt0x150(unsigned char* obj);
void* GetData02100044(void);
int CheckSlotsAllFree0205e488(void* obj);
extern "C" void* func_ov017_021b0fe0(int a, int b);

// USA: func_ov017_021b05c4  (semantic: AdvanceSlotQueue_021b05c4)
extern "C" ARM unsigned char func_ov017_021b05c4(struct Ctx021b05c4* self) {
    GameState* bs = GameState::GetInstance();
    if (self->byte23 == 0) {
        if (self->byte24 == 4) {
            EnqueueEventTag23Field_021d0d58();
            self->byte25 = 0;
            return 0xa;
        }
        int idx = -1;
        volatile unsigned char* p24 = &self->byte24;
        while (self->byte24 < 4) {
            if (self->byteC != self->byte24 && self->arr1b[self->byte24] != 3 && self->arr1b[self->byte24] != 0) {
                idx = self->byte24;
                self->byte24 = *p24 + 1;
                break;
            }
            self->byte24 = *p24 + 1;
        }
        if (idx < 0) {
            return self->byteA;
        }
        GameObject* combatant = GetCombatantWithFlag0x100(bs, idx);
        if (combatant == 0) {
            return self->byteA;
        }
        int field150 = GetFieldAt0x150((unsigned char*)combatant);
        int val = *(int*)((char*)field150 + RegionOffset950) & 0xff;
        func_ov017_021b0fe0(idx, val);
        self->byte23 = self->byte23 + 1;
    } else if (self->byte23 == 1) {
        void* data = GetData02100044();
        if (CheckSlotsAllFree0205e488(data) != 0) {
            self->byte23 = 0;
        }
    }
    return self->byteA;
}
