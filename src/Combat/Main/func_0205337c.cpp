#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

void* GetDataPtr02114e04_020d6c00(void);
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);

struct Vec3copy0202ec84 { int x; int y; int z; };
ARM int ComputeTwoFromVec3_0202ec84(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2);

struct StructAt020473c8;
ARM void RenderFlaggedIndexedEntry(struct StructAt020473c8* obj, int param1);

struct Node0205337c {
    unsigned char pad0[0x1c];
    int screenX;
    int screenY;
    int depth;
};

struct Anim0205337c {
    signed char anim[5];
    signed char animIdx;
    signed char* GetTable() { return anim; }
    int GetIndex() const { return animIdx; }
};

struct Obj0205337c {
    unsigned char pad0[0x44];
    struct Vec3copy0202ec84 pose;
    unsigned char pad1[0x178 - 0x50];
    struct Anim0205337c anim;
    unsigned char pad2[0x190 - 0x17e];
    struct Node0205337c* node;
};

// USA: func_0205337c
extern "C" ARM void func_0205337c(struct Obj0205337c* obj) {
    if (TestFlags02046708((struct FlagWord02046708*)GetDataPtr02114e04_020d6c00(), 2)) return;
    if (obj->node == NULL) return;

    void* target = GetField0x3b0Value(GameState::GetInstance());
    *(volatile int*)0x4000444 = 0;

    struct Vec3copy0202ec84 pose = obj->pose;
    pose.y += 0x1b33;

    int outB, outA;
    ComputeTwoFromVec3_0202ec84(target, &pose, &outB, &outA);
    outB -= 0xc;
    outA -= 0xc;

    int idx = obj->anim.GetIndex();
    signed char* animations = obj->anim.GetTable();
    int kind = animations[idx];
    if (!(kind != 0xc && kind != 0xd && kind != 0xe)) {
        outB -= 0xc;
        outA -= 6;
    } else if (kind == 0x1e) {
        outA += 4;
        outB += 4;
    }

    int sx = outB;
    int sy = outA;
    struct Node0205337c* node = obj->node;
    node->screenX = sx << 12;
    node->screenY = sy << 12;
    node->depth = -0xa000;

    RenderFlaggedIndexedEntry((struct StructAt020473c8*)obj->node, 1);
    *(volatile int*)0x4000448 = 1;
}
