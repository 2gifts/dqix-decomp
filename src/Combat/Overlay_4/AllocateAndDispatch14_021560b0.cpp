#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { handlerCount = 13 };
#define data_ov004_02170360 data_ov004_02170c60
#else
enum { handlerCount = 14 };
#endif

extern char data_ov004_02170360[handlerCount * 4];

extern "C" int func_ov011_02184a24(int, void*, int);

// USA: func_ov004_021560b0
// JPN: func_ov004_0215749c
ARM int AllocateAndDispatch14_021560b0(SafeAllocator* alloc, int arg) {
    void* buf = alloc->Allocate(handlerCount * 4);
    memcpy(buf, data_ov004_02170360, handlerCount * 4);
    return func_ov011_02184a24(arg, buf, handlerCount);
}
