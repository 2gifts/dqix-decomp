#include <globaldefs.h>

#include "Combat/ActionState.h"

// USA: func_02027304  (semantic: ClearActionStateForIdOrAll02027304)
extern "C" ARM void func_02027304(unsigned char *obj, int id) {
    if (id < 0) {
        int i;
        for (i = 0; i < 4; i++) {
            ClearActionState(&data_020fdc60[i], 0);
        }
        return;
    }
    if (id >= 4) return;
    {
        int i;
        unsigned char *p;
        for (i = 0; i < 4; i++) {
            p = obj + i;
            if (id == p[0x758]) {
                ClearActionState(&data_020fdc60[i], 0);
                return;
            }
        }
    }
}
