#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

int Reset3FieldsAndDispatch_0216aa10(void);
#if defined(jpn)
enum { handlerCount = 18 };
#define data_ov004_021700ec data_ov004_02170844
#else
enum { handlerCount = 19 };
#endif

struct Block0x4c_0216aa70 { unsigned int w[handlerCount]; };
extern struct Block0x4c_0216aa70 data_ov004_021700ec;
extern "C" void func_ov011_02184a24(void*, void*, int);
extern "C" void func_ov011_02184c28(void*, void*);

// USA: func_ov004_0216aa70
ARM void AllocateAndCopyBuf76_0216aa70(SafeAllocator* a, void* target) {
    struct Block0x4c_0216aa70 tmp = data_ov004_021700ec;
    void* buf = a->Allocate(sizeof(Block0x4c_0216aa70));
    memcpy(buf, &tmp, sizeof(Block0x4c_0216aa70));
    func_ov011_02184a24(target, buf, handlerCount);
    func_ov011_02184c28(target, (void*)Reset3FieldsAndDispatch_0216aa10);
}
