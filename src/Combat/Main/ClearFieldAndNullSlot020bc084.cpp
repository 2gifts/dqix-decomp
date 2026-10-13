#include <globaldefs.h>
#pragma optimize_for_size off

struct Obj020bc084 {
    int field0;
};

static inline bool HasObj(struct Obj020bc084* const* slot) {
    return *slot != NULL;
}

// USA: func_020bc084
ARM void ClearFieldAndNullSlot020bc084(struct Obj020bc084** slot) {
    if (!HasObj(slot)) {
        return;
    }
    (*slot)->field0 = 0;
    *slot = NULL;
}
