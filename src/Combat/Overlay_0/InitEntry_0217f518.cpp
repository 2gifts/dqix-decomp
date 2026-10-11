#include <globaldefs.h>
#include "std_library_functions.h"

void ReleaseGlobalEntry0203c198(char* obj);
int HasAnyFlags_021719f8_021719f8(int* obj);
extern "C" void __clear(void* buf, int n);
#if defined(jpn)
extern "C" int func_ov000_02171a74(void* obj);
struct Container020e0310;
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310*, int);
#else
extern "C" int func_ov000_02171a74(void* obj, char* buf);
#endif
struct Obj0203c108;
void SwapGlobalEntry0203c108(struct Obj0203c108* obj, char* fmt);
extern "C" void func_ov000_02170ffc(void* obj);

// USA: func_ov000_0217f518  (semantic: InitEntry_0217f518)
extern "C" ARM void func_ov000_0217f518(char* obj) {
#if !defined(jpn)
    char buf[0x80];
#endif
    memset(obj + 0x10, 0, 8);
    *(unsigned char*)(obj + 0x10) = 0xd;
    *(unsigned char*)(obj + 0x18) = 0;
    *(unsigned char*)(obj + 0x1c) = 0;
    *(char*)(obj + 0x1d) = -1;
    *(char*)(obj + 0x20) = -1;
    *(short*)(obj + 0x1e) = -1;
    *(char*)(obj + 0x22) = -1;
    *(char*)(obj + 0x21) = -1;
    *(short*)(obj + 0x2c) = -1;
    *(char*)(obj + 0x2e) = -1;
    *(short*)(obj + 0x26) = 0;
    ReleaseGlobalEntry0203c198(obj + 0x50);
#if defined(jpn)
    *(char*)(obj + 0x47d) = -1;
#else
    *(char*)(obj + 0x43d) = -1;
#endif
    if (HasAnyFlags_021719f8_021719f8((int*)obj)) {
#if defined(jpn)
        int ret = func_ov000_02171a74(obj);
        struct Container020e0310* container = *(struct Container020e0310**)(obj + 4);
        if (container && ret >= 0) {
            SwapGlobalEntry0203c108((struct Obj0203c108*)(obj + 0x50), (char*)_Z21GetFieldByKey020e0434P17Container020e0310i(container, ret));
        }
#else
        __clear(buf, 0x80);
        int ret = func_ov000_02171a74(obj, buf);
        if (ret >= 0) {
            SwapGlobalEntry0203c108((struct Obj0203c108*)(obj + 0x50), buf);
        }
#endif
        *(unsigned char*)(obj + 0x10) = 0x64;
    }
    func_ov000_02170ffc(obj);
}
