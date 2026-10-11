#include <globaldefs.h>
#if defined(jpn)
enum { kPointerOffset = 4 };
#else
enum { kPointerOffset = 0x38 };
#endif


struct Obj020444e0 { char pad[kPointerOffset]; void* field38; };

extern "C" int func_020e1f1c(void* p);
extern "C" void func_02066cf0(void* obj, int flag);
extern "C" void func_020e23f4(void* p);
int InvokeSubHandlerIfPresent(int* obj);

// USA: func_020444e0
ARM void ReleaseField0x38IfValid020444e0(struct Obj020444e0* obj) {
    void* field38 = obj->field38;
    if (field38 != NULL) {
        if (func_020e1f1c(field38) == 0) return;
        func_02066cf0(obj, 0);
        func_020e23f4(obj->field38);
        InvokeSubHandlerIfPresent((int*)obj->field38);
    } else {
        func_02066cf0(obj, 0);
    }
}
