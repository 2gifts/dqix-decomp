#include <globaldefs.h>
#include "Combat/NameEntryQueue.h"

#if defined(jpn)
#define CheckThreeFlags_02195550 func_ov017_02196118
#endif

// USA: func_ov017_02195550
#if defined(jpn)
extern "C"
#endif
ARM int CheckThreeFlags_02195550(unsigned char* resources) {
    EntryQueueReceiver02195250* queue = (EntryQueueReceiver02195250*)resources;
    if (queue->changedEntryMask != 0) return 1;
    if (queue->active->state != 0) return 1;
    return queue->count != 0;
}
