#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;
struct Foo0201c444;

extern void AllocateArray0201c444(struct Foo0201c444*, int);

struct GlobalList020fdc14 {
    int count;
    int pad4;
    struct Foo0201c444* array;
};
extern struct GlobalList020fdc14 data_020fdc14;

// USA: func_0201c1c8
ARM int AllocateListAndReset0201c1c8(struct Variant02030b0c* v) {
    int n = ((Script::Parameter*)v)->ToInt();
    AllocateArray0201c444(data_020fdc14.array, n);
    data_020fdc14.count = 0;
    return 1;
}
