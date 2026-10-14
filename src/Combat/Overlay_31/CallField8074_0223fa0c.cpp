#include <globaldefs.h>

extern int data_ov031_02290fa4;
struct Mutex;
void* LockMutex(Mutex*);

// USA: func_ov031_0223fa0c
ARM void* CallField8074_0223fa0c(void) {
    return LockMutex((Mutex*)&data_ov031_02290fa4);
}
