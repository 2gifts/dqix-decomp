#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void func_ov011_02184a24(void* a, void* b, int c);

#if defined(jpn)
enum { handlerCount = 18 };
#define data_ov004_0216ffac data_ov004_02170708
#else
enum { handlerCount = 19 };
#endif

struct Buf021677b4 { unsigned int w[handlerCount]; };
extern struct Buf021677b4 data_ov004_0216ffac;

// USA: func_ov004_021677b4
ARM void AllocateAndCopyHandlerTable_021677b4(SafeAllocator* self, void* target) {
	struct Buf021677b4 buf = data_ov004_0216ffac;
	void* allocated = self->Allocate(sizeof(Buf021677b4));
	memcpy(allocated, &buf, sizeof(Buf021677b4));
	func_ov011_02184a24(target, allocated, handlerCount);
}
