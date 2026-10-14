#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Struct02030b7c;
extern "C" void func_ov000_02169b78(void* p);

struct Data02184264 {
    char pad0[0x8];
    SafeAllocator* alloc;
};
extern struct Data02184264 data_ov000_02184264;

// USA: func_ov000_0216b180
ARM int BuildStringEventFromVariant0216b180(struct Struct02030b7c* obj, int count) {
    char* p = (char*)data_ov000_02184264.alloc->Allocate(0xc);
    *(int*)(p + 0x0) = 0;
    *(int*)(p + 0x4) = 0;
    *(int*)(p + 0x0) = 0x2e;
    *(void**)(p + 0x8) = 0;

    if (count <= 1) {
        char* text = (char*)(void*)((Script::Parameter*)obj)->ToString();
        if (text) {
            int len = strlen(text);
            char* buf = (char*)data_ov000_02184264.alloc->Allocate(len + 1);
            *(void**)(p + 0x8) = buf;
            strcpy(buf, text);
        }
    }

    func_ov000_02169b78(p);
    return 1;
}
