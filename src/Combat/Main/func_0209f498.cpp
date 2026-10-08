#include <globaldefs.h>

#include "Combat/ManagerSelection.h"
#include "std_library_functions.h"

// USA: func_0209f498
extern "C" ARM void func_0209f498(void *manager, int mode) {
    ManagerSelectionPrefix *owner = static_cast<ManagerSelectionPrefix *>(manager);
    int recordSize                = sizeof(SelectionRecord);
    if (mode == 0) {
        int total;
        owner->kept.count = 0;
        total             = owner->source[0x8e07];
        for (int i = 0; i < total; ++i) {
            SelectionRecord *record = reinterpret_cast<SelectionRecord *>(owner->source + 0x5c60) + i;
            if (record != NULL) {
                int excluded = 0;
                if (record->value12 >= 7 && record->value12 <= 18) {
                    excluded = 1;
                }
                if (excluded != 0) {
                    continue;
                }
                int positive = 0;
                for (int j = 0; j < 8; ++j) {
                    if (record->values30[j] > 0) {
                        positive = 1;
                        break;
                    }
                }
                if (positive == 0) {
                    int index = owner->kept.count++;
                    memcpy(&owner->kept.records[index], record, recordSize);
                }
            }
        }
        return;
    }
    owner->scratch.count = 0;
    memset(owner->scratch.records, 0, sizeof(owner->scratch.records));
    for (int i = 0; i < owner->kept.count; ++i) {
        SelectionRecord *record = &owner->kept.records[i];
        int excluded            = 0;
        if (record->value12 >= 7 && record->value12 <= 18) {
            excluded = 1;
        }
        if (excluded == 0) {
            int positive = 0;
            for (int j = 0; j < 8; ++j) {
                if (record->values30[j] > 0) {
                    positive = 1;
                    break;
                }
            }
            if (positive == 0) {
                int index = owner->scratch.count++;
                memcpy(&owner->scratch.records[index], record, recordSize);
            }
        }
    }
    owner->kept.count = owner->scratch.count;
    memcpy(owner->kept.records, owner->scratch.records, sizeof(owner->kept.records));
}
