#include <globaldefs.h>

extern int data_ov031_022918a4;
struct Mutex;
void* LockMutex(Mutex*);

// USA: func_ov031_02240310
ARM void* AcquireData022918a4_02240310(void) {
    return LockMutex((Mutex*)&data_ov031_022918a4);
}
