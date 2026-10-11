#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { handlerCount = 7 };
#define data_ov004_0216faec data_ov004_02170278
#else
enum { handlerCount = 8 };
#endif

struct Block02156dc8 { unsigned int v[handlerCount]; };

extern Block02156dc8 data_ov004_0216faec;

extern "C" int func_ov011_02184a24(int, void*, int);

// USA: func_ov004_02156dc8
// JPN: func_ov004_02157e90
ARM int AllocateAndDispatch8_02156dc8(SafeAllocator* alloc, int arg) {
    Block02156dc8 local = data_ov004_0216faec;
    void* buf = alloc->Allocate(sizeof(Block02156dc8));
    memcpy(buf, &local, sizeof(Block02156dc8));
    return func_ov011_02184a24(arg, buf, handlerCount);
}
