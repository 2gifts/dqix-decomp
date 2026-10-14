#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
extern "C" void func_ov000_02169b78(void* p);

struct Data02184264 {
    char pad0[0x8];
    SafeAllocator* alloc;
};
extern struct Data02184264 data_ov000_02184264;

// USA: func_ov000_0216abc4
ARM int BuildEventFromVariantList0216abc4(char* obj, int count) {
    char* p = (char*)data_ov000_02184264.alloc->Allocate(0x10);

    if (count == 1) {
        *(int*)(p + 0x0) = 0;
        *(int*)(p + 0x4) = 0;
        *(int*)(p + 0x0) = 0x1e;
        int val = ((Script::Parameter*)((struct Variant02030b0c*)obj))->ToInt();
        *(int*)(p + 0xc) = val;
        *(signed char*)(p + 0x8) = -1;
        func_ov000_02169b78(p);
    } else if (count == 2) {
        *(int*)(p + 0x0) = 0;
        *(int*)(p + 0x4) = 0;
        *(int*)(p + 0x0) = 0x1e;
        int val0 = ((Script::Parameter*)((struct Variant02030b0c*)obj))->ToInt();
        *(unsigned char*)(p + 0x8) = (unsigned char)val0;
        int val1 = ((Script::Parameter*)((struct Variant02030b0c*)(obj + 8)))->ToInt();
        *(int*)(p + 0xc) = val1;
        func_ov000_02169b78(p);
    }

    return 1;
}
