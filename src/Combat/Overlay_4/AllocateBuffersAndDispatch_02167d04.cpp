#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void func_ov004_02167b78(void* a, int b);
#if defined(jpn)
extern "C" void func_ov004_02168074(void* a, int b);
#endif

struct DataStruct02171024 { void* field0; void* field4; void* field8; };
extern struct DataStruct02171024 data_ov004_02171024;

// USA: func_ov004_02167d04
ARM int AllocateBuffersAndDispatch_02167d04(void* a) {
#if defined(jpn)
	func_ov004_02168074(a, 0);
#else
	void* base = func_ov011_021845f8(a, 0);
	if (base != NULL) {
		SafeAllocator* alloc = (SafeAllocator*)((char*)base + 4);
		data_ov004_02171024.field4 = alloc->Allocate(0xc);
		data_ov004_02171024.field0 = alloc->Allocate(0x80);
		data_ov004_02171024.field8 = alloc->Allocate(0x80);
		func_ov004_02167b78(a, 0);
	}

#endif
	return 0;
}
