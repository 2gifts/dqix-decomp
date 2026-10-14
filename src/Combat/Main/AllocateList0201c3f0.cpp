#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;
struct Foo0201c414;

extern void AllocateArray0201c414(struct Foo0201c414*, int);

struct GlobalList020fdc14_c3f0 {
    int pad0;
    int pad4;
    struct Foo0201c414* array;
};
extern struct GlobalList020fdc14_c3f0 data_020fdc14;

// USA: func_0201c3f0
ARM int AllocateList0201c3f0(struct Variant02030b0c* v) {
    int n = ((Script::Parameter*)v)->ToInt();
    AllocateArray0201c414(data_020fdc14.array, n);
    return 1;
}
