#include <globaldefs.h>

#if defined(jpn)
enum { kTemplateBytes = 0x5c, kTemplateWords = 0x17 };
#else
enum { kTemplateBytes = 0x60, kTemplateWords = 0x18 };
#endif

#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_ov011_02184a24(void* obj, void* v1, int v2);
extern unsigned char data_ov004_02170444;

// USA: func_ov004_021633ac
ARM void AllocateAndCopyStruct60_021633ac(SafeAllocator* a, void* obj) {
    void* buf = a->Allocate(kTemplateBytes);
    memcpy(buf, &data_ov004_02170444, kTemplateBytes);
    func_ov011_02184a24(obj, buf, kTemplateWords);
}
