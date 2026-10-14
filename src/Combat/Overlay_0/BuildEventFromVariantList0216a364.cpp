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

// USA: func_ov000_0216a364
ARM int BuildEventFromVariantList0216a364(char* obj, int count) {
    char* p = (char*)data_ov000_02184264.alloc->Allocate(0x18);
    *(int*)(p + 0x0) = 0xc;
    int val0 = ((Script::Parameter*)((struct Variant02030b0c*)obj))->ToInt();
    *(short*)(p + 0x8) = (short)val0;
    *(unsigned char*)(p + 0xa) = 0;
    *(int*)(p + 0xc) = 0;
    *(int*)(p + 0x10) = 0;
    *(int*)(p + 0x14) = 0;

    obj += 8;
    if (*(unsigned short*)(p + 0x8) == 5 || *(unsigned short*)(p + 0x8) == 6) {
        *(int*)(p + 0x14) = 0x3fe66666;
    }

    if (count >= 2) {
        int val1 = ((Script::Parameter*)((struct Variant02030b0c*)obj))->ToInt();
        *(unsigned char*)(p + 0xa) = (unsigned char)val1;
        obj += 8;
    }

    if (count >= 3) {
        float f0 = ((Script::Parameter*)((struct TaggedValue02030b44*)obj))->ToFloat();
        *(float*)(p + 0xc) = f0;
        float f1 = ((Script::Parameter*)((struct TaggedValue02030b44*)(obj + 8)))->ToFloat();
        *(float*)(p + 0x10) = f1;
        float f2 = ((Script::Parameter*)((struct TaggedValue02030b44*)(obj + 0x10)))->ToFloat();
        *(float*)(p + 0x14) = f2;
    }

    func_ov000_02169b78(p);
    return 1;
}
