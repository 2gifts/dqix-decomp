#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct020a9ea4;
void ClearStruct020a9ea4(struct Struct020a9ea4* p);
extern "C" void* func_0205ec34(void);
void SetOrClearBitInArray_0206df6c(void* unused, unsigned char* array, int bit, int value);

struct Data_02163008 {
	SafeAllocator* alloc;
	char pad[0x4b4 - 4];
	void* field4b4;
	void* field4b8;
};
extern Data_02163008 data_ov001_021658b8;

// USA: func_ov001_02163008
ARM int InitAllocAndClearBits_02163008(void) {
	SafeAllocator* alloc = data_ov001_021658b8.alloc;
	void* p1 = alloc->Allocate(8);
	data_ov001_021658b8.field4b4 = p1;
	ClearStruct020a9ea4((struct Struct020a9ea4*)p1);
	void* p2 = alloc->Allocate(0x8000);
	data_ov001_021658b8.field4b8 = p2;
	memset(p2, 0, 0x8000);
	void* g = func_0205ec34();
	SetOrClearBitInArray_0206df6c(g, (unsigned char*)g + 0x8c, 0x1142, 1);
	return 1;
}
