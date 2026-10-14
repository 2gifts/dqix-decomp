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

struct Struct0205ec40 {
    unsigned short f0;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
    int f8;
    int fc;
    int f10;
    int f14;
};

void ClearStruct0205ec40(struct Struct0205ec40* s);
extern "C" void func_0205ec70(SafeAllocator* alloc, int limit, struct Variant02030b0c* arr, void* dst8, void* dstc);
struct Node020643fc;
void InsertNodeByKey020643fc(void* unused, struct Node020643fc* node);

extern char data_02108844;

// USA: func_0205f9cc
extern "C" ARM int func_0205f9cc(struct Variant02030b0c* arr, int b) {
    int id = _ZNK6Script9Parameter5ToIntEv(&arr[0]);
    if (id != *(int*)(&data_02108844 + 0x484)) {
        return 0;
    }

    int startSec = _ZNK6Script9Parameter5ToIntEv(&arr[1]);
    int startMs = _ZNK6Script9Parameter5ToIntEv(&arr[2]);
    int endSec = _ZNK6Script9Parameter5ToIntEv(&arr[3]);
    int endMs = _ZNK6Script9Parameter5ToIntEv(&arr[4]);

    int cur = *(int*)(&data_02108844 + 0x488);
    int start = startSec * 1000 + startMs;
    int end = endSec * 1000 + endMs;
    cur = cur * 1000 + *(int*)(&data_02108844 + 0x48c);
    if (cur < start || end < cur) {
        return 0;
    }

    SafeAllocator* alloc = *(SafeAllocator**)(&data_02108844 + 0x480);
    struct Struct0205ec40* node = (struct Struct0205ec40*)alloc->Allocate(0x18);
    if (node == NULL) {
        return 1;
    }

    ClearStruct0205ec40(node);
    node->f0 = id;
    node->f2 = startSec;
    node->f3 = endSec;
    node->f4 = startMs;
    node->f5 = endMs;
    node->f6 = _ZNK6Script9Parameter5ToIntEv(&arr[5]);

    func_0205ec70(alloc, b - 6, &arr[6], &node->f8, &node->fc);

    InsertNodeByKey020643fc(&data_02108844, (struct Node020643fc*)node);
    return 1;
}
