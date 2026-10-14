#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void EnqueueTag33ForListedCombatant_021c12b0(unsigned char param);
extern int data_ov017_021d8478;
void PopStack1AndTrigger_020a1f4c(int flag);
void PopStack0AndTrigger_020a1e54(int flag);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern int data_02114e20;

struct Obj021c1394 {
	char pad[8];
	SafeAllocator allocator;
};

// USA: func_ov017_021c1394  (semantic: ResetAndPopStacks_021c1394)
extern "C" ARM void func_ov017_021c1394(Obj021c1394* self) {
	if (*(unsigned char*)((char*)self + 0x1e) != 0) {
		EnqueueTag33ForListedCombatant_021c12b0(0);
	}
	if (data_ov017_021d8478 != 0) {
		data_ov017_021d8478 = 0;
		PopStack1AndTrigger_020a1f4c(1);
		PopStack0AndTrigger_020a1e54(1);
	}
	void* p = self->allocator.GetSignedAllocator();
	self->allocator.Destroy();
	TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
}
