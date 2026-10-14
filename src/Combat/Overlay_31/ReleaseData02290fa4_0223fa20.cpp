#include <globaldefs.h>

extern int data_ov031_02290fa4;
struct RefNode020c80f8;
struct Mutex;
void UnlockMutex(Mutex*);

// USA: func_ov031_0223fa20
ARM void ReleaseData02290fa4_0223fa20(void) {
    UnlockMutex((Mutex*)&data_ov031_02290fa4);
}
