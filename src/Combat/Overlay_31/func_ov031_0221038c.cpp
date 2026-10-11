#include <globaldefs.h>
#include "System/Mutex.h"

struct State0221038c {
    int field0;
    volatile int state;
    Mutex mutex;
};
extern State0221038c* data_ov031_0224e588;

// USA: func_ov031_0221038c
extern "C" ARM void func_ov031_0221038c(int state) {
    State0221038c* context = data_ov031_0224e588;
    if (context == NULL) return;
    Mutex* mutex = &context->mutex;
    (void)context->state;
    LockMutex(mutex);
    if (data_ov031_0224e588->state != 2) data_ov031_0224e588->state = state;
    UnlockMutex(&data_ov031_0224e588->mutex);
}
