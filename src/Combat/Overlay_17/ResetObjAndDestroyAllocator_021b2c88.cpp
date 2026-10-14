#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void PopStack1AndTrigger_020a1f4c(int flag);
void PopStack0AndTrigger_020a1e54(int flag);
void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern int data_ov017_021d840c;
extern int data_02114e20;

struct Obj021b2c88 {
	char pad[0xc];
	SafeAllocator allocator;
};

// USA: func_ov017_021b2c88  (semantic: ResetObjAndDestroyAllocator_021b2c88)
extern "C" ARM void func_ov017_021b2c88(struct Obj021b2c88* self) {
	if (data_ov017_021d840c != 0) {
		PopStack1AndTrigger_020a1f4c(1);
		PopStack0AndTrigger_020a1e54(1);
		data_ov017_021d840c = 0;
	}

	void* p = self->allocator.GetSignedAllocator();
	self->allocator.Destroy();
	TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
}
