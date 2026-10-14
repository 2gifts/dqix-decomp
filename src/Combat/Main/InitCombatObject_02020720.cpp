#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "System/Memory.h"
#include "Combat/MapDisplay.h"
#include "Combat/CombatScriptContext.h"

struct List0204af64;
ARM void ResetList0204af64(struct List0204af64* obj);

extern "C" ARM void func_0202445c(void* obj);

// USA: func_02020720  (semantic: InitCombatObject_02020720)
extern "C" ARM void func_02020720(MapDisplay* obj) {
    obj->forwardingX = 0;
    obj->forwardingY = 0;
    obj->names = 0;
    obj->nameCount = 0;
    obj->field28 = 0;
    obj->forwarding = 0;
    obj->forwardingCount = 0;
    obj->field34 = 0;
    obj->scale = 0x1000;
    int v = 0x1000 - 0x1400;
    obj->cameraBiasX = v;
    obj->cameraBiasZ = v;
    obj->mapState = 0;
    obj->mapPalette = 0;
    obj->forwardingFill = 0;
    obj->displayMode = 1;
    obj->forwardingPending = 0;
    obj->field754 = 0;
    obj->flags = obj->flags & 1;
    obj->state = 0;
    obj->fielda9c = 0;

    for (int i = 0; i < 4; i++) {
        obj->slots[i] = -1;
        obj->slotFlags[i] = 0;
        obj->flags758[i] = 0;
        obj->recordVisible[i] = 1;
    }

    ResetList0204af64(&obj->list4c);

    obj->field75c = 0;
    obj->field75d = 0;
    obj->field77a = 0;
    obj->field77c = 0;
    obj->field9b4 = 0;
    obj->field760 = 0;
    obj->field764 = 0;
    obj->field766 = 0;
    obj->field768 = 1;

    func_0202445c(obj);

    obj->field9bc = 0;
    obj->actionState = 0;
    data_020fdc4c.unknownCounter = 0;
    obj->fieldaa0 = 0;

    VectorizedMemset(obj->bytesaa2, 0, 0x100);
}
