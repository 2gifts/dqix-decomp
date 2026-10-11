#include <globaldefs.h>

struct DispatchTable_0223ca40 {
    void* slot0;
    void (*slot4)(void*, int);
};

struct DispatchObject_0223ca40 {
    char padding[0x14];
    DispatchTable_0223ca40* dispatch;
};

// USA: func_ov031_0223ca40
extern "C" ARM void CallVTableField14_0223ca40(void* obj, int unused) {
    ((DispatchObject_0223ca40*)obj)->dispatch->slot4(obj, unused);
}
