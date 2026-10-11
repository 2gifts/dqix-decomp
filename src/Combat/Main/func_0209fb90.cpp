#include <globaldefs.h>

#include "Combat/ManagerSelection.h"
#include "std_library_functions.h"

// USA: func_0209fb90
extern "C" ARM void func_0209fb90(void *manager, int refilter) {
    ManagerSelectionPrefix *owner = (ManagerSelectionPrefix *) manager;
    int recordSize                = sizeof(SelectionRecord);
    if (refilter == 0) {
        int total;
        owner->kept.count = 0;
        total             = owner->source[0x8e07];
        for (int i = 0; i < total; ++i) {
            SelectionRecord *record = (SelectionRecord *) (owner->source + 0x5c60) + i;
            if (record != NULL && (record->flags1e & 0x36) == 0) {
                int index = owner->kept.count++;
                memcpy(&owner->kept.records[index], record, recordSize);
            }
        }
        return;
    }
    owner->scratch.count = 0;
    memset(owner->scratch.records, 0, sizeof(owner->scratch.records));
    for (int i = 0; i < owner->kept.count; ++i) {
        SelectionRecord *record = &owner->kept.records[i];
        if ((record->flags1e & 0x36) == 0) {
            int index = owner->scratch.count++;
            memcpy(&owner->scratch.records[index], record, recordSize);
        }
    }
    owner->kept.count = owner->scratch.count;
    memcpy(owner->kept.records, owner->scratch.records, sizeof(owner->kept.records));
}
