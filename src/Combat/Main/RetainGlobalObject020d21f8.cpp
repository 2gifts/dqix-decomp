#include <globaldefs.h>

struct Mutex;
int LockMutex(Mutex*);
extern int data_02112754;

// USA: func_020d21f8
extern "C" ARM void func_020d21f8(void) {
    LockMutex((Mutex*)&data_02112754);
}
