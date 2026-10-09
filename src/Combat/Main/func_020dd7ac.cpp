#include <globaldefs.h>
#include "Combat/Main/MessageSlotTable.h"

// USA: func_020dd7ac  (semantic: InitMessageSlotTable_020dd7ac)
extern "C" ARM void func_020dd7ac(MessageSlotTable_020dd7ac* obj) {
    obj->flag = -1;
    obj->unused04 = 0;
    obj->ptrs[1] = obj->ptrs[0] = 0;
    obj->ptrs[2] = 0;
    obj->ptrs[3] = 0;
    obj->ptrs[4] = 0;
    obj->ptrs[5] = 0;
    obj->ptrs[6] = 0;
    obj->ptrs[7] = 0;
    obj->ptrs[8] = 0;
    obj->ptrs[9] = 0;
    obj->ptrs[10] = 0;
    obj->ptrs[11] = 0;
    obj->pad38 = 0;
    obj->ptrs[0] = &obj->f3e;
    obj->ptrs[1] = &obj->f42;
    obj->ptrs[2] = &obj->f48;
    obj->ptrs[3] = &obj->f50;
    obj->ptrs[4] = &obj->f58;
    obj->ptrs[5] = &obj->f60;
    obj->ptrs[6] = &obj->f66;
    obj->ptrs[7] = &obj->f6a;
    obj->ptrs[8] = &obj->f6e;
    obj->ptrs[9] = &obj->f72;
    obj->ptrs[10] = &obj->f76;
    obj->ptrs[11] = &obj->f7a;
    obj->f3e = 0;
    obj->f3c = 0;
    obj->f42 = 0;
    obj->f40 = 0;
    obj->f48 = 0;
    obj->f44 = 0;
    obj->f50 = 0;
    obj->f4c = 0;
    obj->f58 = 0;
    obj->f54 = 0;
    obj->f60 = 0;
    obj->f5c = 0;
    obj->f66 = 0;
    obj->f64 = 0;
    obj->f6a = 0;
    obj->f68 = 0;
    obj->f6e = 0;
    obj->f6c = 0;
    obj->f72 = 0;
    obj->f70 = 0;
    obj->f76 = 0;
    obj->f74 = 0;
    obj->f7a = 0;
    obj->f78 = obj->f7a;
}
