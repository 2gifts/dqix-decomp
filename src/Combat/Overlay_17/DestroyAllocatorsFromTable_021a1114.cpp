#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern int data_02114e20;
extern int data_ov017_021d6680[];

// USA: func_ov017_021a1114
ARM void DestroyAllocatorsFromTable_021a1114(char* obj) {
	for (int i = 0; data_ov017_021d6680[i] > -1; i++) {
		int off = data_ov017_021d6680[i] * 0x14;
		void* signedAlloc = ((SafeAllocator*)(obj + 0x38 + off))->GetSignedAllocator();
		if (signedAlloc) {
			((SafeAllocator*)(obj + 0x38 + off))->Destroy();
			TailForward02012da4((AllocatorUnion*)&data_02114e20, signedAlloc);
		}
	}
}
