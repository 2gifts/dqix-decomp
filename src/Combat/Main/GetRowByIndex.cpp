#include <globaldefs.h>

struct GetRowByIndexRow { char pad[0x4c]; };

// USA: func_0209b9c0
ARM struct GetRowByIndexRow* GetRowByIndex_0209b9c0(struct GetRowByIndexRow *base, int i) {
    if (i < 0 || i >= 6) return NULL;
    return &base[i];
}
