#if defined(jpn)
#define R(j,u) (j)
#define _Z23EmptyDestructor0205cb60Pv func_0205deb8
#define _Z25ResetDisplayState02155480P11Obj02155480 func_ov006_02156b68
#define data_ov011_021889a0 data_ov011_02189700
#define data_ov013_02187dd8 data_ov013_02188cf0
#define func_ov006_02154fe4 func_ov006_02156730
#define func_ov006_021570fc func_ov006_02158704
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Container02186e74 {
	SafeAllocator* arr; // 0x0
};

extern int data_ov013_02187dd8[R(4,5)];

// USA: func_ov013_02186e74
ARM void InitAllocatorArray02186e74(struct Container02186e74* obj, SafeAllocator* allocator) {
	unsigned char i;

	if (allocator == NULL) return;

	obj->arr = (SafeAllocator*)allocator->Allocate(R(0x50,0x64));

	for (i = 0; i < R(4,5); i++) {
		SafeAllocator* base = (SafeAllocator*)((char*)obj->arr + i * 0x14);
		int sz;
		void* ptr;
		base->ResetAllocatorPointer();
		sz = data_ov013_02187dd8[i];
		ptr = allocator->Allocate(sz);
		base->CreateTypeA(ptr, sz);
	}
}
