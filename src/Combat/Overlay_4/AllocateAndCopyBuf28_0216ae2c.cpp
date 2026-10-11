#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { handlerCount = 6 };
#define data_ov004_02170154 data_ov004_0217088c
#else
enum { handlerCount = 7 };
#endif

struct Block0x1c_0216ae2c { unsigned int w[handlerCount]; };
extern struct Block0x1c_0216ae2c data_ov004_02170154;
extern "C" void func_ov011_02184a24(void*, void*, int);
extern "C" void func_ov011_02184c28(void*, void*);
extern "C" void func_ov004_0216acf8(void);

// USA: func_ov004_0216ae2c
ARM void AllocateAndCopyBuf28_0216ae2c(SafeAllocator* a, void* target) {
    struct Block0x1c_0216ae2c tmp = data_ov004_02170154;
    void* buf = a->Allocate(sizeof(Block0x1c_0216ae2c));
    memcpy(buf, &tmp, sizeof(Block0x1c_0216ae2c));
    func_ov011_02184a24(target, buf, handlerCount);
#if !defined(jpn)
    func_ov011_02184c28(target, (void*)func_ov004_0216acf8);
#endif
}
