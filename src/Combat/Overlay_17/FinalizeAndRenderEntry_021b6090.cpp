#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3copy0202ec84 { unsigned int v[3]; };
int ComputeTwoFromVec3_0202ec84(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2);

struct StructAt020473c8;
void RenderFlaggedIndexedEntry(struct StructAt020473c8* obj, int param1);

int GetField0x3b0Value(GameState* battleStruct);
extern "C" short _Z8fix32sini(int x);

struct Obj021b6090 {
    char pad0[0x16];
    unsigned char field16;
    char pad1[0x20 - 0x17];
    void* field20;
    char pad2[0x2c - 0x24];
    struct Vec3copy0202ec84 field2c;
    int field38;
};

// USA: func_ov017_021b6090  (semantic: FinalizeAndRenderEntry_021b6090)
extern "C" ARM void func_ov017_021b6090(struct Obj021b6090* self) {
    GameState* battle = GameState::GetInstance();
    void* ptr3b0 = (void*)GetField0x3b0Value(battle);
    struct Vec3copy0202ec84 vecBuf = self->field2c;

    if (self->field38 < 0x191e) {
        self->field38 += battle->GetTickCount() * 0x199;
    }

    vecBuf.v[1] += _Z8fix32sini(self->field38);

    int outA, outB;
    if (ptr3b0 != NULL) {
        ComputeTwoFromVec3_0202ec84(ptr3b0, &vecBuf, &outA, &outB);
    }

    unsigned char* obj20 = (unsigned char*)self->field20;
    if (obj20 == NULL) return;

    int shiftedA = (outA - 0xc) << 0xc;
    int shiftedB = (outB - 0x28) << 0xc;
    *(int*)(obj20 + 0x1c) = shiftedA;
    *(int*)(obj20 + 0x20) = shiftedB;
    *(int*)(obj20 + 0x24) = 0;
    RenderFlaggedIndexedEntry((struct StructAt020473c8*)obj20, 1);

    unsigned char v = self->field16;
    unsigned short clamped = (v > 0x1f) ? 0x1f : v;
    *(unsigned short*)(obj20 + 0x82) = clamped;
}
