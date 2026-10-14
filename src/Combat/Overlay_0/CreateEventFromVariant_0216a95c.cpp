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

// USA: func_ov000_0216a95c
ARM int CreateEventFromVariant_0216a95c(char* obj) {
    char* p = (char*)data_ov000_02184264.alloc->Allocate(0x14);
    int val = ((Script::Parameter*)((struct Variant02030b0c*)obj))->ToInt();
    float f = ((Script::Parameter*)((struct TaggedValue02030b44*)(obj + 8)))->ToFloat();
    int scaled = (int)(f * 4096.0f);
    *(int*)(p + 0x0) = 0;
    *(int*)(p + 0x4) = 0;
    *(int*)(p + 0x0) = 0x19;
    *(short*)(p + 0xe) = (short)scaled;
    *(short*)(p + 0xc) = (short)(val + 0x64);
    *(unsigned char*)(p + 0x10) = 0;
    *(int*)(p + 0x8) = 0;
    func_ov000_02169b78(p);
    return 1;
}
