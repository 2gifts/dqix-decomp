#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void PopStack0AndTrigger_020a1e54(int flag);
void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern int data_02114e20;

struct Obj021bac8c {
	char pad0[0xc];
	SafeAllocator allocator;
	void* field20;
};

// USA: func_ov017_021bac8c  (semantic: PopStackAndForwardAllocator_021bac8c)
extern "C" ARM void func_ov017_021bac8c(struct Obj021bac8c* self) {
	if (self->field20 != NULL) {
		PopStack0AndTrigger_020a1e54(1);
		self->field20 = NULL;
	}

	void* p = self->allocator.GetSignedAllocator();
	self->allocator.Destroy();
	TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
}
