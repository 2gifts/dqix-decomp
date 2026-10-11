#include <globaldefs.h>

struct Obj_02205a38;
struct Obj0220527c;
struct Obj02205eac;
void* SetLookupFields_02205134(void*, void*, int);
int TailCall0220520cField64_0220527c(Obj0220527c*, void*);
int TailCall02205ebcField4_02205eac(Obj02205eac*);

// USA: func_ov031_02205e60
extern "C" ARM int func_ov031_02205e60(Obj_02205a38* obj) {
    char* state = *(char**)((char*)obj + 0x64);
    if (*(int*)(state + 0xf8) < *(unsigned short*)(state + 0xfc)) return 0;
    void* record = SetLookupFields_02205134((void*)TailCall02205ebcField4_02205eac, obj, 0);
    if (record == NULL) return -33;
    return TailCall0220520cField64_0220527c((Obj0220527c*)obj, record);
}
