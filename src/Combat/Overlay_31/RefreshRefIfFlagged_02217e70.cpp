#include <globaldefs.h>
#include "System/ProcessorContext.h"

void* LockMutex(Mutex*);

struct RefNode020c80f8;
struct Mutex;
void UnlockMutex(Mutex*);

// USA: func_ov031_02217e70
ARM void RefreshRefIfFlagged_02217e70(char *self) {
	if (*(unsigned char*)(self + 0x1000) != 0xff) return;
	LockMutex((Mutex*)(self + 0x3f8 + 0x1800));
	*(int*)(self + 0x1000 + 0xc10) = 1;
	UnlockMutex((Mutex*)(self + 0x3f8 + 0x1800));
	if (*(int*)(self + 0x1000 + 0xba4) == 0) return;
	AwaitContextCompletion((ProcessorContext*)(self + 0x1800 + 0x338));
}
