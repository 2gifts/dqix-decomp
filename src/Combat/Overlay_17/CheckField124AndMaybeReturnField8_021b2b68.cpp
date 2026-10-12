#include <globaldefs.h>

#if defined(jpn)
#define func_ov017_021b2b68 func_ov017_021b3278
#endif
#include "Filesystem/BackgroundLoader.h"


extern "C" void func_ov017_0218b5b0(void);
extern "C" void func_ov017_0219b624(void);

struct Base021b2b68 { char pad[0x8]; int field8; char pad2[0x2c]; int field38; };

// USA: func_ov017_021b2b68  (semantic: CheckField124AndMaybeReturnField8_021b2b68)
extern "C" ARM int func_ov017_021b2b68(struct Base021b2b68* self) {
	if (((BackgroundLoader*)((void*)(int)BackgroundLoader::GetInstance()))->GetNumQueuedTasks() > 0) {
		return self->field8;
	}
	func_ov017_0218b5b0();
	func_ov017_0219b624();
	self->field38 &= ~4;
	return 3;
}
