#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { handlerCount = 36 };
#define data_ov004_0216ff00 data_ov004_02170668
#else
enum { handlerCount = 38 };
#endif

struct Block0x98_02165df4 { unsigned int w[handlerCount]; };
extern struct Block0x98_02165df4 data_ov004_0216ff00;
extern "C" void func_ov011_02184a24(void*, void*, int);
extern "C" void func_ov011_02184c28(void*, void*);
extern "C" void func_ov004_02165be4(void);

// USA: func_ov004_02165df4
ARM void CopyGlobalBlockAndDispatch_02165df4(SafeAllocator* a, void* target) {
    struct Block0x98_02165df4 tmp = data_ov004_0216ff00;
    void* buf = a->Allocate(sizeof(Block0x98_02165df4));
    memcpy(buf, &tmp, sizeof(Block0x98_02165df4));
    func_ov011_02184a24(target, buf, handlerCount);
    func_ov011_02184c28(target, (void*)func_ov004_02165be4);
}
