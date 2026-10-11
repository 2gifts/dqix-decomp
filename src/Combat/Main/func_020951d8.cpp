#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c {
    int tag;
    int val;
};

extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct Manager02109404 {
    unsigned char f0;
    unsigned char pad1[0xb];
    SafeAllocator* alloc;
};
extern Manager02109404 data_02109404;

struct Entry0210941c {
    unsigned int id : 9;
    unsigned int rest : 23;
    unsigned int f4;
    unsigned int f8;
    unsigned int fc;
};
extern struct Entry0210941c data_0210941c[];
extern unsigned char data_02109418[];

struct Node02095910 {
    unsigned short bits2 : 9;
    unsigned short bit9 : 1;
    unsigned short bit10 : 1;
    unsigned short count : 5;
    unsigned short small[13];
    unsigned short bigCount;
    unsigned short big[5];
    void* link;
};
struct Owner02095910 {
    unsigned char pad[0xa4];
    void* slot;
};
void SetSlotA4(struct Owner02095910* owner, struct Node02095910* node);

// USA: func_020951d8
extern "C" ARM int func_020951d8(struct Variant02030b0c* arr, int b) {
    struct Node02095910* node;
    int p0 = _ZNK6Script9Parameter5ToIntEv(&arr[0]);
    int p1 = _ZNK6Script9Parameter5ToIntEv(&arr[1]);
    struct Variant02030b0c* q = &arr[2];
    arr += 3;
    int p2 = _ZNK6Script9Parameter5ToIntEv(q);
    int n = data_02109418[0];
    struct Entry0210941c* tbl = data_0210941c;
    if (data_02109404.f0 == 0) {
        int i;
        for (i = 0; i < n; i++) {
            if (tbl[i].id == p0) {
                break;
            }
        }
        if (i == n) {
            return 0;
        }
    }
    node = (struct Node02095910*)data_02109404.alloc->Allocate(0x2c);
    node->bits2 = p0;
    node->bit9 = p1;
    node->bit10 = p2;
    int smallCount = 0;
    int bigCount = 0;
    int i;
    node->link = 0;
    for (i = 0; i < b - 3; i++) {
        int v = _ZNK6Script9Parameter5ToIntEv(arr);
        arr++;
        if ((v >> 16) == 1000) {
            if (bigCount <= 5) {
                node->big[bigCount] = v;
                bigCount++;
            }
        } else {
            if (smallCount <= 13) {
                node->small[smallCount] = v;
                smallCount++;
            }
        }
    }
    node->count = smallCount;
    node->bigCount = bigCount;
    SetSlotA4((struct Owner02095910*)&data_02109418, node);
    return 1;
}
