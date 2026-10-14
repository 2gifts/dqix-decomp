#include <globaldefs.h>

struct FlagObj {
    char unk[0x14];
    int flags;
};

struct Counter {
    char unk[0x8];
    int count;
};

struct IncObj {
    char unk[0x138];
    struct FlagObj* flagObj;
    char unk2[0x60];
    struct Counter* counter;
};

// USA: func_02053dd0
ARM void IncrementCounterUnlessFlagged_02053dd0(struct IncObj* obj) {
    struct Counter* counter = obj->counter;
    if (counter == 0 || (obj->flagObj->flags & 1) != 0) {
        return;
    }
    counter->count++;
}
