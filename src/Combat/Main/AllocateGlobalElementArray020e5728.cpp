#include <globaldefs.h>
#include "Resource/Script.h"

class SafeAllocator;
struct Variant02030b0c;
struct ElementArray020e5850;
void AllocateElementArray020e5850(struct ElementArray020e5850* self, SafeAllocator* alloc, int count);

extern void* data_021536c4[2];

// USA: func_020e5728
ARM int AllocateGlobalElementArray020e5728(struct Variant02030b0c* p) {
    int count = ((Script::Parameter*)p)->ToInt();
    AllocateElementArray020e5850((struct ElementArray020e5850*)data_021536c4[1],
                                 (SafeAllocator*)data_021536c4[0], count);
    return 1;
}
