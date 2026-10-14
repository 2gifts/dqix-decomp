#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct TaggedValue02030b44;
extern "C" void func_ov000_02169b78(void* p);

struct Data02184264 {
    char pad0[0x8];
    SafeAllocator* alloc;
};
extern struct Data02184264 data_ov000_02184264;

// USA: func_ov000_0216b088
ARM int BuildEventFromVariantList0216b088(char* obj, int count) {
    char* p = (char*)data_ov000_02184264.alloc->Allocate(0x10);
    *(int*)(p + 0x0) = 0;
    *(int*)(p + 0x4) = 0;
    *(int*)(p + 0x0) = 0x2b;

    int val0 = ((Script::Parameter*)((struct Variant02030b0c*)obj))->ToInt();
    *(unsigned char*)(p + 0x8) = (unsigned char)val0;
    int val1 = ((Script::Parameter*)((struct Variant02030b0c*)(obj + 8)))->ToInt();
    *(unsigned char*)(p + 0x9) = (unsigned char)val1;

    if (count >= 3) {
        float f = ((Script::Parameter*)((struct TaggedValue02030b44*)(obj + 0x10)))->ToFloat();
        *(int*)(p + 0xc) = (int)(f * 4096.0f);
    }

    func_ov000_02169b78(p);
    return 1;
}
