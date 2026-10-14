#include <globaldefs.h>

struct RefNode020c80f8;
struct Mutex;
void UnlockMutex(Mutex*);
extern struct RefNode020c80f8 data_ov031_022918a4;

// USA: func_ov031_02240324
ARM void ReleaseAllocatorRef_02240324(void) {
	UnlockMutex((Mutex*)&data_ov031_022918a4);
}
