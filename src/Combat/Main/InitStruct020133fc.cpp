#include <globaldefs.h>
#include "World/ZoneChest.h"

// USA: func_020133fc
ARM void InitStruct020133fc(ZoneChestRenderRecord* record) {
    StoreThreeWordsAt0x0020130a8(&record->position, 0, 0, 0);
    record->angleY = 0;
    record->angleX = 0;
    record->counter = 0;
    record->active = 1;
    record->secondPass = 0;
    record->recordIndex = -1;
    record->uniqueID = 0;
    record->owner = -1;
    record->object = NULL;
    record->delay = 0;
    record->taskID = -1;
    record->special = 0;
}
