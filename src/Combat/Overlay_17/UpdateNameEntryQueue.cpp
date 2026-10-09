#include <globaldefs.h>

#include "Combat/NameEntryQueue.h"

// USA: func_ov017_02195250
extern "C" ARM void func_ov017_02195250(void *receiver, void *incomingEntry) {
    EntryQueueReceiver02195250 *queue = (EntryQueueReceiver02195250 *) receiver;
    Entry15_02195214 *entry           = (Entry15_02195214 *) incomingEntry;

    if (queue->active->state == 2 && queue->active->entry.a == entry->a) {
        entry->e = 1;
    } else {
        entry->e = 0;
    }
    for (int i = 0; i < queue->count; i++) {
        if (entry->a == queue->entries[i].a) {
            func_ov017_02195214(&queue->entries[i], entry);
            return;
        }
    }

    {
        ActiveEntry02195250 *active = queue->active;
        if (active->state == 1 && active->entry.a == entry->a) {
            active->state = 0;
            active->mode  = 0;
        }
    }
    if (queue->count < 3) {
        func_ov017_02195214(&queue->entries[queue->count++], entry);
    }
}
