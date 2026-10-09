#include <globaldefs.h>

extern "C" int rand(void);

struct Vec3_021571f4 { int x, y, z; };

class Node021571f4 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void SetPosition(const Vec3_021571f4* v);
};

struct Block021571f4 {
    char pad0[0x1c];
    unsigned char counts[12];
    int numSpawned;
};
struct Struct021707d8_021571f4 { char pad[8]; Block021571f4* block; };
extern Struct021707d8_021571f4 data_ov004_021707d8;

extern "C" void* func_ov011_021849c8(void*);
extern "C" Node021571f4* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" void func_ov023_021fa078(void* obj, void* ctx, unsigned short val, Vec3_021571f4* srcVec, int p5, int p6);

// USA: func_ov004_021571f4
extern "C" ARM void func_ov004_021571f4(void* self, int total) {
    int count = total - data_ov004_021707d8.block->numSpawned;
    if (count == 0) return;

    for (int i = 0; i < count; i++) {
        int slot = rand() % 12;
        Block021571f4* blk = data_ov004_021707d8.block;
        while (blk->counts[slot] >= 10) {
            slot = (slot + 1) % 12;
        }
        blk->counts[slot]++;

        Block021571f4* block = data_ov004_021707d8.block;
        int n = block->counts[slot];
        int id = block->numSpawned + 0x578 + i;

        Node021571f4* node = func_ov023_021f6880(func_ov011_021849c8(self), id);
        if (node == 0 || func_ov023_021f6f10(node) != 0) {
            node = 0;
        }
        if (!node) return;

        Vec3_021571f4 pos;
        pos.x = (slot * 21) << 12;
        pos.y = (n * -19) << 12;
        pos.z = 0;
        node->SetPosition(&pos);

        Vec3_021571f4 dst;
        dst.x = (slot * 21) << 12;
        dst.y = (0xc0 - n * 19) << 12;
        dst.z = 0;

        void* effect = func_ov023_021f6880(func_ov011_021849c8(self), 0xffff);
        if (!effect) return;
        func_ov023_021fa078(effect, self, id, &dst, 0xd000, 0xd000);
    }
    data_ov004_021707d8.block->numSpawned = total;
}
