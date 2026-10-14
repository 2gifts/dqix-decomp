#include <globaldefs.h>

struct Mutex;
void LockMutex(Mutex*);
struct RefNode020c80f8;
void UnlockMutex(Mutex*);

extern struct RefNode020c80f8 data_ov031_02290f8c;
extern int data_ov031_02290f88;

// USA: func_ov031_0223faa8
ARM void ResetAndReleaseNode_0223faa8(void) {
	LockMutex((Mutex*)&data_ov031_02290f8c);
	data_ov031_02290f88 = 0;
	UnlockMutex((Mutex*)&data_ov031_02290f8c);
}
