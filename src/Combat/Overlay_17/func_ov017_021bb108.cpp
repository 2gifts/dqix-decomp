#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void DestroyActiveAllocators_0215aa5c(void);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern int data_02114e20;

// JPN: func_ov017_021bb700
// USA: func_ov017_021bb108
extern "C" ARM void func_ov017_021bb108(char* self) {
#if defined(jpn)
 enum {regionalOffset0=0x78, regionalOffset1=0x120, regionalOffset2=0x134};
#else
 enum {regionalOffset0=0x7c, regionalOffset1=0x124, regionalOffset2=0x138};
#endif
	void* p1 = ((SafeAllocator*)(self + regionalOffset0))->GetSignedAllocator();
	if (p1 != NULL) {
		DestroyActiveAllocators_0215aa5c();
		void* p2 = ((SafeAllocator*)(self + regionalOffset1))->GetSignedAllocator();
		if (p2 != NULL) {
			((SafeAllocator*)(self + regionalOffset1))->Destroy();
			((SafeAllocator*)(self + regionalOffset0))->Free(p2);
		}
		void* p3 = ((SafeAllocator*)(self + regionalOffset0))->GetSignedAllocator();
		((SafeAllocator*)(self + regionalOffset0))->Destroy();
		TailForward02012da4((AllocatorUnion*)&data_02114e20, p3);
	}
	if (*(SafeAllocator**)(self + regionalOffset2) == NULL) return;
	void* p4 = (*(SafeAllocator**)(self + regionalOffset2))->GetSignedAllocator();
	if (p4 == NULL) return;
	(*(SafeAllocator**)(self + regionalOffset2))->Destroy();
	TailForward02012da4((AllocatorUnion*)&data_02114e20, p4);
	*(SafeAllocator**)(self + regionalOffset2) = NULL;
}
