#include <globaldefs.h>
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

struct Node02198f84 {
    unsigned char pad0[0x20];
    short field_0x20;
    unsigned char pad22[0x2c - 0x22];
    unsigned char field_0x2c;
    unsigned char field_0x2d;
    unsigned short low : 4;
    unsigned short flags : 12;
    unsigned short id;
    unsigned char pad32[0x38 - 0x32];
    Vector3i pos;
    Vector3i vecA;
    Vector3i vecB;
    Vector3i vecC;
    short field_0x68;
    short field_0x6a;
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
    unsigned char pad0[0x36b8];
    unsigned char nodeCount;
    unsigned char pad36b9[3];
    Node02198f84* nodes[0x10];
    struct TailList020469b4* tailList;
    unsigned char pad3700[0x3b10 - 0x3700];
    struct Struct021ab250* state6;
    unsigned char pad3b14[0x42ec - 0x3b14];
    unsigned short field_0x42ec;
};

extern "C" void* func_02012fe4(void);
extern "C" void* func_0205ec34(void);
extern "C" int _Z28LookupAndForEachNode020649b0PviS_(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);
extern "C" void func_02018300(void* a, void* node, int b, int c, int d);
extern "C" void _Z19InitState6_021ab250P14Struct021ab250(struct Struct021ab250* p);
Pending02198f84* GetField0x3f8Address(GameState* state);
extern "C" void _Z29SetIntField_021ab698_021ab698Pci(char* p, int v);
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_02198f84
extern "C" ARM void func_ov017_02198f84(Self02198f84* self) {
    void* ctx = func_02012fe4();
    for (int i = 0; i < self->nodeCount; i++) {
        Node02198f84* node = self->nodes[i];
        if (node == NULL) {
            continue;
        }
        int clear = 0;
        void* r = func_0205ec34();
        Query02198f84 q;
        q.field_0x28 = node->field_0x20;
        q.field_0x1e = node->field_0x2d;
        q.field_0x1c = node->field_0x2c;
        if (_Z28LookupAndForEachNode020649b0PviS_(r, 0x11, &q)) {
            func_0206f81c(&q);
        }
        if (!(node->flags & 4)) {
            func_02018300(ctx, node, 1, 1, 1);
            if ((node->flags & 8) && node->id != 0) {
                _Z19InitState6_021ab250P14Struct021ab250(self->state6);
                Pending02198f84* pending = GetField0x3f8Address(GameState::GetInstance());
                if (pending->pending != 0) {
                    node->id = pending->id;
                    node->pos = pending->pos;
                    node->field_0x68 = pending->field_0x1c;
                    node->field_0x6a = pending->field_0xb;
                    node->vecA = pending->vecA;
                    node->vecB = pending->vecB;
                    node->vecC = pending->vecC;
                    pending->pending = 0;
                }
                _Z29SetIntField_021ab698_021ab698Pci((char*)self->state6, (int)node);
                AppendNodeToTail(self->tailList, (struct TailNode020469b4*)self->state6);
            } else if (!(node->flags & 8)) {
                clear = 1;
            }
        } else {
            self->field_0x42ec = 0;
            node->flags &= ~4;
        }
        if (clear) {
            self->field_0x42ec = 0;
        }
    }
}
