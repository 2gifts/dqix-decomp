#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

extern "C" void func_ov011_02184770(void);
void PopStack1AndTrigger_020a1f4c(int flag);
void PopStack0AndTrigger_020a1e54(int flag);
void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern int data_02114e20;

struct GlobalWithSlot_021d83f0_021b2200 {
	unsigned int field0;
	int slot;
};
extern struct GlobalWithSlot_021d83f0_021b2200 data_ov017_021d83f0;

struct Obj021b2200 {
	char pad[0xc];
	int fieldc;
	char pad2[0x10 - 0x10];
	SafeAllocator allocator;
};

// USA: func_ov017_021b2200
ARM void ClearPendingAndDestroyAllocator_021b2200(struct Obj021b2200* self) {
	if (self->fieldc > -1) {
		int x = (int)BackgroundLoader::GetInstance();
		int y = self->fieldc;
		((BackgroundLoader*)(x))->RemoveTask((int)(y));
		self->fieldc = -1;
	}

	if (data_ov017_021d83f0.slot != 0) {
		func_ov011_02184770();
		data_ov017_021d83f0.slot = 0;
		PopStack1AndTrigger_020a1f4c(1);
		PopStack0AndTrigger_020a1e54(1);
	}

	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
	}
}
