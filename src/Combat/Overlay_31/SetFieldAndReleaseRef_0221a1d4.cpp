#include <globaldefs.h>

struct Mutex;
void LockMutex(Mutex*);
struct RefNode020c80f8;
void UnlockMutex(Mutex*);

extern char *data_ov031_0224e60c;

// USA: func_ov031_0221a1d4  (semantic: SetFieldAndReleaseRef_0221a1d4)
extern "C" ARM void func_ov031_0221a1d4(int a) {
	LockMutex((Mutex*)(data_ov031_0224e60c + 0x1dc + 0x1000));
	*(int*)(data_ov031_0224e60c + 0x1000) = a;
	UnlockMutex((Mutex*)(data_ov031_0224e60c + 0x1dc + 0x1000));
}
