#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void PopStack0AndTrigger(int flag);
void PopStack1AndTrigger(int flag);
void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern int data_02114e20;

struct Obj021c1a24 {
	char pad[8];
	SafeAllocator allocator;
	unsigned char b1c;
	unsigned char b1d;
	unsigned char pad1e[2];
	int f20;
};

// USA: func_ov017_021c1a24  (semantic: ClearFieldAndDestroyAllocator_021c1a24)
extern "C" ARM void func_ov017_021c1a24(struct Obj021c1a24* self) {
	if (self->f20 != 0) {
		self->f20 = 0;
		#if !defined(jpn)
		if (self->b1d != 0) {
			PopStack0AndTrigger(1);
		}
		#endif
		PopStack1AndTrigger(1);
	}

	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
	}

	self->allocator.ResetAllocatorPointer();
	self->b1c = 0;
}
