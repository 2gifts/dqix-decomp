#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Array0215e85c;
void InitArray_0215e85c(struct Array0215e85c* self, class SafeAllocator* allocator, int count);

extern int data_ov003_02180cb8;

// USA: func_ov003_0215e5fc  (semantic: InitArrayFromVariant_0215e5fc)
extern "C" ARM int func_ov003_0215e5fc(struct Variant02030b0c* v) {
	int count = ((Script::Parameter*)v)->ToInt();
	SafeAllocator* alloc = (SafeAllocator*)*(int*)&data_ov003_02180cb8;
	struct Array0215e85c* obj = (struct Array0215e85c*)*(int*)((char*)&data_ov003_02180cb8 + 4);
	InitArray_0215e85c(obj, alloc, (short)count);
	return 1;
}
