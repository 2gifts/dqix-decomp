#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern void* data_ov031_0224e588;
int LockMutex(Mutex*);

struct RefNode020c80f8 {
	unsigned char unk[8];
	void* owner;
	int refCount;
};
struct Mutex;
extern void UnlockMutex(Mutex*);

extern "C" int func_ov031_02207434(void* a);
extern "C" void func_ov031_02210358(int a, int b);
extern void SetGlobal0224e588Deref_022103dc(void* value);

// USA: func_ov031_02210b4c  (semantic: ReleaseAndPollState_02210b4c)
extern "C" ARM void func_ov031_02210b4c(void) {
	int savedState = *(int*)((char*)data_ov031_0224e588 + 0x1b8);
	LockMutex((Mutex*)((char*)data_ov031_0224e588 + 0x1bc));
	*(int*)((char*)data_ov031_0224e588 + 0x1b8) = -59;
	UnlockMutex((Mutex*)((char*)data_ov031_0224e588 + 0x1bc));

	if (savedState >= 0) {
		int result = func_ov031_02207434((void*)savedState);
		if (result < 0) {
			func_ov031_02210358(5, 5 - 0x37);
		} else {
			do {
				SleepCurrentContext(100);
				result = func_ov031_02207434((void*)savedState);
			} while (result == -26);
			if (result != 0) {
				func_ov031_02210358(5, 5 - 0x37);
			}
		}
	}

	SetGlobal0224e588Deref_022103dc((void*)1);
}
