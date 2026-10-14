#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int n);
#if !defined(jpn)
extern "C" void func_0203c5a8(void* ptr, void* buf, short* fieldAddr);
#endif
extern void* data_02105244;

void ReleaseGlobalEntry0203c198(char* obj);

struct RefArray0xc6b8;
void IncrementEntryCount0x24(struct RefArray0xc6b8* obj, short index);

struct RefArray0xc6fc;
#if defined(jpn)
void DecrementEntryCount0x24(struct RefArray0xc6fc* obj, const short* indices);
#else
void DecrementEntryCount0x24(struct RefArray0xc6fc* obj, short index);
#endif

#if defined(jpn)
extern "C" void func_0203cb58(void*, void*);
extern "C" void func_0203bf00(void*, char*, void*, int);
extern "C" void func_0203c5a8(void*, void*, void*, int);
#endif
struct Obj0203c108 {
    char pad[0x14];
    short idx;
};

// USA: func_0203c108
ARM void SwapGlobalEntry0203c108(struct Obj0203c108* obj, char* fmt) {
    if (data_02105244 != NULL && fmt != NULL && *fmt != 0) {
#if defined(jpn)
        char saved[0x14];
        char buf[0x80];
        memcpy(saved, obj, 0x14);
        func_0203cb58(data_02105244, saved);
        ReleaseGlobalEntry0203c198((char*)obj);
        __clear(buf, 0x80);
        func_0203bf00(obj, fmt, buf, 10);
        *(int*)((char*)obj + 0x20) = 10;
        func_0203c5a8(data_02105244, buf, obj, 10);
        DecrementEntryCount0x24(static_cast<RefArray0xc6fc*>(data_02105244),
                               reinterpret_cast<const short*>(saved));
#else
        char buf[0x100];
        __clear(buf, 0x100);
        sprintf(buf, fmt);
        short oldIdx = obj->idx;
        IncrementEntryCount0x24((struct RefArray0xc6b8*)data_02105244, oldIdx);
        ReleaseGlobalEntry0203c198((char*)obj);
        func_0203c5a8(data_02105244, buf, &obj->idx);
        DecrementEntryCount0x24((struct RefArray0xc6fc*)data_02105244, oldIdx);
#endif
    }
}
