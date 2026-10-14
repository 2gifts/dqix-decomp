#include <globaldefs.h>

struct Mutex;
void LockMutex(Mutex*);
struct RefNode020c80f8;
void UnlockMutex(Mutex*);

extern struct RefNode020c80f8 data_ov031_02290f8c;
extern int data_ov031_02290f88;

// USA: func_ov031_0223fa60
ARM int AcquireOnceFlag_0223fa60(void) {
	LockMutex((Mutex*)&data_ov031_02290f8c);
	int wasZero = (data_ov031_02290f88 == 0);
	if (wasZero) {
		data_ov031_02290f88 = 1;
	}
	UnlockMutex((Mutex*)&data_ov031_02290f8c);
	return wasZero;
}
