#include <globaldefs.h>
#include "World/ZoneChest.h"
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct Pending02198f84 {
    unsigned short id;
    unsigned char pending;
    unsigned char pad3[0xb - 0x3];
    signed char field_0xb;
    unsigned char pad0c[0x10 - 0x0c];
    Vector3i pos;
    short field_0x1c;
    unsigned char pad1e[0x3c - 0x1e];
    Vector3i vecA;
    Vector3i vecB;
    Vector3i vecC;
};

struct Query02198f84 {
    unsigned char pad0[0x1c];
    unsigned short field_0x1c;
    unsigned short field_0x1e;
    unsigned char pad20[0x28 - 0x20];
    short field_0x28;
    unsigned char pad2a[0x34 - 0x2a];
};

struct Self02198f84 {
#if defined(jpn)
    unsigned char pad0[0x34a8];
#else
    unsigned char pad0[0x36b8];
#endif
    unsigned char nodeCount;
    unsigned char pad36b9[3];
    ZoneFeatures::Opcode6aEntry* nodes[0x10];
    struct TailList020469b4* tailList;
#if defined(jpn)
    unsigned char pad3700[0x38f0 - 0x34f0];
#else
    unsigned char pad3700[0x3b10 - 0x3700];
#endif
    struct Struct021ab250* state6;
    unsigned char pad3b14[0x42ec - 0x3b14];
    unsigned short field_0x42ec;
};

extern "C" void* func_02012fe4(void);
extern "C" void* func_0205ec34(void);
int LookupAndForEachNode020649b0(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);
void InitState6_021ab250(struct Struct021ab250* p);
Pending02198f84* GetField0x3f8Address_0200fd0c(GameState* state);
void SetIntField_021ab698_021ab698(char* p, int v);
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_02198f84
extern "C" ARM void func_ov017_02198f84(Self02198f84* self) {
    Zone3D* ctx = (Zone3D*)func_02012fe4();
    for (int i = 0; i < self->nodeCount; i++) {
        ZoneFeatures::Opcode6aEntry* node = self->nodes[i];
        if (node == NULL) {
            continue;
        }
        int clear = 0;
        void* r = func_0205ec34();
        Query02198f84 q;
        q.field_0x28 = node->unk_20;
        q.field_0x1e = node->unk_2c.type2.unk_1;
        q.field_0x1c = node->unk_2c.type2.unk_0;
        if (LookupAndForEachNode020649b0(r, 0x11, &q)) {
            func_0206f81c(&q);
        }
        if (!(node->unk_2c.type2.unk_2_high & 4)) {
            func_02018300(ctx, node, 1, 1, 1);
            if ((node->unk_2c.type2.unk_2_high & 8) && node->unk_2c.type2.maybeZone != 0) {
                InitState6_021ab250(self->state6);
                Pending02198f84* pending = GetField0x3f8Address_0200fd0c(GameState::GetInstance());
                if (pending->pending != 0) {
                    node->unk_2c.type2.maybeZone = pending->id;
                    node->unk_2c.type2.vectors_c[0] = pending->pos;
                    node->unk_2c.type2.unk_3c = pending->field_0x1c;
                    node->unk_2c.type2.unk_3e = pending->field_0xb;
                    node->unk_2c.type2.vectors_c[1] = pending->vecA;
                    node->unk_2c.type2.vectors_c[2] = pending->vecB;
                    node->unk_2c.type2.vectors_c[3] = pending->vecC;
                    pending->pending = 0;
                }
                SetIntField_021ab698_021ab698((char*)self->state6, (int)node);
                AppendNodeToTail(self->tailList, (struct TailNode020469b4*)self->state6);
            } else if (!(node->unk_2c.type2.unk_2_high & 8)) {
                clear = 1;
            }
        } else {
            self->field_0x42ec = 0;
            node->unk_2c.type2.unk_2_high &= ~4;
        }
        if (clear) {
            self->field_0x42ec = 0;
        }
    }
}
