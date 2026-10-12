#include <globaldefs.h>

struct Obj0220527c;
struct Obj_0220586c;
void* SetLookupFields_02205134(void*, void*, int);
int TailCall0220520cField64_0220527c(Obj0220527c*, void*);
extern "C" int func_ov031_0220586c(Obj_0220586c*);

struct LookupQueueState {
    char unknown0[0x70];
    short flags;
    signed char lookupKey;
    char unknown73;
    unsigned short value74;
    unsigned short value76;
    int value78;
};

struct LookupQueueRecord {
    char unknown0[0x10];
    unsigned short value74;
    unsigned short value76;
    int value78;
};

// USA: func_ov031_02205814
extern "C" ARM int func_ov031_02205814(void* obj) {
    LookupQueueState* state = (LookupQueueState*)obj;
    LookupQueueRecord* record = (LookupQueueRecord*)SetLookupFields_02205134(
        (void*)func_ov031_0220586c, state, state->lookupKey);
    if (record == NULL) return -33;
    record->value74 = state->value74;
    record->value76 = state->value76;
    record->value78 = state->value78;
    state->flags |= 2;
    return TailCall0220520cField64_0220527c((Obj0220527c*)state, record);
}
