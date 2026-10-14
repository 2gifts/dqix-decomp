#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Obj020899bc {
    char pad[8];
    short field8;
};

extern struct Obj020899bc* data_02108efc;

// USA: func_020899bc
ARM int StoreVariantToGlobalField8_020899bc(struct Variant02030b0c* p) {
    data_02108efc->field8 = (short)((Script::Parameter*)p)->ToInt();
    return 1;
}
