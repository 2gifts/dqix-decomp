#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct Struct0224e5e8_022169a0 {
	char pad[8];
	char *field8;
};
extern struct Struct0224e5e8_022169a0 data_ov031_0224e5e8;

void* LockMutex(Mutex*);
struct RefNode020c80f8;
struct Mutex;
void UnlockMutex(Mutex*);
void RefreshRefIfFlagged_02217e70(char *self);

// USA: func_ov031_022169a0  (semantic: ClearFlagAwaitContext_022169a0)
extern "C" ARM void func_ov031_022169a0(void) {
	char *base = data_ov031_0224e5e8.field8;
	if (base == 0) return;
	LockMutex((Mutex*)(base + 0x1000 + 0x3d8));
	*(int*)(data_ov031_0224e5e8.field8 + 0x1000 + 0x3f0) = 1;
	UnlockMutex((Mutex*)(data_ov031_0224e5e8.field8 + 0x3d8 + 0x1000));
	char *ctx = *(char**)(data_ov031_0224e5e8.field8 + 0x1000 + 0x314);
	if (ctx != 0) {
		RefreshRefIfFlagged_02217e70(ctx);
	}
	base = data_ov031_0224e5e8.field8;
	if (*(int*)(base + 0x1000 + 0x384) == 0) return;
	AwaitContextCompletion((ProcessorContext*)(base + 0x1000 + 0x318));
}
