#include <globaldefs.h>

#if defined(jpn)
#define func_ov017_021a7280 func_ov017_021a7c28
#endif
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "GameState/GameState.h"

extern "C" void* func_02057924(void* obj);
extern "C" void func_02057f00(void* obj, int index);
extern "C" void func_020a0c0c(void);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
void SetByteField0x253(void* obj);
void ForwardField0xc0_0205ebec(void* obj);

extern char data_02108760;
extern int data_02114e20;

struct Obj021a7280 {
	char pad[0x30];
	SafeAllocator allocator;
};

// USA: func_ov017_021a7280  (semantic: ForwardAndDestroyAllocatorAt48_021a7280)
extern "C" ARM void func_ov017_021a7280(struct Obj021a7280* self) {
	func_02057f00(func_02057924(self), 0xd);

	SetByteField0x253(GameState::GetInstance()->GetUnknownGameObject());

	ForwardField0xc0_0205ebec(&data_02108760);

	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
	}

	func_020a0c0c();
}
