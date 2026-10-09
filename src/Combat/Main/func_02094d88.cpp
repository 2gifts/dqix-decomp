#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
extern "C" void* func_0205ec34(void);

struct PackedNibbleArray0206e120 {
    unsigned char pad[0x2CC];
    unsigned char bits[1];
};
int GetPackedNibbleField(struct PackedNibbleArray0206e120* obj, int index);

extern "C" void func_0205ec70(SafeAllocator* alloc, int limit, struct Variant02030b0c* arr, void* dst8, void* dstc);

struct Owner020958fc { unsigned char pad[0xa0]; void* slot; };
struct Node020958fc {
    unsigned short f0;
    unsigned short bits2 : 9;
    unsigned short bit9  : 1;
    unsigned short bit10 : 1;
    unsigned short bit11 : 1;
    unsigned short bit12 : 1;
    unsigned short bit13 : 1;
    unsigned short pad2  : 2;
    unsigned int   bits4a : 8;
    unsigned int   bits4b : 6;
    unsigned int   bits4c : 5;
    unsigned int   pad4   : 13;
    int f8;
    void* link;
};
void SetSlotA0(struct Owner020958fc* owner, struct Node020958fc* node);

struct Manager02109404 {
    unsigned char f0;
    unsigned char pad1[2];
    unsigned char f3;
    unsigned char f4;
    unsigned char pad5[3];
    unsigned short f8;
    unsigned char pad10[2];
    SafeAllocator* alloc;
};
extern Manager02109404 data_02109404;
extern Owner020958fc data_02109418;

// USA: func_02094d88
extern "C" ARM int func_02094d88(struct Variant02030b0c* arr, int b) {
    int p0 = _ZNK6Script9Parameter5ToIntEv(&arr[0]);
    int p1 = _ZNK6Script9Parameter5ToIntEv(&arr[1]);
    if (p1 == data_02109404.f8) {
        goto tail;
    }
    if (data_02109404.f8 < 0xC3B5) {
        goto early;
    }
    if (data_02109404.f8 > 0xC3B5 + 0x130) {
        goto early;
    }
    if (p1 == 0xC3B5) {
        goto tail;
    }
    return 0;
early:
    return 1;
tail:
    int p2 = _ZNK6Script9Parameter5ToIntEv(&arr[2]);
    int p3 = _ZNK6Script9Parameter5ToIntEv(&arr[3]);
    int p4 = _ZNK6Script9Parameter5ToIntEv(&arr[4]);
    if (p3 * 100 + p4 > data_02109404.f3 * 100 + data_02109404.f4) {
        return 0;
    }
    int p5 = _ZNK6Script9Parameter5ToIntEv(&arr[5]);
    void* nibbles = func_0205ec34();
    int p6 = _ZNK6Script9Parameter5ToIntEv(&arr[6]);
    if (p6 >= 0) {
        int ok = (GetPackedNibbleField((struct PackedNibbleArray0206e120*)nibbles, p6) == 3);
        if (ok == 0) {
            return 0;
        }
    }

    struct Node020958fc* node = (struct Node020958fc*)data_02109404.alloc->Allocate(0x10);
    node->f0 = p1;
    node->bits2 = p0;
    node->bits4a = p2;
    node->bits4b = p3;
    node->bits4c = p4;
    node->bit9 = p5;

    int p7 = _ZNK6Script9Parameter5ToIntEv(&arr[7]);
    node->bit11 = p7;
    int p8 = _ZNK6Script9Parameter5ToIntEv(&arr[8]);
    node->bit10 = p8;
    int p9 = _ZNK6Script9Parameter5ToIntEv(&arr[9]);
    node->bit12 = p9;
    int p10 = _ZNK6Script9Parameter5ToIntEv(&arr[10]);
    node->bit13 = p10;

    node->f8 = 0;
    node->link = 0;

    int local8 = 0;
    func_0205ec70(data_02109404.alloc, b - 0xb, &arr[11], &node->f8, &local8);

    SetSlotA0(&data_02109418, node);
    return 1;
}