#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Node0201ebc4 {
    void* buf;
    int f4;
    int count;
};
struct Container0201ebc4 {
    int f0;
    SafeAllocator* alloc;
    Node0201ebc4* node;
};
extern Container0201ebc4 data_020fdc40;

// USA: func_0201ebc4
ARM int AllocNode0201ebc4(Variant02030b0c* p) {
    int count = ((Script::Parameter*)p)->ToInt();
    Node0201ebc4* node = data_020fdc40.node;
    node->buf = data_020fdc40.alloc->Allocate(count * 0xc);
    node->count = count;
    return 1;
}
