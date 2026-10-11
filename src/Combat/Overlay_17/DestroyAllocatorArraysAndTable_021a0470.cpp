#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

struct T020545b8;
void DestroyAllocators020545b8(struct T020545b8* obj);
int TailForward02012da4(AllocatorUnion*, void*);

extern AllocatorUnion data_02114e20;
extern int data_ov017_021d68cc[];

// JPN: func_ov017_021a0f20
// USA: func_ov017_021a0470  (semantic: DestroyAllocatorArraysAndTable_021a0470)
extern "C" ARM void func_ov017_021a0470(char* self) {
#if defined(jpn)
 enum {regionalOffset0=0xb8};
#else
 enum {regionalOffset0=0x2c8};
#endif
	char* group = self + regionalOffset0;
	int i = 0;
	group = group + 0x1000;
	for (; i < 4; i++) {
		DestroyAllocators020545b8((struct T020545b8*)(group + i * 0x5ec));
	}

	for (int i = 0; data_ov017_021d68cc[i] >= 0; i++) {
		int off = data_ov017_021d68cc[i] * 0x14;
		void* p = ((SafeAllocator*)(self + 0x38 + off))->GetSignedAllocator();
		((SafeAllocator*)(self + 0x38 + off))->Destroy();
		((SafeAllocator*)(self + 0x38 + off))->ResetAllocatorPointer();
		if (p != NULL) {
			TailForward02012da4(&data_02114e20, p);
		}
	}
}
