#include <globaldefs.h>
struct Mutex;
int UnlockMutex(Mutex*);

extern int data_02112754;

// USA: func_020d220c
extern "C" ARM void func_020d220c(void) {
    UnlockMutex((Mutex*)(&data_02112754));
}
