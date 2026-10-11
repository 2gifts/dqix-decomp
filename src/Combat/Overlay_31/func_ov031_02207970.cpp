#include <globaldefs.h>

struct Obj0220527c;
void* SetLookupFields_02205134(void*, void*, int);
int TailCall0220520cField64_0220527c(Obj0220527c*, void*);
extern "C" void func_ov031_022079ac(void);

// USA: func_ov031_02207970
extern "C" ARM int func_ov031_02207970(void* obj, void* value) {
    void* record = SetLookupFields_02205134((void*)func_ov031_022079ac, obj, 1);
    if (record == NULL) return -33;
    *(void**)((char*)record + 0x10) = value;
    return TailCall0220520cField64_0220527c((Obj0220527c*)obj, record);
}
