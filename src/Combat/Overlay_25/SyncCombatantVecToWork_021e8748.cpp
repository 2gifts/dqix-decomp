#include <globaldefs.h>
#include "System/Matrix.h"

#if defined(jpn)
enum { kWorkVectorOffset = 0x71cc, kWorkFlagOffset = 0x71d8 };
#else
enum { kWorkVectorOffset = 0x6fdc, kWorkFlagOffset = 0x6fe8 };
#endif


struct CombatVectorWork {
    char unknown0[kWorkVectorOffset];
    Vector3i vector;
    unsigned char vectorUpdated;
};
CombatVectorWork* GetActiveCombatWork(void);

struct Obj021e8748 {
    char pad[8];
    Vector3i mid;
};

// USA: func_ov025_021e8748  (semantic: SyncCombatantVecToWork_021e8748)
extern "C" ARM int func_ov025_021e8748(struct Obj021e8748* obj) {
    CombatVectorWork* w = GetActiveCombatWork();
    if (w) {
        Vector3i local = obj->mid;
        w->vector = local;
        w->vectorUpdated = 1;
    }
    return 1;
}
