#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { handlerCount = 19 };
#define data_ov004_0216fa8c data_ov004_0217021c
#else
enum { handlerCount = 20 };
#endif

struct Block80_0215502c {
	unsigned int words[handlerCount];
};

extern Block80_0215502c data_ov004_0216fa8c;

extern "C" int func_ov011_02184a24(int, void*, int);

// USA: func_ov004_0215502c
// JPN: func_ov004_021565a4
ARM int AllocateAndDispatch20_0215502c(SafeAllocator* alloc, int arg) {
	Block80_0215502c local = data_ov004_0216fa8c;
	void* buf = alloc->Allocate(sizeof(Block80_0215502c));
	memcpy(buf, &local, sizeof(Block80_0215502c));
	return func_ov011_02184a24(arg, buf, handlerCount);
}
