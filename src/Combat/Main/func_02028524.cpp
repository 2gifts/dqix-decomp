#include <globaldefs.h>

struct Vec3s_02028524 {
    short x;
    short y;
    short z;
};

struct Vec3s32_02028524 {
    int x;
    int y;
    int z;
};

struct Node0x10_02028524 {
    unsigned char id;
    unsigned char pad1[3];
    struct Vec3s_02028524 vec;
    unsigned char pad2[6];
};

struct SearchCtx_02028524 {
    unsigned char pad0[2];
    unsigned char count;
    unsigned char pad1;
    struct Node0x10_02028524* nodes;
};

extern "C" void _Z9CopyVec3sP5Vec3sS0_(struct Vec3s_02028524* dst, struct Vec3s_02028524* src);
extern "C" int abs(int x);

// USA: func_02028524
extern "C" ARM int func_02028524(struct SearchCtx_02028524* ctx, struct Vec3s32_02028524* pos) {
    if (ctx->count == 0) return 0;

    int sx = pos->x << 4;
    int sy = pos->y << 4;
    int sz = pos->z << 4;
    struct Node0x10_02028524* nodes = ctx->nodes;

    int bestIdx = 0;
    struct Vec3s_02028524 v0;
    _Z9CopyVec3sP5Vec3sS0_(&v0, &nodes[0].vec);
    int bestDist = abs(v0.x - (sx >> 16)) + abs(v0.y - (sy >> 16)) + abs(v0.z - (sz >> 16));

    for (int i = 1; i < ctx->count; i++) {
        struct Vec3s_02028524 v;
        _Z9CopyVec3sP5Vec3sS0_(&v, &nodes[i].vec);
        int d = abs(v.x - (sx >> 16)) + abs(v.y - (sy >> 16)) + abs(v.z - (sz >> 16));
        if (d < bestDist) {
            bestIdx = i;
            bestDist = d;
        }
    }
    return bestIdx;
}