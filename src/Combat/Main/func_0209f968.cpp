#include <globaldefs.h>

#include "Combat/ManagerSelection.h"
#include <std_library_functions.h>

struct SelectionRecord0209f968 {
    unsigned char pad0[0x12];
    short value12;
    unsigned short value14;
    unsigned short value16;
    unsigned char pad18[0x28];
};

// USA: func_0209f968
extern "C" ARM void func_0209f968(void *manager, int mode, int key, int minCount) {
    ManagerSelectionPrefix *state = static_cast<ManagerSelectionPrefix *>(manager);
    int recordSize                = sizeof(SelectionRecord);
    int groupCount                = *reinterpret_cast<int *>(state->source + 0x8e20);
    if (mode != 0) {
        state->kept.count = 0;
        int count         = state->source[0x8e07];
        for (int group = 0; group < groupCount; group++) {
            for (int slot = 0; slot < 4; slot++) {
                state->scratch.count = 0;
                memset(state->scratch.records, 0, sizeof(state->scratch.records));
                for (int i = 0; i < count; i++) {
                    SelectionRecord0209f968 *record =
                        reinterpret_cast<SelectionRecord0209f968 *>(state->source + 0x5c60 + i * recordSize);
                    if (record != NULL && record->value16 == group && record->value12 == slot && record->value14 == key) {
                        int index = state->scratch.count++;
                        memcpy(&state->scratch.records[index], record, recordSize);
                    }
                }
                if (state->scratch.count >= minCount && state->scratch.count + state->kept.count < 16) {
                    memcpy(&state->kept.records[state->kept.count], state->scratch.records,
                           state->scratch.count * recordSize);
                    state->kept.count += state->scratch.count;
                }
            }
        }
    } else {
        state->scratch.count = 0;
        memset(state->scratch.records, 0, sizeof(state->scratch.records));
        for (int group = 0; group < groupCount; group++) {
            for (int slot = 0; slot < 4; slot++) {
                int localCount = 0;
                SelectionRecord localRecords[16] = {};
                for (int i = 0; i < state->kept.count; i++) {
                    SelectionRecord0209f968 *record =
                        reinterpret_cast<SelectionRecord0209f968 *>(&state->kept.records[i]);
                    if (record->value16 == group && record->value12 == slot && record->value14 == key) {
                        memcpy(&localRecords[localCount++], record, recordSize);
                    }
                }
                if (localCount >= minCount && localCount + state->scratch.count < 16) {
                    memcpy(&state->scratch.records[state->scratch.count], localRecords, localCount * recordSize);
                    state->scratch.count += localCount;
                }
            }
        }
        state->kept.count = state->scratch.count;
        memcpy(state->kept.records, state->scratch.records, sizeof(state->scratch.records));
    }
}
