#include <globaldefs.h>

#include "Combat/ManagerSelection.h"
#include <std_library_functions.h>

// USA: func_0209f774
extern "C" ARM void func_0209f774(void *manager, int mode) {
    ManagerSelectionPrefix *state = static_cast<ManagerSelectionPrefix *>(manager);
    int recordSize                = sizeof(SelectionRecord);
    if (mode == 0) {
        int count;
        int i;
        state->kept.count = 0;
        count             = state->source[0x8e07];
        for (i = 0; i < count; i++) {
            SelectionRecord *record = reinterpret_cast<SelectionRecord *>(state->source + 0x5c60 + i * recordSize);
            if (record != NULL && record->state1f != 0) {
                int index = state->kept.count++;
                memcpy(&state->kept.records[index], record, recordSize);
            }
        }
        return;
    }
    state->scratch.count = 0;
    memset(state->scratch.records, 0, sizeof(state->scratch.records));
    int i;
    for (i = 0; i < state->kept.count; i++) {
        SelectionRecord *record = &state->kept.records[i];
        if (record->state1f != 0) {
            int index = state->scratch.count++;
            memcpy(&state->scratch.records[index], record, recordSize);
        }
    }
    state->kept.count = state->scratch.count;
    memcpy(state->kept.records, state->scratch.records, sizeof(state->scratch.records));
}
