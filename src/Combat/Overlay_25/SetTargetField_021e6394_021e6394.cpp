#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif

struct Ctx021ef988 { char pad[kGlobalHolderInnerOffset]; void* target; };
extern struct Ctx021ef988 data_ov025_021ef988;

struct Param021e6394 { char pad[8]; int value; };

// USA: func_ov025_021e6394
ARM int SetTargetField_021e6394_021e6394(struct Param021e6394* p) {
    *(int*)((char*)data_ov025_021ef988.target + 0x560) = p->value;
    return 1;
}
