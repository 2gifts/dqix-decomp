#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Array02028754;

void AllocateClearArray02028754(struct Array02028754* obj, SafeAllocator* alloc, int count);

struct Globals02027fbc {
    struct Array02028754* obj;
    SafeAllocator* alloc;
};
extern struct Globals02027fbc data_020fdd30;

// USA: func_02027fbc
ARM int AllocClearFromVariant02027fbc(struct Variant02030b0c* p) {
    int count = ((Script::Parameter*)p)->ToInt();
    AllocateClearArray02028754(data_020fdd30.obj, data_020fdd30.alloc, count);
    return 1;
}
